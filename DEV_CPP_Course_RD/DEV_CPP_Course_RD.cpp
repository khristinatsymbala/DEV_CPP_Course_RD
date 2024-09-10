// DEV_CPP_Course_RD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>


/*
На завтра:
	доробити ремув з клану  - зробити універсальне для використання ще у блоці файтингу
	мені потрібен індекс та клан 
	чекінг чи його здоров'я не впало нижче 0 

	подумати над резістами - якось вони мали б працювати 
	подумати над варіантом кріт удару

	Заготовка:
	std::cout << std::endl;
	std::cout <<"  "<< std::endl;

*/

enum EDamageType {
	Water = 1,
	Fire,
	Earth,
	Wind,
	Magic
};

struct Clan_Member_Info {
	public:
		std::string clan_member_name;
		int clan_number{0};
		float clan_member_health{ 0 };
		float clan_member_damage{ 0 };
		EDamageType damageType;
	};


///////////////////////////////////////////// Prototype func
//////////////////// Members
Clan_Member_Info InputData();
Clan_Member_Info Precreate_Clan_Member(std::string clan_member_name_new, int class_number_new, float clan_health_new, float clan_damage_new, int damageType_new);
EDamageType damageType_index(int damage_type_index);
void AddMemberToClan(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights, Clan_Member_Info& new_member);

//////////////////// Menu
void Display_Menu();
int Get_selection();


//////////////////// Actions
void Add_New_Player_To_Clan(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights);
void Remove_Player_From_Clan(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights);
void All_Players_Stats(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights);
void Fight(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights);
void Remove_Player(int clan_number,int player_index, std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights);

//////////////////// Additional func
void Display_All_Members(std::vector<Clan_Member_Info>& clan);
float Total_Damage_Of_Clan(std::vector<Clan_Member_Info>& clan);
float ProcessDamage(float current_health, float damage_received, EDamageType damage_type);
float Modify_Damage(float damage_received, EDamageType damage_type);
float Total_Health_Of_Clan(std::vector<Clan_Member_Info>& clan);


int main() {

	///////////////////////////////////////////// Clans
	std::vector<Clan_Member_Info> clan_Warriors;
	std::vector<Clan_Member_Info> clan_Knights;
	
	//////////////////////////////////////////// Add members to Warriors
	Clan_Member_Info Steve = Precreate_Clan_Member("Steve", 0, 120, 12, 4);
	AddMemberToClan(clan_Warriors, clan_Knights, Steve);
	Clan_Member_Info Kitnis = Precreate_Clan_Member("Kitnis", 0, 100, 20, 2);
	AddMemberToClan(clan_Warriors, clan_Knights, Kitnis);
	Clan_Member_Info Ronin_01 = Precreate_Clan_Member("Ronin_01", 0, 150, 35, 1);
	AddMemberToClan(clan_Warriors, clan_Knights, Ronin_01);

	//////////////////////////////////////////// Add members to Knights
	Clan_Member_Info Stela = Precreate_Clan_Member("Stela", 1, 120, 34, 2);
	AddMemberToClan(clan_Warriors, clan_Knights, Stela);
	Clan_Member_Info Stepan = Precreate_Clan_Member("Stepan", 1, 160, 23, 3);
	AddMemberToClan(clan_Warriors, clan_Knights, Stepan);
	Clan_Member_Info Filli = Precreate_Clan_Member("Filli", 1, 180, 12, 5);
	AddMemberToClan(clan_Warriors, clan_Knights, Filli);

	///////////////////////////////////////////// Main logic
	int selection{0};

	do
	{
		Display_Menu();
		selection = Get_selection();
		switch (selection)
		{
		case 0: 
			// add new a player to the battle

			Add_New_Player_To_Clan(clan_Warriors, clan_Knights);
			break;
		case 1:
			// remove a player from combat
			Remove_Player_From_Clan(clan_Warriors, clan_Knights);
			break;
		case 2:
			// fight

			Fight(clan_Warriors, clan_Knights);
			break;
		case 3:
			// see all players

			All_Players_Stats(clan_Warriors, clan_Knights);
			break;
		case 4:
			// exit
			std::cout << "Thank u for a Game!! " << std::endl;
			break;
	
		default:
			break;
		}

	} while (selection != 4);

	return 0;
}

