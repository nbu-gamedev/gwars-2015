#include "Actor.h"

Actor::Actor()
{
	this->_x = 0;
	this->_y = 0;
}

Actor::Actor(int x, int y, File* img)
{
	this->_x = 0;
	this->_y = 0;
	this->_displayImage = img;
}

Actor::~Actor()
{
	delete this->_displayImage;
}
