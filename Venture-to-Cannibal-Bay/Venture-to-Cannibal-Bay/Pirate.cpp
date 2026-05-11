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
	Animation ani = Animation();
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
	else if (options.getPath() == "guns") {
		this->gun();
	}
	else if (options.getPath() == "supplies") {
		this->food();
	}
	else {
		action();
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
	this->user->setFood(this->user->getFood() - duration);
	if (duration > 3000) {
		system("cls");
		PrintFile ascii = PrintFile("./Ascii-art/lostLife.txt");
		ascii.OutputAscii();
		this->user->setLives(this->user->getLives() - 1);
		cout << " you lost a life" << endl;
		system("pause");
	}
	else {
		this->ani.swordAnimation();
		PrintFile ascii = PrintFile("./Ascii-art/Win.txt");
		ascii.OutputAscii();
		cout << " you won the fight and didn't lose a life" << endl;
		system("pause");
	}
	
}
void Pirate::gun() {
	this->ani.gunAnimation();
	cout << " you shot all the pirates" << endl;
	system("pause");
	this->user->setAmmo(this->user->getAmmo() - 5);
}

void Pirate::food() {
	PrintFile ascii = PrintFile("./Ascii-art/supplies.txt");
	ascii.OutputAscii();
	cout << " you bribed the Pirates and gave up your supplies in exchange for your lives" << endl;
	this->user->setFood(this->user->getFood() - 200000);
	system("pause");
}


int Pirate::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}

