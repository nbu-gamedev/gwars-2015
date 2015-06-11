#pragma once

#include <string>

#include "Engine.h"
#include "Actor.h"

using namespace std;

class Engine;

class RenderManager
{
public:
	RenderManager(Engine* engine, int width, int height);
	~RenderManager();

	void Render(Actor* actor);
	void Render(string img);
private:
	Engine* engine;

	SDL_Window* window;
	SDL_Surface* screen;

	SDL_Surface* LoadSurface(string path);
};

