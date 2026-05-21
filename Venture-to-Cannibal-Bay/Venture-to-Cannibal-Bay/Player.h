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
#include "TextTree.h"
using namespace std;

//inherits from entity
class Player: public Entity
{
private:
	int lives;
	int food;
	int ammo;
	bool shipKey;
	int clues;
	int totalClues;
	vector<char> enemyChar;
	TextTree tree;
	vector <Entity> magazine;
	vector <Entity> projectiles;
	Entity bullet;
	bool repeat;
public:
	//constructor
	Player();
	//getters and setters for all the variables
	void setStartX(int nX);
	void setStartY(int nY);
	bool getRepeat();
	void setRepeat(bool nRepeat);
	int getTotalClues();
	void setTotalClues(int nClues);
	int getClues();
	void setTreePoint();
	void setClues(int nClues);
	int getLives();
	int getFood();
	int getAmmo();
	bool getShipKey();
	void setShipKey(bool nKey);
	bool checkIfKey(int futureX, int futureY);
	void setLives(int nLives);
	void setFood(int nFood);
	void setAmmo(int nAmmo);
	//checks if player can shoot
	void shoot();
	//moves the player
	void Move() override;
	//checks if the enemy is on a tile
	bool checkIfEnemy(int futureX, int futureY);
	//changes alive variable to true
	void revive();
	//fill a variable with an entity to serve as a projectile
	void fillMag();
	//spawns the projectile infront of player
	void shootBullet();
	//handels projectile movement
	void moveBullet();
	//outputs text for the story
	void outputClue();
};

