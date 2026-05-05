#include "Player.h"

Player::Player(): Entity(){
	this->lives = 5;
	this->food = 10;
	this->ammo = 10;

}
/*
void Player::setMap(Maps* currMap) {
	this->map = currMap;
	this->mapWidth = this->map->getWidth();
	this->mapHeight = this->map->getHeight();
	this->map->changeChar(this->playerChar);
	this->map->moveEntity(this->entityX, this->entityY);
}

*/
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

/*
bool Player::checkSpace(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	//this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->charCheck == ' ') {

		return true;

	}
	return false;
}

*/

void Player::Move() {
	int key = getKeyValue();
	if (key == KEY_DOWN) {
		this->playerChar = 'V';
		this->canMoveY = checkSpace(this->entityX, this->entityY + 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->playerChar);
			this->map->clearSpace(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->entityY += 1;
			//map[this->entityX + this->entityY * this->mapWidth] = this->playerChar;
			this->map->moveEntity(this->entityX, this->entityY);
		}
	}
	else if (key == KEY_UP) {
		this->playerChar = '^';
		this->canMoveY = checkSpace(this->entityX, this->entityY - 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->playerChar);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_LEFT) {
		this->playerChar = '<';
		this->canMoveX = checkSpace(this->entityX - 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->playerChar);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->playerChar;
		}
	}
	else if (key == KEY_RIGHT) {
		this->playerChar = '>';
		this->canMoveX = checkSpace(this->entityX + 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->playerChar);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX += 1;
			this->map->moveEntity(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->playerChar;
		}
	}

}
