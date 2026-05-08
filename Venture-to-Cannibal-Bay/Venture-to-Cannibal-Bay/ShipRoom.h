#pragma once
#include "Ship.h"
class ShipRoom :public Ship
{
public:
	ShipRoom();
	ShipRoom(Player* cUser);
	void mapLoop() override;
};

