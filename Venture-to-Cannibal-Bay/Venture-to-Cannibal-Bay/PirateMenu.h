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

public:
	void displayTitle() override;
	void redrawMenu() override;
	void getKeyInput() override;
	void animation();
};

