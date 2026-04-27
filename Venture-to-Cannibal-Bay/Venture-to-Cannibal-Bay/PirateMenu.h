#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream> 
#include "PrintFile.h"
#include "Menu.h"

using namespace std;

class PirateMenu : public Menu
{
private:
	string path;
public:
	PirateMenu();
	void displayTitle() override;
	void redrawMenu() override;
	bool getKeyInput() override;
	string getPath();
};

