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
#define KEY_UP 38
#define KEY_DOWN 40
#define KEY_LEFT 37
#define KEY_RIGHT 39
#define KEY_ENTER 13
#define KEY_E 69
#define KEY_Q 81
#define KEY_F 70

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
	int startX;
	int startY;


public:
	Entity();
	int getStartX();
	int getStartY();
	void setX(int nX);
	int getX();
	void setY(int nY);
	int getY();
	bool isAlive();
	void kill();
	EntityState getState();
	EntityOrientation getOrientation();
	void setState(EntityState nState);
	void setOrientation(EntityOrientation nOrientation);
	void setMap(Maps* currMap);
	int getKeyValue();
	bool checkSpace(int futureX, int futureY);
	virtual void Move();
	void setChar(char nChar);
};
