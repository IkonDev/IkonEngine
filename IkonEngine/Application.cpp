#include "Application.h"
#include "IOManager.h"
#include <stdio.h>

Application::Application()
{
}

Application::~Application()
{
}
/*
void Application::RenderTexture(char* FilePath)
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

void Application::RenderTexture(char* FilePath, SDL_Rect* Transform, double Angle, SDL_Point* Centre, SDL_RendererFlip Flip, SDL_Rect* Clip)
{
	SDL_Texture* Texture = nullptr;
	Texture = IOManager::LoadTexture(FilePath, mEngine->GetRenderer());
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture, *Transform, Angle, Centre, Flip, *Clip);
	}
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
}
*/
void Application::RenderTexture(SDL_Texture* Texture)
{
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture);
	}
}

void Application::RenderTexture(SDL_Texture* Texture, SDL_Rect* Transform, double Angle, SDL_Point* Centre, SDL_RendererFlip Flip, SDL_Rect* Clip)
{
	if (Texture != nullptr)
	{		
		mEngine->RenderTexture(Texture, Transform, Angle, Centre, Flip, Clip);
	}
}
