#include "Ship.h"

Ship::Ship(){
	this->playerX = 7;
	this->playerY = 2;
	this->mapWidth = 13;
	this->mapHeight = 34;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->map = "";
	this->filename = "./Ascii-art/ShipMap.txt";
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
	this->map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
}
	
bool Ship::checkHorizontal(int futureX, int futureY) {
	this->mapChar = map[futureX + this->playerY * this->mapWidth];
	if (this->mapChar == ' ') {
		return true;
	}
	return false;
}


bool Ship::checkVertical(int futureX, int futureY) {
	this->mapChar = map[futureY + this->playerX * this->mapWidth];
	if (this->mapChar == ' ') {
		return true;
	}
	return false;
}



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

		if (this->getKeyValue() == KEY_UP) {
			this->playerChar = '^';
			this->canMoveY = checkVertical(this->playerX, this->playerY - 1);
			if (this->canMoveY == true) {
				this->playerY -= 1;
				map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
			}
		}
		else if (this->getKeyValue() == KEY_DOWN) {
			this->playerChar = 'V';
			this->canMoveY = checkVertical(this->playerX, this->playerY + 1);
			if (this->canMoveY == true) {
				map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
				this->playerY -= 1;
				map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
			}
		}
		else if (this->getKeyValue() == KEY_LEFT) {
			this->playerChar = '<';
			this->canMoveX = checkHorizontal(this->playerX-1, this->playerY);
			if (this->canMoveX == true) {
				this->playerX -= 1;
				map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
			}
		}
		else if (this->getKeyValue() == KEY_RIGHT) {
			this->playerChar = '>';
			this->canMoveX = checkHorizontal(this->playerX + 1, this->playerY);
			if (this->canMoveX == true) {
				this->playerX += 1;
				map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
			}
		}



		//######## Update Game ########//
		//Loop through all entities in the game and call their update method (doing AI etc.).
	
		//############################//



		//######## Render ########//
		//\r is called a carriage-return. Instead of using system("cls") (which 
		// will cause screen flickering), \r moves the cout curser to the beginning of
		// the line (which allows us to overwrite previous output).
		system("cls");
		
		outputMap();


		//Calculating how long to wait to achieve desired FPS.
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 200 - msDuration; //This game runs at 5 FPS (change from 200 to 33 to try 30 FPS).
		this_thread::sleep_for(chrono::milliseconds(msRemaining));

	}
	/*while (true) {

		if (this->getKeyValue() == KEY_E) {
			break;
		}
	*/
}