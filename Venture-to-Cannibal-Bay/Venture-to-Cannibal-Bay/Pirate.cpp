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
	
}
