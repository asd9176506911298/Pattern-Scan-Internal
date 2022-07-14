#pragma once

#include <Windows.h>
#include <TlHelp32.h>

DWORD GetProcId(const wchar_t* procName);

MODULEENTRY32 GetModule(DWORD dwProcID, const wchar_t* moduleName);