#include "Combinatorics.h"

// �������� ����� ������
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
			cout << "����������, ������� ����� �����: ";
			input = false;
		}
	} while (!input);
}

// ����
void Combinatorics()
{
	int Num_Fun;

	do
	{
		cout << "�������� ��������:	" << endl;
		cout << "1. ���������� � ������������" << endl;
		cout << "2. ���������� ��� ����������" << endl;
		cout << "3. ��������� � ������������" << endl;
		cout << "4. ��������� ��� ����������" << endl;
		cout << "5. ������������ � ������������" << endl;
		cout << "6. ������������ ��� ����������" << endl;
		cout << "(��� �������� �� ������� ���� ������� 0)" << endl;

		do
		{
			cout << endl << "��� �����: ";
			Check(Num_Fun);
			if ((Num_Fun < 0) || (Num_Fun > 6)) cout << "������� ������������ ������. ��������� ����." << endl;
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

// ���������� � ������������
void Place_with_repet()
{
	struct Elements El;

	do
	{
		cout << "������� ���������� ���������: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	do
	{
		cout << "������� ���������� ���� ��� ����������: ";
		Check(El.element_2);
		if (El.element_2 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_2 < 1);

	El.num_ways = pow(El.element_1, El.element_2);

	cout << endl << "���������� ��������: " << El.num_ways << endl;
}


// ���������� ��� ����������
void Place_without_repet()
{
	int k;
	struct Elements El;

	do
	{
		cout << "������� ���������� ���������: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	do
	{
		cout << "������� ���������� ���� ��� ����������: ";
		Check(El.element_2);
		if ((El.element_2 < 1) || (El.element_2 >= El.element_1)) cout << "������� ������������ ������. ��������� ����." << endl;
	} while ((El.element_2 < 1) || (El.element_2 >= El.element_1));

	k = El.element_1 - El.element_2;
	El.num_ways = fc(El.element_1) / fc(k);

	cout << endl << "���������� ��������: " << El.num_ways << endl;
}

// ��������� � ������������
void Combin_with_repet()
{
	int k, l;
	struct Elements El;

	do
	{
		cout << "������� ����� ���������� ���������: ";
		Check(El.element_1);
		if (El.element_1 <= 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_1 <= 1);

	cout << endl;

	do
	{
		cout << "������� ���������� ���������� ���������: ";
		Check(El.element_2);
		if (El.element_2 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_2 < 1);

	k = El.element_1 + El.element_2 - 1;
	l = El.element_1 - 1;
	El.num_ways = fc(k) / (fc(El.element_2) * fc(l));

	cout << endl << "���������� ��������: " << El.num_ways << endl;
}

// ��������� ��� ����������
void Combin_without_repet()
{
	int k;
	struct Elements El;

	do
	{
		cout << "������� ����� ���������� ���������: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	do
	{
		cout<< "������� ���������� ���������� ���������: ";
		Check(El.element_2);
		if ((El.element_2 < 1) || (El.element_2 >= El.element_1)) cout << "������� ������������ ������. ��������� ����." << endl;
	} while ((El.element_2 < 1) || (El.element_2 >= El.element_1));

	k = El.element_1 - El.element_2;
	El.num_ways = fc(El.element_1) / (fc(El.element_2) * fc(k));

	cout << endl << "���������� ��������: " << El.num_ways << endl;
}

// ������������ � ������������
void Permutations_with_repet()
{
	int s, l, k[25];
	struct Elements El;

	do
	{
		cout << "������� ���������� ����� ���������: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_1 < 1);

	cout << endl;

	for (int i = 0; i < El.element_1; i++)
	{
		do
		{
			cout  << "������� ���������� ��������� " << i + 1 << " ����: ";
			Check(k[i]);
			if (k[i] < 1) cout << "������� ������������ ������. ��������� ����." << endl;
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

	cout << endl << "���������� ��������: " << El.num_ways << endl;
}

// ������������ ��� ����������
void Permutations_without_repet()
{
	struct Elements El;

	do
	{
		cout << "������� ���������� ���������: ";
		Check(El.element_1);
		if (El.element_1 < 1) cout << "������� ������������ ������. ��������� ����." << endl;
	} while (El.element_1 < 1);

	El.num_ways = fc(El.element_1);

	cout << endl << "���������� ��������: " << El.num_ways << endl;
}

// ���������
int fc(int a)
{
	if (a < 0) return 0;
	if (a == 0) return 1;
	return a * fc(a - 1);
}