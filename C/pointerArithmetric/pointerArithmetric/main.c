#include <stdio.h>; 

void main()
{
	int a[] = {1, 2, 3, 4, 5};
	int* p = a; 
	// Here is I'm using %d to print the value at the pointer becuase looking at decimal is easier to see
	// than checking arithmatic in hex

	printf("the location in memeory that p is pointing: %d\n", p);
	printf("the conecnts of p: %d\n", *p);
	p++; // in pointer arithmetic the pointer is actually advanced by 1 integer, which is 4 bytes. 
	// this is 1 times the size of the value that the pointer is pointing at. Which is an int. 
	printf("the location in memeory that p is pointing: %d\n", p);
	printf("the conecnts of p: %d\n", *p);
	p++;
	printf("the location in memeory that p is pointing: %d\n", p);
	printf("the conecnts of p: %d\n", *p);

	double aD[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double* pD = aD;
	printf("----------------------\n");

	printf("the location in memeory that p is pointing: %d\n", pD);
	printf("the conecnts of p: %d\n", *pD);
	pD++; // in pointer arithmetic the pointer is actually advanced by 1 double, which is 8 bytes. 
	// this is 1 times the size of the value that the pointer is pointing at. Which is an double. 
	printf("the location in memeory that p is pointing: %d\n", pD);
	printf("the conecnts of p: %d\n", *pD);
	pD++;
	printf("the location in memeory that p is pointing: %d\n", pD);
	printf("the conecnts of p: %d\n", *pD);

	// test
	printf("testing memeory acccess");

	int arr[] = { 1,2,3 };
	int* pointer = arr; 

	printf("pointer address: %p\n", pointer);
	printf("value pointer address: %d\n", *pointer);
	pointer--; 
	printf("pointer address: %p\n", pointer);
	printf("value pointer address: %d\n", *pointer);
	pointer--;
	printf("pointer address: %p\n", pointer);
	printf("value pointer address: %d\n", *pointer); 
	pointer--;
	printf("pointer address: %p\n", pointer);
	printf("value pointer address: %d\n", *pointer);

}