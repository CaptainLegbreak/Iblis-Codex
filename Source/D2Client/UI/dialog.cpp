#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
class D2DialogWidget;
struct D2DialogWidgetNodeStrc;
struct D2DialogItemStrc;
struct Handler;
struct HandlerNode;
struct SelectionEntry;

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

struct SelectionEntry
{
    int enabled;
    char pad04[272-4];
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
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
static void __cdecl sub_004B7100_Select(int step, SelectionState* state); // 0x004B7100

static D2ClientDialogStrc* gpGlobal_007C0E54; // 0x007C0E54

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

// 0x004B73E0
static void __stdcall sub_004B73E0_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
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
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
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
                sub_00420290_HandleMsg(pMsg);
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
                sub_00420290_HandleMsg(pMsg);
                return;
            }
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1AA);
            exit(-1);
        }
    }

handled:
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
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
