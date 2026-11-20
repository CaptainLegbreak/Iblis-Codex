#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define IMODE_SOCKETED 6
#define STAT_LEVEL 12
#define STAT_ITEM_MAGICBONUS 80
#define UNIT_ITEM 4
#define ITEMDROPFLAG_SUPERIOR 0x40
#define UNITFLAG_TARGETABLE 2

struct D2SeedStrc;
struct D2ItemsTxt;
struct D2ItemRatioTxt;
struct D2QualityModsStrc;
struct D2ItemTypesTxt;
struct D2SaveHeaderStrc;
struct D2PlayerDataStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

struct D2UniqueItemsTxt
{
    char unk0x000[0x2C];
    unsigned char nUniqueItemFlags[4];
    char unk0x030[0x11C];
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __fastcall sub_005564D0_IsDroppedUnique(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x005564D0

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    union
    {
        int nItemLevel;
        int nItemLvl;
    };
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
    char unk0x34[0x0C];
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

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __stdcall sub_005566B0_RollUniqueItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005566B0
int __stdcall ITEMS_RollItemQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x00556F60
unsigned short __fastcall sub_005C1BC0_RollTemperedAffix(D2UnitStrc* pItem, int bPrefix); // 0x005C1BC0
int __fastcall D2GAME_RollRareItem_6FC53360(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21A0
int __fastcall sub_005C21D0_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21D0
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll); // 0x005C2540
int __fastcall sub_005C2940_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2940
int __fastcall ITEMS_RollSuperiorItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2AD0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
void __stdcall ITEMS_SetItemQuality(D2UnitStrc* pItem, int nQuality); // 0x00627EA0
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BCB0
void* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed); // 0x00650E50
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, void* pProperty, int nArg2, int nArg5); // 0x0065FEC0
static void __stdcall ITEMS_AssignLegacySpecialProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x00556D80
static void D2GAME_ITEMS_AssignSpecial_6FC4DB60(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x00556E80
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc*); // 0x00554010
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int, unsigned char, unsigned short); // 0x00637910
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
extern const int gnQualityOrder_006E1138[6]; // 0x006E1138
unsigned char __stdcall sub_0062E8D0_HasAltInvGfx(D2UnitStrc* pItem); // 0x0062E8D0
void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555AE0
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180

typedef void(__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x00557FA0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

struct D2QualityModsStrc
{
    unsigned short f_0;
    unsigned short wRare;
    unsigned short wSet;
    unsigned short wUnique;
};
int __fastcall sub_00558610_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2); // 0x00558610

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char bMode;
    unsigned char pad0x09[3];
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
};

struct D2SaveHeaderStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558530
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558580
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555E70
int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555FB0
int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x005560F0
static int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x00556240
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C270
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C790
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

static void __stdcall ITEMS_RollDropSockets(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem);
static void __stdcall ITEMS_ResetToNormalQuality(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int nLowSeed);
static int ITEMS_ResetToSuperiorQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed);
static int __stdcall sub_00557380_ResetToMagicQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed);
static int sub_005573F0_ResetToRareQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed);
static void __stdcall ITEMS_AssignSpecialPropertiesForFormat(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);

// 0x00556360
static __declspec(noinline) void sub_00556360_RollArmorClass(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1C9);

    const unsigned int nMinAc = pItemsTxtRecord->dwMinAc;
    const unsigned int nMaxAc = pItemsTxtRecord->dwMaxAc;
    const unsigned int nACValue = sub_00472280(&pItem->pSeed, nMinAc, nMaxAc - nMinAc + 1);
    D2_ASSERT(nACValue <= nMaxAc, 0x1CE);
    STATLIST_SetUnitStat(pItem, 31, nACValue, 0);
}

// 0x005563D0
static __declspec(noinline) void sub_005563D0_SetWeaponDamage(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1DB);

    if (pItemsTxtRecord->nMaxDam)
    {
        STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
    }

    if (pItemsTxtRecord->nMinDam)
    {
        STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMinDam)
    {
        STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMaxDam)
    {
        STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
    }

    if (pItemsTxtRecord->nMaxMisDam)
    {
        STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
        STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
    }
}

void sub_A04_Emit_00557AB0(D2UnitStrc** ppItem, int bWeapon)
{
    if (bWeapon)
    {
        sub_005563D0_SetWeaponDamage(*ppItem);
    }
    else
    {
        sub_00556360_RollArmorClass(*ppItem);
    }
}

