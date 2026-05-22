#include "PirateMenu.h"

//constructor
PirateMenu::PirateMenu():Menu() {
	this->path = "N/A";
}
string PirateMenu::getPath() {
	return path;
}
//displays the ascii art of ships
void PirateMenu::displayTitle() {
	//creates printfile class and passes the filename into it to print
	PrintFile ascii = PrintFile("./Ascii-art/Ships.txt");
	ascii.OutputAscii();
}

void PirateMenu::redrawMenu() {
	system("cls");
	displayTitle();
	TextColour colour;
	colour.changeColour(4);
	cout << "Pirate Ships are approacing what will you do" << endl;
	colour.changeColour(15);
	cout << "|------------------------|" << endl;
	if (this->menuPosition < 0) this->menuPosition = 2;
	if (this->menuPosition > 2) this->menuPosition = 0;
	//switches what is output depending on the input of the player
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
	cout << " press up and down arrows to move and press enter to select" << endl;
}




bool PirateMenu::getKeyInput() {
	while (this->waiting) {
		//gets the value of the player input
		this->keyValue = getKeyValue();
		//takes different action depending on input value
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
	
				return false;
			case 1:
				this->path = "guns";

				return false;
			case 2:
				this->path = "supplies";
				return false;
			}
		}
	}
}

