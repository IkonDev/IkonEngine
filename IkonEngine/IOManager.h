#pragma once

class SDL_Surface;

static class IOManager
{
public:
	static SDL_Surface* LoadSurface(char* FilePath);
};

