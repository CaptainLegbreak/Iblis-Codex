#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

enum D2WinControlType
{
    D2WIN_TEXTBOX = 4,
};

enum TextBoxFlags
{
    TEXTBOXFLAG_NO_WORD_WRAP = 0x20,
};

struct Unicode
{
    unsigned short wChar;
};

struct D2CelFileStrc;
struct D2WinScrollBarStrc;
struct SMSGHANDLER_PARAMS;

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
    int unk0x68[5];
    int unk0x7C[5];
    D2WinScrollBarStrc* pScrollBar;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps);                        // 0x00507F20
int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep);                  // 0x00507F60
extern "C" int __fastcall sub_00507FA0_GetScrollBarField4C(D2WinScrollBarStrc* pScrollBar);                // 0x00507FA0
int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox);            // 0x00507FD0
int __fastcall sub_00508000_SetScrollCallback(D2WinScrollBarStrc* pScrollBar, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x00508000

// 0x004FB870
void __fastcall D2Win_10197(D2WinTextBoxStrc* pTextBox, int nLineNum)
{
    D2_ASSERT(pTextBox, 0x21D);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x21E);
    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x21F);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }
        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x229);
    D2_ASSERT(i == nLineNum, 0x22A);

    for (int j = 0; j < 5; ++j)
    {
        if (pLine->pColumns[j])
        {
            FOG_Free(pLine->pColumns[j], ".\\Src\\D2WinTextBox.cpp", 0x231, 0);
            pLine->pColumns[j] = 0;
        }
    }
}

// 0x004FB950
int __fastcall D2Win_10054(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x24A);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x24B);

    return pTextBox->nLine;
}

// 0x004FB990
int __fastcall D2Win_10049(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x256);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x257);

    return pTextBox->nCurrentLine;
}

// 0x004FB9D0
void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* pTextBox, int nLine)
{
    D2_ASSERT(pTextBox, 0x262);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x263);

    pTextBox->nCurrentLine = D2_MIN(D2_MAX(nLine, -1), pTextBox->nNumLines - 1);
}

// 0x004FBA30
int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine)
{
    D2_ASSERT(pTextBox, 0x271);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x272);

    nLine = nLine < pTextBox->nNumLines ? nLine : pTextBox->nNumLines;

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    for (int i = 0; i < nLine; ++i)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
    }

    if (pLine)
    {
        pTextBox->pCurrentLine = pLine;
        pTextBox->nLine = nLine;
    }

    if (pTextBox->pScrollBar)
    {
        SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, nLine);
    }

    return 1;
}

// 0x004FBC20
void __fastcall D2Win_10056(D2WinTextBoxStrc* pTextBox, int nNumColumns)
{
    D2_ASSERT(pTextBox, 0x2DD);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x2DE);
    D2_ASSERT((nNumColumns > 0) && (nNumColumns <= 5), 0x2E0);
    D2_ASSERT(pTextBox->nNumColumns <= nNumColumns, 0x2E2);

    pTextBox->nNumColumns = nNumColumns;

    if (nNumColumns > 1)
    {
        pTextBox->dwTextBoxFlags |= TEXTBOXFLAG_NO_WORD_WRAP;
    }
}

// 0x004FC5E0
int __fastcall D2Win_10191(D2WinTextBoxStrc* pTextBox, int nMaxSteps)
{
    D2_ASSERT(pTextBox, 0x582);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x583);

    return SCROLLBAR_SetMaxSteps(pTextBox->pScrollBar, nMaxSteps);
}

// 0x004FC620
int __fastcall D2Win_10192(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x58C);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x58D);

    return sub_00507FA0_GetScrollBarField4C(pTextBox->pScrollBar);
}

// 0x004FC660
int __fastcall D2Win_10193(D2WinTextBoxStrc* pTextBox, int nCurrentStep)
{
    D2_ASSERT(pTextBox, 0x596);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x597);

    return SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, nCurrentStep);
}

// 0x004FC6A0
int __fastcall D2Win_10194(D2WinTextBoxStrc* pTextBox, D2WinTextBoxStrc* pLinkedTextBox)
{
    D2_ASSERT(pTextBox, 0x5A0);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x5A1);

    return SCROLLBAR_SetTextBox(pTextBox->pScrollBar, pLinkedTextBox);
}

// 0x004FC6E0
int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*))
{
    D2_ASSERT(pTextBox, 0x5AA);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x5AB);

    return sub_00508000_SetScrollCallback(pTextBox->pScrollBar, pfScrollCallback);
}
