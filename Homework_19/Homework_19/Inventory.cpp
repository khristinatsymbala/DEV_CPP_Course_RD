#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::AddWeapon(std::unique_ptr<Weapon> weapon)
{
	

	if (weapons.size() >= maxWeapons) {
		std::cout << "Inventory is full. Cannot add more weapons." << std::endl;
		return;
	}

	weapons.push_back(std::move(weapon));

}

void Inventory::DropWeapon(std::unique_ptr<Weapon> weapon)
{
	
}
