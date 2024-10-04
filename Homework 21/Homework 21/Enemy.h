#pragma once
#include "Actor.h"
#include<iostream>


class Enemy : public Actor, public IHealthUpdateReceiver, public IDamagable {
public:
	//приклад використання в отримані повідомленя 
	virtual void ReceiveNewHealth(float newHealth) {
		std::cout << "Enemy got new info about new health  " << newHealth << std::endl;
	}

	Enemy() {};
	virtual ~Enemy() {};
	virtual void ApplyDamage(float damage) = 0;
	virtual Enemy* clone() = 0;
	virtual Character* ChooseTarget(Character* hero,Character* hero2) =0;
	//virtual Character* ChooseTarget() = 0;
	virtual std::string GetName() = 0;
	virtual float GetHealth() = 0;
	virtual float GetDamage() = 0;
	virtual int GetXP() = 0;
	virtual void SetHealth(float newHealth) = 0;
	virtual float Atack() = 0;
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
	virtual void ApplyDamage(float damage) {
		health_ -= damage;
	}
	float newCharacterHealth = 0.f;
	virtual void ReceiveNewHealth(float newHealth) {
		std::cout << "Slime got new info about new health   " << newHealth << std::endl;
		newCharacterHealth = newHealth;
	}

	virtual std::string GetName() { return "Slime"; }
	virtual float GetHealth() { return health_; }
	virtual float GetDamage() { return damage; }

	virtual float Atack() {

		float Damage = damage; 

		if (newCharacterHealth <= 50.f) {
			Damage /= 2; 
		}

		return Damage;
	}

	virtual int GetXP() { return 1; }

	virtual Enemy* clone() {
		return new Slime();
	}
	virtual void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health_ = newHealth;
		}
	}

	virtual Character* ChooseTarget(Character* hero, Character* hero2) {
		if (hero->GetHealth() <= 50) {
			std::cout << "Hero name - " << hero->GetName() << std::endl;
			return hero;  
		}
		else if (hero2->GetHealth() <= 50) {
			std::cout << "Hero name - " << hero2->GetName()<<std::endl;
			return hero2; 
		}
		else {
			Character* random = (rand() % 2 == 0) ? hero : hero2;
			std::cout << "Hero name - " << random->GetName() << std::endl;
			return random;
		}}
	
private:
	float health_ = 50.0f;
	float damage = 25.0f;
};

//class Goblin : public Enemy {
//public:
//	Goblin() {}
//	~Goblin() {}
//
//	Goblin(Goblin& g) {
//		health_ = g.health_;
//	}
//	virtual void ReceiveNewHealth(float newHealth) {
//		std::cout << "Goblin got new info" << newHealth << std::endl;
//	}
//	virtual void ApplyDamage(float damage) {
//		health_ -= damage;
//	}
//	virtual std::string GetName() { return "Goblin"; }
//	virtual float GetHealth() { return health_; }
//	virtual float GetDamage() { return 20.0f; }
//	virtual int GetXP() { return 1; }
//
//	virtual Character* ChooseTarget(Character* hero, Character* hero2) {
//		if (hero->GetHealth() <= 50) {
//			return hero;
//		}
//		else if (hero2->GetHealth() <= 50) {
//			return hero2;
//		}
//		else {
//
//			return (rand() % 2 == 0) ? hero : hero2;
//		}
//	}
//
//
//	virtual Enemy* clone() {
//		return new Goblin();
//	}
//	virtual void SetHealth(float newHealth) {
//		if (newHealth >= 0) {
//			health_ = newHealth;
//		}
//	}
//private:
//	float health_ = 80.f;
//};