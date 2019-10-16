#include <stdio.h>

enum ValueType 
{
	CHAR, 
	INT, 
	FLOAT, 
	STRING
};

// switches on the value type passed in
void PrintValue(void * p, enum ValueType type)
{
	switch (type)
	{
	case CHAR: 
		printf("character: %c\n", *(char*) p);
		break;
	case INT:
		printf("integer: %d\n", *(int*)p);
		break;
	case FLOAT: 
		printf("float: %f\n", *(float*)p);
		break;
	case STRING:
		printf("string: %s", (char*)p);
		break;
	default: 
		printf("unexpected\n");
	}
}
// Using void poiunter in C/C++
void main()
{
	
	int*p; 
	*p = 100;
	printf("%d", *p);


	//
	//
	//int a = 100; 
	//char c = 'h'; 
	//float pi = 3.14f; 
	//
	//int* pa = &a; 
	//char* pc = &c; 
	//float* ppi = &pi; 

	//void *p;

	//// void pointers can be used as generic pointers
	//p = pa; 
	//p = &a; 
	//p = &c; 
	//p = &pi;

	//PrintValue(&a, INT);
	//PrintValue(&c, CHAR);
	//PrintValue(ppi, FLOAT);
	//PrintValue("hello", STRING);
}