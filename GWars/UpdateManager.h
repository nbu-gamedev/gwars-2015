#pragma once

#include <cstdlib>
#include <sys/timeb.h>

#include "SDL.h"

#include "Actor.h"
#include "Player.h"
#include "Kamikadze.h"

class UpdateManager
{
public:
	UpdateManager();
	~UpdateManager();
	
	void Update();
	void Update(Actor*);

	void HandleEvent(Player* player, SDL_Event& event);

	void MovePlayer(Player* player);
	void FollowPlayer(Actor* kamikadze, Player* player);
private:
	long GetMilliSeconds();
};

