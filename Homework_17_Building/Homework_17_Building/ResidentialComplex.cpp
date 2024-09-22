#include "ResidentialComplex.h"

ResidentialComplex::ResidentialComplex()
{
}

ResidentialComplex::ResidentialComplex(std::string NameComplex)
	:Name(NameComplex)
{
}

ResidentialComplex::~ResidentialComplex()
{
	std::cout << "ResidentialComplex with name" << Name << " has been destroyed." << std::endl;
}

//void ResidentialComplex::AddBuilding(std::unique_ptr<Buildings> building)
//{ buildings.push_back(building);
//}


void ResidentialComplex::AddBuilding()
{
	int maxAge{ 0 };
	int iniCost{ 0 };

	std::cout << "Enter new age to your building: ";
	std::cin >> maxAge;

	std::cout << "Enter new initial cost to your building: ";
	std::cin >> iniCost;

	std::unique_ptr<Buildings> newBuilding = std::make_unique<Buildings>(maxAge, iniCost);
	buildings.push_back(newBuilding);
	
}

void ResidentialComplex::ListBuildings()
{
	if (!buildings.empty())
	{
		std::cout << "Buildings in the complex:"<<std::endl;

		for (auto& building : buildings) {
				std::cout << "Building ID: " << building->GetID() << std::endl;
			}
	}
	else {
		std::cout << "There are no buildings in the complex" << std::endl;
	}
	
}

void ResidentialComplex::RemoveBuilding(int BuildID)
{
	for (auto i = buildings.begin(); i != buildings.end(); i++) {
		if ((*i)->GetID() == BuildID)
		{
			buildings.erase(i);
			std::cout << "Building with ID " << BuildID << " removed." << std::endl;
			return;
		}
	}
	std::cout << "Building with ID " << BuildID << " not found." << std::endl;
}

std::string ResidentialComplex::GetName()
{
	return Name;
}
