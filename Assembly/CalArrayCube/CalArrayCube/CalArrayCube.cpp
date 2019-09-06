
#include "pch.h"
#include <iostream>

int x[3][2]; //arrays are stored with row major ordering 

void calArrayCub(int *y, const int* x, int numOfRows, int numOfColumns)
{
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfColumns; j++)
		{
			int k = i * numOfColumns + j;
			y[k] = x[k] * x[k]*x[k];

		}
	}
}
int main()
{
	const int nRows = 4; 
	const int nCols = 3; 
	int x[nRows][nCols] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
	int y[nRows][nCols];
	calArrayCub(&y[0][0], &x[0][0], nRows, nCols);

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			printf("(%2d, %2d) : %6d, %6d\n", i, j, x[i][j], y[i][j]);

		}
	}
	return 0; 
}
