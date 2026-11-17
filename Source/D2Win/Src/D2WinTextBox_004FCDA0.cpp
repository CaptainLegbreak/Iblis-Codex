#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WinControlStrc;
struct Unicode;
struct D2WinTextBoxLineStrc;
struct D2WinTextBoxStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
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
    int nType;
    int unk0x04[4];
    int nWidth;
    int unk0x18[10];
    int field_40;
    int field_44;
    D2WinTextBoxLineStrc* pFirstLine;
    D2WinTextBoxLineStrc* pLastLine;
    D2WinTextBoxLineStrc* pCurrentLine;
    int nNumLines;
    int nLine;
    unsigned int dwTextBoxFlags;
    int unk0x60[12];
    D2WinScrollBarStrc* pScrollBar;
    int eFont;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char szD2WinTextBoxCpp_006DC840[]; // 0x006DC840
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0
int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps); // 0x00507F20
int __fastcall D2Win_10051(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn); // 0x004FB790
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
int __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FCDA0
int __fastcall sub_004FCDA0_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent)
{
    D2_ASSERT(pTextBox, 0x482);
    D2_ASSERT(pTextBox->nType == 4, 0x483);

    int nMaxWidth = pTextBox->nWidth - 2 * pTextBox->field_40;
    if (nIndent == 2)
    {
        Unicode wszSpaces[6];
        wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
        wszSpaces[5].wChar = 0;
        nMaxWidth -= sub_00501820(wszSpaces);
    }

    Unicode* pBuffer = (Unicode*)SMemAlloc(0x800, szD2WinTextBoxCpp_006DC840, 0x497, 0);
    Unicode* pText = pBuffer;
    sub_005267E0(pText, wszText);

    int nSplit = 0;
    const int nLength = sub_00526800(pText);
    Unicode* pChar = pText;
    Unicode* pSpace = 0;
    while (nSplit < nLength)
    {
        if (pChar->wChar == 0x20)
            pSpace = pChar;

        const int nNext = nSplit + 1;
        if (D2Win_10122(wszText, nNext) >= nMaxWidth)
        {
            if (pSpace)
            {
                nSplit = pSpace - pText;
                pChar = pSpace;
            }
            break;
        }

        ++pChar;
        ++nSplit;
    }

    Unicode* pFirst = (Unicode*)SMemAlloc(0x800, szD2WinTextBoxCpp_006DC840, 0x4B7, 0);
    pText = (Unicode*)SMemAlloc(0x800, szD2WinTextBoxCpp_006DC840, 0x4B8, 0);
    sub_00526790(pFirst, pBuffer, nSplit);
    pFirst[nSplit].wChar = 0;
    sub_00526790(pText, pChar, nLength - nSplit);
    pText[nLength - nSplit].wChar = 0;
    SMemFree(pBuffer, szD2WinTextBoxCpp_006DC840, 0x4BF, 0);

    D2Win_10051(pTextBox, pFirst, nColor, 1, nIndent);
    D2Win_10051(pTextBox, pText, nColor, 0, nIndent == 1 ? 2 : nIndent);

    SMemFree(pFirst, szD2WinTextBoxCpp_006DC840, 0x4C4, 0);
    SMemFree(pText, szD2WinTextBoxCpp_006DC840, 0x4C5, 0);
    return 1;
}

// 0x004FCD40
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int a3, int a4)
{
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    return D2Win_10058_0(pControl, wszText, a3, a4);
}

// 0x004FCF80
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText)
{
    D2_ASSERT(pControl, 0x109);
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pControl, wszText, 4, 0, 0);
}

// 0x004FFE10
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText)
{
    Unicode wszText[256];
    sub_00526F20_ToUnicode(wszText, szText, 256);
    return sub_004FF5A0_SetEditText(pControl, wszText);
}
