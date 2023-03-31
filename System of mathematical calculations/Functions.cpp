#include "Functions.h"

// Проверка ввода данных типа int
void Input_validation_int(int &data)
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
void Input_validation_double(double &data)
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
void Functions()
{
	int type_of_function, action;

	do
	{
		cout << "Выберите действие:	" << endl;
		cout << "1. Вычисление определённого интеграла на отрезке" << endl;
		cout << "2. Построение графика функции" << endl;
		cout << "3. Поиск корня y = 0 на отрезке" << endl;
		cout << "4. Поиск экстремумов на отрезке" << endl;
		cout << "(Для перехода на главное меню введите 0)" << endl << endl;

		do
		{
			cout << "Ваш выбор: ";
			Input_validation_int(action);
			if ((action < 0) || (action > 4)) cout << "Введены некорректные данные. Повторите ввод." << endl;
		} while ((action < 0) || (action > 4));

		system("cls");

		cout << "Выберите вид функции:	" << endl;
		cout << "1. Полином степени N" << endl;
		cout << "2. Степенная" << endl;
		cout << "3. Показательная" << endl;
		cout << "4. Логарифмическая" << endl;
		cout << "5. Синусоида" << endl;
		cout << "6. Косинусоида" << endl << endl;

		do
		{
			cout << "Ваш выбор: ";
			Input_validation_int(type_of_function);
			if ((type_of_function < 1) || (type_of_function > 6)) cout << "Введены некорректные данные. Повторите ввод." << endl;
		} while ((type_of_function < 1) || (type_of_function > 6));

		system("cls");

		switch (action)
		{
		case 1:   Definite_integral(type_of_function); break;
		case 2:   Function_graph(type_of_function); break;
		case 3:   Root_Search(type_of_function); break;
		case 4:   Extremum(type_of_function);
		}

		if (action != 0)
		{
			cout << endl << endl;
			system("pause");
			system("cls");
		}
	} while (action != 0);
}

// Выбор функции
double Function_Generator(int type_of_function, int &status, int &N, double *coefficients, double &a, double &b, double &c, double &d, double x)
{
	switch (type_of_function)
	{
	case 1:   return Polynomial_of_degree_N(status, N, coefficients, x);
	case 2:   return Power_function(status, a, b, c, x);
	case 3:   return Exponential_function(status, a, b, c, d, x);
	case 4:   return Logarithmic_function(status, a, b, c, x);
	case 5:   return Sinusoid(status, a, b, c, d, x);
	case 6:   return Cosine(status, a, b, c, d, x);
	}
}

// Полином степени N
double Polynomial_of_degree_N(int &status, int &N, double *coefficients, double x)
{
	double y;

	if (status == 0)
	{
		cout << "Выбранная вами функция имеет вид: a0+a1*x+a2*x^2+...+aN*x^N" << endl << endl;

		do
		{
			cout << "Введите степень полинома N: ";
			Input_validation_int(N);
			if (N < 0) cout << "Введены некорректные данные. Повторите ввод." << endl;
			if (N > 25) cout << "Максимально допустимое значение N - 25." << endl;
		} while ((N < 0) || (N > 25));

		for (int i = 0; i <= N; i++)
		{
			cout << "Введите коэффициент а" << i << " : ";
			Input_validation_double(coefficients[i]);
		}

		status = 1;

		cout << endl;
		cout << "Выбранная вами функция имеет вид: y=";
		if (coefficients[0] != 0) cout << coefficients[0];
		for (int i = 1; i <= N; i++)
		{
			if (coefficients[i] != 0)
			{
				if (coefficients[i] > 0)
				{
					cout << "+";
					if (coefficients[i] == 1) cout << "x^" << i;
					else cout << coefficients[i] << "x^" << i;
				}
				else
				{
					if (coefficients[i] == -1) cout << "-x^" << i;
					else cout << coefficients[i] << "x^" << i;
				}
			}
		}
		cout << endl;

		return 0;
	}

	if (status == -1)
	{
		y = 0;

		for (int i = 1; i <= N; i++) y += coefficients[i] * i * pow(x, i - 1);

		return y;
	}

	y = 0;

	for (int i = 0; i <= N; i++) y += coefficients[i] * pow(x, i);

	return y;
}

