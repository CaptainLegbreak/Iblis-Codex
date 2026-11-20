#include "D2WinTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;

    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, size_t count);                 // 0x00526610
};

extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0
extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC

__declspec(noinline) static int sub_00501840_GetMultiLineTextWidth(const Unicode* pText);

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

void __fastcall sub_Emit_00501840(const Unicode* pText, int* pWidth, int nExtra)
{
    *pWidth = sub_00501840_GetMultiLineTextWidth(pText) + nExtra;
}
