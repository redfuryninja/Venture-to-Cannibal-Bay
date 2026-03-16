#include "MainMenu.h"

MainMenu::MainMenu(): Menu() {
}


void MainMenu::displayTitle() {
	PrintFile ascii = PrintFile("./Ascii-art/Title.txt");
	ascii.OutputAscii();
}

void MainMenu::redrawMenu() {
	system("cls");
	displayTitle();
	cout << "|------------------------|" << endl;
	if (this->menuPosition < 0) this->menuPosition = 1;
	if (this->menuPosition > 1) this->menuPosition = 0;
	switch (this->menuPosition) {
	case 0:
		cout << "| > Venture to the bay < |" << endl;
		cout << "|          Exit          |" << endl;
		break;

	case 1:
		cout << "|   Venture to the bay   |" << endl;
		cout << "|        > Exit <        |" << endl;
		break;
	}

	cout << "|------------------------|" << endl;
	getKeyInput();
}
