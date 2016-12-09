#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	void SetEngine(Engine* aEngine) { mEngine = aEngine; }

	void BlitImage(char* FilePath);
private:
	Engine* mEngine = nullptr;
};

