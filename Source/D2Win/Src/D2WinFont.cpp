#include "D2WinTypes.h"
#include "D2Unicode.h"
#include "D2Win.h"
#include "D2ClientTypes.h"
#include "D2CelContext.h"

struct D2CelFileStrc;

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

D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                             // 0x00841DA0

D2CelFileStrc* ghMonsterIndicators_00841DA4;                                                                // 0x00841DA4

extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8

unsigned int gdwLastShiftedTickCount_00841EC0;                                                              // 0x00841EC0

bool gbKoreanFonts_00841EC6;                                                                                // 0x00841EC6

Unicode gwszFramedText_00841EC8[1024];                                                                      // 0x00841EC8

extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC

extern wchar_t gwszColorCode_008426E0[2];                                                                   // 0x008426E0

struct D2FontStrc;

struct D2CmpCelContextStrc;

struct D2CharStrc;

struct D2FontCacheStrc;

struct T0044CB60;

struct D2GfxDataStrc;

struct Unicode;

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0

D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pContext); // 0x00601840

void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

void __stdcall TEXTURE_CelDrawColor(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0

struct T0044CB60
{
    void* pText;
    T0044CB60* pNext;
};

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

struct D2SplittedTextStrc
{
    Unicode* wszLine;
    D2SplittedTextStrc* pNextLine;
};

int gnFramedTextAlign_008426D4;                                                                             // 0x008426D4

int gnFramedTextColor_008426D0;                                                                             // 0x008426D0

int gnFramedTextRectColor_008426D8;                                                                         // 0x008426D8

int gnFramedTextX_008426C8;                                                                                 // 0x008426C8

int gnFramedTextY_008426CC;                                                                                 // 0x008426CC

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

typedef unsigned int size_t;

static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText);

static int sub_00501910_GetTextLineWidth(const Unicode* pText);

static void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered);

static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText);

static void __stdcall sub_00501C30_DrawFontText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode);

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern "C" int __fastcall sub_00526800_2(const unsigned short* pText);

static int sub_005019C0_GetTextHeight(const Unicode* pText);

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                              // 0x004F59B0

static int shim_2;

void __stdcall shim_1(int nLength, int nY, int nWidth, int nPalette, int bCentered);

static int sub_005019C0_GetTextHeight(const Unicode* pText);

__declspec(noinline) static void __stdcall sub_00501A80_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nPalette, int bCentered);

extern unsigned int gaFontCharValidBits_006DC9B8[8]; // 0x006DC9B8

static void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered);

unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180

extern unsigned char gnTooltipColor_00841EC4; // 0x00841EC4

static void __stdcall sub_00501A80_DrawTextLine(int nY, int nWidth, int nShift, int bCentre, const Unicode* pText, int nX);

extern "C" const char gszFormatMonsterIndicators_006DCA10[];                                                // 0x006DCA10

static void __stdcall sub_005013A0(int nFont, char* pBuffer, int nLength);

static void __stdcall sub_00501490_BuildFontPath(int nFont, char* pBuffer, int nLength);

static void sub_6F8A9E90(int nFont);

int __fastcall sub_00502EF0(int nFontSize);

void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0);              // 0x0040B430

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

    D2FontStrc* pFont = (D2FontStrc*)ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szFile, 0, ".\\Src\\D2WinFont.cpp", 0xB5);
    gFontCache_00841DA8[nFont].pFontInfo[0] = pFont;
    gFontCache_00841DA8[nFont].pFontInfo[1] = pFont;
    gFontCache_00841DA8[nFont].pCharInfo = pFont->aChars;
}

// 0x005015F0
void __stdcall D2Win_10116()
{
    for (int i = 0; i < 14; ++i)
    {
        if (gFontCache_00841DA8[i].pCellFile)
        {
            sub_004FAAE0_FreeCellFile(gFontCache_00841DA8[i].pCellFile);
            gFontCache_00841DA8[i].pCellFile = 0;
        }
        if (gFontCache_00841DA8[i].pFontInfo[0])
        {
            FOG_Free(gFontCache_00841DA8[i].pFontInfo[0], ".\\Src\\D2WinFont.cpp", 0x135, 0);
            gFontCache_00841DA8[i].pFontInfo[0] = 0;
        }
    }
    sub_004FAAE0_FreeCellFile(ghMonsterIndicators_00841DA4);
    ghMonsterIndicators_00841DA4 = 0;
}

