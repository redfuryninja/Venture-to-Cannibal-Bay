#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream> 
#include <conio.h>
#include "Maps.h"
#include "Entity.h"
using namespace std;


class Player: public Entity
{
private:
	int lives;
	int food;
	int ammo;
	Entity* bullet;

public:
	Player();

	int getLives();
	int getFood();
	int getAmmo();
	void setLives(int nLives);
	void setFood(int nFood);
	void setAmmo(int nAmmo);
	void shoot();
	void Move() override;
};

