#include "ShipRoom.h"
#include "Ship.h"

ShipRoom::ShipRoom() {
	this->playerX = 1;
	this->playerY = 3;
	this->mapWidth = 22;
	this->mapHeight = 8;
	this->playerChar = '>';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/testMap.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;

}
ShipRoom::ShipRoom(Player* cUser) {
	this->playerX = 2;
	this->playerY = 5;
	this->mapWidth = 21;
	this->mapHeight = 8;
	this->playerChar = '>';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/testMap.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;
	this->user = cUser;
}



void ShipRoom::mapLoop() {
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->user->setX(playerX);
	this->user->setY(playerY);
	this->user->setMap(this->mapPointer);


	bool quit = false;
	this->map.setMessage("press arrow keys to move, and F to interact");
	while (quit == false) {
		clock_t start = clock();
		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;


		//######## Process Input ########//


		if (this->user->isAlive()) {
			this->user->Move();
		}

		if (this->user->getY() == 5 and this->user->getX() == 0) {
			quit = true;
		}


		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;




		//######## Render ########//

		//outputMap();


		//Calculating how long to wait to achieve desired FPS.

		
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 100 - msDuration; //This game runs at 5 FPS (change from 200 to 33 to try 30 FPS).
		this_thread::sleep_for(chrono::milliseconds(msRemaining));

		



	}
}