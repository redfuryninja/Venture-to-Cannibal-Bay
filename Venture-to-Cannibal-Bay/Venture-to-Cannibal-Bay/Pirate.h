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
using namespace std;

class Pirate
{
private:
	int startClock;
	int endClock;
	bool failed;
	Player* user;
public:
	Pirate();
	Pirate(Player* c_User);
	void action();
};

