#include "IOManager.h"
#include <SDL.h>
#include <stdio.h>
SDL_Surface* IOManager::LoadSurface(char* FilePath, const SDL_PixelFormat* Format)
{
	SDL_Surface* Surface = nullptr;
	SDL_Surface* OptimizedSurface = nullptr;
	Surface = SDL_LoadBMP(FilePath);
	if (Surface == nullptr)
	{
		printf("Unable to load image %s! SDL Error: %s\n", FilePath, SDL_GetError());
	}
	else
	{
		OptimizedSurface = SDL_ConvertSurface(Surface, Format, NULL);
		if (OptimizedSurface == nullptr)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", FilePath, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(Surface);
		return OptimizedSurface;
	}
	return nullptr;
}
