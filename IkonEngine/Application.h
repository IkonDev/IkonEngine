#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	void SetEngine(Engine* aEngine) { mEngine = aEngine; }

	//Blits an image to the screen
	void RenderTexture(char* FilePath);
	void RenderTexture(char* FilePath, int x = 0, int y = 0, int w = 0, int h = 0);
	void RenderTexture(SDL_Texture* Texture);
	void RenderTexture(SDL_Texture* Texture, int x = 0, int y = 0, int w = 0, int h = 0);

private:
	Engine* mEngine = nullptr;
};

