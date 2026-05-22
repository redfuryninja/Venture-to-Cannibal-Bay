#include "GameLoop.h"

GameLoop::GameLoop() {
	Player Pointer = Player();
	this->user = &Pointer;
	this->game = Pirate(user);
	this->Start = MainMenu();
	this->beachLoop = Beach(this->user);
	this->shipLoop = Ship(this->user);
}
//constructor that passes the user to each game loop

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
// it calls each class that holds a screen the player will go to and calls them all in sequence
void GameLoop::playGame() {
	

	if (this->user->isAlive() == true and this->user->getFood() >0) {
		this->Start.displayMenu();
	}
	if (this->user->isAlive() == true and this->user->getFood() > 0) {
		this->user->outputClue();

	}
	if (this->user->isAlive() == true and this->user->getFood() > 0) {
		this->game.action();

	}
	if (this->user->isAlive() == true and this->user->getFood() > 0) {
		this->beachLoop.mapLoop();


	}
	if (this->user->isAlive() == true and this->user->getFood() > 0) {

		this->shipLoop.mapLoop();
		
	}
	
	if (this->user->isAlive() == true and this->user->getFood() > 0) {

		this->cutscene.cutscene();
	}
	if (this->user->isAlive() == true and this->user->getFood() > 0) {

		this->mazeLoop.mapLoop();
	}
	if (this->user->isAlive() == true and this->user->getFood() > 0) {
		this->ending.Ending();

	}
}