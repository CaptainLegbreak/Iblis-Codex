#include "D2WinTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
typedef unsigned int size_t;
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2CelFileStrc;

struct Unicode
{
    unsigned short wChar;
    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, size_t count);                 // 0x00526610
};

struct D2CharStrc
{
    unsigned short wChar;
    unsigned char unk0x02;
    unsigned char nWidth;
};

struct D2FontStrc
{
    unsigned int dwHeader;
    unsigned short unk0x04;
    unsigned short unk0x06;
    unsigned short unk0x08;
    unsigned char nHeight;
    unsigned char unk0x0B;
};


extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0
extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC
extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern int gnFontMetric2_0072E004;                                                                          // 0x0072E004
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                              // 0x004F59B0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
static int shim_2;
void __stdcall shim_1(int nLength, int nY, int nWidth, int nPalette, int bCentered);

__declspec(noinline) static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText);
__declspec(noinline) static int sub_005019C0_GetTextHeight(const Unicode* pText);
__declspec(noinline) static void __stdcall sub_00501A80_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nPalette, int bCentered);

// 0x00501840
static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 525);
    int nWidth = 0;
    int nMax = 0;
    const int nLength = sub_00526800((const unsigned short*)pText);
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
static int sub_005019C0_GetTextHeight(const Unicode* pText)
{
    D2_ASSERT(pText, 606);

    int nLines = 1;
    int nLength = sub_00526800((const unsigned short*)pText);
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

// calling-convention shim (not game code)
static void __stdcall sub_00501A80_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nPalette, int bCentered)
{
    shim_2 = nX;
    const int nLength = sub_00526800((const unsigned short*)wszText);
    shim_1(nLength, nY, nWidth, nPalette, bCentered);
}

static __forceinline void sub_005023B0_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight)
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
