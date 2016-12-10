#include "Application.h"
#include "IOManager.h"
#include <stdio.h>

Application::Application()
{
}

Application::~Application()
{
}

void Application::BlitImage(char * FilePath)
{
	SDL_Surface* Surface = nullptr;
	Surface = IOManager::LoadSurface(FilePath, mEngine->GetSurface()->format);
	if (Surface != nullptr)
	{
		mEngine->BlitSurface(Surface);
	}
	SDL_FreeSurface(Surface);
}

void Application::BlitImage(char * FilePath, int x, int y, int w, int h)
{
	SDL_Surface* Surface = nullptr;
	Surface = IOManager::LoadSurface(FilePath, mEngine->GetSurface()->format);
	if (Surface != nullptr)
	{
		SDL_Rect Transform;
		Transform.x = x;
		Transform.y = y;
		Transform.w = w;
		Transform.h = h;
		mEngine->BlitSurface(Surface, Transform);
	}
	SDL_FreeSurface(Surface);
}

void Application::BlitImage(SDL_Surface* Surface)
{
	if (Surface != nullptr)
	{
		mEngine->BlitSurface(Surface);
	}
}

void Application::BlitImage(SDL_Surface* Surface, int x, int y, int w, int h)
{
	if (Surface != nullptr)
	{
		SDL_Rect Transform;
		Transform.x = x;
		Transform.y = y;
		Transform.w = w;
		Transform.h = h;
		mEngine->BlitSurface(Surface, Transform);
	}
}
