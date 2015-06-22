#include <iostream>
#include <string>

#include "SDL.h"

#include "World.h"

#include "UpdateManager.h"
#include "RenderManager.h"

#include "SDLExceptions.h"
#include "Constants.h"

using namespace std;

void CatchFatalExceptions(exception& e)
{
	cout << e.what() << endl;
	exit(-1);
}

int main(int argc, char* args[])
{
	World* world = new World();

	try
	{
		RenderManager* renderManager = new RenderManager(SCREEN_WIDTH, SCREEN_HEIGHT);
		UpdateManager* updateManager = new UpdateManager();

		world->SetUpdateManager(updateManager);
		world->SetRenderManager(renderManager);

		world->StartGame();

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
	catch (SDLTextureImageNotFoundException& e)
	{
		CatchFatalExceptions(e);
	}

	delete world;

	return 0;
}