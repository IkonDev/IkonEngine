#include "Engine.h"
#include <stdio.h>

bool Engine::Init(unsigned int ScreenX, unsigned int ScreenY)
{
	v_mScreenDimensions = glm::vec2(ScreenX, ScreenY);

	//Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//SDL Initialization failed
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		mWindow = SDL_CreateWindow("SDL_TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenX, ScreenY, SDL_WINDOW_SHOWN);
		if (mWindow == nullptr)
		{
			//Window creation failed
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Window was succesfully created
			mSurface = SDL_GetWindowSurface(mWindow);

			//Fill the screen grey
			SDL_FillRect(mSurface, NULL, SDL_MapRGB(mSurface->format, 0x11, 0x11, 0x11));

			//Update the window
			SDL_UpdateWindowSurface(mWindow);

			printf("Init Successful!");
			b_mWasInit = true;

			return true;
		}
	}
	return false;
}

bool Engine::Shutdown()
{
	//Destroy window
	SDL_DestroyWindow(mWindow);

	//Quit SDL
	SDL_Quit();

	return true;
}

void Engine::BlitSurface(SDL_Surface* Surface)
{
	//Apply the image
	SDL_BlitSurface(Surface, NULL, mSurface, NULL);
	SDL_UpdateWindowSurface(mWindow);
}
