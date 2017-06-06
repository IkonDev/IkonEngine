#include "CellManager.h"
#include "SDL.h"
#include <omp.h>
#include <string>
#include <bitset>
#include <iostream>

CellManager::CellManager() : GridSize(32)
{
	const int GridSqr = GridSize * GridSize;
	Array = new bool[GridSqr];
	
	#pragma omp parallel for
	for (int i = 0; i < GridSqr; ++i)
	{
		const int x = i % GridSize;
		const int y = i / GridSize;
		Array[y * GridSize + x] = false;
	}
}

CellManager::CellManager(unsigned int Size) : GridSize(Size)
{	
	const int GridSqr = GridSize * GridSize;
	Array = new bool[GridSqr];
	
	#pragma omp parallel for
	for (int i = 0; i < GridSqr; ++i)
	{
		const int x = i % GridSize;
		const int y = i / GridSize;
		Array[y * GridSize + x] = false;
	}
}

CellManager::~CellManager()
{
	delete[] Array;
	Array = nullptr;
}

void CellManager::SetRule(RuleSet R)
{
	DefaultSet = GetRuleVars(R);
	//ClearArray(); 
	//NOTE: Maybe we want to clear the array here??
}

void CellManager::ClearArray()
{
	Generations = 0;
	const int GridSqr = GridSize * GridSize;
	#pragma omp parallel for
	for (int i = 0; i < GridSqr; ++i)
	{
		const int x = i % GridSize;
		const int y = i / GridSize;
		Array[y * GridSize + x] = false;
	}
}

void CellManager::Randomize(int Percentage)
{
	Generations = 0;
	const int GridSqr = GridSize * GridSize;
	#pragma omp parallel for
	for (int i = 0; i < GridSqr; ++i)
	{
		const int x = i % GridSize;
		const int y = i / GridSize;
		int R = rand() * (omp_get_thread_num() + 3);
		bool Result = (R % 100) < Percentage ? true : false;
		Array[y * GridSize + x] = Result;
	}
}

/* Old stepping code.. New Code uses OpenMP. Thanks Biskwit. */
//void CellManager::Step()
//{
//	unsigned int Time = SDL_GetTicks(); //Get time for benchmark purposes
//	bool* Next = new bool[GridSize * GridSize];
//	if (Threaded)
//	{
//		int Threads = std::thread::hardware_concurrency();
//		for (auto i = 0; i < Threads; ++i)
//		{
//			int ChunkWidth = GridSize / Threads;
//			//Calculate chunk size
//			int Low = (i * ChunkWidth);
//			int High = ((i + 1) * ChunkWidth);
//			//Push Threads
//			ThreadList.push_back(std::thread(
//				[=]()
//			{
//				for (int y = 0; y < (int)GridSize; ++y)
//				{
//					for (auto x = Low; x < High; ++x)
//					{
//						bool AliveStatus = Array[y * GridSize + x]; //Set bool to initial grid cell (IGC) status;
//						int N = GetNeighbors(x, y, Array); //Get the manhattan neighbors of (IGC)
//
//						bool Result = GetRule(N, AliveStatus, DefaultSet); //Work out the result based on a rule
//
//																		   //Set NEW grid and list cell status
//						Next[y * GridSize + x] = Result;
//					}
//				}
//			}
//			));
//		}
//
//		for (int T = 0; T < ThreadList.size(); ++T)
//		{
//			ThreadList[T].join();
//		}
//		ThreadList.clear();
//	}
//	else
//	{
//		for (int y = 0; y < (int)GridSize; ++y)
//		{
//			for (int x = 0; x < (int)GridSize; ++x)
//			{
//				bool AliveStatus = Array[y * GridSize + x]; //Set bool to initial grid cell (IGC) status;
//				int N = GetNeighbors(x,y, Array); //Get the manhattan neighbors of (IGC)
//				
//				bool Result = GetRule(N, AliveStatus, DefaultSet); //Work out the result based on a rule
//				
//				//Set NEW grid and list cell status
//				Next[y * GridSize + x] = Result;
//			}
//		}
//	}
//
//	//When the loop is complete, set the old to the new.
//	delete[] Array;
//	Array = Next;
//
//	unsigned int TimeElapsed = SDL_GetTicks();
//	unsigned int TimeTotal = TimeElapsed - Time;
//	std::cout << "Last Update: " << TimeTotal << "ms" << std::endl;
//}

