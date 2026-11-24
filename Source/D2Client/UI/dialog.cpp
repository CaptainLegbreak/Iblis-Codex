#include "D2Client.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2ClientDialogWidget.h"

#pragma function(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

class D2DialogWidget;

struct D2DialogWidgetNodeStrc;

struct Handler;

struct HandlerNode;

struct SMSGHANDLER_PARAMS;

struct D2ClientDialogStrc;

struct Message;

struct SelectionState;

struct D2MsgHandlerEntryStrc;

class D2DialogWidget
{
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnMouseMove(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
};


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __cdecl sub_0045AE90(); // 0x0045AE90

int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY); // 0x0047F190

int __fastcall TEXT_IsInPanelButton(int nMode, int nX, int nY); // 0x004A6580

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

static void __cdecl sub_004B7100_Select(SelectionState* state, int step); // 0x004B7100

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall CUNIT_SetDialogState(int nState); // 0x004898D0

void __cdecl DIALOG_LoadDialogHotkeys(); // 0x004B7C60

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern D2MsgHandlerEntryStrc gaDialogWheelHandlers[]; // 0x007273E4

extern D2MsgHandlerEntryStrc gaDialogHandlers[]; // 0x007273F0

static inline void DIALOG_InitDialog(D2ClientDialogStrc* pDialog);

extern "C" int __stdcall sub_00420290_QueueMessage(Message*); // 0x00420290

extern "C" int __fastcall sub_004B9A00_Notify(int, void*, int, int, int); // 0x004B9A00

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB);                                                     // 0x00469AA0

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB);                                                                // 0x00469D90

void __stdcall ROSTERPETS_HandleDialogEscape(SMSGHANDLER_PARAMS* pMsg);                                     // 0x004B76D0

struct D2RectStrc;

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern int gnGlobal_007273F4; // 0x007273F4

extern int gnGlobal_00727400; // 0x00727400

static D2ClientDialogStrc* gpDialogList; // 0x007C0E54

extern "C" void __stdcall DIALOG_SelectPreviousMsg(Message* message);

extern "C" void __stdcall DIALOG_SelectNextMsg(Message* message);

extern "C" void __stdcall DIALOG_SelectPreviousAltMsg(Message* message);

extern "C" void __stdcall DIALOG_SelectNextAltMsg(Message* message);

static void __stdcall DIALOG_LButtonDownMsg(SMSGHANDLER_PARAMS* pMsg);


extern "C" void __stdcall DIALOG_WheelMsg(Message* message);

static int gnDialogHandlerRegCount; // 0x007C0E4C

static int gbDialogHandlersRegistered; // 0x007C0E58

static int gnDialogCount; // 0x007C0E5C

extern const char* gaszDialogCels[]; // 0x007274AC

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840


static int DIALOG_FindDialogItem(D2ClientDialogStrc* pDialog, SMSGHANDLER_PARAMS* pMsg);

static int __stdcall DIALOG_UpdateHoverItem(SMSGHANDLER_PARAMS* pMsg, D2ClientDialogStrc* pDialog);

void __stdcall DIALOG_LButtonUpMsg(SMSGHANDLER_PARAMS* pMsg);

void __stdcall DIALOG_LButtonDownMsg(SMSGHANDLER_PARAMS* pMsg);

// 0x004B7150
static inline void DIALOG_HoverFirstEnabledLine(D2ClientDialogStrc* pDialog)
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

// 0x004B7180
static int DIALOG_FindDialogItem(D2ClientDialogStrc* pDialog, SMSGHANDLER_PARAMS* pMsg)
{
    if (pDialog)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
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
static int __stdcall DIALOG_UpdateHoverItem(SMSGHANDLER_PARAMS* pMsg, D2ClientDialogStrc* pDialog)
{
    D2_ASSERT(pDialog, 0xE1);
    const int nOld = pDialog->nHover;
    const int nItem = DIALOG_FindDialogItem(pDialog, pMsg);
    pDialog->nHover = nItem;
    pDialog->nPressedItem = nItem;
    if (nItem == nOld || nItem == -1)
        return 0;
    sub_004B9A00(1, 0, 0, 0, 0);
    return 1;
}

// 0x004B7270
void __stdcall DIALOG_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpDialogList;
    if (pDialog->dwTick + 0x50 > GetTickCount())
        return;
    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->pWidget && pNode->pWidget->OnMouseMove(pMsg) == 1)
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    DIALOG_UpdateHoverItem(pMsg, pDialog);
}

