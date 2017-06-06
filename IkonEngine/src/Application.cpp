#include "Application.h"
#include "IOManager.h"
#include <glm\glm.hpp>
#include <omp.h>

//Setup
Application::Application()
{
	//Get a pointer to the input handler
	Input = InputHandler::Instance(); 

	//Setup the cellular automata system
	if(Manager == nullptr)
		Manager = new CellManager(512);

	//Set the automata rule
	Manager->SetRule(RuleSet::GameOfLife);

	//Set the default update rate
	UpdateRate = 1000 / (int)Manager->GridSize;
	if (UpdateRate < 1)
		UpdateRate = 1;
	
	

	//Load a texture for display of tiles
	TileOff = IOManager::LoadTexture("Data/Tex/Game/Block.png", Engine::Instance()->GetRenderer());
	TileOn = IOManager::LoadTexture("Data/Tex/Game/Block2.png", Engine::Instance()->GetRenderer());

	//Set the background to a nice purple
	Engine::Instance()->SetRenderColour(77, 0, 77, 255);
}
//Shutdown
Application::~Application()
{
	if (Manager != nullptr)
	{
		delete Manager;
		Manager = nullptr;
	}
}

//Update loop
void Application::Update()
{	
	system("cls");
	UpdateDraw = false;
	if (Updates < 1)
	{
		UpdateDraw = true;
	}

	if (Input->IsKeyPressed(InputHandler::IkonKey::SHIFT))
	{
		if (Input->WasKeyPressed(InputHandler::IkonKey::Q))
		{
			mEngine->SetEngineState(EngineState::ENGINE_RUNNING, false);
		}
	}

	if (EnableDraw)
	{

		//Get TileSize
		TileSize = (int)(Engine::Instance()->GetScreenDimensions().y) / CamZoom;
		//Setup position
		glm::vec2 Position = Input->MousePosition;
		Position.x -= (float)StartingPoint;
		Position.y -= (float)StartingPoint;
		Position /= (float)TileSize;
		Position.x += (float)CamX;
		Position.y += (float)CamY;

		//Toggle a cells state
		if (Input->IsKeyPressed(InputHandler::IkonKey::MB_LEFT))
		{
			Manager->SetCell((int)Position.x, (int)Position.y, true);
			UpdateDraw = true;
		}
		if (Input->IsKeyPressed(InputHandler::IkonKey::MB_RIGHT))
		{
			Manager->SetCell((int)Position.x, (int)Position.y, false);
			UpdateDraw = true;
		}

		//X
		if ((Input->IsKeyPressed(InputHandler::IkonKey::LEFT) && (Updates % UpdateRate == 0)))
		{
			CamX -= (int)(CamZoom / 16);
			if (CamX < 0)
			{
				CamX = 0;
			}
			UpdateDraw = true;
		}
		if ((Input->IsKeyPressed(InputHandler::IkonKey::RIGHT) && (Updates % UpdateRate == 0)))
		{
			CamX += (int)(CamZoom / 16);
			if (CamX > (int)Manager->GridSize - CamZoom)
			{
				CamX = (int)Manager->GridSize - CamZoom;
			}
			UpdateDraw = true;
		}
		//Y
		if ((Input->IsKeyPressed(InputHandler::IkonKey::UP) && (Updates % UpdateRate == 0)))
		{
			CamY -= (int)(CamZoom / 16);
			if (CamY < 0)
			{
				CamY = 0;
			}
			UpdateDraw = true;
		}
		if ((Input->IsKeyPressed(InputHandler::IkonKey::DOWN) && (Updates % UpdateRate == 0)))
		{
			CamY += (int)(CamZoom / 16);
			if (CamY > (int)Manager->GridSize - CamZoom)
			{
				CamY = (int)Manager->GridSize - CamZoom;
			}
			UpdateDraw = true;
		}

		if ((Input->IsKeyPressed(InputHandler::IkonKey::O) && (Updates % UpdateRate == 0)))
		{
			CamZoom -= (int)(CamZoom / 8);
			if (CamZoom < 8)
			{
				CamZoom = 8;
			}
			UpdateDraw = true;
		}
		if ((Input->IsKeyPressed(InputHandler::IkonKey::P) && (Updates % UpdateRate == 0)))
		{
			CamZoom += (int)(CamZoom / 8);
			if (CamZoom > (int)Manager->GridSize)
			{
				CamZoom = (int)Manager->GridSize;
			}
			UpdateDraw = true;
		}

		//Clear the board
		if (Input->WasKeyPressed(InputHandler::IkonKey::R))
		{
			UpdateDraw = true;
			Manager->ClearArray();
		}

		//Clear the board
		if (Input->WasKeyPressed(InputHandler::IkonKey::T))
		{
			UpdateDraw = true;
			Manager->Randomize(50);
		}

		//Modify the update rate
		if (Input->WasKeyPressed(InputHandler::IkonKey::Q) && UpdateRate > 2)
			UpdateRate /= 2;

		if (Input->WasKeyPressed(InputHandler::IkonKey::W))
			UpdateRate *= 2;

		//Set the rule
		if (Input->WasKeyPressed(InputHandler::IkonKey::KEY_1))
			Manager->SetRule(RuleSet::GameOfLife);

		if (Input->WasKeyPressed(InputHandler::IkonKey::KEY_2))
			Manager->SetRule(RuleSet::LiveFreeOrDie);

		if (Input->WasKeyPressed(InputHandler::IkonKey::KEY_3))
			Manager->SetRule(RuleSet::EightLife);

		if (Input->WasKeyPressed(InputHandler::IkonKey::KEY_4))
			Manager->SetRule(RuleSet::R_2x2);

		//Load new tiles
		if (Input->WasKeyPressed(InputHandler::IkonKey::I))
		{
			TileOff = nullptr;
			TileOff = IOManager::LoadTexture("Data/Tex/Game/Block.png", Engine::Instance()->GetRenderer());
			UpdateDraw = true;
		}
	}

	//Step the simulation
	if (Input->WasKeyPressed(InputHandler::IkonKey::X))
	{
		UpdateDraw = true;
		Manager->Step();
	}

	if ((Input->IsKeyPressed(InputHandler::IkonKey::KEY_SPACE) && (Updates % UpdateRate == 0)))
	{
		UpdateDraw = true;
		Manager->Step();
	}

	if (Input->WasKeyPressed(InputHandler::IkonKey::N))
	{
		EnableDraw = !EnableDraw;
	}

	Updates++;
}


