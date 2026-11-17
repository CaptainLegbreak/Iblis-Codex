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
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char szItemModeCpp[];                                                                      // 0x006E1164
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

void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);                             // 0x0055C270
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);               // 0x00621050
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                     // 0x006289F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                        // 0x0062E740
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem);                                                         // 0x0062E790
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);        // 0x0063B210
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int bUnused, unsigned char nPage, const char* szFile, int nLine); // 0x0063B950
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused); // 0x0063C3B0
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                     // 0x0055CC90
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4);                 // 0x0055D710
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x00562E00
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                    // 0x00628BA0
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem);            // 0x0063C790
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60

void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558530
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558580
int __fastcall ITEMMODE_CheckAndResolveBodySlotPair(D2UnitStrc*, D2UnitStrc*, D2UnitStrc**, D2UnitStrc**, int*); // 0x0055F2D0
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x00562E00
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc*, int); // 0x00627D70
int __stdcall ITEMS_CheckRequirements(D2UnitStrc*, D2UnitStrc*, int, int*, int*, int*); // 0x0062EAF0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc*, D2UnitStrc*); // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063BDB0
void __stdcall sub_0063BE30_Return(D2InventoryStrc*, int); // 0x0063BE30
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc*, D2UnitStrc*); // 0x0063C790

// 0x0055BFF0
static __declspec(noinline) int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem)
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

// 0x0055C110
static __declspec(noinline) int __stdcall sub_0055C110_UpdateBookScrollSkillQuantity(int bAddQuantity, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId != -1)
    {
        int nQuantity = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
        if (nQuantity || !ITEMS_CheckItemTypeId(pItem, 0x12))
        {
            if (!nQuantity)
            {
                nQuantity = 1;
            }

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            int nNewQuantity;
            if (bAddQuantity)
            {
                if (!pSkill)
                {
                    nNewQuantity = nQuantity;
                    STATLIST_AddUnitStat(pUnit, 5, nNewQuantity, 0);
                    sub_6FD136E0(pUnit, nSkillId);
                    pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                    D2_ASSERT(pSkill, 0x225);
                }
                else
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) + nQuantity;
                }
            }
            else
            {
                if (pSkill)
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) - nQuantity;
                    if (nNewQuantity < 0)
                    {
                        nNewQuantity = 0;
                    }
                }
                else
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x230);
                    exit(-1);
                }
            }

            SKILLS_SetQuantity(pSkill, nNewQuantity);

            int nUnitGUID;
            int nUnitType;
            if (!pUnit)
            {
                nUnitGUID = -1;
                nUnitType = 6;
            }
            else
            {
                nUnitGUID = pUnit->dwUnitId;
                nUnitType = pUnit->dwUnitType;
            }

            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0x234), nUnitType, nUnitGUID, nSkillId, nNewQuantity);

            if (!nNewQuantity)
            {
                if (UNITS_GetLeftSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 1, 0, -1);
                }

                if (UNITS_GetRightSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
                }
            }

            return 1;
        }
    }

    return 0;
}

// 0x0055C470
static __declspec(noinline) void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon)
{
    *ppRightHandWeapon = 0;
    *ppMainWeapon = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        *ppMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRightHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (*ppMainWeapon == pRightHandWeapon)
        {
            *ppRightHandWeapon = pLeftHandWeapon;
        }
        else
        {
            *ppRightHandWeapon = pRightHandWeapon;
        }

        if (*ppRightHandWeapon && !ITEMS_CheckItemTypeId(*ppRightHandWeapon, 0x2D))
        {
            *ppRightHandWeapon = 0;
        }
    }
}

// 0x0055C4D0
static __declspec(noinline) int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }

    return 1;
}

// 0x0055C4F0
static __declspec(noinline) void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft)
{
    if (!pUnit || !pCurrentSkill)
    {
        return;
    }

    int nSkillId;
    int nOwnerGUID;
    if (bLeft)
    {
        UNITS_GetLeftSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }
    else
    {
        UNITS_GetRightSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill || pSkill == pCurrentSkill)
    {
        return;
    }

    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return;
    }

    D2GAME_AssignSkill_6FD13800(pUnit, bLeft, nSkillId, nOwnerGUID);
}

