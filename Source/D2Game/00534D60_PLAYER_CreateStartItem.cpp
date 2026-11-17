extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StatListStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2ItemsTxt;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2GameStrc;

struct D2CharStatsTxt
{
    char unk0x00[0xAC];
    short wStartSkill;
};

struct D2CharItemStrc
{
    unsigned int dwItemCode;
    unsigned char nBodyLoc;
    unsigned char nItemCount;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
};

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define INVPAGE_INVENTORY 0
#define ITEMQUAL_NORMAL 2
#define IFLAG_STARTITEM 0x20000
#define ITEMTYPE_BOW_QUIVER 5
#define STAT_QUANTITY 70
#define STAT_DURABILITY 72
#define STAT_ITEM_SINGLESKILL 107

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall sub_6FC45060(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2);                                     // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
int __fastcall sub_6FC48940(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6); // 0x0055E9B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

inline int M08_UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// 0x00534B30
static int __stdcall PLAYER_PlaceItemInInventory(D2GameStrc* pGame, int a8, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pItem, 180);
    D2_ASSERT(pPlayer, 181);
    ITEMS_SetInvPage(pItem, INVPAGE_INVENTORY);
    const int nItemGUID = pItem->dwUnitId;
    return D2GAME_PlaceItem_6FC44410(".\\PLAYER\\Player.cpp", 186, pGame, pPlayer, nItemGUID, UNITS_GetXPosition(pItem), CLIENTS_GetUnitY(pItem), a8, 1, 0) != 0;
}

// 0x00534BB0
static int __stdcall sub_00534BB0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pItem, 198);
    D2_ASSERT(pPlayer, 199);
    const int nItemGUID = pItem->dwUnitId;
    int nUnused;
    return sub_6FC45060(pGame, pPlayer, nItemGUID, ITEMS_GetBodyLocation(pItem), 1, &nUnused) != 0;
}

static __forceinline int __stdcall sub_M08_PlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int bFindFreeSlot)
{
    D2_ASSERT(pItem, 216);
    D2_ASSERT(pPlayer, 217);
    int nUnused;
    const int nX = M08_UNITS_GetXPositionInline(pItem);
    const int nItemGUID = pItem->dwUnitId;
    return sub_6FC48940(pGame, pPlayer, nItemGUID, nX, bFindFreeSlot, &nUnused) != 0;
}

static D2UnitStrc* __stdcall sub_00534C70(D2GameStrc* pGame, int nCount, int nItemId, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt)
{
    if (!pPlayer)
    {
        return 0;
    }
    const int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pPlayer, nItemId, pGame, 4, ITEMQUAL_NORMAL, 1, 1, nItemLevel, 0, 0, 0);
    if (pItem)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (pStatList)
        {
            D2Common_10474(pItem, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
        if (!nCount && pCharStatsTxt->wStartSkill >= 0 && pCharStatsTxt->wStartSkill < sgptDataTables->nSkillsTxtRecordCount)
        {
            D2StatListStrc* pStartItemStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
            if (!pStartItemStatList)
            {
                pStartItemStatList = STATLIST_AllocStatList(pItem->pMemoryPool, 0x40, 0, UNIT_ITEM, pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStartItemStatList, 1);
            }
            STATLIST_SetStatIfListIsValid(pStartItemStatList, STAT_ITEM_SINGLESKILL, 1, pCharStatsTxt->wStartSkill);
        }
        if (ITEMS_CheckIfStackable(pItem))
        {
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pItem), 0);
        }
    }
    return pItem;
}

// 0x00534D60
void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem)
{
    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(pCharItem->dwItemCode, &nItemId))
    {
        return;
    }
    for (int i = 0; i < pCharItem->nItemCount; ++i)
    {
        D2UnitStrc* pItem = sub_00534C70(pGame, nCount, nItemId, pPlayer, pCharStatsTxt);
        ITEMS_SetItemFlag(pItem, IFLAG_STARTITEM, 1);
        ITEMS_SetBodyLocation(pItem, pCharItem->nBodyLoc);
        if (ITEMS_CheckIfBeltable(pItem))
        {
            if (!sub_M08_PlaceStartItemInBelt(pGame, pPlayer, pItem, 1))
            {
                PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            }
        }
        else if (pCharItem->nBodyLoc)
        {
            if (!sub_00534BB0(pGame, pItem, pPlayer))
            {
                PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            }
            if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 250, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
            }
        }
        else
        {
            PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 250, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
            }
            if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 100, 0);
            }
        }
    }
}
