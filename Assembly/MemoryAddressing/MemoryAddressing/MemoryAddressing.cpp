#include "pch.h"
#include <iostream>

extern "C" int MemoryAddressing(int i, int *v1, int *v2, int *v3, int *v4);
extern "C" int NumFibVals; 

int main()
{
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0; 
	int result;

	for (int i = 0; i <= NumFibVals; i++)
	{
		result = MemoryAddressing(i, &v1, &v2, &v3, &v4);
		printf("result: %5d	v1: %5d	v2:%5d v3: %5d v4: %5d \n", result, v1,v2,v3,v4);
	}
	return 0;
}