// 0x00501650
D2CharStrc* __fastcall sub_6F8AA100(unsigned short wChar)
{
    if (wChar > 0xFF)
    {
        return gFontCache_00841DA8[gnCurrentFont_0072DFFC].pCharInfo;
    }

    return &gFontCache_00841DA8[gnCurrentFont_0072DFFC].pCharInfo[wChar];
}

inline int D2Win_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
    {
        return 0;
    }

    return wChar == 0xFF;
}

// 0x00501730
int __fastcall D2Win_10123(const Unicode* wszText, int nTextLength)
{
    int nWidth = 0;
    int nCount = 0;
    const Unicode* pChar = wszText;
    while (pChar->wChar)
    {
        if (nCount >= nTextLength)
        {
            break;
        }

        const unsigned short wChar = pChar->wChar;
        if (wChar != '\n')
        {
            if (nCount + 3 < nTextLength && D2Win_IsColorCodePrefix(wChar) && pChar[1].wChar == 'c' && pChar[2].wChar >= '0' && pChar[2].wChar < '7')
            {
                pChar += 3;
                nCount += 3;
                continue;
            }

            nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        }

        ++pChar;
        ++nCount;
    }

    return nWidth;
}

// 0x005017D0
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength)
{
    int nCount = 0;
    int nWidth = 0;
    for (const Unicode* i = wszText; i->wChar; ++i)
    {
        if (nCount >= nTextLength)
            break;
        const unsigned short wChar = i->wChar;
        if (wChar != '\n')
            nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        ++nCount;
    }
    return nWidth;
}

// 0x00501820
int __fastcall sub_00501820(const Unicode* wszText)
{
    return D2Win_10122(wszText, sub_00526800(wszText));
}

// 0x00501840
static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 525);
    int nWidth = 0;
    int nMax = 0;
    const int nLength = sub_00526800((const Unicode*)pText);
    for (int nCount = 0; nCount < nLength; ++nCount)
    {
        const unsigned short wChar = pText->wChar;
        if (!wChar)
            break;
        if (wChar == '\n')
        {
            if (nWidth > nMax)
                nMax = nWidth;
            nWidth = 0;
            ++pText;
            continue;
        }
        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            ++pText;
            if (!Unicode::strnicmp(pText, (const Unicode*)gwszMonsterCode_008426DC, 1))
                nWidth += gpfGetCharInfo_00841DA0(*(const int*)gwszMonsterCode_008426DC)->nWidth;
            pText += 2;
            nCount += 2;
            continue;
        }
        nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        ++pText;
    }
    if (nMax > nWidth)
        nWidth = nMax;
    return nWidth;
}

void __fastcall sub_Emit_00501840(const Unicode* pText, int* pWidth, int nExtra)
{
    *pWidth = sub_00501840_GetMultiLineTextWidth(pText) + nExtra;
}

// 0x00501910
static int sub_00501910_GetTextLineWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 572);
    int nWidth = 0;
    const int nLength = sub_00526800((const Unicode*)pText);
    for (int nCount = 0; nCount < nLength; ++nCount)
    {
        const unsigned short wChar = pText->wChar;
        if (wChar == '\n')
            break;
        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            ++pText;
            if (!Unicode::strnicmp(pText, (const Unicode*)gwszMonsterCode_008426DC, 1))
                nWidth += gpfGetCharInfo_00841DA0(*(const int*)gwszMonsterCode_008426DC)->nWidth;
            nCount += 2;
            pText += 2;
            continue;
        }
        nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        ++pText;
    }
    return nWidth;
}

void __fastcall sub_M388_Emit_00501910(const Unicode* pText, int* pWidth, int nExtra)
{
    *pWidth = sub_00501910_GetTextLineWidth(pText) + nExtra;
}

// 0x005019C0
static int sub_005019C0_GetTextHeight(const Unicode* pText)
{
    D2_ASSERT(pText, 606);

    int nLines = 1;
    int nLength = sub_00526800(pText);
    const Unicode* pChar = pText;
    if (nLength > 0)
    {
        do
        {
            if (pChar->wChar == '\n')
                ++nLines;
            ++pChar;
        }
        while (--nLength);
    }

    return gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight * gnFontMetric2_0072E004 * nLines / 10;
}

// 0x00501A40
int __stdcall D2Win_10125()
{
    return gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight;
}

