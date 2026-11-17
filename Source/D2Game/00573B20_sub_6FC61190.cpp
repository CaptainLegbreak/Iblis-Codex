struct D2GameStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x6C];
    int dwBoughtItemId;
};

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
};

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                   // 0x0063ABD0
void* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                      // 0x00633640
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
int __fastcall sub_6FC45060(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);  // 0x00562590

// 0x00573B20
void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterItemCodeStrc* pItemCode, int dwILvl, int dwQuality)
{
    const int nType = pMonster ? pMonster->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    if (!pMonster->pInventory)
    {
        INVENTORY_AllocInventory(0, pMonster);
    }

    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(pItemCode->nItemCode, &nItemId))
    {
        return;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pMonster, nItemId, pGame, 4, dwQuality, 1, 1, dwILvl, 0, 0, 0);
    if (!pItem)
    {
        return;
    }

    ITEMS_SetItemFlag(pItem, 0x1000, 1);
    ITEMS_SetBodyLocation(pItem, pItemCode->nBodyLoc);
    if (pItemCode->nBodyLoc == 0)
    {
        return;
    }

    {
        const int nItemGUID = pItem->dwUnitId;
        int nUnused;
        if (!sub_6FC45060(pGame, pMonster, nItemGUID, ITEMS_GetBodyLocation(pItem), 1, &nUnused))
        {
            SUNIT_RemoveUnit(pGame, pItem);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 0x48, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
        }
    }
}

// 0x00578640
void __fastcall D2GAME_NPC_IdentifyBoughtItem_6FCCA990(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    const int nGUID = nItemGUID;
    if (pPlayerData->dwBoughtItemId != nGUID)
    {
        return;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nGUID);
    if (!pItem || ITEMS_CheckItemFlag(pItem, 0x10, 0xD1F, gszNpcSourceFile))
    {
        return;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
}
