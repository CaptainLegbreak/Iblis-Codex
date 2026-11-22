#include "D2Launch.h"

struct Unicode
{
    unsigned short wChar;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

// 0x0042FB20
void __cdecl sub_0042FB20()
{
    sub_0042F480_Reset();
    sub_0042F430_CreateControl(2);
    sub_0042F430_CreateControl(3);
    sub_0042F430_CreateControl(6);
    sub_0042F430_CreateControl(7);
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(4);
    char szTail[0x200] = { 0 };
    char szText[0x200] = { 0 };
    Unicode wszText[0x200];
    wszText[0].wChar = 0;
    for (int i = 1; i < 0x200; i++)
        wszText[i].wChar = 0;
    const char* szKey;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        sub_005263E0(szText, D2LANG_GetStringFromTblIndex(0x557A), 0x200);
        szKey = "2001";
    }
    else
    {
        sub_005263E0(szText, D2LANG_GetStringFromTblIndex(0x13F0), 0x200);
        szKey = "2000";
    }
    int nKeyLen = SStrLen(szKey);
    char* pFound = strstr(szText, szKey);
    if (pFound)
    {
        SStrCopy(szTail, pFound + nKeyLen, 0x7FFFFFFF);
        SStrCopy(pFound, "2000 - 2016", 0x7FFFFFFF);
        SStrCopy(pFound + SStrLen("2000 - 2016"), szTail, 0x7FFFFFFF);
    }
    sub_00526320_ToUnicode(wszText, szText, 0x200);
    sub_004FC9B0_SetText(pControl, wszText, 4, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x13F1), 4, 0, 0);
    D2Win_10029(0);
    if (sub_00514D80())
        D2SOUND_10034(1);
}
