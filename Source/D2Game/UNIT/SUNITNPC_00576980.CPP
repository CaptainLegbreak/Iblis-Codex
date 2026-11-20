#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Path.h"

#define STAT_LEVEL 12
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define STORE_LEVEL_BONUS 5
#define STORE_HIGH_LEVEL 25
#define ITEM_VERSION_EXPANSION 100
#define STORE_MAX_FAILED_ITEMS 32
#define ITEMCODE_CROSSBOW_BOLTS ' vqc'
#define ITEMCODE_ARROWS ' vqa'
#define FILLSTORE_ASSERT_LINE 713
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define IFLAG_SOCKETED 0x800
union D2SeedStrc;
struct Obj00536B40;
struct D2ItemsTxt;
struct D2ItemCacheStrc;
struct D2UnitProxyStrc;
struct D2NpcTradeStrc;
struct D2NpcRecordStrc;
struct D2MonsterDataStrc;
struct D2PlayerDataStrc;
struct D2MonStatsTxt;
struct D2GSPacketSrv58;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char f_74[0x04];
    unsigned short wItemFormat;
    unsigned char unk_7A[0x2];
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char bHireInit;
    unsigned char nAct;
    unsigned char bTrader;
    char unk0x04[0x04];
    unsigned int dwTicks;
    D2UnitProxyStrc pProxy;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x20];
    D2NpcTradeStrc npcTrade;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260


int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500


D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
extern "C" unsigned int __fastcall sub_00536B40(Obj00536B40* pObj); // 0x00536B40
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel); // 0x00576890
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId); // 0x00629C80
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
D2UnitStrc* __fastcall D2GAME_NPC_GenerateStoreItem_6FCC6A60(D2UnitStrc* pNpc, unsigned int dwCode, D2GameStrc* pGame, int bVendorItem, int nQuality, int nItemLevel, int nPlayerLevel); // 0x00576330
int __fastcall sub_00576900_RollStoreItemQuality(D2SeedStrc* pSeed, unsigned int dwCode, int nItemLevel);
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2PlayerDataStrc
{
    char szName[16];
};


struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};



#pragma pack(push, 1)
struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nAction;
};

#pragma pack(pop)

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
void __fastcall QUESTS_ActChange_HirelingChangeAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int nNewLevel, int nOldLevel); // 0x005467E0
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50
void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDestLevel, int nTileCalc); // 0x0054B830
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSound, D2UnitStrc* pTarget); // 0x00553380
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevel); // 0x00558200
void __fastcall ITEMS_FillItemDrop(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x00558270
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pOwner, int a4); // 0x0055A2A0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0055FE00
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, int a6, int a7, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
void __fastcall ITEMMODE_DropCursorItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID); // 0x00563C00
void __fastcall sub_00570360(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00570360
void __fastcall sub_00570C80_PLAYERSTATS_ResetToBaseStats(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00570C80
void __fastcall sub_00572EA0_AdvanceInteraction(D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00572EA0
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bSingle); // 0x00576770
static int __stdcall sub_00578610_IsCursorItem(unsigned int nItemGUID, D2UnitStrc* pUnit); // 0x00578610
void __fastcall D2GAME_STORES_CreateVendorCache_6FCC74F0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bRefresh, int bGamble); // 0x00579430
void __fastcall ACT5Q1_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005877C0
void __fastcall ACT5Q4_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0058BC00
void __fastcall sub_0058FD20_ACT1Q1_SetRespecRewardPending(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0058FD20
void __fastcall sub_0058FD50_ACT1Q1_SetRespecRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0058FD50
void __fastcall ACT1Q3_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00591790
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoords); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
int __stdcall ITEMS_CheckIfFlagIsSet(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BCB0
int __stdcall sub_0062C590(D2UnitStrc* pItem); // 0x0062C590
int __stdcall ITEMS_IsPersonalizable(D2UnitStrc* pItem); // 0x0062C6A0
int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem); // 0x0062C770
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuest, int nState); // 0x0065C310
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, int* pWaypointNo); // 0x00660E00
void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, int nWaypointNo); // 0x00660EC0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

