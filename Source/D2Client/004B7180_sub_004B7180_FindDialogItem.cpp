struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXPos;
    unsigned short nYPos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

class D2DialogWidget
{
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnMouseMove(SMSGHANDLER_PARAMS* pMsg);
};

struct D2DialogWidgetNodeStrc
{
    D2DialogWidget* f_0;
    D2DialogWidgetNodeStrc* pNext;
};

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
    char unk0x54[0xC];
    void (__cdecl* pfnDefault)();
    int (__cdecl* pfnOutside)();
    char unk0x68[0xF0];
    D2DialogItemStrc f_158[9];
    char unk0xAE8[0x20];
    D2DialogWidgetNodeStrc* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY);                                              // 0x0047F190
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY);                                     // 0x004A6580
int __fastcall sub_004A6630_IsInPanelButton2(int nMode, int nX, int nY);                                    // 0x004A6630
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
static D2ClientDialogStrc* gpGlobal_007C0E54;                                                               // 0x007C0E54

// 0x004B7180
static int sub_004B7180_FindDialogItem(D2ClientDialogStrc* pDialog, SMSGHANDLER_PARAMS* pMsg)
{
    if (pDialog)
    {
        const int nX = pMsg->nXPos;
        const int nY = pMsg->nYPos;
        int nOffset = 0;
        for (int i = 0; i < pDialog->nCount; ++i)
        {
            if (pDialog->f_158[i].nType == 1 && nX > pDialog->nX + 0xF && nX < pDialog->nX + pDialog->nWidth - 0xF
                && nY > pDialog->nY + pDialog->f_158[i].nHeight + nOffset - 0xB
                && nY < pDialog->nY + pDialog->f_158[i].nHeight + nOffset + 4)
                return i;
            nOffset += pDialog->f_158[i].nHeight;
        }
    }
    return -1;
}

static int __stdcall sub_004B7200_UpdateHoverItem(SMSGHANDLER_PARAMS* pMsg, D2ClientDialogStrc* pDialog)
{
    D2_ASSERT(pDialog, 0xE1);
    const int nOld = pDialog->nHover;
    const int nItem = sub_004B7180_FindDialogItem(pDialog, pMsg);
    pDialog->nHover = nItem;
    pDialog->f_44 = nItem;
    if (nItem == nOld || nItem == -1)
        return 0;
    sub_004B9A00(1, 0, 0, 0, 0);
    return 1;
}

void __stdcall sub_004B72E0_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXPos;
    const int nY = pMsg->nYPos;
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    if (sub_004538D0(0x15) && sub_0047F190_IsInMiniPanelRect(nX, nY))
    {
        if (!pDialog)
            return;
        if (pDialog->bActive != 1)
            return;
        pDialog->bActive = 0;
        return;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
    D2_ASSERT(pDialog, 0x123);
    if (pDialog->bActive != 1)
    {
        for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
        {
            if (pNode->f_0 && pNode->f_0->OnLButtonUp(pMsg) == 1)
                return;
        }
        return;
    }

    if (pDialog->dwTick + 0x50 > GetTickCount())
        return;
    const int nItem = sub_004B7180_FindDialogItem(pDialog, pMsg);
    if (pDialog->f_44 == nItem && nItem >= 0 && nItem < pDialog->nCount)
    {
        int (__cdecl* pfnCallback)() = pDialog->f_158[pDialog->nHover].pfnCallback;
        if (pfnCallback && pfnCallback())
            return;
    }
    pDialog->bActive = 0;
}

void __stdcall sub_004B73E0_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    D2_ASSERT(pDialog, 0x15B);
    if (pDialog->dwTick + 0x50 > GetTickCount())
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_0 && pNode->f_0->OnLButtonDown(pMsg) == 1)
            goto handled;
    }

    pDialog->bActive = 1;
    if (sub_004B7200_UpdateHoverItem(pMsg, pDialog))
        goto handled;

    {
        const int nX = pMsg->nXPos;
        const int nY = pMsg->nYPos;
        if (nX >= pDialog->nX - 4 && nX <= pDialog->nX + pDialog->nWidth + 4 && nY >= pDialog->nY - 4 && nY <= pDialog->nY + pDialog->nHeight + 4)
            goto handled;
        if (sub_004538D0(0x15) && sub_0047F190_IsInMiniPanelRect(nX, nY))
            return;
        if (pDialog->pfnOutside)
        {
            if (!pDialog->pfnOutside())
                return;
            if (sub_004538D0(6) && sub_004A6580_IsInPanelButton(sub_0045AE90(), nX, nY))
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
            }
            if (sub_004538D0(7) && sub_004A6630_IsInPanelButton2(sub_0045AE90(), nX, nY))
                goto handled;
            return;
        }
        else
        {
            D2_ASSERT(pDialog->pfnDefault, 0x1AA);
            pDialog->pfnDefault();
        }
    }

handled:
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}
