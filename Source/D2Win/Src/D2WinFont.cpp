#include "D2Win.h"
#include "D2ClientTypes.h"
#include "D2WinTypes.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2FontStrc;
struct D2CelFileStrc;
struct D2CmpCelContextStrc;
struct D2CharStrc;
struct D2FontCacheStrc;
struct T0044CB60;
struct D2GfxDataStrc;
struct Unicode;

extern D2FontCacheStrc gFontCache_00841DA8[]; // 0x00841DA8
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0
D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pContext); // 0x00601840
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
void __stdcall TEXTURE_CelDrawColor(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0

struct T0044CB60
{
    void* pText;
    T0044CB60* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern int gnFontMetric2_0072E004; // 0x0072E004

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

extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0

Unicode gwszFramedText_00841EC8[1024];                                                                      // 0x00841EC8

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0

extern D2CelFileStrc* ghMonsterIndicators_00841DA4;                                                         // 0x00841DA4

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

// 0x00501650
D2CharStrc* __fastcall sub_6F8AA100(unsigned short wChar)
{
    if (wChar > 0xFF)
    {
        return gFontCache_00841DA8[gnCurrentFont_0072DFFC].pCharInfo;
    }

    return &gFontCache_00841DA8[gnCurrentFont_0072DFFC].pCharInfo[wChar];
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

// 0x00501820
int __fastcall sub_00501820(const Unicode* wszText)
{
    return D2Win_10122(wszText, sub_00526800(wszText));
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

#include "gen/data/Source/D2Win/Src/D2WinFont.inc"