// 0x0055C560
static __declspec(noinline) int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], 0x30) || pSkillsTxtRecord->nRange != 2)
    {
        return 0;
    }

    return sub_0055C4D0_IsSkillUsable(pUnit, pSkill) != 0;
}

// 0x0055C5C0
static __declspec(noinline) void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != 0)
    {
        return;
    }

    D2UnitStrc* pRightHandWeapon;
    D2UnitStrc* pMainWeapon;
    sub_0055C470_GetWeapons(pUnit, &pMainWeapon, &pRightHandWeapon);
    if (!pMainWeapon)
    {
        return;
    }

    int bThrown = ITEMS_CheckItemTypeId(pMainWeapon, 0x30) && !ITEMS_CheckItemTypeId(pMainWeapon, 0x2E);
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (bThrown && !sub_0055C560_IsThrowSkillUsable(pUnit, pLeftSkill))
    {
        UNITS_InitLeftSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 1, 2, -1);
        pLeftSkill = UNITS_GetLeftSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pLeftSkill))
    {
    case 2:
    case 7:
        sub_0055C4F0_RestoreSkill(pUnit, pLeftSkill, 1);
        break;
    }

    bThrown = pRightHandWeapon && ITEMS_CheckItemTypeId(pRightHandWeapon, 0x30) && !ITEMS_CheckItemTypeId(pRightHandWeapon, 0x2E);
    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (bThrown && !sub_0055C560_IsThrowSkillUsable(pUnit, pRightSkill))
    {
        UNITS_InitRightSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, 4, -1);
        pRightSkill = UNITS_GetRightSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pRightSkill))
    {
    case 2:
    case 7:
        sub_0055C4F0_RestoreSkill(pUnit, pRightSkill, 0);
        break;
    }
}

// 0x0055F240
__declspec(noinline) int __fastcall sub_0055F240_GetOppositeBodyLoc(int nBodyLoc)
{
    switch (nBodyLoc)
    {
    case 4:
        return 5;
    case 5:
        return 4;
    case 6:
        return 7;
    case 7:
        return 6;
    case 11:
        return 12;
    case 12:
        return 11;
    }

    return 0;
}

int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0
int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc*, D2UnitStrc*); // 0x0062A1E0
// build: context GetUnitType
static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}
// 0x0055F2D0
int __fastcall ITEMMODE_CheckAndResolveBodySlotPair(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc** ppPrimary, D2UnitStrc** ppOther, int* pBodyLoc)
{
    if (!pUnit || !pItem || GetUnitType(pItem) != 4) return 0;
    D2UnitStrc* pPrimary = *ppPrimary;
    if (pPrimary)
    {
        if (*ppOther) return 0;
    }
    else if (!*ppOther) return 1;
    int nOpposite = sub_0055F240_GetOppositeBodyLoc(*pBodyLoc);
    if (pPrimary)
    {
        *ppPrimary = *ppOther;
        *ppOther = pPrimary;
        *pBodyLoc = nOpposite;
    }
    switch (*pBodyLoc)
    {
    case 4: case 5: case 11: case 12:
        if (ITEMS_GetAmmoType(pItem) > 0)
        {
            if (!*ppOther) return 1;
            return ITEMS_CheckItemTypeId(*ppOther, ITEMS_GetAmmoType(pItem)) != 0;
        }
        if (ITEMS_GetQuiverType(pItem))
        {
            if (!*ppOther) return 1;
            if (ITEMS_GetAmmoType(*ppOther) <= 0) return 0;
            return ITEMS_CheckItemTypeId(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        }
        if (ITEMS_GetAmmoType(*ppOther) > 0) return ITEMS_CheckItemTypeId(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        if (ITEMS_GetQuiverType(*ppOther) > 0) return ITEMS_CheckItemTypeId(pItem, ITEMS_GetQuiverType(*ppOther)) != 0;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem) && !ITEMS_Is1Or2Handed(pUnit, pItem)) return 0;
        if (ITEMS_CheckWeaponIfTwoHanded(*ppOther) && !ITEMS_Is1Or2Handed(pUnit, *ppOther)) return 0;
        {
            int bItemWeapon = ITEMS_CheckItemTypeId(pItem, 45);
            int bOtherWeapon = ITEMS_CheckItemTypeId(*ppOther, 45);
            if (bItemWeapon)
            {
                if (bOtherWeapon)
                {
                    if (GetUnitType(pUnit) == 1) return 1;
                    switch (pUnit->dwClassId)
                    {
                    case 4: return 1;
                    case 6:
                        if (ITEMS_CheckItemTypeId(pItem, 67) && ITEMS_CheckItemTypeId(*ppOther, 67)) return 1;
                        return 0;
                    default: return 0;
                    }
                }
            }
            else if (!bOtherWeapon) return 0;
            return *ppPrimary == 0;
        }
    default: return *ppPrimary == 0;
    }
}

