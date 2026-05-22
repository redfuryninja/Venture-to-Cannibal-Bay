#pragma once
#include <iostream>
#include <thread>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream> 
#include <conio.h>
#include "Maps.h"
#include "TextTree.h"
#include "Player.h"
#include "PrintFile.h"
#include "TextColour.h"

#include <vector>
using namespace std;
class End
{
private:
	string fileName;
	Player* user;
	TextColour colour;
	vector<vector<string>> endMessage;

public:
	End();
	End(Player* cUser);
	//loops through the neding sequences of the game
	void Ending();
};