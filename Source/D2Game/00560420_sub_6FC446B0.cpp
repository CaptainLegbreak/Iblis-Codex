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
    char unk0x00[0x70];
    int bExpansion;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc* pUnit, D2UnitStrc* pItem);
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine);
void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);    // 0x00567400
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);              // 0x00621050
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
extern "C" char __stdcall sub_00628250(D2UnitStrc* pUnit);                                                // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell);                               // 0x00628320
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define IMODE_STORED 0
#define IMODE_ONCURSOR 4
#define INVPAGE_EQUIP 1
#define INVPAGE_TRADE 2
#define INVPAGE_NULL 0xFF
#define UNITFLAG_TARGETABLE 0x2
#define IFLAG_NEWITEM 0x1
#define IFLAG_QUANTITY 0x20
#define IFLAG_NOEQUIP 0x4000

// 0x00560420
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus, int nUpdateMode, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int bAllowOccupiedCursor)
{
    D2_ASSERT(pGame, 0x906);
    D2_ASSERT(pUnit, 0x907);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventoryArg)
    {
        pInventory = pInventoryArg;
    }

    D2_ASSERT(pInventory, 0x910);

    if (INVENTORY_GetCursorItem(pInventory) && !bAllowOccupiedCursor)
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER && !PLAYER_IsBusy(pUnit) && sub_00628250(pItem))
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_STORED)
    {
        *pItemStatus = 1;
        return 0;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x936);

    pItem->dwFlags &= ~UNITFLAG_TARGETABLE;

    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemove, 0x947);
    D2_ASSERT(pItem == pRemove, 0x948);

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);

    if (ITEMS_IsCharmUsable(pItem, pUnit))
    {
        sub_0055DBC0(pGame, pUnit, 0);
        UNITS_RefreshInventory(pUnit, 1);
    }

    sub_0055C6E0_OnItemToCursor(pUnit, pItem);

    const unsigned char nInvPage = sub_00628250(pItem);
    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nInvPage, pGame->bExpansion);

    int bTrade = 0;
    int bEquip = 1;

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nInvPage)
        {
        case INVPAGE_EQUIP:
            bEquip = 0;
            break;
        case INVPAGE_TRADE:
            bTrade = 1;
            break;
        }
    }
    else
    {
        bEquip = 0;
    }

    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0x965, pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nInventoryRecordId, 0, nInvPage);

    ITEMS_SetItemCell(pItem, nInvPage);
    ITEMS_SetInvPage(pItem, INVPAGE_NULL);

    if (bEquip)
    {
        INVENTORY_SetCursorItem(pInventory, pItem);
    }

    UNITS_ChangeAnimMode(pItem, IMODE_ONCURSOR);

    if (nUpdateMode == 1)
    {
        if (bSetQuantityFlag)
        {
            ITEMS_SetItemFlag(pItem, IFLAG_QUANTITY, 1);
        }

        if (bTrade == 1)
        {
            PLRTRADE_RemoveItemFromTrade(pGame, pUnit, pItem);
        }

        ITEMS_SetItemCMDFlag(pItem, 4, 1);

        if (sub_0055F590_CheckItem(pItem, ".\\ITEMS\\ItemMode.cpp", 0x975))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);
        }

        if (sub_006280A0(pItem, IFLAG_NOEQUIP, 0x978, (unsigned int)".\\ITEMS\\ItemMode.cpp"))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NOEQUIP, 0);
        }

        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    return 1;
}
