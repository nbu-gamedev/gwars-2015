#pragma once

#include <string>

#include <SDL.h>

#include "Settings.h"
#include "World.h"
#include "RenderManager.h"

using namespace std;

class World;
class RenderManager;

class Engine
{
public:
	Engine(Settings settings);
	//Engine(Settings settings, SDL_Window* window, SDL_Surface* surface);
	~Engine();

	//SDL_Surface* LoadSurface(string img);

	void SetWorld(World* world);
	World* GetWorld();

	void SetRenderManager(RenderManager* manager);
	RenderManager* GetRenderManager();

	void LoadSettings(Settings settings);
private:
	World* world;

	RenderManager* renderManager;
};

