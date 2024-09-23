#include <iostream>
#include <vector>
#include "ResidentialComplex.h"
#include <memory>

///////////////////////////////////////////// Prototype func
//////////////////// Menu
int Display_Main_Menu(ResidentialComplex& first, ResidentialComplex& second);
void Display_Residential_Complex_Menu();
int Get_selection();
void WorkingWithBuilding(const std::unique_ptr<Buildings>& building);

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
    std::cout << std::endl;
    std::cout << "1. Work with Residential Complex: "<< first.GetName() << std::endl;
    std::cout << "2. Work with Residential Complex: "<< second.GetName() << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Select an option: " << std::endl;
    return Get_selection();
}

void Display_Residential_Complex_Menu()
{
    std::cout << "=== Residential Complex Menu ===" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Add Building" << std::endl;
    std::cout << "2. List Buildings and work with a specific building" << std::endl;;
    std::cout << "3. Go back to Main Menu" << std::endl;
    std::cout << std::endl;
    std::cout << "Select an option: " << std::endl;
}

int Get_selection()
{
    int selection{};
    std::cout << "Enter your choice : " << selection;

    std::cin >> selection;

    return selection;
}

void WorkingWithBuilding(const std::unique_ptr<Buildings>& building) {

    int choice = 0;

    do {
        std::cout << "=== Building Menu ===" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Age the building" << std::endl;
        std::cout << "2. Get current cost" << std::endl;
        std::cout << "3. Destroy building" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int years;
            std::cout << "Enter the number of years to age the building: ";
            std::cin >> years;
            building->ToAge(years);
            break;
        }
        case 2: {
            std::cout << "Current cost of the building: " << building->GetCost() << std::endl;
            break;
        }
        case 3: {
            building->GetDestroy();
            break;
        }
        case 4: {
            std::cout << "Exiting building menu." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
        }
    } while (choice != 4);
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
                /////////////////////////MOve to another 

                int buildingID;
                std::cout << "Enter the ID of the building to work with: ";
                std::cin >> buildingID;
                const std::unique_ptr<Buildings>& selectedBuilding = complex.GetBuildingByID(buildingID);
                if (selectedBuilding) {
                    WorkingWithBuilding(selectedBuilding);
                }
                else {
                    std::cout << "Building with ID " << buildingID << " not found." << std::endl;
                }

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
