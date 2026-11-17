struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x60 - 0x14];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC4 - 0x60 - 4];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2BooksTxt
{
    char unk0x00[0x08];
    int dwScrollSkillId;
    int dwBookSkillId;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                             // 0x00535060
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity);
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, int a3, int nStatId, int nValue, int a6);
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue);
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGold);
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);              // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);              // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAmount);
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus);
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);               // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                      // 0x00621000
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                   // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                            // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                 // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                     // 0x00628280
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                          // 0x0062B400
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem);
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                   // 0x0062FF70
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);        // 0x0063B210
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int bUnused, unsigned char nPage, const char* szFile, int nLine);
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                      // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                  // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem);
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem);
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused);
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);            // 0x0063CC70
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity);
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                               // 0x0064C370
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                     // 0x0055CC90
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4);                 // 0x0055D710
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x00562E00
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                    // 0x00628BA0
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem);            // 0x0063C790
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60

static void __stdcall sub_0055C850_PickupGold(D2GameStrc* pGame, D2UnitStrc* pGoldPile, D2UnitStrc* pUnit)
{
    const int nInventoryLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nUnitGold = STATLIST_UnitGetStatValue(pUnit, 0xE, 0);
    const int nPileGold = STATLIST_UnitGetStatValue(pGoldPile, 0xE, 0);
    int nRemainingGold = 0;
    int nPickedGold = nPileGold;
    if (nPileGold + nUnitGold > nInventoryLimit)
    {
        nPickedGold = nInventoryLimit - nUnitGold;
        nRemainingGold = nPileGold - nPickedGold;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pGoldPile);
    if (pOwner && pOwner->dwUnitType == 0)
    {
        PLRTRADE_AddGold(pUnit, 0xE, nPickedGold);
    }
    else if (SUNIT_GetPartyId(pUnit) != -1)
    {
        nRemainingGold = PARTY_ShareGoldDrop(pGame, pUnit, nPileGold);
    }
    else if (pUnit)
    {
        const int nNewGold = STATLIST_UnitGetStatValue(pUnit, 0xE, 0) + nPickedGold;
        if (nNewGold < 0)
        {
            STATLIST_SetUnitStat(pUnit, 0xE, 0, 0);
        }
        else if (pUnit->dwUnitType == 0 && nNewGold > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, 0xE, 0, 0);
        }
        else
        {
            STATLIST_AddUnitStat(pUnit, 0xE, nPickedGold, 0);
        }
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pGoldPile), !pGoldPile ? 6 : pGoldPile->dwUnitType, !pGoldPile ? -1 : pGoldPile->dwUnitId);
    UNITS_FreeCollisionPath(pGoldPile);
    UNITROOM_RemoveUnitFromRoom(pGoldPile);
    if (pGoldPile)
    {
        pGoldPile->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pGoldPile);

    if (nRemainingGold > 0)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nRemainingGold);
        SUNIT_AttachSound(pUnit, 0x17, pUnit);
    }
}

static void __stdcall sub_0055C9A0_DropBackToGround(int nSoundId, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
    ITEMS_SetInvPage(pItem, 0xFF);
    if (pItem)
    {
        pItem->dwFlags |= 0x1000;
    }

    UNITS_ChangeAnimMode(pItem, 3);
    SUNIT_AttachSound(pUnit, nSoundId, pUnit);
}

static int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x1EC);

    if (ITEMS_CheckItemTypeId(pItem, 0x16) || ITEMS_CheckItemTypeId(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        if (pBooksTxtRecord)
        {
            if (ITEMS_CheckItemTypeId(pItem, 0x16))
            {
                return pBooksTxtRecord->dwScrollSkillId;
            }

            if (ITEMS_CheckItemTypeId(pItem, 0x12))
            {
                return pBooksTxtRecord->dwBookSkillId;
            }
        }
    }

    return -1;
}

static void __stdcall sub_0055C070_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x202);
    D2_ASSERT(pItem, 0x203);

    const int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId == -1)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        const int nQuantity = SKILLS_GetQuantity(pSkill) + nQuantityBonus;
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitType = pUnit->dwUnitType;
        const int nUnitGUID = pUnit->dwUnitId;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x20B), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
}

