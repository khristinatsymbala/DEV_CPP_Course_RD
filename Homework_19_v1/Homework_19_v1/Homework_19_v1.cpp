// Homework_19_v1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Monster.h"
#include <memory>
int main()
{
    
    std::cout << "---------Welcome to the Adventure!---------" << std::endl;
    std::cout << "You are entering a dark forest filled with dangers." << std::endl;

    Character hero("Hero",0,100.0f);

    hero.SetWeapon(std::make_unique<Sword>());
    hero.SetWeapon(std::make_unique<Halberd>());

   
    std::cout << "Available weapons:" << std::endl;
    hero.ListWeapons();

    Weapon* equippedWeapon = hero.GetWeapon();

    if (equippedWeapon) {
        std::cout << "Currently equipped weapon: " << equippedWeapon->GetName() << " with damage: " << equippedWeapon->GetDamage() << std::endl;
    }
    else {
        std::cout << "No weapon equipped." << std::endl;
    }

    std::cout << "5 Slime appear on your way" << std::endl;
    std::cout << "What will you do?" << std::endl;
    std::cout << "1. Fight monsters; 2. Run away." << std::endl;

    int choice;
    std::cin >> choice;

   /* Monster* slimePrototype = new Slime();
    Spawner* slimeSpawner = new Spawner(slimePrototype);*/

    Monster* goblinPrototype = new Goblin();
    Spawner* goblinSpawner = new Spawner(goblinPrototype);

    std::unique_ptr<Monster> slimePrototype = std::make_unique<Slime>();
    std::unique_ptr <Spawner> slimeSpawner = std::make_unique<Spawner>(std::move(slimePrototype));

    
    if (choice == 1) {

        for (int i = 0; i < 5; i++) {

            Monster* slime = slimePrototype->clone();

            //hero.Fight(slime, hero);
            float damage = hero.GetWeapon()->GetDamage();

            hero.SetHealth(hero.GetHealth() - slime->GetDamage());
            std::cout << slime->GetName() << " hits you for " << slime->GetDamage()
                << " damage. Your HP: " << hero.GetHealth() << std::endl;

            slime->SetHealth(slime->GetHealth() - damage);
            std::cout << "You attack the " << slime->GetName() << " with your " << hero.GetWeapon()->GetName()
                << ", " << damage << " damage. Monster HP: " << slime->GetHealth() << std::endl;


            if (slime->GetHealth() < 0) {
                std::cout << "You defeated the " << slime->GetName() << std::endl;
                hero.GainXP(slime->GetXP());
            }
            else if (hero.GetHealth() <= 0) {
                std::cout << "You have been defeated!" << std::endl;
                break;
            }

            delete slime;
        }

    }

    //if (choice == 1) {
    //   
    //    for (int i = 0; i < 5; i++) {
    //        
    //        Monster* slime = slimePrototype->clone();

    //        //hero.Fight(slime, hero);
    //           float damage = hero.GetWeapon()->GetDamage();

    //            hero.SetHealth(hero.GetHealth() - slime->GetDamage());
    //            std::cout << slime->GetName() << " hits you for " << slime->GetDamage()
    //                << " damage. Your HP: " << hero.GetHealth() << std::endl;

    //            slime->SetHealth(slime->GetHealth() - damage);
    //            std::cout << "You attack the " << slime->GetName() << " with your " << hero.GetWeapon()->GetName()
    //                << ", " << damage << " damage. Monster HP: " << slime->GetHealth() << std::endl;


    //            if (slime->GetHealth() < 0) {
    //                std::cout << "You defeated the " << slime->GetName() << std::endl;
    //                hero.GainXP(slime->GetXP());
    //            } else if (hero.GetHealth() <= 0) {
    //            std::cout << "You have been defeated!" << std::endl;
    //            break; }

    //            delete slime;
    //    }
    //} else if (choice == 0) {
    //    std::cout << "You ran away safely" << std::endl;
    //    return 0;
    //}
    //std::cout <<  std::endl;
    //std::cout << std::endl;
    //std::cout << "You pass further and see a beautiful meadow" << std::endl;
    //std::cout << "Little bunnies are playing on it" << std::endl;
    //std::cout << "At one point, the light dims and one of the bunnies is pierced by an arrow. Other animals get scared and run away" << std::endl;
    //std::cout << "A trio of goblins emerges from the bushes opposite" << std::endl;
    //std::cout << std::endl;
    //std::cout << "What will you do?" << std::endl;
    //std::cout << "1. Fight monsters; 2. Run away." << std::endl;
    //std::cout << std::endl;
    //std::cout << std::endl;

    //int newchoice;
    //std::cin >> newchoice;

    //if (newchoice == 1) {

    //    for (int i = 0; i < 3; i++) {

    //        Monster* goblin = goblinPrototype->clone();

    //        //hero.Fight(slime, hero);
    //        float damage = hero.GetWeapon()->GetDamage();

    //        hero.SetHealth(hero.GetHealth() - goblin->GetDamage());
    //        std::cout << goblin->GetName() << " hits you for " << goblin->GetDamage()
    //            << " damage. Your HP: " << hero.GetHealth() << std::endl;

    //        goblin->SetHealth(goblin->GetHealth() - damage);
    //        std::cout << "You attack the " << goblin->GetName() << " with your " << hero.GetWeapon()->GetName()
    //            << ", " << damage << " damage. Monster HP: " << goblin->GetHealth() << std::endl;


    //        if (goblin->GetHealth() < 0) {
    //            std::cout << "You defeated the " << goblin->GetName() << std::endl;
    //            hero.GainXP(goblin->GetXP());
    //        }
    //        else if (hero.GetHealth() <= 0) {
    //            std::cout << "You have been defeated!" << std::endl;
    //            break;
    //        }

    //        delete goblin;
    //    }
    //}
    //else if (newchoice == 0) {
    //    std::cout << "You ran away safely" << std::endl;
    //    return 0;
    //}

    //delete slimePrototype;
    //delete slimeSpawner;
    //delete goblinPrototype;
    //delete goblinSpawner;
}
