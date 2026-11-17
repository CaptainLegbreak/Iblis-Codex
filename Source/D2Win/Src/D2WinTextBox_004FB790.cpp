#include "D2Win.h"

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    void* pfDraw;
    void* pfInitialize;
    void* pfHandleMouseDown;
    void* pfHandleMouseUp;
    void* pfHandleCharInput;
    void* pfHandleVirtualKeyInput;
    void* field_34;
    void* pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinTextBoxLineStrc
{
    Unicode* pColumns[5];
    int field_14;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    D2WinTextBoxLineStrc* pNext;
};

struct D2WinTextBoxStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    D2WinTextBoxLineStrc* pFirstLine;
    D2WinTextBoxLineStrc* pLastLine;
    D2WinTextBoxLineStrc* pCurrentLine;
    int nNumLines;
    int nLine;
    int dwTextBoxFlags;
    int nCurrentLine;
    int nNumColumns;
};
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
    D2_ASSERT(pTextBox->controlHeader.nType == 4, 0x1FA);
    D2_ASSERT(pTextBox->nNumColumns > nColumn, 0x1FB);

    Unicode wszText[1024];
    sub_005267E0(wszText, pText);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    for (int i = 0; i < a3; ++i)
    {
        if (!pLine)
            return 1;

        pLine = pLine->pNext;
    }

    if (pLine)
    {
        D2_ASSERT(pLine->pColumns[nColumn] == 0, 0x20F);
        pLine->pColumns[nColumn] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(wszText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x210, 0);
        sub_005267E0(pLine->pColumns[nColumn], wszText);
    }

    return 1;
}
