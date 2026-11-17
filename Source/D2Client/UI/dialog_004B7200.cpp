#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
class D2DialogWidget;
struct D2DialogWidgetNodeStrc;
struct D2DialogItemStrc;
struct D2MsgHandlerEntryStrc;

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
    int unk0x08;
    int unk0x0C;
    union
    {
        int bActive;
        int unk0x10;
    };
    int unk0x14;
    int unk0x18;
    union
    {
        int bModal;
        int unk0x1C;
    };
    union
    {
        int bKeepKeys;
        int unk0x20;
    };
    int unk0x24;
    int unk0x28;
    union
    {
        int nX;
        int unk0x2C;
    };
    union
    {
        int nY;
        int unk0x30;
    };
    union
    {
        int nWidth;
        int unk0x34;
    };
    union
    {
        int nHeight;
        int unk0x38;
    };
    char unk0x3C[8];
    union
    {
        int nHover;
        int unk0x44;
    };
    union
    {
        int f_44;
        int unk0x48;
    };
    int unk0x4C;
    union
    {
        int nCount;
        int unk0x50;
    };
    union
    {
        unsigned int nState;
        int unk0x54;
    };
    int unk0x58;
    int unk0x5C;
    union
    {
        void (__cdecl* pfnDefault)();
        int unk0x60;
    };
    union
    {
        int (__cdecl* pfnOutside)();
        int unk0x64;
    };
    char unk0x68[0xF0];
    D2DialogItemStrc f_158[9];
    char unk0xAE8[0x20];
    union
    {
        D2DialogWidgetNodeStrc* pWidgets;
        int unk0xB08;
    };
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY); // 0x0047F190
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY); // 0x004A6580
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __cdecl sub_00453AE0(); // 0x00453AE0

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __cdecl sub_0044DA40(); // 0x0044DA40
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_004898D0(int nState); // 0x004898D0
void __cdecl sub_004B7C60(); // 0x004B7C60
int __cdecl sub_004F59A0(); // 0x004F59A0
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273E4[]; // 0x007273E4
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273F0[]; // 0x007273F0

static D2ClientDialogStrc* gpGlobal_007C0E54; // 0x007C0E54

static int sub_004B7180_FindDialogItem(D2ClientDialogStrc* pDialog, SMSGHANDLER_PARAMS* pMsg)
{
    if (pDialog)
    {
        const int nY = pMsg->nYPos;
        const int nX = pMsg->nXPos;
        int nOffset = 0;
        for (int i = 0; i < pDialog->nCount; ++i)
        {
            D2DialogItemStrc* pItem = &pDialog->f_158[i];
            if (pItem->nType == 1 && nX > pDialog->nX + 0xF && nX < pDialog->nX + pDialog->nWidth - 0xF)
            {
                const int nItemY = pDialog->nY + pItem->nHeight + nOffset;
                if (nY > nItemY - 0xB && nY < nItemY + 4)
                    return i;
            }
            nOffset += pItem->nHeight;
        }
    }
    return -1;
}

// 0x004B7200
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

// 0x004B7270
void __stdcall sub_004B7270_DialogMouseMotion(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    if (pDialog->dwTick + 0x50 > GetTickCount())
        return;
    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_0 && pNode->f_0->OnMouseMove(pMsg) == 1)
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }
    }
    sub_004B7200_UpdateHoverItem(pMsg, pDialog);
}

// 0x004B72E0
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

static int gnGlobal_007C0E4C; // 0x007C0E4C

static int gnGlobal_007C0E58; // 0x007C0E58

static int gnGlobal_007C0E5C; // 0x007C0E5C

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
