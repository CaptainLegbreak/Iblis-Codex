struct D2GameStrc;
struct D2InventoryStrc;

#define NPC_CLASS_150 150
#define NPC_CLASS_515 515
#define NPC_CLASS_198 198

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01[6];
    unsigned char bRefreshInventory;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x1C];
    int bTrading;
    D2NpcTradeStrc tTrade;
    char unk0x28[0x18];
    int dwNPCGUID;
};

D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536C50
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);          // 0x0063CC70
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00557FD0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
void __fastcall D2GAME_STORES_CreateVendorCache_6FCCAE20(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bGamble); // 0x00578B30
void __fastcall sub_00536D10_ReallocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc); // 0x00536D10
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade); // 0x00576980
void __fastcall sub_00576C30_AddItemsToTrade(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory);            // 0x00576C30

static __forceinline int UNITS_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }

    return -1;
}

// 0x00576650
void __fastcall sub_00576650_AddGambleItem(D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit)
{
    if (!pItem || !pNpc)
    {
        return;
    }

    D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNpc);
    if (!pGambleInventory)
    {
        return;
    }

    int nUnused;
    sub_6FC446B0(pGame, pNpc, UNITS_GetUnitGUIDInline(pItem), &nUnused, 0, 0, pGambleInventory, 0);
    if (bInit)
    {
        pItem->dwFlagEx |= 0x10;
        UNITS_RefreshInventory(pNpc, 1);
        INVENTORY_AddItemToTradeInventory(pGambleInventory, pItem);
        ITEMS_SetItemCMDFlag(pItem, 1, 1);
    }
    else
    {
        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
}

// 0x00579430
void __fastcall D2GAME_STORES_CreateVendorCache_6FCC74F0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC, int bRefreshInventory, int bGamble)
{
    if (!pNPC)
    {
        return;
    }

    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNPC, &nUnused);
    if (!pNpcRecord)
    {
        return;
    }

    pNpcRecord->bTrading = 1;
    pNpcRecord->dwNPCGUID = UNITS_GetUnitGUIDInline(pNPC);
    D2GAME_STORES_CreateVendorCache_6FCCAE20(pGame, pPlayer, pNPC, bGamble);

    const int nClassId = pNPC->dwClassId;
    if (nClassId == NPC_CLASS_150 || nClassId == NPC_CLASS_515 || nClassId == NPC_CLASS_198)
    {
        return;
    }

    if (bRefreshInventory && !bGamble)
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->tTrade;
        if (pTrade->bRefreshInventory)
        {
            pTrade->bRefreshInventory = 0;
            sub_00536D10_ReallocNpcInventory(pGame, pNpcRecord, pNPC);
            D2GAME_NPC_FillStoreInventory_6FCC7100(pGame, pPlayer, pNPC, pTrade);
            pTrade->bVendorInit = 1;
        }
    }

    UNITS_RefreshInventory(pNPC, 1);
    if (!bGamble)
    {
        sub_00576C30_AddItemsToTrade(pNPC, pNPC->pInventory);
    }
    else
    {
        D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNPC);
        if (pGambleInventory)
        {
            sub_00576C30_AddItemsToTrade(pNPC, pGambleInventory);
        }
    }
}
