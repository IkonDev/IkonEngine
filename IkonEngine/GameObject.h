#pragma once
#include "Texture.h"
#include "glm\vec2.hpp"
class Application;
struct SDL_Texture;
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(float DT) = 0;
	virtual void Draw(Application* RenderApp) = 0;

	void SetPosition(glm::vec2 Pos) { Position = Pos; }
	glm::vec2 GetPosition() const { return Position; }

protected:
	SDL_Texture* Tex;
	glm::vec2 Position;
};

