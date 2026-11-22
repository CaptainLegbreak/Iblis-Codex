#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2UnitData.h"

#define UNIT_PLAYER 0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define ITEMQUAL_NORMAL 2

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

struct D2CorpseStrc;

struct D2ItemsTxt;

struct D2PlayerDataStrc;

struct D2StaticPathStrc;

struct D2CharStatsTxt;

struct D2CharItemStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2CoordStrc;

struct D2DataTablesStrc;



void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

void __fastcall PLRINTRO_Destroy(D2GameStrc* pGame, D2PlrIntroStrc* pPlayerIntro); // 0x00572620

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630

D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005746D0

void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0

void __fastcall PLAYERLIST_FreePlayerLists(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055B790

void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057C980

void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555AE0

void __fastcall ARENA_FreeArenaUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0053F580

void __fastcall PLAYER_FreePlayerDataExtras(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00534880

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

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

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

int __fastcall ITEMMODE_PlaceCursorItemInBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6); // 0x0055E9B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall SCMD_SendInteractionTarget(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5); // 0x0053D6D0

void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00579130

void __fastcall OBJMODE_CloseObjectInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x005854D0

void __fastcall PLRTRADE_CloseCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567330

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue); // 0x00530EA0

void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pPortal); // 0x00553720

void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pPortal); // 0x0058CF50

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset); // 0x0061AED0

#define STAT_LEVEL 12

#define STAT_GOLD 14

#define STAT_GOLDLOST 175

struct D2DifficultyLevelsTxt;

unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __fastcall PLAYER_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue); // 0x00535510

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800

void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss); // 0x005391E0

static int __stdcall PLAYER_PlaceItemInInventory(D2GameStrc* pGame, int a8, D2UnitStrc* pItem, D2UnitStrc* pPlayer);

static int __stdcall PLAYER_EquipStartItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer);

static D2UnitStrc* __stdcall PLAYER_CreateStartItemStack(D2GameStrc* pGame, int nCount, int nItemId, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt);

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260

static void __stdcall PLAYER_ApplyDeathGoldLoss(D2GameStrc* pGame, D2UnitStrc* pKiller, D2UnitStrc* pPlayer);

void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer);

void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem);

int gnVirtualPlayerCount_6FD4DC1C; // 0x00883D70

static void __stdcall PLAYER_ApplyDeathExperienceLoss(D2GameStrc* pGame, D2UnitStrc* pDefender);

void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker);

// build: context sub_M08_PlaceStartItemInBelt
extern "C" const char gszEmptyAssertText; // 0x006CC837

void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0

// 0x00534840
static void PLAYER_FreePartyLifeList(D2GameStrc* pGame, D2PlayerDataStrc* pPlayerData)
{
    D2LifeSyncStrc* pNode = pPlayerData->pPartyLifeList;
    while (pNode)
    {
        D2LifeSyncStrc* pNext = pNode->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pNode, ".\\PLAYER\\Player.cpp", 43, 0);
        pNode = pNext;
    }
    pPlayerData->pPartyLifeList = 0;
}

// 0x00534880
void __fastcall PLAYER_FreePlayerDataExtras(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        PLAYER_FreePartyLifeList(pGame, pPlayerData);
        for (int i = 0; i < 3; ++i)
        {
            PLRINTRO_Destroy(pGame, pPlayerData->pPlayerIntro[i]);
            pPlayerData->pPlayerIntro[i] = 0;
        }
    }
}

// 0x00534970
static void sub_00534970_RemoveCorpseUnits(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pUnit)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (pRoom)
            {
                const int guid=(pUnit ? pUnit->dwUnitId : -1);
                DUNGEON_AllocDrlgDelete(pRoom, pUnit->dwUnitType, guid);
            }
            SUNIT_RemoveUnit(pGame, pUnit);
        }
    }
}

// 0x005349D0
void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    PLAYERPETS_FreePetsFromPlayerData(pGame, pPlayer);
    PARTY_LeaveParty(pGame, pPlayer);
    PLAYERLIST_FreePlayerLists(pGame, pPlayer);
    SUNITDMG_FreeAttackerCombatList(pGame, pPlayer);
    sub_00534970_RemoveCorpseUnits(pGame, pPlayer);
    SUNIT_RemoveAllItemsFromInventory(pGame, pPlayer);
    INVENTORY_FreeInventory(pPlayer->pInventory);
    ARENA_FreeArenaUnit(pGame, pPlayer);
    PLAYER_FreePlayerDataExtras(pGame, pPlayer);
    UNITS_FreePlayerData(pGame->pMemoryPool, pPlayer);
    if (pPlayer->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pPlayer->pHoverText);
    }
    EVENT_FreeUnitTimers(pGame, pPlayer);
}

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
static int __stdcall PLAYER_PlaceItemInInventory(D2GameStrc* pGame, int a8, D2UnitStrc* hItem, D2UnitStrc* hPlayer)
{
    D2_ASSERT(hItem, 180);
    D2_ASSERT(hPlayer, 181);
    ITEMS_SetInvPage(hItem, INVPAGE_INVENTORY);
    const int nItemGUID = hItem->dwUnitId;
    return D2GAME_PlaceItem_6FC44410(".\\PLAYER\\Player.cpp", 186, pGame, hPlayer, nItemGUID, CLIENTS_GetUnitX(hItem), CLIENTS_GetUnitY(hItem), a8, 1, 0) != 0;
}

