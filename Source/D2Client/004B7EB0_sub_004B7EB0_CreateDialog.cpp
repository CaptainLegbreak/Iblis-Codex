struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
    int unk0x38;
    int unk0x3C;
    int unk0x40;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    int unk0x54;
    int unk0x58;
    int unk0x5C;
    int unk0x60;
    int unk0x64;
    char unk0x68[0xB08 - 0x68];
    int unk0xB08;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_004545C0(int bSet);                                                                     // 0x004545C0
void __fastcall sub_004898D0(int nState);                                                                   // 0x004898D0
void __cdecl sub_004B7C60();                                                                                // 0x004B7C60
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0

extern D2MsgHandlerEntryStrc gaMsgHandlers_007273E4[];                                                      // 0x007273E4
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273F0[];                                                      // 0x007273F0
static int gnGlobal_007C0E4C;                                                                               // 0x007C0E4C
static D2ClientDialogStrc* gpGlobal_007C0E54;                                                               // 0x007C0E54
static int gnGlobal_007C0E58;                                                                               // 0x007C0E58
static int gnGlobal_007C0E5C;                                                                               // 0x007C0E5C

// 0x004B7EB0
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28)
{
    sub_004545C0(0);
    sub_004898D0(0);
    sub_0044DA40();
    if (!nArg8)
    {
        return 0;
    }

    gnGlobal_007C0E5C += 1;
    D2ClientDialogStrc* pDialog = (D2ClientDialogStrc*)FOG_Alloc(sizeof(D2ClientDialogStrc), ".\\UI\\dialog.cpp", 0x3E7, 0);
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->pNext = gpGlobal_007C0E54;
    gpGlobal_007C0E54 = pDialog;
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->unk0x24 = nArg1;
    pDialog->unk0x2C = nArg1;
    pDialog->unk0x60 = nArg8;
    pDialog->unk0x64 = nArgC;
    pDialog->unk0x58 = nArg18;
    pDialog->unk0x38 = 0;
    pDialog->unk0x50 = 0;
    pDialog->unk0x4C = 0;
    pDialog->unk0x44 = -1;
    pDialog->unk0x5C = 2;
    pDialog->unk0xB08 = 0;
    pDialog->unk0x28 = nArg2;
    pDialog->unk0x30 = nArg2;
    pDialog->unk0x14 = nArg14;
    pDialog->unk0x1C = nArg24;
    pDialog->unk0x34 = nArg1C;
    pDialog->dwTick = GetTickCount();
    pDialog->unk0x10 = 0;
    pDialog->unk0x54 = 0;
    pDialog->unk0x0C = 0;
    pDialog->unk0x08 = 0;
    pDialog->unk0x38 = nArg20;
    pDialog->unk0x48 = -1;
    pDialog->unk0x18 = nArg10;
    pDialog->unk0x20 = nArg28;
    gnGlobal_007C0E58 = 1;
    sub_004B7C60();
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273F0, 0xE);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273E4, 1);
    gnGlobal_007C0E4C += 1;
    D2_ASSERT(gnGlobal_007C0E5C == 1, 0x408);
    return pDialog;
}
