#include "Pirate.h"
#include "PirateMenu.h"

Pirate::Pirate() {
	int startClock = 0;
	int endClock = 0;
	bool failed = false;
	
}
Pirate::Pirate(Player* c_User) {
	this->user = c_User;
	int startClock = 0;
	int endClock = 0;
	bool failed = false;
}
void Pirate::action() {
	PirateMenu options = PirateMenu();
	bool loop = true;
	while (loop == true) {
		options.redrawMenu();
		loop = options.getKeyInput();
	}
		

	if (options.getPath() == "swords") {
		this->sword();
	}

}

void Pirate::animation() {
	bool quit = false;
	int pos = 0;
	for (int i = 0; i < 20; i++) {
		clock_t start = clock();
		if (pos == 0) {
			PrintFile ascii = PrintFile("./Ascii-art/sword.txt");
			ascii.OutputAscii();
			pos = 1;

		}
		else if (pos == 1) {
			PrintFile ascii2 = PrintFile("./Ascii-art/fight.txt");
			ascii2.OutputAscii();
			pos = 0;

		}
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 150 - msDuration;
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		system("cls");
	}
}
void Pirate::sword(){
	clock_t start = clock();
	cout << "you are being attacked by pirates, press E to Dodge" << endl;
	while (true) {

		if (this->getKeyValue() == KEY_E) {
			break;
		}
	}
	clock_t end = clock();
	int duration = end - start;
	if (duration > 15) {
		system("cls");
		PrintFile ascii = PrintFile("./Ascii-art/lostLife.txt");
		ascii.OutputAscii();
		this->user->setLives(this->user->getLives() - 1);
		cout << " you lost a life" << endl;
	}
	else {
		animation();
		PrintFile ascii = PrintFile("./Ascii-art/Win.txt");
		ascii.OutputAscii();
		cout << " you won the fight and didn't lose a life" << endl;
	}
	
}

int Pirate::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}