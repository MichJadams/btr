# include <stdio.h>
# include <stdlib.h>
int addition(int a, int b)
{
	return a + b; 
}
// main is a procedure because it returns void
// functions return results
void main() {
	
	int a = 10; 
	int b = 20; 

	int result; 

	result = addition(a, b);
	printf("the result %d\n", result);
	system("pause");

}
