#include "pch.h"
#include <iostream>

//produced the volume and area from  
extern "C" bool SphereAreaAndVolume(double radius, double* sa, double* v);

int main()
{

	double radius = 0;
	double sa =-1;
	double v = -1; 

	bool rv = SphereAreaAndVolume(radius, &sa, &v);
	printf("rc: %8.2lf, %8.2lf", sa, v);
}

// I'm still generally confused on when to use fmulp and fmul. I understand the differentce, but not when to use one over 
// the other 