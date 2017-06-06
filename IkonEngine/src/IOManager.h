#pragma once
#include <string>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_PixelFormat;
struct SDL_Renderer;

class IOManager
{
public:
	static SDL_Surface* LoadSurface(char* FilePath, const SDL_PixelFormat* Format = nullptr);
	static SDL_Texture* LoadTexture(char* FilePath, SDL_Renderer* Renderer, const SDL_PixelFormat* Format = nullptr);
};

