#include <stdio.h>

int merge(int* lptr, int* rptr, int* resptr, int resultLength)
{
	// currently merges two equal length arrays into a resulting array  
	int leftIndex = 1;
	int rightIndex = 1;
	int leftSize = lptr[0]; 
	int rightSize = rptr[0];

	for (int i = 0; i < resultLength; i++)
	{
		// what happends here is that leftIndex is incrmented and now points to nothing memory
		// maybe I can do something smart here, like make the first element of every array it's size. 
		// And make arrays 1 indexed. 

		if (leftIndex < leftSize && (lptr[leftIndex] < rptr[rightIndex]))
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
}

main()
{
	int left[] = { 3,3,5 }; // the first element of each array is the array's size 
	int right[] = { 3,7,8 }; // the first element of each array is the array size
	int result[4];
	int resultLength = 4;

	merge(&left, &right, &result, resultLength);

	for (int i = 0; i < 4; i++)
	{
		printf("index %d, element %d\n", i, result[i]);
	}
}
