#pragma once

#include <SDL.h>
#include <glm/glm.hpp>

class Engine
{
public:
	Engine()  {};
	~Engine() {};

	bool Init(unsigned int ScreenX, unsigned int ScreenY);
	bool Shutdown();

	//Rendering functions
	void RenderTexture(SDL_Texture* Texture, SDL_Rect Transform = { 0,0,0,0 });
	void ClearRenderer();
	void UpdateWindow();

	//Get useful elements
	SDL_Window* GetWindow() { return mWindow; }
	SDL_Renderer* GetRenderer() { return mRenderer; }
	SDL_Surface* GetSurface() { return mSurface; }

	//Get screen dimensions
	const glm::vec2 GetScreenDimensions() const { return m_vScreenDimensions; }

private:
	bool m_bWasInit = false;

	glm::vec2 m_vScreenDimensions = glm::vec2(0);

	SDL_Window*  mWindow  = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	SDL_Surface* mSurface = nullptr;
};

