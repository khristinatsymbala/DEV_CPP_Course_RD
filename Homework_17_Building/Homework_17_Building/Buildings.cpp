#include"Buildings.h"

Buildings::Buildings()
{

}

Buildings::Buildings(int MaxAge1, int InitialCost1)
{
	MaxAge = MaxAge1;
	Initial_Cost = InitialCost1;
}

// ������� ������� ������� �����. 
// �� ������ ����� ������� ����� ���������� �����: 0 ���� � initial cost, MaxAge ���� � 0$, MaxAge/2 � InitialCost/2
int Buildings::GetCost()
{
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
	}
}


// �������� �������, ��� � ������� ��������� ������ �� ���� id ���� �������
void Buildings::Destroy()
{
	
}
