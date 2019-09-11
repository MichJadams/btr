

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
void MmxAddBytes(void);
int main()
{
	MmxAddBytes();
}

void MmxAddBytes(void)
{
	MmxVal a, b, c;
	char buff[256]; 
	// packed byte addition - signed integers 
	a.i8[0] = 50;	b.i8[0] = 30;
	a.i8[1] = 80;	b.i8[1] = 64;
	a.i8[2] = -27;	b.i8[2] = -32;
	a.i8[3] = -70;	b.i8[3] = -80;

	a.i8[4] = -42;	b.i8[4] = 90;
	a.i8[5] = 60;	b.i8[5] = -85;
	a.i8[6] = 64;	b.i8[6] = 90;
	a.i8[7] = 100;	b.i8[7] = -30;

	printf("\n\n Packed Byte Addition - signed integers\n");
	printf("a: %s\n", a.ToString_i8(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i8(buff, sizeof(buff)));

	// add signed byte 
	c = MmdAdd(a, b, MmxAddOp::paddsb);
	printf("\n paddsp result\n");
	printf("c: %s\n", c.ToString_i8(buff, sizeof(buff)));

	// unsigned packed byte addition
	a.u8[0] = 50;	b.u8[0] = 30;
	a.u8[1] = 80;	b.u8[1] = 64;
	a.u8[2] = 132;	b.u8[2] = 32;
	a.u8[3] = 120;	b.u8[3] = 80;

	a.u8[4] = 42;	b.u8[4] = 90;
	a.u8[5] = 60;	b.u8[5] = 85;
	a.u8[6] = 64;	b.u8[6] = 90;
	a.u8[7] = 100;	b.u8[7] = 30;

	printf("\n\n Packed Byte Addition - unsigned integers\n");
	printf("a: %s\n", a.ToString_u8(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_u8(buff, sizeof(buff)));

	// add signed byte 
	c = MmdAdd(a, b, MmxAddOp::paddusp);
	printf("\n paddusp result\n");
	printf("c: %s\n", c.ToString_u8(buff, sizeof(buff)));

	// add signed byte 
	printf("\n\n Packed Byte Addition - wraped around \n");
	printf("a: %s\n", a.ToString_x8(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x8(buff, sizeof(buff)));

	c = MmdAdd(a, b, MmxAddOp::paddb);
	printf("\n paddsp result\n");
	printf("c: %s\n", c.ToString_i8(buff, sizeof(buff)));


}
