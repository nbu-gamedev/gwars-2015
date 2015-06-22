#include <string>

#include "Kamikadze.h"

using namespace std;

Kamikadze::Kamikadze()
{
}

Kamikadze::Kamikadze(int x, int y)
{
	this->_x = x;
	this->_y = y;

	this->type = KAMIKADZE;
}


Kamikadze::~Kamikadze()
{
}
