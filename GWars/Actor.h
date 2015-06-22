#pragma once

#include <string>

#include "Constants.h"

using namespace std;

class Actor
{
public:
	Actor();
	~Actor();

	Actors GetType();

	int _x, _y;
protected:
	Actors type;
};
