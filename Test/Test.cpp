// Test.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include <windows.h>
#include <shlwapi.h>
#include "TestDll.h"

typedef void (*PFunction_GetTest)(ITest**);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	TCHAR modulePath[MAX_PATH] = { 0 };
	GetModuleFileName(nullptr, modulePath, MAX_PATH);
	PathRemoveFileSpec(modulePath);
	_tcscat(modulePath, _T("\\1.0.0.1"));
	SetCurrentDirectory(modulePath);

	HMODULE hDll = LoadLibrary(_T("TestDll.dll"));
	if (hDll)
	{
		PFunction_GetTest pFunctionGetTest = (PFunction_GetTest)GetProcAddress(hDll, "GetTest");
		ITest* pTest = nullptr;
		if (pFunctionGetTest)
		{
			pFunctionGetTest(&pTest);
			if (pTest)
			{
				pTest->Init();
				pTest->Uninit();

			}
		}
		
		FreeLibrary(hDll);

	}
	
    return 0;
}


