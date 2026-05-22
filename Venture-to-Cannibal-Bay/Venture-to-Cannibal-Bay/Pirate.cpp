#include "Pirate.h"
#include "PirateMenu.h"
//constructors
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
	/*
	loops through menu until player makes choice, closes and reopens with each choice
	so it doesnt take to much up to much storage
	*/
	
	while (loop == true) {
		options.redrawMenu();
		loop = options.getKeyInput();
	}
		
	//opens path to choice player selected
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
	//gets starting clock value
	clock_t start = clock();
	
	this->colour.changeColour(64);
	cout << "you are being attacked by pirates, press E to Dodge" << endl;
	this->colour.changeColour(15);
	while (true) {

		if (this->getKeyValue() == KEY_E) {
			break;
		}
	}
	//gets end clock value
	clock_t end = clock();
	int duration = end - start;
	this->user->setFood(this->user->getFood() - duration);
	//if player was quick enough in hitting key then it will play an animation but if they're too slow it just shows an ascii image
	if (duration > 3000) {
		system("cls");
		PrintFile ascii = PrintFile("./Ascii-art/lostLife.txt");
		ascii.OutputAscii();
		this->user->setLives(this->user->getLives() - 1);
		cout << " you lost a life" << endl;
		system("pause");
	}
	else {
		//starts animation callin animaton class
		this->ani.swordAnimation();
		system("cls");
		//outputs ascii art
		PrintFile ascii = PrintFile("./Ascii-art/Win.txt");
		ascii.OutputAscii();
		this->colour.changeColour(4);
		cout << " you won the fight and didn't lose a life" << endl;
		this->colour.changeColour(15);
		system("pause");
	}
	
}
//plays ascii animation before continuing
void Pirate::gun() {
	this->ani.gunAnimation();
	this->colour.changeColour(4);
	cout << " you shot all the pirates" << endl;
	this->colour.changeColour(15);
	system("pause");
	this->user->setAmmo(this->user->getAmmo() - 5);
}
// outputs ascii image
void Pirate::food() {
	PrintFile ascii = PrintFile("./Ascii-art/supplies.txt");
	ascii.OutputAscii();
	this->colour.changeColour(4);
	cout << " you bribed the Pirates and gave up your supplies in exchange for your lives" << endl;
	this->colour.changeColour(15);
	this->user->setFood(this->user->getFood() /2);
	system("pause");
}

//gets key value of input
int Pirate::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}