void CellManager::Step()
{
	Generations += 1;
	unsigned int Time = SDL_GetTicks(); //Get time for benchmark purposes

	const int GridSqr = GridSize * GridSize;
	bool* Next = new bool[GridSqr];
	
	#pragma omp parallel for
	for (int i = 0; i < GridSqr; ++i)
	{
		const int x = i % GridSize;
		const int y = i / GridSize;

		bool AliveStatus = Array[y * GridSize + x]; //Set bool to initial grid cell (IGC) status;
		int N = GetNeighbors(x, y, Array); //Get the manhattan neighbors of (IGC)

		bool Result = GetRule(N, AliveStatus, DefaultSet); //Work out the result based on a rule
												   
		Next[y * GridSize + x] = Result; //Set NEW grid cell status
	}

	//When the loop is complete, set the old to the new.
	delete[] Array;
	Array = Next;

	unsigned int TimeElapsed = SDL_GetTicks();
	unsigned int TimeTotal = TimeElapsed - Time;
	std::cout << "Last Update: " << TimeTotal << "ms" << std::endl;
}
bool CellManager::GetRule(unsigned int Neighbors, bool Alive, RuleSet ruletype)
{
	RuleVars R = GetRuleVars((unsigned int)ruletype);
	if (Alive)
	{
		if (R.BS[9 + Neighbors])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (R.BS[Neighbors])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void CellManager::ToggleCell(unsigned int x, unsigned int y)
{
	if (x >= 0 && y >= 0)
	{
		if (x < GridSize && y < GridSize)
		{
			bool Status = Array[y * GridSize + x];
			Array[y * GridSize + x] = !Status;
		}
	}
}

void CellManager::SetCell(unsigned int x, unsigned int y, bool Val)
{
	if (x >= 0 && y >= 0)
	{
		if (x < GridSize && y < GridSize)
		{
			Array[y * GridSize + x] = Val;
		}
	}
}

int CellManager::GetNeighbors(unsigned int x, unsigned int y, bool* refArray)
{
	int Neighbors = 0;
	int xPos = x;
	int yPos = y;

	for (int yy = yPos - 1; yy <= yPos + 1; yy++)
	{
		for (int xx = xPos - 1; xx <= xPos + 1; xx++)
		{
			if ((xx >= 0) && (xx < (int)GridSize)) //Make sure you are not out of bounds on X
			{
				if ((yy >= 0) && (yy < (int)GridSize)) //Make sure you are not out of bounds on Y
				{
					if (!((xx == xPos) && (yy == yPos))) //Make sure to to check against self
					{ 
						if (Array[(yy * GridSize) + xx] == true)
						{
							Neighbors++; //Add a neighbour
						}
					}
				}
			}
		}
	}

	return Neighbors;
}

bool CellManager::Test(unsigned int x, unsigned int y)
{
	return Array[y * GridSize + x];
}

bool CellManager::GetRule(unsigned int Neighbors, bool Alive, RuleVars ruletype)
{
	RuleVars R = ruletype;
	if (Alive)
	{
		if (R.BS[9 + Neighbors])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (R.BS[Neighbors])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

RuleVars CellManager::GetRuleVars(unsigned int Rule)
{
	std::string binary = std::bitset<18>(Rule).to_string();
	RuleVars R = RuleVars();
	R.B0 = (binary[17] == (char)49);
	R.B1 = (binary[16] == (char)49);
	R.B2 = (binary[15] == (char)49);
	R.B3 = (binary[14] == (char)49);
	R.B4 = (binary[13] == (char)49);
	R.B5 = (binary[12] == (char)49);
	R.B6 = (binary[11] == (char)49);
	R.B7 = (binary[10] == (char)49);
	R.B8 = (binary[9]  == (char)49);
	R.S0 = (binary[8]  == (char)49);
	R.S1 = (binary[7]  == (char)49);
	R.S2 = (binary[6]  == (char)49);
	R.S3 = (binary[5]  == (char)49);
	R.S4 = (binary[4]  == (char)49);
	R.S5 = (binary[3]  == (char)49);
	R.S6 = (binary[2]  == (char)49);
	R.S7 = (binary[1]  == (char)49);
	R.S8 = (binary[0]  == (char)49);
	return R;
}
