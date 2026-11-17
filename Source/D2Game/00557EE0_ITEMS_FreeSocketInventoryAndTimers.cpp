#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define IMODE_SOCKETED 6
#define STAT_LEVEL 12

struct D2InventoryStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwItemMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
};

struct D2GameStrc
{
    char unk0x0000[0x6D];
    unsigned char nDifficulty;
    char unk0x006E[0x2];
    int bExpansion;
    char unk0x0074[0x10AC];
    D2UnitStrc* pUnitList[5][128];
};

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x00555AE0
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion);      // 0x0061DCA0

// 0x00557EE0
void __fastcall ITEMS_FreeSocketInventoryAndTimers(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_CheckIfSocketable(pItem))
    {
        SUNIT_RemoveAllItemsFromInventory(pGame, pItem);
        INVENTORY_FreeInventory(pItem->pInventory);
    }

    sub_6FC349F0(pGame, pItem);
}

// 0x00557F10
void __fastcall ITEMS_RemoveAll(D2GameStrc* pGame)
{
    D2UnitStrc** ppUnit = pGame->pUnitList[3];
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pUnit = *ppUnit;
        while (pUnit)
        {
            if (pUnit->dwItemMode != IMODE_SOCKETED)
            {
                SUNIT_RemoveUnit(pGame, pUnit);
                pUnit = *ppUnit;
            }
            else
            {
                pUnit = SUNIT_GetNextUnitFromList(pUnit);
            }
        }
        ++ppUnit;
    }
}

// 0x00558200
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
            return nLevel > 1 ? nLevel : 1;
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
            return nLevel > 1 ? nLevel : 1;
        }

        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    }
    else if (!nLevelId)
    {
        return 1;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const int nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    return nLevel > 1 ? nLevel : 1;
}
