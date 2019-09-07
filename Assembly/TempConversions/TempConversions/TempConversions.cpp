#include "pch.h"
#include <iostream>


extern "C" double FtoCAsm(double degreeF);
extern "C" double CtoFAsm(double degreeC);

int main()
{
	double cel_temp = 29;
	double f_temp = 100;

	printf("cel value: %10f converted value: %10f \n", cel_temp, FtoCAsm(cel_temp));
	printf("f value: %10f converted value: %10.41f\n", f_temp, CtoFAsm(f_temp));

	printf("\n");
	// a loop!

	double deg_vals[] = { 45.7, 40,5, 100, -123, 50 };
	int nf = sizeof(deg_vals) / sizeof(double); 

	for (int i = 0; i < nf; i++)
	{
		double deg_c = FtoCAsm(deg_vals[i]);
		double deg_f = CtoFAsm(deg_vals[i]);

		printf("i: %d originals: %10.4lf f:%10.4lf c:%10.4lf\n",i, deg_vals[i], deg_c, deg_f);
	};

	return 0; 
}

