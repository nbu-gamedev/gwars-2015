#include "Actor.h"

Actor::Actor()
{

}

string Actor::GetImage()
{
	return this->image;
}

int Actor::GetX()
{
	return this->x;
}

int Actor::GetY()
{
	return this->y;
}

void Actor::SetX(int x)
{
	//TODO: Add validation?
	this->x = x;
}

void Actor::SetY(int y)
{
	//TODO: Add validation?
	this->y = y;
}

void Actor::Update()
{

}

Actor::~Actor()
{
}
