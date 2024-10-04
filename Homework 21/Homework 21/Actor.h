#pragma once
#include<vector>
#include <memory>
#include <iostream>
#include "Interface.h"

class Enemy;
class Weapon;


class Actor {
public:
private:

};

//public IHealthNotifier - підписується на це, бо він сповіщає всім кому це потрібно
class Character : public Actor, public IHealthNotifier, public IDamagable
{
public:

	virtual void ApplyDamage(float damage) {
		health -= damage;
		//проходимось по масиву та відсилаємо нове здоров'я
		for (IHealthUpdateReceiver* receiver : subscribers)
		{
			receiver->ReceiveNewHealth(health);
		}
	}
	virtual void Subscribe(IHealthUpdateReceiver* receiver) 
	{
		subscribers.push_back(receiver);
	}
	virtual void Unsubscribe(IHealthUpdateReceiver* receiver) {
		//тут ми шукаємо між початком та кінцем, нашого ресівера
		subscribers.erase(std::find(subscribers.begin(), subscribers.end(),receiver));
	}

	Character(std::string Name, int XP, float Health)
		:name{ Name }, Xp{ XP }, health{ Health } {}
	~Character() {}

	//  видає зброю персонажу
	void SetWeapon(std::unique_ptr<Weapon> weapon);

	//дає змогу дізнатися, що за вепон у персонажа
	Weapon* GetWeapon() const;

	void ListWeapons();
	void GainXP(int Xp_enemy);

	bool IsAlive() const { return health > 0; }
	float GetHealth() { return health; }
	void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health = newHealth;
		}
	}

	void Fight(Enemy* monster);

private:
	// зберігання наших сабскраберів
	std::vector <IHealthUpdateReceiver*> subscribers;
	float health = 100.0f;

	std::string name;
	int activeWeaponIndex;
	int maxWeapons{ 2 };
	int Xp{ 0 };
	std::vector<std::unique_ptr<Weapon>> inventory;
};