struct D2CelFileStrc;

struct D2CharStrc
{
    unsigned short wChar;
    unsigned char unk0x02;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short nImageIndex;
    unsigned short unk0x0A[2];
};

struct D2FontStrc
{
    unsigned int dwHeader;
    unsigned short unk0x04;
    unsigned short unk0x06;
    unsigned short unk0x08;
    unsigned char nHeight;
    unsigned char unk0x0B;
    D2CharStrc aChars[1];
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile;
    D2FontStrc* pFontInfo[2];
    D2CharStrc* pCharInfo;
    unsigned int dwShiftedTickCount;
};

struct Unicode
{
    unsigned short wChar;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType);                              // 0x004FA9B0
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile);                                        // 0x004FAAE0
void* __cdecl sub_004FAC80_GetArchive();                                                                    // 0x004FAC80
D2CharStrc* __fastcall sub_6F8AA100(unsigned short wChar);                                                  // 0x00501650
D2CharStrc* __fastcall sub_6F8AA140(unsigned short wChar);                                                  // 0x00501690
void* __fastcall sub_00517079_ReadFileToBuffer(void* pArchive, const char* szFile, int* pSize, const char* szSrcFile, int nLine); // 0x00517079
int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150
void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength);                  // 0x00526320

extern "C" const char gszDataGlobal_006D4118[];                                                             // 0x006D4118
extern "C" const char gszDataLocal_006D41A8[];                                                              // 0x006D41A8
extern const char* gaFontNames_006DC980[14];                                                                // 0x006DC980
extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern int gnFontMetric1_0072E000;                                                                          // 0x0072E000
extern int gnFontMetric2_0072E004;                                                                          // 0x0072E004
extern int gnFontMetric3_0072E008;                                                                          // 0x0072E008
D2FontCacheStrc* gpFontCache_00841D88;                                                                      // 0x00841D88
char gszFontLanguage_00841D8C[4];                                                                           // 0x00841D8C
D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(unsigned short wChar);                                    // 0x00841DA0
D2CelFileStrc* ghMonsterIndicators_00841DA4;                                                                // 0x00841DA4
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8
extern unsigned int gdwLastShiftedTickCount_00841EC0;                                                       // 0x00841EC0
bool gbKoreanFonts_00841EC6;                                                                                // 0x00841EC6
extern Unicode gwszFramedText_00841EC8[1024];                                                               // 0x00841EC8
extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC
extern wchar_t gwszColorCode_008426E0[2];                                                                   // 0x008426E0

// 0x005013A0
static void __stdcall sub_005013A0(int nFont, char* pBuffer, int nLength)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\%s\\", gszDataLocal_006D41A8, "Font");
    D2_ASSERT(nLength > (int)strlen(szPath) + 20, 0x7B);

    if (!gbKoreanFonts_00841EC6)
        wsprintfA(pBuffer, "%s%s%s", szPath, gszFontLanguage_00841D8C, gaFontNames_006DC980[nFont]);
    else if (nFont == 13)
        wsprintfA(pBuffer, "%s%s%s", szPath, "KOR\\", gaFontNames_006DC980[13]);
    else
        wsprintfA(pBuffer, "%s%s%s", szPath, gszFontLanguage_00841D8C, gaFontNames_006DC980[nFont]);
}

// 0x00501490
static void __stdcall sub_00501490_BuildFontPath(int nFont, char* pBuffer, int nLength)
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\%s\\", gszDataLocal_006D41A8, "Font");
    D2_ASSERT(nLength > (int)strlen(szPath) + 20, 0x95);

    if (!gbKoreanFonts_00841EC6)
        wsprintfA(pBuffer, "%s%s%s.tbl", szPath, gszFontLanguage_00841D8C, gaFontNames_006DC980[nFont]);
    else if (nFont == 13)
        wsprintfA(pBuffer, "%s%s%s.tbl", szPath, "KOR\\", gaFontNames_006DC980[13]);
    else
        wsprintfA(pBuffer, "%s%s%s.tbl", szPath, gszFontLanguage_00841D8C, gaFontNames_006DC980[nFont]);
}

// 0x00501580
static void sub_6F8A9E90(int nFont)
{
    char szFile[0x50];
    sub_00501490_BuildFontPath(nFont, szFile, 0x4F);

    if (gFontCache_00841DA8[nFont].pFontInfo[0])
        FOG_Free(gFontCache_00841DA8[nFont].pFontInfo[0], ".\\Src\\D2WinFont.cpp", 0xB3, 0);

    D2FontStrc* pFont = (D2FontStrc*)sub_00517079_ReadFileToBuffer(sub_004FAC80_GetArchive(), szFile, 0, ".\\Src\\D2WinFont.cpp", 0xB5);
    gFontCache_00841DA8[nFont].pFontInfo[0] = pFont;
    gFontCache_00841DA8[nFont].pFontInfo[1] = pFont;
    gFontCache_00841DA8[nFont].pCharInfo = pFont->aChars;
}

