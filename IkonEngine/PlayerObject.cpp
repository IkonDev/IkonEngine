#include "PlayerObject.h"
#include "Application.h"
#include "IOManager.h"
#include <SDL.h>

#define PI 3.14159265359

PlayerObject::PlayerObject()
{
	Tex = IOManager::LoadTexture("Data/Tex/Game/Dude.png", Engine::GetEngine()->GetRenderer());
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Update(float DT)
{
	double xRot =  sin(Rotation * PI / 180);
	double yRot = -cos(Rotation * PI / 180);
	glm::vec2 Rot = glm::vec2(xRot, yRot);
	Rot = glm::normalize(Rot);

	//Set texture based on current keystate
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_UP])
	{
		Position += Rot * DT;
	}
	if (currentKeyStates[SDL_SCANCODE_DOWN])
	{
		Position -= Rot * DT;
	}
	if (currentKeyStates[SDL_SCANCODE_LEFT])
	{
		Rotation -= 1.5 * DT;
	}
	if (currentKeyStates[SDL_SCANCODE_RIGHT])
	{
		Rotation += 1.5 * DT;
	}
}

void PlayerObject::Draw(Application* RenderApp)
{
	GameObject::Draw(RenderApp);
}

