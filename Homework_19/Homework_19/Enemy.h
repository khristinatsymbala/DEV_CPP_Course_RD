#pragma once
#include <string>
class Monster
{
public:
	Monster();
	virtual ~Monster() {}
	//virtual Monster* clone() = 0;
	virtual std::string GetName() = 0;
	virtual float GetHealth() = 0;
	virtual void SetHealth(float newHealth) = 0;

	virtual float GetDamage() = 0;
	virtual int GetXP() = 0;

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



class Slime : public Monster
{
public:

	Slime(float health, float damage)
		: health_{ health }, damage_{ damage } {}

	virtual float GetHealth() override { return health_; }
	virtual std::string GetName() override { return Name; }
	virtual void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health_ = newHealth;
		}
	}

	virtual float GetDamage() { return damage_; }
	virtual int GetXP() { return Xp_; }

private:
	float health_ = 2.0f;
	float damage_ = 2.0f;
	int Xp_ = 2;
	std::string Name = "Slime";
};