// 0x005564A0
static __declspec(noinline) unsigned int ITEMS_HasUniqueBeenDroppedAlready(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

inline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecord(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }

    return 0;
}

// 0x00556530
static int __stdcall ITEMS_CanUniqueItemBeDropped(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nFileIndex = ITEMS_GetFileIndex(pItem);
    D2UniqueItemsTxt* pUniqueItemsTxtRecord = ITEMS_GetUniqueItemsTxtRecord(nFileIndex);
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    if (pUniqueItemsTxtRecord->nUniqueItemFlags[0] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_NOLIMIT])
    {
        return 1;
    }

    if ((pItemsTxtRecord->nQuest || !sub_005564D0_IsDroppedUnique(pGame, pItem)) && nFileIndex <= 4096)
    {
        pGame->dwUniqueFlags[nFileIndex >> 5] |= gdwBitMasks[nFileIndex & 0x1F];
        return 1;
    }

    return 0;
}

int __fastcall sub_K11_Emit005564A0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_CanUniqueItemBeDropped(pGame, pItem))
    {
        return ITEMS_HasUniqueBeenDroppedAlready(pGame, ITEMS_GetFileIndex(pItem));
    }

    return 0;
}

// 0x005565E0
static int __stdcall ITEMS_AssignDropMagicAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem)
{
    const int nPrefixId = pItemDrop->nPrefix[0];
    int bForceSuffixRoll = 0;
    int bForcePrefixRoll = 0;
    unsigned short nPrefix = 0;
    unsigned short nSuffix = 0;
    if (nPrefixId < 0)
    {
        bForceSuffixRoll = 1;
    }
    else
    {
        if (nPrefixId > 0)
        {
            bForcePrefixRoll = 1;
        }

        nPrefix = ITEMS_RollMagicAffixes(*ppItem, 1, bForcePrefixRoll, 1, 1, nPrefixId);
        ITEMS_AssignPrefix(*ppItem, nPrefix, 0);
        if (!nPrefix)
        {
            bForceSuffixRoll = 1;
        }
    }

    if (bForceSuffixRoll || pItemDrop->nSuffix[0] >= 0)
    {
        if (pItemDrop->nSuffix[0] > 0)
        {
            bForceSuffixRoll = 1;
        }

        nSuffix = ITEMS_RollMagicAffixes(*ppItem, 1, bForceSuffixRoll, 1, 0, pItemDrop->nSuffix[0]);
        ITEMS_AssignSuffix(*ppItem, nSuffix, 0);
    }

    if (!nPrefix && !nSuffix)
    {
        return 0;
    }

    ITEMS_SetItemFlag(*ppItem, 0x10, 0);
    ITEMS_AssignStaffModsForFormat(*ppItem, pItemDrop);
    return 1;
}

// 0x00556CA0
static void ITEMS_MakeEthereal(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (pItemDrop->dwFlags2 & 2)
    {
        return;
    }

    if (!ITEMSIsA(pItem, 0x2D) && !ITEMSIsA(pItem, 0x32))
    {
        return;
    }

    if (!ITEMS_HasDurability(pItem))
    {
        return;
    }

    switch (ITEMS_GetItemQuality(pItem))
    {
    case 1:
    case 5:
        return;
    }

    if (ITEMS_IsQuestItem(pItem))
    {
        return;
    }

    int bApplyEthereality = 0;
    const int nRoll = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), 100);
    if (nRoll < 5)
    {
        bApplyEthereality = 1;
    }

    if (pItemDrop->dwFlags1 & 0x400000)
    {
        bApplyEthereality = 1;
    }

    if ((pItemDrop->dwFlags2 & 4) || bApplyEthereality)
    {
        ITEMMODS_ApplyEthereality(pItem);
        if (ITEMS_HasDurability(pItem))
        {
            const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, 0x49, 0) / 2 + 1;
            STATLIST_SetUnitStat(pItem, 0x49, nMaxDurability, 0);
            const int nDurability = STATLIST_UnitGetStatValue(pItem, 0x49, 0);
            STATLIST_SetUnitStat(pItem, 0x48, nDurability, 0);
        }
    }
}

__forceinline D2ItemsTxt* ITEMMODE_GetItemsTxtRecordOfItem_H10(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4)
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    }

    return 0;
}

