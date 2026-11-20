#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"

#pragma function(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

class D2DialogWidget;
struct D2DialogWidgetNodeStrc;
struct Handler;
struct HandlerNode;
struct SelectionEntry;
struct SMSGHANDLER_PARAMS;
struct D2ClientDialogStrc;
struct Message;
struct SelectionState;
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY); // 0x0047F190
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY); // 0x004A6580
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

typedef void (__stdcall* MSGHANDLERFN)(SMSGHANDLER_PARAMS* pMsg);

struct Message
{
    char pad00[10];
    short wheel;
    char padWheel[24-10-2];
    int handled;
    int result;
};

struct Handler
{
    virtual int unused0(Message*);
    virtual int unused1(Message*);
    virtual int wheel(Message*);
    virtual int unused3(Message*);
    virtual int unused4(Message*);
    virtual int unused5(Message*);
    virtual int unused6(Message*);
    virtual int previous2(Message*);
    virtual int next2(Message*);
    virtual int previous1(Message*);
    virtual int next1(Message*);
};

struct HandlerNode
{
    Handler* object;
    HandlerNode* next;
};

struct SelectionState
{
    char pad00[68];
    int selected;
    char padSelected[76-68-4];
    int activeCount;
    int totalCount;
    char padTotal[372-80-4];
    SelectionEntry entries[9];
    char padEntries[4];
    HandlerNode* handlers;
};
static void __cdecl sub_004B7100_Select(int step, SelectionState* state); // 0x004B7100
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
void __cdecl sub_00453AE0(); // 0x00453AE0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __cdecl sub_0044DA40(); // 0x0044DA40
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_004898D0(int nState); // 0x004898D0
void __cdecl sub_004B7C60(); // 0x004B7C60
int __cdecl sub_004F59A0(); // 0x004F59A0
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273E4[]; // 0x007273E4
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273F0[]; // 0x007273F0

static __forceinline void sub_004B7BC0_InitDialog(D2ClientDialogStrc* pDialog);

// 0x004B7150
static __forceinline void sub_004B7150_HoverFirstTypedItem(D2ClientDialogStrc* pDialog)
{
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        if (pDialog->pLines[i].bEnabled)
        {
            pDialog->nHover = i;
            return;
        }
    }
}

static D2ClientDialogStrc* gpGlobal_007C0E54; // 0x007C0E54

// 0x004B7180
static int sub_004B7180_FindDialogItem(D2ClientDialogStrc* pDialog, SMSGHANDLER_PARAMS* pMsg)
{
    if (pDialog)
    {
        const int nX = pMsg->nXPos;
        const int nY = pMsg->nYPos;
        int nOffset = 0;
        for (int i = 0; i < pDialog->nLines; ++i)
        {
            if (pDialog->pLines[i].bEnabled == 1 && nX > pDialog->nX + 0xF && nX < pDialog->nX + pDialog->nWidth - 0xF
                && nY > pDialog->nY + pDialog->pLines[i].nHeight + nOffset - 0xB
                && nY < pDialog->nY + pDialog->pLines[i].nHeight + nOffset + 4)
                return i;
            nOffset += pDialog->pLines[i].nHeight;
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
    pDialog->unk0x48 = nItem;
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
            sub_00420290_BreakHandlerChain(pMsg);
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
    sub_00420290_BreakHandlerChain(pMsg);
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
    if (pDialog->unk0x48 == nItem && nItem >= 0 && nItem < pDialog->nLines)
    {
        int (__cdecl* pfnCallback)() = pDialog->pLines[pDialog->nHover].pfnCallback;
        if (pfnCallback && pfnCallback())
            return;
    }
    pDialog->bActive = 0;
}

// 0x004B73E0
static void __stdcall sub_004B73E0_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    D2_ASSERT(pDialog, 0x15B);
    if (pDialog->dwTick + 0x50 > GetTickCount())
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_0 && pNode->f_0->OnLButtonDown(pMsg) == 1)
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
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
                sub_00420290_BreakHandlerChain(pMsg);
            }
            if (sub_004538D0(7) && sub_004A6630_IsInPanelButton2(sub_0045AE90(), nX, nY))
                goto handled;
            return;
        }
        else
        {
            if (pDialog->pfnDefault)
            {
                pDialog->pfnDefault();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1AA);
            exit(-1);
        }
    }

