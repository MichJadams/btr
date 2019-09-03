#include "pch.h"
#include <iostream>

extern "C" int signedMinA(int a, int b, int c); //conditional jumps
extern "C" int signedMaxA(int a, int b, int c); 

extern "C" int signedMinB(int a, int b, int c); // conditional moves 
extern "C" int signedMaxB(int a, int b, int c);
int main()
{
	int resultMinA = signedMinA(10, 11, 12);
	int resultMaxA = signedMaxA(10, 11, 12);
	int resultMinB = signedMinB(10, 11, 12);
	int resultMaxB = signedMaxA(10, 11, 12);

	printf("result min for a: %4d \n",resultMinA);
	printf("result max for a: %4d \n", resultMaxA);
	printf("result min for b: %4d \n", resultMinB);
	printf("result max for b: %4d \n", resultMaxB);

}


