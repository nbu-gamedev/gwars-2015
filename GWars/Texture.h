#pragma once
#include <string>

#include "SDL.h"

using namespace std;

class Texture
{
public:
	Texture();
	Texture(string path, SDL_Renderer* renderer);
	~Texture();

	SDL_Texture* GetTexture();

	int GetWidth();
	int GetHeight();

private:
	SDL_Texture* texture;

	int width;
	int height;

	void Free();
};

