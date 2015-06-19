#pragma once

#include "SDL.h"

#include "Actor.h"
#include "UpdateManager.h"

class RenderManager
{
public:
	RenderManager();
	RenderManager(int width, int height);
	~RenderManager();
	
	void Render();
	void Render(Actor*);
private:
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Renderer* renderer;
};