#include "IOManager.h"
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>

SDL_Surface* IOManager::LoadSurface(char* FilePath, const SDL_PixelFormat* Format)
{
	//If the pixelformat isnt set, set it to RGB888 by default.
	if (Format == nullptr)
	{
		Format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888);
	}

	SDL_Surface* OptimizedSurface = nullptr;
	SDL_Surface* Surface = nullptr;
	Surface = IMG_Load(FilePath);
	if (Surface == nullptr)
	{
		printf("Unable to load image %s! SDL Error: %s\n", FilePath, IMG_GetError());
		return nullptr;
	}

	//Convert surface to optimized format
	OptimizedSurface = SDL_ConvertSurface(Surface, Format, NULL);
	if (OptimizedSurface == nullptr)
	{
		printf("Unable to optimize image %s! SDL Error: %s\n", FilePath, SDL_GetError());
		return nullptr;
	}

	//Get rid of old loaded surface
	SDL_FreeSurface(Surface);

	return OptimizedSurface;
}

SDL_Texture* IOManager::LoadTexture(char* FilePath, SDL_Renderer* Renderer, const SDL_PixelFormat * Format)
{
	//Get the image as a surface 
	//Use LoadSurface to handle error checking & minimise code
	SDL_Surface* Surface = LoadSurface(FilePath, Format);

	//Create a texture from the surface
	SDL_Texture* Texture = nullptr;
	Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
	if (Texture == nullptr)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", FilePath, SDL_GetError());
		return nullptr;
	}

	//Free the surface
	SDL_FreeSurface(Surface);

	return Texture;
}