#include "Character.h"

Character::Character()
{
}

Character::Character(std::string Name, int XP, float Health, float Defence)
	:name{Name},Xp{XP},health{Health},defence{Defence}
{
}

Character::~Character()
{
}

void Character::SetWeapon(std::unique_ptr<Weapon> weapon)
{
}

void Character::HideWeapon(std::unique_ptr<Weapon> weapon)
{
}

Weapon* Character::GetWeapon() const
{
	
}
