struct D2CellFileStrc;
struct D2WinScrollBarStrc;
struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
};

struct D2WinTextBoxStrc
{
    int nType;
    D2CellFileStrc* pCellFile;
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
    int (__stdcall* field_34)(SMSGHANDLER_PARAMS* pMsg);
    void* pfShouldMouseInputBeHandled;
    void* pNext;
    int field_40;
    int field_44;
    void* pFirstLine;
    void* pLastLine;
    void* pCurrentLine;
    int nNumLines;
    int nLine;
    unsigned int dwTextBoxFlags;
    int nCurrentLine;
    int nNumColumns;
    int unk0x68[10];
    D2WinScrollBarStrc* pScrollBar;
    int eFont;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern int gdwGlobal_00841B70;                                                                              // 0x00841B70
extern int gnTextBoxLineGap_0072DE90;                                                                       // 0x0072DE90
struct tagPOINT { long x; long y; };
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4
#define gnMouseY_007D55A8 (gMousePosition_6F8FE234.y)
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __cdecl sub_00525150();                                                                         // 0x00525150
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __stdcall CONTROL_AppendToList(D2WinTextBoxStrc* pControl);                                             // 0x004F9210
D2WinScrollBarStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6); // 0x005084F0
int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox);            // 0x00507FD0
extern "C" void __fastcall sub_005080C0_SetScrollBarField50(D2WinScrollBarStrc* pScrollBar, int nValue);   // 0x005080C0
int __stdcall TEXTBOX_Draw(SMSGHANDLER_PARAMS* pMsg);                                                       // 0x004FBF30
int __stdcall TEXTBOX_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                      // 0x004FC3F0
int __stdcall TEXTBOX_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);

static void sub_004FB5A0_SetTextBoxLineGap(int nFont)
{
    if (sub_00525150() == 7)
    {
        const int nOldFont = sub_00502EF0(nFont);
        if (D2Win_10125() > 13)
        {
            gnTextBoxLineGap_0072DE90 = 8;
        }
        else
        {
            gnTextBoxLineGap_0072DE90 = (D2Win_10125() > 7) + 6;
        }
        sub_00502EF0(nOldFont);
    }
    else if (sub_00525150() == 9)
    {
        const int nOldFont = sub_00502EF0(nFont);
        if (D2Win_10125() > 13)
        {
            gnTextBoxLineGap_0072DE90 = 8;
        }
        else
        {
            gnTextBoxLineGap_0072DE90 = (D2Win_10125() > 7) + 6;
        }
        if (gdwGlobal_00841B70)
        {
            gnTextBoxLineGap_0072DE90 = 3;
        }
        sub_00502EF0(nOldFont);
    }
    else if (sub_00525150() == 6)
    {
        gnTextBoxLineGap_0072DE90 = gdwGlobal_00841B70 != 0 ? 0 : 4;
    }
    else if (sub_00525150() == 10)
    {
        gnTextBoxLineGap_0072DE90 = gdwGlobal_00841B70 != 0 ? 0 : 4;
    }
    else
    {
        gnTextBoxLineGap_0072DE90 = 4;
    }
}

// 0x004FBAB0
int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x290);
    D2_ASSERT(pTextBox->nType == 4, 0x291);

    sub_00502EF0(pTextBox->eFont);
    const int nHeight = pTextBox->nHeight - 2 * pTextBox->field_44;
    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
    const int nLineHeight = D2Win_10125() + pTextBox->field_A8;
    return (nHeight - nLineHeight) / (nLineHeight + pTextBox->field_A4) + 1;
}

// 0x004FC2F0
int __stdcall TEXTBOX_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)pMsg->hWnd;
    D2_ASSERT(pTextBox, 0x4D0);
    D2_ASSERT(pTextBox->nType == 4, 0x4D1);

    if (!(pTextBox->dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->dwFlags & gdwBitMasks_006CE268[0]) || pTextBox->nNumLines < 1)
    {
        return 0;
    }

    if (pTextBox->dwTextBoxFlags & 1)
    {
        const int nY = pTextBox->nHeight - pTextBox->nImageY + gnMouseY_007D55A8;
        sub_00502EF0(pTextBox->eFont);
        sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
        pTextBox->nCurrentLine = pTextBox->nLine + (nY - pTextBox->field_44) / (D2Win_10125() + pTextBox->field_A8);
        if (pTextBox->dwTextBoxFlags & 8)
        {
            pTextBox->nCurrentLine = D2_MIN(D2_MAX(pTextBox->nCurrentLine, 0), pTextBox->nNumLines - 1);
        }
        else if (pTextBox->nCurrentLine < 0 || pTextBox->nCurrentLine >= pTextBox->nNumLines)
        {
            pTextBox->nCurrentLine = -1;
        }
    }

    if (pTextBox->field_34)
    {
        return pTextBox->field_34(pMsg);
    }
    return 0;
}