// 0x004B72E0
void __stdcall DIALOG_LButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2ClientDialogStrc* pDialog = gpDialogList;
    if (GAME_GetUIVarState(0x15) && sub_0047F190_IsInMiniPanelRect(nX, nY))
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
            if (pNode->pWidget && pNode->pWidget->OnLButtonUp(pMsg) == 1)
                return;
        }
        return;
    }

    if (pDialog->dwTick + 0x50 > GetTickCount())
        return;
    const int nItem = DIALOG_FindDialogItem(pDialog, pMsg);
    if (pDialog->nPressedItem == nItem && nItem >= 0 && nItem < pDialog->nLines)
    {
        int (__cdecl* pfnCallback)() = pDialog->pLines[pDialog->nHover].pfnCallback;
        if (pfnCallback && pfnCallback())
            return;
    }
    pDialog->bActive = 0;
}

// 0x004B73E0
static void __stdcall DIALOG_LButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpDialogList;
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
        if (pNode->pWidget && pNode->pWidget->OnLButtonDown(pMsg) == 1)
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
    }

    pDialog->bActive = 1;
    if (DIALOG_UpdateHoverItem(pMsg, pDialog))
        goto handled;

    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        if (nX >= pDialog->nX - 4 && nX <= pDialog->nX + pDialog->nWidth + 4 && nY >= pDialog->nY - 4 && nY <= pDialog->nY + pDialog->nHeight + 4)
            goto handled;
        if (GAME_GetUIVarState(0x15) && sub_0047F190_IsInMiniPanelRect(nX, nY))
            return;
        if (pDialog->pfnOutside)
        {
            if (!pDialog->pfnOutside())
                return;
            if (GAME_GetUIVarState(6) && TEXT_IsInPanelButton(sub_0045AE90(), nX, nY))
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
            }
            if (GAME_GetUIVarState(7) && sub_004A6630_IsInPanelButton2(sub_0045AE90(), nX, nY))
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
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1AA);
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
    DIALOG_HoverFirstEnabledLine(pDialog);
}

void __fastcall sub_M304_Emit_004B7BC0(D2ClientDialogStrc* pDialog)
{
    DIALOG_InitDialog(pDialog);
}

// 0x004B7570
static void __stdcall DIALOG_HandleDialogKey(int bClose, SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (!bClose)
        return;

    D2ClientDialogStrc* pDialog = gpDialogList;
    D2_ASSERT(pDialog, 0x1C2);
    if (pDialog->nState >= 5 && pDialog->pfnDefault)
    {
        pDialog->pfnDefault();
        UI_StartUIVarDelay();
    }
}

// 0x004B75D0
void __stdcall DIALOG_KeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpDialogList;
    if (pDialog->bKeepKeys || !GAME_GetUIVarState(5))
        DIALOG_HandleDialogKey(pDialog->bModal == 0, pMsg);
}

static inline SelectionState* GetSelectionState(int line)
{
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(state, line);
    return state;
}

static inline bool DispatchWheelHandlers(HandlerNode* pNode, Message* pMessage)
{
    for (; pNode; pNode = pNode->next)
    {
        if (pNode->object && pNode->object->wheel(pMessage) == 1)
        {
            return true;
        }
    }
    return false;
}

// 0x004B7610
extern "C" void __stdcall DIALOG_WheelMsg(Message* message)
{
    if (message->wheel)
    {
        int turns = message->wheel / 120;
        if (turns)
        {
            SelectionState* state = gVar_007C0E54;
            D2_ASSERT(gVar_007C0E54, 505);
            if (DispatchWheelHandlers(gVar_007C0E54->handlers, message))
            {
                return;
            }
            if (turns > 0)
                sub_004B7100_Select(state, -1);
            else
                sub_004B7100_Select(state, 1);
        }
    }
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
}

extern "C" { SelectionState* gVar_007C0E54; } // 0x007C0E54

// 0x004B7770
extern "C" void __stdcall DIALOG_SelectPreviousMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 565);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->previous1(message) == 1)
            return;
    sub_004B7100_Select(state, -1);
}

static void __cdecl sub_004B7100_Select(SelectionState* state, int step)
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

// 0x004B77F0
extern "C" void __stdcall DIALOG_SelectNextMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 597);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->next1(message) == 1)
            return;
    sub_004B7100_Select(state, 1);
}

// 0x004B7870
extern "C" void __stdcall DIALOG_SelectPreviousAltMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 626);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->previous2(message) == 1)
            return;
    sub_004B7100_Select(state, -1);
}

