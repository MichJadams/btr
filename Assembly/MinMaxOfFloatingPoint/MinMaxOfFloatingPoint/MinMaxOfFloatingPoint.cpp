// MinMaxOfFloatingPoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
extern "C" bool CallMinMax(const float *a, int n, float *min, float *max);
int main()
{
	float a[] = { 10,9,7,-34,10 };
	const int n = sizeof(a) / sizeof(float);

	float min, max; 

	CallMinMax(a, n, &min, &max);
	for (int i = 0; i < n; i++) 
	{

		printf("%8.2f",a[i]);
	}
	printf("\n");
	printf("min: %g max: %g", min, max);

}

