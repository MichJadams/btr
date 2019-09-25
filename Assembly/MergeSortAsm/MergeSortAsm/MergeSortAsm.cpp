// MergeSortAsm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" void MergeSort(int *input, const int *output, int length);
int main()
{
	std::cout << "Hello World!\n";
	printf("merge sorting\n");

	const int arrayLength = 10;
	int input[arrayLength] = { 1,5,4,3,10,5,4,3,2,5 };
	int output[arrayLength];

	MergeSort(input, output, arrayLength);

	for (int i = 0; i < arrayLength; i++)
	{
		printf("element %d value = %d \n", i, output[i]);
	}
}

