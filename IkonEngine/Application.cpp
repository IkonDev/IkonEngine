#include "Application.h"
#include "IOManager.h"
#include <glm\glm.hpp>
#include <stdio.h>

Application::Application()
{
	Ping = IOManager::LoadTexture("Data/Tex/Game/Grass.png", Engine::GetEngine()->GetRenderer());
	P = new PlayerObject();
	P->SetPosition(glm::vec2(256, 256));
}

Application::~Application()
{
	delete P;
}
void Application::Update()
{
	P->Update(0.06f);
}
void Application::Draw()
{
	glm::vec2 SD = mEngine->GetScreenDimensions();
	for (int x = 0; x < SD.x / TILESIZE; ++x)
	{
		for (int y = 0; y < SD.y / TILESIZE; ++y)
		{
			//Create Transformation
			glm::vec4 Transform;
			Transform.x = (float)(x * TILESIZE);
			Transform.y = (float)(y * TILESIZE);
			Transform.z = (float)TILESIZE;
			Transform.w = (float)TILESIZE;
	
			//Render			
			RenderTexture(Ping, Transform);
		}
	}

	P->Draw(this);
	//Wait(50);
	UpdateWindow();
}
/*
void Application::RenderTexture(char* FilePath)
{
	SDL_Texture* Texture = nullptr;
	Texture = IOManager::LoadTexture(FilePath, mEngine->GetRenderer());
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture);
	}
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
}

void Application::RenderTexture(char* FilePath, SDL_Rect* Transform, double Angle, SDL_Point* Centre, SDL_RendererFlip Flip, SDL_Rect* Clip)
{
	SDL_Texture* Texture = nullptr;
	Texture = IOManager::LoadTexture(FilePath, mEngine->GetRenderer());
	if (Texture != nullptr)
	{
		mEngine->RenderTexture(Texture, *Transform, Angle, Centre, Flip, *Clip);
	}
	SDL_DestroyTexture(Texture);
	Texture = nullptr;
}
*/
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
