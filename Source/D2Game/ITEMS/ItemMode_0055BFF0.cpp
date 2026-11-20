#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ITEMQUAL_UNIQUE 7
#define QUESTSTATEFLAG_A1Q4 4
#define QUESTSTATEFLAG_A2Q1 9
#define QUESTSTATEFLAG_A2Q2 10
#define QFLAG_REWARDGRANTED 0
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define ITEMACTION_FLAG_BELT 0x20
#define IFLAG_NEWITEM 0x1
#define IFLAG_IDENTIFIED 0x10
struct D2CorpseStrc;
struct D2StaticPathStrc;
struct D2BooksTxt;
struct D2SkillsTxt;
struct D2EquipmentRefreshStateStrc;
struct D2ItemsTxt;
struct D2PlayerDataStrc;
struct D2QuestItemPairStrc;

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
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x2];
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, int a3, int nStatId, int nValue, int a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGold); // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAmount); // 0x0055B030
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x0055DBC0
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId); // 0x00570080
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill); // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity); // 0x00645120
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0


struct D2UniqueItemsTxt
{
    short wId;
    char unk0x002[0x2A];
    unsigned char nUniqueItemFlags[4];
    char unk0x030[0x11C];
};


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2QuestItemPairStrc gQuestItemPairs_00731FEC[4]; // 0x00731FEC
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610
static int __stdcall sub_6FC428F0(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem); // 0x0055CA40
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused); // 0x0063C3B0
int __stdcall sub_0062A360(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A360
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* pWeapon); // 0x006233A0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc); // 0x0063E490
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590
void __fastcall sub_6FC45930(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x005608C0
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C270
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int bUnused, unsigned char nPage, const char* szFile, int nLine); // 0x0063B950
void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nFlags); // 0x0053EED0
void __fastcall sub_6FC49090(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055ED30
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60
void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0055FE00
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660

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

// 0x0055BFF0
static int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x1EC);

    if (ITEMSIsA(pItem, 0x16) || ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        if (pBooksTxtRecord)
        {
            if (ITEMSIsA(pItem, 0x16))
            {
                return pBooksTxtRecord->dwScrollSkillId;
            }

            if (ITEMSIsA(pItem, 0x12))
            {
                return pBooksTxtRecord->dwBookSkillId;
            }
        }
    }

    return -1;
}

// 0x0055C070
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
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x20B), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
}

static int __stdcall sub_0055C110_UpdateBookScrollSkillQuantity(int bAddQuantity, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId != -1)
    {
        int nQuantity = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
        if (nQuantity || !ITEMSIsA(pItem, 0x12))
        {
            if (!nQuantity)
            {
                nQuantity = 1;
            }

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            int nNewQuantity;
            if (bAddQuantity)
            {
                if (pSkill)
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) + nQuantity;
                }
                else
                {
                    STATLIST_AddUnitStat(pUnit, 5, nQuantity, 0);
                    sub_6FD136E0(pUnit, nSkillId);
                    pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                    D2_ASSERT(pSkill, 0x225);
                    nNewQuantity = nQuantity;
                }
            }
            else
            {
                D2_ASSERT(pSkill, 0x230);

                nNewQuantity = SKILLS_GetQuantity(pSkill) - nQuantity;
                if (nNewQuantity < 0)
                {
                    nNewQuantity = 0;
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

            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x234), nUnitType, nUnitGUID, nSkillId, nNewQuantity);

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

// 0x0055C270
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x24D);
    D2_ASSERT(pItem, 0x24E);

    if (pUnit->dwUnitType == 0)
    {
        sub_0055C110_UpdateBookScrollSkillQuantity(1, pUnit, pItem);
    }
}

// 0x0055C460
void __fastcall sub_0055C460_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats)
{
    sITEMSAddStatsList(pGame, pItem, pUnit, bAllowBrokenItemStats);
}

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

        if (*ppRightHandWeapon && !ITEMSIsA(*ppRightHandWeapon, 0x2D))
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
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], 0x30) || pSkillsTxtRecord->nAuraTargetState != 2)
    {
        return 0;
    }

    return sub_0055C4D0_IsSkillUsable(pUnit, pSkill) != 0;
}

