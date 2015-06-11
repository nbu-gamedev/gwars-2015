#include <SDL.h>
#include <SDL_image.h>

#include "RenderManager.h"
#include "SDLExceptions.h"
#include "Engine.h"

using namespace std;

RenderManager::RenderManager(Engine* engine, int width, int height)
{
	this->engine = engine;	

	this->window = SDL_CreateWindow("GWars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);

	if (window == NULL)
		throw SDLWindowCreateException();

	this->screen = SDL_GetWindowSurface(window);
}

void RenderManager::Render(Actor* actor)
{
	// draw the actor
	SDL_Surface *image = IMG_Load ( actor->GetImage().c_str() );
	if ( !image )
	{
		printf ( "IMG_Load: %s\n", IMG_GetError () );
		return;
	}

	// Draws the image on the screen:
	SDL_Rect rcDest;
	rcDest.x = actor->GetX();
	rcDest.y = actor->GetY();
	rcDest.w = 0;
	rcDest.h = 0;

	SDL_BlitSurface ( image, NULL, this->screen, &rcDest );

	// something like SDL_UpdateRect(surface, x_pos, y_pos, image->w, image->h); is missing here

	SDL_FreeSurface ( image );

	SDL_UpdateWindowSurface( this->window );

	//Wait two seconds
	SDL_Delay(3000);
}

void RenderManager::Render(string image)
{
	//Apply the PNG image
	SDL_BlitSurface(this->LoadSurface(image), NULL, this->screen, NULL );
			
	//Update the surface
	SDL_UpdateWindowSurface( this->window );

	//Wait two seconds
	SDL_Delay(3000);
}

SDL_Surface* RenderManager::LoadSurface(string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, this->screen->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}


RenderManager::~RenderManager()
{
	//Destroy window
	SDL_DestroyWindow(this->window);

	//Quit SDL subsystems
	SDL_Quit();
}
