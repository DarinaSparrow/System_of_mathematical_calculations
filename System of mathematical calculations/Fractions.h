//Гришина Анастасия
#pragma once

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

#if defined(max)
#undef max
#endif

void Fractions();

void input_fraction(int &numerator, int &denominator);
void reduce_fraction(int &numerator, int &denominator);
void action_menu(int &num1, int &den1, int &num2, int &den2);
void output_fraction(int numerator, int denominator);

void add_fractions(int num1, int den1, int num2, int den2);
void subtract_fractions(int num1, int den1, int num2, int den2);
void multiplication_fraction(int num1, int den1, int num2, int den2);
void division_fraction(int num1, int den1, int num2, int den2);
void comparison_fractions(int num1, int den1, int num2, int den2);
void reduce_fraction1(int &numerator, int &denominator);
void decimal(int &numerator, int &denominator);

int gcd(int a, int b);