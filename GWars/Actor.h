#pragma once

#include "File.h"

class Actor
{
public:
	Actor();
	Actor(int x, int y, File* img);
	~Actor();

	int _x, _y;
	File* _displayImage;
};
