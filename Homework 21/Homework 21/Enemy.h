#pragma once
#include "Actor.h"
#include<iostream>

class Enemy : public Actor, public IHealthUpdateReceiver {
public:
	//приклад використання в отримані повідомленя 
	virtual void ReceiveNewHealth(float newHealth) {
		std::cout << "Enemy got new info" << newHealth << std::endl;
	}

	Enemy() {};
	virtual ~Enemy() {};

	virtual Enemy* clone() = 0;

	virtual std::string GetName() = 0;
	virtual float GetHealth() = 0;
	virtual float GetDamage() = 0;
	virtual int GetXP() = 0;
	virtual void SetHealth(float newHealth) = 0;
};

class Spawner
	{
	public:
		Spawner(std::unique_ptr<Enemy> prototype)
			: prototype_{ std::move(prototype) } {}


		~Spawner() {}

		Spawner(Spawner&& s) {
			prototype_ = std::move(s.prototype_);
			std::cout << "Move Constructor Called" << std::endl;
		}

		std::unique_ptr<Enemy> spawnMonster() {
			return std::unique_ptr<Enemy>(prototype_->clone()); // Return a unique_ptr
		}
	
	private:
		std::unique_ptr<Enemy> prototype_;
	};


class Slime : public Enemy {
public:
	Slime() {}
	~Slime() {}

	Slime(Slime& s) {
		health_ = s.health_;
		std::cout << "Copy Constructor Called" << std::endl;
	}

	virtual void ReceiveNewHealth(float newHealth) {
		std::cout << "Slime got new info" << newHealth << std::endl;
	}

	virtual std::string GetName() { return "Slime"; }
	virtual float GetHealth() { return health_; }
	virtual float GetDamage() { return 7.0f; }
	virtual int GetXP() { return 1; }

	virtual Enemy* clone() {
		return new Slime();
	}
	virtual void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health_ = newHealth;
		}
	}
private:
	float health_ = 15.0f;
};

class Goblin : public Enemy {
public:
	Goblin() {}
	~Goblin() {}

	Goblin(Goblin& g) {
		health_ = g.health_;
	}
	virtual void ReceiveNewHealth(float newHealth) {
		std::cout << "Goblin got new info" << newHealth << std::endl;
	}

	virtual std::string GetName() { return "Goblin"; }
	virtual float GetHealth() { return health_; }
	virtual float GetDamage() { return 5.0f; }
	virtual int GetXP() { return 1; }

	virtual Enemy* clone() {
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