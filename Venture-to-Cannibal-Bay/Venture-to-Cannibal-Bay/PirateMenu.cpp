#include "PirateMenu.h"




void PirateMenu::displayTitle() {
	PrintFile ascii = PrintFile("./Ascii-art/Ships");
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
	getKeyInput();
}




void PirateMenu::getKeyInput() {
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
				cout << "sup" << endl;
				return;
			case 1:
				quick_exit(0);
				return;
			}
		}
	}
}

