#include <SDL.h>
#include <SDL_image.h>

#include "RenderManager.h"
#include "Actor.h"
#include "SDLExceptions.h"

using namespace std;

RenderManager::RenderManager(int width, int height)
{
	const int SDL_INIT_SUCCESS = 0;

	bool SDLInitalised = SDL_Init(SDL_INIT_VIDEO) == SDL_INIT_SUCCESS;

	if (!SDLInitalised)
		throw SDLInitialiseException();

	//SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

	this->window = SDL_CreateWindow("GWars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);

	if (this->window == NULL)
		throw SDLWindowCreateException();

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED );

	this->screen = SDL_GetWindowSurface(window);
}

void RenderManager::Render()
{
	// TODO: Implement actor render logic
}

void RenderManager::Render(Actor* actor)
{
	// TODO: Implement actor render logic
}

RenderManager::~RenderManager()
{
	//Destroy window
	SDL_DestroyWindow(this->window);

	//Quit SDL subsystems
	SDL_Quit();
}
