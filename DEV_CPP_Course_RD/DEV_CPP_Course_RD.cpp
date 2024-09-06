// DEV_CPP_Course_RD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

enum EDamageType {
	Water = 1,
	Fire,
	Earth,
	Wind,
	Magic
};

struct ClanInfo {
	public:
		std::string clan_name;
		int clan_number{0};
		float clan_health{ 0 };
		float clan_damage{ 0 };
		EDamageType damageType;
	};
//Prototype func
ClanInfo InputData();
ClanInfo PreCreateClan(std::string& clan_name_new, int class_number_new, float clan_health_new, float clan_damage_new, int damageType_new);
EDamageType damageType_index(int damage_type_index);
int main() {

	


	return 0;
}

ClanInfo InputData() {
	ClanInfo Clan;

	std::cout << "Enter Clan Name: ";
	std::cin >> Clan.clan_name;

	std::cout << "Enter Clan Numder: ";
	std::cin >> Clan.clan_number;

	std::cout << "Enter Clan Health: ";
	std::cin >> Clan.clan_health;

	std::cout << "Enter Clan Damage: ";
	std::cin >> Clan.clan_damage;

	int damage_type_index = 0;
	std::cout << " Select Damage Type (1: Water, 2: Fire, 3: Earth, 4: Wind, 5: Magic): ";
	std::cin >> damage_type_index;

	EDamageType damageType = (EDamageType)damage_type_index;

	return Clan;
}

ClanInfo PreCreateClan(std::string& clan_name_new, int class_number_new, float clan_health_new, float clan_damage_new,int damageType_new)
{
	ClanInfo Clan;
	Clan.clan_name = clan_name_new;
	Clan.clan_number = class_number_new;
	Clan.clan_health = clan_health_new;
	Clan.clan_damage = clan_damage_new;
	Clan.damageType = damageType_index(damageType_new);
	return Clan;
}

EDamageType damageType_index(int damage_type_index)
{
	
	EDamageType damageType = (EDamageType)damage_type_index;
	return (EDamageType)damage_type_index;
}






























///////////////////////Homework 1////////////////////////////////////////
//int main()
//{
//    float health{ 0 };
//
//    do {
//        std::cout << "Enter the hero`s health: " << std::endl;
//        std::cin >> health;
//
//        if (health < 0) {
//            std::cout << "Please enter a non-negative health." << std::endl;
//        }
//
//    }while(health < 0);
//
//
//    while (health > 0) {
//
//        float item_distance, item_impact;
//
//        do
//        {
//            std::cout << "Enter the distance to item : " << std::endl;
//            std::cin >> item_distance;
//
//            if (item_distance < 0)
//            {
//                std::cout << "Please enter a non-negative health." << std::endl;
//            }
//
//        } while (item_distance < 0);
//
//        std::cout << "Enter item impact (damage/healing): " << std::endl;
//        std::cin >> item_impact;
//
//        if (item_distance <= 100)
//        {
//            float result_impact{ 0 };
//
//            result_impact = item_impact * (1 - item_distance / 100);
//            health += result_impact;
//
//            if (health < 1 && health > 0) {
//                health = 1;
//            }
//
//        } else {
//            std::cout << "No impact " << std::endl;
//        }
//
//        std::cout << "The hero has died." << std::endl;
//        return 0;
//    }
//
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
