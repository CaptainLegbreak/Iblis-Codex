#include "D2Client.h"

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, va_list args); // 0x006CC4AC

// 0x0045B960
void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...)
{
    char szBuffer[256];
    va_list args;
    va_start(args, szFormat);
    unsigned long nWritten = wvsprintfA(szBuffer, szFormat, args);
    WriteFile(hFile, szBuffer, nWritten, &nWritten, 0);
}