// 0x004B78F0
extern "C" void __stdcall DIALOG_SelectNextAltMsg(Message* message)
{
    message->handled = 1;
    message->result = 0;
    sub_00420290_QueueMessage(message);
    SelectionState* state = gVar_007C0E54;
    D2_ASSERT(gVar_007C0E54, 656);
    for (HandlerNode* node = gVar_007C0E54->handlers; node; node = node->next)
        if (node->object && node->object->next2(message) == 1)
            return;
    sub_004B7100_Select(state, 1);
}

// 0x004B7970
static __declspec(noinline) int DIALOG_IsChatKey(D2ClientDialogStrc* pDialog, int nKey)
{
    if (pDialog->bKeepKeys)
        return 0;
    if (CUNIT_HasHotkeyBinding(5, 1) && CUNIT_GetHotkeyBinding(5, 1) == nKey)
        return 1;
    if (CUNIT_HasHotkeyBinding(5, 0) && CUNIT_GetHotkeyBinding(5, 0) == nKey)
        return 1;
    return 0;
}

// 0x004B79D0
void __stdcall DIALOG_EnterMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    D2ClientDialogStrc* pDialog = gpDialogList;
    D2_ASSERT(pDialog, 0x2C8);
    if (pDialog->nState < 5)
        return;
    if (DIALOG_IsChatKey(pDialog, 0xD))
        return;
    int nSelected = pDialog->nHover;
    if (nSelected >= 0 && nSelected < pDialog->nLines)
    {
        int (__cdecl* pfnCallback)() = pDialog->pLines[nSelected].pfnCallback;
        if (pfnCallback && pfnCallback() == 1)
            UI_StartUIVarDelay();
        return;
    }
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        if (pDialog->pLines[i].bEnabled)
        {
            pDialog->nHover = i;
            return;
        }
    }
}

// 0x004B7A90
void __stdcall DIALOG_KeyDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2ClientDialogStrc* pDialog = gpDialogList;
    D2_ASSERT(pDialog, 0x2EE);
    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->pWidget && pNode->pWidget->MsgSlot06(pMsg))
            return;
    }
    if (DIALOG_IsChatKey(pDialog, pMsg->wParam))
        return;
    if (pMsg->wParam == 0xD)
    {
        DIALOG_EnterMsg(pMsg);
        return;
    }
    if (pMsg->wParam == 0x1B)
    {
        ROSTERPETS_HandleDialogEscape(pMsg);
        return;
    }
    if (pDialog->unk0x18 == 1)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x004B7B40
void __cdecl DIALOG_InitDialogs()
{
    gbDialogHandlersRegistered = 0;
}

// 0x004B7B50
void __cdecl DIALOG_FreeDialogs()
{
    if (gbDialogHandlersRegistered)
    {
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaDialogHandlers, 0xE);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaDialogWheelHandlers, 1);
        gnDialogHandlerRegCount -= 1;
    }

    D2ClientDialogStrc* pDialog = gpDialogList;
    while (pDialog)
    {
        D2ClientDialogStrc* pNext = pDialog->pNext;
        FOG_Free(pDialog, ".\\UI\\dialog.cpp", 0x333, 0);
        pDialog = pNext;
    }

    gpDialogList = 0;
}

// 0x004B7BC0
static inline void DIALOG_InitDialog(D2ClientDialogStrc* pDialog)
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

// 0x004B7C00
void __fastcall DIALOG_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC)
{
    D2_ASSERT(pDialog, 0x355);
    D2DialogWidgetNodeStrc* pOld = pDialog->pWidgets;
    pDialog->pWidgets = (D2DialogWidgetNodeStrc*)FOG_Alloc(sizeof(D2DialogWidgetNodeStrc), ".\\UI\\dialog.cpp", 0x359, 0);
    pDialog->pWidgets->pNext = pOld;
    pDialog->pWidgets->pWidget = (D2DialogWidget*)pWidget;
}

