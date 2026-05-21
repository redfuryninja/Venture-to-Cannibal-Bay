#pragma once
#include "Enemy.h"
//inherits from enemy instead of entity as the enemies have different movement
class RangeEnemy: public Enemy
{
private:
	vector <Entity> quiver;
	vector <Entity> projectiles;
	Entity bullet;
	int arrows;
	int count;
public:
	//constructs the enemy
	RangeEnemy();
	//checks if the player can shoot and starts the process if they can
	void shoot();
	//checks if anything shares it's coordinats which kills the enemy if it is
	void Move() override;
	//fills the vector with Entitys that will move on command
	void fillquiver();
	//handles the spawning of projectiles
	void shootArrow();
	//moves the projectiles
	void moveArrow();
	//gets the size of how many projectiles the enemy has
	int getQuiverSize();
};

