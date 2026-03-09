#pragma once
#include <vector>
#include <iostream>

using namespace std;
class Entity
{
protected:
	int x;
	int y;
	int z;
	bool alive;
	string state;
	string orientation;

	//These member functions are marked as protected (private when inherrited) as
	//they should only be used from within the class (e.g., only the AI should control 
	//state and orientation).
	void setX(int nX);
	int getX();
	void setState(string nState);
	void setOrientation(string nOrientation);

public:
	Entity();

	string getState();
	string getOrientation();

	bool isAlive();
	void kill();

	virtual void setLocation(vector<string>& gameMap, int nX) = 0;

	virtual void update(vector<string>& gameMap) = 0;
};

