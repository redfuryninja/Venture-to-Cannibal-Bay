#include "Player.h"
#include "PrintFile.h"
Player::Player() : Entity() {
	this->lives = 5;
	this->food = 300000;
	this->ammo = 10;
	this->startX = 10;
	this->startY = 2;
	this->enemyChar = { 'M', 'A' };
	this->clues = 0;
	this->totalClues = 0;
	this->tree = TextTree();
	this->shipKey = true;
	this->repeat = false;

}

bool Player::getRepeat() {
	return this->repeat;
}
void Player::setRepeat(bool nRepeat) {
	this->repeat = nRepeat;
}

int Player::getTotalClues() {
	return this->totalClues;
}
void Player::setTotalClues(int nClues) {
	this->totalClues = nClues;
}

int Player::getClues() {
	return this->clues;
}
void Player::setClues(int nClues) {
	this->clues = nClues;
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
	this->food = nFood;
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
void Player::outputClue() {
	this->tree.outputText();
	this->clues += 1;
	this->totalClues += 1;
	this->tree.setTreePoint(this->totalClues);
}

void Player::Move() {
	//int key = getKeyValue();
	this->projX = entityX;
	this->projY = entityY;


	if (this->checkIfEnemy(this->entityX, this->entityY) == true){
		this->entityX = 10;
		this->entityY = 2;
		this->setLives(this->getLives() - 1);
		this->map->clearSpace(this->getX(), this->getY());
		this->map->changeChar('v');
		this->map->moveEntity(this->entityX, this->entityY);
		PrintFile ascii = PrintFile("./Ascii-art/lostLife.txt");
		ascii.OutputAscii();
		cout << " you lost a life" << endl;
		system("pause");
	}
	if (GetAsyncKeyState(KEY_DOWN)) {
		this->entityChar = 'v';
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
		else if (this->map->getChar(entityX, entityY + 1) == 'A') {
			this->alive = false;
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
		else if (this->map->getChar(entityX, entityY - 1) == 'A') {
			this->alive = false;
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
		else if (this->map->getChar(entityX-1, entityY) == 'A') {
			this->alive = false;
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
		else if (this->map->getChar(entityX+1, entityY) == 'A') {
			this->alive = false;
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
			else if (this->orientation == UP and this->map->getChar(this->entityX, this->entityY-1) == 'D') {
				this->entityChar = 'D';
				this->map->changeChar(this->entityChar);
				this->map->clearSpace(this->entityX, this->entityY);
				this->entityY -= 1;
				this->map->moveEntity(this->entityX, this->entityY);
				this->entityChar = '^';

			}
			else if (this->orientation == DOWN and this->map->getChar(this->entityX, this->entityY+1) == 'D') {
				this->entityChar = 'D';
				this->map->changeChar(this->entityChar);
				this->map->clearSpace(this->entityX, this->entityY);
				this->entityY += 1;
				this->map->moveEntity(this->entityX, this->entityY);
				this->entityChar = 'v';


			}
		}
		if (this->orientation == RIGHT and this->map->getChar(this->entityX + 1, this->entityY) == '!') {
			this->outputClue();
			system("cls");
		}
		else if (this->orientation == LEFT and this->map->getChar(this->entityX - 1, this->entityY) == '!') {
			this->outputClue();
			system("cls");

		}
	}
	

	
	
}

void Player::fillMag() {
	for (int i = 0; i < this->ammo + 1; i++) {
		Entity nBullet = Entity();
		nBullet.setChar('O');
		nBullet.setMap(this->map);
		this->magazine.push_back(nBullet);
	}
}


void Player::shoot() {
	if (this->state == SHOOTING) {
		this->map->setMessage("can't shoot, reloading");
		this->state = NUETRAL;
	}
	else {
		this->state = SHOOTING;
		this->shootBullet();
	}
}

void Player::shootBullet() {
	if (this->getState() == SHOOTING and this->getAmmo() > 0) {
		this->setState(NUETRAL);
		this->bullet = magazine[this->getAmmo()];
		this->setAmmo(this->getAmmo() - 1);
		if (this->getOrientation() == UP) {
			if (this->checkSpace(this->getX(), this->getY() - 1) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX());
				this->bullet.setY(this->getY() - 1);
				this->bullet.setOrientation(UP);
				this->projectiles.push_back(this->bullet);

			}


		}
		else if (this->getOrientation() == DOWN) {
			if (this->checkSpace(this->getX(), this->getY() + 1) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX());
				this->bullet.setY(this->getY() + 1);
				this->bullet.setOrientation(DOWN);
				this->projectiles.push_back(this->bullet);

			}


		}
		else if (this->getOrientation() == LEFT) {
			if (this->checkSpace(this->getX() - 1, this->getY()) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX() - 1);
				this->bullet.setY(this->getY());
				this->bullet.setOrientation(LEFT);
				this->projectiles.push_back(this->bullet);

			}


		}
		else if (this->getOrientation() == RIGHT) {
			if (this->checkSpace(this->getX() + 1, this->getY()) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX() + 1);
				this->bullet.setY(this->getY());
				this->bullet.setOrientation(RIGHT);
				this->projectiles.push_back(this->bullet);

			}


		}
	}
}
void Player::moveBullet() {

	for (int i = 0; i < this->projectiles.size(); i++) {
		if (this->projectiles[i].isAlive()) {
			this->projectiles[i].Move();
		}
		else {
			this->map->changeChar(' ');
			this->map->moveEntity(this->projectiles[i].getX(), this->projectiles[i].getY());
			this->map->moveEntity(0, 0);
			this->projectiles.erase(projectiles.begin() + i, projectiles.begin() + i + 1);
		}


	}
}