// 0x00576980
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade)
{
    D2SeedStrc* pSeed = (D2SeedStrc*)sub_00536B40((Obj00536B40*)pGame);

    pTrade->dwTicks = GetTickCount();

    int nNpcIndex;
    int nSpawnedItems = 0;
    int i;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nNpcIndex);
    if (pNpcRecord)
    {
    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nItemLevel = sub_00576890(pGame, pNpc, nLevel + STORE_LEVEL_BONUS);

    for (i = 0; i < pNpcRecord->npcTrade.pProxy.nItems; ++i)
    {
        int nUnused;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pItemCache[i].dwCode, &nUnused);
        if (pItemsTxtRecord->nLevel <= nItemLevel)
        {
            unsigned int nNormalItems;
            if (nItemLevel >= STORE_HIGH_LEVEL)
            {
                nNormalItems = 0;
            }
            else
            {
                nNormalItems = OBJECTS_RollRandomNumber(pSeed, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMin, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMax + 1);
            }

            if (pItemsTxtRecord->wVersion < ITEM_VERSION_EXPANSION || pGame->wItemFormat >= ITEM_VERSION_EXPANSION)
            {
                for (unsigned int j = 0; j < nNormalItems; ++j)
                {
                    const int nQuality = sub_00576900_RollStoreItemQuality(pSeed, pNpcRecord->npcTrade.pProxy.pItemCache[i].dwCode, nItemLevel);
                    if (!D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->npcTrade.pProxy.pItemCache[i].dwCode, pGame, 1, nQuality, nItemLevel, nLevel))
                    {
                        ++nSpawnedItems;
                    }

                    if (nSpawnedItems > STORE_MAX_FAILED_ITEMS)
                    {
                        return;
                    }
                }

                int nItemId;
                DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pItemCache[i].dwCode, &nItemId);
                if (ITEMS_CheckBitField1Flag1(nItemId) == 1 && pTrade->pProxy.pItemCache[i].nMagicLevel <= nItemLevel)
                {
                    int nMinItems = 1;
                    if (nItemLevel >= STORE_HIGH_LEVEL)
                    {
                        nMinItems = OBJECTS_RollRandomNumber(pSeed, 1, 3) + 1;
                    }

                    const unsigned int nMagicItems = OBJECTS_RollRandomNumber(pSeed, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMagicMin, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMagicMax + nMinItems);
                    for (unsigned int j = 0; j < nMagicItems; ++j)
                    {
                        if (!D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->npcTrade.pProxy.pItemCache[i].dwCode, pGame, 1, ITEMQUAL_MAGIC, nItemLevel, nLevel))
                        {
                            ++nSpawnedItems;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < pNpcRecord->npcTrade.pProxy.nPerms; ++i)
    {
        D2UnitStrc* pStoreItem = D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->npcTrade.pProxy.pPermCache[i], pGame, 1, ITEMQUAL_NORMAL, nItemLevel, nLevel);
        if (pStoreItem)
        {
            int nUnused;
            const unsigned int nItemCode = DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pPermCache[i], &nUnused)->dwCode;
            if (nItemCode == ITEMCODE_CROSSBOW_BOLTS || nItemCode == ITEMCODE_ARROWS)
            {
                STATLIST_SetUnitStat(pStoreItem, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pStoreItem), 0);
            }
        }
        else
        {
            ++nSpawnedItems;
        }

        if (nSpawnedItems > STORE_MAX_FAILED_ITEMS)
        {
            break;
        }
    }
    }
    else
    {
        D2_ASSERT(0, FILLSTORE_ASSERT_LINE);
    }
}

