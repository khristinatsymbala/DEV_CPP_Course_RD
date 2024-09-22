#pragma once
#include <vector>
#include <memory>
#include "Weapon.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void AddWeapon(std::unique_ptr<Weapon> weapon);
	void DropWeapon(std::unique_ptr<Weapon> weapon);

	void AddNewSlot();

private:
	std::vector<std::unique_ptr<Weapon>> weapons;
	int maxWeapons = 3;
};

