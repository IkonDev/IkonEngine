#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	void SetEngine(Engine* aEngine) { mEngine = aEngine; }

	//Blits an image to the screen
	void BlitImage(char* FilePath);
	void BlitImage(char* FilePath, int x = 0, int y = 0, int w = 0, int h = 0);
	void BlitImage(SDL_Surface* Surface);
	void BlitImage(SDL_Surface* Surface, int x = 0, int y = 0, int w = 0, int h = 0);

private:
	Engine* mEngine = nullptr;
};

