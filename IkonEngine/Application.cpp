#include "Application.h"
#include "IOManager.h"
#include <stdio.h>

Application::Application()
{
}

Application::~Application()
{
}

void Application::RenderTexture(char * FilePath)
{
	SDL_Texture* Texture = nullptr;
	Texture = IOManager::LoadTexture(FilePath, mEngine->GetRenderer());
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture);
	}
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
}

void Application::RenderTexture(char * FilePath, int x, int y, int w, int h)
{
	SDL_Texture* Texture = nullptr;
	Texture = IOManager::LoadTexture(FilePath, mEngine->GetRenderer());
	if (Texture != nullptr)
	{
		SDL_Rect Transform;
		Transform.x = x;
		Transform.y = y;
		Transform.w = w;
		Transform.h = h;
		mEngine->RenderTexture(Texture, Transform);
	}
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
}

void Application::RenderTexture(SDL_Texture* Texture)
{
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture);
	}
}

void Application::RenderTexture(SDL_Texture* Texture, int x, int y, int w, int h)
{
	if (Texture != nullptr)
	{
		SDL_Rect Transform;
		Transform.x = x;
		Transform.y = y;
		Transform.w = w;
		Transform.h = h;
		mEngine->RenderTexture(Texture, Transform);
	}
}
