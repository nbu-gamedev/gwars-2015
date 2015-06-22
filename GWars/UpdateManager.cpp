#include <cstdlib>
#include <sys/timeb.h>
#include <ctime>

#include "UpdateManager.h"

#include "Actor.h"
#include "Player.h"
#include "Constants.h"


UpdateManager::UpdateManager()
{
}

void UpdateManager::Update()
{
	// TODO: Implement update manager logic
}

void UpdateManager::Update(Actor*)
{
	// TODO: Implement update manager logic
}

void UpdateManager::HandleEvent(Player* player, SDL_Event &e)
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
			case SDLK_UP: player->_velY -= PLAYER_VEL; break;
            case SDLK_DOWN: player->_velY  += PLAYER_VEL; break;
            case SDLK_LEFT: player->_velX -= PLAYER_VEL; break;
            case SDLK_RIGHT: player->_velX += PLAYER_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player->_velY += PLAYER_VEL; break;
            case SDLK_DOWN: player->_velY -= PLAYER_VEL; break;
            case SDLK_LEFT: player->_velX += PLAYER_VEL; break;
            case SDLK_RIGHT: player->_velX -= PLAYER_VEL; break;
        }
    }
}

void UpdateManager::MovePlayer(Player* player)
{
	//Move the dot left or right
	player->_x += player->_velX;

    //If the dot went too far to the left or right
    if((player->_x < 0) || (player->_x + PLAYER_WIDTH > SCREEN_WIDTH) )
    {
        //Move back
        player->_x -= player->_velX;
    }

    //Move the dot up or down
    player->_y += player->_velY;

    //If the dot went too far up or down
    if( ( player->_y < 0 ) || ( player->_y + PLAYER_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        player->_y -= player->_velY;
    }
}

void UpdateManager::FollowPlayer(Actor* kamikadze, Player* player)
{
	srand(time(0));

	kamikadze->_x = player->_x - 50;
	kamikadze->_y = player->_y - 50;
}

long UpdateManager::GetMilliSeconds()
{
	timeb tb;
	ftime(&tb);
	long nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

UpdateManager::~UpdateManager()
{
}
