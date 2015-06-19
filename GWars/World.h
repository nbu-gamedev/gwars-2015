#pragma once

class UpdateManager;
class RenderManager;

class World
{
public:
	World();
	World(UpdateManager*, RenderManager*);
	~World();
	
	void SetUpdateManager(UpdateManager*);
	void SetRenderManager(RenderManager*);

	void StartGame();
private:
	bool gameIsFinished;

	UpdateManager* updateManager;
	RenderManager* renderManager;
};

