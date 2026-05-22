#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream> 
#include "PrintFile.h"
#include "Menu.h"
#include "TextColour.h"

using namespace std;

class PirateMenu : public Menu
{
private:
	string path;
public:
	//constructor
	PirateMenu();
	//displays ascii art
	void displayTitle() override;
	//rewrites menu to reflect player input
	void redrawMenu() override;
	// gets the player input
	bool getKeyInput() override;
	//gets the path reflceting hte players choice
	string getPath();
};