// 0x00502C60
void __fastcall D2Win_10115_FONT()
{
    char szFile[0x50];
    const int nLanguage = STRTABLE_GetLanguage();
    gbKoreanFonts_00841EC6 = false;
    gnFontMetric1_0072E000 = 16;
    gnFontMetric2_0072E004 = 17;
    gnFontMetric3_0072E008 = 3;

    if (nLanguage < 6)
    {
        strcpy(gszFontLanguage_00841D8C, "Latin\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA100;
        gnFontMetric2_0072E004 = 16;
    }
    else switch (nLanguage)
    {
    case 12:
        gbKoreanFonts_00841EC6 = true;
        strcpy(gszFontLanguage_00841D8C, "LATIN\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA100;
        break;

    case 6:
        gnFontMetric1_0072E000 = 14;
        gnFontMetric2_0072E004 = 15;
        gnFontMetric3_0072E008 = 5;
        strcpy(gszFontLanguage_00841D8C, "JPN\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA140;
        break;

    case 7:
        gnFontMetric3_0072E008 = 5;
        strcpy(gszFontLanguage_00841D8C, "KOR\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA140;
        break;

    case 8:
    case 9:
        gnFontMetric3_0072E008 = 2;
        gnFontMetric1_0072E000 = 14;
        gnFontMetric2_0072E004 = 14;
        strcpy(gszFontLanguage_00841D8C, "CHI\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA140;
        break;

    case 10:
        gnFontMetric1_0072E000 = 13;
        gnFontMetric2_0072E004 = 13;
        strcpy(gszFontLanguage_00841D8C, "LATIN2\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA140;
        break;

    case 11:
        strcpy(gszFontLanguage_00841D8C, "CYR\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA140;
        break;

    default:
        strcpy(gszFontLanguage_00841D8C, "Latin\\");
        gpfGetCharInfo_00841DA0 = sub_6F8AA140;
        break;
    }

    if (!gFontCache_00841DA8[1].pCellFile)
    {
        sub_005013A0(1, szFile, 0x4F);
        gFontCache_00841DA8[1].pCellFile = ARCHIVE_LoadCellFile(szFile, 0);
        sub_6F8A9E90(1);
    }

    if (!ghMonsterIndicators_00841DA4)
    {
        char szPath[0x104];
        wsprintfA(szPath, "%s\\UI\\Font\\MonsterIndicators", gszDataGlobal_006D4118);
        ghMonsterIndicators_00841DA4 = ARCHIVE_LoadCellFile(szPath, 0);
    }

    gpFontCache_00841D88 = &gFontCache_00841DA8[1];
    memset(gwszFramedText_00841EC8, 0, 0x800);
    *(unsigned short*)szFile = 'c';
    sub_00526320_ToUnicode(gwszColorCode_008426E0, szFile, 2);
    *(unsigned short*)szFile = 'm';
    sub_00526320_ToUnicode(gwszMonsterCode_008426DC, szFile, 2);
}

int __fastcall sub_00502EF0(int nFontSize)
{
    const int nOldFont = gnCurrentFont_0072DFFC;
    const unsigned int dwShiftedTickCount = GetTickCount() >> 10;

    if (nOldFont == nFontSize)
    {
        gFontCache_00841DA8[nFontSize].dwShiftedTickCount = dwShiftedTickCount;
    }
    else
    {
        gnCurrentFont_0072DFFC = nFontSize;

        if (!gFontCache_00841DA8[nFontSize].pCellFile)
        {
            char szFile[0x50];
            sub_005013A0(nFontSize, szFile, 0x4F);
            gFontCache_00841DA8[nFontSize].pCellFile = ARCHIVE_LoadCellFile(szFile, 0);
            sub_6F8A9E90(nFontSize);
            gFontCache_00841DA8[nFontSize].dwShiftedTickCount = dwShiftedTickCount;
        }

        if (dwShiftedTickCount - gdwLastShiftedTickCount_00841EC0 > 600)
        {
            gdwLastShiftedTickCount_00841EC0 = dwShiftedTickCount;

            for (int i = 0; i < 14; ++i)
            {
                D2FontCacheStrc* pFont = &gFontCache_00841DA8[i];
                if (i != nFontSize && dwShiftedTickCount - pFont->dwShiftedTickCount > 240 && pFont->pCellFile)
                {
                    ARCHIVE_FreeCellFile(pFont->pCellFile);
                    pFont->pCellFile = 0;
                }
            }
        }

        gpFontCache_00841D88 = &gFontCache_00841DA8[nFontSize];

        if (gbKoreanFonts_00841EC6)
        {
            gpfGetCharInfo_00841DA0 = sub_6F8AA140;
            if (nFontSize != 13)
                gpfGetCharInfo_00841DA0 = sub_6F8AA100;
        }
    }

    return nOldFont;
}

#include "gen/data/Source/D2Win/Src/D2WinFont_005013A0.inc"