int __fastcall ITEMMODE_AssignItemQualityAndProperties(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop)
{
    D2ItemsTxt* pItemsTxtRecord = ITEMMODE_GetItemsTxtRecordOfItem_H10(*ppItem);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetAutoAffix(*ppItem, 0);
    for (int i = 0; i < 3; i += 1)
    {
        ITEMS_AssignPrefix(*ppItem, 0, i);
        ITEMS_AssignSuffix(*ppItem, 0, i);
    }

    ITEMS_AssignRarePrefix(*ppItem, 0);
    ITEMS_AssignRareSuffix(*ppItem, 0);

    int nQuality = ITEMS_RollItemQuality(*ppItem, pItemDrop);
    if (pItemDrop->nQuality)
    {
        nQuality = pItemDrop->nQuality;
    }
    ITEMS_SetItemQuality(*ppItem, nQuality);

    if (ITEMS_CanBeMagic(*ppItem))
    {
        if (ITEMS_IsQuestItem(*ppItem))
        {
            ITEMS_SetItemQuality(*ppItem, 7);
        }
        else if (!ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem))
        {
            ITEMS_SetItemQuality(*ppItem, 4);
        }
    }

    if (!ITEMS_CanBeRare(*ppItem) && ITEMS_GetItemQuality(*ppItem) == 6)
    {
        ITEMS_SetItemQuality(*ppItem, 4);
    }

    if (sub_00628C70(*ppItem))
    {
        ITEMS_SetItemQuality(*ppItem, 7);
    }

    if (ITEMS_CanBeNormal(*ppItem))
    {
        ITEMS_SetItemQuality(*ppItem, 2);
    }

    unsigned int nSeed;
    int nMaxDurability;
    switch (ITEMS_GetItemQuality(*ppItem))
    {
    case 1:
    {
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C2FB0_ApplyLowQuality(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case 2:
        ITEMS_AssignSpecialPropertiesForFormat(pGame, *ppItem, pItemDrop);
        break;
    case 3:
    {
        ITEMS_SetFileIndex(*ppItem, -1);
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_RollSuperiorItem(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case 6:
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!D2GAME_RollRareItem_6FC53360(*ppItem, pItemDrop))
        {
            if (!sub_00557380_ResetToMagicQuality(pItemDrop, ppItem, &nSeed))
            {
                if (!ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
                {
                    ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
                }
            }
        }
        break;
    case 4:
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_AssignDropMagicAffixes(pItemDrop, ppItem))
        {
            if (!ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;
    case 7:
        ITEMS_SetFileIndex(*ppItem, -1);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005566B0_RollUniqueItem(pGame, *ppItem, pItemDrop))
        {
            if (ITEMS_HasDurability(*ppItem) && ITEMS_GetItemFormat(*ppItem) >= 1)
            {
                const int nDurability = STATLIST_UnitGetStatValue(*ppItem, 0x48, 0);
                nMaxDurability = STATLIST_GetUnitBaseStat(*ppItem, 0x49, 0);
                STATLIST_SetUnitStat(*ppItem, 0x48, D2_MIN(3 * nDurability, 0xFF), 0);
                STATLIST_SetUnitStat(*ppItem, 0x49, D2_MIN(3 * nMaxDurability, 0xFF), 0);
            }

            if (!sub_005573F0_ResetToRareQuality(pItemDrop, ppItem, &nSeed))
            {
                if (!sub_00557380_ResetToMagicQuality(pItemDrop, ppItem, &nSeed))
                {
                    if (!ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
                    {
                        ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
                    }
                }
            }
        }
        break;
    case 8:
    {
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C21D0_RollCraftedItem(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case 9:
    {
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        const unsigned short nRarePrefix = sub_005C1BC0_RollTemperedAffix(*ppItem, 1);
        const unsigned short nRareSuffix = sub_005C1BC0_RollTemperedAffix(*ppItem, 0);
        if (nRarePrefix && nRareSuffix)
        {
            ITEMS_AssignRarePrefix(*ppItem, nRarePrefix);
            ITEMS_AssignRareSuffix(*ppItem, nRareSuffix);
        }
        else
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
        }
        break;
    }
    case 5:
        ITEMS_SetFileIndex(*ppItem, -1);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C2940_RollSetItem(*ppItem, pItemDrop))
        {
            if (ITEMS_HasDurability(*ppItem) && ITEMS_GetItemFormat(*ppItem) >= 1)
            {
                const int nDurability = STATLIST_UnitGetStatValue(*ppItem, 0x48, 0);
                nMaxDurability = STATLIST_GetUnitBaseStat(*ppItem, 0x49, 0);
                STATLIST_SetUnitStat(*ppItem, 0x48, D2_MIN(2 * nDurability, 0xFF), 0);
                STATLIST_SetUnitStat(*ppItem, 0x49, D2_MIN(2 * nMaxDurability, 0xFF), 0);
            }

            if (!sub_00557380_ResetToMagicQuality(pItemDrop, ppItem, &nSeed))
            {
                if (!ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
                {
                    ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
                }
            }
        }
        break;
    default:
        return 0;
    }

    if (ITEMS_GetItemQuality(*ppItem) <= 0)
    {
        return 0;
    }

    if (ITEMS_GetItemQuality(*ppItem) >= 10)
    {
        return 0;
    }

    if (ITEMS_GetItemFormat(*ppItem) >= 100)
    {
        ITEMS_MakeEthereal(*ppItem, pItemDrop);
    }

    switch (ITEMS_GetItemQuality(*ppItem))
    {
    case 1:
    case 2:
    case 3:
        ITEMS_RollDropSockets(pGame, pItemDrop, *ppItem);
        break;
    }

    if (ITEMS_GetItemFormat(*ppItem) >= 100)
    {
        switch (ITEMS_GetItemQuality(*ppItem))
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        case 9:
        {
            const int nAutoPrefix = pItemsTxtRecord->wAutoPrefix;
            if (nAutoPrefix)
            {
                const unsigned short nAutoAffix = sub_005C1940_RollAutoAffix(*ppItem, 0, 1, 0, 1, 0, nAutoPrefix);
                if (nAutoAffix > 0)
                {
                    ITEMS_SetAutoAffix(*ppItem, nAutoAffix);
                    void* pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(nAutoAffix);
                    sub_0065FEC0_ItemApplyProps(0, 0, *ppItem, pMagicAffixTxtRecord, 0, 0);
                }
            }
            break;
        }
        }
    }

    return 1;
}

// 0x00556A60
static int __stdcall ITEMS_AssignCharmAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    unsigned short wPrefix = 0;
    unsigned short wSuffix = 0;
    int nRand = 0;
    if (pItemDrop->nPrefix[0] > 0)
    {
        wPrefix = ITEMS_RollMagicAffixes(pItem, 1, 1, 1, 1, pItemDrop->nPrefix[0]);
        ITEMS_AssignPrefix(pItem, wPrefix, 0);
    }
    else if (pItemDrop->nSuffix[0] <= 0)
    {
        wSuffix = ITEMS_RollMagicAffixes(pItem, 1, 0, 1, 1, pItemDrop->nSuffix[0]);
        ITEMS_AssignPrefix(pItem, wSuffix, 0);
        if (!wSuffix)
        {
            nRand = 1;
        }
    }

    if (pItemDrop->nSuffix[0] > 0)
    {
        wSuffix = ITEMS_RollMagicAffixes(pItem, 1, 1, 1, 0, pItemDrop->nSuffix[0]);
        ITEMS_AssignSuffix(pItem, wSuffix, 0);
    }
    else if (pItemDrop->nPrefix[0] <= 0)
    {
        wPrefix = ITEMS_RollMagicAffixes(pItem, 1, nRand, 1, 0, pItemDrop->nPrefix[0]);
        ITEMS_AssignSuffix(pItem, wPrefix, 0);
    }

    if (!wPrefix && !wSuffix)
    {
        ITEMS_GetBaseCode(pItem);
        D2_ASSERT(0, 0x372);
    }

    ITEMS_SetItemFlag(pItem, 0x10, 0);
    return 1;
}

// 0x00556B60
static void __stdcall ITEMS_RollDropSockets(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    if (ITEMS_GetItemQuality(pItem) < 2)
    {
        return;
    }

    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        return;
    }

    if (!ITEMS_GetMaxSockets(pItem))
    {
        return;
    }

    int nMaxSockets = ITEMS_GetMaxSockets(pItem);
    switch (pGame->nDifficulty)
    {
    case 0:
        if (nMaxSockets >= 3)
        {
            nMaxSockets = 3;
        }
        break;
    case 1:
        if (nMaxSockets >= 4)
        {
            nMaxSockets = 4;
        }
        break;
    case 2:
        if (nMaxSockets >= 6)
        {
            nMaxSockets = 6;
        }
        break;
    }

    if (nMaxSockets <= 0)
    {
        return;
    }

    if (ITEMS_GetItemFormat(pItem) >= 100 || !ITEMSIsA(pItem, 3))
    {
        int nChance = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), 100);
        if (pItemDrop->dwFlags2 & 8)
        {
            return;
        }

        if (pItemDrop->dwFlags2 & 0x10)
        {
            nChance = 0;
        }

        if ((pItemDrop->dwFlags1 & 0x800) || nChance < 33)
        {
            ITEMS_SetItemFlag(pItem, 0x800, 1);
            int nSockets;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                nSockets = ITEMS_GetItemStartSeed(pItem) % nMaxSockets + 1;
            }
            else
            {
                if (nMaxSockets > 3)
                {
                    nMaxSockets = 3;
                }

                if (ITEMSIsA(pItem, 0x25) && nMaxSockets > 2)
                {
                    nMaxSockets = 2;
                }

                nSockets = nMaxSockets;
            }

            ITEMS_AddSockets(pItem, nSockets);
        }
    }
}

