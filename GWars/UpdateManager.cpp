#include <cstdlib>
#include <sys/timeb.h>

#include "UpdateManager.h"
#include "Actor.h"


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
