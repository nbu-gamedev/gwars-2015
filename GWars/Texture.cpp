#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"

#include "SDLExceptions.h"

using namespace std;
Texture::Texture()
{
}

Texture::Texture(string path, SDL_Renderer* renderer)
{
	this->Free();

	//The final texture
	SDL_Texture* texture = NULL;

	//Load image from the path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

	if( loadedSurface == NULL )
	{
		cout << SDL_GetError() << endl;
		throw SDLTextureImageNotFoundException();
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if(texture == NULL)
		{
			cout << SDL_GetError() << endl;
			throw SDLTextureCreationException();
		}
		else
		{
			//Get image dimensions
			this->width = loadedSurface->w;
			this->height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	this->texture = texture;
}

SDL_Texture* Texture::GetTexture()
{
	return this->texture;
}

int Texture::GetHeight()
{
	return this->height;
}

int Texture::GetWidth()
{
	return this->width;
}

void Texture::Free()
{
	if( this->texture != NULL )
	{
		SDL_DestroyTexture(this->texture);
		this->texture = NULL;

		this->width = 0;
		this->height = 0;
	}
}

Texture::~Texture()
{
	this->Free();
}
