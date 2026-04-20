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
	options.displayMenu();
	if (options.getPath() == "swords") {
		this->sword();
	}
}


void Pirate::sword(){
	bool quit = false;
	int pos = 0;
	while (quit == false){
		clock_t start = clock();
		if (pos == 0) {
			PrintFile ascii = PrintFile("./Ascii-art/sword.txt");
			ascii.OutputAscii();
			pos = 1;
			system("cls");
		}
		else if (pos == 1){
			PrintFile ascii2 = PrintFile("./Ascii-art/fight.txt");
			ascii2.OutputAscii();
			pos = 0;
			system("cls");
		}
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 150 - msDuration;
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
	}
}