// 0x0055C5C0
static void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit)
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

    int bThrown = ITEMSIsA(pMainWeapon, 0x30) && !ITEMSIsA(pMainWeapon, 0x2E);
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

    bThrown = pRightHandWeapon && ITEMSIsA(pRightHandWeapon, 0x30) && !ITEMSIsA(pRightHandWeapon, 0x2E);
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

// 0x0055C6E0
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x394);
    D2_ASSERT(pItem, 0x395);

    if (pUnit->dwUnitType == 0)
    {
        sub_0055C110_UpdateBookScrollSkillQuantity(0, pUnit, pItem);
    }
}

// build: context sub_0055D970_UpdateEquippedItemStats
static void __stdcall sub_0055D970_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return;
    }

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0xB || nBodyLoc == 0xC)
    {
        return;
    }

    sub_0063D1D0_InventoryItemCall(pUnit->pInventory, pItem);

    if (UNITS_GetAnimOrSeqMode(pItem) == 1 || !UNITS_GetAnimOrSeqMode(pItem) && ITEMS_IsCharmUsable(pItem, pUnit))
    {
        sITEMSAddStatsList(pGame, pItem, pUnit, 1);
    }
}

// 0x0055D9D0
static void sub_0055D9D0_SaveEquipmentRefreshState(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState)
{
    pRefreshState->nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pRefreshState->nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
    pRefreshState->nStamina = STATLIST_UnitGetStatValue(pUnit, 10, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pRefreshState->nLeftSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pRefreshState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\ITEMS\\ItemMode.cpp", 0x9DF);
    }
    else
    {
        pRefreshState->nLeftSkillOwnerGUID = -1;
        pRefreshState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pRefreshState->nRightSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pRefreshState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\ITEMS\\ItemMode.cpp", 0x9EB);
    }
    else
    {
        pRefreshState->nRightSkillOwnerGUID = -1;
        pRefreshState->nRightSkillId = 0;
    }
}

// 0x0055DA70
static void sub_0055DA70_RestoreSelectedSkills(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState)
{
    if (pRefreshState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRefreshState->nLeftSkillId, pRefreshState->nLeftSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (SKILLS_GetUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;

            default:
                D2GAME_AssignSkill_6FD13800(pUnit, 1, pRefreshState->nLeftSkillId, pRefreshState->nLeftSkillOwnerGUID);
                break;
            }
        }
    }

    if (pRefreshState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRefreshState->nRightSkillId, pRefreshState->nRightSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (SKILLS_GetUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;

            default:
                D2GAME_AssignSkill_6FD13800(pUnit, 0, pRefreshState->nRightSkillId, pRefreshState->nRightSkillOwnerGUID);
                break;
            }
        }
    }
}

// 0x0055E000
static void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pItem, 0);
}

// 0x0055E050
static int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem)
{
    int nSkillId = -1;
    if (ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFA4);
        nSkillId = pBooksTxtRecord->dwBookSkillId;
    }
    else if (ITEMSIsA(pItem, 0x16))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFAB);
        nSkillId = pBooksTxtRecord->dwScrollSkillId;
    }

    return nSkillId;
}

// 0x0055E8E0
static void __stdcall sub_0055E8E0_InitItemDrop(int nId, D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    memset(pItemDrop, 0, sizeof(D2ItemDropStrc));
    pItemDrop->pGame = pGame;
    pItemDrop->nItemLvl = ITEMS_GetItemLevel(pItem);
    pItemDrop->wItemFormat = pGame->wItemFormat;
    pItemDrop->nId = nId;
    pItemDrop->nSpawnType = 4;
    pItemDrop->nX = sub_E03_ItemGetUnitX(pItem);
    pItemDrop->nY = sub_E03_ItemGetUnitY(pItem);
    pItemDrop->pSeed = pItem->pSeed;
    pItemDrop->wUnitInitFlags = 1;
    pItemDrop->nQuality = 2;
    pItemDrop->dwSeed = pItem->dwInitSeed;
    const unsigned int nItemSeed = ITEMS_GetItemStartSeed(pItem);
    pItemDrop->dwFlags1 = 2;
    pItemDrop->dwItemSeed = nItemSeed;
}

