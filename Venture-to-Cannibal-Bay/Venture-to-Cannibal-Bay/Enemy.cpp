#include "Enemy.h"
Enemy::Enemy() :Entity() {
	this->entityChar = 'M';
	this->state = MOVING;
	this->orientation = DOWN;
}

bool Enemy::getWeaponDeath() {
	return this->weaponDeath;
}
void Enemy::Move() {
	
	if (this->orientation == DOWN) {

		this->canMoveY = checkSpace(this->entityX, this->entityY + 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->entityY += 1;
			//map[this->entityX + this->entityY * this->mapWidth] = this->entityChar;
			this->map->moveEntity(this->entityX, this->entityY);
		}
		else if (this->map->getChar(entityX,entityY+1) == 'O' or this->map->getChar(entityX, entityY + 1) == '!') {
			this->alive = false;
			this->weaponDeath = true;
		}
		else if (this->checkIfPlayer(this->entityX, this->entityY +1)){
			this->alive = false;
		}
	
		else {
			
			this->orientation = UP;
		}
	}


	else if (this->orientation == UP) {

		this->canMoveY = checkSpace(this->entityX, this->entityY - 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->entityChar);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->entityChar;
		}
		else if (this->map->getChar(entityX, entityY - 1) == 'O' or this->map->getChar(entityX, entityY + 1) == '!') {
			this->alive = false;
			this->weaponDeath = true;
		}
		else if (this->checkIfPlayer(this->entityX, this->entityY - 1)) {
			this->alive = false;
		}
		else {

			this->orientation = DOWN;
		}
	}
	else if (this->orientation == LEFT) {

		this->canMoveX = checkSpace(this->entityX - 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->entityChar;
		}
		else if (this->checkIfPlayer(this->entityX-1, this->entityY)) {
			this->alive = false;
		}
		else if (this->checkIfWeapon(this->entityX-1, this->entityY)) {
			this->alive = false;
			this->weaponDeath = true;
		}
		else if (this->map->getChar(entityX-1, entityY) == 'O' or this->map->getChar(entityX-1, entityY) == '!') {
			this->alive = false;
			this->weaponDeath = true;
		}
		else {
			this->orientation = RIGHT;
		}
	}
	else if (this->orientation == RIGHT) {

		this->canMoveX = checkSpace(this->entityX + 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);
			//map[this->entityX + this->entityY * this->mapWidth] = this->mapChar;
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX += 1;
			this->map->moveEntity(this->entityX, this->entityY);
			//map[this->entityX + this->entityY * this->mapWidth] = this->entityChar;
		}
		else if (this->map->getChar(entityX+1, entityY) == 'O' or this->map->getChar(entityX+1, entityY) == '!') {
			this->alive = false;
			this->weaponDeath = true;
		}
		else if (this->checkIfPlayer(this->entityX+1, this->entityY)) {
			this->alive = false;
		}
		else if (this->checkIfWeapon(this->entityX + 1, this->entityY)) {
			this->alive = false;
			this->weaponDeath = true;
		}

		else {
			this->orientation = LEFT;
		}
	}
}