// 0x00556D80
static void __stdcall ITEMS_AssignLegacySpecialProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    switch (ITEMS_GetItemType(pItem))
    {
    case 13:
        ITEMS_AssignCharmAffixes(pItemDrop, pItem);
        break;
    case 40:
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        break;
    }
    case 7:
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        ITEMS_SetItemFlag(pItem, 0x10000, 1);
        break;
    }
    case 22:
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 1), 0);
        break;
    case 18:
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 0), 0);
        break;
    default:
        ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
        ITEMS_RollDropSockets(pGame, pItemDrop, pItem);
        break;
    }
}

// 0x00556E80
static void D2GAME_ITEMS_AssignSpecial_6FC4DB60(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMSIsA(pItem, 13))
    {
        ITEMS_AssignCharmAffixes(pItemDrop, pItem);
    }

    if (ITEMSIsA(pItem, 40))
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
    }

    if (ITEMSIsA(pItem, 7))
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        ITEMS_SetItemFlag(pItem, 0x10000, 1);
    }

    if (ITEMSIsA(pItem, 22))
    {
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 1), 0);
    }

    if (ITEMSIsA(pItem, 18))
    {
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 0), 0);
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
}

// 0x00557250
static void ITEMS_ClearAffixesAndFileIndex(D2UnitStrc** ppItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        ITEMS_AssignPrefix(*ppItem, 0, i);
        ITEMS_AssignSuffix(*ppItem, 0, i);
    }

    ITEMS_AssignRarePrefix(*ppItem, 0);
    ITEMS_AssignRareSuffix(*ppItem, 0);
    ITEMS_SetFileIndex(*ppItem, -1);
}

