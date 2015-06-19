#include "World.h"
#include "Actor.h"
#include "UpdateManager.h"
#include "RenderManager.h"

World::World()
{
}

World::World(UpdateManager* updateManager, RenderManager* renderManager)
{
	this->gameIsFinished = false;

	this->updateManager = updateManager;
	this->renderManager = renderManager;
}

void World::SetRenderManager(RenderManager* renderManager)
{
	this->renderManager = renderManager;
}

void World::SetUpdateManager(UpdateManager* renderManager)
{
	this->updateManager = updateManager;
}

void World::StartGame()
{
	// player->IsAlive()
	while (true)
	{
		this->updateManager->Update();
		this->renderManager->Render();
	}
}

World::~World()
{
	delete this->renderManager;
	delete this->updateManager;
}
