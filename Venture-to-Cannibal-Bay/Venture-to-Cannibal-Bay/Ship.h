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
#include "Player.h"
#include "Enemy.h"
#include "RangeEnemy.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_E 101
using namespace std;
class Ship
{
protected:
	int playerX;
	int playerY;
	int mapWidth;
	int mapHeight;
	Maps map;
	Maps* mapPointer;
	char playerChar;
	char mapChar;
	bool canMoveX;
	bool canMoveY;
	string filename;
	ifstream artFile;
	string linePrint;
	Player* user;
	vector <Entity> magazine;
	Entity bullet;
	vector <Enemy> meleeEnemies;
	vector<RangeEnemy> rangedEnemies;
	vector <Entity> projectiles;

public:
	//default constructorer and one with player
	Ship();
	Ship(Player* c_User);
	//looops through the player map
	virtual void mapLoop();
	//creates the enemies for the level
	void createEnemies();

};

