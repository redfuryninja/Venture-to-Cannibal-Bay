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
	Pirate();
	Pirate(Player* c_User);
	void action();
	void sword();
	void gun();
	void food();
	int getKeyValue();
};

