#include <stdio.h>

void main()
{
	printf("hello world!\r\n");
	printf("Char size = %d\n", sizeof(char));
	printf("unsigned Char size = %d\n", sizeof(unsigned char));
	printf("signed Char size = %d\n", sizeof(signed char));
	printf("float size = %d\n", sizeof(float));
	printf("double size = %d\n", sizeof(double));
	printf("double size = %d\n", sizeof(int));
	printf("unsigned int size = %d\n", sizeof(unsigned int));
	printf("signed int size = %d\n", sizeof(signed int));
	printf("short size = %d\n", sizeof(int short unsigned));

	int a = 10;
	printf("address of a %p", &a);


	system("pause");
}