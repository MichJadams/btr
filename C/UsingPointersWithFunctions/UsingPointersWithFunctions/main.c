#include <stdio.h> 

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}

void main()
{
	int a = 15;
	int b = 10;
	printf("this is the value at a %d\n", a);
	printf("this is the value at b %d\n", b);
	printf("------------------------------\n");

	// The address of 'a' changes if you pass it directly. Because it is placed on the stack. 
	swap(&a,&b); // gotta pass em pointers if you want the value change to be 'global'
	printf("this is the value at a %d\n", a);
	printf("this is the value at b %d\n",b);

};