// 0x00501A60
static void __stdcall sub_00501A60_DrawRectUp(int nX, int nY, int nWidth, int nHeight, unsigned int dwColor, int nDrawMode)
{
    D2GFX_DrawBox(nX, nY - nHeight, nWidth + nX, nY, dwColor, nDrawMode);
}

// 0x00501A80
static void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentered)
    {
        nX += (nWidth - sub_00501910_GetTextLineWidth(wszText)) >> 1;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
    tContext.nDirection = 0;

    const Unicode* wszTextCur = wszText;
    while (nCount < nLength)
    {
        const Unicode tChar = *wszTextCur;
        ++wszTextCur;
        ++nCount;
        const unsigned short wChar = wszTextCur[-1].wChar;

        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            const Unicode tNext = *wszTextCur;
            ++nCount;
            ++wszTextCur;

            if (!Unicode::strncmp(&tNext, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nGlobalPaletteShift = 0;
                }
                else
                {
                    const Unicode* pDigit = wszTextCur;
                    ++nCount;
                    ++wszTextCur;
                    nGlobalPaletteShift = pDigit->wChar - '0';
                    if (nGlobalPaletteShift >= '\r')
                    {
                        nGlobalPaletteShift = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --wszTextCur;

                D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
                tContext.nFrame = pCharInfo->nImageIndex;
                TEXTURE_CelDrawColor((D2GfxDataStrc*)&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor((D2GfxDataStrc*)&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

            nX += pCharInfo->nWidth;
        }
        else
        {
            if (bCentered)
            {
                nX = ((nWidth - sub_00501910_GetTextLineWidth(wszTextCur)) >> 1) + nStartX;
            }
            else
            {
                nX = nStartX;
            }

            nY += gnFontMetric1_0072E000 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / -10;
        }
    }
}

// build: context sub_00501A80_Shim
// calling-convention shim (not game code)
void __stdcall sub_00501A80_Shim(const Unicode* wszText, int nX, int nY, int nWidth, int nShift, int bCentered)
{
    FONT_DrawString(wszText, nX, nY - 2, nWidth, nShift, bCentered);
}

// 0x00501C30
static void __stdcall sub_00501C30_DrawFontText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentered)
    {
        nX += (nWidth - sub_00501910_GetTextLineWidth(wszText)) >> 1;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
    tContext.nDirection = 0;

    if (nLength <= 0)
    {
        return;
    }

    const Unicode* wszTextCur = wszText;
    do
    {
        const Unicode tChar = *wszTextCur;
        ++wszTextCur;
        ++nCount;
        const unsigned short wChar = wszTextCur[-1].wChar;

        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            const Unicode tNext = *wszTextCur;
            ++nCount;
            ++wszTextCur;

            if (!Unicode::strncmp(&tNext, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nColor = 0;
                }
                else
                {
                    const Unicode* pDigit = wszTextCur;
                    ++nCount;
                    ++wszTextCur;
                    nColor = pDigit->wChar - '0';
                    if (nColor >= '\r')
                    {
                        nColor = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --wszTextCur;

                D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
                tContext.nFrame = pCharInfo->nImageIndex;
                TEXTURE_CelDrawColor((D2GfxDataStrc*)&tContext, nX, nY, (unsigned int)-1, eDrawMode, nColor);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor((D2GfxDataStrc*)&tContext, nX, nY, (unsigned int)-1, eDrawMode, nColor);

            nX += pCharInfo->nWidth;
        }
        else
        {
            if (bCentered)
            {
                nX = ((nWidth - sub_00501910_GetTextLineWidth(wszTextCur)) >> 1) + nStartX;
            }
            else
            {
                nX = nStartX;
            }

            nY += -16 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10;
        }
    }
    while (nCount < nLength);
}

void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode)
{
    int nWidth = 0;
    if (bCentered)
        nWidth = sub_00501840_GetMultiLineTextWidth(wszText) + 8;
    sub_00501C30_DrawFontText(wszText, nX, nY, nWidth, nColor, bCentered, eDrawMode);
}

inline int sub_K08_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
        return 0;

    return wChar == 0xFF;
}

// 0x00502190
static void sub_00502190_DrawFontText(const Unicode* pText, int nX, int nY)
{
    const Unicode* wszText = pText;
    const int nStartX = nX;
    const int nLength = sub_00526800(pText);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
    tContext.nDirection = 0;

    if (nLength <= 0)
        return;

    while (1)
    {
        const Unicode wc = *wszText;
        ++wszText;
        if (sub_K08_IsColorCodePrefix(wc.wChar))
        {
            wszText += 2;
            continue;
        }

        if (wc.wChar != 0x0A)
        {
            D2CharStrc* pChar = ((D2CharStrc* (__fastcall*)(unsigned short))gpfGetCharInfo_00841DA0)(wc.wChar);
            tContext.nFrame = pChar->nImageIndex;
            sub_004F6480(&tContext, nX, nY, -1, 5, 0);
            nX += pChar->nWidth;
        }
        else
        {
            nX = nStartX;
            nY += -15 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10;
        }
    }
}

// 0x00502280
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign)
{
    if (wszText && sub_00526800(wszText) < 1024)
        sub_005267E0(gwszFramedText_00841EC8, wszText);
    else
        memset(gwszFramedText_00841EC8, 0, sizeof(gwszFramedText_00841EC8));
    gnFramedTextX_008426C8 = nX;
    gnFramedTextY_008426CC = nY;
    gnFramedTextColor_008426D0 = nTextColor;
    gnFramedTextAlign_008426D4 = nAlign;
    gnFramedTextRectColor_008426D8 = 0;
}

// 0x005022F0
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign, int nRectangleColor)
{
    D2Win_10129_DrawFramedText(wszText, nX, nY, nTextColor, nAlign);
    gnFramedTextRectColor_008426D8 = nRectangleColor;
}

// 0x00502320
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered)
{
    int nWidth = 0;
    if (bCentered)
        nWidth = sub_00501840_GetMultiLineTextWidth(wszText) + 8;
    sub_00501A80_DrawTextLine(nY, nWidth, nColor, bCentered, wszText, nX);
}