// 0x00576C90
int __fastcall sub_00576C90_RollTraderItemCode(D2GameStrc* pGame, D2UnitStrc* pNpc, D2SeedStrc* pSeed, int nUnused, unsigned int* pCode, int* pIndex)
{
    int nIndex = *pIndex;
    int nNpcIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nNpcIndex);
    if (pNpcRecord)
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->npcTrade;
        if (pTrade && pTrade->bTrader && pTrade->pProxy.nItems && pTrade->pProxy.pItemCache)
        {
            int nItemId = ITEMS_RollLimitedRandomNumber(pSeed, pTrade->pProxy.nItems);
            pSeed->lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;

            const int nRand = nItemId;
            DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pItemCache[nRand].dwCode, &nItemId);
            ITEMS_CheckBitField1Flag1(nItemId);
            *pCode = pTrade->pProxy.pItemCache[nRand].dwCode;
            *pIndex = nIndex;
            return 1;
        }

        D2_ASSERT(pTrade, 899);
        D2_ASSERT(pTrade->bTrader, 900);
    }

    D2_ASSERT(pNpcRecord, 905);
    *pCode = 0;
    return 0;
}

static __declspec(noinline) int __stdcall sub_00578610_IsCursorItem(unsigned int nItemGUID, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
        if (pItem)
        {
            const unsigned int nId = pItem->dwUnitId;
            if (nId == nItemGUID)
            {
                return 1;
            }
        }
    }

    return 0;
}