// Степенная функция
double Power_function(int &status, double &a, double &b, double &c, double x)
{
	if (status == 0)
	{
		cout << "Выбранная вами функция имеет вид: a*x^b+c" << endl << endl;

		cout << "Введите коэффициент a: ";
		Input_validation_double(a);
		cout << "Введите степень числа b: ";
		Input_validation_double(b);
		cout << "Введите коэффициент c: ";
		Input_validation_double(c);

		status = 1;

		cout << endl;
		cout << "Выбранная вами функция имеет вид:  y=";
		if (a == 0) cout << c;
		else 
		{
			if (b == 0) cout << a + c;
			else
			{
				if (a == 1) cout << "x";
				else if (a == -1) cout << "-x";
				else cout << a << "x";
				if (b < 0) cout << "^(" << b << ")";
				else if (b != 1) cout << "^" << b;
				if (c != 0) 
				{
					if (c > 0) cout << "+" << c;
					else cout << c;
				}
			}
		}
		cout << endl;

		return 0;
	}

	if (status == -1) return a * b * pow(x, b - 1);

	return a * pow(x, b) + c;
}

// Показательная функция
double Exponential_function(int &status, double &a, double &b, double &c, double &d, double x)
{
	if (status == 0)
	{
		cout << "Выбранная вами функция имеет вид: a*b^(c*x)+d" << endl << endl;

		cout << "Введите коэффициент a: ";
		Input_validation_double(a);
		cout << "Введите число b: ";
		Input_validation_double(b);
		cout << "Введите коэффициент c: ";
		Input_validation_double(c);
		cout << "Введите коэффициент d: ";
		Input_validation_double(d);

		status = 1;

		cout << endl;
		cout << "Выбранная вами функция имеет вид:  y=";
		if (a == 0) cout << d;
		else
		{
			if (b == 0)  cout << d;
			else
			{
				if (c == 0) cout << a + d;
				else
				{
					if (a == -1)
					{
						if (b == 1) cout << (-1) * a + d;
						else if (b < 0) cout << "-(" << b << ")^";
						else cout << "-" << b << "^";
					}
					else if (a != 1)
					{
						if (b == 1) cout << a + d;
						else if (b < 0) cout << a << "*(" << b << ")^";
						else cout << a << "*" << b << "^";
					}
					if (c == 1) cout << "x";
					else if (c == -1) cout << "(-x)";
					else cout << "(" << c << "x)";
					if ((d != 0) && (b != 1))
					{
						if (d > 0) cout << "+" << d;
						else cout << d;
					}
				}
			}
		}
		cout << endl;

		return 0;
	}

	if (status == -1) return a * c * log(b) * pow(b, c * x);

	return a * pow(b, c * x) + d;
}

// Логарифмическая функция
double Logarithmic_function(int &status, double &a, double &b, double &c, double x)
{
	if (status == 0)
	{
		cout << "Выбранная вами функция имеет вид: a*ln(b*x)+c" << endl << endl;

		cout << "Введите коэффициент a: ";
		Input_validation_double(a);
		do
		{
			cout << "Введите коэффициент b: ";
			Input_validation_double(b);
			if (b == 0) cout << "Коэффициент b не может быть равен 0." << endl;
		} while (b == 0);
		cout << "Введите коэффициент c: ";
		Input_validation_double(c);

		status = 1;

		cout << endl;
		cout << "Выбранная вами функция имеет вид:  y=";
		if (a == 0) cout << c;
		else
		{
			if (a == -1) cout << "-ln(";
			else if (a == 1) cout << "ln(";
			else cout << a << "*ln(";
			if (b == 1) cout << "x)";
			else if (b == -1) cout << "-x)";
			else cout << b << "x)";
			if (c != 0)
			{
				if (c > 0) cout << "+" << c;
				else cout << c;
			}
		}
		cout << endl;

		return 0;
	}

	if (status == -1) return a / x;

	return a * log(b * x) + c;
}

