#pragma once


#include<iostream>

class Buildings {
public:
	Buildings();
	Buildings(int MaxAge1, int InitialCost1);
	~Buildings() {
		std::cout << "Building " << ID << " is destroyed!" << std::endl;
	}

	int SetID();

	int GetCost();
	void ToAge(int years);

private:
	int ID{ 0 };
	static int sID;

	int MaxAge{ 0 };
	int currentAge{ 0 };

	int Initial_Cost{ 0 }; // початкова вартість будівлі
	int currentCost{ 0 };

	void Destroy();
};