// 0x005023A0
void __fastcall sub_005023A0_DrawFontText(const Unicode* pText, int nX, int nY)
{
    sub_00502190_DrawFontText(pText, nX, nY);
}

// calling-convention shim (not game code)
static void __stdcall sub_00501A80_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nPalette, int bCentered)
{
    shim_2 = nX;
    const int nLength = sub_00526800((const Unicode*)wszText);
    shim_1(nLength, nY, nWidth, nPalette, bCentered);
}

static inline void sub_005023B0_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight)
{
    *pWidth = sub_00501840_GetMultiLineTextWidth(pText) + 8;
    *pHeight = sub_005019C0_GetTextHeight(pText);
}

// 0x005023B0
void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor)
{
    int nTextWidth = 0;
    int nTextHeight = 0;
    sub_005023B0_GetTextDimensions(wszText, &nTextWidth, &nTextHeight);

    nY += 2;

    int nScreenWidth;
    int nScreenHeight;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);

    int nLeft = D2_MAX(nX, 0);
    if (nLeft >= nScreenWidth - nTextWidth)
    {
        nLeft = nScreenWidth - nTextWidth;
    }
    nY = D2_MIN(D2_MAX(nY, nTextHeight), nScreenHeight - 31);

    D2GFX_DrawBox(nLeft, nY - nTextHeight, nTextWidth + nLeft, nY, dwColor, eDrawMode);
    sub_00501A80_DrawString(wszText, nLeft, nY - 3 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10, nTextWidth, nColor, 1);
}

// 0x00502480
void __fastcall D2Win_10133(const Unicode* wszText, int nX, int nY, int nColor, int nDrawMode, int nTextColor)
{
    int nScreenWidth;
    int nLeft;
    int nTop;
    int nScreenHeight;
    const int nRectWidth = sub_00501840_GetMultiLineTextWidth(wszText);
    const int nRectHeight = gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight;
    nLeft = nX;
    nY += 2;
    nTop = nY;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);
    if (nX + nRectWidth > nScreenWidth)
        nLeft = nScreenWidth - nRectWidth;
    if (nY > nScreenHeight - 31)
        nTop = nScreenHeight - 31;
    if (nTop - nRectHeight < 0)
        nTop *= 2;
    D2GFX_DrawBox(nLeft, nTop - nRectHeight, nLeft + nRectWidth, nTop, nColor, nDrawMode);
    sub_00501A80_DrawTextLine(nTop - 2, nRectWidth, nTextColor, 1, wszText, nLeft);
}

static int sub_00501840_IsColorCode(unsigned short wChar)
{
    return wChar == 0xFF;
}

