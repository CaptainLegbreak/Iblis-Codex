#pragma function(memset)
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                              // 0x00681EF0

struct D2DialogWidgetNodeStrc;

struct D2DialogItemStrc
{
    int nHeight;
    char unk0x04[0x14];
    int (__cdecl* pfnCallback)();
    int nType;
    char unk0x20[0xF0];
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    int unk0x04;
    void* pCelFile;
    int unk0x0C;
    int bActive;
    char unk0x14[0x18];
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    char unk0x3C[8];
    int nHover;
    int f_44;
    int unk0x4C;
    int nCount;
    char unk0x54[8];
    int unk0x5C;
    void (__cdecl* pfnDefault)();
    int (__cdecl* pfnOutside)();
    char unk0x68[0xF0];
    D2DialogItemStrc f_158[9];
    char unk0xAE8[0x20];
    D2DialogWidgetNodeStrc* pWidgets;
    D2ClientDialogStrc* pNext;
};

// 0x004B7150
static __forceinline void sub_004B7150_HoverFirstTypedItem(D2ClientDialogStrc* pDialog)
{
    for (int i = 0; i < pDialog->nCount; ++i)
    {
        if (pDialog->f_158[i].nType)
        {
            pDialog->nHover = i;
            return;
        }
    }
}

// 0x004B7BC0
static __forceinline void sub_004B7BC0_InitDialog(D2ClientDialogStrc* pDialog)
{
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->nWidth = 0;
    pDialog->nHeight = 0;
    pDialog->nCount = 0;
    pDialog->unk0x4C = 0;
    pDialog->nX = 0;
    pDialog->nY = 0;
    pDialog->pWidgets = 0;
    pDialog->nHover = -1;
    pDialog->unk0x5C = 2;
}

void __fastcall sub_M304_Emit_004B7150(D2ClientDialogStrc* pDialog)
{
    sub_004B7150_HoverFirstTypedItem(pDialog);
}

void __fastcall sub_M304_Emit_004B7BC0(D2ClientDialogStrc* pDialog)
{
    sub_004B7BC0_InitDialog(pDialog);
}
