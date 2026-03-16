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
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
class Menu
{
protected:
	int menuPosition;
	bool waiting;
	int keyValue;

public:
	Menu();
	int getKeyValue();
	void getKeyInput();
	void displayTitle();
	void displayMenu();
	virtual void redrawMenu();


};