static int __stdcall sub_0055D0D0_AutoStackPickup(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pStackItem = 0;
    int nCounter = 0;

    while (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0)
    {
        ++nCounter;

        if (ITEMS_GetAutoStack(pItem))
        {
            if (ITEMS_GetQuiverType(pItem))
            {
                pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
                if (!pStackItem)
                {
                    pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
                }
            }
            else
            {
                pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
            }
        }

        if (!pStackItem)
        {
            return 0;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity1 = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            const int nQuantity2 = STATLIST_UnitGetStatValue(pStackItem, 0x46, 0);
            if (nQuantity1 + nQuantity2 > ITEMS_GetTotalMaxStack(pStackItem))
            {
                const int nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
                D2_ASSERT(nMaxStack >= 0, 0x5C7);

                STATLIST_SetUnitStat(pStackItem, 0x46, nMaxStack, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5CA), pStackItem, 1, 0x46, nMaxStack, 0);

                const int nRest = nQuantity2 - nMaxStack + nQuantity1;
                D2_ASSERT(nRest >= 0, 0x5CC);

                STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);

                if (ITEMS_GetItemType(pItem) == 0x12 && ITEMS_GetItemType(pStackItem) == 0x12)
                {
                    sub_0055C070_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pStackItem) - nQuantity2, pUnit, pStackItem);
                }
            }
            else
            {
                const int nQuantity = nQuantity2 + nQuantity1;
                D2_ASSERT(nQuantity >= 0, 0x5D7);

                if (ITEMS_HasDurability(pItem))
                {
                    const int nDurability = STATLIST_UnitGetStatValue(pItem, 0x48, 0);
                    if (nDurability < STATLIST_UnitGetStatValue(pStackItem, 0x48, 0))
                    {
                        STATLIST_SetUnitStat(pStackItem, 0x48, nDurability, 0);
                        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5E4), pStackItem, 1, 0x48, nDurability, 0);
                    }
                }

                STATLIST_SetUnitStat(pStackItem, 0x46, nQuantity, 0);
                STATLIST_SetUnitStat(pItem, 0x46, 0, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5ED), pStackItem, 1, 0x46, nQuantity, 0);

                if (ITEMS_GetItemType(pItem) == 0x12 && ITEMS_GetItemType(pStackItem) == 0x12)
                {
                    sub_0055C070_AddBookScrollSkillQuantity(nQuantity1, pUnit, pStackItem);
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                if (pRoom)
                {
                    DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (pItem)
                {
                    pItem->dwFlags &= ~2;
                }

                ITEMS_RemoveFromAllPlayers(pGame, pItem);
                INVENTORY_SetCursorItem(pInventory, 0);
                return 1;
            }
        }
    }

    if (nCounter)
    {
        D2_ASSERT(0, 0x606);
    }

    return 0;
}

int __stdcall sub_0055D370_TryMergeBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x622);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pInventory, pItem, 0);
    if (!pBook)
    {
        return 0;
    }

    const int nSrcValue = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
    D2_ASSERT(nSrcValue >= 0, 0x62E);

    const int nDstValue = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
    D2_ASSERT(nDstValue >= 0, 0x630);

    const int nDstMaxValue = ITEMS_GetTotalMaxStack(pBook);
    D2_ASSERT(nDstMaxValue >= 0, 0x632);

    const int nQuantity = nDstValue + nSrcValue;
    if (nQuantity > nDstMaxValue)
    {
        STATLIST_SetUnitStat(pBook, 0x46, nDstMaxValue, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x638), pBook, 1, 0x46, nDstMaxValue, 0);

        const int nRest = nDstValue - nDstMaxValue + nSrcValue;
        D2_ASSERT(nRest >= 0, 0x63A);

        STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x63D), pItem, 1, 0x46, nRest, 0);
        sub_0055C070_AddBookScrollSkillQuantity(nDstMaxValue - nDstValue, pUnit, pBook);
        return 1;
    }

    D2_ASSERT(nQuantity >= 0, 0x645);

    STATLIST_SetUnitStat(pBook, 0x46, nQuantity, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x648), pBook, 1, 0x46, nQuantity, 0);
    sub_0055C070_AddBookScrollSkillQuantity(nSrcValue, pUnit, pBook);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    if (pItem)
    {
        pItem->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pItem);
    INVENTORY_SetCursorItem(pInventory, 0);
    return 1;
}

static int sub_0055FFA0_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScroll)
{
    D2_ASSERT(pGame, 0x610);

    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pUnit->pInventory, pScroll, 0);
    if (pBook)
    {
        int nItemStatus;
        const int nBookGUID = pBook->dwUnitId;
        return ITEMMODE_AddScrollToBook(pGame, pUnit, !pScroll ? -1 : pScroll->dwUnitId, nBookGUID, &nItemStatus);
    }

    return 0;
}

