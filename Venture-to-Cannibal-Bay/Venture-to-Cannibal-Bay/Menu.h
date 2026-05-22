#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include <fstream>
#include <sstream> 
#include "PrintFile.h"
#include "Player.h"
using namespace std;
//defining key input values that match with microsoft key input codes
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
	string path;
public:
	//constructors
	Menu();
	Menu(Player* c_User);
	//get value of input
	int getKeyValue();
	//get the key input and act upon it
	virtual bool getKeyInput();
	//display ascii art
	virtual void displayTitle();
	//loop that calls the redraw menu function
	void displayMenu();
	//displays the menu and changes made by key input
	virtual void redrawMenu();


};
