#include "stdafx.h"
#include "Windows.h"
#include "iostream"
using namespace std;

#define OFF	0
#define ON	1

#ifdef USE_VOLATILE
void AcquireLock(volatile LONG& ISign)
{
	while (LSign == OFF);
	ISign = OFF;
}
#else
void AcquireLock(LONG& ISign)
{
	while (ISign == OFF);
	ISign = OFF;
}
#endif

void ReleaseLock(LONG& ISign)
{
	ISign = ON;
}

LONG g_ICSSign = ON;
int g_nValue = 0;

DWORD WINAPI ThreadProc(PVOID pParam)
{
	INT dwCurid = (INT)pParam;

	AcquireLock(g_ICSSign);

	cout << " ==> Thread " << dwCurid << " Enter : " << g_nValue << endl;
	g_nValue++;
	cout << " <== Thread " << dwCurid << " Leave : " << g_nValue << endl;

	ReleaseLock(g_ICSSign);

	return 0;
}

#define MAX_THR_CNT 6
void _tmain()
{
	HANDLE arhThrs[MAX_THR_CNT];
	for (int i = 0; i < MAX_THR_CNT; i++)
	{
		DWORD dwTheaID = 0;
		arhThrs[i] = CreateThread(NULL, 0, ThreadProc, (PVOID)i, 0, &dwTheaID);
	}
	getchar();

	for (int i = 0; i < MAX_THR_CNT; i++)
		CloseHandle(arhThrs[i]);
}

