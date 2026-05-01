#include "Player.h"

Player::Player(){
	this->lives = 5;
	this->food = 10;
	this->ammo = 10;
	Maps createMap = Maps();
	this->map = &createMap;
	this->playerX = 10;
	this->playerY = 2;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->lives = 5;
	this->food = 10;
	this->ammo = 10;
	this->charCheck = '/';
}

void Player::setMap(Maps* currMap) {
	this->map = currMap;
	this->mapWidth, this->mapHeight = this->map->getDimensions();
}
int Player::getLives() {
	return this->lives;
}
int Player::getFood() {
	return this->food;
}
int Player::getAmmo() {
	return this->ammo;
}
void Player::setLives(int nLives) {
	this->lives = nLives;
}
void Player::setFood(int nFood) {
	this->food= nFood;
}
void Player::setAmmo(int nAmmo) {
	this->ammo = nAmmo;
}


bool Player::checkSpace(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	//this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->charCheck == ' ') {

		return true;

	}
	return false;
}

int Player::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}

void Player::playerMove() {
	int key = getKeyValue();
	if (key == KEY_DOWN) {
		this->playerChar = 'V';
		this->canMoveY = checkSpace(this->playerX, this->playerY + 1);
		if (this->canMoveY == true) {
			this->map->clearSpace(this->playerX, this->playerY);
			//map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->playerY += 1;
			//map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
			this->map->moveEntity(this->playerX, this->playerY);
		}
	}
	else if (key == KEY_UP) {
		this->playerChar = '^';
		this->canMoveY = checkSpace(this->playerX, this->playerY - 1);
		if (this->canMoveY == true) {
			//map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->playerX, this->playerY);
			this->playerY -= 1;
			this->map->moveEntity(this->playerX, this->playerY);
			//map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_LEFT) {
		this->playerChar = '<';
		this->canMoveX = checkSpace(this->playerX - 1, this->playerY);
		if (this->canMoveX == true) {
			//map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->playerX, this->playerY);
			this->playerY -= 1;
			this->map->moveEntity(this->playerX, this->playerY);
			//map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_RIGHT) {
		this->playerChar = '>';
		this->canMoveX = checkSpace(this->playerX + 1, this->playerY);
		if (this->canMoveX == true) {
			//map[this->playerX + this->playerY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->playerX, this->playerY);
			this->playerY -= 1;
			this->map->moveEntity(this->playerX, this->playerY);
			//map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
		}
	}

}
