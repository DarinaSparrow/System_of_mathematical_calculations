#include "Combinatorics.h"

// Проверка ввода данных
void Check(int &a)
{
	bool input;

	do
	{
		input = true;
		cin >> a;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Пожалуйста, введите целое число: ";
			input = false;
		}
	} while (!input);
}

// Меню
void Combinatorics()
{
	int Num_Fun;

	do
	{
		cout << "Выберите действие:	" << endl;
		cout << "1. Размещения с повторениями" << endl;
		cout << "2. Размещения без повторений" << endl;
		cout << "3. Сочетания с повторениями" << endl;
		cout << "4. Сочетания без повторений" << endl;
		cout << "5. Перестановки с повторениями" << endl;
		cout << "6. Перестановки без повторений" << endl;
		cout << "(Для перехода на главное меню введите 0)" << endl;

		do
		{
			cout << endl << "Ваш выбор: ";
			Check(Num_Fun);
			if ((Num_Fun < 0) || (Num_Fun > 6)) cout << "Введены некорректные данные. Повторите ввод." << endl;
		} while ((Num_Fun < 0) || (Num_Fun > 6));

		system("cls");

		switch (Num_Fun)
		{
		case 1: Place_with_repet(); break;
		case 2: Place_without_repet(); break;
		case 3: Combin_with_repet(); break;
		case 4: Combin_without_repet(); break;
		case 5: Permutations_with_repet(); break;
		case 6: Permutations_without_repet();
		}

		if (Num_Fun != 0)
		{
			cout << endl;
			system("pause");
			system("cls");
		}
	} while (Num_Fun != 0);
}

// Размещения с повторениями
void Place_with_repet()
{
	struct Elements El;

	do
	{
		cout << "Введите количество элементов: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	do
	{
		cout << "Введите количество мест для размещения: ";
		Check(El.element_2);
		if (El.element_2 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_2 < 1);

	El.num_ways = pow(El.element_1, El.element_2);

	cout << endl << "Количество способов: " << El.num_ways << endl;
}


// Размещения без повторений
void Place_without_repet()
{
	int k;
	struct Elements El;

	do
	{
		cout << "Введите количество элементов: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	do
	{
		cout << "Введите количество мест для размещения: ";
		Check(El.element_2);
		if ((El.element_2 < 1) || (El.element_2 >= El.element_1)) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while ((El.element_2 < 1) || (El.element_2 >= El.element_1));

	k = El.element_1 - El.element_2;
	El.num_ways = fc(El.element_1) / fc(k);

	cout << endl << "Количество способов: " << El.num_ways << endl;
}

// Сочетания с повторениями
void Combin_with_repet()
{
	int k, l;
	struct Elements El;

	do
	{
		cout << "Введите общее количество элементов: ";
		Check(El.element_1);
		if (El.element_1 <= 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_1 <= 1);

	cout << endl;

	do
	{
		cout << "Введите количество выбираемых элементов: ";
		Check(El.element_2);
		if (El.element_2 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_2 < 1);

	k = El.element_1 + El.element_2 - 1;
	l = El.element_1 - 1;
	El.num_ways = fc(k) / (fc(El.element_2) * fc(l));

	cout << endl << "Количество способов: " << El.num_ways << endl;
}

// Сочетания без повторений
void Combin_without_repet()
{
	int k;
	struct Elements El;

	do
	{
		cout << "Введите общее количество элементов: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	do
	{
		cout<< "Введите количество выбираемых элементов: ";
		Check(El.element_2);
		if ((El.element_2 < 1) || (El.element_2 >= El.element_1)) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while ((El.element_2 < 1) || (El.element_2 >= El.element_1));

	k = El.element_1 - El.element_2;
	El.num_ways = fc(El.element_1) / (fc(El.element_2) * fc(k));

	cout << endl << "Количество способов: " << El.num_ways << endl;
}

// Перестановки с повторениями
void Permutations_with_repet()
{
	int s, l, k[25];
	struct Elements El;

	do
	{
		cout << "Введите количество типов элементов: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	for (int i = 0; i < El.element_1; i++)
	{
		do
		{
			cout  << "Введите количество элементов " << i + 1 << " типа: ";
			Check(k[i]);
			if (k[i] < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
		} while (k[i] < 1);
	}

	s = 0;
	l = 1;
	for (int i = 0; i < El.element_1; i++)
	{
		s += k[i];
		l *= fc(k[i]);
	}
	El.num_ways = fc(s) / l;

	cout << endl << "Количество способов: " << El.num_ways << endl;
}

// Перестановки без повторений
void Permutations_without_repet()
{
	struct Elements El;

	do
	{
		cout << "Введите количество элементов: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "Введены некорректные данные. Повторите ввод." << endl;
	} while (El.element_1 < 1);

	El.num_ways = fc(El.element_1);

	cout << endl << "Количество способов: " << El.num_ways << endl;
}

// Факториал
int fc(int a)
{
	if (a < 0) return 0;
	if (a == 0) return 1;
	return a * fc(a - 1);
}