static __forceinline int MONSTERS_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x00579D60
int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID)
{
    D2UnitStrc* pMonster = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcGUID);
    if (!pMonster || !pPlayer)
    {
        return 0;
    }

    const int nClassId = pMonster->dwClassId;
    if (!MONSTERS_CheckMonStatsFlag(nClassId, 9) || pMonster->dwUnitType != UNIT_MONSTER
        || !pMonster->pMonsterData || !pMonster->pMonsterData->pMonInteract)
    {
        return 0;
    }

    int nWpNo;
    int bRefreshInventory = 0;
    if (MONSTERAI_GetInteractUnitCount(pMonster->pMonsterData->pMonInteract) == 1)
    {
        bRefreshInventory = 1;
    }

    if (nType == 1)
    {
        switch ((unsigned int)pMonster->dwClassId)
        {
        case 0x93:
        case 0x94:
        case 0x9A:
        case 0xB1:
        case 0xB2:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFD:
        case 0xFE:
        case 0xFF:
        case 0x101:
        case 0x195:
        case 0x1FF:
        case 0x200:
        case 0x201:
            sub_00572EA0_AdvanceInteraction(pMonster, pPlayer);
            D2GAME_STORES_CreateVendorCache_6FCC74F0(pGame, pPlayer, pMonster, bRefreshInventory, 0);
            break;
        }
        return 0;
    }

    if (nType == 2)
    {
        switch ((unsigned int)pMonster->dwClassId)
        {
        case 0x93:
        case 0xC7:
        case 0xFE:
        case 0x195:
        case 0x200:
        case 0x202:
            sub_00572EA0_AdvanceInteraction(pMonster, pPlayer);
            D2GAME_STORES_CreateVendorCache_6FCC74F0(pGame, pPlayer, pMonster, bRefreshInventory, 1);
            break;
        }
        return 0;
    }

    if (nType == 3)
    {
        D2GAME_NPC_BuildHirelingList_6FCC6FF0(pGame, UnitGetClient(pPlayer, gszNpcSource_006E15F0, 0xB50), pMonster,
            MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pMonster)) <= 1);
        return 0;
    }

    if (nClassId == 0x9A)
    {
        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        packet58.nUnitId = nNpcGUID;

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszNpcSource_006E15F0, 0xB59);
        if (!sub_00578610_IsCursorItem(nItemGUID, pPlayer))
        {
            return 3;
        }

        D2UnitStrc* pInput = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 3, 1))
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (!pInput)
        {
            return 0;
        }

        if (!sub_0062C590(pInput))
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        D2ItemDropStrc itemDrop;
        ITEMS_FillItemDrop(pGame, &itemDrop, pInput);

        itemDrop.dwFlags2 |= 0x20 | (ITEMS_IsEthereal(pInput) != 0 ? 4 : 2);
        itemDrop.wItemFormat = pGame->wItemFormat;

        bool bInputIsPersonalized = false;
        char szName[100];
        if (ITEMS_CheckIfFlagIsSet(ITEMS_GetItemFlags(pInput), IFLAG_PERSONALIZED))
        {
            bInputIsPersonalized = true;
            strcpy(szName, ITEMS_GetEarName(pInput));
        }

        if (D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pInput))
        {
            itemDrop.nQuality = 6;
            int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
            if (nItemLevel > 5)
            {
                nItemLevel += 4;
            }
            itemDrop.nItemLvl = nItemLevel;

            D2UnitStrc* pOutput = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
            if (!pOutput)
            {
                packet58.nAction = 7;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                return 0;
            }

            D2GAME_NPC_RepairItem_6FCC6970(pGame, pOutput, 0);
            ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pOutput, pPlayer);
            ITEMS_SetInvPage(pOutput, 0);

            if (bInputIsPersonalized)
            {
                ITEMS_SetItemFlag(pOutput, IFLAG_PERSONALIZED, 1);
                ITEMS_SetEarName(pOutput, szName);
            }

            const int nOutputGUID = pOutput->dwUnitId;
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSource_006E15F0, 0xBA9, pGame, pPlayer, nOutputGUID, 0, 0, 1, 1, 0))
            {
                UNITS_ChangeAnimMode(pOutput, 3);
                D2CoordStrc coords;
                UNITS_GetCoords(pPlayer, &coords);
                D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pPlayer);
                D2CoordStrc returnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pPlayerRoom, &coords, &returnCoords, 1, 1);
                D2GAME_DropItem_6FC52260(pGame, 0, pOutput, pRoom, returnCoords.nX, returnCoords.nY);
            }

            ACT1Q3_SetRewardGranted(pGame, pPlayer);
            packet58.nAction = 6;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            return 0;
        }

        packet58.nAction = 7;
        sub_0053D8D0_SendPacket0x58(pClient, &packet58);
        ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        return 0;
    }
    else if (nClassId == 0x94)
    {
        if (pGame->nDifficulty == 2
            && QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 1, 0) == 1
            && !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x29, 1)
            && !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x29, 0))
        {
            sub_0058FD20_ACT1Q1_SetRespecRewardPending(pGame, pPlayer);
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x29, 1))
        {
            sub_00570360(pGame, pPlayer);
            sub_00570C80_PLAYERSTATS_ResetToBaseStats(pGame, pPlayer);
            SUNIT_AttachSound(pPlayer, 2, pPlayer);
            sub_0058FD50_ACT1Q1_SetRespecRewardGranted(pGame, pPlayer);
        }
        return 0;
    }
    else if (nClassId == 0x1FF)
    {
        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        packet58.nUnitId = nNpcGUID;

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszNpcSource_006E15F0, 0xBE2);
        if (!sub_00578610_IsCursorItem(nItemGUID, pPlayer))
        {
            return 3;
        }

        D2UnitStrc* pInput = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x23, 1))
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (!pInput)
        {
            return 0;
        }

        if (!ITEMS_IsSocketable(pInput))
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        D2UnitStrc* pOutput = ITEMS_Duplicate(pGame, pInput, pPlayer, 1);
        if (!pOutput)
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pInput))
        {
            ITEMS_SetItemFlag(pOutput, IFLAG_SOCKETED, 1);

            int nSockets = sub_0062BC20(pOutput);
            switch (ITEMS_GetItemQuality(pOutput))
            {
            case 4:
                if (nSockets >= 2)
                {
                    nSockets = 2;
                }

                nSockets = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pOutput), nSockets) + 1;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                if (nSockets >= 1)
                {
                    nSockets = 1;
                }
                break;
            }

            ITEMS_AddSockets(pOutput, nSockets);

            D2GAME_NPC_RepairItem_6FCC6970(pGame, pOutput, 0);
            ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pOutput, pPlayer);
            ITEMS_SetInvPage(pOutput, 0);

            const int nOutputGUID = pOutput->dwUnitId;
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSource_006E15F0, 0xC36, pGame, pPlayer, nOutputGUID, 0, 0, 1, 1, 0))
            {
                UNITS_ChangeAnimMode(pOutput, 3);
                D2CoordStrc coords;
                UNITS_GetCoords(pPlayer, &coords);
                D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pPlayer);
                D2CoordStrc returnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pPlayerRoom, &coords, &returnCoords, 1, 1);
                D2GAME_DropItem_6FC52260(pGame, 0, pOutput, pRoom, returnCoords.nX, returnCoords.nY);
            }

            ACT5Q1_SetRewardGranted(pGame, pPlayer);
            packet58.nAction = 6;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            return 0;
        }

        packet58.nAction = 7;
        sub_0053D8D0_SendPacket0x58(pClient, &packet58);
        ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        return 0;
    }
    else if (nClassId == 0x200)
    {
        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        packet58.nUnitId = nNpcGUID;

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszNpcSource_006E15F0, 0xC57);
        if (!sub_00578610_IsCursorItem(nItemGUID, pPlayer))
        {
            return 3;
        }

        D2UnitStrc* pInput = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x26, 1))
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (!pInput)
        {
            return 0;
        }

        if (!ITEMS_IsPersonalizable(pInput))
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        D2UnitStrc* pOutput = ITEMS_Duplicate(pGame, pInput, pPlayer, 1);
        if (!pOutput)
        {
            packet58.nAction = 7;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        }

        if (D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pInput))
        {
            D2GAME_NPC_RepairItem_6FCC6970(pGame, pOutput, 0);
            ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pOutput, pPlayer);
            ITEMS_SetInvPage(pOutput, 0);

            const int nOutputGUID = UNITS_GetUnitId(pOutput);
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSource_006E15F0, 0xC91, pGame, pPlayer, nOutputGUID, 0, 0, 1, 1, 0))
            {
                UNITS_ChangeAnimMode(pOutput, 3);
                D2CoordStrc coords;
                UNITS_GetCoords(pPlayer, &coords);
                D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pPlayer);
                D2CoordStrc returnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pPlayerRoom, &coords, &returnCoords, 1, 1);
                D2GAME_DropItem_6FC52260(pGame, 0, pOutput, pRoom, returnCoords.nX, returnCoords.nY);
            }

            ITEMS_SetItemFlag(pOutput, IFLAG_PERSONALIZED, 1);
            ITEMS_SetEarName(pOutput, UNITS_GetPlayerData(pPlayer)->szName);
            ACT5Q4_SetRewardGranted(pGame, pPlayer);

            packet58.nAction = 6;
            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            return 0;
        }

        packet58.nAction = 7;
        sub_0053D8D0_SendPacket0x58(pClient, &packet58);
        ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        return 0;
    }
    else if (nClassId == 0x9B)
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 6, 0))
        {
            return 0;
        }

        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x28, 0);
        QUESTS_ActChange_HirelingChangeAct(pGame, pPlayer, pMonster, 0x28, 1);

        if (WAYPOINTS_GetWaypointNoFromLevelId(0x28, &nWpNo))
        {
            WAYPOINTS_ActivateWaypoint(sub_00547F50(pGame, pPlayer), nWpNo);
        }
        return 0;
    }
    else if (nClassId == 0xAF)
    {
        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 1, 5);
        return 0;
    }
    else if (nClassId == 0xD2)
    {
        if (nType || !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0xE, 0))
        {
            return 0;
        }

        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x4B, 0);
        QUESTS_ActChange_HirelingChangeAct(pGame, pPlayer, pMonster, 0x4B, 0x28);

        if (WAYPOINTS_GetWaypointNoFromLevelId(0x4B, &nWpNo))
        {
            WAYPOINTS_ActivateWaypoint(sub_00547F50(pGame, pPlayer), nWpNo);
        }
        return 0;
    }
    else if (nClassId == 0x108)
    {
        if (!nType)
        {
            D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x28, 5);
        }
        return 0;
    }
    else if (nClassId == 0x16F)
    {
        if (nType || !pGame->bExpansion || !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x1A, 0))
        {
            return 0;
        }

        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x6D, 0);
        QUESTS_ActChange_HirelingChangeAct(pGame, pPlayer, pMonster, 0x6D, 0x67);

        if (WAYPOINTS_GetWaypointNoFromLevelId(0x6D, &nWpNo))
        {
            WAYPOINTS_ActivateWaypoint(sub_00547F50(pGame, pPlayer), nWpNo);
        }
        return 0;
    }
    else if (nClassId == 0x208)
    {
        if (!nType)
        {
            D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x67, 5);
        }
        return 0;
    }

    return 0;
}
