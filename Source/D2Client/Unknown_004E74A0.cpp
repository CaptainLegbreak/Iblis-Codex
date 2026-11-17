#include "D2Client.h"

// calling-convention shim (not game code)
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength);                  // 0x00526320
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70

static __declspec(noinline) void __stdcall sub_004E74A0_FormatDamageRange(int bPrefixSign, wchar_t* wszText, int bUseFormat, int nMinDamage, int nMaxDamage);
// 0x004E74A0
static void __stdcall sub_004E74A0_FormatDamageRange(int bPrefixSign, wchar_t* wszText, int bUseFormat, int nMinDamage, int nMaxDamage)
{
    char szText[32];
    if (bUseFormat && (nMinDamage >= 10000 || nMaxDamage >= 10000))
    {
        if (!(nMinDamage < 10000))
            wsprintfA(szText, "%s%dK-%dK", bPrefixSign ? szPlus_006DBEC4 : &gszEmptyAssertText, (nMinDamage + 500) / 1000, (nMaxDamage + 500) / 1000);
        else
            wsprintfA(szText, "%s%d-%dK", bPrefixSign ? szPlus_006DBEC4 : &gszEmptyAssertText, nMinDamage, (nMaxDamage + 500) / 1000);
    }
    else if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMinDamage, nMaxDamage);
    else
        wsprintfA(szText, szFmtRange_006D9D70, nMinDamage, nMaxDamage);
    sub_00526320_ToUnicode(wszText, szText, 32);
}

// 0x004E75B0
static int sub_004E75B0_FormatValueOrRange(wchar_t* wszText, int bPrefixSign, int nMin, int nMax)
{
    if (nMin == nMax)
    {
        char szText[32];
        if (bPrefixSign && nMin >= 0)
            wsprintfA(szText, "+%d", nMin);
        else
            wsprintfA(szText, szFmtD_006D57BC, nMin);
        sub_00526320_ToUnicode(wszText, szText, 32);
        return 1;
    }
    sub_004E74A0_FormatDamageRange(bPrefixSign, wszText, 1, nMin, nMax);
    return 1;
}

// build: context sub_004E75B0_Shim
// calling-convention shim (not game code)
extern "C" int __stdcall sub_004E75B0_Shim(wchar_t* p, int a, int b, int c)
{
    return sub_004E75B0_FormatValueOrRange(p, a, b, c);
}
