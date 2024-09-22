#include <iostream>
#include <vector>
#include "ResidentialComplex.h"
#include <memory>

///////////////////////////////////////////// Prototype func
//////////////////// Menu
int Display_Main_Menu(ResidentialComplex& first, ResidentialComplex& second);
void Display_Residential_Complex_Menu();
int Get_selection();

//////////////////// Menu Actions
void HandleResidentialComplex(ResidentialComplex& complex);

int main() {
    ///////////////////////////////////////////// ResidentialComplex
    ResidentialComplex NewEngland("NewEngland");
    ResidentialComplex Smarahdovyi("Smarahdovyi");

    int selection{ 0 };

    while (true) {
        int selection = Display_Main_Menu(NewEngland, Smarahdovyi);
        if (selection == 1) {
            std::cout << "\nYou selected Residential " << NewEngland.GetName() <<std::endl;
            HandleResidentialComplex(NewEngland);
        }
        else if (selection == 2) {
            std::cout << "\nYou selected Residential " << Smarahdovyi.GetName() << std::endl;
            HandleResidentialComplex(Smarahdovyi);
        }
        else if (selection == 3) {
            std::cout << "Exit";
        }
        else {
            std::cout << "Invalid choice, please try again"<< std::endl;
        }
    }

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

void HandleResidentialComplex(ResidentialComplex& complex)
{
    do
    {
        Display_Residential_Complex_Menu();
            int selection = Get_selection();
            if (selection == 1) {
                int Age = 120;
                int cost = 2456;
                complex.AddBuilding();
            }
            else if (selection == 2){
                complex.ListBuildings();
            }
            else if (selection == 3) {
                break;
            }
            else
            {
                std::cout << "Invalid choice, please try again"<<std::endl;
            }
            

    } while (false);
    
}
