#include "Menu.h"
#include "GameLoop.h"

Menu::Menu() {
	this->menuPosition = 0;
	this->waiting = true;
	this->keyValue = -1;
	this->fileName = "./Ascii-art/menu.txt";
}

Menu::Menu(Player* c_User) {
	this->user = c_User;
	this->menuPosition = 0;
	this->waiting = true;
	this->keyValue = -1;
	this->fileName = "./Ascii-art/menu.txt";
	this->game = GameLoop(user);
}

int Menu::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}
void Menu::displayTitle() {
	PrintFile ascii = PrintFile("./Ascii-art/menu.txt");
	ascii.OutputAscii();
	
}

void Menu::displayMenu() {
	//while loop
	this->redrawMenu();
	//this->redrawMenu(up/down);
	//this->getKeyInput();
}

void Menu::redrawMenu() {
	system("cls");
	displayTitle();
	cout << "|------------------------|" << endl;
	if (this->menuPosition < 0) this->menuPosition = 1;
	if (this->menuPosition > 1) this->menuPosition = 0;
	switch (this->menuPosition) {
	case 0:
		cout <<"|      > Option 1 <      |" << endl;
		cout <<"|        Option 2        |"<<endl;
		return;

	case 1:
		cout <<"|        Option 1        |" << endl;
		cout <<"|      > Option 2 <      |" << endl;
		return;
}

	cout << "|------------------------|" << endl;
	this->getKeyInput();
}


void Menu::getKeyInput() {
	while (this->waiting) {
		this->keyValue = getKeyValue();
		switch (this->keyValue) {
		case KEY_UP:
			this->menuPosition--;
			this->redrawMenu();
		case KEY_DOWN:
			this->menuPosition++;
			this->redrawMenu();
		case KEY_ENTER:
			switch (this->menuPosition) {
			case 0:
				game.playGame();
				return;
			case 1:
				quick_exit(0);
				return;
			}
		}
	}
}