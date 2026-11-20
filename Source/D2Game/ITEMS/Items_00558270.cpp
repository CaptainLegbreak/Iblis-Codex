#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_ITEM 4
#define ITEMTYPE_GOLD 4
#define ITEMTYPE_PLAYER_BODY_PART 7
#define STAT_GOLD 14
#define STAT_MAXDURABILITY 73
#define UNITFLAG_TARGETABLE 2
#define EVENTTYPE_STATREGEN 3
#define IFLAG_RUNEWORD 0x4000000
#define STATE_RUNEWORD 171
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2ItemDataStrc;
struct D2ActiveRoomStrcView;
struct D2ItemsTxt;



struct D2ItemDataStrc
{
    char unk0x00[0x24];
    int dwActionStamp;
};


struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    char unk0x78[0x04];
    D2ActiveRoomStrc* pRoomNext;
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
    unsigned char eEarLvl;
    char unk0x51[3];
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

typedef void(__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x00557FA0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem); // 0x006283A0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, int nPrefix, int nIndex); // 0x00627EF0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
extern int gdwHealthPotionCodes_00731F4C[4]; // 0x00731F4C
extern unsigned int gnHealthPotionCodes_00731F5C; // 0x00731F5C
extern int gdwManaPotionCodes_00731F60[4]; // 0x00731F60
extern unsigned int gnManaPotionCodes_00731F70; // 0x00731F70


struct D2ActiveRoomStrcView
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555E70
int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555FB0
int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x005560F0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00558270
void __fastcall ITEMS_FillItemDrop(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    memset(pItemDrop, 0, sizeof(D2ItemDropStrc));

    pItemDrop->pGame = pGame;
    pItemDrop->wItemFormat = ITEMS_GetItemFormat(pItem);
    pItemDrop->nItemLvl = ITEMS_GetItemLevel(pItem);
    if (pItemDrop->nItemLvl <= 0)
    {
        pItemDrop->nItemLvl = 1;
    }

    pItemDrop->nId = !pItem ? -1 : pItem->dwClassId;
    pItemDrop->nSpawnType = !pItem ? 0 : pItem->dwAnimMode;
    pItemDrop->nQuality = ITEMS_GetItemQuality(pItem);
    pItemDrop->nX = CLIENTS_GetUnitX(pItem);
    pItemDrop->nY = CLIENTS_GetUnitY(pItem);

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        pItemDrop->nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
    }
    else if (ITEMS_CheckIfStackable(pItem))
    {
        const int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);

        D2_ASSERT(nQuantity >= 0, 3241);

        pItemDrop->nQuantity = nQuantity;
    }

    pItemDrop->pSeed = &pItem->pSeed;
    pItemDrop->wUnitInitFlags = 1;
    pItemDrop->dwSeed = pItem->dwInitSeed;
    pItemDrop->dwItemSeed = ITEMS_GetItemStartSeed(pItem);
    pItemDrop->nItemIndex = ITEMS_GetFileIndex(pItem);
    pItemDrop->dwFlags1 = ITEMS_GetItemFlags(pItem);
    pItemDrop->nMinDur = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
    pItemDrop->nMaxDur = STATLIST_GetUnitBaseStat(pItem, STAT_MAXDURABILITY, 0);
    pItemDrop->nItemIndex = ITEMS_GetFileIndex(pItem);
    pItemDrop->bForce = 0;

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_PLAYER_BODY_PART)
    {
        strcpy(pItemDrop->szName, ITEMS_GetEarName(pItem));
        pItemDrop->eEarLvl = ITEMS_GetEarLevel(pItem);
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, 3265, ".\\ITEMS\\Items.cpp"))
    {
        strcpy(pItemDrop->szName, ITEMS_GetEarName(pItem));
    }
}

