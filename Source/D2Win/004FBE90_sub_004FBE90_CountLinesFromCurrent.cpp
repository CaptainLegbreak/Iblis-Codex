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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl isspace(int c);                                                                      // 0x00687006
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
int __fastcall SCROLLBAR_GetMaxSteps(D2WinScrollBarStrc* pScrollBar);                                       // 0x00507EF0
int __fastcall SCROLLBAR_GetCurrentStep(D2WinScrollBarStrc* pScrollBar);                                    // 0x00507FA0
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps);                        // 0x00507F20
int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep);                  // 0x00507F60

int __fastcall sub_004FCDA0_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent);

// 0x004FBE90
static __declspec(noinline) int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x393);
    D2_ASSERT(pTextBox->nType == 4, 0x394);

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCount = 0;
    while (pLine)
    {
        pLine = pLine->pNext;
        ++nCount;
    }

    return nCount;
}

static __forceinline int sub_B03_AddLineRecord(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int nColor, char bIsWrapped, int nIndent)
{
    D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), ".\\Src\\D2WinTextBox.cpp", 0x15D, 0);
    Unicode* pDest;
    if (nIndent == 2)
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 6), ".\\Src\\D2WinTextBox.cpp", 0x161, 0);
        pLine->pColumns[0][4].wChar = 0x20;
        pLine->pColumns[0][3].wChar = pLine->pColumns[0][4].wChar;
        pLine->pColumns[0][2].wChar = pLine->pColumns[0][3].wChar;
        pLine->pColumns[0][1].wChar = pLine->pColumns[0][2].wChar;
        pLine->pColumns[0][0].wChar = pLine->pColumns[0][1].wChar;
        pDest = pLine->pColumns[0] + 5;
    }
    else
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x167, 0);
        pDest = pLine->pColumns[0];
    }
    sub_005267E0(pDest, pText);

    pLine->pColumns[1] = 0;
    pLine->pColumns[2] = 0;
    pLine->pColumns[3] = 0;
    pLine->pColumns[4] = 0;
    pLine->field_14 = nColor;
    pLine->field_18 = bIsWrapped;
    pLine->pNext = 0;

    int bScrolled = 0;
    if (!pTextBox->pFirstLine)
    {
        ++pTextBox->nNumLines;
        pTextBox->pFirstLine = pLine;
        pTextBox->pLastLine = pLine;
        pTextBox->pCurrentLine = pLine;
    }
    else
    {
        pTextBox->pLastLine->pNext = pLine;
        ++pTextBox->nNumLines;
        pTextBox->pLastLine = pLine;

        const int nVisible = D2Win_10055(pTextBox);
        if (sub_004FBE90_CountLinesFromCurrent(pTextBox) > nVisible)
        {
            D2WinScrollBarStrc* pScrollBar = pTextBox->pScrollBar;
            if (!pScrollBar || SCROLLBAR_GetMaxSteps(pScrollBar) == SCROLLBAR_GetCurrentStep(pScrollBar))
            {
                bScrolled = 1;
                pTextBox->pCurrentLine = pTextBox->pCurrentLine->pNext;
                ++pTextBox->nLine;
            }
        }
    }

    if (pTextBox->pScrollBar)
    {
        const int nStep = SCROLLBAR_GetCurrentStep(pTextBox->pScrollBar);
        SCROLLBAR_SetMaxSteps(pTextBox->pScrollBar, pTextBox->nNumLines - D2Win_10055(pTextBox));
        if (bScrolled)
            SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, pTextBox->nLine);
        else
            SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, nStep);
    }

    return 1;
}

int __fastcall D2Win_10051(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent)
{
    D2_ASSERT(pTextBox, 0x132);
    D2_ASSERT(pTextBox->nType == 4, 0x133);

    Unicode wszBuffer[0x400];
    sub_005267E0(wszBuffer, wszText);

    const Unicode* pText = wszBuffer;
    while (pText->wChar)
    {
        if (pText->wChar >= 0x100 || !isspace(pText->wChar))
            break;

        ++pText;
    }

    sub_00502EF0(pTextBox->eFont);

    if (!(pTextBox->dwTextBoxFlags & 0x20))
    {
        int nMaxWidth = pTextBox->nWidth - 2 * pTextBox->field_40;
        if (nIndent == 2)
        {
            Unicode wszSpaces[6];
            wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
            wszSpaces[5].wChar = 0;
            nMaxWidth -= sub_00501820(wszSpaces);
        }

        if (D2Win_10122(pText, 0xFF) >= nMaxWidth)
            return sub_004FCDA0_AddWrappedText(pTextBox, pText, nColor, nIndent);
    }

    return sub_B03_AddLineRecord(pTextBox, pText, nColor, bIsWrapped, nIndent);
}

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

    Unicode* pCopy = (Unicode*)SMemAlloc(0x800, ".\\Src\\D2WinTextBox.cpp", 0x497, 0);
    Unicode* pCopyToFree = pCopy;
    sub_005267E0(pCopy, wszText);

    int nSplit = 0;
    const int nLength = sub_00526800(pCopy);
    Unicode* pRest = pCopy;
    Unicode* pSpace = 0;
    for (Unicode* pScan = pCopy; nSplit < nLength; pScan = pRest)
    {
        if (pScan->wChar == 0x20)
            pSpace = pScan;

        const int nNext = nSplit + 1;
        if (D2Win_10122(wszText, nNext) >= nMaxWidth)
        {
            if (pSpace)
            {
                nSplit = pSpace - pCopy;
                pRest = pSpace;
            }
            break;
        }

        ++pRest;
        nSplit = nNext;
    }

    Unicode* pFirst = (Unicode*)SMemAlloc(0x800, ".\\Src\\D2WinTextBox.cpp", 0x4B7, 0);
    Unicode* pSecond = (Unicode*)SMemAlloc(0x800, ".\\Src\\D2WinTextBox.cpp", 0x4B8, 0);
    sub_00526790(pFirst, pCopyToFree, nSplit);
    pFirst[nSplit].wChar = 0;
    const int nRest = nLength - nSplit;
    sub_00526790(pSecond, pRest, nRest);
    pSecond[nRest].wChar = 0;
    SMemFree(pCopyToFree, ".\\Src\\D2WinTextBox.cpp", 0x4BF, 0);

    D2Win_10051(pTextBox, pFirst, nColor, 1, nIndent);
    if (nIndent == 1)
        nIndent = 2;
    D2Win_10051(pTextBox, pSecond, nColor, 0, nIndent);

    SMemFree(pFirst, ".\\Src\\D2WinTextBox.cpp", 0x4C4, 0);
    SMemFree(pSecond, ".\\Src\\D2WinTextBox.cpp", 0x4C5, 0);
    return 1;
}
