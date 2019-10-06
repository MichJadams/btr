// pointers and arrays 

#include <stdio.h>

void main()
{
	// array names are actually pointers to the first element 
	int arr[] = { 1,2,3,4,5,6 }; 

	// pointer to the first element in the array
	int* p = arr; 

	// these are all equivalent. The same is true for strings in C

	printf("%p \n", &arr[0]);
	printf("pointer %p \n", p);
	printf("pointer array address %p\n ", arr);
	printf("----");
	p++; // we can inclement the pointer and get the second element in the array
	printf("pointer %p \n", p);
	printf("%p \n", &arr[1]);

	for (int i = 0; i < 6; i++) 
	{
		printf("%d, ", arr[i]);
	}
}