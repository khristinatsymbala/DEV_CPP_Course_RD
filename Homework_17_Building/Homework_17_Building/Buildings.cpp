#include"Buildings.h"

int Buildings::sID = 0;

Buildings::Buildings()
{
	ID = SetID();
	MaxAge = 50;
	Initial_Cost = 1000;
	currentCost = Initial_Cost;
}

Buildings::Buildings(int MaxAge1, int InitialCost1)
{
	ID = SetID();
	MaxAge = MaxAge1;
	Initial_Cost = InitialCost1;
	currentCost = InitialCost1;
}

int Buildings::SetID()
{
	return sID++;
}

// ������� ������� ������� �����. 
// �� ������ ����� ������� ����� ���������� �����: 0 ���� � initial cost, MaxAge ���� � 0$, MaxAge/2 � InitialCost/2
int Buildings::GetCost()
{
	if (currentAge > MaxAge) {
		std::cout << "The building is out of service" << std::endl;
		return 0;
	}

	currentCost = Initial_Cost - Initial_Cost * ((MaxAge / 2) - (Initial_Cost / 2)); // RE DO
	return currentCost;
}

// ������ ���� ������� ������� �������� ������ �� year ����
// ���� ������ ���������� �����, �� �� ������������ ��, �� ���� ������� ��������� �������� ������� Destroy();
void Buildings::ToAge(int years)
{
	if (currentAge + years > MaxAge) {
		Destroy();
	}
	else {
		currentAge += years;
		GetCost();
	}
}


// �������� �������, ��� � ������� ��������� ������ �� ���� id ���� �������
void Buildings::Destroy()
{
	std::cout << "Building with ID " << ID << " has been destroyed." << std::endl;
}
