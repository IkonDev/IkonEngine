#include "Texture.h"
#include "IOManager.h"
#include "Engine.h"
#include <string>
#include <SDL.h>
Texture::Texture()
{
	TextureData = nullptr;
}

Texture::Texture(Texture &Tex)
{
	this->TextureData = Tex.TextureData;
}

Texture::~Texture()
{
	if (TextureData != nullptr)
	{
		SDL_DestroyTexture(TextureData);
		TextureData = nullptr;
	}
}

void Texture::LoadTexture(char* FilePath)
{
	TextureData = IOManager::LoadTexture(FilePath, Engine::Instance()->GetRenderer());
}

void Texture::SetColourMod(unsigned int red, unsigned int green, unsigned int blue)
{
	//Modulate texture
	SDL_SetTextureColorMod(TextureData, red, green, blue);
}
