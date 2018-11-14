// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "TestDll.h"

class Test : public ITest
{
public:
	virtual void Init()
	{
		MessageBox(nullptr, TEXT("Test::Init"), TEXT("Test::Init"), MB_OK);
	}

	virtual void Uninit()
	{
		MessageBox(nullptr, TEXT("Test::Uninit"), TEXT("Test::Uninit"), MB_OK);
	}
};

Test g_test;

void GetTest(ITest** pTest)
{
	*pTest = &g_test;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

