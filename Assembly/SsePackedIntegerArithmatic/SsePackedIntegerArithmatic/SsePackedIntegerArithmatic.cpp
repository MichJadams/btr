#include "pch.h"
#include <iostream>
#include "XmmVal.h"

extern "C" void SsePackedInt16_add(XmmVal * a, XmmVal *b, XmmVal c[2]);
extern "C" void SsePackedInt32_sub(const XmmVal * a, const XmmVal *b, XmmVal *c);
extern "C" void SsePackedInt32_mul(const XmmVal * a, const XmmVal *b, XmmVal c[2]);

int main()
{
	XmmVal a, b;
	XmmVal c[2];
	int count; 
	char buff[256]; 

	a.i16[0] = 10; 
	a.i16[1] = 10;
	a.i16[2] = 10;
	a.i16[3] = 10;
	a.i16[4] = 10;
	a.i16[5] = 10;
	a.i16[6] = 10;
	a.i16[7] = 10;
	a.i16[8] = 10;
	a.i16[9] = 10;
	a.i16[10] = 10;

	b.i16[0] = 400;
	b.i16[1] = 400;
	b.i16[2] = 400;
	b.i16[3] = 400;
	b.i16[4] = 400;
	b.i16[5] = 400;
	b.i16[6] = 400;
	b.i16[7] = 400;
	b.i16[8] = 400;
	b.i16[9] = 400;
	b.i16[10] = 400;

	SsePackedInt16_add(&a, &b, c);
	printf("result:");
	printf("c: %s", c->ToString_i16(buff, sizeof(buff)));

}