Clan_Member_Info InputData() {
	Clan_Member_Info Clan;

	std::cout << "Enter Your Name: ";
	std::cin >> Clan.clan_member_name;

	std::cout << "Select Clan : (0 - Warriors, 1 - Knights)";
	std::cin >> Clan.clan_number;


	std::cout << "Enter Your Health: ";
	std::cin >> Clan.clan_member_health;

	std::cout << "Enter Your Damage: ";
	std::cin >> Clan.clan_member_damage;

	int damage_type_index = 0;
	std::cout << " Select Damage Type (1: Water, 2: Fire, 3: Earth, 4: Wind, 5: Magic): ";
	std::cin >> damage_type_index;

	EDamageType damageType = (EDamageType)damage_type_index;
	Clan.damageType = damageType_index(damage_type_index);

	return Clan;
}

Clan_Member_Info Precreate_Clan_Member(std::string clan_member_name_new, int class_number_new, float clan_health_new, float clan_damage_new,int damageType_new)
{
	Clan_Member_Info Clan;
	Clan.clan_member_name = clan_member_name_new;
	Clan.clan_number = class_number_new;
	Clan.clan_member_health = clan_health_new;
	Clan.clan_member_damage = clan_damage_new;
	Clan.damageType = damageType_index(damageType_new);

	return Clan;
}

EDamageType damageType_index(int damage_type_index)
{
	EDamageType damageType = (EDamageType)damage_type_index;
	return (EDamageType)damage_type_index;
}

void AddMemberToClan(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights, Clan_Member_Info& new_member)
{
	if (new_member.clan_number == 0)
	{
		clan_Warriors.push_back(new_member);
		std::cout << new_member.clan_member_name << " Added to Warriors clan " << std::endl;
	}
	else if (new_member.clan_number == 1)
	{
		clan_Knights.push_back(new_member);
		std::cout << new_member.clan_member_name << " Added to Knights clan " << std::endl;
	}
	else {
		std::cout << "No clan with this ID" << std::endl;
	}
}

void Display_Menu()
{ 
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << " --------- Welcome to Clan Battles-------- " << std::endl;
	std::cout << std::endl;
	std::cout << " 0  - add a player to the battle" << std::endl;
	std::cout << " 1  - remove a player from combat" << std::endl;
	std::cout << " 2  - fight" << std::endl;
	std::cout << " 3  - see all players" << std::endl;
	std::cout << " 4  - exit" << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl; 
	std::cout << std::endl;
}

int Get_selection()
{
	int selection{};
	std::cout << "Enter your choice : " << selection;

	std::cin >> selection;

	return selection;
}

void Add_New_Player_To_Clan(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights)
{

	std::cout << "Hello new player. Please enter your details below " << std::endl;

	Clan_Member_Info new_member = InputData();
	AddMemberToClan(clan_Warriors, clan_Knights, new_member);
}

void Remove_Player_From_Clan(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights)
{
	int player_index{ 0 };
	int clan_number{ 0 };

	std::cout << " PPlease enter the clan index of the player you want to remove? ";
	std::cin >> clan_number;

	std::cout << " Please enter the player index you want to remove? ";
	std::cin >> player_index;

	Remove_Player(clan_number, player_index, clan_Warriors, clan_Knights);
}

void Display_All_Members(std::vector<Clan_Member_Info>& clan)
{
	int index = 0;
	for (auto& member : clan)
	{
		std::cout << std::endl;
		std::cout << "Number: " << index << std::endl;
		std::cout << "Name: " << member.clan_member_name << std::endl;
		std::cout << "Health: " << member.clan_member_health << std::endl;
		std::cout << "Damage: " << member.clan_member_damage << std::endl;
		std::cout << "Damage Type: " << member.damageType << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << std::endl;
		index++;
	}
}

float Total_Damage_Of_Clan(std::vector<Clan_Member_Info>& clan)
{
	float total_damage{ 0 };
	for (size_t i = 0; i < clan.size(); i++)
	{
		total_damage += clan[i].clan_member_damage;
	}
	return total_damage;
}

float ProcessDamage(float current_health, float damage_received, EDamageType damage_type)
{
	return current_health - Modify_Damage(damage_received, damage_type);
}

