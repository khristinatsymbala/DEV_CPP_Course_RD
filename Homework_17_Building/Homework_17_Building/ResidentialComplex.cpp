#include "ResidentialComplex.h"

ResidentialComplex::ResidentialComplex()
{
}

ResidentialComplex::~ResidentialComplex()
{
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