// 0x005572A0
static void __stdcall ITEMS_ResetToNormalQuality(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int nLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, nLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), nLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 2);
    pItemDrop->nQuality = 2;
    ITEMS_AssignSpecialPropertiesForFormat(pGame, *ppItem, pItemDrop);
}

// 0x00557320
static int ITEMS_ResetToSuperiorQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 3);
    pItemDrop->nQuality = 3;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return ITEMS_RollSuperiorItem(*ppItem, pItemDrop);
}

// 0x00557380
static int __stdcall sub_00557380_ResetToMagicQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 4);
    pItemDrop->nQuality = 4;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return ITEMS_AssignDropMagicAffixes(pItemDrop, ppItem);
}

// 0x005573F0
static int sub_005573F0_ResetToRareQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 6);
    pItemDrop->nQuality = 6;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return D2GAME_RollRareItem_6FC53360(*ppItem, pItemDrop);
}

// 0x00556F30
static void __stdcall ITEMS_AssignSpecialPropertiesForFormat(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (!ITEMS_GetItemFormat(pItem))
    {
        ITEMS_AssignLegacySpecialProperties(pGame, pItem, pItemDrop);
    }
    else
    {
        D2GAME_ITEMS_AssignSpecial_6FC4DB60(pItem, pItemDrop);
    }
}

