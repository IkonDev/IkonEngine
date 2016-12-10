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
	void BlitImage(char* FilePath, int x, int y, int w, int h);
	void BlitImage(SDL_Surface* Surface);
	void BlitImage(SDL_Surface* Surface, int x, int y, int w, int h);
private:
	Engine* mEngine = nullptr;
};