static void __stdcall sub_00501A80_DrawTextLine(int nY, int nWidth, int nShift, int bCentre, const Unicode* pText, int nX)
{
    const int nLength = sub_00526800(pText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentre)
        nX += (nWidth - sub_00501910_GetTextLineWidth(pText)) >> 1;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
    tContext.nDirection = 0;
    while (nCount < nLength)
    {
        const Unicode c = *pText;
        const int bColor = sub_K08_IsColorCodePrefix(pText->wChar);
        ++pText;
        ++nCount;
        if (bColor)
        {
            const Unicode c2 = *pText;
            ++nCount;
            ++pText;
            if (!Unicode::strncmp(&c2, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nShift = 0;
                }
                else
                {
                    ++nCount;
                    nShift = (pText++)->wChar - '0';
                    if (nShift >= 13)
                        nShift = 0;
                }
            }
            else
            {
                --nCount;
                --pText;
                D2CharStrc* pChar = gpfGetCharInfo_00841DA0(c.wChar);
                tContext.nFrame = pChar->nImageIndex;
                TEXTURE_CelDrawColor((D2GfxDataStrc*)&tContext, nX, nY, -1, 5, nShift);
                nX += pChar->nWidth;
            }
        }
        else if (c.wChar != '\n')
        {
            D2CharStrc* pChar = gpfGetCharInfo_00841DA0(c.wChar);
            tContext.nFrame = pChar->nImageIndex;
            TEXTURE_CelDrawColor((D2GfxDataStrc*)&tContext, nX, nY, -1, 5, nShift);
            nX += pChar->nWidth;
        }
        else
        {
            if (bCentre)
                nX = ((nWidth - sub_00501910_GetTextLineWidth(pText)) >> 1) + nStartX;
            else
                nX = nStartX;
            nY += gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight * gnFontMetric1_0072E000 / -10;
        }
    }
}

// 0x00502520
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight)
{
    *pWidth = sub_00501840_GetMultiLineTextWidth(pText);
    *pHeight = sub_005019C0_GetTextHeight(pText);
}

// Returns whether the font can draw a character: 0 for the colour-code prefix 0xFF, else the character's bit in its
// row of gaFontCharValidBits_006DC9B8.
// 0x00502550
unsigned int __fastcall D2Win_10128(unsigned char nCharCode)
{
    if (Unicode(nCharCode).isPipe())
    {
        return 0;
    }

    // not original source: the identical arms, the identical-arm if below and the __assume only shape register use
    const unsigned int nRowChar = nCharCode ? nCharCode : nCharCode;
    const unsigned int dwOffset = (nRowChar >> 5) & 7;
    D2_ASSERT(dwOffset < 8, 0x4D8);
    const int nShift = nCharCode % 32;
    unsigned int dwWord = gaFontCharValidBits_006DC9B8[dwOffset];
    if (dwOffset)
    {
        dwWord >>= nShift;
    }
    else
    {
        dwWord >>= nShift;
    }
    const int nBits = (unsigned char)dwWord;
    __assume(nBits != 0x80000000);
    return nBits & 1;
}

// 0x005025C0
void __fastcall sub_005025C0_DrawFramedText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int eDrawMode, int nTextColor)
{
    int nScreenWidth;
    int nLeft;
    int nScreenHeight;
    const int nTextHeight = sub_005019C0_GetTextHeight(wszText);
    const int nPad = 4 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10;
    nLeft = nX;
    nY += 2;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);
    if (nX + nWidth > nScreenWidth)
        nLeft = nScreenWidth - nWidth;
    if (nY > nScreenHeight - 31)
        nY = nScreenHeight - 31;
    if (nY - nTextHeight < 0)
        nY *= 2;
    const int nInset = nLeft - 4;
    D2GFX_DrawBox(nInset, nY + nPad - nTextHeight, nInset + nWidth, nY, nColor, eDrawMode);
    sub_00501A80_DrawTextLine(nY - 2, 0, nTextColor, 0, wszText, nLeft);
}

extern "C" void __stdcall sub_K08_EmitDrawRect(int nX, int nY, int nWidth, int nHeight, unsigned int dwColor, int nDrawMode)
{
    sub_00501A60_DrawRectUp(nX, nY, nWidth, nHeight, dwColor, nDrawMode);
}

