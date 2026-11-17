struct D2InventoryStrc;
struct D2ItemsTxt;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
static int s_nGoldItemId_0088C6F8;                                                                          // 0x0088C6F8

D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);         // 0x0055BF50
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);                            // 0x0055C270
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
int __fastcall sub_6FC4BFF0(D2GameStrc* pGame, D2SeedStrc* pSeed, int nItemLevel, int a4, int a5);         // 0x00555E70
int __fastcall sub_6FC4C1E0(D2GameStrc* pGame, D2SeedStrc* pSeed, int nItemLevel, int a4, int a5);         // 0x00555FB0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion);      // 0x0061DCA0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_IsMetalItem(int nItemId);                                                               // 0x00629CC0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot);     // 0x0063C4F0
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem);            // 0x0063C790
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define IMODE_INBELT 2
#define IMODE_ONCURSOR 4
#define ITEMSPAWN_GROUND 3
#define ITEMDROPFLAG_SUPERIOR 0x40
#define IFLAG_INSTORE 0x2000
#define COLLIDE_MASK_SPAWN 0x3E01
#define STAT_LEVEL 12
#define UNITFLAG_TARGETABLE 2
#define INVPAGE_NULL 0xFF

// 0x00559300
D2UnitStrc* __fastcall sub_6FC4F640(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    if (!s_nGoldItemId_0088C6F8)
    {
        DATATBLS_GetItemRecordFromItemCode(' dlg', &s_nGoldItemId_0088C6F8);
    }

    D2CoordStrc coords1;
    D2CoordStrc coords2;
    coords2.nX = pCoords->nX;
    coords2.nY = pCoords->nY;

    const int nX = coords2.nX + 2;
    const int nY = coords2.nY + 3;
    if (D2GAME_GetRoom_6FC52070(pRoom, nX, nY))
    {
        coords1.nX = nX;
        coords1.nY = nY;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = 0;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.pGame = pGame;
        itemDrop.nId = s_nGoldItemId_0088C6F8;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, IFLAG_INSTORE, 0);
        }

        return pItem;
    }

    return 0;
}

// 0x005594C0
D2UnitStrc* __fastcall D2GAME_DropArmor_6FC4F830(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    const int nItemId = sub_6FC4BFF0(pGame, pSeed, nItemLevel, a4, a5);
    D2CoordStrc coords1;
    D2CoordStrc coords2;
    if (nItemId >= 0)
    {
        coords2.nX = pCoords->nX;
        coords2.nY = pCoords->nY;

        D2ActiveRoomStrc* pTargetRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pRoom, &coords2, &coords1, 1, 1);
        if (!pTargetRoom)
        {
            return 0;
        }

        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = pUnit;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.dwFlags2 |= ITEMDROPFLAG_SUPERIOR;
        itemDrop.pGame = pGame;
        itemDrop.nId = nItemId;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
    }

    return 0;
}

// 0x00559630
D2UnitStrc* __fastcall D2GAME_DropWeapon_6FC4FA50(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    int nItemId = -1;
    for (int i = 0; i < 6; ++i)
    {
        nItemId = sub_6FC4C1E0(pGame, pSeed, nItemLevel, a4, a5);
        if (nItemId >= 0 && ITEMS_IsMetalItem(nItemId))
        {
            break;
        }
    }

    D2CoordStrc coords1;
    D2CoordStrc coords2;
    if (nItemId >= 0)
    {
        coords2.nX = pCoords->nX;
        coords2.nY = pCoords->nY;

        const int nX = coords2.nX + 2;
        const int nY = coords2.nY + 3;
        if (D2GAME_GetRoom_6FC52070(pRoom, nX, nY))
        {
            coords1.nX = nX;
            coords1.nY = nY;
        }
        else
        {
            coords1.nX = coords2.nX;
            coords1.nY = coords2.nY;
        }

        D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
        if (pTargetRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));

            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = pSeed;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.dwFlags2 |= ITEMDROPFLAG_SUPERIOR;
            itemDrop.pGame = pGame;
            itemDrop.nId = nItemId;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.nX = coords1.nX;
            itemDrop.nY = coords1.nY;
            itemDrop.pRoom = pTargetRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 0;
            itemDrop.nItemLvl = nItemLevel;

            return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

// 0x0055A200
void __fastcall ITEMS_DropPlayerEar(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = 0;
    int nItemId;
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER || !DATATBLS_GetItemRecordFromItemCode(' rae', &nItemId))
    {
        return;
    }

    D2CoordStrc unitCoords;
    D2CoordStrc coords;

    UNITS_GetCoords(pUnit, &unitCoords);

    pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &unitCoords, &coords, 1, 1);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pUnit, nItemId, pGame, 4, 2, 1, 1, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 0, 0, 0);
    if (pItem)
    {
        D2GAME_DropItem_6FC52260(pGame, 0, pItem, pRoom, coords.nX, coords.nY);
    }
}

// 0x0055E9B0
int __fastcall sub_6FC48940(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6)
{
    D2_ASSERT(pGame, 0x11FB);
    D2_ASSERT(pUnit, 0x11FC);

    *a6 = 0;

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1201);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        *a6 = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_ONCURSOR)
    {
        *a6 = 1;
        return 0;
    }

    do
    {
        if (!ITEMS_CheckIfBeltable(pItem))
        {
            break;
        }

        D2InventoryStrc* pInventory = pUnit->pInventory;
        if (bFindFreeSlot)
        {
            if (!INVENTORY_PlaceItemInFreeBeltSlot(pInventory, pItem))
            {
                break;
            }
        }
        else
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, ".\\ITEMS\\ItemMode.cpp", 0x1222);

            if (!INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, nBeltSlot))
            {
                break;
            }

            ITEMS_SetInvPage(pItem, INVPAGE_NULL);
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
        {
            INVENTORY_SetCursorItem(pInventory, 0);
            sub_0055C270_OnItemToBelt(pUnit, pItem);

            pItem->dwFlags &= ~UNITFLAG_TARGETABLE;

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pItem, IMODE_INBELT);
            ITEMS_SetInvPage(pItem, INVPAGE_NULL);
            ITEMS_SetItemCMDFlag(pItem, 0x400, 1);
            UNITS_RefreshInventory(pUnit, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            return 1;
        }

        *a6 = 1;
    }
    while (0);

    return 0;
}
