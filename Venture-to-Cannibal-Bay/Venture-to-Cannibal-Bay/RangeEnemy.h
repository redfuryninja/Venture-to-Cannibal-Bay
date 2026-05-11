#pragma once
#include "Enemy.h"
class RangeEnemy: public Enemy
{
private:
	vector <Entity> quiver;
	vector <Entity> projectiles;
	Entity bullet;
	int arrows;
	int count;
public:
	RangeEnemy();
	void shoot();
	void Move() override;
	void fillquiver();
	void shootArrow();
	void moveArrow();
	int getQuiverSize();
};

