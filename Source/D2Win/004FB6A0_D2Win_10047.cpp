struct Unicode
{
    unsigned short wChar;
};

struct D2CelFileStrc;

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
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x004FB6A0
int __fastcall D2Win_10047(D2WinTextBoxStrc* pTextBox)
{
    if (!pTextBox)
        return 0;

    D2_ASSERT(pTextBox->controlHeader.nType == 4, 0xDE);

    D2WinTextBoxLineStrc* pNext = 0;
    for (D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine; pLine; pLine = pNext)
    {
        pNext = pLine->pNext;
        for (int i = 0; i < 5; ++i)
        {
            if (pLine->pColumns[i])
                FOG_Free(pLine->pColumns[i], ".\\Src\\D2WinTextBox.cpp", 0xE7, 0);
        }
        FOG_Free(pLine, ".\\Src\\D2WinTextBox.cpp", 0xE9, 0);
    }

    pTextBox->pCurrentLine = 0;
    pTextBox->pFirstLine = 0;
    pTextBox->pLastLine = 0;
    pTextBox->nNumLines = 0;
    pTextBox->nLine = 0;
    return 1;
}
