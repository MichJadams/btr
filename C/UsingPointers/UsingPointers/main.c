#include <stdio.h> 

void main()
{
	int a = 14; 
	int* p = &a; 
	int b = 100; 

	printf("address for a is %p\n", &a);
	printf("address for p is %p\n", p); // p is pointing to a

	printf("a has value = %d\n", a);
	printf("p has value = %d in hex = %X\n", p, p );

	//what is the value at the address pointed to by (p)?
	printf("p is pointing to the address with the contents %d\n", *p);

	// start (*) can be translated as "contents of"

	*p = 15;
	printf("p is pointing to the address with the contents %d\n", *p);
	printf("a now equals %d\n", a);

	p = &b; 

	printf("now p has been redefined to point to the address %p\n", p);
	printf("b has the address %p\n", &b);
}