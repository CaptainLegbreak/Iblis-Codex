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

struct D2InventoryStrc;

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
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
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion);      // 0x0061DCA0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810

#define ITEMSPAWN_GROUND 3
#define COLLIDE_MASK_SPAWN 0x3E01

static __declspec(noinline) int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts);

// build: symbol ?$S1@?1??ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PAUD2SeedStrc@@HHHH@Z@4IA 0x008846F0
// build: symbol ?s_nGoldItemId@?1??ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PAUD2SeedStrc@@HHHH@Z@4HA 0x008846EC
// 0x00556240
static int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
{
    static int s_nGoldItemId = DATATBLS_GetItemIdFromItemCode(' dlg');

    D2_ASSERT(s_nGoldItemId != -1, 0x17C);
    D2_ASSERT(s_nGoldItemId != 0, 0x17F);
    D2_ASSERT(nLevelId <= 65, 0x180);

    const int nDiff = 65 - nLevelId;
    const int nBaseLayer = nLevelId >> 1;

    int nAdd = nBaseLayer + 10;
    if (nLevelId % 2)
    {
        nAdd += 1;
    }

    const int nBaseLayerChance = nBaseLayer + nDiff + 5;
    int nWeaponChance;
    int& nWeaponChanceRef = nWeaponChance;
    nWeaponChanceRef = nBaseLayerChance + nAdd;

    const int nRand = sub_00472280(pSeed, 0, 100);
    if (nRand < nDiff)
    {
        return s_nGoldItemId;
    }

    if (nRand < nBaseLayerChance)
    {
        return ITEMMODE_SelectRandomArmorItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < nWeaponChance)
    {
        return ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < 100)
    {
        return ITEMMODE_SelectRandomMiscItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity, bAllowBodyParts);
    }

    D2_ASSERT(0, 0x1BA);
}

D2UnitStrc* __fastcall sub_00559130_DropRandomItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDropOut)
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

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    const int nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, nItemLevel, -1, 0, 0);

    D2CoordStrc coords1;
    D2CoordStrc coords2 = *pCoords;

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
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        if (pItemDropOut)
        {
            *pItemDropOut = itemDrop;
        }
        return pItem;
    }

    return 0;
}
