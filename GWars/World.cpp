#include "World.h"
#include "Engine.h"

using namespace std;

World::World(Engine* engine)
{
	this->engine = engine;
	
	enemies.push_back(leftSideEnemies);
	enemies.push_back(rightSideEnemies);
	enemies.push_back(topSideEnemies);
	enemies.push_back(botSideEnemies);
}


World::~World()
{
}
