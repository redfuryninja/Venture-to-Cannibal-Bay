#include "Entity.h"
//constuor
Entity::Entity() {
	this->state = NUETRAL;
	this->orientation = DOWN;
	this->alive = true;
	this->startX = 0;
	this->startY = 0;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->entityChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->charCheck = '/';
	this->playerChars = { 'v','^','<','>' };
	this->playerWeapon = { 'O', '!', 'A'};
}



int Entity::getStartX() {
	return this->startX;
}
int Entity::getStartY() {
	return this->startY;
}
void Entity::setX(int nX)
{
	this->entityX = nX;
}

int Entity::getX()
{
	return this->entityX;
}

void Entity::setY(int nY)
{
	this->entityY = nY;
}

void Entity::setChar(char nChar) {
	this->entityChar = nChar;
}

int Entity::getY()
{
	return this->entityY;
}

EntityState Entity::getState(){
	return this->state;
}
EntityOrientation Entity::getOrientation() {
	return this->orientation;
}

void Entity::setState(EntityState nState) {
	this->state = nState;
}
void Entity::setOrientation(EntityOrientation nOrientation) {
	this->orientation = nOrientation;
}

bool Entity::isAlive()
{
	return this->alive;
}

void Entity::kill()
{
	this->alive = false;
}


//checks if the character in the coordinates is a space or an A returns true if that is the case
bool Entity::checkSpace(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	
	if (this->charCheck == ' ' or this->charCheck == 'A' ) {

		return true;

	}
	return false;
}

//checks if player on coordinates is a player
bool Entity::checkIfPlayer(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	
	for (int i = 0; i < this->playerChars.size(); i++) {
		if (this->charCheck == playerChars[i]) {
			return true;
		}

	}


	return false;
}

//checks if player on coordinates is a weapon
bool Entity::checkIfWeapon(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	
	for (int i = 0; i < this->playerWeapon.size(); i++) {
		if (this->charCheck == playerWeapon[i]) {
			return true;
		}

	}


	return false;
}


//gets value of a keypress
int Entity::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}
// gets the map dimention from the map pointer and places the entity on the given cooridinates
void Entity::setMap(Maps* currMap) {
	this->map = currMap;
	this->mapWidth = this->map->getWidth();
	this->mapHeight = this->map->getHeight();
	this->map->changeChar(this->entityChar);
	this->map->moveEntity(this->entityX, this->entityY);
}

void Entity::Move() {
	//checks the space in the orientation set to the entity and if its not a wall it will keep moving until it shares teh x and y coords
	if (this->orientation == DOWN) {

		this->canMoveY = checkSpace(this->entityX, this->entityY + 1);
		if (this->canMoveY == true or this->checkIfPlayer(this->entityX, this->entityY + 1) or this->checkIfPlayer(this->entityX, this->entityY - 1) == true) {
			this->map->changeChar(this->entityChar);
			this->map->clearSpace(this->entityX, this->entityY);
		
			this->entityY += 1;

			this->map->moveEntity(this->entityX, this->entityY);
		}
		else {
			this->alive = false;
		}
	}
	else if (this->orientation == UP) {

		this->canMoveY = checkSpace(this->entityX, this->entityY - 1) ;
		if (this->canMoveY == true or this->checkIfPlayer(this->entityX, this->entityY - 1) == true) {
			this->map->changeChar(this->entityChar);

			this->map->clearSpace(this->entityX, this->entityY);
			this->entityY -= 1;
			this->map->moveEntity(this->entityX, this->entityY);

		}
		else {
			this->alive = false;
		}
	}
	else if (this->orientation == LEFT) {

		this->canMoveX = checkSpace(this->entityX - 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);

			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX -= 1;
			this->map->moveEntity(this->entityX, this->entityY);

		}
		else {
			this->alive = false;
		}
	}
	else if (this->orientation == RIGHT) {

		this->canMoveX = checkSpace(this->entityX + 1, this->entityY);
		if (this->canMoveX == true) {
			this->map->changeChar(this->entityChar);

			this->map->clearSpace(this->entityX, this->entityY);
			this->entityX += 1;
			this->map->moveEntity(this->entityX, this->entityY);

		}
		else {
			this->alive = false;
		}
	}
}
