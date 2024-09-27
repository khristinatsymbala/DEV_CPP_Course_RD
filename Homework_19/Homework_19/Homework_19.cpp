/*
�������� ������� ���� ��������� Character �� ��������
void SetWeapon(unique_ptr<Weapon> weapon); ���� ����� ���������
Weapon* GetWeapon() const; �� ����� ��������, �� �� ����� � ���������


�������� ������� ���� Weapon �� ����� ������������ ��������
float GetDamage() = 0; ������� �������� ����� ����
string GetName() = 0; ������� ����� ����


�������� ���� � 3 �����-������� ����� ���� ����
�������� �� �������:
���������� ���� ��������� ����� �����, �� �������� ���� ���� � ���� ������� ���������� ����, ��� ����� ���� (��� �����) ���� ���� ������

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


