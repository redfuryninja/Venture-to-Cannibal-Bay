#include "RangeEnemy.h"
RangeEnemy::RangeEnemy() {
	this->arrows = 24;
	this->count = 9;
}
void RangeEnemy::fillquiver() {
	for (int i = 0; i <this->arrows; i++) {
		Entity nBullet = Entity();
		nBullet.setChar('A');
		nBullet.setMap(this->map);
		this->quiver.push_back(nBullet);
	}
}


void RangeEnemy::shoot() {
	if (this->state == SHOOTING) {
		this->map->setMessage("can't shoot, reloading");
		this->state = NUETRAL;
	}
	else {
		this->state = SHOOTING;
		this->shootArrow();
	}
}
int RangeEnemy::getQuiverSize() {
	return this->quiver.size();
}

void RangeEnemy::shootArrow() {
	if (this->getState() == SHOOTING and this->arrows>0 and this->count == 9) {
		this->count = 0;
		this->arrows -= 1;
		this->bullet = this->quiver[this->arrows];
		
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
	else if (this->count != 9 and this->arrows <= 0) {
		this->count += 1;
		this->arrows = 24;
	}
	else if (this->arrows <= 0) {
		this->arrows = 24;
	}
	else if (this->count != 9) {
		this->count += 1;
	}

}
void RangeEnemy::moveArrow() {

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

void RangeEnemy::Move() {
	shoot();
	if (this->map->getChar(entityX-1, entityY) == 'O' or this->map->getChar(entityX-1, entityY) == '!') {
		this->alive = false;
		this->weaponDeath = true;
	}
	else if (this->map->getChar(entityX+1, entityY) == 'O' or this->map->getChar(entityX+1, entityY) == '!') {
		this->alive = false;
		this->weaponDeath = true;
	}
	else if (this->map->getChar(entityX, entityY-1) == 'O' or this->map->getChar(entityX, entityY-1) == '!') {
		this->alive = false;
		this->weaponDeath = true;
	}
	else if (this->map->getChar(entityX, entityY+1) == 'O' or this->map->getChar(entityX, entityY+1) == '!') {
		this->alive = false;
		this->weaponDeath = true;
	}
	else if (this->checkIfPlayer(this->entityX, this->entityY)) {
		this->alive = false;
	}
}


