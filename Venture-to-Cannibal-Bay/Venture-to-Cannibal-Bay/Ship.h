#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <iostream>
#include <string>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_E 101
using namespace std;
class Ship
{
private:
	int playerX;
	int playerY;
	int mapWidth;
	int mapHeight;
	string map;
	bool collisionX;
	bool collisionY;
	char playerChar;
	char mapChar;
	bool canMoveX;
	bool canMoveY;
	string filename;
	ifstream artFile;
	string linePrint;
public:
	Ship();
	void outputMap();
	bool checkHorizontal(int futureX, int futureY);
	bool checkVertical(int futureX, int futureY);
	int getKeyValue();
	void mapLoop();
};

