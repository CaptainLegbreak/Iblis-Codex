#include "Fog.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile); // 0x00408000
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660
extern int gdwGlobal_0074F0C8; // 0x0074F0C8

// 0x004088C0
int __fastcall sub_004088C0_ReportNestedError(const char* szFile, int nLine, const char* szMessage)
{
    if (gdwGlobal_0074F0C8)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "\n***** ENCOUNTERED ERROR DURING ERROR HANDLING!!!\n%s,%d\n%s\n*****", sub_00408000_StripSourcePath(szFile), nLine, szMessage);
        return 1;
    }
    return 0;
}
