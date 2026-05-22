#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include <fstream>
#include <sstream> 
#include <ctime>
#include <thread>
#include "Player.h"
#include "Animation.h"
#include "TextColour.h"
//sets the value of Key_E so it can be called when getting value of key input

#define KEY_E 101
using namespace std;

class Pirate
{
private:
	int startClock;
	int endClock;
	bool failed;
	Player* user;
	Animation ani;
	TextColour colour;
public:
	//constructors
	Pirate();
	Pirate(Player* c_User);
	//main loop
	void action();
	//paths for the different choices the player can make
	void sword();
	void gun();
	void food();
	//gets player inputs
	int getKeyValue();
};

