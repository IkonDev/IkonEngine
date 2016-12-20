#pragma once
#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject();
	~PlayerObject();

	// Inherited via GameObject
	virtual void Update(float DT) override;
	virtual void Draw(Application* RenderApp) override;

};

