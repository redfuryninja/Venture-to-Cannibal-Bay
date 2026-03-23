#include "GameLoop.h"
GameLoop::GameLoop() {

}

GameLoop::GameLoop(Player* c_User) {
	this->user = c_User;
}

void GameLoop::playGame() {
	cout << "gameloop" << endl;
}