#include <iostream>
#include <string>

#include "SDL.h"

#include "Settings.h"
#include "World.h"
#include "UpdateManager.h"
#include "RenderManager.h"
#include "Kamikadze.h"
#include "SDLExceptions.h"
#include "File.h"
#include "Actor.h"

using namespace std;

void CatchFatalExceptions(exception& e)
{
	cout << e.what() << endl;
	exit(-1);
}

int main(int argc, char* args[])
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	World* world = new World();

	try
	{
		RenderManager* renderManager = new RenderManager(SCREEN_WIDTH, SCREEN_HEIGHT);
		UpdateManager* updateManager = new UpdateManager();

		world->SetUpdateManager(updateManager);
		world->SetRenderManager(renderManager);

		world->StartGame();
		
		Actor* pesho = new Actor();
		Actor* gosho = new Actor();		

		delete world;
	}
	catch (SDLInitialiseException& e)
	{
		CatchFatalExceptions(e);
	}
	catch (SDLWindowCreateException& e)
	{
		CatchFatalExceptions(e);		
	}

	delete world;

	return 0;
}