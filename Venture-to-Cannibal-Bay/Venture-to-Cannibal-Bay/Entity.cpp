#include "Entity.h"


Entity::Entity()
{
	this->x = 0;
	this->y = 0;
	this->state = "Neutral";
	this->orientation = "Left";
	this->alive = true;
}

void Entity::setX(int nX)
{
	this->x = nX;
}

int Entity::getX()
{
	return this->x;
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
