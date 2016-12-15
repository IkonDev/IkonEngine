#pragma once

struct SDL_Texture;

class Texture
{
public:
	bool operator=(Texture &RHS) { return (this->TextureData == RHS.TextureData); }
	
	Texture();
	Texture(Texture &Tex);

	~Texture();

	void LoadTexture(char* FilePath);
	

private:
	SDL_Texture* TextureData;
};

