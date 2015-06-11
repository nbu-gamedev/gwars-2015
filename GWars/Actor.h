#pragma once

#include <string>

using namespace std;

class Actor
{
public:
	Actor();
	Actor(int x, int y, string image);
	~Actor();

	int GetX();
	void SetX(int x);

	int GetY();
	void SetY(int y);

	string GetImage();

	virtual void Update() = 0;
protected:
	static const int DEFAULT_X_LOCATION = 0;
	static const int DEFAULT_Y_LOCATION = 0;

	string image;

	int x;
	int y;
};

