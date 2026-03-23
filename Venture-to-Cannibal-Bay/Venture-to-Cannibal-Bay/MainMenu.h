#pragma once
#include "MainMenu.h"
#include "Menu.h"
using namespace std;
class MainMenu: public Menu
{
public:
	MainMenu();
	void displayTitle() override;
	void redrawMenu() override;
};

