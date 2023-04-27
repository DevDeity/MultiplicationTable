#include <iostream>
#include <stdlib.h>


using namespace std;

int errorsNumber = 0;

int GetRandValue(int minValue, int maxValue)
{
	return rand() % maxValue + minValue;
}

void PrintSelectedTable(int selectedTableNumber)
{
	for (int counter = 1; counter < 10 + 1; counter++)
	{
		int answer = selectedTableNumber * counter;
		printf("%d * %d = %d\n", selectedTableNumber, counter, answer);
	}
}

void AskUser(int selectNumber)
{
	int answerUser;
	int randomValue;
	for (int i = 1; i < 3 + 1; i++)
	{
		randomValue = GetRandValue(1, 10);
		printf("Сколько будет %d * %d\n", selectNumber, randomValue);
		cin >> answerUser;
		if (answerUser == selectNumber * randomValue)
			cout << "Правильно ответ = " << answerUser << "\n";
		else
		{
			cout << "Неверно. Правильный ответ = " << selectNumber * i << "\n";
			++errorsNumber;
		}
	}
}

int GetUserGrade(int errorsNumber)
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

void main()
{
	setlocale(0, "Russian");
	srand(time(NULL));

	int randValue = GetRandValue(1, 10);

	PrintSelectedTable(randValue);

	AskUser(randValue);

	printf("Ваша оценка за работу = %d\n", GetUserGrade(errorsNumber));

	return;
}

