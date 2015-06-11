#pragma once

#include <vector>

#include "Engine.h"
#include "Actor.h"

using namespace std;

class Engine;

class World
{
public:
	World();
	World(Engine* engine);
	~World();
private:
	Engine* engine;

	vector<Actor*> leftSideEnemies;
	vector<Actor*> rightSideEnemies;
	vector<Actor*> topSideEnemies;
	vector<Actor*> botSideEnemies;

	vector<vector<Actor*>> enemies;
};

