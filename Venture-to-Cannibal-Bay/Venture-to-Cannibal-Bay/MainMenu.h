#pragma once
#include "TextColour.h"
#include "Menu.h"
using namespace std;
class MainMenu: public Menu
{
public:
	//constructor
	MainMenu();
	//dispalys designated ascii
	void displayTitle() override;
	//displays the menu options
	void redrawMenu() override;
};

