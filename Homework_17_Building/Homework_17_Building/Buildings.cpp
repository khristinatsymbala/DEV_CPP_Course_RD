#include"Buildings.h"

Buildings::Buildings()
{

}

Buildings::Buildings(int MaxAge1, int InitialCost1)
{
	MaxAge = MaxAge1;
	Initial_Cost = InitialCost1;
}

// Повертає поточну вартість будівлі. 
// Із кожним роком вартість будівлі зменшується лінійно: 0 років – initial cost, MaxAge років – 0$, MaxAge/2 – InitialCost/2
int Buildings::GetCost()
{
	return currentCost;
}

// Виклик цієї функції повинен зістарити будівлю на year років
// Якщо будівля зістарилась більше, ніж її максимальний вік, то вона повинна викликати приватну функцію Destroy();
void Buildings::ToAge(int years)
{
	if (currentAge + years > MaxAge) {
		Destroy();
	}
	else {
		currentAge += years;
	}
}


// Приватна функція, яка в консоль повідомить будівля із яким id була знищена
void Buildings::Destroy()
{
	
}