// Синусоида
double Sinusoid(int &status, double &a, double &b, double &c, double &d, double x)
{
	if (status == 0)
	{
		cout << "Выбранная вами функция имеет вид: a*sin(b*x+c)+d" << endl << endl;

		cout << "Введите коэффициент a: ";
		Input_validation_double(a);
		cout << "Введите коэффициент b: ";
		Input_validation_double(b);
		cout << "Введите коэффициент c: ";
		Input_validation_double(c);
		cout << "Введите коэффициент d: ";
		Input_validation_double(d);

		status = 1;

		cout << endl;
		cout << "Выбранная вами функция имеет вид:  y=";
		if (a == 0) cout << d;
		else if (a == 1) cout << "sin(";
		else if (a == -1) cout << "-sin(";
		else cout << a << "*sin("; 
		if (b == 0) cout << c << ")";
		else
		{
			if (b == 1) cout << "x";
			else if (b == -1) cout << "-x";
			else cout << b << "x";
			if (c == 0) cout << ")";
			else if (c > 0) cout << "+" << c << ")";
			else cout << c << ")";
		}
		if (d > 0) cout << "+" << d;
		else if (d < 0) cout << d;
		cout << endl;

		return 0;
	}

	if (status == -1) return a * b * cos(b * x + c);

	return a * sin(b * x + c) + d;
}

// Косинусоида
double Cosine(int &status, double &a, double &b, double &c, double &d, double x)
{
	if (status == 0)
	{
		cout << "Выбранная вами функция имеет вид: a*cos(b*x+c)+d" << endl << endl;

		cout << "Введите коэффициент a: ";
		Input_validation_double(a);
		cout << "Введите коэффициент b: ";
		Input_validation_double(b);
		cout << "Введите коэффициент c: ";
		Input_validation_double(c);
		cout << "Введите коэффициент d: ";
		Input_validation_double(d);

		status = 1;

		cout << endl;
		cout << "Выбранная вами функция имеет вид:  y=";
		if (a == 0) cout << d;
		else if (a == 1) cout << "cos(";
		else if (a == -1) cout << "-cos(";
		else cout << a << "*cos(";
		if (b == 0) cout << c << ")";
		else
		{
			if (b == 1) cout << "x";
			else if (b == -1) cout << "-x";
			else cout << b << "x";
			if (c == 0) cout << ")";
			else if (c > 0) cout << "+" << c << ")";
			else cout << c << ")";
		}
		if (d > 0) cout << "+" << d;
		else if (d < 0) cout << d;
		cout << endl;

		return 0;
	}

	if (status == -1) return (-1) * a * b * sin(b * x + c);

	return a * cos(b * x + c) + d;
}

// Вычисление определённого интеграла на отрезке
void Definite_integral(int type_of_function)
{
	int status, N, sign;
	double a, b, c, d, plug, coefficients[26], integral, start, end, step, parts, glass, sum_1, sum_2;

	plug = 0;

	status = 0;
	Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, plug);

	cout << endl;
	cout << "Введите нижний предел интегрирования: ";
	Input_validation_double(start);
	cout << "Введите верхний предел интегрирования: ";
	Input_validation_double(end);
	cout << endl;

	if (start <= end) sign = 1;
	else
	{
		sign = -1;
		glass = start;
		start = end;
		end = glass;
	}

	step = 0.1;
	parts = (end - start) / step;

	if (start == end) cout << "Определённый интеграл на отрезке [" << start << ", " << end << "] равен 0";

	else
	{
		sum_1 = 0;
		for (int i = 1; i <= parts; i++) sum_1 += Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, start + step * (i - 0.5));

		sum_2 = 0;
		for (int i = 1; i < parts; i++) sum_2 += Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, start + step * i);

		integral = sign * step * (Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, start) + Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, end) + 4 * sum_1 + 2 * sum_2) / 6;

		cout << "Определённый интеграл на отрезке [" << start << ", " << end << "], с учётом выбранных вами пределов, равен " << integral;
	}
}

