#include "PirateMenu.h"


PirateMenu::PirateMenu():Menu() {
	this->path = "N/A";
}
string PirateMenu::getPath() {
	return path;
}

void PirateMenu::displayTitle() {
	PrintFile ascii = PrintFile("./Ascii-art/Ships.txt");
	ascii.OutputAscii();
}

void PirateMenu::redrawMenu() {
	system("cls");
	displayTitle();
	cout << "|------------------------|" << endl;
	if (this->menuPosition < 0) this->menuPosition = 2;
	if (this->menuPosition > 2) this->menuPosition = 0;
	switch (this->menuPosition) {
	case 0:
		cout << "|  > Fight with Swords < |" << endl;
		cout << "|    Fight with Guns     |" << endl;
		cout << "|    Give them Supplies  |" << endl;
		break;

	case 1:
		cout << "|    Fight with Swords   |" << endl;
		cout << "|  > Fight with Guns <   |" << endl;
		cout << "|    Give them Supplies  |" << endl;
		break;
	case 2:
		cout << "|    Fight with Swords   |" << endl;
		cout << "|    Fight with Guns     |" << endl;
		cout << "|  > Give them Supplies <|" << endl;
		break;
	}

	cout << "|------------------------|" << endl;
}




bool PirateMenu::getKeyInput() {
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
				this->path = "swords";
				cout << "swords" << endl;
				return false;
			case 1:
				this->path = "guns";
				cout << "guns" << endl;
				return false;
			case 2:
				this->path = "suppliess";
				cout << "supplies" << endl;
				return false;
			}
		}
	}
}

