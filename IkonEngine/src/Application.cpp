#include "Application.h"
#include "IOManager.h"

#include <glm\glm.hpp>
#include <omp.h>

//Setup
Application::Application()
{
	//Get a pointer to the input handler
	Input = InputHandler::Instance(); 

	//Load a texture for display of tiles
	TestTileA = IOManager::LoadTexture("Data/Tex/Game/Block.png", Engine::Instance()->GetRenderer());
	TestTileB = IOManager::LoadTexture("Data/Tex/Game/Block2.png", Engine::Instance()->GetRenderer());

	//Set the background to a nice purple
	Engine::Instance()->SetRenderColour(77, 0, 77, 255);
}
//Shutdown
Application::~Application()
{
	
}

//Update loop
void Application::Update()
{	
	if (Input->IsKeyPressed(InputHandler::IkonKey::SHIFT))
	{
		if (Input->WasKeyPressed(InputHandler::IkonKey::Q))
		{
			mEngine->SetEngineState(EngineState::ENGINE_RUNNING, false);
		}
	}
}

	//Drawing loop
void Application::Draw()
{
	Engine::Instance()->ClearRenderer();

	omp_lock_t Lock;
	omp_init_lock(&Lock);

	for (int y = 0; y < 32; ++y)
	{
		#pragma omp parallel for
		for (int x = 0; x < 32; ++x)
		{
			glm::vec4 Transform;
			Transform.x = (float)x * TileSize;
			Transform.y = (float)y * TileSize;
			Transform.z = (float)TileSize;
			Transform.w = (float)TileSize;

			omp_set_lock(&Lock);
			SDL_SetTextureColorMod(TestTileA, 0, 255, 255);
			RenderTexture(TestTileA, Transform, 0.0f);
			SDL_SetTextureColorMod(TestTileA, 255, 255, 255);
			omp_unset_lock(&Lock);
		}

	}
	omp_destroy_lock(&Lock);
	UpdateWindow();

}

//RENDERING CODE - IGNORE
void Application::RenderTexture(SDL_Texture* Texture)
{
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture);
	}
}
void Application::RenderTexture(SDL_Texture* Texture, glm::vec4 Transform, double Angle, glm::vec2 Centre, SDL_RendererFlip Flip, SDL_Rect* Clip)
{
	//SDL Suitable Transform
	SDL_Rect SDLTransform = SDL_Rect();
	SDLTransform.x = (int)Transform.x;
	SDLTransform.y = (int)Transform.y;
	SDLTransform.w = (int)Transform.z;
	SDLTransform.h = (int)Transform.w;

	//SDL Suitable point
	SDL_Point SDLCentre = SDL_Point();
	SDLCentre.x = (int)Centre.x;
	SDLCentre.y = (int)Centre.y;

	if (Texture != nullptr)
	{		
		mEngine->RenderTexture(Texture, &SDLTransform, Angle, &SDLCentre, Flip, Clip);
	}
}