// 0x00556F60
int __stdcall ITEMS_RollItemQuality(D2UnitStrc* pItem, D2ItemDropStrc* pDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1 && pDrop->nQuality)
        return pDrop->nQuality;
    D2GameStrc* ptGame = SUNIT_GetGameFromUnit(pItem);
    D2_ASSERT(ptGame, 0x482);
    const unsigned short nVersion = ITEMS_GetItemFormat(pItem) >= 1 ? 100 : 0;
    D2ItemRatioTxt* pRatio = DATATBLS_GetItemRatioTxtRecord(!pItem ? -1 : pItem->dwClassId, ptGame->nDifficulty, nVersion);
    D2_ASSERT(pRatio, 0x486);
    D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pRecord, 0x489);
    if (pRecord->nQuest)
        return 2;
    int nItemLevel = pDrop->nItemLevel;
    int nChance = 0;
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        if (ITEMSIsA(pItem, 0x34))
            nItemLevel = 1;
        else
        {
            nItemLevel -= pRecord->nLevel;
            if (nItemLevel < 1)
                nItemLevel = 1;
        }
    }
    int nQuality = 1;
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            switch (gnQualityOrder_006E1138[i])
            {
            case 7: nChance = pRatio->dwUnique - nItemLevel / pRatio->dwUniqueDivisor; nQuality = 7; break;
            case 6: nChance = pRatio->dwRare - nItemLevel / pRatio->dwRareDivisor; nQuality = 6; break;
            case 5: nChance = pRatio->dwSet - nItemLevel / pRatio->dwSetDivisor; nQuality = 5; break;
            case 4: nChance = pRatio->dwMagic - nItemLevel / pRatio->dwMagicDivisor; nQuality = 4; break;
            case 3: nChance = pRatio->dwHiQuality - nItemLevel / pRatio->dwHiQualityDivisor; nQuality = 3; break;
            case 2: nChance = pRatio->dwNormal - nItemLevel / pRatio->dwNormalDivisor; nQuality = 2; break;
            }
            if (nChance <= 0 || !ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nChance))
                return nQuality;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            switch (gnQualityOrder_006E1138[i])
            {
            case 7: nChance = pRatio->dwUnique - nItemLevel; nQuality = 7; break;
            case 6: nChance = pRatio->dwRare - nItemLevel; nQuality = 6; break;
            case 5: nChance = pRatio->dwSet - nItemLevel; nQuality = 5; break;
            case 4: nChance = pRatio->dwMagic - nItemLevel / pRatio->dwMagicDivisor; nQuality = 4; break;
            case 3: nChance = pRatio->dwHiQuality - nItemLevel / pRatio->dwHiQualityDivisor; nQuality = 3; break;
            case 2: nChance = pRatio->dwNormal - nItemLevel / pRatio->dwNormalDivisor; nQuality = 2; break;
            }
            if (nChance <= 0)
                nChance = 1;
            if (!ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nChance))
                return nQuality;
        }
    }
    return (((unsigned char)pDrop->dwFlags2 & 0x40) | 0x20) >> 5;
}

#include "gen/data/Source/D2Game/ITEMS/Items.inc"

// 0x00557A70
static void sub_00557A70_RollVarInvGfx(D2UnitStrc* pItem)
{
    if (sub_0062E8D0_HasAltInvGfx(pItem))
    {
        const unsigned char nIndex = sub_00472280(&pItem->pSeed, 0, sub_0062E8D0_HasAltInvGfx(pItem));
        ITEMS_SetVarGfxIndex(pItem, nIndex);
    }
}

void sub_G07_Emit_00557A70(D2UnitStrc** ppItem)
{
    sub_00557A70_RollVarInvGfx(*ppItem);
}

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

// 0x00557F50
static void sub_00557F50_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        if (INVENTORY_UnitIsItem(i) == pItem)
        {
            INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            return;
        }
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem && pCursorItem == pItem)
    {
        INVENTORY_SetCursorItem(pInventory, 0);
    }
}

// 0x00557FA0
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    sub_00557F50_RemoveItemFromInventory(pUnit->pInventory, (D2UnitStrc*)pArg);
}

// 0x00557FC0
static __forceinline void sub_00557FC0_RemoveItemFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
}

void __fastcall sub_M110_Emit_00557FC0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
        sub_00557FC0_RemoveItemFromAllPlayers(pGame, pItem);
}

// 0x00557FD0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pUnit);
    SUNIT_RemoveUnit(pGame, pUnit);
}

static inline int ITEMS_IsUniqueWithFileIndex(D2UnitStrc* pItem, int nFileIndex)
{
    return pItem && pItem->dwUnitType == 4 && ITEMS_GetItemQuality(pItem) == 7 && ITEMS_GetFileIndex(pItem) == nFileIndex;
}

// 0x00558070
D2UnitStrc* __fastcall sub_00558070_FindUniqueItem(D2UnitStrc* pUnit, int nFileIndex)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (ITEMS_IsUniqueWithFileIndex(pCursorItem, nFileIndex))
    {
        return pCursorItem;
    }

    for (D2UnitStrc* pIt = INVENTORY_GetFirstItem(pInventory); pIt; pIt = INVENTORY_GetNextItem(pIt))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pIt);
        if (ITEMS_IsUniqueWithFileIndex(pItem, nFileIndex) && ITEMS_GetInvPage(pItem) != 1)
        {
            return pItem;
        }
    }

    return 0;
}

// 0x00558990
void __cdecl sub_00558990_Nop()
{
}

