struct D2GameStrc;
struct D2InventoryStrc;
struct D2ActiveRoomStrc;

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue);                                 // 0x0053FF00
int __fastcall sub_00540900_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGold);                // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);              // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                               // 0x00552FD0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSound, D2UnitStrc* pSource);                     // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pUnit);                                                       // 0x00554630
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pItem);                          // 0x00557FD0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGold);                       // 0x0055B030
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);        // 0x0055BF50
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                      // 0x0055CC90
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);             // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bRefresh);                                     // 0x00621000
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer);                          // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x006272B0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
unsigned int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                        // 0x0062B400
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);            // 0x0063CC70
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define STAT_GOLD 14
#define IMODE_ONGROUND 3
#define IMODE_ONCURSOR 4
#define ITEMTYPE_GOLD 4
#define UNITFLAG_TARGETABLE 0x00000002
#define UNITFLAG_SENDREFRESHMSG 0x00001000
#define UNITFLAG_ISRESURRECT 0x02000000

static __forceinline void AddGoldToUnit(D2UnitStrc* pUnit, int nGold)
{
    if (pUnit)
    {
        const int nNewGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) + nGold;
        if (nNewGold < 0)
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER && nNewGold > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else
        {
            STATLIST_AddUnitStat(pUnit, STAT_GOLD, nGold, 0);
        }
    }
}

// build: context sub_0055C850_PickupGold
static void __stdcall sub_0055C850_PickupGold(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pGoldPile)
{
    const int nInventoryLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nUnitGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    const int nPileGold = STATLIST_UnitGetStatValue(pGoldPile, STAT_GOLD, 0);
    int nRemainingGold = 0;

    int nPickedGold = nPileGold;
    if (nPileGold + nUnitGold > nInventoryLimit)
    {
        nPickedGold = nInventoryLimit - nUnitGold;
        nRemainingGold = nPileGold - nPickedGold;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pGoldPile);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        PLRTRADE_AddGold(pUnit, STAT_GOLD, nPickedGold);
    }
    else if (SUNIT_GetPartyId(pUnit) != -1)
    {
        nRemainingGold = sub_00540900_ShareGoldDrop(pGame, pUnit, nPileGold);
    }
    else
    {
        AddGoldToUnit(pUnit, nPickedGold);
    }

    int nUnitGUID = -1;
    int nUnitType = 6;
    if (pGoldPile)
    {
        nUnitGUID = pGoldPile->dwUnitId;
        nUnitType = pGoldPile->dwUnitType;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pGoldPile), nUnitType, nUnitGUID);
    UNITS_FreeCollisionPath(pGoldPile);
    UNITROOM_RemoveUnitFromRoom(pGoldPile);

    if (pGoldPile)
    {
        pGoldPile->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pGoldPile);

    if (nRemainingGold > 0)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nRemainingGold);
        SUNIT_AttachSound(pUnit, 0x17, pUnit);
    }
}

// build: context sub_0055C9A0_DropBackToGround
static void __stdcall sub_0055C9A0_DropBackToGround(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nSound)
{
    int nUnitGUID = -1;
    int nUnitType = 6;
    if (pItem)
    {
        nUnitGUID = pItem->dwUnitId;
        nUnitType = pItem->dwUnitType;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), nUnitType, nUnitGUID);
    ITEMS_SetInvPage(pItem, 0xFF);

    if (pItem)
    {
        pItem->dwFlags |= UNITFLAG_SENDREFRESHMSG;
    }

    UNITS_ChangeAnimMode(pItem, IMODE_ONGROUND);
    SUNIT_AttachSound(pUnit, nSound, pUnit);
}

// 0x0055CF50
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 1368);
    D2_ASSERT(pUnit, 1369);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 1374);

    if (INVENTORY_GetCursorItem(pInventory) || PLAYER_IsBusy(pUnit))
    {
        return;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 1390);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    if (pItem->dwAnimMode != IMODE_ONGROUND)
    {
        *pItemStatus = 1;
        return;
    }

    if (!sub_6FC425F0(pGame, pUnit, pItem))
    {
        sub_0055C9A0_DropBackToGround(pUnit, pItem, 0x13);
        return;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        sub_0055C850_PickupGold(pGame, pUnit, pItem);
    }
    else
    {
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
        pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
        INVENTORY_SetCursorItem(pInventory, pItem);
        UNITS_ChangeAnimMode(pItem, IMODE_ONCURSOR);
        ITEMS_SetItemCMDFlag(pItem, 64, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        UNITS_RefreshInventory(pUnit, 1);
        pItem->dwFlags &= ~UNITFLAG_ISRESURRECT;
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        QUESTS_ItemPickedUp(pGame, pUnit, pItem);
    }

    SUNIT_AttachSound(pUnit, 1, pUnit);
}
