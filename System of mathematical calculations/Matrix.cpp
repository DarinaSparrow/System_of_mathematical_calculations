#include "Matrix.h"

// Проверка ввода данных типа int
void Check_int(int &data)
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
			cout << "Пожалуйста, введите целое число: ";
			input = false;
		}
	} while (!input);
}

// Проверка ввода данных типа double
void Check_double(double &data)
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
			cout << "Пожалуйста, введите число: ";
			input = false;
		}
	} while (!input);
}

// Меню
void Matrix()
{
	int num, M_1, N_1, M_2, N_2;
	struct matrix element_1, element_2, element_res;

	do
	{
		cout << "Выберите действие:	" << endl;
		cout << "1. Сложение матриц" << endl;
		cout << "2. Вычитание матриц" << endl;
		cout << "3. Умножение матриц" << endl;
		cout << "4. Умножение матрицы на число" << endl;
		cout << "5. Сложение/вычитание матрицы с числом" << endl;
		cout << "6. Транспонирование матрицы" << endl;
		cout << "7. Нахождение обратной матрицы" << endl;
		cout << "8. Вычисление определителя матрицы" << endl;
		cout << "(Для перехода на главное меню введите 0)" << endl;

		do
		{
			cout << endl << "Ваш выбор: ";
			Check_int(num);
			if ((num < 0) || (num > 8)) cout << "Введены некорректные данные. Повторите ввод." << endl;
		} while ((num < 0) || (num > 8));

		system("cls");

		switch (num)
		{
		case 1:
			cout << "Введите размерность первой матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			cout << "Введите размерность второй матрицы." << endl << endl;
			Input(M_2, N_2, element_2);
			Addition(M_1, N_1, element_1, M_2, N_2, element_2, element_res);
			break;

		case 2:
			cout << "Введите размерность первой матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			cout << "Введите размерность второй матрицы." << endl << endl;
			Input(M_2, N_2, element_2);
			Subtraction(M_1, N_1, element_1, M_2, N_2, element_2, element_res);
			break;

		case 3:
			cout << "Введите размерность первой матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			cout << "Введите размерность второй матрицы." << endl << endl;
			Input(M_2, N_2, element_2);
			Multiplication(M_1, N_1, element_1, M_2, N_2, element_2, element_res);
			break;

		case 4:
			cout << "Введите размерность матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			Multiplication_with_Num(M_1, N_1, element_1, element_res);
			break;

		case 5:
			cout << "Введите размерность матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			Add_with_Num(M_1, N_1, element_1, M_2, N_2, element_2, element_res);
			break;

		case 6:
			cout << "Введите размерность матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			Transposition(M_1, N_1, element_1, element_res);
			break;

		case 7:
			cout << "Введите размерность матрицы." << endl << endl;
			Input(M_1, N_1, element_1);
			Inverse_M(M_1, N_1, element_1, element_res);
			break;

		case 8:
			Determinant(M_1, N_1, element_1);
		}

		if (num != 0)
		{
			cout << endl;
			system("pause");
			system("cls");
		}
	} while (num != 0);
}

// Ввод матрицы 1
void Input(int &M, int &N, struct matrix &element)
{
	do
	{
		cout << "Количество строк: ";
		Check_int(M);
		if (M <= 0) cout << "Минимальное количество строк - 1." << endl;
	} while (M <= 0);

	do
	{
		cout << "Количество столбцов: ";
		Check_int(N);
		if (N <= 0) cout << "Минимальное количество столбцов - 1." << endl;
	} while (N <= 0);

	cout << endl;

	cout << "Введите элементы матрицы: " << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			Check_double(element.m[i][j]);
		}
	}
	cout << endl;
}

// Сложение матриц
void Addition(int M_1, int N_1, struct matrix &element_1, int M_2, int N_2, struct matrix &element_2, struct matrix &element_res)
{
	if ((M_1 == M_2) && (N_1 == N_2)) 
	{
		for (int i = 0; i < M_1; i++) 
		{
			for (int j = 0; j < N_1; j++) 
			{
				element_res.m[i][j] = element_1.m[i][j] + element_2.m[i][j];
			}
		}

		Output(M_1, N_1, element_res);
	}

	else cout << "Невозможно реализовать операцию. " << endl;
}

// Вычитание матриц
void Subtraction(int M_1, int N_1, struct matrix &element_1, int M_2, int N_2, struct matrix &element_2, struct matrix &element_res)
{
	if ((M_1 == M_2) && (N_1 == N_2)) 
	{
		for (int i = 0; i < M_1; i++) 
		{
			for (int j = 0; j < N_1; j++) 
			{
				element_res.m[i][j] = element_1.m[i][j] - element_2.m[i][j];
			}
		}

		Output(M_1, N_1, element_res);
	}

	else cout << "Невозможно реализовать операцию. " << endl;
}

// Умножение матриц
void Multiplication(int M_1, int N_1, struct matrix &element_1, int M_2, int N_2, struct matrix &element_2, struct matrix &element_res)
{
	if (N_1 == M_2) 
	{
		for (int i = 0; i < M_1; i++) 
		{
			for (int j = 0; j < N_2; j++) 
			{
				element_res.m[i][j] = 0;
				for (int k = 0; k < N_2; k++) 
				{
					element_res.m[i][j] += element_1.m[i][k] * element_2.m[k][j];
				}
			}
		}

		Output(M_1, N_2, element_res);
	}

	else cout << "Невозможно реализовать операцию. " << endl;
}

