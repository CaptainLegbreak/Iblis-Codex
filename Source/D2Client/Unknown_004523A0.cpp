struct Unicode
{
    unsigned short wChar;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

// 0x004523A0
Unicode* __fastcall sub_004523A0_FormatRangeText(Unicode* pText, int nFirst, int nSecond)
{
    if (pText->wChar)
    {
        D2_ASSERT(sub_00526800(pText) < 500, 0x39A);
        Unicode wszBuffer[0x200];
        wszBuffer[0].wChar = 0;
        for (int i = 1; i < 0x200; i++)
        {
            wszBuffer[i].wChar = 0;
        }
        Unicode wszDigit[4];
        wszDigit[0].wChar = 0;
        wszDigit[1].wChar = 0;
        wszDigit[2].wChar = 0;
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        char szDigit[4];
        wsprintfA(szDigit, "%c", (char)(nFirst + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_00526700(wszBuffer, pText);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        wsprintfA(szDigit, "%c", (char)(nSecond + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_005267E0(pText, wszBuffer);
    }
    return pText;
}
