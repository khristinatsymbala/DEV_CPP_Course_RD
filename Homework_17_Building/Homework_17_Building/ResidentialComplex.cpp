#include "ResidentialComplex.h"

ResidentialComplex::ResidentialComplex()
{
}

ResidentialComplex::~ResidentialComplex()
{
	std::cout << "ResidentialComplex with name" << Name << " has been destroyed." << std::endl;
}

void ResidentialComplex::AddBuilding(std::unique_ptr<Buildings> building)
{
	buildings.push_back(building);
}

void ResidentialComplex::ListBuildings()
{
	for (auto& building : buildings) {
		std::cout << "Building ID: " << building->GetID() << std::endl;
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
