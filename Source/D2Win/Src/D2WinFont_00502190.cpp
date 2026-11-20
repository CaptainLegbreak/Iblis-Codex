#include "D2CelContext.h"
#include "D2WinTypes.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"
struct D2CelFileStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern D2FontCacheStrc* gpFontCache_00841D88;                                                               // 0x00841D88
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(unsigned short wChar);                             // 0x00841DA0
extern D2FontCacheStrc gFontCache_00841DA8[];                                                               // 0x00841DA8

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
            D2CharStrc* pChar = gpfGetCharInfo_00841DA0(wc.wChar);
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

// 0x005023A0
void __fastcall sub_005023A0_DrawFontText(const Unicode* pText, int nX, int nY)
{
    sub_00502190_DrawFontText(pText, nX, nY);
}
