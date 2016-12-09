#include "IOManager.h"
#include <SDL.h>
#include <stdio.h>
SDL_Surface* IOManager::LoadSurface(char * FilePath)
{
	SDL_Surface* Surface = nullptr;
	Surface = SDL_LoadBMP(FilePath);
	if (Surface == nullptr)
	{
		printf("Unable to load image %s! SDL Error: %s\n", FilePath, SDL_GetError());
	}
	return Surface;
}
