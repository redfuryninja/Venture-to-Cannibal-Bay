#pragma once
#include "Ship.h"
class ShipRoom :public Ship
{
public:
	//constructors, one basic the other is passed a player pointer
	ShipRoom();
	ShipRoom(Player* cUser);
	//function to keep the level running
	void mapLoop() override;
};