// build: context D2GAME_DoKeyCheck_6FC4A4B0
int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 0x15F3);
    D2_ASSERT(pUnit, 0x15F4);

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x15F7);

    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pUnit->pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMSIsA(pItem, 0x29) && !ITEMS_GetInvPage(pItem))
        {
            if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) - 1 > 0)
            {
                STATLIST_AddUnitStat(pItem, 0x46, -1, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1605), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, 0x46, 0), 0);
                return 1;
            }

            sub_0055E000_RemoveItemAndNotify(pGame, pUnit, pItem);
            return 1;
        }
    }

    return 0;
}

// 0x0055F500
void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2EquipmentRefreshStateStrc refreshState;
    sub_0055D9D0_SaveEquipmentRefreshState(pUnit, &refreshState);

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        int nStatNotDynamic = 0;
        if (pItem && pItem->dwUnitType == 4 && STATLIST_GetOwner(pItem, &nStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
        }

        pCurrent = pNext;
    }

    sub_0055DA70_RestoreSelectedSkills(pUnit, &refreshState);
}

// 0x0055F6E0
void __fastcall sub_0055F6E0_AddItemQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue)
{
    STATLIST_AddUnitStat(pItem, 0x46, nValue, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x18E0), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, 0x46, 0), 0);
    sub_0055C070_AddBookScrollSkillQuantity(nValue, pUnit, pItem);
}

// 0x0055F900
void __fastcall sub_0055F900_EquipItemRefresh(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }

    ITEMS_SetItemFlag(pItem, 0x200, 1);
    ITEMS_SetItemFlag(pItem, 0x100, 0);
    if (pInventory)
    {
        sub_0055D970_UpdateEquippedItemStats(pGame, pItem, pUnit);
        sub_0055DBC0(pGame, pUnit, 0);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
    if (nMaxDurability > 0)
    {
        STATLIST_SetUnitStat(pItem, 0x48, nMaxDurability, 0);
        if (pUnit)
        {
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x193C), pItem, 1, 0x48, nMaxDurability, 0);
        }
    }

    ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    if (pUnit)
    {
        sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
    }
}

// build: context sub_E03_EmitItemDrop
int __fastcall sub_E03_EmitItemDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nId)
{
    D2ItemDropStrc itemDrop;
    sub_0055E8E0_InitItemDrop(nId, pGame, pItem, &itemDrop);
    sub_0055E000_RemoveItemAndNotify(pGame, pUnit, pItem);
    return sub_00558D90_SpawnItem(pGame, &itemDrop, 0) != 0;
}

int __fastcall sub_E03_EmitBookSkillA(D2UnitStrc* pItem)
{
    return sub_0055E050_GetBookSkillIdChecked(pItem);
}

int __fastcall sub_0055CA00_MatchFieldPair(D2ItemsTxt* pRecord1, D2ItemsTxt* pRecord2, int nValue1, int nValue2)
{
    if (pRecord1->dwCode == nValue1 && pRecord2->dwCode == nValue2)
    {
        return 1;
    }

    if (pRecord1->dwCode == nValue2 && pRecord2->dwCode == nValue1)
    {
        return 1;
    }

    return 0;
}

static __forceinline int ITEMS_IsItemInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_ITEM;
}

static __forceinline D2UniqueItemsTxt* DATATBLS_GetUniqueItemsTxtRecordInline(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }
    return 0;
}

