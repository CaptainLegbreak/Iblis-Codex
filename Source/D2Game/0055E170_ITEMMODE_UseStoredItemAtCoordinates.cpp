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

struct D2BitBufferStrc;
struct D2ItemsTxt { char unused00[0x80]; unsigned int code; };
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*, D2UnitStrc*); // 0x00543520
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc*, unsigned char, int, int); // 0x0053B3D0
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc*, D2UnitStrc*, int); // 0x005678A0
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005BF240
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc*, D2UnitStrc*); // 0x0058A0A0
void __fastcall sub_00570360_ResetSkills(D2GameStrc*, D2UnitStrc*); // 0x00570360
void __fastcall sub_00570C80_ResetStats(D2GameStrc*, D2UnitStrc*); // 0x00570C80
int __stdcall sub_00628C20_IsUsable(D2UnitStrc*); // 0x00628C20
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*, int, int); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc*, int, int); // 0x0065C3A0
// 0x0055E000
static __declspec(noinline) void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pItem, 0);
}

// 0x0055E050
static __declspec(noinline) int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem)
{
    int nSkillId = -1;
    if (ITEMS_CheckItemTypeId(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFA4);
        nSkillId = pBooksTxtRecord->dwBookSkillId;
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x16))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFAB);
        nSkillId = pBooksTxtRecord->dwScrollSkillId;
    }

    return nSkillId;
}

// build: context sub_0055E0D0_DecrementBook
static __declspec(noinline) void __stdcall sub_0055E0D0_DecrementBook(D2UnitStrc* player, int skillId)
{
    D2SkillStrc* skill = SKILLS_GetSkillById(player, skillId, -1);
    D2_ASSERT(skill, 0xFC4);
    int quantity = SKILLS_GetQuantity(skill) - 1;
    if (quantity <= 0) {
        if (UNITS_GetRightSkill(player) == skill) D2GAME_AssignSkill_6FD13800(player, 0, 0, -1);
        quantity = 0;
    }
    SKILLS_SetQuantity(skill, quantity);
    int id = !player ? -1 : player->dwUnitId;
    int type = !player ? 6 : player->dwUnitType;
    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(player, ".\\ITEMS\\ItemMode.cpp", 0xFC2), type, id, skillId, quantity);
}

static __forceinline D2InventoryStrc* UNITS_GetInventory(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pInventory;
}

static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x0055E170
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* game, D2UnitStrc* player, int itemId, int x, int y, int* status)
{
    D2_ASSERT(game, 0x105A);
    D2_ASSERT(player, 0x105B);
    *status = 0;
    sub_0055BF50_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x1060);
    D2UnitStrc* item = SUNIT_GetServerUnit(game, 4, itemId);
    if (!item) { *status = 1; return 0; }
    if (item->dwUnitType != 4 || INVENTORY_GetCursorItem(UNITS_GetInventory(player))) return 0;
    if (item->dwAnimMode || !sub_00628C20_IsUsable(item)) { *status = 1; return 0; }
    if (ITEMS_GetItemType(item) == 18 && STATLIST_UnitGetStatValue(item, 70, 0) <= 0) return 0;
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(game, player, 1)) return 0;
    if (SKILLITEM_pSpell_Handler(game, player, item, item, x, y)) {
        if (ITEMS_GetItemType(item) == 18) {
            int skillId = sub_0055E050_GetBookSkillIdChecked(item);
            if (skillId != -1 && STATLIST_UnitGetStatValue(item, 70, 0) > 0) {
            STATLIST_AddUnitStat(item, 70, -1, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(player, ".\\ITEMS\\ItemMode.cpp", 0x10B2), item, 1, 70, STATLIST_UnitGetStatValue(item, 70, 0), 0);
            int id = item->dwUnitId;
            int type = item->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(player, ".\\ITEMS\\ItemMode.cpp", 0x10B3), 0x7C, type, id);
            sub_0055E0D0_DecrementBook(player, skillId);
            return 1;
            }
        } else {
        int skillId = sub_0055E050_GetBookSkillIdChecked(item);
        if (skillId != -1) {
            D2SkillStrc* skill = SKILLS_GetSkillById(player, skillId, -1);
            if (skill) {
                int quantity = SKILLS_GetQuantity(skill) - 1;
                if (quantity <= 0) {
                    if (UNITS_GetRightSkill(player) == skill) D2GAME_AssignSkill_6FD13800(player, 0, 0, -1);
                    quantity = 0;
                }
                SKILLS_SetQuantity(skill, quantity);
                int id = player->dwUnitId;
                int type = player->dwUnitType;
                D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(player, ".\\ITEMS\\ItemMode.cpp", 0x10C6), type, id, skillId, quantity);
            }
        }
        sub_0055BF50_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x10C9);
        sub_0055E000_RemoveItemAndNotify(game, player, item);
        }
        return 1;
    }
    D2ItemsTxt* record = DATATBLS_GetItemsTxtRecord(sub_00623C60(item));
    D2BitBufferStrc* flags = sub_00543520(game, player);
    if (record->code == 0x20737361) {
        sub_0055BF50_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x10D5);
        if (QUESTRECORD_GetQuestState(flags, 9, 5)) {
            QUESTRECORD_ClearQuestState(flags, 9, 5);
            STATLIST_AddUnitStat(player, 5, 1, 0);
            QUESTS_SendLogUpdate(player, 8);
            sub_0055E000_RemoveItemAndNotify(game, player, item);
            return 1;
        }
        SUNIT_AttachSound(player, 19, player);
        return 1;
    }
    if (record->code == 0x207A7978) {
        sub_0055BF50_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x10E5);
        if (QUESTRECORD_GetQuestState(flags, 20, 5)) {
            QUESTRECORD_ClearQuestState(flags, 20, 5);
            STATLIST_AddUnitStat(player, 7, 0x1400, 0);
            QUESTS_SendLogUpdate(player, 18);
            sub_0055E000_RemoveItemAndNotify(game, player, item);
            return 1;
        }
        SUNIT_AttachSound(player, 19, player);
        return 1;
    }
    if (record->code == 0x20327274) {
        sub_0055BF50_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x10F8);
        if (QUESTRECORD_GetQuestState(flags, 37, 8) && !QUESTRECORD_GetQuestState(flags, 37, 7)) {
            QUESTRECORD_SetQuestState(flags, 37, 7);
            ACT5Q3_ApplyResistanceReward(game, player);
            QUESTS_SendLogUpdate(player, 33);
            sub_0055E000_RemoveItemAndNotify(game, player, item);
            return 1;
        }
        SUNIT_AttachSound(player, 19, player);
        return 1;
    }
    if (record->code == 0x20616F74) {
        sub_0055BF50_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x110D);
        sub_00570360_ResetSkills(game, player);
        sub_00570C80_ResetStats(game, player);
        sub_0055E000_RemoveItemAndNotify(game, player, item);
        SUNIT_AttachSound(player, 2, player);
        return 1;
    }
    return 0;
}
