struct D2ClientStrc;
struct D2InventoryStrc;
struct D2PlayerTradeStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x60 - 0x14];
    D2InventoryStrc* pInventory;
};

struct D2GameStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x5C];
    D2PlayerTradeStrc* pTrade;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x0055F9C0
void __fastcall sub_6FC4BA50(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0055FCC0
void __fastcall sub_6FC90BE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg);                           // 0x00566C80
void __fastcall sub_6FC90C20(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00566CC0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x005678F0
void __fastcall PLRTRADE_RestoreInventory(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (!UNITS_GetPlayerData(pUnit)->pTrade)
    {
        return;
    }

    D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrTrade.cpp", 0x84F), 0x92, 0, !pUnit ? -1 : pUnit->dwUnitId);
    SUNIT_IterateLivingPlayers(pGame, sub_6FC90BE0, pUnit);

    D2UnitStrc* pNext;
    for (D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory); pCurrent; pCurrent = pNext)
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        pNext = INVENTORY_GetNextItem(pCurrent);
        if (pItem && pItem->dwUnitType == 4)
        {
            if (pItem->dwAnimMode == 0)
            {
                ITEMMODE_ResetBookScrollSkillQuantity(pUnit, pItem);
            }

            INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
            ITEMS_SetItemCMDFlag(pItem, 1, 1);
        }
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pUnit->pInventory);
    if (pCursorItem && pCursorItem->dwUnitType == 4)
    {
        INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pCursorItem);
        ITEMS_SetItemCMDFlag(pCursorItem, 1, 1);
    }

    sub_6FC4BA50(pGame, pUnit);
    sub_6FC90C20(pGame, pUnit);
}
