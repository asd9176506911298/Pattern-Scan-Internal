#include "memhack.h"

void Patch(void* dst, void* src, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_READWRITE, &oldprotect);
	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void PatchEx(HANDLE hProcess, void* dst, void* src, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtectEx(hProcess ,dst, size, PAGE_READWRITE, &oldprotect);
	memcpy(dst, src, size);
	VirtualProtectEx(hProcess, dst, size, oldprotect, &oldprotect);
}

void Nop(void* dst, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void NopEx(HANDLE hProcess, void* dst, unsigned int size)
{
	byte* nopArray = new byte[size];
	memset(nopArray, 0x90, size);

	DWORD oldprotect;
	VirtualProtectEx(hProcess, dst, size, PAGE_READWRITE, &oldprotect);
	WriteProcessMemory(hProcess, dst, nopArray, size, 0);
	VirtualProtectEx(hProcess, dst, size, oldprotect, &oldprotect);
	delete[] nopArray;
}