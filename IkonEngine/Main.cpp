#include "Engine.h"
#include "Application.h"

#undef main //Makes SDL work, SDL tries to declare its own main function

int main()
{
	//Setup Engine
	Engine* EE = new Engine();
	EE->Init(1024,768);
	//Setup Game
	Application App = Application();
	App.SetEngine(EE);


	App.BlitImage("Data/Tex/Test.bmp");

	//Shutdown Engine
	EE->Shutdown();
	delete EE;

	//C++ Stuff
	system("pause");
	return 0;
}