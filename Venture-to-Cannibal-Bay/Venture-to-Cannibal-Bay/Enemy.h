#pragma once
#include <algorithm>
#include "Entity.h"
class Enemy: public Entity
{
private:
	vector<char> playerChars;
	vector<char> playerWeapon;
	bool weaponDeath;
public:
	Enemy();
	bool checkIfPlayer(int futureX, int futureY);
	bool checkIfWeapon(int futureX, int futureY);
	bool getWeaponDeath();
	void Move() override;
};

