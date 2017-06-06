//CRT Leak Detector---------
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//--------------------------
#include <ctime>
#include <stdio.h>

#include "Engine.h"
#include "Application.h"


#undef main //Makes SDL work, SDL tries to declare its own main function

int main()
{
	//CRT leak detector, tell it to dump leaks at any program exit.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Seed RNG
	srand((unsigned int)time(NULL));

	//Setup Engine
	Engine* EE = Engine::Instance();
	Application* App = nullptr;

	//If the engine initializes successfully...
	if (EE->Init(1024, 1024, "Cellular Automata"))
	{
		//...Create the App and give it the engine.
		App = new Application();
		App->SetEngine(EE);
	}
	
#pragma region GAME

	while (EE->GetEngineState(EngineState::ENGINE_RUNNING)) //Set the engine state ENGINE_RUNNING to false to quit
	{
		EE->ClearRenderer();
		EE->Update();

		App->Update();
		App->Draw();	
	}
	//5 Lines is all you need

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