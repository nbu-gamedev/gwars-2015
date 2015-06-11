#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Settings.h"
#include "Engine.h"
#include "SDLExceptions.h"

using namespace std;

Engine::Engine(Settings settings)
{
	const int SDL_INIT_SUCCESS = 0;
	bool SDLInitalised = SDL_Init(SDL_INIT_VIDEO) == SDL_INIT_SUCCESS;

	if (!SDLInitalised)
	{
		throw SDLInitialiseException();
	}	
}

void Engine::SetWorld(World* world)
{
	// TODO: add 1-time world set validation
	this->world = world;
}

World* Engine::GetWorld()
{
	return this->world;
}

void Engine::SetRenderManager(RenderManager* manager)
{
	// TODO: add 1-time manager set validation
	this->renderManager = manager;
}

RenderManager* Engine::GetRenderManager()
{
	return this->renderManager;
}

//void Engine::Draw()
//{
//	//Fill the surface white
//	SDL_FillRect( this->screen, NULL, SDL_MapRGB( this->screen->format, 0xFF, 0xFF, 0xFF ) );
//	
//
//	//Update the surface
//	SDL_UpdateWindowSurface( window );
//}
//
//
//
//void Engine::ChangeBackground(string image)
//{
//	//Apply the PNG image
//	SDL_BlitSurface(this->LoadSurface(image), NULL, this->screen, NULL );
//			
//	//Update the surface
//	SDL_UpdateWindowSurface( this->window );
//
//	//Wait two seconds
//	SDL_Delay(10000);
//}

//Engine::Engine(Settings settings, SDL_Window* window, SDL_Surface* surface)
//{
//	bool SDLInitalised = SDL_Init(SDL_INIT_VIDEO) < 0;
//
//	this->window = window;
//	this->screen = surface;
//}

Engine::~Engine()
{
	
}