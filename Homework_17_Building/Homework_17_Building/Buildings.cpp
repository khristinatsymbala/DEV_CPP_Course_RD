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

// Повертає поточну вартість будівлі. 
// Із кожним роком вартість будівлі зменшується лінійно: 0 років – initial cost, MaxAge років – 0$, MaxAge/2 – InitialCost/2
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

// Виклик цієї функції повинен зістарити будівлю на year років
// Якщо будівля зістарилась більше, ніж її максимальний вік, то вона повинна викликати приватну функцію Destroy();
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


// Приватна функція, яка в консоль повідомить будівля із яким id була знищена
void Buildings::Destroy()
{
	std::cout << "Building with ID " << ID << " has been destroyed." << std::endl;
}
