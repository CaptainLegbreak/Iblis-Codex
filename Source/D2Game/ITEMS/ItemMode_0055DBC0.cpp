#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2TxtTables.h"
struct D2GameStrc;
struct D2UnitStrc;
// build: ob1

struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2DynamicPathStrc;






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


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char szItemModeCpp[];                                                                      // 0x006E1164
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue);                                 // 0x0053FF00
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGold);                      // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);             // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B030
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);         // 0x0055BF50
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);             // 0x0055CC90
void __fastcall sub_0055DBC0_RecalcEquippedItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);
static __forceinline int sub_0055DBC0_GetUnitType(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// build: context sub_0055DBC0_UnitFlag9
static __forceinline int sub_0055DBC0_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// 0x0055DBC0
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId);                                               // 0x00570080
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
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
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                               // 0x006374B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0
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
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);        // 0x00558D90
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit);           // 0x0053D2E0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0

static void __declspec(noinline) __stdcall sub_0055D970_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit);

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

    INVENTORY_UpdateWeaponGUIDOnInsert(pUnit->pInventory, pItem);

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
        pRefreshState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, szItemModeCpp, 0x9DF);
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
        pRefreshState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, szItemModeCpp, 0x9EB);
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

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
int __fastcall sub_0055DB00_CheckEquipRequirements(D2UnitStrc* pUnit,D2UnitStrc* pItem); // 0x0055DB00
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem,unsigned int dwFlag,int nLine,const char* szFile); // 0x006280A0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory,D2UnitStrc* pItem); // 0x0063D2B0
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame,D2UnitStrc* pItem,D2UnitStrc* pUnit,int nArg1,int nArg2); // 0x0055C730
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient,D2UnitStrc* pUnit,int nArg); // 0x0053D3C0

// 0x0055DBC0
void __fastcall sub_0055DBC0_RecalcEquippedItemStates(D2GameStrc* pGame,D2UnitStrc* pUnit,int bRefresh)
{
    if (!pUnit)
        return;

    if (sub_0055DBC0_GetUnitType(pUnit) && !sub_0055DBC0_UnitFlag9(pUnit))
        return;

    D2EquipmentRefreshStateStrc refreshState;
    sub_0055D9D0_SaveEquipmentRefreshState(pUnit,&refreshState);
    D2InventoryStrc* pInventory=pUnit->pInventory;
    if(!pInventory) return;
    for(D2UnitStrc* pLink=INVENTORY_GetFirstItem(pInventory);pLink;pLink=INVENTORY_GetNextItem(pLink))
    {
        D2UnitStrc* pItem=INVENTORY_UnitIsItem(pLink);
        if(pItem && INVENTORY_GetItemNodePage(pLink)==1 && ITEMS_IsCharmUsable(pItem,pUnit) && !STATLIST_GetOwner(pItem,0) && sub_0055DB00_CheckEquipRequirements(pUnit,pItem))
        {
            ITEMS_SetItemFlag(pItem,0x4000,0);
            sub_0055D970_UpdateEquippedItemStats(pGame,pItem,pUnit);
        }
    }
    for (int i = 1; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0xa85, szItemModeCpp) && !STATLIST_GetOwner(pItem, 0))
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xa8a, szItemModeCpp) && !STATLIST_GetOwner(pItem, 0))
            continue;

        if (sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
        const int nMode = UNITS_GetAnimOrSeqMode(pItem);
        if (nMode == 1)
            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, nMode, nMode);
    }
    int bContinue;
    do
    {
        bContinue=0;
        for (int i = 1; i < 11; ++i)
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (!pItem)
                continue;

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0xaa4, szItemModeCpp))
                continue;

            if (!ITEMS_CheckItemFlag(pItem, 0x4000, 0xaa8, szItemModeCpp) && STATLIST_GetOwner(pItem, 0))
                continue;

            if (!sub_0055DB00_CheckEquipRequirements(pUnit, pItem))
                continue;

            {
                ITEMS_SetItemFlag(pItem,0x4000,0);
                D2InventoryStrc* pCurrentInventory=pUnit->pInventory;
                if(pCurrentInventory)
                {
                    unsigned char nBodyLoc=ITEMS_GetBodyLocation(pItem);
                    if(nBodyLoc!=0xb && nBodyLoc!=0xc)
                    {
                        INVENTORY_UpdateWeaponGUIDOnInsert(pCurrentInventory,pItem);
                        if (UNITS_GetAnimOrSeqMode(pItem)==1)
                        {
                            sITEMSAddStatsList(pGame,pItem,pUnit,1);
                        }
                        else if (!UNITS_GetAnimOrSeqMode(pItem) && ITEMS_IsCharmUsable(pItem,pUnit))
                        {
                            sITEMSAddStatsList(pGame,pItem,pUnit,1);
                        }
                    }
                }
                bContinue=1;
            }
        }
    }while(bContinue);
    for(int i=1;i<11;++i)
    {
        D2UnitStrc* pItem=INVENTORY_GetItemFromBodyLoc(pInventory,i);
        if(pItem && ITEMS_GetItemQuality(pItem)==5 && !ITEMS_CheckItemFlag(pItem,0x100,0xac2,szItemModeCpp) && !ITEMS_CheckItemFlag(pItem,0x4000,0xac3,szItemModeCpp))
        {
            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(*(D2GameStrc* *)&pGame,pItem,pUnit,1,1);
            sITEMSAddStatsList(pGame,pItem,pUnit,1);
        }
    }
    sub_0055DA70_RestoreSelectedSkills(pUnit,&refreshState);
    UNITS_RefreshInventory(pUnit,1);
    if(bRefresh)
    {
        D2ClientStrc* pClient;
        if(pUnit->dwUnitType==0) pClient=UnitGetClient(pUnit,szItemModeCpp,0xa44);
        else
        {
            D2UnitStrc* pOwner=AIGENERAL_GetMinionOwner(pUnit);
            if(!pOwner || pOwner->dwUnitType!=0) return;
            pClient=UnitGetClient(pOwner,szItemModeCpp,0xa49);
        }
        if(pClient) D2GAME_SendPacket0x48_6FC3EF40(pClient,pUnit,0);
    }
}
