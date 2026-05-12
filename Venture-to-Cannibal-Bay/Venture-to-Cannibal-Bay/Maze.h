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
#include "TextColour.h"
using namespace std;

class Maze
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
	TextColour colour;

public:
	Maze();
	Maze(Player* c_User);
	virtual void mapLoop();
	void createEnemies();

};