// Построение графика функции
void Function_graph(int type_of_function)
{
	int status, N, count_1, count_2, parts_x, parts_y, size_of_parts_x, size_of_parts_y;
	double a, b, c, d, plug, coefficients[26], start, end, border, step, glass, sampling_rate, max_y, min_y;
	struct coordinates points_1[750], points_2[750];

	plug = 0;

	status = 0;
	Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, plug);

	cout << endl;
	cout << "Введите минимальное значение x, для которого будет построен график: ";
	Input_validation_double(start);
	cout << "Введите максимальное значение x, для которого будет построен график: ";
	Input_validation_double(end);
	do
	{
		cout << "Введите модуль максимального/минимального значения y, которое может отображаться на графике: ";
		Input_validation_double(border);
		if (border <= 0) cout << "Минимально допустимое значение - 1." << endl;
	} while (border <= 0);
	cout << endl;
	cout << "Введите частоту дискретизации: ";
	Input_validation_double(sampling_rate);

	if (start > end)
	{
		glass = start;
		start = end;
		end = glass;
	}

	step = fabs(end - start) / sampling_rate;

	if (((type_of_function == 4) && (b * start <= 0)) || ((type_of_function == 2) && (((b < 0) && ((int)b == b) && (start == 0)) || ((b > 0) && ((int)b != b) && (start < 0)) || ((b < 0) && ((int)b != b) && (start <= 0)))))
	{
		max_y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, end);
		min_y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, end);
	}
	else
	{
		max_y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, start);
		min_y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, start);
	}

	if (fabs(max_y) > border)
	{
		if (max_y > 0) max_y = border;
		else max_y = -border;
	}

	if (fabs(min_y) > border)
	{
		if (min_y > 0) min_y = border;
		else min_y = -border;
	}

	count_1 = 0;
	count_2 = 0;

	for (double x = start; x <= end; x += step)
	{
		if (((type_of_function == 4) && (b * x <= 0)) || ((type_of_function == 2) && (((b < 0) && ((int)b == b) && (x == 0)) || ((b > 0) && ((int)b != b) && (x < 0)) || ((b < 0) && ((int)b != b) && (x <= 0)))));
		else
		{
			if ((type_of_function == 2) && (b < 0) && ((int)b == b))
			{
				if (x < 0)
				{
					points_1[count_1].x = x;
					points_1[count_1].y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, x);
					if (fabs(points_1[count_1].y) <= border)
					{
						if (points_1[count_1].y > max_y) max_y = points_1[count_1].y;
						if (points_1[count_1].y < min_y) min_y = points_1[count_1].y;
						count_1 += 1;
					}
				}
				else
				{
					points_2[count_2].x = x;
					points_2[count_2].y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, x);
					if (fabs(points_2[count_2].y) <= border)
					{
						if (points_2[count_2].y > max_y) max_y = points_2[count_2].y;
						if (points_2[count_2].y < min_y) min_y = points_2[count_2].y;
						count_2 += 1;
					}
				}
			}
			else
			{
				points_1[count_1].x = x;
				points_1[count_1].y = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, x);
				if (fabs(points_1[count_1].y) <= border)
				{
					if (points_1[count_1].y > max_y) max_y = points_1[count_1].y;
					if (points_1[count_1].y < min_y) min_y = points_1[count_1].y;
					count_1 += 1;
				}
			}
		}
	}

	parts_x = 0;
	if (fabs(start) > fabs(end))
	{
		parts_x = (int)fabs(start);
		if ((int)start != start) parts_x += 1;
	}
	else
	{
		parts_x = (int)fabs(end);
		if ((int)end != end) parts_x += 1;
	}
	size_of_parts_x = (Width / 2 - 25) / parts_x;

	parts_y = 0;
	if (((type_of_function == 1) && (N == 0)) || ((type_of_function == 2) && ((a == 0) || (b == 0))) || ((type_of_function == 3) && ((a == 0) || (b == 0) || (c == 0))) || ((type_of_function == 4) && (a == 0)) || (((type_of_function == 5) || (type_of_function == 6)) && ((a == 0) || (b == 0))))
	{
		cout << endl;
		cout << "Графиком данной фукции будет явлляться прямая, параллельная оси Ох.";
		if ((int)coefficients[0] != coefficients[0]) parts_y += (int)fabs(coefficients[0]) + 1;
		else parts_y = fabs(coefficients[0]) + 1;
		size_of_parts_y = (Height / 2 - 25) / parts_y;
	}
	else
	{
		if (fabs(min_y) > fabs(max_y))
		{
			parts_y = (int)fabs(min_y);
			if ((int)min_y != min_y) parts_y += 1;
		}
		else
		{
			parts_y = (int)fabs(max_y);
			if ((int)max_y != max_y) parts_y += 1;
		}
		size_of_parts_y = (Height / 2 - 25) / parts_y;
	}

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow(u8"График функции", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	SDL_RenderDrawLine(renderer, Width / 2, 10, Width / 2, Height - 10);
	SDL_RenderDrawLine(renderer, Width / 2, 10, Width / 2 - 5, 20);
	SDL_RenderDrawLine(renderer, Width / 2, 10, Width / 2 + 5, 20);
	for (int i = 1; i <= parts_y; i++) SDL_RenderDrawLine(renderer, Width / 2 - 3, Height / 2 - i * size_of_parts_y, Width / 2 + 3, Height / 2 - i * size_of_parts_y);
	for (int i = 1; i <= parts_y; i++) SDL_RenderDrawLine(renderer, Width / 2 - 3, Height / 2 + i * size_of_parts_y, Width / 2 + 3, Height / 2 + i * size_of_parts_y);

	SDL_RenderDrawLine(renderer, 10, Height / 2, Width - 10, Height / 2);
	SDL_RenderDrawLine(renderer, Width - 20, Height / 2 - 5, Width - 10, Height / 2);
	SDL_RenderDrawLine(renderer, Width - 20, Height / 2 + 5, Width - 10, Height / 2);
	for (int i = 1; i <= parts_x; i++) SDL_RenderDrawLine(renderer, Width / 2 - i * size_of_parts_x, Height / 2 - 3, Width / 2 - i * size_of_parts_x, Height / 2 + 3);
	for (int i = 1; i <= parts_x; i++) SDL_RenderDrawLine(renderer, Width / 2 + i * size_of_parts_x, Height / 2 - 3, Width / 2 + i * size_of_parts_x, Height / 2 + 3);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

	SDL_Point POINTS_1[750];
	for (int i = 0; i < count_1; i++)
	{
		POINTS_1[i].x = (int)(Width / 2 + points_1[i].x * size_of_parts_x);
		POINTS_1[i].y = (int)(Height / 2 - points_1[i].y * size_of_parts_y);
	}

	SDL_RenderDrawLines(renderer, POINTS_1, count_1);

	if ((type_of_function == 2) && (b < 0) && ((int)b == b))
	{
		SDL_Point POINTS_2[750];
		for (int i = 0; i < count_1; i++)
		{
			POINTS_2[i].x = (int)(Width / 2 + points_2[i].x * size_of_parts_x);
			POINTS_2[i].y = (int)(Height / 2 - points_2[i].y * size_of_parts_y);
		}

		SDL_RenderDrawLines(renderer, POINTS_2, count_2);
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Поиск корня y=0 на отрезке
void Root_Search(int type_of_function)
{
	int status, N, count;
	double a, b, c, d, plug, coefficients[26], roots[50], start, end, glass, step, first, second;

	plug = 0;

	status = 0;
	Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, plug);

	cout << endl;
	cout << "Введите левую границу диапазона значений x: ";
	Input_validation_double(start);
	cout << "Введите правую границу диапазона значений x: ";
	Input_validation_double(end);
	cout << endl;

	if (start > end)
	{
		glass = start;
		start = end;
		end = glass;
	}

	step = 0.1;

	count = 0;

	for (first = start; first < end; first += step)
	{
		second = first + step;
		if (second > end) second = end;

		if (Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, first) * Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, second) <= 0)
		{
			roots[count] = Dichotomy(type_of_function, status, N, coefficients, a, b, c, d, first, second);
			count += 1;
		}
	}

	if (count == 0) cout << "На выбранном вами диапазоне значений x корни уравнения отсутствуют.";
	else
	{
		cout << "Корни уравнения, с учётом выбранного вами диапазона значений x: ";
		for (int i = 0; i < count; i++) cout << round(roots[i] * 100) / 100 << " ";
	}
}

