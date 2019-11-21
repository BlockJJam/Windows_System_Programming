#include "stdafx.h"
#include "Windows.h"
#include "iostream"
using namespacd std;

#define TEST_MODE 3

#if TEST_MODE ==1
volatile int g_x, g_y;
#else
int g_x, g_y;
#endif
int g_a, g_b;

DWORD WINPI TP25(PVOID) 
{
	g_x = 25;
}