#include "GameObject.h"
#include <SDL_Render.h>
GameObject::GameObject()
{
	Tex = nullptr;
	Position = glm::vec2(0);
}

GameObject::~GameObject()
{
	if (Tex != nullptr)
		SDL_DestroyTexture(Tex);
}