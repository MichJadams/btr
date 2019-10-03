#include <stdio.h>
void moveMin(int * pArrayToSort, int indexOfElement, int element)
{
	for (int i = indexOfElement; i > 0; i --)
	{
		if (element < pArrayToSort[i])
		{
			int temp = pArrayToSort[i]; 
			pArrayToSort[i] = element; 
			pArrayToSort[indexOfElement] = temp; 
			indexOfElement = i;
		}
	}
}

void selectionSort(int * pArrayToSort, int arrayToSortLength)
{
	for (int i = 0; i < arrayToSortLength; i++)
	{
		moveMin(pArrayToSort, i, pArrayToSort[i]);
	};
}

void main()
{
	int arrayToSort[] = { 1,5,2 };
	int arrayToSortLength = sizeof(arrayToSort) / sizeof(int);
	selectionSort(&arrayToSort, arrayToSortLength);
}