// Умножение матрицы на число
void Multiplication_with_Num(int M, int N, struct matrix &element, struct matrix &element_res)
{
	double number_mult;

	cout << "Введите число, на которое хотите умножить матрицу: "; 
	Check_double(number_mult);
	cout << endl;

	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			element_res.m[i][j] = element.m[i][j] * number_mult;
		}
	}

	Output(M, N, element_res);
}

// Сложение/вычитание матрицы с числом
void Add_with_Num(int M_1, int N_1, struct matrix &element_1, int &M_2, int &N_2, struct matrix &element_2, struct matrix &element_res)
{
	int num_add; double number_add;

	cout << "Введите число, с которым хотите сложить матрицу: "; 
	Check_double(number_add);
	cout << endl;

	cout << "Уточните действие:" << endl;
	cout << "1. Сложение матрицы с единичной матрицой, умноженной на число" << endl;
	cout << "2. Сложение каждого элемента матрицы с числом" << endl;

	do
	{
		cout << endl << "Ваш выбор: ";
		Check_int(num_add);
		if ((num_add != 1) && (num_add != 2)) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while ((num_add != 1) && (num_add != 2));

	if (num_add == 1)
	{
		if (M_1 == N_1)
		{
			M_2 = M_1; N_2 = N_1;
			for (int i = 0; i < M_2; i++)
			{
				for (int j = 0; j < N_2; j++)
				{
					if (i == j) element_2.m[i][j] = number_add;
					else element_2.m[i][j] = 0;
				}
			}
		}
	}

	if (num_add == 2)
	{
		M_2 = M_1; N_2 = N_1;
		for (int i = 0; i < M_2; i++) 
		{
			for (int j = 0; j < N_2; j++) 
			{
				element_2.m[i][j] = number_add;
			}
		}
	}

	cout << endl;

	Addition(M_1, N_1, element_1, M_2, N_2, element_2, element_res);
}

// Транспонирование матрицы
void Transposition(int &M, int &N, struct matrix &element, struct matrix &element_res)
{
	int t;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			element_res.m[j][i] = element.m[i][j];
		}
	}

	t = N; N = M; M = t;

	Output(M, N, element_res);
}

// Нахождение обратной матрицы
void Inverse_M(int M, int N, struct matrix &element, struct matrix &element_res)
{
	if (N == M)
	{
		double m[100][100], obr[100][100];
		int i, j, k;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				m[i][j] = element.m[i][j];
			}
		}

		for (k = 0; k < N; k++)
		{
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (i == k && j == k) obr[i][j] = 1 / m[i][j];
					if (i == k && j != k) obr[i][j] = -m[i][j] / m[k][k];
					if (i != k && j == k) obr[i][j] = m[i][k] / m[k][k];
					if (i != k && j != k) obr[i][j] = m[i][j] - m[k][j] * m[i][k] / m[k][k];
				}
			}

			for (i = 0; i < N; i++)
			{
				{
					for (j = 0; j < N; j++) m[i][j] = obr[i][j];
				}
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				element_res.m[i][j] = m[i][j];
			}
		}

		Output(M, N, element_res);
	}

	else cout << "Невозможно реализовать операцию. " << endl;
}

// Вычисление определителя матрицы
void Determinant(int &M, int &N, struct matrix &element)
{
	double m[Nmax][Mmax], Determ;

	cout << "Введите размерность матрицы." << endl << endl;

	do
	{
		cout << "Количество строк: ";
		Check_int(M);
		if (M <= 0) cout << "Минимальное количество строк - 1." << endl;
	} while (M <= 0);

	do
	{
		cout << "Количество столбцов: ";
		Check_int(N);
		if (N <= 0) cout << "Минимальное количество столбцов - 1." << endl;
	} while (N <= 0);

	cout << endl << "Введите элементы матрицы: " << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			Check_double(m[i][j]);
			element.m[i][j] = m[i][j];
		}
	}

	if ((M == 1) && (N == 1))
	{
		Determ = m[0][0];
		cout << endl << "Определитель: " << Determ << endl;
	}
	else if ((M == 2) && (N == 2))
	{
		Determ = m[0][0] * m[1][1] - m[1][0] * m[0][1];
		cout << endl << "Определитель: " << Determ << endl;
	}
	else if (M == N)
	{
		Determ = Deter(m, M);
		cout << endl << "Определитель (целое число): " << Determ << endl;
	}
	else
	{
		cout << endl << "Невозможно реализовать операцию. " << endl;
	}
}

// 
double Deter(double m[Nmax][Mmax], int M)
{
	double det = 0;
	double subm[Nmax][Mmax];

	if (M == 2) 
	{

		return ((m[0][0] * m[1][1]) - (m[1][0] * m[0][1]));
	}

	else 
	{
		for (int k = 0; k < M; k++) 
		{
			int subi = 0;
			for (int i = 1; i < M; i++) 
			{
				int subj = 0;
				for (int j = 0; j < M; j++) 
				{
					if (j == k) continue;
					subm[subi][subj] = m[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, k) * m[0][k] * Deter(subm, M - 1));
		}
	}

	return det;
}

//Вывод результата
void Output(int M, int N, struct matrix element_res)
{
	cout << "Результат: " << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			cout << element_res.m[i][j] << "\t";
		}
		cout << endl;
	}
}