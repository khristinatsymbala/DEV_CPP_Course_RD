#include <iostream>
#include <vector>
#include "ResidentialComplex.h"

///////////////////////////////////////////// Prototype func
//////////////////// Menu
int Display_Main_Menu(ResidentialComplex& first, ResidentialComplex& second);
void Display_Residential_Complex_Menu();
int Get_selection();

//////////////////// Menu Actions

int main() {
    ///////////////////////////////////////////// ResidentialComplex
    ResidentialComplex NewEngland("NewEngland");
    ResidentialComplex Smarahdovyi("Smarahdovyi");

    //////////////////////////////////////////// Add members to NewEngland

    //////////////////////////////////////////// Add members to Smarahdovyi

	return 0;
}

int Display_Main_Menu(ResidentialComplex& first, ResidentialComplex& second)
{
    std::cout << "=== Main Menu ===" << std::endl;
    std::cout << "1. Work with Residential Complex: "<< first.GetName() << std::endl;
    std::cout << "2. Work with Residential Complex: "<< second.GetName() << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Select an option: " << std::endl;
    return Get_selection();
}

void Display_Residential_Complex_Menu()
{
    std::cout << "=== Residential Complex Menu ===" << std::endl;
    std::cout << "1. Add Building" << std::endl;
    std::cout << "2. List Buildings" << std::endl;;
    std::cout << "3. Go back to Main Menu" << std::endl;
    std::cout << "Select an option: " << std::endl;
}

int Get_selection()
{
    int selection{};
    std::cout << "Enter your choice : " << selection;

    std::cin >> selection;

    return selection;
}