// 0x00558B90
void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct)
{
    if (!pGame->pAct[nAct])
    {
        return;
    }

    const int nGameFrame = pGame->dwGameFrame;
    for (D2ActiveRoomStrc* i = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); i; i = i->pRoomNext)
    {
        D2UnitStrc* pNext = i->pUnitFirst;
        while (pNext)
        {
            D2UnitStrc* pItem = pNext;
            pNext = pItem->ptRoomNext;
            if (pItem->dwUnitType == UNIT_ITEM)
            {
                const int nDeletionFrame = pItem->pItemData->dwActionStamp;
                if (nDeletionFrame && nDeletionFrame <= nGameFrame)
                {
                    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                    if (pRoom)
                    {
                        DUNGEON_AllocDrlgDelete(pRoom, pItem->dwUnitType, pItem->dwUnitId);
                        UNITS_FreeCollisionPath(pItem);
                        UNITROOM_RemoveUnitFromRoom(pItem);
                    }

                    pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
                    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
                    SUNIT_RemoveUnit(pGame, pItem);
                }
            }
        }
    }
}

// 0x00558450
int __fastcall ITEMS_GetHealthPotionDropCode(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(hRoom, 0xD5E);

    unsigned char nIndex = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (pGame && pGame->nDifficulty > DIFFMODE_NORMAL)
    {
        nIndex += 2;
    }

    if (nIndex >= gnHealthPotionCodes_00731F5C)
    {
        return gdwHealthPotionCodes_00731F4C[3];
    }

    return gdwHealthPotionCodes_00731F4C[nIndex];
}

// 0x005584C0
int __fastcall ITEMS_GetManaPotionDropCode(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(hRoom, 0xD7D);

    unsigned char nIndex = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (pGame && pGame->nDifficulty > DIFFMODE_NORMAL)
    {
        nIndex += 2;
    }

    if (nIndex >= gnManaPotionCodes_00731F70)
    {
        return gdwManaPotionCodes_00731F60[3];
    }

    return gdwManaPotionCodes_00731F60[nIndex];
}

// 0x00558530
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nReplenishDurability = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_REPLENISH_DURABILITY, 0);
    if (nReplenishDurability && !EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_STATREGEN))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, 2500 / nReplenishDurability + pGame->dwGameFrame + 1, 0, 0);
    }
}

// 0x00558580
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nReplenishQuantity = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_REPLENISH_QUANTITY, 0);
    if (nReplenishQuantity && !EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_STATREGEN))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, 2500 / nReplenishQuantity + pGame->dwGameFrame + 1, 0, 0);
    }
}

// 0x00558C50
void __fastcall ITEMS_DestroyRunewordStatList(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM || !(ITEMS_GetItemFlags(pItem) & IFLAG_RUNEWORD))
    {
        return;
    }

    ITEMS_SetItemFlag(pItem, IFLAG_RUNEWORD, 0);
    ITEMS_AssignPrefix(pItem, 0, 0);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, STATE_RUNEWORD, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
}

#include "gen/data/Source/D2Game/ITEMS/Items_00558270.inc"

// build: symbol ?ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PATD2SeedStrc@@HHHH@Z 0x00556240
static int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
{
    static int s_nGoldItemId = DATATBLS_GetItemIdFromItemCode(' dlg');

    D2_ASSERT(s_nGoldItemId != -1, 0x17C);
    D2_ASSERT(s_nGoldItemId != 0, 0x17F);
    D2_ASSERT(nLevelId <= 65, 0x180);

    const int nBaseLayer = nLevelId >> 1;
    const int nDiff = 65 - nLevelId;

    int nAdd = nBaseLayer + 10;
    if (nLevelId % 2)
    {
        nAdd += 1;
    }

    const int nBaseLayerChance = nBaseLayer + nDiff + 5;
    nAdd += nBaseLayerChance;

    const int nRand = sub_00472280(pSeed, 0, 100);
    if (nRand < nDiff)
    {
        return s_nGoldItemId;
    }

    if (nRand < nBaseLayerChance)
    {
        return ITEMMODE_SelectRandomArmorItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < nAdd)
    {
        return ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < 100)
    {
        return ITEMMODE_SelectRandomMiscItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity, bAllowBodyParts);
    }

    D2_ASSERT(0, 0x1BA);
}

