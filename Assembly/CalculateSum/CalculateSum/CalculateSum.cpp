#include "pch.h"
#include <iostream>

extern "C" int AdderAsm(int a, int b, int c);
int AdderCpp(int a, int b, int c);

int main()
{
	int a = 17, b = 11, c = 14; 

	int sum = AdderAsm(a, b, c);
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("c: %d\n", c);
	printf("sum: %d\n", sum);


	//int sum = AdderCpp(a, b, c);

	return 0;

}

int AdderCpp(int a, int b, int c)
{
	return a + b + c;
}
