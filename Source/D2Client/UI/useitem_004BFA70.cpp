#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2Txt.h"
#include "D2StormTypes.h"


int gnGlobal_007C5474;                                                                                      // 0x007C5474
int gnGlobal_007C5480;                                                                                      // 0x007C5480
extern int gnGlobal_007C5470;                                                                               // 0x007C5470
void* gpGlobal_007C5484;                                                                                    // 0x007C5484
extern unsigned long gdwTick_007C5488;                                                                      // 0x007C5488
extern D2MsgHandlerEntryStrc gaMsgHandlers_00727950[];                                                      // 0x00727950
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __fastcall sub_004C1D60(D2UnitStrc* pItem);                                                             // 0x004C1D60
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __stdcall sub_004922A0_ClickMsg(SMSGHANDLER_PARAMS* pMsg);                                              // 0x004922A0
void __fastcall sub_004BFBC0_HitTestHotspots(int nX, int nY);                                               // 0x004BFBC0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __cdecl sub_004B1670();                                                                                 // 0x004B1670
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_00467430(void* pRect);                                                                  // 0x00467430

// 0x004BFA70
static void sub_004BFA70_ToggleUseMode(D2UnitStrc* pItem)
{
    if (gnGlobal_007C5474 == 1)
    {
        gnGlobal_007C5474 = 2;
        sub_00468070_SetCursorItemState(0);
        if (!pItem)
            return;
        gnGlobal_007C5480 = pItem->dwUnitId;
        sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
        return;
    }
    if (gnGlobal_007C5474 == 2)
    {
        gnGlobal_007C5474 = 1;
        gnGlobal_007C5480 = 0;
        if (pItem)
            sub_00468070_SetCursorItemState(pItem);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}

static D2UnitStrc* GetCursorItem_Inline()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    return pPlayer ? INVENTORY_GetCursorItem(pPlayer->pInventory) : 0;
}

void __stdcall sub_004BFC50_OnClick(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (GetTickCount() - gdwTick_007C5488 < 0x190)
        return;
    gdwTick_007C5488 = GetTickCount();
    int bHandled;
    if (gnGlobal_007C5474 == 1)
    {
        bHandled = sub_004922A0_ClickMsg(pMsg);
    }
    else if (gnGlobal_007C5474 == 2)
    {
        bHandled = sub_00489190(pMsg);
    }
    else
    {
        goto check_item;
    }
    if (bHandled)
        return;
    sub_004BFBC0_HitTestHotspots(nX, nY);
check_item:
    D2UnitStrc* pItem = GetCursorItem_Inline();
    if (!pItem)
        return;
    if (nX < 0x7B || nX > 0x7B + 0x58 || nY < 0x6A || nY > 0x6A + 0x72)
        return;
    D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    if (!pTxt)
        return;
    if (ITEMS_CheckItemFlag(pItem, 0x10, 0x210, ".\\UI\\UseItem.cpp"))
    {
        if (gnGlobal_007C5470 == 1)
        {
            if (sub_004B1670() == 0x9A && sub_0062C590(pItem))
                goto use_item;
            if (sub_004B1670() == 0x1FF && sub_0062C770(pItem))
                goto use_item;
            if (sub_004B1670() == 0x200 && sub_0062C6A0(pItem))
                goto use_item;
        }
        else if (!gnGlobal_007C5470 && pTxt->dwCode == 0x20747368)
        {
            goto use_item;
        }
    }
    sub_004B9A00(3, 0, 0, 0, 0);
    return;
use_item:
    sub_004BFA70_ToggleUseMode(pItem);
}

// 0x004C0090
void __cdecl sub_004C0090_CloseUseItemPanel()
{
    gnGlobal_007C5474 = 0;
    sub_004BFA70_ToggleUseMode(GetCursorItem_Inline());
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00727950, 8);
    if (gpGlobal_007C5484)
    {
        sub_004B8020(gpGlobal_007C5484);
        gpGlobal_007C5484 = 0;
    }
    sub_00455F20(0xE, 1, 0);
    sub_00467430(0);
}

#include "gen/data/Source/D2Client/UI/useitem_004BFA70.inc"
