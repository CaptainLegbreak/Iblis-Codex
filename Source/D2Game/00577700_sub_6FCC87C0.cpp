struct D2GameStrc;
struct D2InventoryStrc;
struct D2NpcGambleStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char bHireInit;
    unsigned char nAct;
    unsigned char bTrader;
};

struct D2NpcRecordStrc
{
    int nNPC;
    D2InventoryStrc* pInventory;
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
    int unk0x10;
    void* pEvent;
    int unk0x18;
    int bTrading;
    D2NpcTradeStrc npcTrade;
};

struct D2NpcVendorChainStrc
{
    int dwGUID;
    unsigned char field_4;
};

#define STAT_QUANTITY 70
#define MONSTER_KASHYA 150
#define MONSTER_GREIZ 198
#define MONSTER_ASHEARA 252
#define MONSTER_QUAL_KEHK 515

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer); // 0x00536CB0
void __fastcall sub_00576070(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00576070
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade); // 0x00576980
void __fastcall sub_00578AE0_FillGambleIfMissing(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2NpcRecordStrc* pNpcRecord); // 0x00578AE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem);                                                        // 0x0062E790
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0

// 0x00577700
D2UnitStrc* __fastcall sub_6FCC87C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* a4)
{
    *a4 = 1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_GetAutoStack(pItem))
    {
        return 0;
    }

    D2UnitStrc* pStackItem = 0;
    int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
    while (1)
    {
        pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    int nQuantity = 0;
    while (1)
    {
        pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    *a4 = nMaxStack;
    return 0;
}

// 0x00578B30
void __fastcall D2GAME_STORES_CreateVendorCache_6FCCAE20(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bGamble)
{
    if (!pNpc)
    {
        return;
    }

    const int nNpcClassId = pNpc->dwClassId;
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        return;
    }

    if (bGamble)
    {
        if (pNpcRecord->bGambleInit)
        {
            SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer)->field_4 = 1;
            sub_00578AE0_FillGambleIfMissing(pGame, pNpc, pPlayer, pNpcRecord);
        }
    }
    else
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->npcTrade;
        if (pTrade && pTrade->bTrader)
        {
            SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer)->field_4 = 0;
            if (!pTrade->bVendorInit)
            {
                D2GAME_NPC_FillStoreInventory_6FCC7100(pGame, pPlayer, pNpc, pTrade);
                pTrade->bVendorInit = 1;
            }

            if (!pTrade->bHireInit)
            {
                if (nNpcClassId == MONSTER_KASHYA || nNpcClassId == MONSTER_QUAL_KEHK || nNpcClassId == MONSTER_GREIZ || nNpcClassId == MONSTER_ASHEARA)
                {
                    sub_00576070(pGame, nNpcClassId, pNpcRecord);
                }
                pTrade->bHireInit = 1;
            }
        }
    }
}
