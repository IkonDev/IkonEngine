//CRT Leak Detector---------
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
//--------------------------

#include "Engine.h"
#include "Application.h"
#include <ctime>

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

	//Pingas
	srand(time(NULL));
	int i = 0;
	while (i < 1500)
	{
		for (int x = 0; x < 1024 / 64; ++x)
		{
			for (int y = 0; y < 768 / 64; ++y)
			{
				char* FilePath = "";
				switch (rand() % 6)
				{
				case 0:
					FilePath = "Data/Tex/PINGA-1.bmp";
					break;
				case 1:
					FilePath = "Data/Tex/PINGA-2.bmp";
					break;
				case 2:
					FilePath = "Data/Tex/PINGA-3.bmp";
					break;
				case 3:
					FilePath = "Data/Tex/PINGA-4.bmp";
					break;
				case 4:
					FilePath = "Data/Tex/PINGA-5.bmp";
					break;
				case 5:
					FilePath = "Data/Tex/PINGA-6.bmp";
					break;
				}
				App->BlitImage(FilePath, x * 64, y * 64, 64, 64);
			}
		}
		EE->UpdateWindow();
		//SDL_Delay(250);
		EE->ClearSurface();
		++i;
	}
	//Quick game loop

	//Place some images
	//App->BlitImage("Data/Tex/Test.bmp", 0, 0, 128, 128);
	//App->BlitImage("Data/Tex/Test2.bmp", 128, 0,128,128);
	//App->BlitImage("Data/Tex/Test2.bmp", 0, 128, 128, 128);
	//App->BlitImage("Data/Tex/Test.bmp", 128, 128, 128, 128);
	//SDL_Delay(5000);

	//Shutdown Engine
	EE->Shutdown();
	delete EE;
	delete App;

	//C++ Stuff
	//system("pause");
	return 0;
}