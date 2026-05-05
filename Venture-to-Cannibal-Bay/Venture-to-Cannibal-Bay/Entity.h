#pragma once
#include <vector>
#include <iostream>
#include "Maps.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_E 101


using namespace std;
class Entity
{
protected:
	int entityX;
	int entityY;
	bool alive;
	string state;
	string orientation;

	int mapWidth;
	int mapHeight;
	Maps* map;
	char playerChar;
	char mapChar;
	bool canMoveX;
	bool canMoveY;
	char charCheck;
	
	//These member functions are marked as protected (private when inherrited) as
	//they should only be used from within the class (e.g., only the AI should control 
	//state and orientation).
	void setX(int nX);
	int getX();
	void setY(int nY);
	int getY();
	void setState(string nState);
	void setOrientation(string nOrientation);

public:
	Entity();

	string getState();
	string getOrientation();

	bool isAlive();
	void kill();

	void setMap(Maps* currMap);
	int getKeyValue();
	bool checkSpace(int futureX, int futureY);
	void Move();
};
