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
	
private:
	bool b_mWasInit = false;

	glm::vec2 v_mScreenDimensions = glm::vec2(0);

	SDL_Window*  mWindow  = nullptr;
	SDL_Surface* mSurface = nullptr;
};

