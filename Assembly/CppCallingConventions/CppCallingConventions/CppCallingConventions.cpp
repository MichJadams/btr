#include "pch.h"
#include <iostream>

extern "C" void calculateSum(int a, int b, int c, int* s1, int* s2, int* s3);
int main()
{
	int a = 2, b = 3, c = 4; 
	int s1, s2, s3;

	calculateSum(a,b,c,&s1, &s2, &s3);
	printf("s1: %4d, s2: %4d, s3: %4d", s1, s2, s3);

	return 0;
}
