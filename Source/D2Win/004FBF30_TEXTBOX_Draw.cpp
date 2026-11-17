struct D2CellFileStrc;

struct Unicode
{
    unsigned short wChar;
};

struct D2GfxDataStrc
{
    int nFrame;
    char unk0x04[0x30];
    D2CellFileStrc* pCellFile;
    char unk0x38[0x08];
    int nDirection;
    char unk0x44[0x04];
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
    D2CellFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char unk0x1C[0x24];
    int field_40;
    int field_44;
    void* pFirstLine;
    void* pLastLine;
    D2WinTextBoxLineStrc* pCurrentLine;
    int nNumLines;
    int nLine;
    unsigned int dwTextBoxFlags;
    int nCurrentLine;
    int nNumColumns;
    int unk0x68[5];
    int unk0x7C[5];
    void* pScrollBar;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern int gdwGlobal_00841B70;                                                                              // 0x00841B70
extern int gnTextBoxLineGap_0072DE90;                                                                       // 0x0072DE90
int __cdecl sub_00525150();                                                                         // 0x00525150
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0
void __fastcall sub_005025C0_DrawFramedText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int eDrawMode, int nTextColor); // 0x005025C0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __fastcall sub_00501FE0_DrawTickerText(const Unicode* wszText, int nX, int nY, int nColor, int nScroll, int nWidth); // 0x00501FE0

// 0x004FB5A0
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

// 0x004FBEE0
static int __stdcall sub_004FBEE0(int nWidth, Unicode* wszText)
{
    int i = 0;
    const int nLength = sub_00526800(wszText);
    while (i < nLength)
    {
        if (D2Win_10122(wszText, i + 1) >= nWidth)
        {
            break;
        }
        ++i;
    }

    wszText[i].wChar = 0;
    return i;
}

// 0x004FBF30
int __fastcall TEXTBOX_Draw(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x3BC);
    D2_ASSERT(pTextBox->nType == 4, 0x3BD);

    if (!(pTextBox->dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0x40, 0x40, 0x40);

    D2CellFileStrc* pCellFile = pTextBox->pCellFile;
    if (pCellFile)
    {
        D2GfxDataStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCellFile = pCellFile;
        tGfxData.nDirection = 0;
        tGfxData.nFrame = 0;
        TEXTURE_CelDraw(&tGfxData, pTextBox->nImageX, pTextBox->nImageY - 1, -1, 5, 0);
    }

    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
    sub_00502EF0(pTextBox->eFont);

    const int v51 = pTextBox->nImageX + pTextBox->field_40;
    int nY = D2Win_10125() + (pTextBox->nImageY - pTextBox->nHeight) + pTextBox->field_44;

    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);

    const int v8 = D2Win_10125() + pTextBox->field_A8;
    int v49 = pTextBox->nHeight - 2 * pTextBox->field_44;
    const int nBoxWidth = pTextBox->nWidth - 2 * pTextBox->field_40;

    if (pTextBox->dwTextBoxFlags & 0x40)
    {
        D2WinTextBoxLineStrc* pCurrentLine = pTextBox->pCurrentLine;
        if (pCurrentLine)
        {
            pTextBox->field_9C -= 2;
            if (pTextBox->field_9C < -sub_00501820(pCurrentLine->pColumns[0]))
            {
                pTextBox->field_9C = nBoxWidth;
            }
        }
    }

    if (pTextBox->dwTextBoxFlags & 0x80)
    {
        D2WinTextBoxLineStrc* pCurrentLine = pTextBox->pCurrentLine;
        if (pCurrentLine)
        {
            pTextBox->field_9C -= 2;
            if (pTextBox->field_9C < -v8)
            {
                pTextBox->field_9C = 0;
                pTextBox->pCurrentLine = pCurrentLine->pNext;
            }
        }
    }

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCounter = 0;
    if (pLine)
    {
        do
        {
            for (int i = 0; i < pTextBox->nNumColumns; ++i)
            {
                const Unicode* wszColumn = pLine->pColumns[i];
                if (!wszColumn)
                {
                    break;
                }

                int v48 = pTextBox->nWidth;
                if (i < pTextBox->nNumColumns - 1)
                {
                    v48 = pTextBox->unk0x68[i + 1];
                }

                const int v16 = pTextBox->unk0x68[i];
                int nX;
                if (v16)
                {
                    nX = v16 + v51;

                    int v18;
                    if (i + 1 < pTextBox->nNumColumns)
                    {
                        v18 = pTextBox->unk0x68[i + 1] - v16;
                        v48 = v18;
                    }
                    else
                    {
                        v48 = pTextBox->nWidth - v16;
                        v18 = v48;
                    }

                    if (pTextBox->unk0x7C[i] & 2)
                    {
                        int nOffset = (v18 - sub_00501820(*(const Unicode* volatile*)&wszColumn)) / 2;
                        if (nOffset < 0)
                        {
                            nOffset = 0;
                        }
                        nX += nOffset;
                    }
                    else if (pTextBox->unk0x7C[i] & 0x10)
                    {
                        int nTextWidth = sub_00501820(wszColumn);
                        if (nTextWidth < 0)
                        {
                            nTextWidth = 0;
                        }
                        nX += v48 - nTextWidth;
                    }
                }
                else if (pTextBox->dwTextBoxFlags & 2)
                {
                    int nOffset = (pTextBox->nWidth - sub_00501820(pLine->pColumns[0])) / 2;
                    if (nOffset < 0)
                    {
                        nOffset = 0;
                    }
                    nX = pTextBox->nImageX + nOffset;
                }
                else if (pTextBox->dwTextBoxFlags & 0x10)
                {
                    int nTextWidth = sub_00501820(pLine->pColumns[0]);
                    if (nTextWidth < 0)
                    {
                        nTextWidth = 0;
                    }
                    nX = pTextBox->nImageX - nTextWidth;
                }
                else
                {
                    nX = v51;
                }

                Unicode wszText[1024];
                for (int j = 0; j < 1024; ++j)
                {
                    wszText[j].wChar = 0;
                }
                sub_005267E0(wszText, pLine->pColumns[i]);
                sub_004FBEE0(v48, wszText);

                if (pTextBox->nCurrentLine == nCounter + pTextBox->nLine && (pTextBox->dwTextBoxFlags & 1))
                {
                    const int nLineColor = pLine->field_14 != 4 ? pLine->field_14 : 0;
                    if (!i)
                    {
                        sub_005025C0_DrawFramedText(wszText, nX, nY, nBoxWidth, nColor, 5, nLineColor);
                    }
                    else
                    {
                        sub_00502320(wszText, nX, nY, nLineColor, 0);
                    }
                }
                else if (pTextBox->dwTextBoxFlags & 0x40)
                {
                    sub_00501FE0_DrawTickerText(pLine->pColumns[i], nX, nY, pLine->field_14, pTextBox->field_9C, nBoxWidth);
                }
                else if (pTextBox->dwTextBoxFlags & 0x80)
                {
                    sub_00502320(wszText, nX, nY + pTextBox->field_9C, pLine->field_14, 0);
                }
                else
                {
                    sub_00502320(wszText, nX, nY, pLine->field_14, 0);
                }
            }

            const int v34 = (!pLine->field_18 ? pTextBox->field_A4 : pTextBox->field_A0) + v8;
            ++nCounter;
            nY += v34;
            v49 -= v34;
            pLine = pLine->pNext;
        }
        while (pLine && v49 >= (!pLine->field_18 ? pTextBox->field_A4 : pTextBox->field_A0) + v8);
    }

    sub_00502EF0(1);
    return 1;
}
