#pragma once
#include <vector>
#include <memory>
#include "Buildings.h"

class ResidentialComplex
{
public:
	ResidentialComplex();
	~ResidentialComplex();

	void AddBuilding(std::unique_ptr<Buildings> building);
	void ListBuildings();
private:
	std::vector < std::unique_ptr<Buildings>> buildings;
	std::string Name;

};

