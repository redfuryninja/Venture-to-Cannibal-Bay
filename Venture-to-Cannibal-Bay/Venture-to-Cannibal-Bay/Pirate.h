#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <atlstr.h>
#include <fstream>
#include <sstream> 
#include "GameLoop.h"
#include "PrintFile.h"
#include "Player.h"
#include "Menu.h"

class Pirate: public Menu
{
private:
	int start;
	int end;
public:
	void displayTitle() override;
	void redrawMenu() override;
	void Action(Player& user);

};

