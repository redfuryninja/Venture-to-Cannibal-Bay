#include "Player.h"

Player::Player(): Entity(){
	this->lives = 5;
	this->food = 10;
	this->ammo = 10;

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


void Player::Move() {
	int key = getKeyValue();
	this->projX = entityX;
	this->projY = entityY;
	if (key == KEY_DOWN) {
		this->entityChar = 'V';
		this->orientation = DOWN;
		this->state = MOVING;
		this->canMoveY = checkSpace(this->entityX, this->entityY + 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY += 1;
			this->map->moveEntity(this->entityX, this->entityY);
		}

	}
	else if (key == KEY_UP) {
		this->entityChar = '^';
		this->orientation = UP;
		this->state = MOVING;
		this->canMoveY = checkSpace(this->entityX, this->entityY - 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
		}

	}
	else if (key == KEY_LEFT) {
		this->entityChar = '<';
		this->orientation = LEFT;
		this->state = MOVING;
		this->canMoveX = checkSpace(this->entityX - 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX -= 1;
			this->map->moveEntity(this->entityX, this->entityY);

		}
	}
	else if (key == KEY_RIGHT) {
		this->entityChar = '>';
		this->orientation = RIGHT;
		this->state = MOVING;
		this->canMoveX = checkSpace(this->entityX + 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX += 1;
			this->map->moveEntity(this->entityX, this->entityY);

		}
	}
	else if (key == KEY_Q) {
		shoot();
	}
}

void Player::shoot() {
	if (this->state == SHOOTING) {
		this->map->setMessage("can't shoot, reloading");
		this->state = NUETRAL;
	}
	else {
		this->state = SHOOTING;
		this->map->setMessage("shooting");
	}
}