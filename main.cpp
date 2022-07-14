#include <Windows.h>
#include "memhack.h"
#include "patternscan.h"
#include "processtools.h"
#include "patternscanInternal.h"

DWORD WINAPI Main(HMODULE hModule)
{
	void* addr = ScanModIn((char*)"\x29\x7b\x00\x8b\xc7", (char*)"xx?xx", "ac_client.exe");
	
	Nop(addr, 5);

	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, hinstDLL, 0, 0);
		if (hThread) CloseHandle(hThread);
	}

	return true;
}