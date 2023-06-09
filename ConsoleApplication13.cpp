#include <iostream>
#include <stdlib.h>

using namespace std;

int GetRandomValue(int minimumValue, int maximumValue)
{
	return rand() % maximumValue + minimumValue;
}

void PrintSelectedMultiplicationTable(int multiplicationTableNumber)
{
	for (int counter = 1; counter < 10 + 1; counter++)
	{
		int answer = multiplicationTableNumber * counter;
		 
		cout << multiplicationTableNumber << "*" << counter << "=" << answer << endl;
	}
}

void StartTest(int selectedMultiplicationTableNumber, int& errorsNumber)
{
	for (int i = 1; i < 3 + 1; i++)
	{
		int selectedNumber;
		int randomValue = GetRandomValue(1, 10);

		cout << "Сколько будет " << selectedMultiplicationTableNumber << "*" << randomValue << endl;
		cin >> selectedNumber;
		if (selectedNumber == selectedMultiplicationTableNumber * randomValue)
			cout << "Правильно ответ = " << selectedNumber << "\n";
		else
		{
			cout << "Неверно. Правильный ответ = " << selectedMultiplicationTableNumber * i << "\n";
			++errorsNumber;
		}
	}
}

int GetUserGrade(int& errorsNumber)
{
	if (errorsNumber == 0)
	{
		return 5;
	}
	else if (errorsNumber == 1)
		return 4;
	else if (errorsNumber == 2)
		return 3;
	else if (errorsNumber == 3)
		return 3;
	else if (errorsNumber == 4)
		return 2;
}

int main()
{
	setlocale(0, "Russian");
	srand(time(NULL));

	static int errorsNumber = 0;
	int selectMultiplicatioTable;

	cout << "Введите значение таблицы умножения" << endl;

	cin >> selectMultiplicatioTable;

	PrintSelectedMultiplicationTable(selectMultiplicatioTable);

	StartTest(selectMultiplicatioTable, errorsNumber);

	cout << "Ваша оценка за работу = " << GetUserGrade(errorsNumber) << endl;

	return 0;
}

