#include"Buildings.h"

int Buildings::sID = 1;

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

int Buildings::GetID()
{
	return ID;
}

// ������� ������� ������� �����. 
// �� ������ ����� ������� ����� ���������� �����: 0 ���� � initial cost, MaxAge ���� � 0$, MaxAge/2 � InitialCost/2
int Buildings::GetCost() {
	if (currentAge >= MaxAge) {
		Destroy();
		return 0;
	}
	else {
		currentCost = (Initial_Cost * (MaxAge - currentAge)) / MaxAge;
	}

	return currentCost;
}

// ������ ���� ������� ������� �������� ������ �� year ����
// ���� ������ ���������� �����, �� �� ������������ ��, �� ���� ������� ��������� �������� ������� Destroy();
void Buildings::ToAge(int years)
{
	currentAge += years;

	if (currentAge > MaxAge) {
		Destroy();
	}
	else {
		GetCost();
	}
}

void Buildings::GetDestroy()
{
	Destroy();
}


// �������� �������, ��� � ������� ��������� ������ �� ���� id ���� �������
void Buildings::Destroy()
{
	std::cout << "Building with ID " << ID << " has been destroyed." << std::endl;
}