// build: context sub_6FC428F0
static int __stdcall sub_6FC428F0(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem)
{
    int nUniqueId = -1;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7])
        {
            nUniqueId = pUniqueItemsTxtRecord->wId;
        }
    }

    while (pPreviousItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pPreviousItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pPreviousItem);
        if (pCheckedItem == pItem)
        {
            break;
        }

        if (!ITEMS_IsItemInline(pCheckedItem))
        {
            pPreviousItem = pNext;
            continue;
        }

        if (nUniqueId >= 0 && ITEMS_GetInvPage(pCheckedItem) != 1 && ITEMS_GetItemQuality(pCheckedItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pCheckedItem) == nUniqueId)
        {
            return 1;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pCheckedItem->dwClassId);
        if (pItemsTxtRecord->nQuest && ITEMS_GetInvPage(pCheckedItem) != 1 && pItemsTxtRecord->nQuest == pItemsTxtRecordArg->nQuest)
        {
            if (pItemsTxtRecordArg->dwCode == pItemsTxtRecord->dwCode
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 43j', ' 43g')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' skb', ' dkb')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 33d', ' 33g')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' fsm')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' piv')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' 1fq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rhq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' yeq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rbq'))
            {
                return 1;
            }
        }

        pPreviousItem = pNext;
    }

    return 0;
}

// 0x0055CC90
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pPreviousItem = INVENTORY_GetFirstItem(pInventory);
    if (!pInventory)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7] && sub_6FC428F0(pItem, pItemsTxtRecord, pPreviousItem))
        {
            return 0;
        }
    }

    if (!pItemsTxtRecord->nQuest)
    {
        return 1;
    }

    const unsigned int nItemCode = pItemsTxtRecord->dwCode;
    if (nItemCode == ' ssa')
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 43j')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_REWARDGRANTED))
        {
            return 0;
        }
    }
    else if (nItemCode == ' zyx')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 33g')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 2rt')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }
    }

    const int nQuest = pItemsTxtRecord->nQuest;
    if (nQuest - 1 == QUESTSTATEFLAG_A2Q1)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' xob')
        {
            return 0;
        }
    }
    else if (nQuest - 1 == QUESTSTATEFLAG_A1Q4)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' gel')
        {
            return 0;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 4; ++i)
        {
            if (pItemsTxtRecord->nQuest == gQuestItemPairs_00731FEC[i].nItemQuest)
            {
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
                if (QUESTRECORD_GetQuestState(pQuestFlags, gQuestItemPairs_00731FEC[i].nQuestFlag, QFLAG_REWARDGRANTED))
                {
                    return 0;
                }
            }
        }
    }

    if (sub_6FC428F0(pItem, pItemsTxtRecord, pPreviousItem))
    {
        return 0;
    }

    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pUnit->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pPlayer && pPlayer->pInventory)
        {
            D2UnitStrc* pFirstItem = INVENTORY_GetFirstItem(pPlayer->pInventory);
            if (pFirstItem && sub_6FC428F0(pItem, pItemsTxtRecord, pFirstItem))
            {
                return 0;
            }
        }
    }

    return 1;
}

#include "gen/data/Source/D2Game/ITEMS/ItemMode_0055BFF0.inc"

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
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5CA), pStackItem, 1, 0x46, nMaxStack, 0);

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
                        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5E4), pStackItem, 1, 0x48, nDurability, 0);
                    }
                }

                STATLIST_SetUnitStat(pStackItem, 0x46, nQuantity, 0);
                STATLIST_SetUnitStat(pItem, 0x46, 0, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5ED), pStackItem, 1, 0x46, nQuantity, 0);

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

// 0x0055D370
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
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x638), pBook, 1, 0x46, nDstMaxValue, 0);

        const int nRest = nDstValue - nDstMaxValue + nSrcValue;
        D2_ASSERT(nRest >= 0, 0x63A);

        STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x63D), pItem, 1, 0x46, nRest, 0);
        sub_0055C070_AddBookScrollSkillQuantity(nDstMaxValue - nDstValue, pUnit, pBook);
        return 1;
    }

    D2_ASSERT(nQuantity >= 0, 0x645);

    STATLIST_SetUnitStat(pBook, 0x46, nQuantity, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x648), pBook, 1, 0x46, nQuantity, 0);
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
    if (!pBook)
    {
        return 0;
    }

    int nItemStatus;
    return ITEMMODE_AddScrollToBook(pGame, pUnit, pScroll ? pScroll->dwUnitId : -1, pBook->dwUnitId, &nItemStatus);
}

