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
	this->cutscene = captured(this->user);
	this->mazeLoop = Maze(this->user);
	this->ending = End(this->user);
} 
void GameLoop::playGame() {
	
	/* 
	*/
	if (this->user->isAlive() == true) {
		this->Start.displayMenu();
	}
	if (this->user->isAlive() == true) {
		this->user->outputClue();

	}
	if (this->user->isAlive() == true) {
		this->game.action();

	}
	if (this->user->isAlive() == true) {
		this->beachLoop.mapLoop();


	}
	if (this->user->isAlive() == true) {

		this->shipLoop.mapLoop();
		
	}
	
	if (this->user->isAlive() == true) {

		this->cutscene.cutscene();
	}
	if (this->user->isAlive() == true) {

		this->mazeLoop.mapLoop();
	}
	if (this->user->isAlive() == true) {
		this->ending.Ending();

	}
}