#include "D2WinTypes.h"
#include "D2WinTypes.h"
struct D2CelFileStrc;

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
void* __stdcall D2Win_GetArchive(); // 0x004FAC80
D2CharStrc* __fastcall sub_6F8AA100(unsigned short wChar);                                                  // 0x00501650
D2CharStrc* __fastcall sub_6F8AA140(unsigned short wChar);                                                  // 0x00501690
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine); // 0x00517079
int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

extern "C" const char gszDataGlobal_006D4118[];                                                             // 0x006D4118
extern "C" const char gszDataLocal_006D41A8[];                                                              // 0x006D41A8
extern const char* gaFontNames_006DC980[14];                                                                // 0x006DC980
extern "C" const char gszFormatMonsterIndicators_006DCA10[];                                                // 0x006DCA10
extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern int gnFontMetric1_0072E000;                                                                          // 0x0072E000
extern int gnFontMetric2_0072E004;                                                                          // 0x0072E004
extern int gnFontMetric3_0072E008;                                                                          // 0x0072E008
extern D2FontCacheStrc* gpFontCache_00841D88;                                                               // 0x00841D88
extern char gszFontLanguage_00841D8C[];                                                                     // 0x00841D8C
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(unsigned short wChar);                             // 0x00841DA0
extern D2CelFileStrc* ghMonsterIndicators_00841DA4;                                                         // 0x00841DA4
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8
unsigned int gdwLastShiftedTickCount_00841EC0;                                                              // 0x00841EC0
extern bool gbKoreanFonts_00841EC6;                                                                         // 0x00841EC6
extern Unicode gwszFramedText_00841EC8[1024];                                                               // 0x00841EC8
extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC
extern wchar_t gwszColorCode_008426E0[2];                                                                   // 0x008426E0

// build: symbol ?sub_005013A0@@YGXHPADH@Z 0x005013A0
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

    D2FontStrc* pFont = (D2FontStrc*)ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szFile, 0, ".\\Src\\D2WinFont.cpp", 0xB5);
    gFontCache_00841DA8[nFont].pFontInfo[0] = pFont;
    gFontCache_00841DA8[nFont].pFontInfo[1] = pFont;
    gFontCache_00841DA8[nFont].pCharInfo = pFont->aChars;
}

// 0x00502EF0
int __fastcall sub_00502EF0(int nFontSize)
{
    const int nOldFont = gnCurrentFont_0072DFFC;
    const unsigned int dwShiftedTickCount = GetTickCount() >> 10;

    if (nOldFont == nFontSize)
    {
        gFontCache_00841DA8[nFontSize].dwShiftedTickCount = dwShiftedTickCount;
        return nOldFont;
    }

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
        if (nFontSize == 13)
            return nOldFont;
        gpfGetCharInfo_00841DA0 = sub_6F8AA100;
    }

    return nOldFont;
}
