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
using namespace std;
class captured
{
private:
	string fileName;
	Player* user;
	TextColour colour;
public:
	captured();
	captured(Player* c_User);
	void cutscene();
};

