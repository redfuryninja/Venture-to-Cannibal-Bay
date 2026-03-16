#include "Pirate.h"

void Pirate::displayTitle() {
	PrintFile ascii = PrintFile("./Ascii-art/Ships");
	ascii.OutputAscii();
}

void Pirate::redrawMenu() {
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
