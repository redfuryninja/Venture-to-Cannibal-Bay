#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <thread>
#include "Entity.h"
class Player: public Entity
{
protected:
	int lives;
	int food;
	int ammo;
public:
	Player();
	int getLives();
	int getFood();
	int getAmmo();
	void setLives(int nLives);
	void setFood(int nFood);
	void setAmmo(int nAmmo);
};