// 0x00534BB0
static int __stdcall PLAYER_EquipStartItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
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
    return ITEMMODE_PlaceCursorItemInBelt(pGame, pPlayer, nItemGUID, nX, bFindFreeSlot, &nUnused) != 0;
}

// 0x00534C10
static int __stdcall PLAYER_PlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int bFindFreeSlot)
{
    D2_ASSERT(pItem, 216);
    D2_ASSERT(pPlayer, 217);
    const int nItemGUID = pItem->dwUnitId;
    int nUnused;
    return ITEMMODE_PlaceCursorItemInBelt(pGame, pPlayer, nItemGUID, CLIENTS_GetUnitX(pItem), bFindFreeSlot, &nUnused) != 0;
}

// 0x00534C70
static D2UnitStrc* __stdcall PLAYER_CreateStartItemStack(D2GameStrc* pGame, int nCount, int nItemId, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt)
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
                pStartItemStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, 0x40, 0, UNIT_ITEM, !pItem ? -1 : pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStartItemStatList, 1);
            }
            const int nLayer = (unsigned short)pCharStatsTxt->wStartSkill;
            STATLIST_SetStatIfListIsValid(pStartItemStatList, STAT_ITEM_SINGLESKILL, 1, nLayer);
        }
        if (ITEMS_CheckIfStackable(pItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nMaxStack, 0);
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
        D2UnitStrc* pItem = PLAYER_CreateStartItemStack(pGame, nCount, nItemId, pPlayer, pCharStatsTxt);
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
            if (!PLAYER_EquipStartItem(pGame, pItem, pPlayer))
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

int __fastcall sub_K10_EmitPlaceStartItemInBelt(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    return PLAYER_PlaceStartItemInBelt(pGame, pPlayer, pItem, 1);
}

// 0x005351C0
void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2UnitStrc* pInteractUnit;
    int nInteractUnitId;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && (pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID)) != 0)
    {
        {
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                D2GAME_NPC_ResetInteract_6FCCB4D0(pGame, pUnit, pInteractUnit);
                nInteractUnitId = pInteractUnit->dwUnitId;
                SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x202), 0x62, UNIT_MONSTER, nInteractUnitId, 0);
                return;

            case UNIT_OBJECT:
                OBJMODE_CloseObjectInteraction(pGame, pUnit, pInteractUnit);
                nInteractUnitId = pInteractUnit->dwUnitId;
                SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x206), 0x62, UNIT_OBJECT, nInteractUnitId, 0);
                return;

            case UNIT_PLAYER:
                sub_6FC91250(pGame, pUnit, 6, 0);
                return;

            case UNIT_ITEM:
                if (DATATBLS_GetItemsTxtRecord(pInteractUnit->dwClassId)->dwCode == ' xob')
                {
                    PLRTRADE_CloseCubeInteraction(pGame, pUnit);
                    nInteractUnitId = pInteractUnit->dwUnitId;
                    SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x211), 0x62, UNIT_ITEM, nInteractUnitId, 0);
                }
                return;
            }
        }
    }

    SCMD_SendInteractionTarget(UnitGetClient(pUnit, ".\\PLAYER\\Player.cpp", 0x217), 0x62, UNIT_INVALID, 0, 0);
}

// 0x005353B0
void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* pPlayer, int nUnitGUID)
{
    D2_ASSERT(pPlayer, 0x240);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x243);

    pPlayerData->dwUniqueId = nUnitGUID;
}

// 0x00535430
void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
	D2_ASSERT(pPlayer, 602);

	D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
	D2_ASSERT(pPlayerData, 605);

	D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, pPlayerData->dwUniqueId);
	if (!pPortal || pPortal->dwClassId != 59)
	{
		return;
	}

	ACT5Q5_OnPortalClosed(pGame, pPortal);

	D2UnitStrc* pOwner = SUNIT_GetPortalOwner(pGame, pPortal);
	D2ActiveRoomStrc* pPortalRoom = UNITS_GetRoom(pPortal);
	if (pPortalRoom)
	{
		DUNGEON_AllocDrlgDelete(pPortalRoom, 2, !pPortal ? -1 : pPortal->dwUnitId);
	}

	SUNIT_RemoveUnit(pGame, pPortal);
	DUNGEON_ToggleHasPortalFlag(pPortalRoom, 1);

	if (!pOwner)
	{
		return;
	}

	ACT5Q5_OnPortalClosed(pGame, pOwner);

	D2ActiveRoomStrc* pOwnerRoom = UNITS_GetRoom(pOwner);
	if (pOwnerRoom)
	{
		DUNGEON_AllocDrlgDelete(pOwnerRoom, 2, !pOwner ? -1 : pOwner->dwUnitId);
	}

	SUNIT_RemoveUnit(pGame, pOwner);
	DUNGEON_ToggleHasPortalFlag(pOwnerRoom, 1);
}

