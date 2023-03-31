#include "Polynomial.h"

// �������� ����� ������ ���� int
void intInputValidation(int &data)
{
	bool input;

	do
	{
		input = true;
		cin >> data;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����������, ������� ����� �����: ";
			input = false;
		}
	} while (!input);
}

// �������� ����� ������ ���� double
void doubleInputValidation(double &data)
{
	bool input;

	do
	{
		input = true;
		cin >> data;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����������, ������� �����: ";
			input = false;
		}
	} while (!input);
}

// ����
void Polynomial()
{
	int menu;
	Data Polynom;

	do
	{
		cout << "�������� ��������:	" << endl;
		cout << "1. �������� ���� �����������" << endl;
		cout << "2. ��������� �� ������� ���������� �������" << endl;
		cout << "3. ��������� ���� �����������" << endl;
		cout << "4. ������� ������� ���������� �� ������" << endl;
		cout << "5. ��������� ���������� �� �������� �����" << endl;
		cout << "6. ���������� ����������� ����������" << endl;
		cout << "(��� �������� �� ������� ���� ������� 0)" << endl << endl;

		do
		{
			cout << "��� �����: ";
			intInputValidation(menu);
			if (menu < 0 || menu > 6) cout << "������� ������������ ������. ��������� ����.\n\n";
		} while (menu < 0 || menu > 6);

		system("cls");

		switch (menu)
		{
		case 1: Addition(Polynom); break;
		case 2: Subtraction(Polynom); break;
		case 3: Multiplication(Polynom); break;
		case 4: Division(Polynom); break;
		case 5: NumberMultiplication(Polynom); break;
		case 6: Derivate(Polynom);
		}

		if (menu != 0)
		{
			cout << endl << endl;
			system("pause");
			system("cls");
		}
	} while (menu != 0); 
}

// ���� ����������
void PolynomInput(Data &Polynom, const int &PolynomNum)
{
	cout << "����������� ��������� ��������� ����:\n\nax^n+bx^(n-1)+cx^(n-2)...nx^1+m\n\nn,n-1,...2,1 - ������� ����������;\nx - ����������;\na,b,c,...,n,m - ������������\n\n";

  #pragma region DegreesInput

	do
	{
		if (PolynomNum == 2) cout << "������� ������������ ������� ������� ����������: ";
		else cout << "������� ������������ ������� ����������: ";
		intInputValidation(Polynom.FPMaxDegree);
		if (Polynom.FPMaxDegree < 0) cout << "������� ������������ ������. ��������� ����.\n\n";
	} while (Polynom.FPMaxDegree < 0);

	if (PolynomNum == 2)
	{
		do
		{
			cout << "������� ������������ ������� ������� ����������: ";
			intInputValidation(Polynom.SPMaxDegree);
			if (Polynom.SPMaxDegree < 0) cout << "������� ������������ ������. ��������� ����.\n\n";
		} while (Polynom.SPMaxDegree < 0);
	}

  #pragma endregion

  #pragma region MaxDegree

	int MaxDegree = 0;

	if (PolynomNum == 2)
	{
		if (Polynom.SPMaxDegree >= Polynom.FPMaxDegree) MaxDegree = Polynom.SPMaxDegree;
		else MaxDegree = Polynom.FPMaxDegree;
	}
	else MaxDegree = Polynom.FPMaxDegree;

  #pragma endregion

  #pragma region FPInput

	int j = Polynom.FPMaxDegree;

	Polynom.FirstPolynom = new double[MaxDegree + 1];

	if (PolynomNum == 2) cout << "\n���� ������� ����������.\n\n";
	else cout << "\n���� ����������.\n\n";

	for (int i = 0; i < MaxDegree - Polynom.FPMaxDegree; i++)
	{
		Polynom.FirstPolynom[i] = 0;
	}

	for (int i = MaxDegree - Polynom.FPMaxDegree; i <= MaxDegree; i++)
	{
		if (i == MaxDegree)
		{
			cout << "������� ��������� �����������: ";
			doubleInputValidation(Polynom.FirstPolynom[i]);
		}

		else
		{
			if (j != 1)
			{
				cout << "������� ����������� ��� ���������� x^" << j << ": ";
				doubleInputValidation(Polynom.FirstPolynom[i]);
			}
			else
			{
				cout << "������� ����������� ��� ���������� x: ";
				doubleInputValidation(Polynom.FirstPolynom[i]);
			}
		}

		j--;
	}

  #pragma endregion

  #pragma region SPInput

	if (PolynomNum == 2)
	{
		j = Polynom.SPMaxDegree;

		Polynom.SecondPolynom = new double[MaxDegree + 1];

		cout << "\n���� ������� ����������.\n\n";

		for (int i = 0; i < MaxDegree - Polynom.SPMaxDegree; i++)
		{
			Polynom.SecondPolynom[i] = 0;
		}

		for (int i = MaxDegree - Polynom.SPMaxDegree; i <= MaxDegree; i++)
		{
			if (i == MaxDegree)
			{
				cout << "������� ��������� �����������: ";
				doubleInputValidation(Polynom.SecondPolynom[i]);
			}

			else
			{
				if (j != 1)
				{
					cout << "������� ����������� ��� ���������� x^" << j << ": ";
					doubleInputValidation(Polynom.SecondPolynom[i]);
				}

				else
				{
					cout << "������� ����������� ��� ���������� x: ";
					doubleInputValidation(Polynom.SecondPolynom[i]);
				}
			}

			j--;
		}
	}
  #pragma endregion

	Polynom.EPMaxDegree = MaxDegree;

  #pragma region FPandSPOutput

	if (PolynomNum == 2) cout << "\n������ ��������� ���������: ";
	else cout << "\n��������� ���������: ";
	PolynomOutput(Polynom.FirstPolynom, Polynom.EPMaxDegree);

	if (PolynomNum == 2)
	{
		cout << "\n������ ��������� ���������: ";
		PolynomOutput(Polynom.SecondPolynom, Polynom.EPMaxDegree);
	}

  #pragma endregion
}

