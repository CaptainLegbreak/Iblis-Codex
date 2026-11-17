struct Unicode
{
    unsigned short ch;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2DialogWidget
{
    virtual void Unk0();
    virtual void Draw();
};

struct D2DialogWidgetNodeStrc
{
    D2DialogWidget* f_0;
    D2DialogWidgetNodeStrc* pNext;
};

struct D2DialogLineStrc
{
    Unicode wszText[0x78];
    int nHeight;
    int nX;
    int nWidth;
    int nArg4;
    int nFont;
    int nType;
    int (__cdecl* pfnCallback)();
    int bEnabled;
};

struct D2ClientDialogStrc
{
    char unk0x00[0x08];
    void* pCelFile;
    int bDrawCel;
    char unk0x10[0x1C];
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    char unk0x3C[0x8];
    int f_44;
    char unk0x48[0x8];
    int nLines;
    int nDrawCount;
    int bAutoSize;
    int nMode;
    char unk0x60[0x8];
    D2DialogLineStrc pLines[10];
    D2DialogWidgetNodeStrc* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_00452E50_AddDirtyRect(D2RectStrc* pRect);                                               // 0x00452E50
void* __cdecl sub_00453AB0();                                                                               // 0x00453AB0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int gnSelectionFrame_007C0E50;                                                                              // 0x007C0E50

// 0x004B8100
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog)
{
    D2_ASSERT(pDialog, 0x48E);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    ++pDialog->nDrawCount;

    tContext.unk0x40 = 0;
    D2RectStrc tRect;
    tRect.nTop = pDialog->nY;
    tRect.nLeft = pDialog->nX;
    tRect.nRight = pDialog->nX + pDialog->nWidth - 1;
    tRect.nBottom = pDialog->nY + pDialog->nHeight - 1;

    if (pDialog->bDrawCel)
    {
        if (pDialog->pCelFile)
        {
            tContext.pCellFile = pDialog->pCelFile;
            tContext.nFrame = 0;
            sub_004F6480(&tContext, pDialog->nX, pDialog->nY + pDialog->nHeight, -1, 5, 0);
        }
    }
    else
    {
        sub_0046EFD0_DrawFramedBox(tRect.nLeft, tRect.nTop, tRect.nRight - tRect.nLeft + 1, tRect.nBottom - tRect.nTop + 1, 0, 1);
        sub_00452E50_AddDirtyRect(&tRect);
    }

    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_0)
        {
            pNode->f_0->Draw();
        }
    }

    const int nOldFont = sub_00502EF0(1);
    int nOffsetY = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        D2DialogLineStrc* pLine = &pDialog->pLines[i];
        int nColor = pLine->nType;
        sub_00502EF0(pLine->nFont);
        int nLineY = pDialog->nY;
        nLineY += *(volatile int*)&nOffsetY;
        nLineY += pLine->nHeight;
        const int nLineX = pLine->nX + pDialog->nX;
        if (pDialog->f_44 == i)
        {
            if (pDialog->nMode == 1)
            {
                nColor = 3;
            }

            if (pDialog->nMode == 2)
            {
                tContext.pCellFile = sub_00453AB0();
                tContext.nFrame = gnSelectionFrame_007C0E50 % 7;
                sub_004F6480(&tContext, nLineX - 24, nLineY + 4, -1, 5, 0);
                sub_004F6480(&tContext, pLine->nWidth + nLineX + 2, nLineY + 4, -1, 5, 0);
                ++gnSelectionFrame_007C0E50;
            }
        }

        sub_00502320(pLine->wszText, nLineX, nLineY, nColor, 0);
        nOffsetY += pLine->nHeight;
    }

    sub_00502EF0(nOldFont);
}
