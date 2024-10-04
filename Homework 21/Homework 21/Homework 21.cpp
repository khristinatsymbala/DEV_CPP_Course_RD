// Homework 21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Actor.h"
#include "Weapon.h"
#include "Enemy.h"


int main()
{
    std::cout << "---------Welcome to the Adventure!---------" << std::endl;
    std::cout << "You are entering a dark forest filled with dangers." << std::endl;
    std::cout << "You meet another person and you decide to team up." << std::endl;

    Character hero("Valera", 0, 100.0f);
    Character hero2("Igor", 0, 100.0f);


    hero.SetWeapon(std::make_unique<Sword>());
    hero.SetWeapon(std::make_unique<Halberd>());

    hero2.SetWeapon(std::make_unique<Two_Hands_Sword>());
    hero2.SetWeapon(std::make_unique<Bludgeon>());

    std::cout << "Available weapons:" << std::endl;
    hero.ListWeapons();
    hero2.ListWeapons();

    Weapon* equippedWeapon = hero.GetWeapon();
    Weapon* equippedWeaponHero2 = hero2.GetWeapon();

    if (equippedWeapon) {
        std::cout << "Currently equipped weapon: " << equippedWeapon->GetName() << " with damage: " << equippedWeapon->GetDamage() << std::endl;
    }
    else {
        std::cout << "No weapon equipped." << std::endl;
    }

    hero.Notify();

    std::cout << "5 Slime appear on your way" << std::endl;
    std::cout << "What will you do?" << std::endl;
    std::cout << "1. Fight monsters; 2. Run away." << std::endl;

    int choice;
    std::cin >> choice;

    Slime slime;
    //Goblin goblin;

    hero.Subscribe(&slime);
    hero2.Subscribe(&slime);
    //hero.Subscribe(&goblin);

    std::unique_ptr<Enemy> slimePrototype = std::make_unique<Slime>(slime);
    std::unique_ptr <Spawner> slimeSpawner = std::make_unique<Spawner>(std::move(slimePrototype));


    if (choice == 1) {
       
        std::vector< std::unique_ptr<Enemy>> slimes;
        
            for (int i = 0; i < 5; i++) {
                std::unique_ptr<Enemy> slime_ = slimeSpawner->spawnMonster();
                slimes.push_back(std::move(slime_));

            Character* target = slimes[i]->ChooseTarget(&hero, &hero2);

            while (slimes[i]->GetHealth() > 0 && target->GetHealth() > 0) {
              target->Fight(slimes[i].get());
            
              target = slimes[i]->ChooseTarget(&hero, &hero2);
            }
            }

    } else if (choice == 0) {
            std::cout << "You ran away safely" << std::endl;
            return 0;
        }
        /*std::cout <<  std::endl;
        std::cout << std::endl;
        std::cout << "You pass further and see a beautiful meadow" << std::endl;
        std::cout << "Little bunnies are playing on it" << std::endl;
        std::cout << "At one point, the light dims and one of the bunnies is pierced by an arrow. Other animals get scared and run away" << std::endl;
        std::cout << "A trio of goblins emerges from the bushes opposite" << std::endl;
        std::cout << std::endl;
        std::cout << "What will you do?" << std::endl;
        std::cout << "1. Fight monsters; 2. Run away." << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        int newchoice;
        std::cin >> newchoice;

        std::unique_ptr<Enemy> goblinPrototype = std::make_unique<Goblin>(goblin);
        std::unique_ptr <Spawner> goblinSpawner = std::make_unique<Spawner>(std::move(goblinPrototype));

        if (newchoice == 1) {
            for (int i = 0; i < 3; i++) {
                
                    std::unique_ptr<Enemy> goblin_ = goblinSpawner->spawnMonster();

                    Character* target = (rand() % 2 == 0) ? &hero : &hero2;

                    if (hero.GetHealth() <= 50) { target = &hero; }
                    else if (hero2.GetHealth() <= 50) { target = &hero2; }

                    target->Fight(goblin_.get());
                
            }
        }*/
} 

/*
Загальна ідея перенести там ту домашку сюди та використати патерн саме на реагування по здоров'ю
умовно є пару енемі і пару карактерів і вона рандомно атакують один одного
але в момент коли в когось з персів падає здоров'я менше умовних 75%
то енемі починають їбашити всі його до смерті

також варта дописати хілерску тєму щоб все таки не прописували так 

Плюс переробити як він сказав спавнер та клас - додати копіювальний конструктор
*/

