#include "Fractions.h"

// Меню
void Fractions()
{
    int num1, den1, num2, den2, choise;

    do
    {
        cout << "Выберите действие:	" << endl;
        cout << "1. Сложение дробей" << endl;
        cout << "2. Вычитание дробей" << endl;
        cout << "3. Умножение дробей" << endl;
        cout << "4. Деление дробей" << endl;
        cout << "5. Сравнение дробей" << endl;
        cout << "6. Сокращение дроби" << endl;
        cout << "7. Представление дроби в десятичном виде" << endl;
        cout << "(Для перехода на главное меню введите 0)" << endl;

        do
        {
            cout << endl << "Ваш выбор: ";
            while (!(cin >> choise))
            {
                cout << "Ошибка! Введите целое число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((choise < 0) || (choise > 7)) cout << "Введены некорректные данные. Повторите ввод." << endl;
        } while ((choise < 0) || (choise > 7));

        system("cls");

        switch (choise)
        {
        case 1:
            cout << "Введите первую дробь" << endl;
            input_fraction(num1, den1);
            cout << endl << "Введите вторую дробь" << endl;
            input_fraction(num2, den2);
            cout << endl << "Ваша первая дробь: ";
            output_fraction(num1, den1);
            cout << "Ваша вторая дробь: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            add_fractions(num1, den1, num2, den2);
            break;

        case 2:
            cout << "Введите первую дробь" << endl;
            input_fraction(num1, den1);
            cout << endl << "Введите вторую дробь" << endl;
            input_fraction(num2, den2);
            cout << endl << "Ваша первая дробь: ";
            output_fraction(num1, den1);
            cout << "Ваша вторая дробь: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            subtract_fractions(num1, den1, num2, den2);
            break;

        case 3:
            cout << "Введите первую дробь" << endl;
            input_fraction(num1, den1);
            cout << endl << "Введите вторую дробь" << endl;
            input_fraction(num2, den2);
            cout << endl << "Ваша первая дробь: ";
            output_fraction(num1, den1);
            cout << "Ваша вторая дробь: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            multiplication_fraction(num1, den1, num2, den2);
            break;

        case 4:
            cout << "Введите первую дробь" << endl;
            input_fraction(num1, den1);
            cout << endl << "Введите вторую дробь" << endl;
            input_fraction(num2, den2);
            cout << endl << "Ваша первая дробь: ";
            output_fraction(num1, den1);
            cout << "Ваша вторая дробь: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            division_fraction(num1, den1, num2, den2);
            break;

        case 5:
            cout << "Введите первую дробь" << endl;
            input_fraction(num1, den1);
            cout << endl << "Введите вторую дробь" << endl;
            input_fraction(num2, den2);
            cout << endl << "Ваша первая дробь: ";
            output_fraction(num1, den1);
            cout << "Ваша вторая дробь: ";
            output_fraction(num2, den2);
            action_menu(num1, den1, num2, den2);
            comparison_fractions(num1, den1, num2, den2);
            break;

        case 6:
            cout << "Введите дробь" << endl;
            input_fraction(num1, den1);
            cout << endl << "Ваша дробь: ";
            output_fraction(num1, den1);
            reduce_fraction1(num1, den1);
            break;

        case 7:
            cout << "Введите дробь: " << endl;
            input_fraction(num1, den1);
            cout << endl << "Ваша дробь: ";
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

// Ввод дроби
void input_fraction (int &numerator, int &denominator) 
{
    cout << "Числитель: ";
    while (!(cin >> numerator)) 
    {
        cout << "Ошибка! Введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Знаменатель: ";
    while (!(cin >> denominator) || denominator == 0) 
    {
        if (cin.fail()) 
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else 
        {
            cout << "Ошибка! Знаменатель не может быть равен 0. Введите другое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Сокращение получившейся дроби
void reduce_fraction(int &numerator, int &denominator)
{
    int divisor = gcd(numerator, denominator);

    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
    }
}

// Меню изменения дроби
void action_menu(int &num1, int &den1, int &num2, int &den2)
{
    int choice;

    cout << endl;
    cout << "Хотите изменить дроби?" << endl;
    cout << "1. Да, только первую" << endl;
    cout << "2. Да, только вторую" << endl;
    cout << "3. Да, обе дроби" << endl;
    cout << "4. Нет, меня всё устраивает" << endl;
    cout << endl;

    do
    {
        cout << "Ваш выбор: ";
        while (!(cin >> choice))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if ((choice < 1) || (choice > 4)) cout << "Введены некорректные данные. Повторите ввод." << endl;
    } while ((choice < 1) || (choice > 4));

    switch (choice)
    {
    case 1:
        cout << endl << "Введите первую дробь" << endl;
        input_fraction(num1, den1);
        break;

    case 2:
        cout << endl << "Введите вторую дробь" << endl;
        input_fraction(num2, den2);
        break;

    case 3:
        cout << endl << "Введите первую дробь" << endl;
        input_fraction(num1, den1);
        cout << endl << "Введите вторую дробь" << endl;
        input_fraction(num2, den2);
        break;

    case 4:
        break;
    }

    cout << endl;
}

// Вывод дроби
void output_fraction(int numerator, int denominator) 
{
    cout << numerator << "/" << denominator << endl;
}

// Сложение
void add_fractions(int num1, int den1, int num2, int den2) 
{
    int lcm = abs(den1 * den2) / gcd(den1, den2);
    int num = num1 * lcm / den1 + num2 * lcm / den2;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "Ответ: " << num << endl;
    else cout << "Ответ: " << num << "/" << lcm << endl;
}

// Вычитание
void subtract_fractions(int num1, int den1, int num2, int den2) 
{
    int lcm = abs(den1 * den2) / gcd(den1, den2);
    int num = num1 * lcm / den1 - num2 * lcm / den2;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "Ответ: " << num;
    else cout << "Ответ: " << num << "/" << lcm << endl;
}

// Умножение
void multiplication_fraction(int num1, int den1, int num2, int den2) 
{
    int num = num1 * num2;
    int lcm = den1 * den2;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "Ответ: " << num << endl;
    else cout << "Ответ: " << num << "/" << lcm << endl;
}

// Деление
void division_fraction(int num1, int den1, int num2, int den2)
{
    int num = num1 * den2;
    int lcm = num2 * den1;

    reduce_fraction(num, lcm);

    if (num == lcm) cout << "Ответ: " << num << endl;
    else cout << "Ответ: " << num << "/" << lcm << endl;
}

// Сравнение
void comparison_fractions(int num1, int den1, int num2, int den2) 
{
    int lcm = abs(den1 * den2) / gcd(den1, den2);
    int num11 = num1 * lcm / den1;
    int num22 = num2 * lcm / den2;

    if (num11 > num22) cout << num1 << "/" << den1 << ">" << num2 << "/" << den2 << endl;
    if (num11 < num22) cout << num2 << "/" << den2 << ">" << num1 << "/" << den1 << endl;
    if (num11 == num22) cout << num1 << "/" << den1 << "=" << num2 << "/" << den2 << endl;
}

// Сокращение
void reduce_fraction1(int &numerator, int &denominator)
{
    int divisor = gcd(numerator, denominator);

    if (divisor > 1)
    {
        numerator /= divisor;
        denominator /= divisor;
        cout << endl << "Сокращенная дробь: ";
        output_fraction(numerator, denominator);
    }
    else
    {
        cout << "Дробь уже несократима" << endl;
    }
}

// Представление в виде десятичной дроби
void decimal(int &numerator, int &denominator) 
{
    int num = numerator;
    int den = denominator;
    double result = static_cast<double>(num) / den;

    cout << endl << numerator << "/" << denominator << " = " << result << endl;
}

//НОД
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}