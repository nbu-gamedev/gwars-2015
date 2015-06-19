#pragma once

#include <cstdlib>
#include <sys/timeb.h>

#include "Actor.h"

class UpdateManager
{
public:
	UpdateManager();
	~UpdateManager();
	
	void Update();
	void Update(Actor*);
private:
	long GetMilliSeconds();
};

