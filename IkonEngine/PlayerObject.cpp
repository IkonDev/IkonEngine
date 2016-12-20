#include "PlayerObject.h"
#include "Application.h"
#include "IOManager.h"
#include <SDL.h>

PlayerObject::PlayerObject()
{
	Tex = IOManager::LoadTexture("Data/Tex/PINGA-1.png", Engine::GetEngine()->GetRenderer());
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Update(float DT)
{
	//Set texture based on current keystate
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_UP])
	{
		Position.y -= (float)TILESIZE;
	}
	if (currentKeyStates[SDL_SCANCODE_DOWN])
	{
		Position.y += (float)TILESIZE;
	}
	if (currentKeyStates[SDL_SCANCODE_LEFT])
	{
		Position.x -= (float)TILESIZE;
	}
	if (currentKeyStates[SDL_SCANCODE_RIGHT])
	{
		Position.x += (float)TILESIZE;
	}
}

void PlayerObject::Draw(Application* RenderApp)
{
	glm::vec4 Transform;
	Transform.x = Position.x;
	Transform.y = Position.y;
	Transform.z = (float)TILESIZE;
	Transform.w = (float)TILESIZE;

	if(Tex != nullptr)
		RenderApp->RenderTexture(Tex, Transform);
}

