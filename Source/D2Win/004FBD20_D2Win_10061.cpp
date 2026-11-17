enum D2WinControlType
{
    D2WIN_TEXTBOX = 4,
};

struct Unicode;
struct D2CelFileStrc;
struct D2WinScrollBarStrc;

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

// 0x004FBD20
int __fastcall D2Win_10061(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x309);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x30A);

    int nLineCount = 0;
    for (D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine; pLine; pLine = pLine->pNext)
    {
        if (!pLine->pNext)
        {
            break;
        }

        ++nLineCount;
    }

    return nLineCount;
}
