// CountCharactersInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

extern "C" int CountChars_(wchar_t *s, wchar_t c); 

int main(int argc)
{
	wchar_t c; 
	wchar_t *s;
	s = (wchar_t *)L"Four schour and seven seconds ago...";
	c = L's';

	wprintf(L"\nTest string: %s\n", s);

	wprintf(L"	 SearchChar: %c Count: %d \n", c, CountChars_(s, c));


	return 0;
}
