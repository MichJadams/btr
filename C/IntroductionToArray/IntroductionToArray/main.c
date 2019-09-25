
#include <stdio.h>

int SumElements(int ar[], int size)
{
	int sum = 0; 

	for (int i = 0; i < size; ++i)
	{
		sum += ar[i]; 
	}

	return sum;
}

void PrintArray(int a[], int size)
{

	for (int i = 0; i < 5; i++)
	{
		printf("value at %d is %d\n", i, a[i]);
	}
}

void main()
{
	
	
	int a[] = { 1,2,3,4,5 };

	a[2] = a[2] / 2;

	int sumOne = SumElements(a,5);
	int sum = 0;
	PrintArray(a, 5);
	printf("%d and sum one %d \n", sum, sumOne);

	// passing arrays into functions
	system("pause");
}

