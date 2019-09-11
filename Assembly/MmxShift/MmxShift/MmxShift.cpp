#include "pch.h"
#include <iostream>
#include "MmxVal.h"

enum MmxShiftOp : unsigned int
{
	psllw,  // shift left logical word 
	psrlw,	// shift right logical word 
	psraw,  // shift right arithmatic word 
	pslld,	// shift left logical dword 
	psrld,	// shift right logical double word 
	psrad,	// shift right arithmatic dword 
};

extern "C" bool MmxShiftAsm(MmxVal x, MmxShiftOp shiftOp, int count, MmxVal *b);
void MmxShiftDwords(void);
void MmxShiftWords(void);

int main()
{
	MmxShiftWords();
	MmxShiftDwords();
	return 0;
}

void MmxShiftWords(void)
{
	MmxVal a,b;
	int count; 
	char buff[256];

	a.u16[0] = 0x1234;
	a.u16[1] = 0xff00;
	a.u16[2] = 0x00cc;
	a.u16[3] = 0x8000;
	count = 2;

	MmxShiftAsm(a, MmxShiftOp::psllw, count, &b);
	printf("\nResult for psllw - count = %d\n", count);
	printf("a: %s \n", a.ToString_x16(buff, sizeof(buff)));
	printf("b: %s \n", b.ToString_x16(buff, sizeof(buff)));

	MmxShiftAsm(a, MmxShiftOp::psrlw, count, &b);
	printf("\nResult for psrlw - count = %d\n", count);
	printf("a: %s \n", a.ToString_x16(buff, sizeof(buff)));
	printf("b: %s \n", b.ToString_x16(buff, sizeof(buff)));

	MmxShiftAsm(a, MmxShiftOp::psraw, count, &b);
	printf("\nResult for psraw - count = %d\n", count);
	printf("a: %s \n", a.ToString_x16(buff, sizeof(buff)));
	printf("b: %s \n", b.ToString_x16(buff, sizeof(buff)));

}
void MmxShiftDwords(void)
{
	MmxVal a, b; 
	int count; 
	char buff[256];

	a.u32[0] = 0x00010001; 
	a.i32[1] = 0x800080000; 
	count = 3;

	MmxShiftAsm(a, MmxShiftOp::pslld, count, &b);
	printf("\nResult for pslld - count = %d\n", count);
	printf("a: %s \n", a.ToString_x32(buff, sizeof(buff)));
	printf("b: %s \n", b.ToString_x32(buff, sizeof(buff)));

	MmxShiftAsm(a, MmxShiftOp::psrld, count, &b);
	printf("\nResult for psrld - count = %d\n", count);
	printf("a: %s \n", a.ToString_x32(buff, sizeof(buff)));
	printf("b: %s \n", b.ToString_x32(buff, sizeof(buff)));

	MmxShiftAsm(a, MmxShiftOp::psrad, count, &b);
	printf("\nResult for psrad - count = %d\n", count);
	printf("a: %s \n", a.ToString_x32(buff, sizeof(buff)));
	printf("b: %s \n", b.ToString_x32(buff, sizeof(buff)));
}
