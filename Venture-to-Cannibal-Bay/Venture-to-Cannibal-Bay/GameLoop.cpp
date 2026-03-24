#include "GameLoop.h"
GameLoop::GameLoop() {

}

GameLoop::GameLoop(Player* c_User) {
	this->user = c_User;
	this->game = Pirate(user);
}

void GameLoop::playGame() {
	this->game.action();
}