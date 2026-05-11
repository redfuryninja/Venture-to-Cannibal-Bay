#include "GameLoop.h"

GameLoop::GameLoop() {
	Player Pointer = Player();
	this->user = &Pointer;
	this->game = Pirate(user);
	this->Start = MainMenu();
	this->beachLoop = Beach(this->user);
	this->shipLoop = Ship(this->user);
}

GameLoop::GameLoop(Player* cUser) {
	this->user = cUser;
	this->game = Pirate(user);
	this->Start = MainMenu();
	this->beachLoop = Beach(this->user);
	this->shipLoop = Ship(this->user);
} 
void GameLoop::playGame() {
	
	/* 
	*/

	this->Start.displayMenu();
	this->shipLoop.mapLoop();
	this->beachLoop.mapLoop();
	this->user->outputClue();
	this->game.action();
	cout << "end so far";
}