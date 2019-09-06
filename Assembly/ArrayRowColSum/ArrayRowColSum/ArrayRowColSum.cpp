// ArrayRowColSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
extern "C" int CalcArrayRowColSum(const int* x, int nrows, int ncols, int* row_Sum, int * colSum);

void printArray(const int* x, int nRows, int nCols, int* colsum, int* rowsum);
int main()
{
    std::cout << "Hello World!\n"; 


	const int nRows = 4;
	const int nCols = 5;
	int x[nRows][nCols] = { {1,2,3,5,4},{4,5,6,1,2},{7,8,9,10,2},{10,11,12,1,2} };
	int rowsum[nRows], colsum[nCols];

	CalcArrayRowColSum((const int *)x, nRows, nCols, rowsum, colsum);
	printArray((const int*) x, nRows, nCols,  colsum, rowsum);
	/*for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			printf("(%5d", (const int*)x[i*nCols + j]);

		}
		printf("%5d\n", rowsum[i]);
	}
	printf("\n");
	for (int i = 0; i < nRows; i++)
	{
		printf("%5d", colsum[i]);
	}*/

	return 0;
}

void printArray(const int* x, int nRows, int nCols, int* colsum, int* rowsum)
{

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			printf("(%5d", x[i*nCols + j]);

		}
		printf("%5d\n", rowsum[i]);
	}
	printf("\n");
	for (int i = 0; i < nRows; i++)
	{
		printf("%5d", colsum[i]);
	}
}