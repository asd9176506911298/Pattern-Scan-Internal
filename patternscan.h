#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include "processtools.h"

void* PatternScan(char* base, size_t size, char* pattern, char* mask);

void* PatternSanEx(HANDLE hProcess, uintptr_t begin, uintptr_t end, char* pattern, char* mask);

void* PatternScannExModule(HANDLE hProcess, wchar_t* procName, wchar_t* module, char* pattern, char* mask);