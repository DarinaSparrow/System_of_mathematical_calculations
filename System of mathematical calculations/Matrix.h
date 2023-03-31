//Соленкова Анна
#pragma once

#include <iostream>
#include <windows.h>

using namespace std;

#define Nmax 100
#define Mmax 100

#if defined(max)
#undef max
#endif

// Элементы матрицы
struct matrix
{
	double m[Nmax][Mmax];
};

void Check_int(int &data);
void Check_double(double& data);

void Matrix();

void Input(int &M, int &N, struct matrix &element);

void Addition(int M_1, int N_1, struct matrix &element_1, int M_2, int N_2, struct matrix &element_2, struct matrix &element_res);
void Subtraction(int M_1, int N_1, struct matrix &element_1, int M_2, int N_2, struct matrix &element_2, struct matrix &element_res);
void Multiplication(int M_1, int N_1, struct matrix &element_1, int M_2, int N_2, struct matrix &element_2, struct matrix &element_res);
void Multiplication_with_Num(int M, int N, struct matrix &element, struct matrix &element_res);
void Add_with_Num(int M_1, int N_1, struct matrix &element_1, int &M_2, int &N_2, struct matrix &element_2, struct matrix &element_res);
void Transposition(int &M, int &N, struct matrix &element, struct matrix &element_res);
void Inverse_M(int M, int N, struct matrix &element, struct matrix &element_res);
void Determinant(int &M, int &N, struct matrix &element);
double Deter(double m[Nmax][Mmax], int M);

void Output(int M, int N, struct matrix element_res);