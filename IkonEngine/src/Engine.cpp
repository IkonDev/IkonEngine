#include "Engine.h"
#include <stdio.h>
#include <SDL_image.h>
#include "InputHandler.h"
Engine* Engine::m_Instance = 0;
bool Engine::Init(unsigned int ScreenX, unsigned int ScreenY, const char* AppName)
{
	m_vScreenDimensions = glm::vec2(ScreenX, ScreenY);
	m_bWasInit = true;

	//Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//SDL Initialization failed
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		m_bWasInit = false;
		return false;
	}

	//PNG Loading
	int ImgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(ImgFlags) & ImgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		m_bWasInit = false;
		return false;
	}

	//Create window
	mWindow = SDL_CreateWindow(AppName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenX, ScreenY, SDL_WINDOW_SHOWN);
	if (mWindow == nullptr)
	{
		//Window creation failed
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		m_bWasInit = false;
		return false;
	}
	else
	{
		//Window was succesfully created
		mSurface = SDL_GetWindowSurface(mWindow);

		//Fill the screen grey // clear screen
		ClearRenderer();

		//Update the window
		SDL_UpdateWindowSurface(mWindow);
	}

	//Try to create hardware renderer for window
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (mRenderer == nullptr)
	{
		//If that fails... Display an error and try to create software renderer for window
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_SOFTWARE);
		if (mRenderer == nullptr)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			m_bWasInit = false;
			return false;
		}
		else
		{
			printf("Fallback To Software Rendering\n");
		}
	}

	if (mRenderer != nullptr)
	{
		//Initialize renderer color
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}

	printf("IkonEngine Init Successful!!\n");
	return true;
}

bool Engine::Shutdown()
{
	//Destroy window
	SDL_DestroyWindow(mWindow);

	//Quit SDL
	SDL_Quit();
	IMG_Quit();

	//Set states to false
	if(m_bIsRunning)
		m_bIsRunning = false;
	if (m_bWasInit)
		m_bWasInit = false;

	return true;
}

void Engine::ClearRenderer()
{
	SDL_RenderClear(mRenderer);
}

void Engine::SetRenderColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	if (GetEngineState(EngineState::ENGINE_INIT))
	{
		//Initialize renderer color
		SDL_SetRenderDrawColor(mRenderer, r, g, b, a);
	}
}

void Engine::UpdateWindow()
{
	SDL_RenderPresent(mRenderer);
}

void Engine::Update()
{
	InputHandler::Instance()->SetPrevKeys();
	//Handle events on queue
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			m_bIsRunning = false;
		}
		InputHandler::Instance()->HandleInput(e);
	}
}

const bool Engine::GetEngineState(EngineState State)
{
	switch (State)
	{
	case EngineState::ENGINE_INIT:
		return m_bWasInit;
		break;

	case EngineState::ENGINE_RUNNING:
		return m_bIsRunning;
		break;
	}

	return false;
}

void Engine::SetEngineState(EngineState State, bool Value)
{
	switch (State)
	{
	case EngineState::ENGINE_INIT:
		m_bWasInit = Value;
		break;

	case EngineState::ENGINE_RUNNING:
		m_bIsRunning = Value;
		break;
	}
}

void Engine::RenderTexture(SDL_Texture* Texture, SDL_Rect* Transform, double Angle, SDL_Point* Centre, SDL_RendererFlip Flip, SDL_Rect* Clip)
{
	//if (Clip == nullptr)
	//{
	//	SDL_Rect R;
	//	R.x = 0;
	//	R.y = 0;
	//	R.w = X;
	//	R.h = Y;
	//	Clip = &R;
	//}
	SDL_RenderCopyEx(mRenderer, Texture, Clip, Transform, Angle, Centre, Flip);
}
