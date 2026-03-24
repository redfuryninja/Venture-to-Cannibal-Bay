#pragma once
#include <iostream>
#include <string>
#include "Pirate.h"
#include "Player.h"
using namespace std;
class GameLoop
{
private:
	Player* user;
	Pirate game;
public:
	GameLoop();
	GameLoop(Player* c_User);
	void playGame();

};

