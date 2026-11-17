struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    char unk0x08[0x10];
    int bReturn;
    int lResult;
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    char unk0x04[0x18];
    int bModal;
    int bKeepKeys;
    char unk0x24[0x30];
    unsigned int nState;
    char unk0x58[8];
    void (__cdecl* pfnDefault)();
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
static D2ClientDialogStrc* gpGlobal_007C0E54;                                                               // 0x007C0E54

// 0x004B7570
static void __stdcall sub_004B7570_HandleDialogKey(int bClose, SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
    if (!bClose)
        return;

    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    D2_ASSERT(pDialog, 0x1C2);
    if (pDialog->nState >= 5 && pDialog->pfnDefault)
    {
        pDialog->pfnDefault();
        sub_00453AE0();
    }
}

// 0x004B75D0
void __stdcall sub_004B75D0_OnDialogKey(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    if (pDialog->bKeepKeys || !sub_004538D0(5))
        sub_004B7570_HandleDialogKey(pDialog->bModal == 0, pMsg);
}
