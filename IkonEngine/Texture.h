#pragma once

struct SDL_Texture;

class Texture
{
public:
	Texture();
	Texture(Texture &Tex);

	~Texture();

	void LoadTexture(char* FilePath);
	SDL_Texture* GetTexture() const { return TextureData; }

private:
	SDL_Texture* TextureData;
};

