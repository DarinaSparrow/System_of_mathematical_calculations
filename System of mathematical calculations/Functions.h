//Корниенко Дарина
#pragma once

#include <iostream>
#include <windows.h>
#include <SDL.h>

using namespace std;

#define Width 900
#define Height 900
#define E 0.001

#if defined(max)
#undef max
#endif

// Координаты точек
struct coordinates
{
	double x;
	double y;
};

void Input_validation_int(int &data);
void Input_validation_double(double &data);

void Functions();

double Function_Generator(int type_of_function, int &status, int &N, double *coefficients, double &a, double &b, double &c, double &d, double x);

double Polynomial_of_degree_N(int &status, int &N, double *coefficients, double x);
double Power_function(int &status, double &a, double &b, double &c, double x);
double Exponential_function(int &status, double &a, double &b, double &c, double &d, double x);
double Logarithmic_function(int &status, double &a, double &b, double &c, double x);
double Sinusoid(int &status, double &a, double &b, double &c, double &d, double x);
double Cosine(int &status, double &a, double &b, double &c, double &d, double x);

void Definite_integral(int type_of_function);
void Function_graph(int type_of_function);
void Root_Search(int type_of_function);
void Extremum(int type_of_function);

double Dichotomy(int type_of_function, int &status, int &N, double *coefficients, double &a, double &b, double &c, double &d, double first, double second);
