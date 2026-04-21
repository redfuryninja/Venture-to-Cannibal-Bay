#include "GameLoop.h"
#include "Ship.h"
GameLoop::GameLoop() {

}

GameLoop::GameLoop(Player* c_User) {
	this->user = c_User;
	this->game = Pirate(user);
}

void GameLoop::playGame() {
	
	/* 
	this->game.action();
	*/
	Ship map = Ship();
	map.mapLoop();
}