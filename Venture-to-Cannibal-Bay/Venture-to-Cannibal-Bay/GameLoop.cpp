#include "GameLoop.h"

GameLoop::GameLoop() {

}

GameLoop::GameLoop(Player* c_User) {
	this->user = c_User;
	this->game = Pirate(user);
	this->Start = MainMenu();
	Ship map = Ship();
} 
void GameLoop::playGame() {
	
	/* 
	*/

	this->Start.displayMenu();
	this->map.mapLoop();
	this->game.action();
}