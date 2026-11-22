#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
struct D2UnitStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);                                 // 0x006CC45C
void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord);                    // 0x00660CB0
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId);
int __cdecl sub_00468830();                                                                                 // 0x00468830
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
int __fastcall sub_004C2240(D2UnitStrc* pItem);                                                             // 0x004C2240
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0
void __fastcall sub_004C21F0(D2UnitStrc* pItem);
int __fastcall sub_004C1D60(D2UnitStrc* pItem);                                                             // 0x004C1D60
int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem);                                             // 0x004C1E20
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
int __cdecl GAME_IsLeftClickRepeating();                                                                                 // 0x0044BFE0
void __cdecl UI_CancelCursorItemUse();                                                                                // 0x00453EC0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar);                                                    // 0x004538D0
int __fastcall UI_GetUIVarUnchecked(int nUIVar);                                                  // 0x00453A90
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode);                           // 0x00621050
void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock);              // 0x0065C1F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState);                                  // 0x0049FF90
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20
void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent);   // 0x004CBDE0
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern int gnUiRecordRow_007A5218;                                                                          // 0x007A5218
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
static int gnBeltHover_007BEF94;                                                                            // 0x007BEF94
static int gbUiRecordMode_007BEF98;                                                                         // 0x007BEF98
static int gnBeltRecordMode2_007BEF9C;                                                                      // 0x007BEF9C
extern D2UnitStrc* gpBeltItemA_007BEFA8;                                                                    // 0x007BEFA8
extern unsigned char gabBeltHotkey_007BEFB0[];                                                              // 0x007BEFB0

static int __stdcall sub_004987E0_GetBeltBoxAt(int nY, int nX)
{
    D2UiRecordStrc tRecord;
    int nResult = -1;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    for (int i = 0; i < tRecord.nBoxes; ++i)
    {
        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, i);
        if (nX >= tRect.nLeft && nX <= tRect.nRight && nY >= tRect.nTop && nY <= tRect.nBottom)
        {
            nResult = i;
            break;
        }
    }
    return nResult;
}

static void __stdcall sub_00498870_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY)
{
    const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
    if (nBox == -1)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    if (sub_00468830() == 6)
    {
        return;
    }

    if (pCursorItem && ITEMS_CheckIfBeltable(pCursorItem))
    {
        const int bBusy = sub_004C2240(pCursorItem);
        if (pBeltItem)
        {
            if (!bBusy)
            {
                sub_004786A0_SendDwords2(0x25, pCursorItem->dwUnitId, pBeltItem->dwUnitId);
                sub_004C21F0(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            sub_004786A0_SendDwords2(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
            sub_004C21F0(pCursorItem);
        }
        sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
        return;
    }

    if (pBeltItem && !pCursorItem && !sub_004C2240(pBeltItem))
    {
        sub_00478680_SendPacket5(0x24, pBeltItem->dwUnitId);
        sub_004C21F0(pBeltItem);
    }
}

void __stdcall sub_A11_Emit_00498870(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00498870_ClickBeltBox(pPlayer->pInventory, nX, nY);
}

static __declspec(noinline) void sub_00498930_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY);
static void sub_00498930_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY)
{
    gnBeltRectY_00722364 = nY;
    gpBeltItemA_007BEFA8 = (D2UnitStrc*)pInventory;
    gnBeltBox_0072235C = nX;
}

static int __stdcall sub_00498A20_CheckState(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2ItemsTxt* pState)
{
    D2_ASSERT(pState, 0xA3D);
    if (pState->nUnique == 1 || pState->nQuest == 1)
    {
        sub_0049FF90_Close(pItem, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    sub_004CB9C0_Request(pPlayer, 0x14);
    return 0;
}

void __stdcall sub_00498A90_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift); // 0x00498A90

static void PANEL_BeltHotkey(int nSlot)
{
    if (GAME_IsExitPending() || sub_00463DF0())
    {
        return;
    }

    if (gabBeltHotkey_007BEFB0[nSlot] != 1)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00498A90_UseBeltSlot(nSlot, pPlayer, pPlayer->pInventory, GetKeyState(0x10) & 0x8000);
}

void __cdecl PANEL_BeltHotkeyFirst()
{
    PANEL_BeltHotkey(0);
}

void __cdecl PANEL_BeltHotkeySecond()
{
    PANEL_BeltHotkey(1);
}

void __cdecl PANEL_BeltHotkeyThird()
{
    PANEL_BeltHotkey(2);
}

void __cdecl PANEL_BeltHotkeyFourth()
{
    PANEL_BeltHotkey(3);
}

// 0x00499BB0
void __stdcall sub_00499BB0_BeltMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gdwGlobal_007A061C || GAME_IsExitPending() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (GAME_IsLeftClickRepeating())
    {
        return;
    }

    if (gbUiRecordMode_007BEF98)
    {
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        {
            if (GAME_GetUIVarState(0x1F))
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
            }
            sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
            return;
        }

        if (!GAME_GetUIVarState(0x1F))
        {
            pMsg->bReturn = 0;
            gbUiRecordMode_007BEF98 = 0;
            gnBeltRecordMode2_007BEF9C = 0;
        }
        else
        {
            pMsg->bReturn = 0;
            gnBeltRecordMode2_007BEF9C = 0;
        }
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (nX < gnGlobal_0071146C / 2 + 0x17 || nX > gnGlobal_0071146C / 2 + 0x91 || nY < gnGlobal_00711470 - 0x27 || nY > gnGlobal_00711470 - 0xA)
    {
        pMsg->bReturn = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (!UI_GetUIVarUnchecked(9))
    {
        gbUiRecordMode_007BEF98 = 1;
        gnBeltRecordMode2_007BEF9C = 1;
        sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

void __stdcall PANEL_BeltClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        if (sub_00468830() == 6)
        {
            UI_CancelCursorItemUse();
        }
        else if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
        }

        const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
        if (nBox < 0)
        {
            pMsg->bReturn = 0;
            return;
        }

        sub_00498A90_UseBeltSlot(nBox, pPlayer, pPlayer->pInventory, (pMsg->wParam >> 2) & 1);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
    gnBeltHover_007BEF94 = 0;
}
