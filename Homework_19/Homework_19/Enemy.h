#pragma once
class Monster
{
public:
	Monster();
	~Monster() {}
	virtual Monster* clone() = 0;

private:

};

class Spawner
{
public:
	Spawner(Monster* prototype)
		:prototype_{ prototype } 
	{}
	~Spawner();

	Monster* spawnMonster();

private:
	Monster* prototype_;
};



