//Выродова Елизавета
#pragma once

#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

#if defined(max)
#undef max
#endif

// Элементы комбинаторики
struct Elements
{
	int element_1;
	int element_2;
	int num_ways;
};

void Check(int &a);

void Combinatorics();

void Place_with_repet();
void Place_without_repet();
void Combin_with_repet();
void Combin_without_repet();
void Permutations_with_repet();
void Permutations_without_repet();

int fc(int a);