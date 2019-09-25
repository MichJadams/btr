#include <stdio.h>
main()
{
	int a[] = { 1,5,4,3,7,8 };

	printf("hello world");
	MergeSort(a);
}

int MergeSort(int a[], int l, int m, int r)
{
	int middle = sizeof(a) / sizeof(int) / 2; 
	// get the left half of the array
	int *left = a; 

	// get the right half of the array 
	int *right = a + middle;

}