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
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_E 101
#define KEY_Q 113

using namespace std;

enum EntityOrientation {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

enum EntityState {
	NUETRAL,
	SLASHING,
	SHOOTING,
	MOVING
};

class Entity
{
protected:
	int entityX;
	int entityY;
	bool alive;
	EntityState state;
	EntityOrientation orientation;
	int mapWidth;
	int mapHeight;
	Maps* map;
	char entityChar;
	char mapChar;
	bool canMoveX;
	bool canMoveY;
	char charCheck;
	int projX;
	int projY;


public:
	Entity();

	void setX(int nX);
	int getX();
	void setY(int nY);
	int getY();
	bool isAlive();
	void kill();

	void setMap(Maps* currMap);
	int getKeyValue();
	bool checkSpace(int futureX, int futureY);
	virtual void Move();
};
