#include <stdio.h> 

void GetMinMax(int a[], int count, int * pmax, int* pmin)
{
	int max, min; 

	max = min = a[0];

	for (int i = 0; i < count; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		};

		if (a[i] > min)
		{
			min = a[i];
		};
	}

	*pmax = max; 
	*pmin = min;
}

void main()
{
	int arr[] = { 13,12,10,1,4,5 };
	int length = sizeof(arr) / sizeof(int);
	int min;
	int max;

	GetMinMax(arr, length, &max, &min);

	printf("The min is: %d\n", min);
	printf("The max is: %d\n", max);
}
