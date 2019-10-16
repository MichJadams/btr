
#include <stdio.h>

void main()
{
	int a = 100; 
	int b = 200;
	int* pa = &a; 
	// read these backwards 

	const int* pc = &a;  // pc is a pointer that points to a constant inters 
	int const* pc2 = &a; // pc2 is a pointer to a constant integer, same as above 

	int* const pp = &a; // pp is a constant that is a pointer to an integer 

	const int* const ppc = &a;  // ppc is a constant pointer to an integer that is constant
	int const* const ppc2 = &a; // same a ppc, ppc2 is a constant pointer to a constant integer 

	// using pa, we have no limitations 
	// 1. pa canb change the value of the integer it points to 
	*pa = 101; 
	//2. pa can point to a totally different integer 
	pa = &b; 

	//const int *: a pointer to a constant integer 
	// 1. pa cannot modify or change the value inside the integer it pointer to 
	/* *pc = 10 cannot be done */

	// 2. pc can change to another integer 
	pa = &b;
	// int * const: a const pointer to an integer 
	// 1. can change the integer it points to 
	*pp = 102; 
	// 2. cannot change the value of the pointer 
	/*  error: pp = &b; */

	// constant pointer to a constant integer 
	// can't do anything. Cannot modify the integer or point to another integer 
	/* *ppc = &b; */

	/* ppc = 103; */ 
}