static int sub_00560020_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x65F);

    if (ITEMSIsA(pItem, 0x16))
    {
        return sub_0055FFA0_AddScrollToBook(pGame, pUnit, pItem);
    }

    if (ITEMSIsA(pItem, 0x12))
    {
        return sub_0055D370_TryMergeBookQuantity(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckIfStackable(pItem) && ITEMS_GetAutoStack(pItem))
    {
        return sub_0055D0D0_AutoStackPickup(pGame, pUnit, pItem);
    }

    return 0;
}

int __fastcall sub_J07_Emit_00560020(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    return sub_00560020_PickupStackable(pGame, pUnit, pItem);
}

// 0x0055F5D0
static int __stdcall sub_0055F5D0_HasSameAffixes(D2UnitStrc* pBook, D2UnitStrc* pItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        if (ITEMS_GetPrefixId(pBook, i) != ITEMS_GetPrefixId(pItem, i))
        {
            return 0;
        }

        if (ITEMS_GetSuffixId(pBook, i) != ITEMS_GetSuffixId(pItem, i))
        {
            return 0;
        }
    }

    return ITEMS_GetAutoAffix(pBook) == ITEMS_GetAutoAffix(pItem);
}

D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pFreeQuantity)
{
    if (!ITEMSIsA(pItem, 0x16))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pBook = INVENTORY_UnitIsItem(pCurrent);
        pCurrent = INVENTORY_GetNextItem(pCurrent);
        if (pBook && ITEMS_GetItemType(pBook) == 0x12 && !ITEMS_GetInvPage(pBook) && sub_0055F5D0_HasSameAffixes(pBook, pItem))
        {
            int nQuantity = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
            if (nQuantity < 0)
            {
                nQuantity = 0;
            }

            const int nMaxStack = ITEMS_GetTotalMaxStack(pBook);
            if (nQuantity < nMaxStack)
            {
                *pFreeQuantity = nMaxStack - nQuantity;
                return pBook;
            }
        }
    }

    return 0;
}

// 0x0055F740
D2UnitStrc* __fastcall sub_0055F740_AddScrollToMatchingBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bCheckOnly)
{
    if (!ITEMSIsA(pItem, 0x16))
    {
        return 0;
    }

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pBook = INVENTORY_UnitIsItem(pCurrent);
        if (ITEMS_GetItemType(pBook) == 0x12 && !ITEMS_GetInvPage(pBook) && sub_0055F5D0_HasSameAffixes(pBook, pItem))
        {
            const int nAdded = 1 > STATLIST_UnitGetStatValue(pItem, 0x46, 0) ? 1 : STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            const int nQuantity = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
            if (nQuantity + nAdded <= ITEMS_GetTotalMaxStack(pBook))
            {
                if (!bCheckOnly)
                {
                    STATLIST_SetUnitStat(pBook, 0x46, nQuantity + nAdded, 0);
                    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1905), pBook, 1, 0x46, nQuantity + nAdded, 0);
                    sub_0055C070_AddBookScrollSkillQuantity(nAdded, pUnit, pBook);
                }

                return pBook;
            }
        }

        pCurrent = pNext;
    }

    return 0;
}

// 0x0055F9C0
void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    const int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId == -1)
    {
        return;
    }

    STATLIST_UnitGetStatValue(pItem, 0x46, 0);

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        SKILLS_GetQuantity(pSkill);
    }

    SKILLS_SetQuantity(pSkill, 0);

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

    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1962), nUnitType, nUnitGUID, nSkillId, 0);
}

// 0x0055FA40
void __fastcall ITEMMODE_RebuildBookScrollSkillQuantities(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pInventory);
    int nCounter = 0;

    D2UnitStrc* pNext;
    for (; pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        if (!pItem || pItem->dwAnimMode == 0)
        {
            ITEMMODE_ResetBookScrollSkillQuantity(pUnit, pItem);
            if (!ITEMS_GetInvPage(pItem))
            {
                nCounter += 1;
            }
        }
    }

    if (!nCounter)
    {
        return;
    }

    for (pCurrent = INVENTORY_GetFirstItem(pInventory); pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        if ((!pItem || pItem->dwAnimMode == 0) && !ITEMS_GetInvPage(pItem))
        {
            sub_0055C110_UpdateBookScrollSkillQuantity(1, pUnit, pItem);
            nCounter -= 1;
            if (!nCounter)
            {
                return;
            }
        }
    }
}

