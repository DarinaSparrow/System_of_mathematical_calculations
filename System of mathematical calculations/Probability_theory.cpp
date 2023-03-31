#include "Probability_theory.h"

// Меню
void Probability_theory()
{
    int choice, m, n, size, values[100];
    double mean, variance, probabilities[100];

    do
    {
        cout << "Выберите действие:	" << endl;
        cout << "1. Вычисление вероятности m/n" << endl;
        cout << "2. Вычисление дисперсии дискретного распределения величин" << endl;
        cout << "3. Вычисление математического ожидания для дискретного распределения величин" << endl;
        cout << "(Для перехода на главное меню введите 0)" << endl;

        do
        {
            cout << endl << "Ваш выбор: ";
            while (!(cin >> choice))
            {
                cout << "Ошибка! Введите целое число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((choice < 0) || (choice > 3)) cout << "Введены некорректные данные. Повторите ввод." << endl;
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
            cout << "Дисперсия дискретного распределения величин: " << variance << endl;
            break;

        case 3:
            Input_values(values, probabilities, size);
            mean = Calculate_mean(values, probabilities, size);
            cout << "Математическое ожидание для дискретного распределения величин: " << mean << endl;
        }

        if (choice != 0)
        {
            cout << endl;
            system("pause");
            system("cls");
        }
    } while (choice != 0);
}

// Ввод количества благоприятных исходов
void Input_1(int &m, int n) 
{
    do
    {
        cout << "Введите количество благоприятных исходов: ";
        while (!(cin >> m))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if ((m > n) || (m < 0)) cout << "Введены некорректные данные. Повторите ввод." << endl;
    } while ((m > n) || (m < 0));
}

// Ввод количества всех возможных событий
void Input_2(int &n) 
{
    do
    {
        cout << "Введите количество всех возможных событий: ";
        while (!(cin >> n))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (n <= 0) cout << "Введены некорректные данные. Повторите ввод." << endl;
    } while (n <= 0);
    cout << endl;
}

// Вычисление вероятности m/n
void Probability(int m, int n) 
{
    double p = static_cast<double>(m) / static_cast<double>(n);
    cout << "Вероятность события " << p << endl;
}

// Ввод значений и вероятностей
void Input_values(int *values, double *probabilities, int &size)
{
    do
    {
        cout << "Введите количество событий: ";
        while (!(cin >> size))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (size <= 0) cout << "Введены некорректные данные. Повторите ввод." << endl;
    } while (size <= 0);

    cout << endl;

    for (int i = 0; i < size; i++) 
    {
        cout << "Введите значение " << i + 1 << " события: ";
        while (!(cin >> values[i]))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        do
        {
            cout << "Введите вероятность " << i + 1 << " события: ";
            while (!(cin >> probabilities[i]))
            {
                cout << "Ошибка! Введите целое число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((probabilities[i] < 0) || (probabilities[i] > 1)) cout << "Введены некорректные данные. Повторите ввод." << endl;
        } while ((probabilities[i] < 0) || (probabilities[i] > 1));

        cout << endl;
    }
}

// Вычисление математического ожидания для дискретного распределения величин
double Calculate_mean(int *values, double *probabilities, int size) 
{
    double mean = 0.0;
    for (int i = 0; i < size; i++) mean += values[i] * probabilities[i];

    return mean;
}

// Вычисление дисперсии дискретного распределения величин
double Calculate_variance(int *values, double *probabilities, int size, double mean)
{
    double variance = 0.0;
    for (int i = 0; i < size; i++) variance += probabilities[i] * pow((values[i] - mean), 2);

    return variance;
}