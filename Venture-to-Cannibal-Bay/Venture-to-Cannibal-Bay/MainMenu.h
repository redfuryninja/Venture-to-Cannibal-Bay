#pragma once
#include "MainMenu.h"
#include "Menu.h"
#include "AsciiArt.h"
class MainMenu: public Menu
{
public:
	MainMenu(string nAscii);
	void redrawMenu() override;
};