// 0x005606B0
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus)
{
    int bIsSwitchWeapon = 0;
    if (nBodyLoc == 0xB || nBodyLoc == 0xC)
    {
        bIsSwitchWeapon = 1;
    }

    D2_ASSERT(pGame, 0xAEE);
    D2_ASSERT(pPlayer, 0xAEF);

    if (pItemStatus)
    {
        *pItemStatus = 0;
    }

    sub_0055BF50_ClearTargetingFlags(pPlayer, ".\\ITEMS\\ItemMode.cpp", 0xAF7);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        if (pItemStatus)
        {
            *pItemStatus = 1;
        }

        return 0;
    }

    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    if (pItem->dwAnimMode != 4)
    {
        if (pItemStatus)
        {
            *pItemStatus = 1;
        }

        return 0;
    }

    if (D2Common_10299(pPlayer, nBodyLoc, pItem, bSkipRequirementCheck) != 1)
    {
        if (pItemStatus)
        {
            *pItemStatus = 0;
        }

        return 0;
    }

    if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0))
    {
        if (pItemStatus)
        {
            *pItemStatus = 1;
        }

        return 0;
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!bIsSwitchWeapon)
    {
        D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        if (pMainWeapon)
        {
            UNITS_SetWeaponGUID(pPlayer, pMainWeapon);
        }
    }

    if (sub_0063BDB0(pInventory, pItem, nBodyLoc))
    {
        int nPage = 3;
        if (bIsSwitchWeapon)
        {
            nPage = 4;
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
        {
            ITEMS_SetBodyLocation(pItem, nBodyLoc);

            if (!bIsSwitchWeapon)
            {
                sub_0063D1D0_InventoryItemCall(pInventory, pItem);
                sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
            }

            INVENTORY_SetCursorItem(pInventory, 0);
            pItem->dwFlags &= ~2;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 0xFF);
            ITEMS_SetItemCMDFlag(pItem, 8, 1);
            ITEMS_SetItemFlag(pItem, 1, 1);
            if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xB4E, ".\\ITEMS\\ItemMode.cpp"))
            {
                ITEMS_SetItemFlag(pItem, 0x4000, 0);
            }

            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pPlayer, 1);
            sub_0055C5C0_RefreshSkillsForEquippedWeapons(pPlayer);
            sub_0055DBC0(pGame, pPlayer, 0);
        }
        else
        {
            if (pItemStatus)
            {
                *pItemStatus = 1;
            }

            return 0;
        }
    }

    return 1;
}

// 0x00560CD0
int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus)
{
    D2_ASSERT(pGame, 0xC44);
    D2_ASSERT(pUnit, 0xC45);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xC4A);

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 0;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
    if (!pItem)
    {
        *pItemStatus = 0;
        return 0;
    }

    const int nItemType = pItem ? pItem->dwUnitType : 6;
    if (nItemType != 4)
    {
        return 0;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xC64);

    const int nResult = D2Common_10299(pUnit, nBodyLoc, 0, 0);
    if (nResult != 3 && nResult != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, nBodyLoc);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    sub_0062A360(pUnit, pItem);
    sub_0063D2B0_DetachItem(pInventory, pItem);
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);

    D2_ASSERT(pRemove, 0xC76);
    D2_ASSERT(pItem == pRemove, 0xC77);

    sub_0063BE30(pInventory, nBodyLoc);

    if (ITEMS_GetItemType(pRemove) == 0x13)
    {
        sub_6FC45930(pGame, pUnit, 0);
    }

    if (bSetQuantityFlag)
    {
        ITEMS_SetItemFlag(pItem, 0x20, 1);
    }
    else
    {
        INVENTORY_SetCursorItem(pInventory, pItem);
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);

    if (pItem)
    {
        pItem->dwFlags &= ~2;
    }

    UNITS_ChangeAnimMode(pItem, 4);
    ITEMS_SetItemCMDFlag(pItem, 0x10, 1);

    if (sub_0055F590_CheckItem(pItem, ".\\ITEMS\\ItemMode.cpp", 0xC8B))
    {
        ITEMS_SetItemFlag(pItem, 1, 1);
    }

    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xC8E, ".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(pItem, 0x4000, 0);
    }

    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
    sub_0055DBC0(pGame, pUnit, 0);
    return 1;
}

