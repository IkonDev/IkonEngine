#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	//Utility function to set the applications engine pointer
	void SetEngine(Engine* aEngine) { mEngine = aEngine; }
	void UpdateWindow() { mEngine->UpdateWindow(); }
	void Wait(unsigned int Milliseconds) { SDL_Delay(Milliseconds); }
	//Blits an image to the screen
		//void RenderTexture(char* FilePath);
		//void RenderTexture(char* FilePath,       SDL_Rect* Transform = nullptr, double Angle = 0.0, SDL_Point* Centre = nullptr, SDL_RendererFlip Flip = SDL_FLIP_NONE, SDL_Rect* Clip = nullptr);
	void RenderTexture(SDL_Texture* Texture);
	void RenderTexture(SDL_Texture* Texture, SDL_Rect* Transform = nullptr, double Angle = 0.0, SDL_Point* Centre = nullptr, SDL_RendererFlip Flip = SDL_FLIP_NONE, SDL_Rect* Clip = nullptr);

private:
	Engine* mEngine = nullptr;
};

