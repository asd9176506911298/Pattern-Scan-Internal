#pragma once
#include <Windows.h>

void Patch(void* dst, void* src, unsigned int size);

void PatchEx(HANDLE hProcess, void* dst, void* src, unsigned int size);

void Nop(void* dst, unsigned int size);

void NopEx(HANDLE hProcess, void* dst, unsigned int size);