// 0x004B7CD0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialogFromFile(int nArg1, int nArg2, int nArg8, int nArgC, int nType, int nArg14)
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    sub_004545C0(0);
    CUNIT_SetDialogState(0);
    GAME_ResetMouseState();
    if (!nArg8)
    {
        return 0;
    }
    if (nType >= 1)
    {
        return 0;
    }

    gnDialogCount += 1;
    D2ClientDialogStrc* pDialog = (D2ClientDialogStrc*)FOG_Alloc(sizeof(D2ClientDialogStrc), ".\\UI\\dialog.cpp", 0x396, 0);
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->pNext = gpDialogList;
    gpDialogList = pDialog;
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->nWidth = 0;
    pDialog->nHeight = 0;
    pDialog->nLines = 0;
    pDialog->nEnabled = 0;
    pDialog->nHover = -1;
    pDialog->nMode = 2;
    pDialog->nX = 0;
    pDialog->nY = 0;
    pDialog->pWidgets = 0;
    pDialog->pfnDefault = (void (__cdecl*)())nArg8;
    pDialog->pfnOutside = (int (__cdecl*)())nArgC;
    pDialog->bAutoSize = 0;
    pDialog->bCountEnabled = 0;
    pDialog->dwTick = GetTickCount();
    pDialog->unk0x18 = nArg14;
    pDialog->nPressedItem = -1;
    pDialog->bActive = 0;
    pDialog->nState = 0;
    pDialog->bDrawCel = 1;
// build: symbol ?gszDataGlobal@* 0x006D4118
    sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal, gaszDialogCels[nType]);
    pDialog->pCelFile = ARCHIVE_LoadClientCellFile(szPath, 0);

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pDialog->pCelFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    D2CelStrc* hCel = CelGetHandle(&tContext);
    D2_ASSERT(hCel, 0x3B3);
    pDialog->nWidth = CelGetWidth(hCel);
    pDialog->nHeight = CelGetHeight(hCel);
    pDialog->nCenterX = nArg1;
    pDialog->nCenterY = nArg2;
    pDialog->nX = nArg1;
    pDialog->nY = nArg2;
    gbDialogHandlersRegistered = 1;
    DIALOG_LoadDialogHotkeys();
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaDialogHandlers, 0xE);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaDialogWheelHandlers, 1);
    gnDialogHandlerRegCount += 1;
    D2_ASSERT(gnDialogCount == 1, 0x3C8);
    return pDialog;
}

// 0x004B7C60
void __cdecl DIALOG_LoadDialogHotkeys()
{
    if (CUNIT_HasHotkeyBinding(0x26, 1))
    {
        unsigned short nValue = CUNIT_GetHotkeyBinding(0x26, 1);
        if (nValue != 0xFFFF && nValue <= 0xDF)
        {
            gnGlobal_007273F4 = nValue;
        }
    }
    if (CUNIT_HasHotkeyBinding(0x26, 0))
    {
        unsigned short nValue = CUNIT_GetHotkeyBinding(0x26, 0);
        if (nValue != 0xFFFF && nValue <= 0xDF)
        {
            gnGlobal_00727400 = nValue;
        }
    }
}

// 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28)
{
    sub_004545C0(0);
    CUNIT_SetDialogState(0);
    GAME_ResetMouseState();
    if (!nArg8)
    {
        return 0;
    }

    gnDialogCount += 1;
    D2ClientDialogStrc* pDialog = (D2ClientDialogStrc*)FOG_Alloc(sizeof(D2ClientDialogStrc), ".\\UI\\dialog.cpp", 0x3E7, 0);
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->pNext = gpDialogList;
    gpDialogList = pDialog;
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
    pDialog->nPressedItem = -1;
    pDialog->unk0x18 = nArg10;
    pDialog->bKeepKeys = nArg28;
    gbDialogHandlersRegistered = 1;
    DIALOG_LoadDialogHotkeys();
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaDialogHandlers, 0xE);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaDialogWheelHandlers, 1);
    gnDialogHandlerRegCount += 1;
    D2_ASSERT(gnDialogCount == 1, 0x408);
    return pDialog;
}

// 0x004B8020
void __fastcall DIALOG_DestroyDialog(void* pRes)
{
    gnDialogCount -= 1;
    if (gnDialogCount == 0)
    {
        sub_004545C0(1);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaDialogHandlers, 0xE);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaDialogWheelHandlers, 1);
        CUNIT_SetDialogState(1);
        sub_00467430(0);
        gbDialogHandlersRegistered = 0;
        D2ClientDialogStrc* pDialog = gpDialogList;
        D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets;
        while (pNode)
        {
            D2DialogWidgetNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, ".\\UI\\dialog.cpp", 0x425, 0);
            pNode = pNext;
        }

        if (pDialog->bDrawCel && pDialog->pCelFile)
        {
            ARCHIVE_FreeClientCellFile(pDialog->pCelFile);
        }

        D2ClientDialogStrc* pNext = pDialog->pNext;
        FOG_Free(pDialog, ".\\UI\\dialog.cpp", 0x430, 0);
        gpDialogList = pNext;
    }
    else
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x436);
        exit(-1);
    }
}

#include "gen/data/Source/D2Client/UI/dialog.inc"
