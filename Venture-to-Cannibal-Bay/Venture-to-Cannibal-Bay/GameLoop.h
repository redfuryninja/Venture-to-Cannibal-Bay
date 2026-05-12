#pragma once
#include <iostream>
#include <string>
#include "Pirate.h"
#include "Player.h"
#include "MainMenu.h"
#include "Ship.h"
#include "Beach.h"
#include "captured.h"
#include "Maze.h"
#include "End.h"
using namespace std;
class GameLoop
{
private:
	Player* user;
	Pirate game;
	Maze mazeLoop;
	MainMenu Start;
	Beach beachLoop;
	Ship shipLoop;
	captured cutscene;
	End ending;
public:
	GameLoop();
	GameLoop(Player* cUser);
	void playGame();

};

