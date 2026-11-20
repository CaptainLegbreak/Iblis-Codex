#include "D2Win.h"
#include "D2ClientTypes.h"
#include "D2WinTypes.h"
#include "D2WinTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2FontStrc;
struct D2CellFileStrc;
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

struct Unicode
{
    unsigned short wChar;
};

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern int gnFontMetric2_0072E004; // 0x0072E004

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
void __fastcall sub_00502680_DrawCellFile(D2CellFileStrc* pCell, int nX, int nY, int nAlign, int eDrawMode, int nShift)
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

#include "gen/data/Source/D2Win/Src/D2WinFont.inc"
