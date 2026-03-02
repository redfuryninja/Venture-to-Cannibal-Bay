#pragma once
#include <iostream>
#include <string>
#include "AsciiArt.h"
#include <windows.h>
#include <conio.h>
#include <atlstr.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
class Menu
{
private:
	int menuPosition;
	bool waiting;
	int keyValue;

public:
	Menu();
	int getKeyInput();
	void displayTitle();
	void displayMenu();
	void redrawMenu();


};

