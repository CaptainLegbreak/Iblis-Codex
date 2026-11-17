enum D2WinControlType
{
    D2WIN_TEXTBOX = 4,
};

struct D2CelFileStrc;
struct D2WinScrollBarStrc;
struct D2WinTextBoxLineStrc;

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

extern "C" void __fastcall sub_005080C0_SetScrollBarField50(D2WinScrollBarStrc* pScrollBar, int nValue);   // 0x005080C0

// 0x004FB910
int __fastcall D2Win_10052_TEXTBOX_GetNumLines(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x23E);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x23F);

    return pTextBox->nNumLines;
}

// 0x004FC720
void __fastcall D2Win_10204(D2WinTextBoxStrc* pTextBox, int nPosition)
{
    D2_ASSERT(pTextBox, 0x5B4);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x5B5);

    sub_005080C0_SetScrollBarField50(pTextBox->pScrollBar, nPosition);
}
