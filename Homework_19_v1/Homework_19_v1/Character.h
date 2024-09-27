#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iostream>
class Weapon;
class Character {
public:
		Character() {}
		Character(std::string Name, int XP, float Health)
			:name{ Name }, Xp{ XP }, health{ Health } {}
		~Character() {}

		//  видає зброю персонажу
		void SetWeapon(std::unique_ptr<Weapon> weapon);

		//дає змогу дізнатися, що за вепон у персонажа
		Weapon* GetWeapon() const;

		void ListWeapons();
		void GainXP(int Xp_enemy);
		float GetHealth() { return health; }
		void SetHealth(float newHealth) {
			if (newHealth >= 0) {
				health = newHealth;
			}
		}

		//void Fight(Monster* monster, Character hero);
private:
	std::string name;
	int Xp{ 0 };
	float health{ 100.0f };
	int activeWeaponIndex;
	int maxWeapons{ 2 };
	std::vector<std::unique_ptr<Weapon>> inventory;
};