//Drawing loop
void Application::Draw()
{
	Engine::Instance()->ClearRenderer();
	if (UpdateDraw && EnableDraw)
	{

		omp_lock_t Lock;
		omp_init_lock(&Lock);
		const int GridSize = CamZoom;
		//Setup some drawing stuff
		StartingPoint = (int)(Engine::Instance()->GetScreenDimensions().y) - (CamZoom * TileSize);
		StartingPoint /= 2;

		for (int y = CamY; y < CamZoom + CamY; ++y)
		{
			#pragma omp parallel for
			for (int x = CamX; x < CamZoom + CamX; ++x)
			{

				glm::vec4 Transform;
				Transform.x = ((x - CamX) * (float)TileSize) + StartingPoint;
				Transform.y = ((y - CamY) * (float)TileSize) + StartingPoint;
				Transform.z = (float)TileSize;
				Transform.w = (float)TileSize;
				if (Manager->Test(x, y))
				{
					omp_set_lock(&Lock);
					SDL_SetTextureColorMod(TileOff, 255, 255, 255);
					RenderTexture(TileOn, Transform, 0.0f);
					SDL_SetTextureColorMod(TileOff, 255, 255, 255);
					omp_unset_lock(&Lock);
				}
				else
				{
					omp_set_lock(&Lock);
					SDL_SetTextureColorMod(TileOff, 135, 135, 135);
					if ((x % 5 == 0))
					{
						SDL_SetTextureColorMod(TileOff, 175, 175, 175);
					}
					if ((y % 5 == 0))
					{
						SDL_SetTextureColorMod(TileOff, 175, 175, 175);
					}
					RenderTexture(TileOff, Transform, 0.0f);
					SDL_SetTextureColorMod(TileOff, 255, 255, 255);
					omp_unset_lock(&Lock);
				}
			}
		}
		omp_destroy_lock(&Lock);

		UpdateWindow();
	}
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
