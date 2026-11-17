struct Unicode
{
    unsigned short wChar;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
const char* __cdecl sub_0040DF60_GetLocalIp();                                                              // 0x0040DF60
const char* __cdecl sub_0044B7C0_GetRecordText1F();                                                         // 0x0044B7C0
const char* __cdecl sub_0044B820_GetRecordText37();                                                         // 0x0044B820
const char* __cdecl sub_0044B7F0_GetRecordText245();                                                        // 0x0044B7F0
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0

extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58
int gnAutomapTextY_007A51BC;                                                                                // 0x007A51BC
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220

// 0x00459E90
void __cdecl sub_00459E90_DrawGameInfoLines()
{
    Unicode wszName[25];
    char szText[28];
    Unicode wszLine[50];
    for (int i = 0; i < 25; ++i)
        wszName[i].wChar = 0;
    for (int i = 0; i < 50; ++i)
        wszLine[i].wChar = 0;
    const char* szFirst = sub_0044B7C0_GetRecordText1F();
    const char* szSecond = sub_0044B820_GetRecordText37();
    if (!szFirst)
    {
        if (!szSecond)
            return;
    }
    else
    {
        sprintf(szText, gszStringFormat_006FFC58, szFirst);
        sub_00526320_ToUnicode(wszName, szText, 25);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0x1055));
        sub_00526700(wszLine, wszName);
        sub_00502320(wszLine, gnAutomapWidth_007A5220 - sub_00501820(wszLine) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
        gnAutomapTextY_007A51BC += 0x10;
    }
    const char* szThird = sub_0044B7F0_GetRecordText245();
    if (!szThird)
        return;
    sprintf(szText, gszStringFormat_006FFC58, szThird);
    sub_00526320_ToUnicode(wszName, szText, 25);
    sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0x1056));
    sub_00526700(wszLine, wszName);
    sub_00502320(wszLine, gnAutomapWidth_007A5220 - sub_00501820(wszLine) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x00459FF0
void __cdecl sub_00459FF0_DrawStringLine()
{
    Unicode wszText[50];
    for (int i = 0; i < 50; ++i)
        wszText[i].wChar = 0;
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x58CA));
    sub_00502320(wszText, gnAutomapWidth_007A5220 - sub_00501820(wszText) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x0045A0A0
void __cdecl sub_0045A0A0_DrawVersionLine()
{
    Unicode wszText[100];
    char szText[100];
    for (int i = 0; i < 100; ++i)
        wszText[i].wChar = 0;
    SStrPrintf(szText, 100, "v %d.%d%c", 1, 14, 100);
    sub_00526320_ToUnicode(wszText, szText, 100);
    const int nWidth = sub_00501820(wszText);
    sub_00502320(wszText, gnAutomapWidth_007A5220 - nWidth - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x0045A120
void __cdecl sub_0045A120_DrawLocalIpLine()
{
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, sub_0040DF60_GetLocalIp(), 300);
    sub_00502320(wszText, gnAutomapWidth_007A5220 - sub_00501820(wszText) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x0045A190
void __cdecl sub_0045A190_DrawDifficultyLine()
{
    unsigned short nString;
    switch (sub_0044DCD0_GetDifficulty())
    {
    case 1:
        nString = 0x1423;
        break;
    case 2:
        nString = 0x1422;
        break;
    default:
        return;
    }
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
        wszText[i].wChar = 0;
    D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(nString)) + sub_00526800(D2LANG_GetStringFromTblIndex(0x1057)) + 3 < 300, 0xB2A);
    sub_005269D0(300, wszText, D2LANG_GetStringFromTblIndex(0x1057), D2LANG_GetStringFromTblIndex(nString));
    sub_00502320(wszText, gnAutomapWidth_007A5220 - sub_00501820(wszText) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}
