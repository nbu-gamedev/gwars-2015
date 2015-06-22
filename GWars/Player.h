#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	Player(int x, int y);
	~Player();
	
	//The velocity of the dot
	int _velX, _velY;
};