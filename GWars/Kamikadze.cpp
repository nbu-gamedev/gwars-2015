#include <string>

#include "Kamikadze.h"

using namespace std;

Kamikadze::Kamikadze()
{
	this->x = DEFAULT_X_LOCATION;
	this->y = DEFAULT_Y_LOCATION;
}

Kamikadze::Kamikadze(int x, int y, string image)
{
	this->x = x;
	this->y = y;

	this->image = image;
}

Kamikadze::~Kamikadze()
{
}
