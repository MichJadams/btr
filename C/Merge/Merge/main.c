#include <stdio.h>

int merge(int* lptr, int* rptr, int rightSize, int leftSize, int* resptr, int resultLength)
{
	// currently merges two equal length arrays into a resulting array  
	int leftIndex = 0;
	int rightIndex = 0;

	for (int i = 0; i < resultLength; i++)
	{
		if (leftIndex <  leftSize && rightIndex < rightSize)
		{
			if (lptr[leftIndex] < rptr[rightIndex])
			{

				resptr[i] = lptr[leftIndex];
				leftIndex += 1;
			}
			else 
			{
				resptr[i] = rptr[rightIndex];
				rightIndex += 1;
			}
		}
		else 
		{
			if (leftIndex < leftSize)
			{
				resptr[i] = lptr[leftIndex];
				leftIndex += 1;
			}
			if (rightIndex < rightSize)
			{
				resptr[i] = rptr[rightIndex];
				rightIndex += 1;
			}
		}
	}
}

sort(int *ptrArr, int arrLength)
{
	if (arrLength < 2)
	{
		if (ptrArr[0] > ptrArr[1])
		{
			int temp = ptrArr[0];
			ptrArr[0] = ptrArr[1];
			ptrArr[1] = temp;
		}
	}
}

mergeSort(int *ptrArr, int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		// I duno
	}

	merge();
}

main()
{
	// example data 
	int left[] = { 1,10 };  
	int right[] = { 7,8,10 }; 
	int leftSize = 2;
	int rightSize = 3;
	int result[5];
	int resultLength = 5;

	merge(&left, &right, rightSize, leftSize, &result, resultLength);

	for (int i = 0; i < 4; i++)
	{
		printf("index %d, element %d\n", i, result[i]);
	}
}
