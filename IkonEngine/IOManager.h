#pragma once

struct SDL_Surface;
struct SDL_PixelFormat;

static class IOManager
{
public:
	static SDL_Surface* LoadSurface(char* FilePath, const SDL_PixelFormat* Format);
};

