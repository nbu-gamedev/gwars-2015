#include <exception>

#include "SDL.h"

using namespace std;

struct SDLInitialiseException : public exception
{
	virtual const char * what () const throw ()
	{
		return "SDL Failed to initialise!";
	}
};

struct SDLWindowCreateException: public exception
{
	virtual const char* what() const throw()
	{
		return "DL failed to create the game window!";
	}
};