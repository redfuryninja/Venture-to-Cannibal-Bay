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
#include "Maps"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_E 101

class Player
{
private:
	int lives;
	int food;
	int ammo;
	int playerX;
	int playerY;
	int mapWidth;
	int mapHeight;
	Maps* map;
	char playerChar;
	char mapChar;
	bool canMoveX;
	bool canMoveY;

public:
	Player();
	Player(string* curMap);
	int getLives();
	int getFood();
	int getAmmo();
	void setLives(int nLives);
	void setFood(int nFood);
	void setAmmo(int nAmmo);
	int getKeyValue();
};

