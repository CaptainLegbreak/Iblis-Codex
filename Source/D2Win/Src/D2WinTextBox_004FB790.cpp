#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"
#include "D2Unicode.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FB790
int __fastcall sub_004FB790(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int a3, int nColumn)
{
    D2_ASSERT(pTextBox, 0x1F9);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x1FA);
    D2_ASSERT(pTextBox->nNumColumns > nColumn, 0x1FB);

    Unicode wszText[1024];
    sub_005267E0(wszText, pText);

    D2WinTextBoxLineStrc* ptLine = pTextBox->pFirstLine;
    for (int i = 0; i < a3; ++i)
    {
        if (!ptLine)
            return 1;

        ptLine = ptLine->pNext;
    }

    if (ptLine)
    {
        D2_ASSERT(ptLine->pColumns[nColumn] == 0, 0x20F);
        ptLine->pColumns[nColumn] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(wszText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x210, 0);
        sub_005267E0(ptLine->pColumns[nColumn], wszText);
    }

    return 1;
}
