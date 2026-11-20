struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2WinScrollBarStrc;

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
    int eType;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl isspace(int c);                                                                      // 0x00687006
extern "C" const char szD2WinTextBoxCpp_006DC840[];                                                         // 0x006DC840
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0
int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FBAB0
extern "C" int __fastcall sub_00507EF0_GetScrollBarField48(D2WinScrollBarStrc* ptScrollbarData); // 0x00507EF0
extern "C" int __fastcall sub_00507FA0_GetScrollBarField4C(D2WinScrollBarStrc* ptScrollbarData); // 0x00507FA0
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps);                        // 0x00507F20
int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep);                  // 0x00507F60

int __fastcall sub_004FCDA0_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent); // 0x004FCDA0

static __declspec(noinline) int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox);
static int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox); // 0x004FBE90

static int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x393);
    D2_ASSERT(pTextBox->eType == 4, 0x394);

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCount = 0;
    while (pLine)
    {
        pLine = pLine->pNext;
        ++nCount;
    }

    return nCount;
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FC9B0
int __fastcall D2Win_10051(D2WinTextBoxStrc* ptTextData, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent)
{
    D2_ASSERT(ptTextData, 0x132);
    D2_ASSERT(ptTextData->eType == 4, 0x133);

    Unicode wszBuffer[0x400];
    sub_005267E0(wszBuffer, wszText);

    const Unicode* pText = wszBuffer;
    while (pText->wChar)
    {
        if (pText->wChar >= 0x100 || !isspace(pText->wChar))
            break;

        ++pText;
    }

    sub_00502EF0(ptTextData->eFont);

    if (!(ptTextData->dwTextBoxFlags & 0x20))
    {
        int nMaxWidth = ptTextData->nWidth - 2 * ptTextData->field_40;
        if (nIndent == 2)
        {
            Unicode wszSpaces[6];
            wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
            wszSpaces[5].wChar = 0;
            nMaxWidth -= sub_00501820(wszSpaces);
        }

        if (D2Win_10122(pText, 0xFF) >= nMaxWidth)
            return sub_004FCDA0_AddWrappedText(ptTextData, pText, nColor, nIndent);
    }

    D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), szD2WinTextBoxCpp_006DC840, 0x15D, 0);
    if (nIndent == 2)
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 6), szD2WinTextBoxCpp_006DC840, 0x161, 0);
        pLine->pColumns[0][4].wChar = 0x20;
        pLine->pColumns[0][3].wChar = pLine->pColumns[0][4].wChar;
        pLine->pColumns[0][2].wChar = pLine->pColumns[0][3].wChar;
        pLine->pColumns[0][1].wChar = pLine->pColumns[0][2].wChar;
        pLine->pColumns[0][0].wChar = pLine->pColumns[0][1].wChar;
        sub_005267E0(pLine->pColumns[0] + 5, pText);
    }
    else
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 1), szD2WinTextBoxCpp_006DC840, 0x167, 0);
        sub_005267E0(pLine->pColumns[0], pText);
    }

    pLine->pColumns[1] = 0;
    pLine->pColumns[2] = 0;
    pLine->pColumns[3] = 0;
    pLine->pColumns[4] = 0;
    pLine->field_14 = nColor;
    pLine->field_18 = bIsWrapped;
    pLine->pNext = 0;
    int bScrolled = 0;

    if (!ptTextData->pFirstLine)
    {
        ++ptTextData->nNumLines;
        ptTextData->pFirstLine = pLine;
        ptTextData->pLastLine = pLine;
        ptTextData->pCurrentLine = pLine;
    }
    else
    {
        ptTextData->pLastLine->pNext = pLine;
        ++ptTextData->nNumLines;
        ptTextData->pLastLine = pLine;

        const int nVisible = D2Win_10055(ptTextData);
        if (sub_004FBE90_CountLinesFromCurrent(ptTextData) > nVisible)
        {
            D2WinScrollBarStrc* pScrollBar = ptTextData->pScrollBar;
            if (!pScrollBar || sub_00507FA0_GetScrollBarField4C(pScrollBar) == sub_00507EF0_GetScrollBarField48(ptTextData->pScrollBar))
            {
                bScrolled = 1;
                ptTextData->pCurrentLine = ptTextData->pCurrentLine->pNext;
                ++ptTextData->nLine;
            }
        }
    }

    if (ptTextData->pScrollBar)
    {
        const int nStep = sub_00507FA0_GetScrollBarField4C(ptTextData->pScrollBar);
        SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, ptTextData->nNumLines - D2Win_10055(ptTextData));
        if (bScrolled)
            SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, ptTextData->nLine);
        else
            SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nStep);
    }

    return 1;
}
