// ArraySquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
extern "C" int squarArrayAsm(int* y, int*x, int n);

int calculatArraySquaresCpp(int* y, int* x, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		y[i] = x[i] * x[i];
		sum += y[1];
	}
	return sum;
}

int main()
{
	int x[] = { 1,2,3 };
	const int n = sizeof(x) / sizeof(int);
	int y1[n];
	int y2[n];


	int cppSum = calculatArraySquaresCpp(y1, x, n);
	int asmSum = squarArrayAsm(y2, x, n);

	printf("cpp sum: %4d", cppSum);
	printf("asm sum: %4d", asmSum);

	for (int i = 0; i < n; i++)
	{
		printf("y1 = %4d y2 = %4d \n", y1[i], y2[i]);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
