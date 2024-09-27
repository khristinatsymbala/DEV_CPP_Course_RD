/*
Створити базовий клас Персонажа Character із методами
void SetWeapon(unique_ptr<Weapon> weapon); видає зброю персонажу
Weapon* GetWeapon() const; дає змогу дізнатися, що за вепон у персонажа


Створити базовий клас Weapon із двома абстрактними методами
float GetDamage() = 0; повертає значення шкоди зброї
string GetName() = 0; повертає назву зброї


Створити хоча б 3 класи-нащадки різних видів зброї
Завдання із зірочкою:
Переробити клас персонажа таким чином, що персонаж може мати у себе декілька екземплярів зброї, але тільки одна (або жодна) може бути обрана

*/
#include <iostream>
#include "Character.h"



int main()
{
    std::cout << "---------Welcome to the Adventure!---------" << std::endl;
    std::cout << "You are entering a dark forest filled with dangers." << std::endl;

    Character hero("Hero",10,45);
    hero.AddWeapon(std::make_unique<Sword>());
    hero.AddWeapon(std::make_unique<Halberd>());

    std::cout << "Slime appear on your way" << std::endl;
    std::cout << "What will you do?" << std::endl;
    std::cout << "1. Fight monsters; 2. Run away." << std::endl;

    int choice;
    std::cin >> choice;

    std::unique_ptr<Slime> slime = std::make_unique<Slime>(2, 2);

    if (choice == 1) {
        hero.FightMonster(std::move(slime), hero);
    }
    else if (choice == 0) {
        std::cout << "You ran away safely" << std::endl;
        return 0;
    }


    

   /* std::cout << "Want to equip a weapon..." << std::endl;
    hero.ChooseWeapon();*/

}


