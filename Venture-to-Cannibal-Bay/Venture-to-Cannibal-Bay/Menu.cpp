#include "Menu.h"

Menu::Menu() {
	this->menuPosition = 0;
	this->waiting = true;
	this->keyValue = -1;
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
}

void Menu::displayMenu() {
	this->redrawMenu();
}

void Menu::redrawMenu() {
	system("cls");
	this->displayTitle();
	cout << "|------------------------|" << endl;
	if (this->menuPosition < 0) this->menuPosition = 1;
	if (this->menuPosition > 1) this->menuPosition = 0;
	switch (this->menuPosition) {
	case 0:
		cout <<"|        > Option 1 <        |" << endl;
		cout <<"|          Option 2          |"<<endl;
		break;

	case 1:
		cout <<"|          Option 1          |" << endl;
		cout <<"|        > Option 2 <        |" << endl;
		break;
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
				GameLoop().playGame();

				return;
			case 1:
				quick_exit(0);
				return;
			}
		}
	}
}