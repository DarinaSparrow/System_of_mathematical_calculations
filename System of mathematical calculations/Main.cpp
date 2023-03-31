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
		cout << "�������� ��� ������������:	" << endl;
		cout << "1. �������� �����������" << endl;
		cout << "2. ����������� ������������ ������" << endl;
		cout << "3. ����������� ������ �������������" << endl;
		cout << "4. ����������� �����������" << endl;
		cout << "5. ������ ����������� � �������������� ����������" << endl;
		cout << "6. ������ � ���������" << endl;
		cout << "(��� ������ �� ��������� ������� 0)" << endl << endl;

		do
		{
			cout << "��� �����: ";
			while (!(cin >> type_of_calculator)) 
			{
				cout << "������! ������� ����� �����: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if ((type_of_calculator < 0) || (type_of_calculator > 6)) cout << "������! ��������� ������� ��������." << endl;
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