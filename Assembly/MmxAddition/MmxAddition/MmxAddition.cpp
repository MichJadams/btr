

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
void MmxAddWord(void);
void MmdDoubleWorkAddition(void);

int main()
{
	MmxAddBytes();
	MmxAddWord();
	MmdDoubleWorkAddition();
	return 0;
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
	printf("\n paddb result\n");
	printf("c: %s\n", c.ToString_i8(buff, sizeof(buff)));
}

void MmxAddWord(void)
{
	MmxVal a, b, c; 
	char buff[256];
	// packed word addition - signed integers 
	a.i16[0] = 500;		b.i16[0] = 830;
	a.i16[1] = 30000;	b.i16[1] = 5000;
	a.i16[2] = -270;	b.i16[2] = -320;
	a.i16[3] = -7000;	b.i16[3] = -80000;

	printf("\n\n Packed word Addition - signed integers\n");
	printf("a: %s\n", a.ToString_i16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i16(buff, sizeof(buff)));


	// add signed byte wrap with signed saturation
	c = MmdAdd(a, b, MmxAddOp::paddsw);
	printf("\n paddsw result\n");
	printf("c: %s\n", c.ToString_i16(buff, sizeof(buff)));

	// add signed byte wrap around 
	c = MmdAdd(a, b, MmxAddOp::paddw);
	printf("\n paddw result\n");
	printf("c: %s\n", c.ToString_u16(buff, sizeof(buff)));
	// now for unsigned saturation
	a.u16[0] = 500;		b.u16[0] = 830;
	a.u16[1] = 48000;	b.u16[1] = 5000;
	a.u16[2] = 270;		b.u16[2] = 320;
	a.u16[3] = 7000;	b.u16[3] = 80000;

	c = MmdAdd(a, b, MmxAddOp::paddusw);
	printf("\n paddusw result\n");
	printf("c: %s\n", c.ToString_u16(buff, sizeof(buff)));
}
void MmdDoubleWorkAddition(void)
{
	MmxVal a, b, c;
	char buff[256];

	a.i64 = 50000;		b.i64 = 5000;

	printf("\n\n Packed word Addition - signed integers\n");
	printf("a: %s\n", a.ToString_i64(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i64(buff, sizeof(buff)));

	c = MmdAdd(a, b, MmxAddOp::paddd);
	printf("\n paddd result\n");
	printf("c: %s\n", c.ToString_i64(buff, sizeof(buff)));
}
