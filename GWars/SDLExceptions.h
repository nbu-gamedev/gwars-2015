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

struct SDLWindowCreateException : public exception
{
	virtual const char* what() const throw()
	{
		return "SDL failed to create the game window!";
	}
};

struct SDLTextureImageNotFoundException : public exception
{
	virtual const char* what() const throw()
	{
		return "Texture image not not found!";
	}
};

struct SDLTextureCreationException : public exception
{
	virtual const char* what() const throw()
	{
		return "Texture image not not found!";
	}
};