#include "D2CelContext.h"
#include "D2WinTypes.h"
#include "D2WinTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

static __declspec(noinline) void __stdcall sub_00501C30_DrawFontText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode);

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
                TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, eDrawMode, nColor);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, eDrawMode, nColor);

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

// 0x00502360
void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode)
{
    int nWidth = 0;
    if (bCentered)
        nWidth = sub_00501840_GetMultiLineTextWidth(wszText) + 8;
    sub_00501C30_DrawFontText(wszText, nX, nY, nWidth, nColor, bCentered, eDrawMode);
}
