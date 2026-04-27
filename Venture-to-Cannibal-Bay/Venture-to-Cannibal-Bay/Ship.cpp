#include "Ship.h"

Ship::Ship(){
	this->playerX = 10;
	this->playerY = 2;
	this->mapWidth = 19;
	this->mapHeight = 41;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->map = "";
	this->filename = "./Ascii-art/shipMap.txt";
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
	this->map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
}
	
bool Ship::checkHorizontal(int futureX, int futureY) {
	int coord = futureX + this->playerY * this->mapWidth;
	this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->mapChar == ' ') {
		//mapChar = ' ';
		return true;

	}
	return false;
}


bool Ship::checkVertical(int futureX, int futureY) {
	this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->mapChar == ' ') {
		//mapChar = ' ';
		return true;
	}
	return false;
}
// if (this->mapChar == ' ')


void Ship::outputMap() {
	cout << this->map << endl;
}

int Ship::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}

void Ship::mapLoop() {
	

	bool quit = false;

	while (quit == false) {
		clock_t start = clock();

		//######## Process Input ########//
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



		//######## Render ########//

		system("cls");
		
		outputMap();


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