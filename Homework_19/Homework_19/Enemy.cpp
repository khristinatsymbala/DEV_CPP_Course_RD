#include "Enemy.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}


Spawner::~Spawner()
{
}

Monster* Spawner::spawnMonster()
{
	return prototype_->clone();
}
