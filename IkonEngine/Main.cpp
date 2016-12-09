//CRT Leak Detector---------
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//--------------------------

#include "Engine.h"
#include "Application.h"


#undef main //Makes SDL work, SDL tries to declare its own main function

int main()
{
	//CRT leak detector, tell it to dump leaks at any program exit.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Setup Engine
	Engine* EE = new Engine();
	EE->Init(1024,768);
	//Setup Game
	Application* App = new Application();
	App->SetEngine(EE);


	App->BlitImage("Data/Tex/Test.bmp");




	//Shutdown Engine
	EE->Shutdown();
	delete EE;
	delete App;

	//C++ Stuff
	//system("pause");
	return 0;
}