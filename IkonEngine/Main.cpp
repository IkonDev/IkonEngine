#include "Engine.h"
#undef main
int main()
{
	Engine* EE = new Engine();
	EE->Init(1024,768);



	EE->Shutdown();
	delete EE;

	return 0;
}