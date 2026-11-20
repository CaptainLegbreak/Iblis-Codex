#include "D2CelContext.h"
#include "D2WinTypes.h"
#include "D2WinTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef unsigned int size_t;

struct D2CelFileStrc;

struct Unicode
{
    unsigned short wChar;

    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, size_t count);                 // 0x00526610
    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count);            // 0x00526540
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern int gnFontMetric1_0072E000;                                                                          // 0x0072E000
extern D2FontCacheStrc* gpFontCache_00841D88;                                                               // 0x00841D88
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8
extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC
extern wchar_t gwszColorCode_008426E0[2];                                                                   // 0x008426E0

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                              // 0x004F59B0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
int __fastcall sub_00502EF0(int nFontId);                                                            // 0x00502EF0
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0);              // 0x0040B430

extern int gnFontMetric2_0072E004;                                                                          // 0x0072E004
extern int gnFontMetric3_0072E008;                                                                          // 0x0072E008
extern unsigned char gnFramedTextBoxColor_00841EC4;                                                         // 0x00841EC4
extern Unicode gwszFramedText_00841EC8[1024];                                                               // 0x00841EC8
extern int gnFramedTextX_008426C8;                                                                          // 0x008426C8
extern int gnFramedTextY_008426CC;                                                                          // 0x008426CC
extern int gnFramedTextColor_008426D0;                                                                      // 0x008426D0
extern int gnFramedTextAlign_008426D4;                                                                      // 0x008426D4
extern int gnFramedTextRectColor_008426D8;                                                                  // 0x008426D8

// 0x00501910
static __declspec(noinline) int sub_00501910_GetTextLineWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 572);
    int nWidth = 0;
    const int nLength = sub_00526800(pText);
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

static __declspec(noinline) void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered);

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
                TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

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

__declspec(noinline) static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText);

// 0x00501840
static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 525);
    int nWidth = 0;
    int nMax = 0;
    const int nLength = sub_00526800(pText);
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

// 0x005019C0
static __declspec(noinline) int sub_005019C0_GetTextHeight(const Unicode* pText)
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
        if (!gnFramedTextBoxColor_00841EC4)
        {
            gnFramedTextBoxColor_00841EC4 = sub_004FB180_FindPaletteIndex(0x50, 0, 0);
        }

        const int nFill = nWidth * gnFramedTextRectColor_008426D8 >> 7;
        const int nRight = nFill + nX;
        D2GFX_DrawBox(nX, nY - nHeight, nRight, nY, gnFramedTextBoxColor_00841EC4, 1);

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
