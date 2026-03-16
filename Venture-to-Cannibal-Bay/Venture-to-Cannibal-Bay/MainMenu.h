#pragma once
#include "MainMenu.h"
#include "Menu.h"
class MainMenu: public Menu
{
public:
	MainMenu();
	void displayTitle() override;
	void redrawMenu() override;
};