// Поиск экстремумов на отрезке
void Extremum(int type_of_function)
{
	int status, N, count_max, count_min;
	double a, b, c, d, plug, coefficients[26], maximum[20], minimum[20], start, end, glass, step, first, second, critical_point, extremum;
	bool flag;

	if (type_of_function == 3) cout << "Выбранная вами показательная функция монотонна на всей области определения.";
	if (type_of_function == 4) cout << "Выбранная вами логарифмическая функция монотонна на всей области определения.";

	if ((type_of_function != 3) && (type_of_function != 4))
	{
		plug = 0;

		status = 0;

		Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, plug);

		if (((type_of_function == 1) && (N != 0) && (N != 1)) || ((type_of_function == 2) && (b > 0) && ((int)b == b) && ((int)b % 2 == 0)) || (type_of_function == 5) || (type_of_function == 6))
		{
			cout << endl;
			cout << "Введите левую границу диапазона значений x: ";
			Input_validation_double(start);
			cout << "Введите правую границу диапазона значений x: ";
			Input_validation_double(end);
			cout << endl;

			if (start > end)
			{
				glass = start;
				start = end;
				end = glass;
			}

			step = 0.1;

			count_max = 0;
			count_min = 0;

			for (first = start; first < end; first += step)
			{
				second = first + step;
				if (second > end) second = end;

				status = -1;
				if (Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, first) * Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, second) <= 0)
				{
					status = 1;

					critical_point = Dichotomy(type_of_function, status, N, coefficients, a, b, c, d, first, second);
					extremum = Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, critical_point);

					if ((Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, critical_point + 0.3) < extremum) && (Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, critical_point - 0.3) < extremum))
					{
						if (((type_of_function == 5) || (type_of_function == 6)) && (count_max == 1));
						else
						{
							flag = false;
							for (int i = 0; i < count_max; i++) if (maximum[i] == extremum) flag = true;
							if (flag == false)
							{
								maximum[count_max] = extremum;
								count_max += 1;
							}
						}
					}

					else if ((Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, critical_point + 0.3) > extremum) && (Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, critical_point - 0.3) > extremum))
					{
						if (((type_of_function == 5) || (type_of_function == 6)) && (count_min == 1));
						else
						{
							flag = false;
							for (int i = 0; i < count_min; i++) if (minimum[i] == extremum) flag = true;
							if (flag == false)
							{
								minimum[count_min] = extremum;
								count_min += 1;
							}
						}
					}
				}
			}

			if (count_max + count_min == 0) cout << "На выбранном вами диапазоне значений x экстремумы отсутствуют.";
			else
			{
				if (count_max == 0) cout << "На выбранном вами диапазоне значений x максимумы отсутствуют.";
				else
				{
					cout << "Максимумы, с учётом выбранного вами диапазона значений x: ";
					for (int i = 0; i < count_max; i++) cout << maximum[i] << " ";
				}

				cout << endl << endl;

				if (count_min == 0) cout << "На выбранном вами диапазоне значений x минимумы отсутствуют.";
				else
				{
					cout << "Минимумы, с учётом выбранного вами диапазона значений x: ";
					for (int i = 0; i < count_min; i++) cout << minimum[i] << " ";
				}
			}
		}

		else cout << endl << "С учётом введёныных данных выбранная вами функция монотонна на всей области определения.";
	}
}

// Дихотомия
double Dichotomy(int type_of_function, int& status, int& N, double* coefficients, double& a, double& b, double& c, double& d, double first, double second)
{
	double half = (first + second) / 2;
	if ((Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, half) == 0) || ((second - first) / 2 < E)) return half;
	if (Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, first) * Function_Generator(type_of_function, status, N, coefficients, a, b, c, d, half) < 0) return Dichotomy(type_of_function, status, N, coefficients, a, b, c, d, first, half);
	return Dichotomy(type_of_function, status, N, coefficients, a, b, c, d, half, second);
}