#include "GameObject.h"
#include <SDL_Render.h>
#include "Application.h"
GameObject::GameObject()
{
	Tex = nullptr;
	Position = glm::vec2(0);
	Rotation = 0;
}

GameObject::~GameObject()
{
	if (Tex != nullptr)
		SDL_DestroyTexture(Tex);
}

void GameObject::Draw(Application* RenderApp)
{
	glm::vec4 Transform;
	Transform.x = Position.x;
	Transform.y = Position.y;
	Transform.z = (float)TILESIZE;
	Transform.w = (float)TILESIZE;

	if (Tex != nullptr)
		RenderApp->RenderTexture(Tex, Transform, Rotation, glm::vec2((float)TILESIZE / 2, (float)TILESIZE / 2));
}