// 0x00558B40
void __fastcall sub_00558B40_RemoveItemFromGame(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, pItem->dwUnitType, pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    pItem->dwFlags &= ~2u;
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
    SUNIT_RemoveUnit(pGame, pItem);
}

// 0x005585D0
static int sub_005585D0_GetMagicFindBonus(D2UnitStrc* pPlayer)
{
    if (pPlayer && (unsigned int)pPlayer->dwUnitType <= UNIT_MONSTER)
    {
        int nMagicBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, STAT_ITEM_MAGICBONUS, 0);
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nMagicBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_MAGICBONUS, 0);
        }
        return nMagicBonus;
    }
    return 0;
}

int sub_B05_Emit_005585D0(int nBase, int nDiv, D2UnitStrc* pPlayer, int* pOut)
{
    nBase -= nDiv;
    const int nMagicBonus = sub_005585D0_GetMagicFindBonus(pPlayer);
    if (nMagicBonus && nMagicBonus <= -100)
    {
        return 0;
    }
    *pOut = nBase / nDiv;
    return nMagicBonus + 100;
}

static __forceinline D2ItemTypesTxt* sub_C03_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x00558640
static int __stdcall sub_00558640_RollItemQuality(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, int nItemId)
{
    int bMagicFind = 0;
    int nChance;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_C03_GetItemTypesTxtRecord(ITEMS_GetItemTypeFromItemId(nItemId));
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    if (pItemTypesTxtRecord->nNormal)
    {
        return 2;
    }

    if (pItemsTxtRecord->nUnique)
    {
        return 7;
    }

    if (pItemTypesTxtRecord->nMagic && pItemsTxtRecord->nQuest)
    {
        return 7;
    }

    D2ItemRatioTxt* pItemRatioTxtRecord = DATATBLS_GetItemRatioTxtRecord(nItemId, pGame->nDifficulty, 100);
    D2_ASSERT(pItemRatioTxtRecord, 0xE8D);

    const int nLevel = nItemLevel - pItemsTxtRecord->nLevel;
    int nMagicFind = sub_005585D0_GetMagicFindBonus(pPlayer);
    if (nMagicFind)
    {
        if (nMagicFind <= -100)
        {
            goto LABEL_SUPERIOR;
        }

        bMagicFind = 1;
    }

    nMagicFind += 100;

    nChance = (pItemRatioTxtRecord->dwUnique - nLevel / pItemRatioTxtRecord->dwUniqueDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 250, 250);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwUniqueMin)
    {
        nChance = pItemRatioTxtRecord->dwUniqueMin;
    }

    nChance -= nChance * pMods->wUnique / 1024;
    if (nChance <= 0)
    {
        return 7;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 7;
    }

    nChance = (pItemRatioTxtRecord->dwSet - nLevel / pItemRatioTxtRecord->dwSetDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 500, 500);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwSetMin)
    {
        nChance = pItemRatioTxtRecord->dwSetMin;
    }

    nChance -= nChance * pMods->wSet / 1024;
    if (nChance <= 0)
    {
        return 5;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 5;
    }

    if (pItemTypesTxtRecord->nRare)
    {
        nChance = (pItemRatioTxtRecord->dwRare - nLevel / pItemRatioTxtRecord->dwRareDivisor) * 128;
        if (bMagicFind)
        {
            const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 600, 600);
            if (nDiminished)
            {
                nChance = nChance * 100 / nDiminished;
            }
        }

        if (nChance <= pItemRatioTxtRecord->dwRareMin)
        {
            nChance = pItemRatioTxtRecord->dwRareMin;
        }

        nChance -= nChance * pMods->wRare / 1024;
        if (nChance <= 0)
        {
            return 6;
        }

        if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
        {
            return 6;
        }
    }

    if (pItemTypesTxtRecord->nMagic)
    {
        return 4;
    }

    nChance = (pItemRatioTxtRecord->dwMagic - nLevel / pItemRatioTxtRecord->dwMagicDivisor) * 128;
    if (bMagicFind)
    {
        nChance = nChance * 100 / nMagicFind;
    }

    if (nChance <= pItemRatioTxtRecord->dwMagicMin)
    {
        nChance = pItemRatioTxtRecord->dwMagicMin;
    }

    nChance -= nChance * pMods->f_0 / 1024;
    if (nChance <= 0)
    {
        return 4;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 4;
    }

LABEL_SUPERIOR:
    nChance = (pItemRatioTxtRecord->dwHiQuality - nLevel / pItemRatioTxtRecord->dwHiQualityDivisor) * 128;
    if (nChance <= 0)
    {
        return 3;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 3;
    }

    nChance = (pItemRatioTxtRecord->dwNormal - nLevel / pItemRatioTxtRecord->dwNormalDivisor) * 128;
    if (nChance <= 0)
    {
        return 2;
    }

    return ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128 ? 2 : 1;
}

