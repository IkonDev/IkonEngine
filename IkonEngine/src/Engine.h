#pragma once

#include <SDL.h>
#include <glm/glm.hpp>

enum EngineState
{
	ENGINE_INIT,
	ENGINE_RUNNING
};

class Engine
{
public:
	Engine()  {};
	~Engine() {};

	bool Init(unsigned int ScreenX, unsigned int ScreenY, const char* AppName);
	bool Shutdown();

	//Rendering functions
	void RenderTexture(SDL_Texture* Texture, SDL_Rect* Transform = nullptr, double Angle = 0.0, SDL_Point* Centre = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Rect* Clip = nullptr);
	void ClearRenderer();
	void SetRenderColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void UpdateWindow();
	void Update();

	//Get useful elements
	SDL_Window* GetWindow() { return mWindow; }
	SDL_Renderer* GetRenderer() { return mRenderer; }
	SDL_Surface* GetSurface() { return mSurface; }
	static Engine* Instance()
	{
		if (!m_Instance)
		{
			m_Instance = new Engine;
		}
		return m_Instance;
	}
	//Get screen dimensions
	const glm::vec2 GetScreenDimensions() const { return m_vScreenDimensions; }

	const bool GetEngineState(EngineState State);
	void SetEngineState(EngineState State, bool Value);

private:
	//Engine instance pointer
	static Engine* m_Instance;

	bool m_bWasInit = false;
	bool m_bIsRunning = true;

	glm::vec2 m_vScreenDimensions = glm::vec2(0);

	SDL_Window*  mWindow  = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	SDL_Surface* mSurface = nullptr;
};