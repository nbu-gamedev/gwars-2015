#include <SDL.h>
#include <SDL_image.h>

#include "RenderManager.h"
#include "Actor.h"
#include "Texture.h"
#include "SDLExceptions.h"
#include "Constants.h"

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

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	this->screen = SDL_GetWindowSurface(window);

	this->Init();
}

void RenderManager::Render()
{
	// TODO: Implement actor render logic
}

void RenderManager::Render(Actor* actor)
{
	// TODO: Implement actor render logic

	Texture* actorTexture = this->textures[actor->GetType()];
	
	SDL_Rect textureToDisplay;

	textureToDisplay.x = actor->_x;
	textureToDisplay.y = actor->_y;

	textureToDisplay.w = actorTexture->GetWidth(); 
	textureToDisplay.h = actorTexture->GetHeight();

	SDL_RenderCopy(this->renderer, actorTexture->GetTexture(), NULL, &textureToDisplay);
}

void RenderManager::Init()
{	
	Texture* player = new Texture("resource/images/player.png", this->renderer);
	Texture* kamikadze = new Texture("resource/images/kamikadze.png", this->renderer);
	Texture* shooter = new Texture("resource/images/shooter.png", this->renderer);
	Texture* bullet = new Texture("resource/images/bullet.png", this->renderer);

	this->textures[PLAYER] = player;
	this->textures[KAMIKADZE] = kamikadze;
	this->textures[SHOOTER] = shooter;
	this->textures[BULLET] = bullet;
}

void RenderManager::Clear()
{
	SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->renderer);
}

void RenderManager::Update()
{
	SDL_RenderPresent(this->renderer);
}

RenderManager::~RenderManager()
{
	//Destroy window
	SDL_DestroyWindow(this->window);

	//Quit SDL subsystems
	SDL_Quit();
}
