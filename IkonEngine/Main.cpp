//CRT Leak Detector---------
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//--------------------------

#include "Engine.h"
#include "Application.h"
#include "IOManager.h"

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

	bool quit = false;
	while (!quit)
	{
		EE->ClearRenderer();
		//Handle events on queue
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		App->Update();
		App->Draw();	
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