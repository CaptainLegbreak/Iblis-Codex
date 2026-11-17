#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char f_74[0x04];
    unsigned short wItemFormat;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define ITEMDROPFLAG_NEVERETH 0x2
#define ITEMDROPFLAG_NOSOCKETS 0x8

// 0x00558200
__forceinline int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId)
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

// 0x00559CE0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed)
{
    if (nItemLevel <= 0)
    {
        nItemLevel = 1;
    }

    D2ItemDropStrc itemDrop = {};
    itemDrop.wItemFormat = pGame->wItemFormat;
    itemDrop.pSeed = 0;
    itemDrop.nSpawnType = nSpawnTarget;
    itemDrop.nX = 0;
    itemDrop.nY = 0;
    itemDrop.pRoom = 0;
    itemDrop.nQuality = nQuality;
    itemDrop.dwFlags2 |= (bNoEthereal ? ITEMDROPFLAG_NEVERETH : 0) | (bNoSockets ? ITEMDROPFLAG_NOSOCKETS : 0);
    itemDrop.nId = nItemId;
    itemDrop.pUnit = pPlayer;
    itemDrop.pGame = pGame;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.dwSeed = dwSeed;
    itemDrop.dwItemSeed = dwItemSeed;

    if (nItemLevel == -1)
    {
        itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
    }
    else
    {
        itemDrop.nItemLvl = nItemLevel;
    }

    if (itemDrop.nItemLvl <= 0)
    {
        itemDrop.nItemLvl = 1;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, bUseSeed);
    if (pItem)
    {
        ITEMS_SetItemFlag(pItem, 0x10, 1);
    }
    return pItem;
}
