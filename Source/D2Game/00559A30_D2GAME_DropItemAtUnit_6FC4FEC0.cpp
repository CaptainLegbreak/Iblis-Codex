struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x90];
    unsigned int dwDropItemCode;
};

struct D2ActiveRoomStrcView
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x0000[0x6D];
    unsigned char nDifficulty;
    char unk0x006E[0x2];
    int bExpansion;
    char unk0x0074[0x4];
    unsigned short wItemFormat;
};

struct D2ItemsTxt
{
    char unk0x00[0xDC];
    unsigned int dwBitField1;
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

int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555E70
int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555FB0
int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x005560F0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion);      // 0x0061DCA0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);  // 0x00558D90
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

// build: symbol ?ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PAUD2SeedStrc@@HHHH@Z 0x00556240
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
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity)
{
    D2_ASSERT(pGame, 0x9C7);

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
        nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity, bIsMonster);
        if (nQuality == 4)
        {
            int nCounter = 0;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
            while (!pItemsTxtRecord || !(pItemsTxtRecord->dwBitField1 & 1))
            {
                if (nCounter > 10)
                {
                    nItemId = ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity);
                }
                else
                {
                    nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity, bIsMonster);
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

        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.nQuality = nQuality;
        itemDrop.nItemLvl = *pItemLevel;
        itemDrop.pUnit = pUnit;
        itemDrop.pSeed = 0;
        itemDrop.pGame = pGame;
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = 3;
        itemDrop.wUnitInitFlags = 1;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);

        if (pItemDrop)
        {
            *pItemDrop = itemDrop;
        }

        return pItem;
    }

    return 0;
}
