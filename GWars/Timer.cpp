#include "Timer.h"


Timer::Timer()
{
	this->startTicks = 0;
	this->pausedTicks = 0;

	this->paused = false;
	this->started = false;
}

void Timer::Start()
{
    this->started = true;
    this->paused = false;

	this->startTicks = SDL_GetTicks();
	this->pausedTicks = 0;
}

void Timer::Stop()
{
    //Stop the timer
    this->started = false;

    //Unpause the timer
    this->paused = false;

	//Clear tick variables
	this->startTicks = 0;
	this->pausedTicks = 0;
}

void Timer::Pause()
{
	 if (this->started && !this->paused)
	 {

        this->paused = true;

        this->pausedTicks = SDL_GetTicks() - this->startTicks;
		this->startTicks = 0;
    }
}

void Timer::Unpause()
{
    //If the timer is running and paused
    if (this->started && this->paused)
    {
        //Unpause the timer
        this->paused = false;

        //Reset the starting ticks
        this->startTicks = SDL_GetTicks() - this->pausedTicks;

        //Reset the paused ticks
        this->pausedTicks = 0;
    }
}

Uint32 Timer::GetTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if (this->started)
    {
        //If the timer is paused
        if (this->paused)
        {
            //Return the number of ticks when the timer was paused
            time = this->pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - this->startTicks;
        }
    }

    return time;
}

bool Timer::IsStarted()
{
	//Timer is running and paused or unpaused
    return this->started;
}

bool Timer::IsPaused()
{
	//Timer is running and paused
    return this->paused && this->started;
}

Timer::~Timer()
{
}