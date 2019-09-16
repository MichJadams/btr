#include "pch.h"
#include <iostream>
#include "XmmVal.h"
#include <math.h>

extern "C" void SsePackedInt16_add(const XmmVal * a,const XmmVal *b, XmmVal c[2]);
extern "C" void SsePackedInt32_sub(const XmmVal * a, const XmmVal *b, XmmVal *c);
extern "C" void SsePackedInt32_mul(const XmmVal * a, const XmmVal *b, XmmVal c[2]);

int main()
{
	_declspec(align(16)) XmmVal a;
	_declspec(align(16)) XmmVal b;
	_declspec(align(16))  XmmVal c[2];
	int count; 
	char buff[256]; 

	a.r32[0] = 10; 
	a.r32[1] = 10;
	a.r32[2] = 10;
	a.r32[3] = 10;


	b.r32[0] = 10;
	b.r32[1] = 30;
	b.r32[2] = 40;
	b.r32[3] = 50;


	SsePackedInt16_add(&a, &b, c);
	printf("result: \n");
	printf("c: %s\n", c[0].ToString_r32(buff, sizeof(buff)));
	printf("c: %s\n", c[1].ToString_r32(buff, sizeof(buff)));
	printf("c: %s\n", c[2].ToString_r32(buff, sizeof(buff)));
	printf("c: %s\n", c[3].ToString_r32(buff, sizeof(buff)));
	printf("c: %s\n", c[4].ToString_r32(buff, sizeof(buff)));
	printf("c: %s\n", c[5].ToString_r32(buff, sizeof(buff)));
	printf("c: %s\n", c[6].ToString_r32(buff, sizeof(buff)));




}
