//Ушенин Евгений
#pragma once

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

#if defined(max)
#undef max
#endif

// Параметры многочлена
struct  Data
{
	double *FirstPolynom;
	int FPMaxDegree;
	double *SecondPolynom;
	int SPMaxDegree;
	double *EndPolynom;
	int EPMaxDegree;
};

void intInputValidation(int &data);
void doubleInputValidation(double &data);

void Polynomial();

void PolynomInput(Data &Polynom, const int &PolynomNum);

void PolynomOutput(const double *EndPolynom, const int &EPMaxDegree);

void Addition(Data &Polynom);
void Subtraction(Data &Polynom);
void Multiplication(Data &Polynom);
void Division(Data &Polynom);
void NumberMultiplication(Data &Polynom);
void Derivate(Data &Polynom);

void MemoryClean(Data &Polynom, const int &PolynomNum);