static int sub_00560020_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x65F);

    if (ITEMS_CheckItemTypeId(pItem, 0x16))
    {
        return sub_0055FFA0_AddScrollToBook(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x12))
    {
        return sub_0055D370_TryMergeBookQuantity(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckIfStackable(pItem) && ITEMS_GetAutoStack(pItem))
    {
        return sub_0055D0D0_AutoStackPickup(pGame, pUnit, pItem);
    }

    return 0;
}

static int __stdcall sub_005600A0_PlaceItemInInventory(D2GameStrc* pGame, int bRemove, int nPage, const char* szFile, int nLine, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x746);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x749);

    if (INVENTORY_PlaceItemAtFreePosition(pInventory, pItem, UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion), 0, 0, szFile, nLine))
    {
        if (bRemove)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
            if (pRoom)
            {
                const int nUnitGUID = !pItem ? -1 : pItem->dwUnitId;
                const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
                DUNGEON_AllocDrlgDelete(pRoom, nUnitType, nUnitGUID);
                UNITS_FreeCollisionPath(pItem);
                UNITROOM_RemoveUnitFromRoom(pItem);
            }
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
        {
            INVENTORY_SetCursorItem(pInventory, 0);
            sub_0055C270_OnItemToBelt(pUnit, pItem);

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 0);
            }

            if (pItem)
            {
                pItem->dwFlags &= ~2u;
            }

            UNITS_ChangeAnimMode(pItem, 0);
            ITEMS_SetItemCMDFlag(pItem, 0x80, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pUnit, 1);

            if (pItem)
            {
                pItem->dwFlags &= ~0x02000000u;
            }

            ITEMS_SetInvPage(pItem, nPage);
            QUESTS_ItemPickedUp(pGame, pUnit, pItem);

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                sub_0055DBC0(pGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        D2_ASSERT(0, 0x76F);
    }

    return 0;
}

// 0x00563560
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x77A);
    D2_ASSERT(pUnit, 0x77B);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x780);

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType == 4)
    {
        if (pItem->dwAnimMode != 3)
        {
            *pItemStatus = 1;
            return 0;
        }

        sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x7A2);

        if (!sub_6FC425F0(pGame, pUnit, pItem))
        {
            sub_0055C9A0_DropBackToGround(0x13, pItem, pUnit);
            return 0;
        }

        SUNIT_AttachSound(pUnit, 1, pUnit);

        if (ITEMS_GetItemType(pItem) == 4)
        {
            sub_0055C850_PickupGold(pGame, pItem, pUnit);
            return 1;
        }

        if (!sub_00560020_PickupStackable(pGame, pUnit, pItem))
        {

            if (sub_6FC42F20(pUnit, pItem, &nItemGUID, 0))
            {
                if (D2Common_10299(pUnit, nItemGUID, pItem, 0) != 1)
                {
                    *pItemStatus = 1;
                    return 0;
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                if (pRoom)
                {
                    DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (ITEMMODE_EquipItemAtResolvedBodyLocation(pGame, pUnit, pItem, 0))
                {
                    QUESTS_ItemPickedUp(pGame, pUnit, pItem);
                    return 1;
                }
            }
            else if (ITEMS_CheckIfBeltable(pItem) && ITEMS_CheckIfAutoBeltable(pInventory, pItem) && INVENTORY_PlaceItemInFreeBeltSlot(pInventory, pItem))
            {
                if (UNITS_GetRoom(pItem))
                {
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
                {
                    INVENTORY_SetCursorItem(pInventory, 0);
                    sub_0055C270_OnItemToBelt(pUnit, pItem);

                    if (ITEMS_IsCharmUsable(pItem, pUnit))
                    {
                        D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 0);
                    }

                    pItem->dwFlags &= ~2u;
                    UNITS_ChangeAnimMode(pItem, 2);
                    ITEMS_SetInvPage(pItem, 0xFF);
                    ITEMS_SetItemCMDFlag(pItem, 0x2000, 1);
                    pItem->dwFlags &= ~0x02000000u;
                    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                    UNITS_RefreshInventory(pUnit, 1);

                    if (ITEMS_IsCharmUsable(pItem, pUnit))
                    {
                        sub_0055DBC0(pGame, pUnit, 0);
                        UNITS_RefreshInventory(pUnit, 1);
                    }

                    return 1;
                }

                D2_ASSERT(0, 0x7ED);
            }
            else
            {
                if (sub_005600A0_PlaceItemInInventory(pGame, 1, 0, ".\\ITEMS\\ItemMode.cpp", 0x7EF, pUnit, pItem))
                {
                    return 1;
                }

                sub_0055C9A0_DropBackToGround(0x17, pItem, pUnit);
            }
        }
    }

    return 0;
}
