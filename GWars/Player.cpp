#include <string>

#include "Player.h"
#include "File.h"

#include "Constants.h"

using namespace std;

Player::Player()
{
}

Player::Player(int x, int y)
{
	this->_x = 0;
	this->_y = 0;
		
	this->_velX = 0;
    	this->_velY = 0;

	this->type = PLAYER;
}

Player::~Player()
{
}
