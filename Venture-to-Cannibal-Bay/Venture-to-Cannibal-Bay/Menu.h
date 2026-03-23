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
#include "GameLoop.h"
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
	string fileName;
	Player* user;
	GameLoop game;
public:
	Menu();
	Menu(Player* c_User);
	int getKeyValue();
	virtual void getKeyInput();
	virtual void displayTitle();
	void displayMenu();
	virtual void redrawMenu();


};
