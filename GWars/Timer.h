#pragma once
#include "SDL.h"

class Timer
{
public:
	Timer();
	~Timer();

	// clock actions
	void Start();
	void Stop();
	void Pause();
	void Unpause();

	Uint32 GetTicks();

	bool IsStarted();
	bool IsPaused();
private:
	Uint32 startTicks;
	Uint32 pausedTicks;

	bool paused;
	bool started;
};