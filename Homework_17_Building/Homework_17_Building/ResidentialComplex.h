#pragma once
#include <vector>
#include <memory>
#include "Buildings.h"

class ResidentialComplex
{
public:
	ResidentialComplex();
	ResidentialComplex(std::string NameComplex);
	~ResidentialComplex();

	void AddBuilding();
	void ListBuildings();
	void RemoveBuilding(int BuildID);

	std::string GetName();

	std::unique_ptr<Buildings> GetBuildingByID(int buildingID);

private:
	std::vector < std::unique_ptr<Buildings>> buildings;
	std::string Name;

};

