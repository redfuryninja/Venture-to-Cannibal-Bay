#pragma once
#include <iostream>
#include <string>
#include "Pirate.h"
#include "Player.h"
#include "MainMenu.h"
#include "Ship.h"
#include "Beach.h"
using namespace std;
class GameLoop
{
private:
	Player* user;
	Pirate game;
	MainMenu Start;
	Beach beachLoop;
	Ship shipLoop;
public:
	GameLoop();
	GameLoop(Player* cUser);
	void playGame();

};