D2UnitStrc* __fastcall ITEMS_DropRandomItemAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDrop)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    if (nItemLevel >= 65)
    {
        nItemLevel = 64;
    }

    D2SeedStrc* pSeed;
    if (pRoom)
    {
        pSeed = &((D2ActiveRoomStrcView*)pRoom)->pSeed;
    }
    else
    {
        pSeed = 0;
    }

    const int nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, nItemLevel, -1, 0, 0);

    D2CoordStrc coords1;
    D2CoordStrc coords2;

    coords2.nX = pCoords->nX;
    coords2.nY = pCoords->nY;

    if (D2GAME_GetRoom_6FC52070(pRoom, coords2.nX + 2, coords2.nY + 3))
    {
        coords1.nX = coords2.nX + 2;
        coords1.nY = coords2.nY + 3;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, 0x3E01, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop = {};

        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.nId = nItemId;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pUnit = 0;
        itemDrop.pGame = pGame;
        itemDrop.nSpawnType = 3;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);

        if (pItemDrop)
        {
            *pItemDrop = itemDrop;
        }

        return pItem;
    }

    return 0;
}

// 0x00559A30
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity)
{
    D2_ASSERT(ptGame, 0x9C7);

    D2SeedStrc* pSeed = &pUnit->pSeed;

    int bIsMonster = 0;
    if (pUnit && pUnit->dwUnitType == 1)
    {
        bIsMonster = 1;
    }

    int nLevel;
    if (pUnit)
    {
        if (pUnit->dwUnitType == 1)
        {
            nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
        }
        else if (pUnit->dwUnitType == 0)
        {
            nLevel = STATLIST_GetUnitBaseStat(pUnit, 12, 0);
        }
        else
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            D2GameStrc* pUnitGame = SUNIT_GetGameFromUnit(pUnit);
            nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pUnitGame->nDifficulty, pUnitGame->bExpansion);
        }

        if (nLevel <= 1)
        {
            nLevel = 1;
        }
    }
    else
    {
        nLevel = 1;
    }
    *pItemLevel = nLevel;

    int nItemId = -1;
    if (!pUnit->dwDropItemCode)
    {
        nItemId = ITEMS_SelectRandomDropItemId(ptGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity, bIsMonster);
        if (nQuality == 4)
        {
            int nCounter = 0;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
            while (!pItemsTxtRecord || !(pItemsTxtRecord->dwBitField1 & 1))
            {
                if (nCounter > 10)
                {
                    nItemId = ITEMMODE_SelectRandomWeaponItemId(ptGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity);
                }
                else
                {
                    nItemId = ITEMS_SelectRandomDropItemId(ptGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity, bIsMonster);
                }

                pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
                nCounter += 1;
            }
        }
    }
    else
    {
        nItemId = DATATBLS_GetItemIdFromItemCode(pUnit->dwDropItemCode);
        D2_ASSERT(nItemId != -1, 0x9EA);
    }

    D2CoordStrc coords1;
    D2CoordStrc unitCoords;

    UNITS_GetCoords(pUnit, &unitCoords);

    D2ActiveRoomStrc* pTargetRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &unitCoords, &coords1, 1, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop = {};

        itemDrop.wItemFormat = ptGame->wItemFormat;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.nQuality = nQuality;
        itemDrop.nItemLvl = *pItemLevel;
        itemDrop.pUnit = pUnit;
        itemDrop.pSeed = 0;
        itemDrop.pGame = ptGame;
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = 3;
        itemDrop.wUnitInitFlags = 1;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(ptGame, &itemDrop, 0);

        if (pItemDrop)
        {
            *pItemDrop = itemDrop;
        }

        return pItem;
    }

    return 0;
}
