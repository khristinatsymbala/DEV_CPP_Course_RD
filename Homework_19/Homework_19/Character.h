#pragma once
#include <memory>
#include "Weapon.h"
#include <string>

class Character
{
public:
	Character();
	Character(std::string Name, int XP, float Health, float Defence);
	~Character();

	// обробка зброї
	void SetWeapon(std::unique_ptr<Weapon> weapon);
	void HideWeapon(std::unique_ptr<Weapon> weapon);

	//дає змогу дізнатися, що за вепон у персонажа
	Weapon* GetWeapon() const;

private:
	std::string name;
	int Xp{ 0 };
	float health{ 0 };
	float defence{ 0 };

	bool haveWeapon = false;
};

