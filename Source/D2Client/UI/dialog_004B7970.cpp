struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01() = 0;
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg) = 0;
};

struct D2DialogWidgetNodeStrc
{
    UIWidget* f_0;
    D2DialogWidgetNodeStrc* pNext;
};

struct D2DialogEntryStrc
{
    int (__cdecl* pfnCallback)();
    int bEnabled;
    char unk0x08[0x108];
};

struct D2ClientDialogStrc
{
    char unk0x00[0x18];
    int unk0x18;
    char unk0x1C[0x4];
    int unk0x20;
    char unk0x24[0x20];
    int f_44;
    char unk0x48[0x8];
    int nEntries;
    unsigned int nState;
    char unk0x58[0x118];
    D2DialogEntryStrc pEntries[9];
    char unk0xB00[0x8];
    D2DialogWidgetNodeStrc* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
void __stdcall sub_004B76D0_TimedCallbackMsg(SMSGHANDLER_PARAMS* pMsg);                                     // 0x004B76D0

static D2ClientDialogStrc* gpGlobal_007C0E54;                                                               // 0x007C0E54

// 0x004B7970
static __declspec(noinline) int sub_004B7970_IsDialogKey(D2ClientDialogStrc* pDialog, int nKey)
{
    if (pDialog->unk0x20)
        return 0;
    if (sub_00469D90(5, 1) && sub_00469AA0(5, 1) == nKey)
        return 1;
    if (sub_00469D90(5, 0) && sub_00469AA0(5, 0) == nKey)
        return 1;
    return 0;
}

// 0x004B79D0
void __stdcall sub_004B79D0_DialogEnterMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    D2_ASSERT(pDialog, 0x2C8);
    if (pDialog->nState < 5)
        return;
    if (sub_004B7970_IsDialogKey(pDialog, 0xD))
        return;
    int nSelected = pDialog->f_44;
    if (nSelected >= 0 && nSelected < pDialog->nEntries)
    {
        int (__cdecl* pfnCallback)() = pDialog->pEntries[nSelected].pfnCallback;
        if (pfnCallback && pfnCallback() == 1)
            sub_00453AE0();
        return;
    }
    for (int i = 0; i < pDialog->nEntries; ++i)
    {
        if (pDialog->pEntries[i].bEnabled)
        {
            pDialog->f_44 = i;
            return;
        }
    }
}

// 0x004B7A90
void __stdcall sub_004B7A90_DialogKeyDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    D2_ASSERT(pDialog, 0x2EE);
    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_0 && pNode->f_0->MsgSlot06(pMsg))
            return;
    }
    if (sub_004B7970_IsDialogKey(pDialog, pMsg->wParam))
        return;
    if (pMsg->wParam == 0xD)
    {
        sub_004B79D0_DialogEnterMsg(pMsg);
        return;
    }
    if (pMsg->wParam == 0x1B)
    {
        sub_004B76D0_TimedCallbackMsg(pMsg);
        return;
    }
    if (pDialog->unk0x18 == 1)
    {
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}
