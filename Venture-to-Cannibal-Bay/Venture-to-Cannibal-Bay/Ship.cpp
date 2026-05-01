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
	this->mapPointer = &this->map;
}
/*
	this->map = "";
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
	this->map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;

bool Ship::checkHorizontal(int futureX, int futureY) {
	int coord = futureX + this->playerY * this->mapWidth;
	this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->mapChar == ' ') {
		
		return true;

	}
	return false;
}


	bool Ship::checkVertical(int futureX, int futureY) {
	this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->mapChar == ' ') {
		return true;
	}
	return false;
}
	*/


int Ship::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}
/*

void Ship::playerMove() {
	int key = getKeyValue();
	if (key == KEY_DOWN) {
		this->playerChar = 'V';
		this->canMoveY = checkVertical(this->playerX, this->playerY + 1);
		if (this->canMoveY == true) {
			map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->playerY += 1;
			map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_UP) {
		this->playerChar = '^';
		this->canMoveY = checkVertical(this->playerX, this->playerY - 1);
		if (this->canMoveY == true) {
			map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->playerY -= 1;
			map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_LEFT) {
		this->playerChar = '<';
		this->canMoveX = checkHorizontal(this->playerX - 1, this->playerY);
		if (this->canMoveX == true) {
			map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->playerX -= 1;
			map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_RIGHT) {
		this->playerChar = '>';
		this->canMoveX = checkHorizontal(this->playerX + 1, this->playerY);
		if (this->canMoveX == true) {
			map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->playerX += 1;
			map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}

}


void Ship::outputMap() {
	cout << this->map << endl;
}
*/


void Ship::mapLoop() {
	
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
		this->user->playerMove();


		//######## Render ########//

		system("cls");
		
		cout << this->mapPointer->getMap();

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