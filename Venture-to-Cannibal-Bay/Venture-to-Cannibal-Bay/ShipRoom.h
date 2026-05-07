#pragma once
#include "Ship.h"
class ShipRoom :public Ship
{
public:
	ShipRoom();
	void mapLoop() override;
};

