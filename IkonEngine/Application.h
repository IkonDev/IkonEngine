#pragma once
#include "Engine.h"
#include "PlayerObject.h"
#include "GameObject.h"

#define TILESIZE 128

class Application
{
public:
	Application();
	~Application();

	//Utility function to set the applications engine pointer
	void SetEngine(Engine* aEngine) { mEngine = aEngine; }
	void UpdateWindow() { mEngine->UpdateWindow(); }
	void Wait(unsigned int Milliseconds) { SDL_Delay(Milliseconds); }
	
	void Update();
	void Draw();
	//Blits an image to the screen
		//void RenderTexture(char* FilePath);
		//void RenderTexture(char* FilePath,       SDL_Rect* Transform = nullptr, double Angle = 0.0, SDL_Point* Centre = nullptr, SDL_RendererFlip Flip = SDL_FLIP_NONE, SDL_Rect* Clip = nullptr);
	void RenderTexture(SDL_Texture* Texture);
	void RenderTexture(SDL_Texture* Texture, glm::vec4 Transform = glm::vec4(0), double Angle = 0.0, glm::vec2 Centre = glm::vec2(0), SDL_RendererFlip Flip = SDL_FLIP_NONE, SDL_Rect* Clip = nullptr);

private:
	Engine* mEngine = nullptr;

	//Game stuff
	GameObject* P = nullptr;

	SDL_Texture* Ping;
};

