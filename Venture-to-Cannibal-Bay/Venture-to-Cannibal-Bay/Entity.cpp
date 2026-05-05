#include "Entity.h"

Entity::Entity() {
	this->state = "Neutral";
	this->orientation = "Left";
	this->alive = true;
	this->entityX = 10;
	this->entityY = 2;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->charCheck = '/';
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

int Entity::getY()
{
	return this->entityY;
}



std::string Entity::getState()
{
	return this->state;
}

void Entity::setState(std::string nState)
{
	this->state = nState;
}

std::string Entity::getOrientation()
{
	return this->orientation;
}

void Entity::setOrientation(std::string nOrientation)
{
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

void Entity::setMap(Maps* currMap) {
	this->map = currMap;
	this->mapWidth = this->map->getWidth();
	this->mapHeight = this->map->getHeight();
	this->map->changeChar(this->playerChar);
	this->map->moveEntity(this->entityX, this->entityY);
}

bool Entity::checkSpace(int futureX, int futureY) {
	this->charCheck = this->map->getMapChar(futureX, futureY);
	//this->mapChar = map[futureX + futureY * this->mapWidth];
	if (this->charCheck == ' ') {

		return true;

	}
	return false;
}








int Entity::getKeyValue() {
	int value = -1;

	while (1) {
		value = _getch();

		if (value != -1)
			return value;
	}
}

/*https://learn.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-6.0/aa299374(v=vs.60) */

void Entity::Move() {
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