// 0x00502680
void __fastcall sub_00502680_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nAlign, int eDrawMode, int nShift)
{
    const unsigned int nFrames = CelFileGetCelsPerDirection((D2CelFileStrc*)pCell);
    unsigned int nWidth;
    D2GfxDataStrc tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = (D2CelFileStrc*)pCell;
    tGfxData.nDirection = 0;
    nWidth = 0;

    if (nAlign == 1 || nAlign == 2)
    {
        for (unsigned int i = 0; i < nFrames; ++i)
        {
            tGfxData.nFrame = i;
            D2CelStrc* pCel = CelGetHandle((D2CmpCelContextStrc*)&tGfxData);
            nWidth += sub_006018C0(pCel);
        }

        if (nAlign == 1)
        {
            nX -= (nWidth >> 1) + 1;
        }
        else
        {
            nX -= nWidth;
        }
    }

    unsigned int j = 0;
    if (j < nFrames)
    {
        int nPosX = nX;
        do
        {
            tGfxData.nFrame = j;
            if (nShift == -1)
            {
                TEXTURE_CelDraw(&tGfxData, nPosX, nY, (unsigned int)-1, eDrawMode, 0);
            }
            else
            {
                TEXTURE_CelDrawColor(&tGfxData, nPosX, nY, (unsigned int)-1, eDrawMode, nShift);
            }
            nPosX += 0x100;
        } while (++j < nFrames);
    }
}

// 0x00502750
void __fastcall sub_00502750_DrawTooltip(const Unicode* text,int x,int y,int color,int centered,int fill)
{
 if(!sub_00526800(text)) return;
 const int width=sub_00501840_GetMultiLineTextWidth(text)+8;
 int screenWidth,screenHeight;
 int rest;
 int height=sub_005019C0_GetTextHeight(text);
 if(centered==1) { rest=width>>1; x-=rest; }
 y+=2;
 WINDOW_GetDimensions(&screenWidth,&screenHeight);
 const int left=((0<x?x:0)<screenWidth-width?(0<x?x:0):screenWidth-width);
 y=((y>height?y:height)<screenHeight-31?(y>height?y:height):screenHeight-31);
 if(fill) {
  if(!gnTooltipColor_00841EC4) gnTooltipColor_00841EC4=sub_004FB180_FindPaletteIndex(80,0,0);
  const int filled=(width*fill)>>7;
  const int right=filled+left;
  ((void (__stdcall*)(int,int,int,int,unsigned char,int))D2GFX_DrawBox)(left,y-height,right,y,gnTooltipColor_00841EC4,1);
  rest=width-filled;
  if(rest) D2GFX_DrawBox(right,y-height,right+rest,y,0,2);
 } else D2GFX_DrawBox(left,y-height,left+width,y,0,2);
 const int inset=3*gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight/10;
 FONT_DrawString(text,left,y-inset,width,color,1);
}

// 0x005028A0
void __fastcall sub_005028A0_FreeTextLines(T0044CB60* pLines)
{
    while (pLines)
    {
        T0044CB60* pNext = pLines->pNext;
        FOG_Free(pLines->pText, ".\\Src\\D2WinFont.cpp", 0x579, 0);
        FOG_Free(pLines, ".\\Src\\D2WinFont.cpp", 0x57A, 0);
        pLines = pNext;
    }
}

void __fastcall sub_M98_Emit_005019C0(const Unicode* pText, int* pHeight, int nExtra)
{
    *pHeight = sub_005019C0_GetTextHeight(pText) + nExtra;
}

// 0x005028E0
D2SplittedTextStrc* __stdcall sub_005028E0_AllocSplitTextLine(const Unicode* wszText, int nLength, int bSkipSpace)
{
    const Unicode* pText = wszText;
    D2SplittedTextStrc* pSplitText = (D2SplittedTextStrc*)FOG_Alloc(sizeof(D2SplittedTextStrc), ".\\Src\\D2WinFont.cpp", 0x588, 0);
    int nCount = nLength;
    if (bSkipSpace && pText->wChar < 0x100 && isspace(pText->wChar))
    {
        nCount = nCount - 1;
        pText = pText + 1;
    }
    pSplitText->wszLine = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nCount + 1), ".\\Src\\D2WinFont.cpp", 0x591, 0);
    pSplitText->pNextLine = 0;
    Unicode::strncpy(pSplitText->wszLine, pText, nCount);
    pSplitText->wszLine[nCount].wChar = 0;
    return pSplitText;
}

