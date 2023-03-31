#include "Fractions.h"

// ����
void Fractions()
{
    int num1, den1, num2, den2, choise;

    do
    {
        cout << "�������� ��������:	" << endl;
        cout << "1. �������� ������" << endl;
        cout << "2. ��������� ������" << endl;
        cout << "3. ��������� ������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "5. ��������� ������" << endl;
        cout << "6. ���������� �����" << endl;
        cout << "7. ������������� ����� � ���������� ����" << endl;
        cout << "(��� �������� �� ������� ���� ������� 0)" << endl;

        do
        {
            cout << endl << "��� �����: ";
            while (!(cin >> choise))
            {
                cout << "������! ������� ����� �����: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((choise < 0) || (choise > 7)) cout << "������� ������������ ������. ��������� ����." << endl;
        } while ((choise < 0) || (choise > 7));

        system("cls");

        switch (choise)
        {
        case 1:
            cout << "������� ������ �����" << endl;
            input_fraction(num1, den1);
            cout << endl << "������� ������ �����" << endl;
            input_fraction(num2, den2);
            cout << endl << "���� ������ �����: ";
            output_fraction(num1, den1);
            cout << "���� ������ �����: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            add_fractions(num1, den1, num2, den2);
            break;

        case 2:
            cout << "������� ������ �����" << endl;
            input_fraction(num1, den1);
            cout << endl << "������� ������ �����" << endl;
            input_fraction(num2, den2);
            cout << endl << "���� ������ �����: ";
            output_fraction(num1, den1);
            cout << "���� ������ �����: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            subtract_fractions(num1, den1, num2, den2);
            break;

        case 3:
            cout << "������� ������ �����" << endl;
            input_fraction(num1, den1);
            cout << endl << "������� ������ �����" << endl;
            input_fraction(num2, den2);
            cout << endl << "���� ������ �����: ";
            output_fraction(num1, den1);
            cout << "���� ������ �����: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            multiplication_fraction(num1, den1, num2, den2);
            break;

        case 4:
            cout << "������� ������ �����" << endl;
            input_fraction(num1, den1);
            cout << endl << "������� ������ �����" << endl;
            input_fraction(num2, den2);
            cout << endl << "���� ������ �����: ";
            output_fraction(num1, den1);
            cout << "���� ������ �����: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            division_fraction(num1, den1, num2, den2);
            break;

        case 5:
            cout << "������� ������ �����" << endl;
            input_fraction(num1, den1);
            cout << endl << "������� ������ �����" << endl;
            input_fraction(num2, den2);
            cout << endl << "���� ������ �����: ";
            output_fraction(num1, den1);
            cout << "���� ������ �����: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            comparison_fractions(num1, den1, num2, den2);
            break;

        case 6:
            cout << "������� �����" << endl;
            input_fraction(num1, den1);
            cout << endl << "���� �����: ";
            output_fraction(num1, den1);
            reduce_fraction1(num1, den1);
            break;

        case 7:
            cout << "������� �����: " << endl;
            input_fraction(num1, den1);
            cout << endl << "���� �����: ";
            output_fraction(num1, den1);
            decimal(num1, den1);
        }

        if (choise != 0)
        {
            cout << endl;
            system("pause");
            system("cls");
        }
    } while (choise != 0);
}

// ���� �����
void input_fraction (int &numerator, int &denominator) 
{
    cout << "���������: ";
    while (!(cin >> numerator)) 
    {
        cout << "������! ������� ����� �����: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "�����������: ";
    while (!(cin >> denominator) || denominator == 0) 
    {
        if (cin.fail()) 
        {
            cout << "������! ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else 
        {
            cout << "������! ����������� �� ����� ���� ����� 0. ������� ������ �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// ���������� ������������ �����
void reduce_fraction(int &numerator, int &denominator)
{
    int divisor = gcd(numerator, denominator);

    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
    }
}

// ���� ��������� �����
void action_menu(int &num1, int &den1, int &num2, int &den2)
{
    int choice;

    cout << endl;
    cout << "������ �������� �����?" << endl;
    cout << "1. ��, ������ ������" << endl;
    cout << "2. ��, ������ ������" << endl;
    cout << "3. ��, ��� �����" << endl;
    cout << "4. ���, ���� �� ����������" << endl;
    cout << endl;

    do
    {
        cout << "��� �����: ";
        while (!(cin >> choice))
        {
            cout << "������! ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if ((choice < 1) || (choice > 4)) cout << "������� ������������ ������. ��������� ����." << endl;
    } while ((choice < 1) || (choice > 4));

    switch (choice)
    {
    case 1:
        cout << endl << "������� ������ �����" << endl;
        input_fraction(num1, den1);
        break;

    case 2:
        cout << endl << "������� ������ �����" << endl;
        input_fraction(num2, den2);
        break;

    case 3:
        cout << endl << "������� ������ �����" << endl;
        input_fraction(num1, den1);
        cout << endl << "������� ������ �����" << endl;
        input_fraction(num2, den2);
        break;

    case 4:
        break;
    }

    cout << endl;
}

// ����� �����
void output_fraction(int numerator, int denominator) 
{
    cout << numerator << "/" << denominator << endl;
}

// ��������
void add_fractions(int num1, int den1, int num2, int den2) 
{
    int lcm = abs(den1 * den2) / gcd(den1, den2);
    int num = num1 * lcm / den1 + num2 * lcm / den2;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "�����: " << num << endl;
    else cout << "�����: " << num << "/" << lcm << endl;
}

// ���������
void subtract_fractions(int num1, int den1, int num2, int den2) 
{
    int lcm = abs(den1 * den2) / gcd(den1, den2);
    int num = num1 * lcm / den1 - num2 * lcm / den2;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "�����: " << num;
    else cout << "�����: " << num << "/" << lcm << endl;
}

// ���������
void multiplication_fraction(int num1, int den1, int num2, int den2) 
{
    int num = num1 * num2;
    int lcm = den1 * den2;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "�����: " << num << endl;
    else cout << "�����: " << num << "/" << lcm << endl;
}

// �������
void division_fraction(int num1, int den1, int num2, int den2)
{
    int num = num1 * den2;
    int lcm = num2 * den1;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "�����: " << num << endl;
    else cout << "�����: " << num << "/" << lcm << endl;
}

// ���������
void comparison_fractions(int num1, int den1, int num2, int den2) 
{
    int lcm = abs(den1 * den2) / gcd(den1, den2);
    int num11 = num1 * lcm / den1;
    int num22 = num2 * lcm / den2;

    if (num11 > num22) cout << num1 << "/" << den1 << ">" << num2 << "/" << den2 << endl;
    if (num11 < num22) cout << num2 << "/" << den2 << ">" << num1 << "/" << den1 << endl;
    if (num11 == num22) cout << num1 << "/" << den1 << "=" << num2 << "/" << den2 << endl;
}

// ����������
void reduce_fraction1(int &numerator, int &denominator)
{
    int divisor = gcd(numerator, denominator);

    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
        cout << endl << "����������� �����: ";
        output_fraction(numerator, denominator);
    }
    else
    {
        cout << "����� ��� �����������" << endl;
    }
}

// ������������� � ���� ���������� �����
void decimal(int &numerator, int &denominator) 
{
    int num = numerator;
    int den = denominator;
    double result = static_cast<double>(num) / den;

    cout << endl << numerator << "/" << denominator << " = " << result << endl;
}

//���
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}