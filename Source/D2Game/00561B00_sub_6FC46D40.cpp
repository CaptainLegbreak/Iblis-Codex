struct D2InventoryStrc;
struct D2ItemsTxt;

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

int dword_0088C6FC;                                                                                         // 0x0088C6FC
bool byte_0088C700;                                                                                         // 0x0088C700

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc* pUnit, D2UnitStrc* pItem);
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine);
void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);         // 0x00568770
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);              // 0x00621050
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
extern "C" char __stdcall sub_00628250(D2UnitStrc* pUnit);                                                // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, unsigned char nPage);                                // 0x006282D0
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
int __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCC0
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70

// 0x00561B00
int __fastcall sub_6FC46D40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nGridItemGUID, int nX, int nY, int* pItemStatus)
{
    D2_ASSERT(pGame, 0xEC0);
    D2_ASSERT(pUnit, 0xEC1);

    *pItemStatus = 0;

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xEC6);

    D2UnitStrc* pCursorItem = SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
    if (!pCursorItem || pCursorItem->dwUnitType != 4 || pCursorItem->dwAnimMode != 4)
    {
        return 0;
    }

    D2UnitStrc* pGridItem = SUNIT_GetServerUnit(pGame, 4, nGridItemGUID);
    if (!pGridItem || pGridItem->dwUnitType != 4)
    {
        return 0;
    }

    const char nInvPage = sub_00628250(pGridItem);
    if (nInvPage == 3)
    {
        if (!byte_0088C700)
        {
            if (!DATATBLS_GetItemRecordFromItemCode(0x20786F62, &dword_0088C6FC))
            {
                return 0;
            }

            byte_0088C700 = 1;
        }

        const int nClassId = (pCursorItem ? pCursorItem->dwClassId : -1);
        if (nClassId == dword_0088C6FC)
        {
            return 0;
        }
    }
    else if (nInvPage == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pGridItem->dwAnimMode != 0)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pGridItem);
    D2_ASSERT(pRemove, 0xF12);
    D2_ASSERT(pGridItem == pRemove, 0xF13);

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pGridItem, pUnit, 0, 1);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0xF15, pInventory, CLIENTS_GetUnitX(pGridItem), CLIENTS_GetUnitY(pGridItem), UNITS_GetInventoryRecordId(pUnit, nInvPage, pGame->bExpansion), 0, nInvPage);

    ITEMS_SetInvPage(pGridItem, 0xFF);
    INVENTORY_SetCursorItem(pInventory, pGridItem);
    sub_0055C6E0_OnItemToCursor(pUnit, pGridItem);
    ITEMS_SetCellOverlap(pGridItem, nInvPage);
    pGridItem->dwFlags &= ~2u;
    UNITS_ChangeAnimMode(pGridItem, 4);
    ITEMS_SetItemCMDFlag(pGridItem, 0x40000, 1);

    if (sub_0055F590_CheckItem(pGridItem, ".\\ITEMS\\ItemMode.cpp", 0xF1F))
    {
        ITEMS_SetItemFlag(pGridItem, 1, 1);
    }

    if (sub_006280A0(pGridItem, 0x4000, 0xF22, (unsigned int)".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(pGridItem, 0x4000, 0);
    }

    INVENTORY_AddItemToTradeInventory(pInventory, pGridItem);

    if (INVENTORY_PlaceItemAtInventoryPage(pInventory, pCursorItem, nX, nY, UNITS_GetInventoryRecordId(pUnit, nInvPage, pGame->bExpansion), 0, nInvPage))
    {
        ITEMS_SetCellOverlap(pCursorItem, 0);
        ITEMS_SetInvPage(pCursorItem, nInvPage);
        UNITS_SetXForStaticUnit(pCursorItem, nX);
        UNITS_SetYForStaticUnit(pCursorItem, nY);

        if (INVENTORY_PlaceItemInSocket(pInventory, pCursorItem, 1))
        {
            pCursorItem->dwFlags &= ~2u;
            sub_0055C270_OnItemToBelt(pUnit, pCursorItem);

            if (ITEMS_IsCharmUsable(pCursorItem, pUnit))
            {
                D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pCursorItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pCursorItem, 0);

            if (sub_0055F590_CheckItem(pCursorItem, ".\\ITEMS\\ItemMode.cpp", 0xF48))
            {
                ITEMS_SetItemFlag(pCursorItem, 1, 1);
            }

            if (sub_006280A0(pCursorItem, 0x4000, 0xF4B, (unsigned int)".\\ITEMS\\ItemMode.cpp"))
            {
                ITEMS_SetItemFlag(pCursorItem, 0x4000, 0);
            }

            ITEMS_SetItemCMDFlag(pCursorItem, 0x40000, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pCursorItem);

            if (nInvPage == 2)
            {
                PLRTRADE_AddItemToTrade(pGame, pUnit, pCursorItem);
            }

            UNITS_RefreshInventory(pUnit, 1);

            if (ITEMS_IsCharmUsable(pGridItem, pUnit))
            {
                sub_0055DBC0(pGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        *pItemStatus = 1;
        return 0;
    }

    *pItemStatus = 1;
    return 0;
}
