#include "MainMenu.h"


MainMenu::MainMenu(): Menu() {
}

//displays thet title card and the controls to the player
void MainMenu::displayTitle() {
	TextColour colour;
	colour.changeColour(4);
	PrintFile ascii = PrintFile("./Ascii-art/Title.txt");
	ascii.OutputAscii();
	colour.changeColour(15);
	PrintFile controls = PrintFile("./Ascii-art/controls.txt");
	controls.OutputAscii();
}
//displays the options to the player
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
	cout << " press up and down arrows to move and press enter to select" << endl;
}
