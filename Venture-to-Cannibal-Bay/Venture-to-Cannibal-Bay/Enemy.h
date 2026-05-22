#pragma once
#include <algorithm>
#include "Entity.h"
//inherits from entity or the purposes of setting up the object
class Enemy: public Entity
{
protected:
	bool weaponDeath;
public:
	//constructer
	Enemy();
	//returens weapondeath
	bool getWeaponDeath();
	//handles movement of the Enenmy Object
	void Move() override;
};

