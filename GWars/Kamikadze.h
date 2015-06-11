#pragma once
#include <iostream>
#include <string>

#include "actor.h"

using namespace std;

class Kamikadze : public Actor
{
public:
	Kamikadze();
	Kamikadze(int x, int y, string image);
	~Kamikadze();

	virtual void Update()
	{
		// TODO: Update kami
		cout << "Kamikadze - updated!" << endl;
	}
};

