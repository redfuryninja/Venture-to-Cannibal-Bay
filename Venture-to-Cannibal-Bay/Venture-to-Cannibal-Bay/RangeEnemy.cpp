#include "RangeEnemy.h"
RangeEnemy::RangeEnemy() {
	this->arrows = 24;
	this->count = 9;
}
//goes through a loop creating objects and putting them in a vector
void RangeEnemy::fillquiver() {
	for (int i = 0; i <this->arrows; i++) {
		Entity nBullet = Entity();
		nBullet.setChar('A');
		nBullet.setMap(this->map);
		this->quiver.push_back(nBullet);
	}
}

//checks if the enemy is in a state to be shooting
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

//gets size of how many projectiles are left
int RangeEnemy::getQuiverSize() {
	return this->quiver.size();
}
//handles movement of arrows has count to set time period between each shot
void RangeEnemy::shootArrow() {
	if (this->getState() == SHOOTING and this->arrows>0 and this->count == 9) {
		this->count = 0;
		this->arrows -= 1;
		//gets the specific projectile from the vector
		this->bullet = this->quiver[this->arrows];
		
		//Moves the projectile up
		if (this->getOrientation() == UP) {
			if (this->checkSpace(this->getX(), this->getY() - 1) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX());
				this->bullet.setY(this->getY() - 1);
				this->bullet.setOrientation(UP);
				this->projectiles.push_back(this->bullet);

			}


		}
		//places the projectile down
		else if (this->getOrientation() == DOWN) {
			if (this->checkSpace(this->getX(), this->getY() + 1) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX());
				this->bullet.setY(this->getY() + 1);
				this->bullet.setOrientation(DOWN);
				this->projectiles.push_back(this->bullet);

			}


		}
		//places the projectile left
		else if (this->getOrientation() == LEFT) {
			if (this->checkSpace(this->getX() - 1, this->getY()) == true) {
				this->bullet.setState(MOVING);
				this->bullet.setX(this->getX() - 1);
				this->bullet.setY(this->getY());
				this->bullet.setOrientation(LEFT);
				this->projectiles.push_back(this->bullet);

			}


		}
		//places the projectile right
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
	//handles the count and the arrows handled so if the one hits 0 before the other one isn't forgotten until the next loop
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
	//moves the arrow and if it cant move clears the space
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
	//checks the position ahead of it and changes alive if it isn't
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


