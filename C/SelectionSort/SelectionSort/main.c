#include <stdio.h>
void moveMin(int * pArrayToSort, int indexOfElement, int element)
{
	for (int j = indexOfElement; j >= 0; --j)
	{
		// if the element from the outter loop (element) is less than the 
		// current element, have them swap places. 
		if (element < pArrayToSort[j])
		{
			// declare an intermediate temp variable 
			int temp = pArrayToSort[indexOfElement];
			pArrayToSort[indexOfElement] = pArrayToSort[j];
			pArrayToSort[j] = temp;
			indexOfElement = j;
		}
	}
}

void selectionSort(int * pArrayToSort, int arrayToSortLength)
{
	for (int i = 0; i < arrayToSortLength; i++)
	{
		// This functions serves to move the element at i in the array into its proper position 
		// in the left half of the array. 
		moveMin(pArrayToSort, i, pArrayToSort[i]);
	};
}

void main()
{
	int arrayToSort[] = { 10,5,4,3,1,5,2 };
	int arrayToSortLength = sizeof(arrayToSort) / sizeof(int);
	selectionSort(&arrayToSort, arrayToSortLength);

	// code for printing out the sorted array
	printf("the array now looks like this: ");
	for (int i = 0; i < arrayToSortLength; i++)
	{
		printf("%d,", arrayToSort[i]);
	}
}