extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode
{
    unsigned short wChar;
};

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

struct D2CharStrc
{
    unsigned short wChar;
    unsigned char unk0x02;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short nImageIndex;
    unsigned short unk0x0A[2];
};

struct D2FontStrc
{
    unsigned int dwHeader;
    unsigned short unk0x04;
    unsigned short unk0x06;
    unsigned short unk0x08;
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile;
    D2FontStrc* pFontInfo[2];
    D2CharStrc* pCharInfo;
    unsigned int dwShiftedTickCount;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FBAB0
void __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps);                       // 0x00507F20
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern D2FontCacheStrc gFontCache_00841DA8[];                                                               // 0x00841DA8

// 0x004FCC40
int __fastcall D2Win_10198(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int nCount, int nValue, char nFlag)
{
    D2_ASSERT(pTextBox, 0x1A7);
    D2_ASSERT(pTextBox->controlHeader.nType == 4, 0x1A8);

    const int nSize = sizeof(Unicode) * (sub_00526800(pText) + 1);
    for (int i = 0; i < nCount; ++i)
    {
        D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), ".\\Src\\D2WinTextBox.cpp", 0x1AF, 0);
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(nSize, ".\\Src\\D2WinTextBox.cpp", 0x1B0, 0);
        sub_005267E0(pLine->pColumns[0], pText);
        for (int j = 1; j < 5; ++j)
        {
            pLine->pColumns[j] = 0;
        }

        pLine->field_14 = nValue;
        pLine->field_18 = nFlag;
        pLine->pNext = 0;

        if (!pTextBox->pFirstLine)
        {
            pTextBox->pFirstLine = pLine;
        }
        else
        {
            pTextBox->pLastLine->pNext = pLine;
        }

        pTextBox->pLastLine = pLine;
        ++pTextBox->nNumLines;
    }

    if (pTextBox->pScrollBar)
    {
        SCROLLBAR_SetMaxSteps(pTextBox->pScrollBar, pTextBox->nNumLines - D2Win_10055(pTextBox));
    }

    return 1;
}

// 0x00501690
D2CharStrc* __fastcall sub_6F8AA140(unsigned short wChar)
{
    int nIterations = 0;
    int nMin = 0;
    D2FontCacheStrc* pFontCache = &gFontCache_00841DA8[gnCurrentFont_0072DFFC];
    int nMax = pFontCache->pFontInfo[1]->unk0x08 - 1;
    if (nMax >= 0)
    {
        D2CharStrc* pCharInfo = pFontCache->pCharInfo;
        do
        {
            const int nMid = (nMin + nMax) / 2;
            ++nIterations;
            if (wChar == pCharInfo[nMid].wChar)
            {
                return &pCharInfo[nMid];
            }

            if (wChar < pCharInfo[nMid].wChar)
            {
                nMax = nMid - 1;
            }
            else
            {
                nMin = nMid + 1;
            }

            if (nIterations > 1000)
            {
                break;
            }
        }
        while (nMax >= nMin);
    }

    return pFontCache->pCharInfo + 31;
}
