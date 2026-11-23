#include "D2Client.h"

struct D2CelFileStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

// 0x004520C0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szFile)
{
    char szPath[0x104];
// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szPath, "%s\\UI\\", gszDataGlobal);
    char* pDest = &szPath[SStrLen(szPath)];
    const char* pSrc = szFile;
    while (*pSrc)
        *pDest++ = *pSrc++;
    *pDest = 0;
    return ARCHIVE_LoadClientCellFile(szPath, 0);
}
