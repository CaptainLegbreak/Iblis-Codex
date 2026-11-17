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
    int f_44;
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

extern char gbGlobal_007C0E80;                                                                              // 0x007C0E80

// 0x004B8590
D2DialogLineStrc* __fastcall sub_004B8590_GetLine(D2ClientDialogStrc* pDialog, int nIndex)
{
    if (pDialog && nIndex >= 0 && nIndex < pDialog->nLines)
        return &pDialog->pLines[nIndex];
    return 0;
}

// 0x004B85B0
void __fastcall sub_004B85B0_GetRect(D2ClientDialogStrc* pDialog, D2RectStrc* pRect)
{
    if (pDialog && pRect)
    {
        pRect->nTop = pDialog->nY;
        pRect->nLeft = pDialog->nX;
        pRect->nBottom = pDialog->nHeight + pDialog->nY;
        pRect->nRight = pDialog->nWidth + pDialog->nX;
    }
}

// 0x004B8A00
int __cdecl sub_004B8A00_IsGlobalClear()
{
    return gbGlobal_007C0E80 == 0;
}
