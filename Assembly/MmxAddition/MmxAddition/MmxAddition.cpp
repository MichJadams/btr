

#include "pch.h"
#include <iostream>
#include "MmxVal.h"

enum MmxAddOp : unsigned int
{
	paddb,		// packed bite addition with wraparound
	paddsb,		// packed byte addition with signed saturdation 
	paddusp,	// packed byte addition with unsigned saturdation
	paddw,		//packed word addition with wraparound
	paddsw,		// packed word addition with signed saturdation
	paddusw,	// packed word addition with unsigned saturation 
	paddd		// packled doubleword addition with wraparound 
};

extern "C" MmxVal MmdAdd(MmxVal a, MmxVal b, MmxAddOp op);

int main()
{
    std::cout << "Hello World!\n"; 
}
