#include <stdio.h>
enum Days {
	Sunday, 
	Monday, 
	Tuesday
};

enum Months {
	October = 10, 
	November = 11, 
	December = 12
};
int year = 100; 

void main()
{
	enum Days MyDay; 
	MyDay = Tuesday; 
	enum Months Month; 
	Month = 90; 

	printf("Sunday =  %d\n", MyDay);
	printf("Month = %d\n", Month);
	int year = 101; 
	printf("The year is %d\n", year);

}