float Modify_Damage(float damage_received, EDamageType damage_type)
{

	switch (damage_type)
	{
	case EDamageType::Water:
		return damage_received * 2;
		break;
	case EDamageType::Fire:
		return damage_received * 3;
		break;
	case EDamageType::Earth:
		return damage_received;
		break;
	case EDamageType::Wind:
		return damage_received / 2;
		break;
	case EDamageType::Magic:
		return damage_received * 3;
		break;
	default:
		return damage_received;
		break;

	}
}

float Total_Health_Of_Clan(std::vector<Clan_Member_Info>& clan)
{
	float total_health{0};
	for (size_t i = 0; i < clan.size(); i++)
	{
		total_health += clan[i].clan_member_damage;
	}
	return total_health;
}

void All_Players_Stats(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights)
{
	std::cout << " --- Members of Knights Clan --- " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;

	Display_All_Members(clan_Knights);

	std::cout << " Amount of Knights damages: " << Total_Damage_Of_Clan(clan_Knights) << std::endl;
	std::cout << std::endl;

	std::cout << " --- Members of Warriors Clan --- " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;

	Display_All_Members(clan_Warriors);

	std::cout << " Amount of Warriors damages: " << Total_Damage_Of_Clan(clan_Warriors) << std::endl;
	std::cout << std::endl;
}

void Fight(std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights)
{
	float total_health_Knights = Total_Health_Of_Clan(clan_Knights);
	float total_health_Warriors = Total_Health_Of_Clan(clan_Warriors);

	for (size_t i = 0; i < clan_Knights.size(); i++)
	{
		for (size_t a = 0; a < clan_Warriors.size(); a++)
		{
			std::cout << " The fight is now!!! " << std::endl;
			std::cout << clan_Knights[i].clan_member_name << " VS " << clan_Warriors[a].clan_member_name << std::endl;
			std::cout <<  std::endl;

			clan_Knights[i].clan_member_health = ProcessDamage(clan_Knights[i].clan_member_health, clan_Warriors[a].clan_member_damage, clan_Warriors[a].damageType);
			clan_Warriors[a].clan_member_health = ProcessDamage(clan_Warriors[a].clan_member_health, clan_Knights[i].clan_member_damage, clan_Knights[i].damageType);

			
			if (clan_Knights[i].clan_member_health <= 0) {
				Remove_Player(clan_Knights[i].clan_number, i, clan_Warriors, clan_Knights);
				i--;
				break;
			}
			else if (clan_Warriors[a].clan_member_health <= 0) {
				Remove_Player(clan_Warriors[a].clan_number, a, clan_Warriors, clan_Knights);
				a--;
				break;
			}
			
			
			total_health_Knights = Total_Health_Of_Clan(clan_Knights);
			total_health_Warriors = Total_Health_Of_Clan(clan_Warriors);

			std::cout << " The player health: " << clan_Knights[i].clan_member_health << "  Clan total health: " << total_health_Knights << std::endl;
			std::cout << " The player health: " << clan_Warriors[a].clan_member_health << "  Clan total health: " << total_health_Warriors << std::endl;
		}
		
	}

	if (total_health_Knights > 0 && total_health_Warriors <= 0)
	{
		std::cout << "Congratulation to Knights" << std::endl;
	}
	else if (total_health_Warriors > 0 && total_health_Knights <= 0) {
		std::cout << "Congratulation to Warriors" << std::endl;
	}
	else if (total_health_Warriors <= 0 && total_health_Knights <= 0) {
		std::cout << "No one to Win" << std::endl;
	}
}

void Remove_Player(int clan_number, int player_index, std::vector<Clan_Member_Info>& clan_Warriors, std::vector<Clan_Member_Info>& clan_Knights)
{
	if (clan_number == 0) 
	{
		if (player_index >= 0 && player_index < clan_Warriors.size()) {
			std::cout << "Removing " << clan_Warriors[player_index].clan_member_name << " from Warriors." << std::endl;
			clan_Warriors.erase(clan_Warriors.begin() + player_index);
		}
		else {
			std::cout << "Invalid player index." << std::endl;
		}
	}
	else if (clan_number == 1) {
		if (player_index >= 0 && player_index < clan_Knights.size()) {
			std::cout << "Removing " << clan_Knights[player_index].clan_member_name << " from Warriors." << std::endl;
			clan_Knights.erase(clan_Knights.begin() + player_index);
		}
		else {
			std::cout << "Invalid player index." << std::endl;
		}
	}
	else {
		std::cout << "Invalid clan index." << std::endl;
	}
	
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