// 0x004FC7A0
D2WinTextBoxStrc* __fastcall D2Win_10042_TEXTBOX_Create(int nX, int nY, int nWidth, int nHeight, int nInsetX, int nInsetY, D2CellFileStrc* pCellFile, int (__stdcall* pfCallback)(SMSGHANDLER_PARAMS*), unsigned int dwTextBoxFlags, int* pFontInfo, int* pScrollBarRect)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)FOG_Alloc(0xAC, ".\\Src\\D2WinTextBox.cpp", 0x63, 0);
    memset(pTextBox, 0, 0xAC);

    if ((dwTextBoxFlags & 4) && !pScrollBarRect)
    {
        nWidth -= 0x1A;
    }
    if (dwTextBoxFlags & 1)
    {
        dwTextBoxFlags |= 0x20;
    }

    pTextBox->nType = 4;
    pTextBox->dwFlags |= gdwBitMasks_006CE268[0];
    pTextBox->dwFlags |= gdwBitMasks_006CE268[2];
    pTextBox->pCellFile = pCellFile;
    pTextBox->nImageX = nX;
    pTextBox->nImageY = nY;
    pTextBox->nWidth = nWidth;
    pTextBox->nHeight = nHeight;
    pTextBox->dwTextBoxFlags = dwTextBoxFlags;
    pTextBox->field_40 = nInsetX;
    pTextBox->field_44 = nInsetY;
    pTextBox->pfDraw = TEXTBOX_Draw;
    pTextBox->pfHandleMouseDown = TEXTBOX_HandleMouseDown;
    pTextBox->pfHandleMouseUp = 0;
    pTextBox->pfHandleCharInput = 0;
    const bool bVirtualKey = (dwTextBoxFlags & 1) != 0;
    pTextBox->pfHandleVirtualKeyInput = bVirtualKey ? TEXTBOX_HandleVirtualKeyInput : 0;
    pTextBox->field_34 = pfCallback;
    pTextBox->nCurrentLine = -1;
    pTextBox->pNext = 0;
    pTextBox->pCurrentLine = 0;
    pTextBox->pFirstLine = 0;
    pTextBox->pLastLine = 0;
    pTextBox->nNumLines = 0;
    pTextBox->nLine = 0;
    pTextBox->nNumColumns = 1;

    if (pFontInfo)
    {
        pTextBox->eFont = pFontInfo[0];
        pTextBox->field_98 = pFontInfo[1];
    }
    else
    {
        pTextBox->eFont = 1;
        pTextBox->field_98 = 0;
    }

    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
    pTextBox->field_A8 = gnTextBoxLineGap_0072DE90;

    if (dwTextBoxFlags & 4)
    {
        pTextBox->pCellFile = 0;
        int nScrollX;
        if (pScrollBarRect)
        {
            nScrollX = pScrollBarRect[0];
            nY = pScrollBarRect[1];
            nHeight = pScrollBarRect[2];
        }
        else
        {
            nScrollX = nX + nWidth + 8;
            nY -= 2;
            nHeight -= 0x10;
        }
        pTextBox->pScrollBar = SCROLLBAR_Create(nScrollX, nY, 10, nHeight, pCellFile, 0);
        SCROLLBAR_SetTextBox(pTextBox->pScrollBar, pTextBox);
        int nPosition = D2Win_10055(pTextBox) - 1;
        if (nPosition <= 0)
        {
            nPosition = 1;
        }
        sub_005080C0_SetScrollBarField50(pTextBox->pScrollBar, nPosition);
    }
    else
    {
        pTextBox->pScrollBar = 0;
    }

    CONTROL_AppendToList(pTextBox);
    return pTextBox;
}