// 0x00502C40
int* __fastcall sub_00502C40_ClearTable(int* pTable)
{
    for (int i = 0; i < 0x200; ++i)
    {
        pTable[i] = 0;
    }
    return pTable;
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
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA100;
        gnFontMetric2_0072E004 = 16;
    }
    else switch (nLanguage)
    {
    case 12:
        gbKoreanFonts_00841EC6 = true;
        strcpy(gszFontLanguage_00841D8C, "LATIN\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA100;
        break;

    case 6:
        gnFontMetric1_0072E000 = 14;
        gnFontMetric2_0072E004 = 15;
        gnFontMetric3_0072E008 = 5;
        strcpy(gszFontLanguage_00841D8C, "JPN\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
        break;

    case 7:
        gnFontMetric3_0072E008 = 5;
        strcpy(gszFontLanguage_00841D8C, "KOR\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
        break;

    case 8:
    case 9:
        gnFontMetric3_0072E008 = 2;
        gnFontMetric1_0072E000 = 14;
        gnFontMetric2_0072E004 = 14;
        strcpy(gszFontLanguage_00841D8C, "CHI\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
        break;

    case 10:
        gnFontMetric1_0072E000 = 13;
        gnFontMetric2_0072E004 = 13;
        strcpy(gszFontLanguage_00841D8C, "LATIN2\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
        break;

    case 11:
        strcpy(gszFontLanguage_00841D8C, "CYR\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
        break;

    default:
        strcpy(gszFontLanguage_00841D8C, "Latin\\");
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
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
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA140;
        if (nFontSize == 13)
            return nOldFont;
        gpfGetCharInfo_00841DA0 = (D2CharStrc* (__fastcall*)(int))sub_6F8AA100;
    }

    return nOldFont;
}

// 0x00503000
void __stdcall D2Win_10124()
{
    const int nSavedFont = gnCurrentFont_0072DFFC;
    int nFont = gnCurrentFont_0072DFFC;

    if (!sub_00526800(gwszFramedText_00841EC8))
    {
        return;
    }

    int nWidth;
    int nHeight;
    int nX;
    int nY;
    int nScreenWidth;
    int nScreenHeight;
    int nRest = 0;
    for (;;)
    {
        nWidth = sub_00501840_GetMultiLineTextWidth(gwszFramedText_00841EC8) + 8;
        nHeight = sub_005019C0_GetTextHeight(gwszFramedText_00841EC8);

        nX = gnFramedTextX_008426C8;
        if (gnFramedTextAlign_008426D4 == 1)
        {
            nX = gnFramedTextX_008426C8 - (nWidth >> 1);
        }

        nY = gnFramedTextY_008426CC + 2;
        WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);

        if (nHeight <= nScreenHeight - 10)
        {
            break;
        }

        if (nFont == 1)
        {
            sub_00502EF0(0);
            nFont = 0;
        }
        else
        {
            if (gnCurrentFont_0072DFFC)
            {
                break;
            }

            sub_00502EF0(6);
            nFont = 6;
        }
    }

    nX = D2_MIN(D2_MAX(nX, 0), nScreenWidth - nWidth);
    nY = D2_MIN(D2_MAX(nY, nHeight - 5), nScreenHeight - 5);

    if (gnFramedTextRectColor_008426D8)
    {
        if (!gnTooltipColor_00841EC4)
        {
            gnTooltipColor_00841EC4 = sub_004FB180_FindPaletteIndex(0x50, 0, 0);
        }

        const int nFill = nWidth * gnFramedTextRectColor_008426D8 >> 7;
        const int nRight = nFill + nX;
        ((void (__stdcall*)(int, int, int, int, unsigned char, int))D2GFX_DrawBox)(nX, nY - nHeight, nRight, nY, gnTooltipColor_00841EC4, 1);

        nRest = nWidth - nFill;
        if (nRest)
        {
            D2GFX_DrawBox(nRight, nY - nHeight, nRight + nRest, nY, 0, 2);
        }
    }
    else
    {
        D2GFX_DrawBox(nX, nY - nHeight, nX + nWidth, nY, 0, 2);
    }

    FONT_DrawString(gwszFramedText_00841EC8, nX, nY - gnFontMetric3_0072E008 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10, nWidth,
                            gnFramedTextColor_008426D0, 1);

    if (nFont != nSavedFont)
    {
        sub_00502EF0(nSavedFont);
    }
}

#include "gen/data/Source/D2Win/Src/D2WinFont.inc"