int __stdcall sub_C03_Emit_00558640(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, unsigned short nItemId)
{
    return sub_00558640_RollItemQuality(pGame, pItem, pPlayer, pMods, nItemLevel, nItemId);
}

static int ITEMS_GetItemsTxtRecordCount()
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (!pItemDataTbl)
    {
        return 0;
    }

    return pItemDataTbl->nItemsTxtRecordCount;
}

// 0x00558CB0
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion)
{
    if (!pGame)
    {
        return 0;
    }

    if (pItemSave->nClassId < 0 || pItemSave->nClassId >= ITEMS_GetItemsTxtRecordCount())
    {
        *pSize = 0;
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_AllocUnitData(4, pItemSave->nClassId, pItemSave->nX, pItemSave->nY, pGame, pRoom, 1, pItemSave->bMode, 0);
    if (!pItem)
    {
        return 0;
    }

    int bFail;
    *pSize = ITEMS_DecodeItemFromBitstream(pItem, pBitstream, nBufferSize, bCheckForHeader, 0, dwVersion, &bFail);
    if (!*pSize || bFail)
    {
        SUNIT_RemoveUnit(pGame, pItem);
        return 0;
    }

    ITEMS_SetItemFlag(pItem, 0x80000, 1);
    ITEMS_SetItemFlag(pItem, 0x2000, 0);
    ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
    ITEMS_ScheduleQuantityReplenishment(pGame, pItem);
    return pItem;
}

// 0x0056A370
int __fastcall sub_0056A370_ReadQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + 298;
    if (pSectionEnd > pEnd)
    {
        return 15;
    }

    const D2SaveHeaderStrc* pQuestHeader = (const D2SaveHeaderStrc*)pSection;
    if (pQuestHeader->dwHeaderMagic != 0x216F6F57)
    {
        return 15;
    }

    if (pQuestHeader->dwVersion != 6)
    {
        return 15;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], &pSection[10 + 96 * i], 96, 1);
    }

    *ppSection = pSectionEnd;
    return 0;
}

// 0x0056B6C0
void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit)
{
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 6, 0) > nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, 6, nMaxHp, 0);
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 8, 0) > nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, 8, nMaxMana, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 10, 0) > nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, 10, nMaxStamina, 0);
    }

    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 267);
}

// 0x0056C2D0
int __fastcall sub_0056C2D0_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

static __declspec(noinline) int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
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

// 0x00559130
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

static int s_nGoldItemId_0088C6F8; // 0x0088C6F8

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

    const int nItemId = ITEMMODE_SelectRandomArmorItemId(pGame, pSeed, nItemLevel, a4, a5);
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
        nItemId = ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, nItemLevel, a4, a5);
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
int __fastcall sub_6FC48940(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6)
{
    D2_ASSERT(ptGame, 0x11FB);
    D2_ASSERT(hUnit, 0x11FC);

    *a6 = 0;

    sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1201);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, UNIT_ITEM, nItemGUID);
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

        D2InventoryStrc* pInventory = hUnit->pInventory;
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
            sub_0055C270_OnItemToBelt(hUnit, pItem);

            pItem->dwFlags &= ~UNITFLAG_TARGETABLE;

            if (ITEMS_IsCharmUsable(pItem, hUnit))
            {
                sITEMSAddStatsList(ptGame, pItem, hUnit, 0);
            }

            UNITS_ChangeAnimMode(pItem, IMODE_INBELT);
            ITEMS_SetInvPage(pItem, INVPAGE_NULL);
            ITEMS_SetItemCMDFlag(pItem, 0x400, 1);
            UNITS_RefreshInventory(hUnit, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            return 1;
        }

        *a6 = 1;
    }
    while (0);

    return 0;
}

// 0x00559830
D2UnitStrc* __fastcall sub_6FC4FCA0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel;
    if (nLevelId && !DUNGEON_IsRoomInTown(pRoom))
    {
        nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
        if (nItemLevel > 1)
        {
            nItemLevel -= 1;
        }
    }
    else
    {
        nItemLevel = 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    int bIsMonster = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        bIsMonster = 1;
    }

    const int nItemId = ITEMMODE_SelectRandomMiscItemId(pGame, pSeed, nItemLevel, a4, a5, bIsMonster);

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

        itemDrop.pUnit = pUnit;
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

        return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
    }

    return 0;
}
