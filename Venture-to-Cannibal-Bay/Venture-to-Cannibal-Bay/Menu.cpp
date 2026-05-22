#include "Menu.h"
#include "GameLoop.h"
//constructors
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

}
//gets value of key input
int Menu::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}
//displays ascii art
void Menu::displayTitle() {
	PrintFile ascii = PrintFile("./Ascii-art/menu.txt");
	ascii.OutputAscii();
	
}
//loops through menu and key input so as to not repeatedly make menus
void Menu::displayMenu() {
	bool loop = true;
	while (loop == true) {
		this->redrawMenu();
		loop = this->getKeyInput();
	}

}
//prints the menu
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
	
}

//gets int player input
bool Menu::getKeyInput() {
	while (this->waiting) {
		this->keyValue = getKeyValue();
		switch (this->keyValue) {
		case KEY_UP:
			this->menuPosition--;
			return true;
		case KEY_DOWN:
			this->menuPosition++;
			return true;
		case KEY_ENTER:
			switch (this->menuPosition) {
			case 0:
				return false;
			case 1:
				quick_exit(0);
				return false;
			}
		}
	}
}