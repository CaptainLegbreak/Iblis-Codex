#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
struct D2GameStrc;
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define ITEMQUAL_NORMAL 2
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define STAT_GOLD 14
#define STAT_GOLDLOST 175
struct D2ItemsTxt;
struct D2StaticPathStrc;
struct D2CharStatsTxt;
struct D2CharItemStrc;
struct D2DifficultyLevelsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
int __fastcall sub_6FC48940(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6); // 0x0055E9B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue); // 0x00535510
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss); // 0x005391E0

inline int M08_UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// 0x00534B30
static int __stdcall PLAYER_PlaceItemInInventory(D2GameStrc* pGame, int a8, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pItem, 180);
    D2_ASSERT(pPlayer, 181);
    ITEMS_SetInvPage(pItem, INVPAGE_INVENTORY);
    const int nItemGUID = pItem->dwUnitId;
    return D2GAME_PlaceItem_6FC44410(".\\PLAYER\\Player.cpp", 186, pGame, pPlayer, nItemGUID, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), a8, 1, 0) != 0;
}

// 0x00534BB0
static int __stdcall sub_00534BB0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pItem, 198);
    D2_ASSERT(pPlayer, 199);
    const int nItemGUID = pItem->dwUnitId;
    int nUnused;
    return ITEMMODE_EquipCursorItem(pGame, pPlayer, nItemGUID, ITEMS_GetBodyLocation(pItem), 1, &nUnused) != 0;
}

static __forceinline int __stdcall sub_M08_PlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int bFindFreeSlot)
{
    D2_ASSERT(pItem, 216);
    D2_ASSERT(pPlayer, 217);
    int nUnused;
    const int nX = M08_UNITS_GetXPositionInline(pItem);
    const int nItemGUID = pItem->dwUnitId;
    return sub_6FC48940(pGame, pPlayer, nItemGUID, nX, bFindFreeSlot, &nUnused) != 0;
}

static D2UnitStrc* __stdcall sub_00534C70(D2GameStrc* pGame, int nCount, int nItemId, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt)
{
    if (!pPlayer)
    {
        return 0;
    }
    const int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pPlayer, nItemId, pGame, 4, ITEMQUAL_NORMAL, 1, 1, nItemLevel, 0, 0, 0);
    if (pItem)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (pStatList)
        {
            D2Common_10474(pItem, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
        if (!nCount && pCharStatsTxt->wStartSkill >= 0 && pCharStatsTxt->wStartSkill < sgptDataTables->nSkillsTxtRecordCount)
        {
            D2StatListStrc* pStartItemStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
            if (!pStartItemStatList)
            {
                pStartItemStatList = STATLIST_AllocStatList(pItem->pMemoryPool, 0x40, 0, UNIT_ITEM, pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStartItemStatList, 1);
            }
            STATLIST_SetStatIfListIsValid(pStartItemStatList, STAT_ITEM_SINGLESKILL, 1, pCharStatsTxt->wStartSkill);
        }
        if (ITEMS_CheckIfStackable(pItem))
        {
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pItem), 0);
        }
    }
    return pItem;
}

// 0x00534D60
void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem)
{
    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(pCharItem->dwItemCode, &nItemId))
    {
        return;
    }
    for (int i = 0; i < pCharItem->nItemCount; ++i)
    {
        D2UnitStrc* pItem = sub_00534C70(pGame, nCount, nItemId, pPlayer, pCharStatsTxt);
        ITEMS_SetItemFlag(pItem, IFLAG_STARTITEM, 1);
        ITEMS_SetBodyLocation(pItem, pCharItem->nBodyLoc);
        if (ITEMS_CheckIfBeltable(pItem))
        {
            if (!sub_M08_PlaceStartItemInBelt(pGame, pPlayer, pItem, 1))
            {
                PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            }
        }
        else if (pCharItem->nBodyLoc)
        {
            if (!sub_00534BB0(pGame, pItem, pPlayer))
            {
                PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            }
            if (ITEMSIsA(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 250, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
            }
        }
        else
        {
            PLAYER_PlaceItemInInventory(pGame, 1, pItem, pPlayer);
            if (ITEMSIsA(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 250, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
            }
            if (ITEMSIsA(pItem, ITEMTYPE_BOW_QUIVER))
            {
                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 100, 0);
            }
        }
    }
}

static void D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }
    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (nStat == STAT_GOLD)
        {
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
        }
        else if (nStat == STAT_GOLDBANK)
        {
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
        }
    }
    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