// 0x00535510
int __fastcall PLAYER_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue)
{
    if (SUNIT_GetServerUnit(pGame, 0, nUnitGUID) != pUnit)
    {
        return 0;
    }

    if (nValue > STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0))
    {
        return 0;
    }

    if (nValue < 0)
    {
        return 0;
    }

    if (nValue > (int)UNITS_GetInventoryGoldLimit(pUnit))
    {
        return 0;
    }

    const unsigned int nAmount = nValue;
    if (nAmount > 0)
    {
        D2CoordStrc tCoord;
        UNITS_GetCoords(pUnit, &tCoord);

        unsigned int nGoldValue = nAmount;
        if (nAmount > 2000000000)
        {
            nGoldValue = 2000000000;
        }

        D2UnitStrc* pGoldPiles[0x20];
        int nCount = 0;
        ITEMS_DropGoldPiles(pGame, pUnit, nGoldValue, pGoldPiles, &nCount, 0x20);
        if (nCount)
        {
            for (int i = 0; i < nCount; ++i)
            {
                D2UnitStrc* pItem = pGoldPiles[i];
                if (pUnit && sub_0044BE50_GetUnitTypeOrInvalid(pUnit) == 0)
                {
                    UNITS_StoreOwner(pItem, pUnit);
                }

                const int nPileGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
                D2GAME_SetStatOrResetGold_6FC7CA70(pUnit, 0xE, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) - nPileGold);
            }
        }
    }

    return 1;
}

// 0x005356B0
int __fastcall PLAYER_SetSkillHotKey(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, unsigned char nHand, int nFlags)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\Player.cpp", 755);
    if (!pClient)
    {
        return 0;
    }

    CLIENTS_SetSkillHotKey(pClient, nHotkeyId, nSkillId, nHand, nFlags);
    return 1;
}

// 0x00535780
void __fastcall PLAYER_SetVirtualPlayerCount(int nPlayers)
{
    if (nPlayers >= 0 && nPlayers <= 8)
    {
        gnVirtualPlayerCount_6FD4DC1C = nPlayers;
    }
}

// build: context PLAYER_SetStatOrResetGold
static inline void PLAYER_SetStatOrResetGold(D2UnitStrc* pUnit, int nStat, int nValue)
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
        if (nStat == 14)
        {
            if (nValue > (int)UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
        }
        else if (nStat == 15)
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

// 0x005357D0
static void __stdcall PLAYER_ApplyDeathGoldLoss(D2GameStrc* pGame, D2UnitStrc* pKiller, D2UnitStrc* pPlayer)
{
    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nGold = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0);
    const int nStash = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0);
    const int nTotal = nStash + nGold;
    const int nPercent = nLevel < 20 ? nLevel : 20;
    const int nMinimum = nLevel * 500;
    int nLoss = nPercent * nTotal / 100;
    const int nKeep = nTotal - nLoss;

    int bPlayerKill = 0;
    if (pKiller && pKiller != pPlayer)
    {
        if (pKiller->dwUnitType == UNIT_PLAYER)
        {
            bPlayerKill = 1;
        }
        else if (pKiller->dwUnitType == UNIT_MONSTER)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pKiller);
            if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
            {
                bPlayerKill = 1;
            }
        }
    }

    if (pGame->nGameType == 3)
    {
        if (nKeep < nMinimum)
        {
            nLoss = nTotal - nMinimum;
            if (nLoss < 0)
            {
                nLoss = 0;
            }
        }

        if (nLoss > nGold)
        {
            nLoss = nGold;
        }
    }

    if (bPlayerKill)
    {
        if (nLoss > nGold)
        {
            PLAYER_SetStatOrResetGold(pPlayer, 15, nStash - nLoss + nGold);
            PLAYER_SetStatOrResetGold(pPlayer, 14, nLoss);
        }

        PLAYER_DropGold(pGame, pPlayer, !pPlayer ? -1 : pPlayer->dwUnitId, nLoss);
    }
    else
    {
        if (!(nLoss > nGold))
        {
            const int nDrop = nGold - nLoss;
            PLAYER_DropGold(pGame, pPlayer, !pPlayer ? -1 : pPlayer->dwUnitId, nDrop);
        }
        else
        {
            if (pGame->nGameType != 3)
            {
                PLAYER_SetStatOrResetGold(pPlayer, 15, nStash - nLoss + nGold);
            }
        }

        PLAYER_SetStatOrResetGold(pPlayer, 14, 0);
    }

    PLAYER_SetStatOrResetGold(pPlayer, 0xAF, nLoss);
}


// 0x005359F0
static void __stdcall PLAYER_ApplyDeathExperienceLoss(D2GameStrc* pGame, D2UnitStrc* pDefender)
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
    PLAYER_ApplyDeathGoldLoss(pGame, pAttacker, pDefender);
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
    PLAYER_ApplyDeathExperienceLoss(pGame, pDefender);
}

