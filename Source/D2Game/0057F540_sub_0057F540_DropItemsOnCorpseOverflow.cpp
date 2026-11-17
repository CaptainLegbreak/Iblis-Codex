extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;

struct D2ClientStrc;

struct D2InventoryStrc;

struct D2CorpseStrc;

struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[4];
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

int __stdcall sub_0062A360(D2UnitStrc* pUnit, D2UnitStrc* pItem);                                           // 0x0062A360
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
void __fastcall sub_6FC45930(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                      // 0x005608C0
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __fastcall sub_0055D930(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused);                            // 0x0055D930
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit);           // 0x0053D2E0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, unsigned int nValue);      // 0x00535510
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory);                             // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse);                                    // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse);                                       // 0x0063D630
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, int nUnitId, int bFree);                   // 0x0063D4E0

// build: symbol ?sub_6FC802F0@@YGXPAUD2GameStrc@@HPAUD2UnitStrc@@1@Z 0x0057F410
static void __stdcall sub_6FC802F0(D2GameStrc* pGame, int nBodyloc, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    const int bUpdateSets = sub_0062A360(pUnit, pItem);
    sub_0063D2B0_DetachItem(pInventory, pItem);
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);

    D2_ASSERT(pRemove, 0x25D);
    D2_ASSERT(pItem == pRemove, 0x25E);

    sub_0063BE30(pInventory, nBodyloc);

    if (ITEMS_GetItemType(pItem) == 0x13)
    {
        sub_6FC45930(pGame, pUnit, 0);
    }

    if (pItem)
    {
        pItem->dwFlags &= ~0x02;
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);
    ITEMS_SetItemFlag(pItem, 0x20, 1);
    ITEMS_SetItemCMDFlag(pItem, 1, 1);
    ITEMS_SetItemCMDFlag(pItem, 0x10, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);

    if (bUpdateSets)
    {
        sub_0055D930(pUnit, pItem, 0);
    }

    ITEMS_UpdateSets(pUnit, pItem, 1, 1);
    UNITS_RefreshInventory(pUnit, 1);
}

static void sub_6FC803F0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrModes.cpp", 0x27D);
    D2GAME_PACKETS_SendPacket0x42_6FC3EE40(pClient, pPlayer);
    INVENTORY_SetCursorItem(pInventory, 0);
    ITEMS_SetItemCMDFlag(pItem, 1, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pPlayer, 1);
}

// 0x0057F540
static void __stdcall sub_0057F540_DropItemsOnCorpseOverflow(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    for (int nBodyLoc = -1; nBodyLoc < 0x0D; ++nBodyLoc)
    {
        D2UnitStrc* pItem = 0;
        if (nBodyLoc == -1)
        {
            pItem = INVENTORY_GetCursorItem(pInventory);
        }
        else
        {
            pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        }

        if (pItem)
        {
            if (nBodyLoc == -1)
            {
                sub_6FC803F0(pGame, pItem, pUnit);
            }
            else
            {
                D2_ASSERT(pItem->dwAnimMode == 1, 0x2A8);
                sub_6FC802F0(pGame, nBodyLoc, pItem, pUnit);
            }

            D2UnitStrc* pDupedItem = ITEMS_Duplicate(pGame, pItem, pUnit, 1);
            D2CoordStrc tCoord;
            UNITS_GetCoords(pUnit, &tCoord);
            D2CoordStrc tReturnCoords;
            D2ActiveRoomStrc* pFreeRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &tCoord, &tReturnCoords, 1, 1);
            D2GAME_DropItem_6FC52260(pGame, pUnit, pDupedItem, pFreeRoom, tReturnCoords.nX, tReturnCoords.nY);
        }
    }

    const int nGold = STATLIST_UnitGetStatValue(pUnit, 0x0E, 0);
    if (pUnit->dwUnitType == 0)
    {
        UNITS_GetInventoryGoldLimit(pUnit);
    }
    STATLIST_SetUnitStat(pUnit, 0x0E, 0, 0);
    const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
    sub_6FC7C260(pGame, pUnit, nUnitId, nGold);
}

// calling-convention shim (not game code)
int __fastcall sub_M380_Emit_0057F700(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nBodyLoc, int nExtra)
{
    sub_0057F540_DropItemsOnCorpseOverflow(pGame, pUnit);
    sub_6FC803F0(pGame, pItem, pUnit);
    sub_6FC802F0(pGame, nBodyLoc, pItem, pUnit);
    return nExtra + 0x35;
}
