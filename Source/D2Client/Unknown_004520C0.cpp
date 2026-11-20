#include "D2Client.h"

struct D2CelFileStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0

// 0x004520C0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szFile)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\UI\\", szDataGlobal_006D4118);
    char* pDest = &szPath[SStrLen(szPath)];
    const char* pSrc = szFile;
    while (*pSrc)
        *pDest++ = *pSrc++;
    *pDest = 0;
    return sub_004788B0(szPath, 0);
}
