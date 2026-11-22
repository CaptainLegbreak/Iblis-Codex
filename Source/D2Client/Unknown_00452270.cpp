#include "D2Unicode.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

// 0x00452270
Unicode* __fastcall sub_00452270_AppendDigitText(Unicode* pText, int nValue)
{
    char szNumber[4];
    unsigned short wszNumberBuf[3];
    Unicode* wszNumber = (Unicode*)wszNumberBuf;
    D2_ASSERT(sub_00526800(pText) < 500, 0x36C);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xF9A));
    wszNumber[0].wChar = 0;
    wszNumber[1].wChar = 0;
    wszNumber[2].wChar = 0;
    wsprintfA(szNumber, "%c", (char)(nValue + '0'));
    Unicode::win2Unicode(wszNumber, szNumber, 2);
    sub_00526700(pText, wszNumber);
    return pText;
}
