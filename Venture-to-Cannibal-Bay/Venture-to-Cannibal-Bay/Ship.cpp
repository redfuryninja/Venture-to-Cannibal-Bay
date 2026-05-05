#include "Ship.h"

Ship::Ship(){
	Player Pointer = Player();
	this->user = &Pointer;
	this->playerX = 10;
	this->playerY = 2;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/bigShipMap.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;
	/*
	
	this->map = "";
	this->filename = "./Ascii-art/bigShipMap.txt";
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
	this->map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
	
	*/
}
Ship::Ship(Player* cUser) {
	this->user = cUser;
	this->playerX = 10;
	this->playerY = 2;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/bigShipMap.txt";
	this->map = Maps(this->filename);

}

void Ship::mapLoop() {
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->user->setMap(this->mapPointer);
	bool quit = false;

	while (quit == false) {
		clock_t start = clock();

		//######## Process Input ########//
		/*
		create map
		pass map to entity
		run entity movement
		give map entity coords
		
		*/
		this->user->Move();

		
		//######## Render ########//

		system("cls");
		
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;
		
		//outputMap();


		//Calculating how long to wait to achieve desired FPS.
		
		
		/*
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 200 - msDuration; //This game runs at 5 FPS (change from 200 to 33 to try 30 FPS).
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		*/
	}
	/*while (true) {

		if (this->getKeyValue() == KEY_E) {
			break;
		}
	*/
}