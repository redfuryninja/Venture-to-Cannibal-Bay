#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <atlstr.h>
#include <fstream>
#include <sstream> 
#include "PrintFile.h"
#include "Player.h"
#include "Menu.h"
#include <ctime>
#include <thread>
using namespace std;

class PirateMenu : public Menu
{
private:

public:
	void displayTitle() override;
	void redrawMenu() override;
	void getKeyInput() override;
};

