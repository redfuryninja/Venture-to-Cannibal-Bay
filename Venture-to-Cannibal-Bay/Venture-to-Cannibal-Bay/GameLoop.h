#pragma once
#include <iostream>
#include <string>
#include "Pirate.h"
#include "Player.h"
#include "MainMenu.h"
#include "Ship.h"
using namespace std;
class GameLoop
{
private:
	Player* user;
	Pirate game;
	MainMenu Start;
	Ship map;
public:
	GameLoop();
	GameLoop(Player* c_User);
	void playGame();

};

