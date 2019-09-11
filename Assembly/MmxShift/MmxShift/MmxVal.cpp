#include "pch.h"

#include "MmxVal.h"
#include <cstdio>

char * MmxVal::ToString_i8(char *s, size_t len)
{
	sprintf_s(s, len, "%4d %4d %4d %4d %4d %4d %4d %4d", i8[0], i8[1], i8[2], i8[3], i8[4], i8[5], i8[6], i8[7]);
	return s;
}

char * MmxVal::ToString_i16(char *s, size_t len)
{
	sprintf_s(s, len, "%8d %8d %8d %8d", i16[0], i16[1], i16[2], i16[3]);
	return s;
}

char * MmxVal::ToString_i32(char *s, size_t len)
{
	sprintf_s(s, len, "%12d %12d", i32[0], i32[1]);
	return s;
}

char * MmxVal::ToString_i64(char *s, size_t len)
{
	sprintf_s(s, len, "%16lld", i64);

	return s;
}
// unsigned to string functions

char * MmxVal::ToString_u8(char *s, size_t len)
{
	sprintf_s(s, len, "%4u %4u %4u %4u %4u %4u %4u %4u", u8[0], u8[1], u8[2], i8[3], i8[4], i8[5], i8[6], i8[7]);

	return s;
}

char * MmxVal::ToString_u16(char *s, size_t len)
{
	sprintf_s(s, len, "%8u %8u %8u %8u", u16[0], u16[1], u16[2], u16[3]);

	return s;
}

char * MmxVal::ToString_u32(char *s, size_t len)
{
	sprintf_s(s, len, "%12u %12u", u32[0], u32[1]);

	return s;
}

char * MmxVal::ToString_u64(char *s, size_t len)
{
	sprintf_s(s, len, "%16llu", u64);

	return s;
}

// x values 
char * MmxVal::ToString_x8(char *s, size_t len)
{
	sprintf_s(s, len, "%02x %02x %02x %02x %02x %02x %02x %02x", u8[0], u8[1], u8[2], i8[3], i8[4], i8[5], i8[6], i8[7]);

	return s;
}

char * MmxVal::ToString_x16(char *s, size_t len)
{
	sprintf_s(s, len, "%04x %04x %04x %04x", u16[0], u16[1], u16[2], u16[3]);

	return s;
}

char * MmxVal::ToString_x32(char *s, size_t len)
{
	sprintf_s(s, len, "%08x %08x", u32[0], u32[1]);

	return s;
}

char * MmxVal::ToString_x64(char *s, size_t len)
{
	sprintf_s(s, len, "%016llX", u64);

	return s;
}
