#include "Actor.h"
#include "Enemy.h"
#include "Weapon.h"

void Character::SetWeapon(std::unique_ptr<Weapon> weapon)
{
    if (activeWeaponIndex >= 0 && activeWeaponIndex < inventory.size()) {
        std::cout << "Unequipping: " << inventory[activeWeaponIndex]->GetName() << std::endl;
    }

    inventory.push_back(std::move(weapon));
    activeWeaponIndex = inventory.size() - 1;

    std::cout << "Equipped: " << inventory[activeWeaponIndex]->GetName() << std::endl;
}

Weapon* Character::GetWeapon() const
{
    if (activeWeaponIndex >= 0 && activeWeaponIndex < inventory.size()) {
        return inventory[activeWeaponIndex].get();
    }
    return nullptr;
}
void Character::ListWeapons()
{
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i << ". " << inventory[i]->GetName() << std::endl;
    }
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

void Character::Fight(Enemy* monster)
{
    float damage = GetWeapon()->GetDamage();
    
    monster->ApplyDamage(damage);
    std::cout << "You attack the " << monster->GetName() << " with your " << GetWeapon()->GetName()
        << ", " << damage << " damage. Monster HP: " << monster->GetHealth() << std::endl;


    ApplyDamage(monster->Atack());
    //SetHealth(GetHealth() - monster->GetDamage());

    std::cout << monster->GetName() << " hits you for " << monster->GetDamage()
        << " damage. Your HP: " << GetHealth() << std::endl;

    
    
    if (monster->GetHealth() < 0) {
        std::cout << "You defeated the " << monster->GetName() << std::endl;
        GainXP(monster->GetXP());
    }
    else if (GetHealth() <= 0) {
        std::cout << "You have been defeated!" << std::endl;
    }
}
