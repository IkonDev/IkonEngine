#pragma once
#include "Texture.h"
#include "glm\vec2.hpp"
#include "glm\vec4.hpp"
class Application;
struct SDL_Texture;
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(float DT) = 0;
	virtual void Draw(Application* RenderApp);

	void SetPosition(glm::vec2 Pos) { Position = Pos; }
	glm::vec2 GetPosition() const { return Position; }

	SDL_Texture* GetTexture() const { return Tex; }

protected:
	SDL_Texture* Tex;
	glm::vec2 Position;
	double Rotation;
};

