#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "Matrix.h"
#include "Fractions.h"
#include "Combinatorics.h"
#include "Polynomial.h"
#include "Probability_theory.h"
#include "Functions.h"

using namespace std;

#if defined(max)
#undef max
#endif

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int type_of_calculator;

	do
	{
		cout << "Выберите вид калькулятора:	" << endl;
		cout << "1. Матричый калькулятор" << endl;
		cout << "2. Калькулятор обыкновенных дробей" << endl;
		cout << "3. Калькулятор формул комбинаторики" << endl;
		cout << "4. Калькулятор многочленов" << endl;
		cout << "5. Теория вероятности и математическая статистика" << endl;
		cout << "6. Работа с функциями" << endl;
		cout << "(Для выхода из программы введите 0)" << endl << endl;

		do
		{
			cout << "Ваш выбор: ";
			while (!(cin >> type_of_calculator)) 
			{
				cout << "Ошибка! Введите целое число: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if ((type_of_calculator < 0) || (type_of_calculator > 6)) cout << "Ошибка! Проверьте входное значение." << endl;
		} while ((type_of_calculator < 0) || (type_of_calculator > 6));

		system("cls");

		switch (type_of_calculator)
		{
		case 1: Matrix(); break;
		case 2: Fractions(); break;
		case 3: Combinatorics(); break;
		case 4: Polynomial(); break;
		case 5: Probability_theory(); break;
		case 6: Functions();
		}

	} while (type_of_calculator != 0);

	system("pause");

	return 1;
}