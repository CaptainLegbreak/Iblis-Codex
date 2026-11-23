#include "D2Structs.h"
#define MV(x) (x)
#define PACKET(x) (x)
struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc;

int __cdecl sub_00468830();
D2UnitStrc* __cdecl sub_004680A0();
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5);
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);
int __cdecl sub_00486B80_IsNpcStateB();
int __cdecl sub_00486D10_CheckTick();
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004C21F0(D2UnitStrc* pItem);
int __fastcall sub_004C2240(D2UnitStrc* pItem);
int __fastcall sub_004C1D60(D2UnitStrc* pItem);
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId);
int __fastcall sub_004B3870(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8);
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);  // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);  // 0x0063BDE0
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck);  // 0x0063DE60
int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem);
extern int gnInvPanelMode;  // 0x007BCBF0
int gbNpcTradeClicked;         // 0x007BCBEC
extern int gnInvMouseX;  // 0x007BCA4C
extern int gnInvMouseY;  // 0x007BCBD8
static void __stdcall INV_ForwardTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gnInvPanelMode = 5;
    sub_00468070_SetCursorItemState(0);
}

// 0x00490780
int __fastcall sub_00490780(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, MV(5));
    D2UnitStrc* pSelected = INVENTORY_GetItemFromBodyLoc(pInventory, MV(4));
    if (sub_00468830() == MV(6))
    {
        D2UnitStrc* pCursor = sub_004680A0();
        if (pCursor && pSelected && !sub_004C2240(pSelected) && sub_00486D10_CheckTick())
        {
            sub_004786A0_SendDwords2(PACKET(0x27), !pSelected ? -1 : pSelected->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
            sub_004C21F0(pSelected);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        if (pSelected && !sub_004C2240(pSelected) && sub_00486D10_CheckTick())
        {
            sub_00478680_SendPacket5(PACKET(0x4C), !pSelected ? -1 : pSelected->dwUnitId);
            sub_004C21F0(pSelected);
            nResult = 1;
        }
    }
    switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
    {
    case 0:
        if (pItem)
        {
            if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
            {
                const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                {
                    sub_004CB9C0_Request(pPlayer, MV(0x14));
                    return 1;
                }
            }
            sub_004CB9C0_Request(pPlayer, MV(0x13));
        }
        return 1;
    case 1:
        if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
        {
            sub_004786A0_SendDwords2(PACKET(0x1A), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pItem);
            sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 2:
        if (!sub_004C2240(pItem) && !sub_004C2240(pOther) && sub_00486D10_CheckTick())
        {
            sub_004786A0_SendDwords2(PACKET(0x1B), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pOther);
            sub_004C21F0(pItem);
            sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 3:
        if (sub_00486B80_IsNpcStateB())
        {
            if (!sub_004C2240(pSelected) && sub_00486D10_CheckTick())
            {
                sub_004785B0_SendPacket3(PACKET(0x1C), MV(4));
                sub_004C21F0(pSelected);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
        }
        else if (gnInvPanelMode < MV(0x13))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pSelected, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        break;
    case 4:
        if (gnInvPanelMode == MV(4))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pOther, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        else if (!sub_004C2240(pOther) && sub_00486D10_CheckTick())
        {
            sub_004785B0_SendPacket3(PACKET(0x1C), MV(5));
            sub_004C21F0(pOther);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 5:
        if (!sub_004C2240(pSelected) && sub_00486D10_CheckTick())
        {
            sub_004786A0_SendDwords2(PACKET(0x1D), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pItem);
            sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 7:
        if (!sub_004C2240(pItem) && !sub_004C2240(pSelected) && !sub_004C2240(pOther) && sub_00486D10_CheckTick())
        {
            sub_004786A0_SendDwords2(PACKET(0x1E), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pItem);
            sub_004C21F0(pSelected);
            sub_004C21F0(pOther);
            nResult = 1;
        }
        break;
    case 6:
        if (!sub_004C2240(pItem) && sub_00486D10_CheckTick() && gnInvPanelMode != MV(0xB))
        {
            sub_004786A0_SendDwords2(PACKET(0x21), !pItem ? -1 : pItem->dwUnitId, !pSelected ? -1 : pSelected->dwUnitId);
            sub_004C21F0(pItem);
            sub_004B9A00(sub_004C1D60(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    }
    return nResult;
}
