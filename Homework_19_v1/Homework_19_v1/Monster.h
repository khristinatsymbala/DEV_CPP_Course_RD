#pragma once
#include <string>
#include <memory>
class Monster
{
public:
	Monster();
	virtual ~Monster() {}

	virtual Monster* clone() = 0;

	virtual std::string GetName() = 0;
	virtual float GetHealth() = 0;
	virtual float GetDamage() = 0;
	virtual int GetXP() = 0;
	virtual void SetHealth(float newHealth) = 0;
};

class Spawner
{
public:
	Spawner(Monster* prototype)
		:prototype_{ prototype } 
	{}
	~Spawner() {}

	Monster* spawnMonster() {
		return prototype_->clone();
	}

private:
	Monster* prototype_;
};

//class Spawner {
//public:
//	Spawner(std::unique_ptr<Monster> prototype)
//		: prototype_(std::move(prototype)) {}
//
//	std::unique_ptr<Monster> spawnMonster() {
//		return prototype_->clone();
//	}
//
//private:
//	std::unique_ptr<Monster> prototype_;
//};

class Slime : public Monster {
public:
	Slime() {}
	~Slime() {}

	virtual std::string GetName() { return "Slime"; }
	virtual float GetHealth() { return health_; }
	virtual float GetDamage() { return 1.0f; }
	virtual int GetXP() { return 1; }

	virtual Monster* clone() {
		return new Slime();
	}
	virtual void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health_ = newHealth;
		}
	}
private:
	float health_ = 2.0f;
};

class Goblin : public Monster {
public:
	Goblin() {}
	~Goblin() {}

	virtual std::string GetName() { return "Goblin"; }
	virtual float GetHealth() { return health_; }
	virtual float GetDamage() { return 5.0f; }
	virtual int GetXP() { return 1; }

	virtual Monster* clone() {
		return new Goblin();
	}
	virtual void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health_ = newHealth;
		}
	}
private:
	float health_ = 20.f;
};