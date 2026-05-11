#pragma once
#include <algorithm>
#include "Entity.h"
class Enemy: public Entity
{
protected:
	bool weaponDeath;
public:
	Enemy();
	bool getWeaponDeath();
	void Move() override;
};

