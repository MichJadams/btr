#include "pch.h"
#include <iostream>
extern "C" int IntegerMulDiv(int a, int b, int* prod, int* quo, int* rem);

int main()
{
	int a = -31; 
	int b = 9; 

	int prod = 0; 
	int quo = 0; 
	int rem = 0; 

	int result = IntegerMulDiv(a, b, &prod, &quo, &rem);

	printf("input a: %4d b: %4d \n", a, b);
	printf("output restult: %4d \n", result);
	printf("output prod: %4d quo: %4d rem: %4d \n", prod, quo, rem);

	return 0; 
}


