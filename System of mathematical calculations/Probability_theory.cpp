#include "Probability_theory.h"

// ����
void Probability_theory()
{
    int choice, m, n, size, values[100];
    double mean, variance, probabilities[100];

    do
    {
        cout << "�������� ��������:	" << endl;
        cout << "1. ���������� ����������� m/n" << endl;
        cout << "2. ���������� ��������� ����������� ������������� �������" << endl;
        cout << "3. ���������� ��������������� �������� ��� ����������� ������������� �������" << endl;
        cout << "(��� �������� �� ������� ���� ������� 0)" << endl;

        do
        {
            cout << endl << "��� �����: ";
            while (!(cin >> choice))
            {
                cout << "������! ������� ����� �����: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((choice < 0) || (choice > 3)) cout << "������� ������������ ������. ��������� ����." << endl;
        } while ((choice < 0) || (choice > 3));

        system("cls");

        switch (choice)
        {
        case 1:
            Input_2(n);
            Input_1(m, n);
            Probability(m, n);
            break;

        case 2:
            Input_values(values, probabilities, size);
            mean = Calculate_mean(values, probabilities, size);
            variance = Calculate_variance(values, probabilities, size, mean);
            cout << "��������� ����������� ������������� �������: " << variance << endl;
            break;

        case 3:
            Input_values(values, probabilities, size);
            mean = Calculate_mean(values, probabilities, size);
            cout << "�������������� �������� ��� ����������� ������������� �������: " << mean << endl;
        }

        if (choice != 0)
        {
            cout << endl;
            system("pause");
            system("cls");
        }
    } while (choice != 0);
}

// ���� ���������� ������������� �������
void Input_1(int &m, int n) 
{
    do
    {
        cout << "������� ���������� ������������� �������: ";
        while (!(cin >> m))
        {
            cout << "������! ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if ((m > n) || (m < 0)) cout << "������� ������������ ������. ��������� ����." << endl;
    } while ((m > n) || (m < 0));
}

// ���� ���������� ���� ��������� �������
void Input_2(int &n) 
{
    do
    {
        cout << "������� ���������� ���� ��������� �������: ";
        while (!(cin >> n))
        {
            cout << "������! ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (n <= 0) cout << "������� ������������ ������. ��������� ����." << endl;
    } while (n <= 0);
    cout << endl;
}

// ���������� ����������� m/n
void Probability(int m, int n) 
{
    double p = static_cast<double>(m) / static_cast<double>(n);
    cout << "����������� ������� " << p << endl;
}

// ���� �������� � ������������
void Input_values(int *values, double *probabilities, int &size)
{
    do
    {
        cout << "������� ���������� �������: ";
        while (!(cin >> size))
        {
            cout << "������! ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (size <= 0) cout << "������� ������������ ������. ��������� ����." << endl;
    } while (size <= 0);

    cout << endl;

    for (int i = 0; i < size; i++) 
    {
        cout << "������� �������� " << i + 1 << " �������: ";
        while (!(cin >> values[i]))
        {
            cout << "������! ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        do
        {
            cout << "������� ����������� " << i + 1 << " �������: ";
            while (!(cin >> probabilities[i]))
            {
                cout << "������! ������� ����� �����: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((probabilities[i] < 0) || (probabilities[i] > 1)) cout << "������� ������������ ������. ��������� ����." << endl;
        } while ((probabilities[i] < 0) || (probabilities[i] > 1));

        cout << endl;
    }
}

// ���������� ��������������� �������� ��� ����������� ������������� �������
double Calculate_mean(int *values, double *probabilities, int size) 
{
    double mean = 0.0;
    for (int i = 0; i < size; i++) mean += values[i] * probabilities[i];

    return mean;
}

// ���������� ��������� ����������� ������������� �������
double Calculate_variance(int *values, double *probabilities, int size, double mean)
{
    double variance = 0.0;
    for (int i = 0; i < size; i++) variance += probabilities[i] * pow((values[i] - mean), 2);

    return variance;
}