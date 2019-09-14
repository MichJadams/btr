// SseFpArithmatic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

extern "C" void SseArithmetriicOpAsmFloat(float a, float b, float c[8]);
extern "C" void SseArithmetriicOpAsmDouble(double a, double b, double c[8]);
void SseSingPercisionTest(void);
void SseDoublePercisionTest(void);

int main()
{
	SseSingPercisionTest();
	SseDoublePercisionTest();
}
void SseSingPercisionTest(void)
{
	float a = 2.5f; 
	float b = -7.6f;
	float c[8]; 

	SseArithmetriicOpAsmFloat(a, b, c);
	printf("\n---------Results from single percision-----------\n");
	printf("a: %.6f\n", a);
	printf("b: %.6f\n", b);

	printf("add:		%.6f\n", c[0]);
	printf("sub:		%.6f\n", c[1]);
	printf("mul:		%.6f\n", c[2]);
	printf("div:		%.6f\n", c[3]);
	printf("min:		%.6f\n", c[4]);
	printf("max:		%.6f\n", c[5]);
	printf("abs of b :	%.6f\n", c[6]);
	printf("sqrt of b:	%.6f\n", c[7]);
}

void SseDoublePercisionTest(void)
{
	double a = 3.14159265;
	double b = 2.71828182845904523;
	double c[8];

	SseArithmetriicOpAsmDouble(a, b, c);
	printf("\n---------Results from double percision-----------\n");
	printf("a: %.14f\n", a);
	printf("b: %.14f\n", b);

	printf("add:		%.14f\n", c[0]);
	printf("sub:		%.14f\n", c[1]);
	printf("mul:		%.14f\n", c[2]);
	printf("div:		%.14f\n", c[3]);
	printf("min:		%.14f\n", c[4]);
	printf("max:		%.14f\n", c[5]);
	printf("abs of b :	%.14f\n", c[6]);
	printf("sqrt of b:	%.14f\n", c[7]);
}
