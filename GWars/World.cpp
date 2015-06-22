#include "World.h"

#include "UpdateManager.h"
#include "RenderManager.h"

#include "Actor.h"
#include "Player.h"
#include "Kamikadze.h"

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
	SDL_Event e;
	
	Player* player = new Player(0, 0);

	Actor* kami = new Kamikadze(150, 150);

	//While application is running
	while (true)
	{
		//Handle events on queue
		while (SDL_PollEvent( &e ) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				// TODO: Fix this, need to call destructors etc.
				exit(-1);
			}

			this->updateManager->HandleEvent(player, e);
		}

		this->updateManager->MovePlayer(player);

		this->updateManager->FollowPlayer(kami, player);

		this->renderManager->Clear();

		this->renderManager->Render(player);

		this->renderManager->Render(kami);
		
		this->renderManager->Update();
	}
}

World::~World()
{
	delete this->renderManager;
	delete this->updateManager;
}
