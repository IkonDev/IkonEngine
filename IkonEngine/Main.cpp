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

	//Seed RNG
	srand((unsigned int)time(NULL));

	//Setup Engine
	Engine* EE = new Engine();
	Application* App = nullptr;

	//If the engine initializes successfully...
	if (EE->Init(1024, 768))
	{
		//...Create the App and give it the engine.
		App = new Application();
		App->SetEngine(EE);
	}
	//The engine (EE) isnt really used by the programmer after this point
	
#pragma region GAME

	//Make some surfaces
	//SDL_Renderer* Renderer = EE->GetRenderer();
	SDL_Texture* Ping[6] =
	{ IOManager::LoadTexture("Data/Tex/PINGA-1.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-2.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-3.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-4.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-5.png", EE->GetRenderer()) ,
	  IOManager::LoadTexture("Data/Tex/PINGA-6.png", EE->GetRenderer()) };

	//Get screen size
	glm::vec2 SD = EE->GetScreenDimensions(); 
	
	//Loop n times
	unsigned int TileSize = 128;
	for (int Frame = 0; Frame < 1200; ++Frame)
	{
		for (int x = 0; x < SD.x / TileSize; ++x)
		{
			for (int y = 0; y < SD.y / TileSize; ++y)
			{
				//Create Transformation
				SDL_Rect Transform;
				Transform.x = x * TileSize;
				Transform.y = y * TileSize;
				Transform.w = TileSize;
				Transform.h = TileSize;

				//Pick a random sprite
				int RandomSpriteIndex = rand() % 6;

				//Render			
				App->RenderTexture(Ping[RandomSpriteIndex], &Transform);
			}
		}

		//Once all the sprites have been blit, update
		App->UpdateWindow();
		App->Wait(50);
	}
	
	//Free Surfaces
	for (int i = 0; i < 6; ++i)
	{
		SDL_DestroyTexture(Ping[i]); //This will be fixed as soon as I get around to making a texture class.
		Ping[i] = nullptr;
	}
	//32 LINES OF CODE PROGRAM LOL
#pragma endregion GAME

	//Shutdown App
	App->SetEngine(nullptr);
	delete App;
	//Shutdown Engine
	EE->Shutdown();
	delete EE;
	//End program
	return 0;
}