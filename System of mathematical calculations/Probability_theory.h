//Гришина Анастасия
#pragma once

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

#if defined(max)
#undef max
#endif

void Probability_theory();

void Input_1(int &m, int n);
void Input_2(int &n);
void Probability(int m, int n);

void Input_values(int *values, double *probabilities, int &size);
double Calculate_mean(int *values, double *probabilites, int size);
double Calculate_variance(int *values, double *probabilities, int size, double mean);