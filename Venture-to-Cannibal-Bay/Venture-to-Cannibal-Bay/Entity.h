#pragma once
#include <vector>
#include <iostream>

using namespace std;
class Entity
{
protected:
	int x;
	int y;
	bool alive;
	string state;
	string orientation;

	
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