handled:
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __fastcall sub_M304_Emit_004B7150(D2ClientDialogStrc* pDialog)
{
    sub_004B7150_HoverFirstTypedItem(pDialog);
}

void __fastcall sub_M304_Emit_004B7BC0(D2ClientDialogStrc* pDialog)
{
    sub_004B7BC0_InitDialog(pDialog);
}

// 0x004B7570
static void __stdcall sub_004B7570_HandleDialogKey(int bClose, SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
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

extern "C" { SelectionState* gVar_007C0E54; } // 0x007C0E54

// 0x004B7770
extern "C" void __stdcall sub_004B7770_Previous1(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 565);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->previous1(message) == 1)
            return;
    sub_004B7100_Select(-1, state);
}

MSGHANDLERFN gpfnEmit_004B73E0 = sub_004B73E0_OnLButtonDown;

static __declspec(noinline) void __cdecl sub_004B7100_Select(int step, SelectionState* state)
{
    if (state->activeCount > 1)
    {
        int selection = state->selected;
        do
        {
            selection += step;
            if (selection >= state->totalCount)
                selection = 0;
            else if (selection < 0)
                selection = state->totalCount - 1;
        } while (!state->entries[selection].enabled);
        sub_004B9A00_Notify(1, 0, 0, 0, 0);
        state->selected = selection;
    }
}

extern "C" void __stdcall sub_004B7610_Wheel(Message* message)
{
    if (message->wheel)
    {
        int turns = message->wheel / 120;
        if (turns)
        {
            SelectionState* state = gVar_007C0E54;
            D2_ASSERT(gVar_007C0E54, 505);
            for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
                if (node->object && node->object->wheel(message) == 1)
                    return;
            if (turns > 0)
                sub_004B7100_Select(-1, state);
            else
                sub_004B7100_Select(1, state);
        }
    }
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
}

// 0x004B77F0
extern "C" void __stdcall sub_004B77F0_Next1(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 597);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->next1(message) == 1)
            return;
    sub_004B7100_Select(1, state);
}

// 0x004B7870
extern "C" void __stdcall sub_004B7870_Previous2(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 626);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->previous2(message) == 1)
            return;
    sub_004B7100_Select(-1, state);
}

// 0x004B78F0
extern "C" void __stdcall sub_004B78F0_Next2(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 656);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->next2(message) == 1)
            return;
    sub_004B7100_Select(1, state);
}

// 0x004B7BC0
static __forceinline void sub_004B7BC0_InitDialog(D2ClientDialogStrc* pDialog)
{
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->nWidth = 0;
    pDialog->nHeight = 0;
    pDialog->nLines = 0;
    pDialog->nEnabled = 0;
    pDialog->nX = 0;
    pDialog->nY = 0;
    pDialog->pWidgets = 0;
    pDialog->nHover = -1;
    pDialog->nMode = 2;
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
    pDialog->nCenterX = nArg1;
    pDialog->nX = nArg1;
    pDialog->pfnDefault = (void (__cdecl*)())nArg8;
    pDialog->pfnOutside = (int (__cdecl*)())nArgC;
    pDialog->bAutoSize = nArg18;
    pDialog->nHeight = 0;
    pDialog->nLines = 0;
    pDialog->nEnabled = 0;
    pDialog->nHover = -1;
    pDialog->nMode = 2;
    pDialog->pWidgets = 0;
    pDialog->nCenterY = nArg2;
    pDialog->nY = nArg2;
    pDialog->bCountEnabled = nArg14;
    pDialog->bModal = nArg24;
    pDialog->nWidth = nArg1C;
    pDialog->dwTick = GetTickCount();
    pDialog->bActive = 0;
    pDialog->nState = 0;
    pDialog->bDrawCel = 0;
    pDialog->pCelFile = 0;
    pDialog->nHeight = nArg20;
    pDialog->unk0x48 = -1;
    pDialog->unk0x18 = nArg10;
    pDialog->bKeepKeys = nArg28;
    gnGlobal_007C0E58 = 1;
    sub_004B7C60();
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273F0, 0xE);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273E4, 1);
    gnGlobal_007C0E4C += 1;
    D2_ASSERT(gnGlobal_007C0E5C == 1, 0x408);
    return pDialog;
}
