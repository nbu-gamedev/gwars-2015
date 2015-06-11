#include <iostream>
#include <string>

#include "SDL.h"

#include "Settings.h"
#include "World.h"
#include "Engine.h"
#include "Kamikadze.h"
#include "SDLExceptions.h"

using namespace std;

int main(int argc, char* args[])
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	Settings settings(SCREEN_WIDTH, SCREEN_HEIGHT);	

	try
	{
		Engine* engine = new Engine(settings);

		RenderManager* renderManager = new RenderManager(engine, SCREEN_WIDTH, SCREEN_HEIGHT);

		World* world = new World(engine);

		engine->SetWorld(world);
		engine->SetRenderManager(renderManager);

		// Update the background
		renderManager->Render("universe.png");

		// Create and draw the player
		Actor* player = new Kamikadze(300, 300, "ship.png");
		renderManager->Render(player);

		player->Update();
		
	}
	catch (SDLInitialiseException& e)
	{
		cout << e.what() << endl;
	}
	catch (SDLWindowCreateException& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}