// build: context ITEMMODE_EquipItemAtResolvedBodyLocation
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck)
{
    int nBodyLoc;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!sub_6FC42F20(pUnit, pItem, &nBodyLoc, bSkipRequirementCheck))
    {
        return 0;
    }

    D2_ASSERT(sub_0063BDB0(pInventory, pItem, nBodyLoc), 0x1674);
    D2_ASSERT(nBodyLoc != 0xB && nBodyLoc != 0xC, 0x1656);

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
    {
        sub_0063BE30(pInventory, nBodyLoc);
        D2_ASSERT(0, 0x1671);
    }

    ITEMS_SetBodyLocation(pItem, nBodyLoc);
    sub_0063D1D0_InventoryItemCall(pInventory, pItem);
    INVENTORY_SetCursorItem(pInventory, 0);
    sITEMSAddStatsList(pGame, pItem, pUnit, 0);

    if (pItem)
    {
        pItem->dwFlags &= ~2;
    }

    UNITS_ChangeAnimMode(pItem, 1);
    ITEMS_SetItemCMDFlag(pItem, 0x200, 1);

    if (pItem)
    {
        pItem->dwFlags &= ~0x2000000;
    }

    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    ITEMS_SetInvPage(pItem, 0xFF);
    sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
    return 1;
}

// 0x005600A0
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
                sITEMSAddStatsList(pGame, pItem, pUnit, 0);
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

int __fastcall sub_K06_Emit_005600A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bRemove)
{
    if (!sub_005600A0_PlaceItemInInventory(pGame, bRemove, 0, ".\\ITEMS\\ItemMode.cpp", 0x7EF, pUnit, pItem))
    {
        UNITS_RefreshInventory(pUnit, 0);
        return 0;
    }
    UNITS_ChangeAnimMode(pItem, 0);
    return 1;
}

// 0x00561E70
void __fastcall sub_00561E70_RemoveFromBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 3988);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, ITEMACTION_FLAG_BELT, 1);
    D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(pClient, pUnit, pItem, nFlags);
    sub_6FC49090(pGame, pUnit, pItem);
}

// 0x00562590
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 0x1380, ".\\ITEMS\\ItemMode.cpp") || !pInventory)
    {
        return;
    }

    D2_ASSERT(!ITEMS_CheckItemCMDFlag(pItem, 0x100000), 0x1383);

    ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pItem, pPlayer);
    ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);

    if (ITEMS_CheckItemFlag(pItem, IFLAG_NOEQUIP, 0x1389, ".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(pItem, IFLAG_NOEQUIP, 0);
    }

    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pPlayer, 1);
    SUNIT_AttachSound(pPlayer, 6, pPlayer);
}

static __forceinline int sub_M70_ItemGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nX;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int sub_M70_ItemGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nY;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00563350
int __fastcall sub_6FC4B310(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pSocketable, int a5)
{
    if (ITEMS_CheckIfSocketable(pItem))
    {
        if (!pItem->pInventory)
        {
            return 0;
        }

        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(i);
            D2UnitStrc* pDupedItem = ITEMS_Duplicate(pGame, pCheckedItem, 0, 1);
            UNITS_ChangeAnimMode(pDupedItem, IMODE_ONCURSOR);
            UNITS_SetXForStaticUnit(pDupedItem, sub_M70_ItemGetUnitX(pCheckedItem));
            UNITS_SetYForStaticUnit(pDupedItem, sub_M70_ItemGetUnitY(pCheckedItem));

            int bPlaced;
            if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pUnit, !pDupedItem ? -1 : pDupedItem->dwUnitId, sub_00451F50_GetUnitGUID(pSocketable), &bPlaced, a5, 0, 1, 0))
            {
                return 0;
            }
        }
    }

    return 1;
}

// 0x00564CA0
extern "C" __declspec(dllexport) int __cdecl sub_00564CA0() {
    return 1;
}