// 0x005600A0
static __declspec(noinline) int __stdcall sub_005600A0_PlaceItemInInventory(D2GameStrc* pGame, int bRemove, int nPage, const char* szFile, int nLine, D2UnitStrc* pUnit, D2UnitStrc* pItem)
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

// build: context ITEMMODE_GetOtherBodyLocItem
static __forceinline D2UnitStrc* ITEMMODE_GetOtherBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc, D2UnitStrc* pItem)
{
    const int nOppositeBodyLoc = sub_0055F240_GetOppositeBodyLoc(nBodyLoc);
    if (!nOppositeBodyLoc)
    {
        return pItem;
    }

    return INVENTORY_GetItemFromBodyLoc(pInventory, nOppositeBodyLoc);
}

// 0x00562F30
int __fastcall ITEMMODE_RecoverCorpseItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pCorpse)
{
    if (!pPlayer || !pCorpse)
    {
        return 0;
    }

    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    D2InventoryStrc* pCorpseInventory = pCorpse->pInventory;
    if (!pPlayerInventory || !pCorpseInventory)
    {
        return 0;
    }

    int bItemRemoved = 0;
    int nCounter = 0;
    do
    {
        bItemRemoved = 0;
        nCounter = 0;
        for (int i = 1; i < 13; ++i)
        {
            int nBodyLoc = i;
            D2UnitStrc* pCorpseItem = INVENTORY_GetItemFromBodyLoc(pCorpseInventory, i);
            if (pCorpseItem)
            {
                ++nCounter;

                if (ITEMS_CheckRequirements(pCorpseItem, pPlayer, 0, 0, 0, 0))
                {
                    D2UnitStrc* pPlayerItem = INVENTORY_GetItemFromBodyLoc(pPlayerInventory, i);
                    D2UnitStrc* pOtherPlayerItem = ITEMMODE_GetOtherBodyLocItem(pPlayerInventory, i, pPlayerItem);

                    int bMoved = 0;
                    if (!ITEMMODE_CheckAndResolveBodySlotPair(pPlayer, pCorpseItem, &pPlayerItem, &pOtherPlayerItem, &nBodyLoc))
                    {
                        if (sub_005600A0_PlaceItemInInventory(pGame, 0, 0, szItemModeCpp, 0x176B, pPlayer, pCorpseItem))
                        {
                            ITEMS_ScheduleDurabilityReplenishment(pGame, pCorpseItem);
                            ITEMS_ScheduleQuantityReplenishment(pGame, pCorpseItem);
                            bMoved = 1;
                        }
                    }
                    else
                    {
                        const int nResolvedBodyLoc = nBodyLoc;
                        D2_ASSERT(!INVENTORY_GetItemFromBodyLoc(pPlayerInventory, nResolvedBodyLoc), 0x1775);

                        if (INVENTORY_PlaceItemInBodyLoc(pPlayerInventory, pCorpseItem, nResolvedBodyLoc))
                        {
                            int nSocketType = 3;
                            if (nResolvedBodyLoc == 11 || nResolvedBodyLoc == 12)
                            {
                                nSocketType = 4;
                            }

                            if (INVENTORY_PlaceItemInSocket(pPlayerInventory, pCorpseItem, nSocketType))
                            {
                                INVENTORY_SetCursorItem(pPlayerInventory, 0);
                                ITEMS_SetBodyLocation(pCorpseItem, nResolvedBodyLoc);
                                pCorpseItem->dwFlags &= ~2u;
                                UNITS_ChangeAnimMode(pCorpseItem, 1);
                                ITEMS_SetItemCMDFlag(pCorpseItem, 8, 1);
                                INVENTORY_AddItemToTradeInventory(pPlayerInventory, pCorpseItem);
                                UNITS_RefreshInventory(pPlayer, 1);
                                pCorpseItem->dwFlags &= ~0x02000000u;
                                ITEMS_SetInvPage(pCorpseItem, 0xFF);

                                if (nSocketType == 3)
                                {
                                    sub_0063D1D0_InventoryItemCall(pPlayerInventory, pCorpseItem);
                                    D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pCorpseItem, pPlayer, 0);
                                    sub_0055C270_OnItemToBelt(pPlayer, pCorpseItem);
                                    sub_0055C5C0_RefreshSkillsForEquippedWeapons(pPlayer);
                                }

                                QUESTS_ItemPickedUp(pGame, pPlayer, pCorpseItem);
                                ITEMS_ScheduleDurabilityReplenishment(pGame, pCorpseItem);
                                ITEMS_ScheduleQuantityReplenishment(pGame, pCorpseItem);
                                bMoved = 1;
                            }
                            else
                            {
                                sub_0063BE30_Return(pPlayerInventory, nResolvedBodyLoc);
                            }
                        }
                    }

                    if (bMoved)
                    {
                        ITEMS_SetItemFlag(pCorpseItem, 1, 1);
                        INVENTORY_RemoveItemFromInventory(pCorpseInventory, pCorpseItem);
                        sub_0063BE30_Return(pCorpseInventory, i);
                        bItemRemoved = 1;
                        --nCounter;
                    }
                }
            }
        }
    }
    while (nCounter && bItemRemoved);

    int bAllowInventoryFallback = 0;
    int nMoved;
    int nResult;
    while (1)
    {
        nMoved = 0;
        nResult = 1;
        D2UnitStrc* pCorpseItem = INVENTORY_GetFirstItem(pCorpseInventory);
        if (!pCorpseItem)
        {
            break;
        }

        do
        {
            D2UnitStrc* pNextItem = INVENTORY_GetNextItem(pCorpseItem);
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCorpseItem);
            if (!ITEMMODE_CanPickUpItem(pGame, pPlayer, pItem))
            {
                nResult = 0;
            }
            else
            {
                if (!ITEMMODE_EquipItemAtResolvedBodyLocation(pGame, pPlayer, pItem, 0))
                {
                    if (ITEMS_CheckIfBeltable(pItem) && INVENTORY_PlaceItemInFreeBeltSlot(pPlayerInventory, pItem))
                    {
                        if (!INVENTORY_PlaceItemInSocket(pPlayerInventory, pItem, 2))
                            goto NextLooseItem;
                        INVENTORY_SetCursorItem(pPlayerInventory, 0);

                        D2_ASSERT(pItem, 0x24E);
                        if (pPlayer->dwUnitType == 0)
                        {
                            sub_0055C110_UpdateBookScrollSkillQuantity(1, pPlayer, pItem);
                        }

                        pItem->dwFlags &= ~2u;
                        if (ITEMS_IsCharmUsable(pItem, pPlayer))
                        {
                            D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pPlayer, 0);
                        }

                        UNITS_ChangeAnimMode(pItem, 2);
                        pItem->dwFlags &= ~0x02000000u;
                        ITEMS_SetItemCMDFlag(pItem, 0x2000u, 1);
                        ITEMS_SetInvPage(pItem, 0xFF);
                        INVENTORY_AddItemToTradeInventory(pPlayerInventory, pItem);
                        UNITS_RefreshInventory(pPlayer, 1);
                    }
                    else if (!bAllowInventoryFallback)
                    {
                        goto NextLooseItem;
                    }
                    else if (!sub_005600A0_PlaceItemInInventory(pGame, 0, 0, szItemModeCpp, 0x17F1, pPlayer, pItem))
                    {
                        nResult = 0;
                        goto NextLooseItem;
                    }
                }
                ++nMoved;
                ITEMS_SetItemFlag(pItem, 1, 1);
            }
NextLooseItem:

            pCorpseItem = pNextItem;
        }
        while (pCorpseItem);

        if (!nMoved)
        {
            if (bAllowInventoryFallback)
            {
                break;
            }

            bAllowInventoryFallback = 1;
        }
    }
    sub_0055DBC0(pGame, pPlayer, 0);
    return nResult;
}
