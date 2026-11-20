#include "D2CelContext.h"
extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef unsigned int size_t;

struct D2CelFileStrc;

struct Unicode
{
    unsigned short wChar;

    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, size_t count);
    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count);
};

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
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile;
    D2FontStrc* pFontInfo[2];
    D2CharStrc* pCharInfo;
    unsigned int dwShiftedTickCount;
};


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift);
int __fastcall sub_00526800(const Unicode* pString);
extern "C" int __fastcall sub_00526800_2(const unsigned short* pText);
extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern int gnFontMetric1_0072E000;
extern int gnFontMetric2_0072E004;
extern D2FontCacheStrc* gpFontCache_00841D88;
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8
extern wchar_t gwszMonsterCode_008426DC[2];
extern wchar_t gwszColorCode_008426E0[2];

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

// build: context sub_00501910_GetTextLineWidth
static __declspec(noinline) int sub_00501910_GetTextLineWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 572);
    int nWidth = 0;
    const int nLength = sub_00526800_2((const unsigned short*)pText);
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

static int sub_00501840_IsColorCode(unsigned short wChar)
{
    return wChar == 0xFF;
}

static __declspec(noinline) int sub_00501840_GetMultiLineTextWidth(const Unicode* pText)
{
    int nCount = 0;
    D2_ASSERT(pText, 525);
    int nMax = 0;
    int nWidth = 0;
    const int nLength = sub_00526800(pText);
    for (; nCount < nLength; ++nCount)
    {
        const unsigned short wChar = pText->wChar;
        if (!wChar)
            break;
        if (wChar == '\n')
        {
            if (nWidth > nMax)
                nMax = nWidth;
            nWidth = 0;
        }
        else if (wChar < 0x100 && sub_00501840_IsColorCode(wChar))
        {
            ++pText;
            if (!Unicode::strnicmp(pText, (const Unicode*)gwszMonsterCode_008426DC, 1))
                nWidth += gpfGetCharInfo_00841DA0(*(const int*)gwszMonsterCode_008426DC)->nWidth;
            pText += 2;
            nCount += 2;
            continue;
        }
        else
        {
            nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        }
        ++pText;
    }
    if (nMax > nWidth)
        nWidth = nMax;
    return nWidth;
}

inline int sub_K08_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
        return 0;

    return wChar == 0xFF;
}

static __declspec(noinline) void __stdcall sub_00501A80_DrawTextLine(int nY, int nWidth, int nShift, int bCentre, const Unicode* pText, int nX)
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
                TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
                nX += pChar->nWidth;
            }
        }
        else if (c.wChar != '\n')
        {
            D2CharStrc* pChar = gpfGetCharInfo_00841DA0(c.wChar);
            tContext.nFrame = pChar->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
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

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                             // 0x004F59B0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

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
