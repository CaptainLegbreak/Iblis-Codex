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
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0

// 0x0055C470
static void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon)
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
static void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft)
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
static int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
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

unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc*); // 0x00539220
void __fastcall sub_00539230_SetWeaponSwitch(D2ClientStrc*, unsigned char); // 0x00539230
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc*); // 0x0053E110
void __fastcall sub_00571C60_SendSkill(D2UnitStrc*, int, int, int); // 0x00571C60
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x0055C730
void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc*); // 0x00622F80
void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc*); // 0x00622FF0
void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc*, int*, int*); // 0x00623120
void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc*, int*, int*); // 0x006231A0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc*, unsigned char); // 0x00627D70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*, unsigned int, int, const char*); // 0x006280A0
D2UnitStrc* __stdcall INVENTORY_RemoveItem(D2InventoryStrc*, D2UnitStrc*); // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063B210
int __stdcall sub_0063BDB0_PlaceBody(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063BDB0
void __stdcall sub_0063BE30_Return(D2InventoryStrc*, int); // 0x0063BE30
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc*, D2UnitStrc*); // 0x0063D2B0
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc*, D2InventoryStrc*, D2UnitStrc**, int); // 0x0063E490
struct SwapEntry { int from; D2UnitStrc* item; int to; int mode; };
static __forceinline int SkillUsable(D2UnitStrc* player, D2SkillStrc* skill)
{
    if (!skill) return 0;
    switch (SKILLS_GetUseState(player, skill)) { case 2: case 7: return 0; }
    return 1;
}
// 0x005616A0
int __fastcall sub_005616A0_SwapWeapons(D2GameStrc* game, D2UnitStrc* player, int* status)
{
    int i;
    SwapEntry entries[4] = { {4,0,11,4}, {5,0,12,4}, {11,0,4,3}, {12,0,5,3} };
    D2_ASSERT(game, 0xE1E);
    D2_ASSERT(player, 0xE1F);
    *status = 0;
    sub_0055BF50_ClearTargetingFlags(player, szItemModeCpp, 0xE24);
    D2InventoryStrc* inventory = player->pInventory;
    int leftId, leftOwner, rightId, rightOwner;
    UNITS_GetSwitchLeftSkillDataResetLeftSkill(player, &leftId, &leftOwner);
    UNITS_GetSwitchRightSkillDataResetRightSkill(player, &rightId, &rightOwner);
    UNITS_InitSwitchRightSkill(player);
    UNITS_InitSwitchLeftSkill(player);
    i=0;
    if (i<4)
    {
        do
        {
            entries[i].item = INVENTORY_GetItemFromBodyLoc(inventory, entries[i].from);
            if (entries[i].item) {
                INVENTORY_GetSecondWieldingWeapon(player, inventory, &entries[i].item, entries[i].from);
                if (!entries[i].item || entries[i].item->dwAnimMode != 1) { *status=1; return 0; }
            }
            ++i;
        } while (i<4);
    }
    if (entries[0].item) D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(game, entries[0].item, player, 0, 1);
    if (entries[1].item) D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(game, entries[1].item, player, 0, 1);
    SwapEntry* entry = entries;
    for (i=0; i<4; ++i, ++entry) {
        D2UnitStrc* item = entry->item;
        if (!item) continue;
        if (i<2) sub_0063D2B0_DetachItem(inventory, item);
        D2UnitStrc* removed = INVENTORY_RemoveItem(inventory, entry->item);
        if (!removed || removed != entry->item) { *status=1; return 0; }
        sub_0063BE30_Return(inventory, entry->from);
        ITEMS_SetInvPage(removed, 255);
        ITEMS_SetItemCMDFlag(removed, 0x200000, 1);
        ITEMS_SetItemFlag(removed, 1, 1);
        if (ITEMS_CheckItemFlag(removed, 0x4000, 0xE5B, szItemModeCpp)) ITEMS_SetItemFlag(removed, 0x4000, 0);
        INVENTORY_AddItemToTradeInventory(inventory, removed);
    }
    for (i=0; i<4; ++i) {
        D2UnitStrc* item = entries[i].item;
        if (item) {
            if (!sub_0063BDB0_PlaceBody(inventory, item, entries[i].to)) { *status=1; return 0; }
            if (!INVENTORY_PlaceItemInSocket(inventory, item, entries[i].mode)) { *status=1; return 0; }
            ITEMS_SetBodyLocation(item, entries[i].to);
            if (entries[i].to == 4 || entries[i].to == 5) {
                sub_0063D1D0_InventoryItemCall(inventory, item);
                D2GAME_ITEMS_UpdateItemStatlist_6FC42310(game, item, player, 0);
                ITEMS_SetItemFlag(item, 64, 1);
            } else {
                ITEMS_SetItemFlag(item, 128, 1);
            }
            item->dwFlags &= ~2;
            UNITS_ChangeAnimMode(item, 1);
            ITEMS_SetItemFlag(item, 1, 1);
            ITEMS_SetItemCMDFlag(item, 0x200000, 1);
            ITEMS_SetItemFlag(item, 1, 1);
            if (i<2) sub_0055C5C0_RefreshSkillsForEquippedWeapons(player);
        }
    }
    sub_0055DBC0(game, player, 0);
    D2SkillStrc* leftSkill = SKILLS_GetSkillById(player, leftId, leftOwner);
    D2SkillStrc* rightSkill = SKILLS_GetSkillById(player, rightId, rightOwner);
    D2ClientStrc* client = SUNIT_GetClientFromPlayer(player, szItemModeCpp, 0xE93);
    D2_ASSERT(client, 0xE94);
    sub_00539230_SetWeaponSwitch(client, !CLIENTS_GetWeaponSwitch(client));
    D2GAME_PACKETS_SendPacket0x97_6FC3FB60(SUNIT_GetClientFromPlayer(player, szItemModeCpp, 0xE98));
    if (SkillUsable(player, leftSkill)) {
        D2GAME_AssignSkill_6FD13800(player, 1, leftId, leftOwner);
        sub_00571C60_SendSkill(player, 1, leftId, leftOwner);
    } else {
        D2SkillStrc* skill = UNITS_GetLeftSkill(player);
        int id, owner;
        if (skill) { id=SKILLS_GetSkillIdFromSkill(skill, szItemModeCpp, 0xEA2); owner=SKILLS_GetOwnerGUIDFromSkill(skill); }
        else { id=0; owner=-1; }
        sub_00571C60_SendSkill(player, 1, id, owner);
    }
    if (SkillUsable(player, rightSkill)) {
        D2GAME_AssignSkill_6FD13800(player, 0, rightId, rightOwner);
        sub_00571C60_SendSkill(player, 0, rightId, rightOwner);
    } else {
        D2SkillStrc* skill = UNITS_GetRightSkill(player);
        int id, owner;
        if (skill) { id=SKILLS_GetSkillIdFromSkill(skill, szItemModeCpp, 0xEB0); owner=SKILLS_GetOwnerGUIDFromSkill(skill); }
        else { id=0; owner=-1; }
        sub_00571C60_SendSkill(player, 0, id, owner);
    }
    return 1;
}
