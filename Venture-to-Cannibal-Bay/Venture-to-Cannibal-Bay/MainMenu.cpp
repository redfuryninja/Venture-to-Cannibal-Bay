#include "MainMenu.h"


MainMenu::MainMenu(): Menu() {
}


void MainMenu::displayTitle() {
	int loop = 0;
	for (int i = 0; i <= 1000; i++) {
	PrintFile ascii = PrintFile("./Ascii-art/sword.txt");
	ascii.OutputAscii();
	system("cls");
	PrintFile ascii2 = PrintFile("./Ascii-art/test.txt");
	ascii2.OutputAscii();
	system("cls");
	}
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