static void __stdcall sub_005357D0_ApplyDeathGoldPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, STAT_LEVEL, 0);
    const int nDefenderInventoryGold = STATLIST_UnitGetStatValue(pDefender, STAT_GOLD, 0);
    const int nDefenderBankGold = STATLIST_UnitGetStatValue(pDefender, STAT_GOLDBANK, 0);
    const int nDefenderTotalGold = nDefenderBankGold + nDefenderInventoryGold;
    const int nPenaltyPercentage = nDefenderLevel < 20 ? nDefenderLevel : 20;
    int nGoldPenalty = nDefenderTotalGold * nPenaltyPercentage / 100;
    int bAttackedByAnotherPlayer = 0;
    if (pAttacker && pAttacker != pDefender)
    {
        if (pAttacker->dwUnitType == UNIT_PLAYER)
        {
            bAttackedByAnotherPlayer = 1;
        }
        else if (pAttacker->dwUnitType == UNIT_MONSTER)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
            if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
            {
                bAttackedByAnotherPlayer = 1;
            }
        }
    }
    if (pGame->nGameType == 3)
    {
        if (nDefenderTotalGold - nGoldPenalty < 500 * nDefenderLevel)
        {
            nGoldPenalty = nDefenderTotalGold - 500 * nDefenderLevel;
            if (nGoldPenalty < 0)
            {
                nGoldPenalty = 0;
            }
        }
        if (nGoldPenalty > nDefenderInventoryGold)
        {
            nGoldPenalty = nDefenderInventoryGold;
        }
    }
    if (bAttackedByAnotherPlayer)
    {
        if (nGoldPenalty > nDefenderInventoryGold)
        {
            D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLDBANK, nDefenderInventoryGold + nDefenderBankGold - nGoldPenalty);
            D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLD, nGoldPenalty);
        }
        sub_6FC7C260(pGame, pDefender, !pDefender ? -1 : pDefender->dwUnitId, nGoldPenalty);
    }
    else
    {
        if (nGoldPenalty > nDefenderInventoryGold)
        {
            if (pGame->nGameType != 3)
            {
                D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLDBANK, nDefenderInventoryGold + nDefenderBankGold - nGoldPenalty);
            }
        }
        else
        {
            sub_6FC7C260(pGame, pDefender, !pDefender ? -1 : pDefender->dwUnitId, nDefenderInventoryGold - nGoldPenalty);
        }
        D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLD, 0);
    }
    D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLDLOST, nGoldPenalty);
}

// 0x005359F0
static void __stdcall sub_005359F0(D2GameStrc* pGame, D2UnitStrc* pDefender)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    const int nClassId = !pDefender ? -1 : pDefender->dwClassId;
    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, STAT_LEVEL, 0);
    if (nDefenderLevel > 1)
    {
        const unsigned int nPreviousExpThreshold = DATATBLS_GetLevelThreshold(nClassId, nDefenderLevel - 1);
        const unsigned int nCurrentExpThreshold = DATATBLS_GetLevelThreshold(nClassId, nDefenderLevel);
        const unsigned int nExpRange = nCurrentExpThreshold - nPreviousExpThreshold;
        int nNewExperienceValue = STATLIST_UnitGetStatValue(pDefender, STAT_EXPERIENCE, 0);
        int nExperiencePenalty = pDifficultyLevelsTxtRecord->dwDeathExpPenalty * nExpRange / 100;
        if (nExperiencePenalty)
        {
            nNewExperienceValue -= nExperiencePenalty;
            if (nNewExperienceValue <= nPreviousExpThreshold)
            {
                nExperiencePenalty += nNewExperienceValue - nPreviousExpThreshold;
                if (nExperiencePenalty < 0)
                {
                    nExperiencePenalty = 0;
                }
                nNewExperienceValue = nPreviousExpThreshold + 1;
            }
            CLIENTS_SetExperienceLoss(UnitGetClient(pDefender, ".\\PLAYER\\Player.cpp", 0x3C4), nExperiencePenalty);
            STATLIST_SetUnitStat(pDefender, STAT_EXPERIENCE, nNewExperienceValue, 0);
        }
    }
}

// 0x00535AB0
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    sub_005357D0_ApplyDeathGoldPenalty(pGame, pDefender, pAttacker);
    if (pAttacker)
    {
        if (pAttacker->dwUnitType == UNIT_PLAYER)
        {
            return;
        }
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            return;
        }
    }
    sub_005359F0(pGame, pDefender);
}
