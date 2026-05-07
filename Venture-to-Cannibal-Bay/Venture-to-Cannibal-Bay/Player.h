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
	bool key;
	vector<char> enemyChar;

public:
	Player();

	int getLives();
	int getFood();
	int getAmmo();
	bool getKey();
	void setKey(bool nKey);
	bool checkifKey(int futureX, int futureY);
	void setLives(int nLives);
	void setFood(int nFood);
	void setAmmo(int nAmmo);
	void shoot();
	void Move() override;
	bool checkIfEnemy(int futureX, int futureY);
	void revive();
};

