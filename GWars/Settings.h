#pragma once
class Settings
{
public:
	Settings(int screenWidth = 640, int screenHeight = 480);
	~Settings();
	
	int GetWidth()
	{
		return this->screenWidth;
	}
	int GetHeight()
	{
		return this->screenHeight;
	}
private:
	int screenWidth;
	int screenHeight;
};

