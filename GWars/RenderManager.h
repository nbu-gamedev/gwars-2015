#pragma once
#include <map>

#include "SDL.h"

#include "Actor.h"
#include "UpdateManager.h"
#include "Texture.h"
#include "Constants.h"

class RenderManager
{
public:
	RenderManager();
	RenderManager(int width, int height);
	~RenderManager();
	
	void Render();
	void Render(Actor*);

	void Clear();
	void Update();
private:
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Renderer* renderer;

	map<Actors, Texture*> textures;

	void Init();
};