// ����� ����������
void PolynomOutput(const double *EndPolynom, const int &EPMaxDegree)
{
	int j = EPMaxDegree;
	int NullResult = 0, FirstCoefficient = 0;

	for (int i = 0; i <= EPMaxDegree; i++)
	{
		if (EndPolynom[i] != 0) FirstCoefficient += 1;

		if (EndPolynom[i] != 0)
		{
			if (EndPolynom[i] > 0 && i != 0)
			{
				if (FirstCoefficient > 1) cout << "+";
			}
			if (EndPolynom[i] != 1 || i == EPMaxDegree)
			{
				if (EndPolynom[i] == -1 && j != 0) cout << "-";
				else cout << EndPolynom[i];
			}
			if (j != 0)
			{
				if (j == 1) cout << "x";
				else cout << "x^" << j;
			}
		}

		else NullResult += 1;

		j--;
	}

	if (NullResult == EPMaxDegree + 1) cout << "0";
}

// C������� �����������
void Addition(Data &Polynom)
{
	int PolynomNum = 2;

	PolynomInput(Polynom, PolynomNum);

	Polynom.EndPolynom = new double[Polynom.EPMaxDegree + PolynomNum];

	for (int i = 0; i <= Polynom.EPMaxDegree; i++)
	{
		Polynom.EndPolynom[i] = Polynom.FirstPolynom[i] + Polynom.SecondPolynom[i];
	}

	cout << "\n\n��������� �������� ���� �����������:";
	PolynomOutput(Polynom.EndPolynom, Polynom.EPMaxDegree);

	MemoryClean(Polynom, PolynomNum);
}

// ��������� �����������
void Subtraction(Data &Polynom)
{
	int PolynomNum = 2;

	PolynomInput(Polynom, PolynomNum);

	Polynom.EndPolynom = new double[Polynom.EPMaxDegree + PolynomNum];

	for (int i = 0; i <= Polynom.EPMaxDegree; i++)
	{
		Polynom.EndPolynom[i] = Polynom.FirstPolynom[i] - Polynom.SecondPolynom[i];
	}

	cout << "\n\n��������� ��������� ���� �����������: ";
	PolynomOutput(Polynom.EndPolynom, Polynom.EPMaxDegree);

	MemoryClean(Polynom, PolynomNum);
}

// ��������� �����������
void Multiplication(Data &Polynom)
{
	int PolynomNum = 2;

	PolynomInput(Polynom, PolynomNum);

	Polynom.EPMaxDegree *= PolynomNum;

	Polynom.EndPolynom = new double[Polynom.EPMaxDegree + PolynomNum];

	for (int i = 0; i <= Polynom.EPMaxDegree; i++)
	{
		Polynom.EndPolynom[i] = 0;
	}

	for (int i = 0; i <= Polynom.EPMaxDegree / 2; i++)
	{
		for (int j = 0; j <= Polynom.EPMaxDegree / 2; j++)
		{
			Polynom.EndPolynom[i + j] += Polynom.FirstPolynom[i] * Polynom.SecondPolynom[j];
		}
	}

	cout << "\n\n��������� ��������� ���� �����������: ";
	PolynomOutput(Polynom.EndPolynom, Polynom.EPMaxDegree);

	MemoryClean(Polynom, PolynomNum);
}

