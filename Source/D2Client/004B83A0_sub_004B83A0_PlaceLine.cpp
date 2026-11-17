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
    char unk0x00[0x14];
    int bCountEnabled;
    char unk0x18[0xC];
    int nCenterX;
    int nCenterY;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    char unk0x3C[0x8];
    int nSelected;
    char unk0x48[0x4];
    int nEnabled;
    int nLines;
    char unk0x54[0x4];
    int bAutoSize;
    int nMode;
    char unk0x60[0x8];
    D2DialogLineStrc pLines[10];
    void* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
void __fastcall sub_00467430(D2RectStrc* pRect);                                                            // 0x00467430
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex);                               // 0x004B82F0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

// 0x004B83A0
static __declspec(noinline) void sub_004B83A0_PlaceLine(D2ClientDialogStrc* pDialog, int nIndex)
{
    int nOldFont = sub_00502EF0(1);
    sub_00502EF0(pDialog->pLines[nIndex].nFont);
    int nWidth = sub_00501820(pDialog->pLines[nIndex].wszText);
    if (nWidth >= pDialog->nWidth)
        pDialog->pLines[nIndex].nX = 0;
    else
        pDialog->pLines[nIndex].nX = (pDialog->nWidth - nWidth + 1) / 2 + 1;
    pDialog->pLines[nIndex].nWidth = nWidth;
    sub_00502EF0(nOldFont);
}

void __fastcall sub_004B8410_LayoutDialog(D2ClientDialogStrc* pDialog)
{
    int nMaxWidth = 0;
    int nHeight = 0;
    D2_ASSERT(pDialog->bAutoSize, 0x59F);
    int nOldFont = sub_00502EF0(1);
    int nDisabled = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        int nWidth = sub_00501820(pDialog->pLines[i].wszText);
        if (nWidth > nMaxWidth)
            nMaxWidth = nWidth;
        if (!pDialog->pLines[i].bEnabled)
            ++nDisabled;
        nHeight += pDialog->pLines[i].nHeight;
    }
    nMaxWidth += 0x14;
    nHeight += 0xF;
    sub_00502EF0(nOldFont);
    pDialog->nX = pDialog->nCenterX - nMaxWidth / 2;
    if (pDialog->bCountEnabled)
        pDialog->nY = pDialog->nCenterY - nDisabled * 0x15;
    else
        pDialog->nY = pDialog->nCenterY - nHeight / 3;
    D2_ASSERT(nMaxWidth <= gnGlobal_0071146C - 0x50, 0x5D2);
    D2_ASSERT(nHeight <= gnGlobal_00711470 - 0x62, 0x5D7);
    if (pDialog->nX + nMaxWidth > gnGlobal_0071146C - 0xA)
        pDialog->nX = gnGlobal_0071146C - nMaxWidth;
    if (pDialog->nY + nHeight > gnGlobal_00711470 - 0x3A)
        pDialog->nY = gnGlobal_00711470 - nHeight - 0x30;
    if (pDialog->nX <= 0xA)
        pDialog->nX = 0xA;
    if (pDialog->nY <= 0xA)
        pDialog->nY = 0xA;
    pDialog->nWidth = nMaxWidth;
    pDialog->nHeight = nHeight;
    for (int j = 0; j < pDialog->nLines; ++j)
        sub_004B83A0_PlaceLine(pDialog, j);
}

void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4,
    int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled)
{
    int nIndex = pDialog->nLines;
    D2_ASSERT(nIndex < 10, 0x552);
    pDialog->nLines = nIndex + 1;
    pDialog->pLines[nIndex].nHeight = nHeight;
    pDialog->pLines[nIndex].nX = 0;
    pDialog->pLines[nIndex].nArg4 = nArg4;
    pDialog->pLines[nIndex].nFont = nFont;
    if (nType == 3)
    {
        D2_ASSERT(pDialog->nMode != 1, 0x55E);
    }
    pDialog->pLines[nIndex].nType = nType;
    pDialog->pLines[nIndex].pfnCallback = pfnCallback;
    pDialog->pLines[nIndex].bEnabled = bEnabled;
    int nLen = sub_00526800(wszText) + 1;
    if (nLen > 0x77)
        nLen = 0x77;
    sub_00526790(pDialog->pLines[nIndex].wszText, wszText, nLen);
    pDialog->pLines[nIndex].wszText[nLen].ch = 0;
    if (bEnabled)
        pDialog->nEnabled += 1;
    if (pDialog->bAutoSize)
        sub_004B8410_LayoutDialog(pDialog);
    else
        sub_004B83A0_PlaceLine(pDialog, nIndex);
    D2RectStrc tRect;
    tRect.nTop = pDialog->nY;
    tRect.nLeft = pDialog->nX;
    tRect.nBottom = pDialog->nY + pDialog->nHeight;
    tRect.nRight = pDialog->nX + pDialog->nWidth;
    sub_00467430(&tRect);
    if (pDialog->nSelected == -1 && bEnabled)
        sub_004B82F0_Select(pDialog, nIndex);
}
