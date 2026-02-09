#include "Menu.h"

Menu::Menu() {
	this->menuPosition = 0;
	this->waiting = true;
	int keyValue = -1;
}
int getKeyInput() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}
void Menu::displayTitle() {
	AsciiArt title = AsciiArt("./Ascii-art/Title.txt");
	title.printAscii();
}

void Menu::displayMenu() {
	Menu menu = Menu();
	menu.redrawMenu();
}

void Menu::redrawMenu() {
	system("cls");
	displayMenu();
	cout << "|------------------------|" << endl;
	if (this->menuPosition < 1) this->menuPosition = 0;
	if (this->menuPosition > 1) this->menuPosition = 0;
	switch (this->menuPosition) {
	case 0:
		cout <<"| > Venture to the bay < |" << endl;
		cout <<"|          Exit          |";

		break;

	case 1:
		cout <<"|    Venture to the bay  |" << endl;
		cout <<"|        > Exit <        |" << endl;
		break;
}

	cout << "|------------------------|" << endl;
	while (this->waiting){
		this->keyValue = getKeyInput();
	}
}