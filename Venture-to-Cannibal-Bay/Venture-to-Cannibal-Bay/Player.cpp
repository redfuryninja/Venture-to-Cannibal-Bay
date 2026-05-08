#include "Player.h"

Player::Player(): Entity(){
	this->lives = 5;
	this->food = 10;
	this->ammo = 10;
	this->startX = 10;
	this->startY = 2;
	this->enemyChar = { 'M', 'A' };
	this->textTreePoint = 0;
	this->tree = TextTree();
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

void Player::revive() {
	this->alive = true;
}

bool Player::getShipKey() {
	return this->shipKey;
}

void Player::setShipKey(bool nKey) {
	this->shipKey = nKey;
}
bool Player::checkIfKey(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	//this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->charCheck == 'K') {

		return true;

	}
	return false;
}


bool Player::checkIfEnemy(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	//this->mapChar = map[futureX + futureY * this->mapWidth];
	for (int i = 0; i < this->enemyChar.size(); i++) {
		if (this->charCheck == enemyChar[i]) {
			return true;
		}

	}


	return false;
}

void Player::Move() {
	//int key = getKeyValue();
	this->projX = entityX;
	this->projY = entityY;
	if (GetAsyncKeyState(KEY_DOWN)) {
		this->entityChar = 'V';
		this->map->changeChar(this->entityChar);
		this->map->moveEntity(this->entityX, this->entityY);
		this->orientation = DOWN;
		this->state = MOVING;
		this->canMoveY = checkSpace(this->entityX, this->entityY + 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY += 1;
			this->map->moveEntity(this->entityX, this->entityY);
		}
		else if (this->checkIfKey(this->entityX, this->entityY + 1) == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY += 1;
			this->map->moveEntity(this->entityX, this->entityY);
			this->shipKey = true;
		}


	}
	else if (GetAsyncKeyState(KEY_UP) & 0x8000) {
		this->entityChar = '^';
		this->map->changeChar(this->entityChar);
		this->map->moveEntity(this->entityX, this->entityY);
		this->orientation = UP;
		this->state = MOVING;
		this->canMoveY = checkSpace(this->entityX, this->entityY - 1);
		if (this->canMoveY == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
		}
		else if (this->checkIfKey(this->entityX, this->entityY - 1) == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
			this->shipKey = true;
		}

	}
	else if (GetAsyncKeyState(KEY_LEFT) & 0x8000) {
		this->entityChar = '<';
		this->map->changeChar(this->entityChar);
		this->map->moveEntity(this->entityX, this->entityY);
		this->orientation = LEFT;
		this->state = MOVING;
		this->canMoveX = checkSpace(this->entityX - 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
		}
		else if (this->checkIfKey(this->entityX - 1, this->entityY) == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX -= 1;
			this->map->moveEntity(this->entityX, this->entityY);
			this->shipKey = true;
		}
	}
	else if (GetAsyncKeyState(KEY_RIGHT) & 0x8000) {
		this->entityChar = '>';
		this->map->changeChar(this->entityChar);
		this->map->moveEntity(this->entityX, this->entityY);
		this->orientation = RIGHT;
		this->state = MOVING;
		this->canMoveX = checkSpace(this->entityX + 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX += 1;
			this->map->moveEntity(this->entityX, this->entityY);

		}
		else if (this->checkIfKey(this->entityX +1, this->entityY) == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX += 1;
			this->map->moveEntity(this->entityX, this->entityY);
			this->shipKey = true;
		}
	}
	else if (GetAsyncKeyState(KEY_Q)) {
		shoot();
	}
	else if (GetAsyncKeyState(KEY_F) & 0x8000) {
		if (this->shipKey == true) {
			if (this->orientation == RIGHT and this->map->getChar(this->entityX+1, this->entityY) == 'D') {
				this->entityChar = 'D';
				this->map->changeChar(this->entityChar);
				this->map->clearSpace(this->entityX, this->entityY);
				this->entityX += 1;
				this->map->moveEntity(this->entityX, this->entityY);
				this->entityChar = '>';

				}
			else if (this->orientation == LEFT and this->map->getChar(this->entityX-1, this->entityY) == 'D') {
				this->entityChar = 'D';
				this->map->changeChar(this->entityChar);
				this->map->clearSpace(this->entityX, this->entityY);
				this->entityX -= 1;
				this->map->moveEntity(this->entityX, this->entityY);
				this->entityChar = '<';
	
				
			}
		}
		if (this->orientation == RIGHT and this->map->getChar(this->entityX + 1, this->entityY) == '!') {
			system("cls");
			this->tree.outputText();
			this->tree.setTreePoint(this->tree.getTreePoint() + 1);
			if (this->tree.getTreePoint() > this->tree.getBookSize()) {
				this->tree.setTreePoint(this->tree.getBookSize());
			}
			system("cls");
		}
		else if (this->orientation == LEFT and this->map->getChar(this->entityX - 1, this->entityY) == '!') {
			system("cls");
			this->tree.outputText();
			system("cls");

		}
	}

	
	
}

void Player::shoot() {
	if (this->state == SHOOTING) {
		this->map->setMessage("can't shoot, reloading");
		this->state = NUETRAL;
	}
	else {
		this->state = SHOOTING;
	}
}