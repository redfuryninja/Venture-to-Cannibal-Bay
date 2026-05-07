#include "ShipRoom.h"
#include "Ship.h"

ShipRoom::ShipRoom() {
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
	/*

	this->map = "";
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
	this->map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;

	*/
}



void ShipRoom::mapLoop() {
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	fillMag();
	this->createEnemies();
	this->user->setMap(this->mapPointer);

	for (int i = 0; i < this->activeEntities.size(); i++) {
		this->activeEntities[i].setMap(this->mapPointer);
	}


	bool quit = false;
	this->map.setMessage("press arrow keys to move, q to shoot and F to open a door you are facing if you have a key");
	while (quit == false) {
		clock_t start = clock();
		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;


		//######## Process Input ########//


		if (this->user->isAlive()) {
			this->user->Move();
		}


		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;




		//######## Render ########//

		//outputMap();


		//Calculating how long to wait to achieve desired FPS.

		/*
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 50 - msDuration; //This game runs at 5 FPS (change from 200 to 33 to try 30 FPS).
		this_thread::sleep_for(chrono::milliseconds(msRemaining));

		*/



	}
}