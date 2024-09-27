#include "Character.h"

Character::Character()
{
}

Character::Character(std::string Name, int XP, float Health)
	:name{Name},Xp{XP},health{Health}
{
}

Character::~Character()
{
}

void Character::ChooseWeapon()
{
    if (activeWeapon == -1) { // no weapon 
        int index;
        ListWeapons();

        std::cout << "Choose a weapon to equip (index): ";
        std::cin >> index;

        if (index >= 0 && index < inventory.size()) {
            activeWeapon = index;
            SetWeapon(std::move(inventory[index]));
        }
        else {
            std::cout << "Invalid selection." << std::endl;
        }
    }
    else {
        std::cout << "You already have a weapon equipped. Do you want to change it?" << std::endl;
        std::cout << "1. Yes; 2. No;";
        int choice;
        std::cin >> choice;

        if (choice == 1) {

            int newIndex;
            ListWeapons();
            std::cout << "Select a new weapon to equip: ";
            std::cin >> newIndex;

            if (newIndex >= 0 && newIndex < inventory.size()) {
                activeWeapon = newIndex;
                SetWeapon(std::move(inventory[newIndex]));
            }
            else {
                std::cout << "Invalid selection." << std::endl;
            }
        }
    }
}

void Character::SetWeapon(std::unique_ptr<Weapon> weapon)
{
    if (weapon) {
        if (activeWeapon >= 0 && activeWeapon < inventory.size() && inventory[activeWeapon]) {
            std::cout << "Equipped: " << inventory[activeWeapon]->GetName() << std::endl;
        }
        else {
            std::cout << "Invalid index or no weapon equipped." << std::endl;
        }
    }
    else {
        std::cout << "No weapon provided to equip." << std::endl;
    }
}


Weapon* Character::GetWeapon() const
{
    if (activeWeapon >= 0 && activeWeapon < inventory.size()) {
        return inventory[activeWeapon].get();
    }
    return nullptr;
}

void Character::AddWeapon(std::unique_ptr<Weapon> weapon)
{
    if (inventory.size() < maxWeapons) {
        inventory.push_back(std::move(weapon));
        std::cout << "Added new weapon to inventory!" << std::endl;
    }
    else {
        std::cout << "No available slots for new weapons. Defeat more monsters to earn slots!" << std::endl;
    }
}

void Character::ListWeapons()
{
    if (inventory.empty()) {
        std::cout << "No weapons in inventory." << std::endl;
        return;
    }
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i << ". " << inventory[i]->GetName() << std::endl;
    }
}



std::unique_ptr<Weapon> Character::GetWeaponAtIndex(int index)
{
    if (index >= 0 && index < inventory.size()) {
        std::unique_ptr<Weapon> weapon = std::move(inventory[index]); 
        inventory.erase(inventory.begin() + index); 
        return weapon;
    }
    return std::unique_ptr<Weapon>();
}

void Character::GainXP(int Xp_enemy)
{
    Xp += Xp_enemy;
    std::cout << "You earned " << Xp_enemy << " XP. Total XP: " << Xp << std::endl;

    if (Xp >= 50) {
        Xp -= 50;
        maxWeapons++;

        std::cout << "Congratulations! You unlocked a new weapon slot. Total slots: " << maxWeapons << std::endl;
    }

}

void Character::FightMonster(std::unique_ptr<Monster> monster, Character& hero)
{
    if (!hero.GetWeapon()) {
        std::cout << "No weapon equipped! Cannot fight." << std::endl;

        ChooseWeapon();

        return;
    }

    std::cout << "A wild " << monster->GetName() << " appears with " << monster->GetHealth() << " HP!" << std::endl;


    while (monster->GetHealth() > 0 && hero.GetHealth() > 0) {

        float damage = hero.GetWeapon()->GetDamage();

        monster->SetHealth(monster->GetHealth() - damage);

        std::cout << "You attack the " << monster->GetName() << " with your " << hero.GetWeapon()->GetName()
            << ", " << damage << " damage. Monster HP: " << monster->GetHealth() << std::endl;


        hero.SetHealth(hero.GetHealth() - monster->GetDamage());
        std::cout << monster->GetName() << " hits you for" << monster->GetDamage() << " damage.Your HP : " << hero.GetHealth() << std::endl;
    }

    if (monster->GetHealth() <= 0) {
        std::cout << "You defeated the " << monster->GetName() << std::endl;
        hero.GainXP(monster->GetXP());
    }
    else {
        std::cout << "You were defeated by the " << monster->GetName() << std::endl;
    }
}

