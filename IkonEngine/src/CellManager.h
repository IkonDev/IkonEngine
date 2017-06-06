#pragma once
#include <vector>
#include <thread>
union RuleVars // 18 bit
{
	struct 
	{
		bool B0;
		bool B1;
		bool B2;
		bool B3;
		bool B4;
		bool B5;
		bool B6;
		bool B7;
		bool B8;
		bool S0;
		bool S1;
		bool S2;
		bool S3;
		bool S4;
		bool S5;
		bool S6;
		bool S7;
		bool S8;
	};
	bool BS[18];
};

enum RuleSet
{
	LiveFreeOrDie = 516,
	GameOfLife    = 6152,
	R_2x2         = 19528,
	EightLife     = 137224,
};

class CellManager
{
public:
	CellManager();
	CellManager(unsigned int Size);
	~CellManager();

	void SetRule(RuleSet R);
	void ClearArray();
	void Randomize(int Percentage);
	void Step();

	void ToggleCell(unsigned int x, unsigned int y);
	void SetCell(unsigned int x, unsigned int y, bool Val);

	int GetNeighbors(unsigned int x, unsigned int y, bool* refArray);
	bool Test(unsigned int x, unsigned int y);

	unsigned int GridSize = 32;
	bool* Array = nullptr;

	static bool GetRule(unsigned int Neighbors, bool Alive, RuleSet ruletype);
	static bool GetRule(unsigned int Neighbors, bool Alive, RuleVars ruletype);

	static RuleVars GetRuleVars(unsigned int Rule);
	RuleVars DefaultSet = GetRuleVars(RuleSet::GameOfLife);

	unsigned int Generations = 0;
	unsigned int GetGenerations() { return Generations; }
};

