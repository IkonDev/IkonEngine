//CRT Leak Detector---------
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//--------------------------

#include "Engine.h"
#include "Application.h"
#include "IOManager.h"
#include <glm/vec2.hpp>

#include <ctime>
#include <stdio.h>

#undef main //Makes SDL work, SDL tries to declare its own main function

int main()
{
	//CRT leak detector, tell it to dump leaks at any program exit.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Setup Engine
	Engine* EE = new Engine();
	EE->Init(1024,768);

	//Setup GameApp
	Application* App = new Application();
	App->SetEngine(EE);

#pragma region GAME
	//Pings
	srand((unsigned int)time(NULL));

	//Make some surfaces
	SDL_Texture* Ping[6] =
	{ IOManager::LoadTexture("Data/Tex/PINGA-1.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-2.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-3.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-4.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-5.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-6.png", EE->GetRenderer()) };

	glm::vec2 SD = EE->GetScreenDimensions(); //Get screen size
	
	int Frame = 0;
	unsigned int i = SDL_GetTicks();
	while (Frame < 100000)
	{
		for (int x = 0; x < SD.x / 64; ++x)
		{
			for (int y = 0; y < SD.y / 64; ++y)
			{
				switch (rand() % 6)
				{
				case 0:
					App->RenderTexture(Ping[0], x * 64, y * 64, 64, 64);
					break;
				case 1:
					App->RenderTexture(Ping[1], x * 64, y * 64, 64, 64);
					break;
				case 2:
					App->RenderTexture(Ping[2], x * 64, y * 64, 64, 64);
					break;
				case 3:
					App->RenderTexture(Ping[3], x * 64, y * 64, 64, 64);
					break;
				case 4:
					App->RenderTexture(Ping[4], x * 64, y * 64, 64, 64);
					break;
				case 5:
					App->RenderTexture(Ping[5], x * 64, y * 64, 64, 64);
					break;
				}
			}
		}

		EE->UpdateWindow();
		//SDL_Delay(250);
		//EE->ClearSurface();
		Frame++;
	}

	printf("%i Frames/s\n", Frame);
	SDL_Delay(550);

	//Free Surfaces
	for (int j = 0; j < 6; ++j)
	{
		SDL_DestroyTexture(Ping[j]);
		Ping[j] = nullptr;
	}

	
#pragma endregion GAME

	//Shutdown Engine
	EE->Shutdown();
	delete EE;
	delete App;

	//C++ Stuff
	return 0;
}