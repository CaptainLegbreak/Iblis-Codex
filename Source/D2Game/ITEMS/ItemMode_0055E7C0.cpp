struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
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
    char unk0x14[0x20 - 0x14];
    int pSeed[2];
    unsigned int dwInitSeed;
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x60 - 0x2C - 4];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC4 - 0x60 - 4];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
    char f_74[0x78 - 0x70 - 4];
    unsigned short wItemFormat;
    char unk0x7A[0xA8 - 0x78 - 2];
    unsigned int dwGameFrame;
};

struct D2BooksTxt
{
    char unk0x00[0x08];
    int dwScrollSkillId;
    int dwBookSkillId;
};

struct D2SkillsTxt
{
    char unk0x00[0x14];
    unsigned char nRange;
    char unk0x15[0x18 - 0x14 - 1];
    short nITypeA[3];
};

struct D2EquipmentRefreshStateStrc
{
    int nHitpoints;
    int nMana;
    int nStamina;
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillOwnerGUID;
    int nLeftSkillOwnerGUID;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    int* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    int unk0x24;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int unk0x2C;
    int nQuality;
    char unk0x34[0x40 - 0x34];
    int dwFlags1;
    int unk0x44;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    char unk0x50[0x84 - 0x50];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, int a3, int nStatId, int nValue, int a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue);                                 // 0x0053FF00
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGold);                      // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);             // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAmount);                      // 0x0055B030
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);         // 0x0055BF50
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
int __fastcall ITEMMODE_CanPickUpItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);             // 0x0055CC90
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);   // 0x0055DBC0
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId);                                               // 0x00570080
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit);                                                     // 0x00622EA0
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit);                                                      // 0x00622F10
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID);                  // 0x00623060
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID);                   // 0x006230C0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0
int __stdcall ITEMS_CheckType(int nItemType, int nItemTypeToCheck);                                         // 0x00629B50
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                               // 0x006374B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __stdcall sub_0063D1D0_InventoryItemCall(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);                                                      // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity);                                      // 0x00645120
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                   // 0x00647960
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                       // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem);                         // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                 // 0x00627910
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem);                                                        // 0x006281E0
unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem);                                           // 0x00627DF0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2UnitStrc* __fastcall sub_00558D90_SpawnItem(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);        // 0x00558D90
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit);           // 0x0053D2E0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0

static __forceinline int sub_E03_ItemGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int sub_E03_ItemGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem) // 0x0055BFF0
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

static void __stdcall sub_0055C070_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem) // 0x0055C070
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

static __declspec(noinline) void __stdcall sub_0055E590_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2);

// 0x0055E590
static void __stdcall sub_0055E590_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2)
{
    D2InventoryStrc* pInventory;
    int nSrcValue;
    int nDstValue;
    int nMaxStack;
    int nQuantity;
    int nRemaining;
    int bRemoveSource;

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return;
    }

    pInventory = pUnit->pInventory;
    nSrcValue = STATLIST_UnitGetStatValue(pItem1, 0x46, 0);
    D2_ASSERT(nSrcValue >= 0, 0x114B);

    nDstValue = STATLIST_UnitGetStatValue(pItem2, 0x46, 0);
    D2_ASSERT(nDstValue >= 0, 0x114D);

    nMaxStack = ITEMS_GetTotalMaxStack(pItem2);
    D2_ASSERT(nMaxStack >= 0, 0x114F);

    nQuantity = nSrcValue + nDstValue;
    bRemoveSource = 1;
    if (nQuantity > nMaxStack)
    {
        STATLIST_SetUnitStat(pItem2, 0x46, nMaxStack, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1155), pItem2, 1, 0x46, nMaxStack, 0);

        nRemaining = nDstValue - nMaxStack + nSrcValue;
        bRemoveSource = 0;
        D2_ASSERT(nRemaining >= 0, 0x1158);

        STATLIST_SetUnitStat(pItem1, 0x46, nRemaining, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x115B), pItem1, 1, 0x46, nRemaining, 0);

        if (ITEMS_GetItemType(pItem1) == 0x12 && ITEMS_GetItemType(pItem2) == 0x12)
        {
            sub_0055C070_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pItem2) - nDstValue, pUnit, pItem2);
        }
    }
    else
    {
        if (ITEMS_HasDurability(pItem1))
        {
            const int nDurability = STATLIST_UnitGetStatValue(pItem1, 0x48, 0);
            if (nDurability < STATLIST_UnitGetStatValue(pItem2, 0x48, 0))
            {
                STATLIST_SetUnitStat(pItem2, 0x48, nDurability, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1170), pItem2, 1, 0x48, nDurability, 0);
            }
        }

        D2_ASSERT(nQuantity >= 0, 0x1176);

        STATLIST_SetUnitStat(pItem2, 0x46, nQuantity, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1179), pItem2, 1, 0x46, nQuantity, 0);

        if (ITEMS_GetItemType(pItem1) == 0x12 && ITEMS_GetItemType(pItem2) == 0x12)
        {
            sub_0055C070_AddBookScrollSkillQuantity(nSrcValue, pUnit, pItem2);
        }
    }

    if (bRemoveSource)
    {
        INVENTORY_SetCursorItem(pInventory, 0);
        D2GAME_PACKETS_SendPacket0x42_6FC3EE40(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1184), pUnit);
        ITEMS_RemoveFromAllPlayers(pGame, pItem1);
    }
    else
    {
        ITEMS_SetItemFlag(pItem2, 8, 1);
    }
}

// 0x0055E7C0
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x1192);
    D2_ASSERT(pUnit, 0x1193);

    *pItemStatus = 0;
    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1198);

    if (nItemGUID1 == nItemGUID2)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2UnitStrc* pItem1 = SUNIT_GetServerUnit(pGame, 4, nItemGUID1);
    if (!pItem1)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem1->dwUnitType != 4)
    {
        return 0;
    }

    D2UnitStrc* pItem2 = SUNIT_GetServerUnit(pGame, 4, nItemGUID2);
    if (!pItem2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem2->dwUnitType != 4)
    {
        return 0;
    }

    if (ITEMS_GetInvPage(pItem2) == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return 0;
    }

    const int nClassId1 = pItem1->dwClassId;
    _ReadWriteBarrier();
    const int nClassId2 = pItem2->dwClassId;
    _ReadWriteBarrier();
    if (nClassId1 != nClassId2)
    {
        return 1;
    }

    sub_0055E590_MergeStacks(pGame, pItem1, pUnit, pItem2);
    ITEMS_SetItemCMDFlag(pItem2, 0x100, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem2);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}