// ������� �����������
void Division(Data &Polynom)
{
	int PolynomNum = 2;
	bool check = TRUE;

	do
	{
		system("cls");

		int DivisorCheck = 0, DividendCheck = 0;

		PolynomInput(Polynom, PolynomNum);

		for (int i = 0; i <= Polynom.FPMaxDegree; i++)
		{
			if (Polynom.SecondPolynom[i] == 0) DivisorCheck += 1;
		}

		if (DivisorCheck == Polynom.FPMaxDegree + 1)
		{
			cout << "\n\n�������� �� ������ ��������� 0. ��������� ����.\n\n";
			check = FALSE;
			system("pause");
		}

		if (Polynom.FPMaxDegree < Polynom.SPMaxDegree)
		{
			cout << "\n\n���������� ��������� ������ ��������� �� ������. ������� ������ ���� ������ ��������. ��������� ����.\n\n";
			check = FALSE;
			system("pause");
		}

	} while (!check);

	Polynom.EPMaxDegree = Polynom.EPMaxDegree - Polynom.SPMaxDegree;

	Polynom.EndPolynom = new double[Polynom.EPMaxDegree + 1];

	for (int i = 0; i <= Polynom.EPMaxDegree; i++)
	{
		double c = Polynom.FirstPolynom[i] / Polynom.SecondPolynom[Polynom.EPMaxDegree];
		Polynom.EndPolynom[i] = c;

		for (int j = Polynom.FPMaxDegree - Polynom.SPMaxDegree; j <= Polynom.FPMaxDegree; j++)
		{
			Polynom.FirstPolynom[i - Polynom.EPMaxDegree + j] -= c * Polynom.SecondPolynom[j];
		}
	}

	cout << "\n\n��������� ������� ���� �����������: ";
	if (Polynom.FirstPolynom[Polynom.FPMaxDegree] != 0) cout << "(";
	PolynomOutput(Polynom.EndPolynom, Polynom.EPMaxDegree);
	if (Polynom.FirstPolynom[Polynom.FPMaxDegree] != 0) cout << ")";
	if (Polynom.FirstPolynom[Polynom.FPMaxDegree] != 0)
	{
		cout << "+(";
		PolynomOutput(Polynom.FirstPolynom, Polynom.FPMaxDegree);
		cout << ")";
		cout << "/(";
		PolynomOutput(Polynom.SecondPolynom, Polynom.FPMaxDegree);
		cout << ")";

		MemoryClean(Polynom, PolynomNum);
	}
}

// ��������� ���������� �� �����
void NumberMultiplication(Data &Polynom)
{
	int PolynomNum = 1;
	PolynomInput(Polynom, PolynomNum);

	double Number;

	cout << "\n\n������� �����, �� ������� ���������� �������� ���������: ";
	doubleInputValidation(Number);

	Polynom.EndPolynom = new double[Polynom.EPMaxDegree + PolynomNum];

	for (int i = 0; i <= Polynom.EPMaxDegree; i++)
	{
		Polynom.EndPolynom[i] = Polynom.FirstPolynom[i] * Number;
	}

	cout << "\n\n��������� ��������� ���������� �� ����� " << Number << ": ";
	PolynomOutput(Polynom.EndPolynom, Polynom.EPMaxDegree);

	MemoryClean(Polynom, PolynomNum);
}

// ����������� �� ����������
void Derivate(Data &Polynom)
{
	int PolynomNum = 1;

	PolynomInput(Polynom, PolynomNum);

	Polynom.EndPolynom = new double[Polynom.EPMaxDegree + PolynomNum];

	int j = Polynom.FPMaxDegree;

	for (int i = 0; i <= Polynom.EPMaxDegree; i++)
	{
		Polynom.EndPolynom[i] = j * Polynom.FirstPolynom[i];
		j--;
	}

	Polynom.EPMaxDegree = Polynom.FPMaxDegree - 1;

	cout << "\n\n����������� �� ����������: ";
	PolynomOutput(Polynom.EndPolynom, Polynom.EPMaxDegree);

	MemoryClean(Polynom, PolynomNum);
}

// ������� ������
void MemoryClean(Data& Polynom, const int& PolynomNum)
{
	delete[] Polynom.FirstPolynom;
	if (PolynomNum == 2) delete[] Polynom.SecondPolynom;
	delete[] Polynom.EndPolynom;
}