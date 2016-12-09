#include "Application.h"
#include "IOManager.h"
Application::Application()
{
}

Application::~Application()
{
}

void Application::BlitImage(char * FilePath)
{
	SDL_Surface* Surface = nullptr;
	Surface = IOManager::LoadSurface(FilePath);
	if (Surface != nullptr)
	{
		mEngine->BlitSurface(Surface);
	}
	SDL_FreeSurface(Surface);
}
