#pragma once
#include <memory>
#include "Weapon.h"
#include <string>
#include <vector>
#include <iostream>
#include "Enemy.h"

class Character
{
public:
	Character();
	Character(std::string Name, int XP, float Health);
	~Character();

	void ChooseWeapon();
	
	//  видає зброю персонажу
	void SetWeapon(std::unique_ptr<Weapon> weapon);

	//дає змогу дізнатися, що за вепон у персонажа
	Weapon* GetWeapon() const;

	void AddWeapon(std::unique_ptr<Weapon> weapon);
	void ListWeapons();

	float GetHealth() { return health; }
	void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health = newHealth;
		}
	}

	bool HasWeapons() const {
		return !inventory.empty();
	}
	
	std::unique_ptr<Weapon> GetWeaponAtIndex(int index);

	void GainXP(int Xp_enemy);

	void FightMonster(std::unique_ptr<Monster> monster, Character& hero);

private:
	std::string name;
	int Xp{ 0 };
	float health{ 100.0f };
	

	int maxWeapons = 2;
	
	int activeWeapon{ -1 };
	std::vector<std::unique_ptr<Weapon>> inventory;
	
};

