struct D2GameStrc;
struct D2InventoryStrc;
struct D2MonsterInteractStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x04];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x48];
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
    char unk0x00[0x20];
    D2NpcTradeStrc npcTrade;
};

enum { UNIT_MONSTER = 1 };

extern int gnNpcGUID_0088CAC4; // 0x0088CAC4
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory); // 0x0063CB70
void __stdcall sub_0063BD00_Return(D2InventoryStrc* pInventory); // 0x0063BD00
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade); // 0x00576980

static __forceinline D2NpcTradeStrc* SUNITNPC_GetNpcTrade(D2NpcRecordStrc* pNpcRecord)
{
    if (pNpcRecord)
    {
        return &pNpcRecord->npcTrade;
    }

    return 0;
}

// 0x00579090
void __fastcall sub_00579090_RefillNpcStore(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (!gnNpcGUID_0088CAC4)
    {
        return;
    }

    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, gnNpcGUID_0088CAC4);
    if (!pNpc)
    {
        return;
    }

    int bHasInteractUnit;
    if (pNpc->dwUnitType == UNIT_MONSTER && pNpc->pMonsterData)
    {
        bHasInteractUnit = MONSTERAI_HasInteractUnit(pNpc->pMonsterData->pMonInteract);
    }
    else
    {
        bHasInteractUnit = MONSTERAI_HasInteractUnit(0);
    }

    if (bHasInteractUnit == 1)
    {
        return;
    }

    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nIndex);
    D2InventoryStrc* pInventory = pNpc->pInventory;
    if (pInventory)
    {
        INVENTORY_RemoveInventoryItems(pInventory);
        sub_0063BD00_Return(pInventory);
    }

    D2NpcTradeStrc* pTrade = SUNITNPC_GetNpcTrade(pNpcRecord);
    if (pTrade && pTrade->bTrader)
    {
        pTrade->bVendorInit = 0;
        D2UnitStrc* const pStorePlayer = *(D2UnitStrc* volatile*)&pPlayer;
        D2GameStrc* const pStoreGame = *(D2GameStrc* volatile*)&pGame;
        D2GAME_NPC_FillStoreInventory_6FCC7100(pStoreGame, pStorePlayer, pNpc, pTrade);
        pTrade->bVendorInit = 1;
    }
}
