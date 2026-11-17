#include "D2Win.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CharStrc;

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

struct Unicode
{
    unsigned short wChar;
};

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
extern int gnFontMetric2_0072E004;                                                                          // 0x0072E004
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8

// 0x00501A40
int __stdcall D2Win_10125()
{
    return gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight;
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

void __fastcall sub_M98_Emit_005019C0(const Unicode* pText, int* pHeight, int nExtra)
{
    *pHeight = sub_005019C0_GetTextHeight(pText) + nExtra;
}

#include "gen/data/Source/D2Win/Src/D2WinFont_00501A40.inc"
