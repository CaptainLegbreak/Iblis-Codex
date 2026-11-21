#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2LevelTxt.h"
struct D2ClientStrc;
struct D2ItemsTxt;
struct D2UnitStrc;

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define ITEMQUAL_UNIQUE 7
#define IFLAG_NEWITEM 0x00000001
#define IFLAG_BROKEN 0x00000100
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_GOLD 14
#define STATE_FREEZE 1
#define STATE_POISON 2
#define IFLAG_IDENTIFIED 0x00000010
#define NPC_CLASS_150 150
#define NPC_CLASS_515 515
#define NPC_CLASS_198 198
#define CHECK(p,line) if (!(p)) { sub_00408A60(text_006CC837,sub_00408090(),line); exit(-1); }
struct Inventory;
struct D2PlayerDataStrc;
struct D2MonsterItemCodeStrc;
struct D2StaticPathStrc;
struct D2NpcGambleStrc;
struct D2NpcRecordStrc;
struct D2NpcTradeStrc;
union D2SeedStrc;
struct D2MercDataStrc;
struct D2GSPacketSrv50;
struct D2NpcVendorChainStrc;

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
};

extern "C" const char gszNpcSourceFile[]; // 0x006E15F0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall sub_0062E660(D2UnitStrc* pItem); // 0x0062E660
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01[6];
    unsigned char bRefreshInventory;
};

struct D2NpcRecordStrc
{
    int nNPC;
    void* pInventory;
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
    D2MercDataStrc* pMercData;
    unsigned char unk_14[0x8];
    int bTrading;
    D2NpcTradeStrc tTrade;
    char unk0x28[0x18];
    int dwNPCGUID;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x006564D0
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
bool __fastcall sub_00576ED0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem); // 0x00576ED0
void __fastcall sub_00576650_AddGambleItem(D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit); // 0x00576650
void __fastcall sub_6FCC6F10(D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit); // 0x005766D0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

typedef void (__fastcall* PetIterateCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

void __fastcall sub_0053D740_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType); // 0x0053D740
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetIterateCallback pCallback, void* pArg); // 0x00574DE0
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost); // 0x00576D90
void __fastcall SUNITNPC_HireMercenaryFromRoster(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, unsigned short wName); // 0x005770E0
int __fastcall sub_00577830_BuyItem(D2GameStrc* ptGame,D2UnitStrc* pPlayer,D2UnitStrc* pNpc,int nItemGuid,int nItemMode,unsigned short nTransaction,int nQuotedCost,int bMultibuy); // 0x00577830
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit); // 0x00578C20
void __fastcall SUNITNPC_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg); // 0x00578CA0
void __fastcall sub_00579AA0_ReplacePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet); // 0x00579AA0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
unsigned int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pPlayer); // 0x0062A530
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling); // 0x006637B0
D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536C50
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
void __fastcall D2GAME_STORES_CreateVendorCache_6FCCAE20(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bGamble); // 0x00578B30
void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc); // 0x00536D10
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade); // 0x00576980
void __fastcall sub_00576C30_AddItemsToTrade(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory); // 0x00576C30

struct Unit { unsigned type; unsigned classId; void* pool; unsigned id; char pad10[0x50]; Inventory* inventory; char pad64[0x64]; unsigned flags; };
extern "C" const char text_006CC837[]; // 0x006CC837
void __fastcall sub_00560420(Game*,Unit*,unsigned,int*,int,int,int,int); // 0x00560420
void __stdcall sub_00621000(Unit*,int); // 0x00621000
void __stdcall sub_0063CC70(Inventory*,Unit*); // 0x0063CC70
void __stdcall sub_00628170(Unit*,int,int); // 0x00628170
void __fastcall sub_00557FD0(Game*,Unit*); // 0x00557FD0

enum
{
    ITEMQUAL_INFERIOR = 1,
    ITEMQUAL_NORMAL = 2,
    ITEMQUAL_SUPERIOR = 3,
};

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetQuantity(D2SkillStrc*); // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc*, int); // 0x00645120
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc*, unsigned char, int, int, int); // 0x0053C520
extern const char gszUnitNpcSource_006E15F0[]; // 0x006E15F0
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc*,D2UnitStrc*,unsigned int); // 0x0055B060
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __fastcall D2GAME_STORES_FillGamble_6FCCA9F0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pUnit, D2NpcRecordStrc* pNpcRecord); // 0x00578790
void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00578D30

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short unk0x02;
    int dwSeed;
    int bHired;
    int bDead;
};

#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nType;
    unsigned short nMercName;
    unsigned char unk0x05[0x0B];
};

#pragma pack(pop)

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0
void __fastcall sub_00577010_VendorRefresh(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00577010
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x006564D0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nId, D2MercDataStrc* pMercData, int bDead); // 0x00573270

struct D2NpcVendorChainStrc
{
    int nPlayerGUID;
    unsigned char field_4;
};

D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer); // 0x00536CB0

// 0x00573B20
void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterItemCodeStrc* pItemCode, int dwILvl, int dwQuality)
{
    const int nType = pMonster ? pMonster->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    if (!pMonster->pInventory)
    {
        INVENTORY_AllocInventory(0, pMonster);
    }

    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(pItemCode->nItemCode, &nItemId))
    {
        return;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pMonster, nItemId, pGame, 4, dwQuality, 1, 1, dwILvl, 0, 0, 0);
    if (!pItem)
    {
        return;
    }

    ITEMS_SetItemFlag(pItem, 0x1000, 1);
    ITEMS_SetBodyLocation(pItem, pItemCode->nBodyLoc);
    if (pItemCode->nBodyLoc == 0)
    {
        return;
    }

    {
        const int nItemGUID = pItem->dwUnitId;
        int nUnused;
        if (!ITEMMODE_EquipCursorItem(pGame, pMonster, nItemGUID, ITEMS_GetBodyLocation(pItem), 1, &nUnused))
        {
            SUNIT_RemoveUnit(pGame, pItem);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 0x48, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
        }
    }
}

// 0x00578640
void __fastcall D2GAME_NPC_IdentifyBoughtItem_6FCCA990(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    const int nGUID = nItemGUID;
    if (pPlayerData->dwBoughtItemId != nGUID)
    {
        return;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nGUID);
    if (!pItem || ITEMS_CheckItemFlag(pItem, 0x10, 0xD1F, gszNpcSourceFile))
    {
        return;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00575FA0
int __fastcall sub_00575FA0_IsUniqueCarryOneItem(D2UnitStrc* pItem)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_UNIQUE)
    {
        return 0;
    }

    if (ITEMS_GetFileIndex(pItem) < 0)
    {
        return 0;
    }

    D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    return (pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7]) != 0;
}

// 0x005761C0
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    if (sub_0062E660(pItem))
    {
        if (ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nMaxStack, 0);

            if (pPlayer)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer, gszNpcSourceFile, 185), pItem, 1, STAT_QUANTITY, nMaxStack, 0);
            }
        }

        D2GAME_RechargeItem_6FC4BD50(pGame, pPlayer, pItem);

        if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 191, gszNpcSourceFile))
        {
            D2GAME_RepairBrokenItem_6FC4B630(pGame, pPlayer, pItem);
        }
        else
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            if (nMaxDurability > 0)
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);

                if (pPlayer)
                {
                    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer, gszNpcSourceFile, 203), pItem, 1, STAT_DURABILITY, nMaxDurability, 0);
                }
            }
        }
    }
}

// 0x00576C30
void __fastcall sub_00576C30_AddItemsToTrade(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pCurrent = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pCurrent)
        {
            pCurrent->dwFlagEx |= 4;
        }

        if (sub_0055F590_CheckItem(pCurrent, gszNpcSourceFile, 730))
        {
            ITEMS_SetItemFlag(pCurrent, IFLAG_NEWITEM, 1);
        }

        INVENTORY_AddItemToTradeInventory(pPlayer->pInventory, pCurrent);
    }
}

// 0x005773D0
void __fastcall sub_005773D0_UpdateMercForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0))
    {
        sub_6FC7E310(pGame, pPlayer, UNITS_GetUnitXPosition(pPlayer), UNITS_GetUnitYPosition(pPlayer));
    }
}

// 0x00575FF0
int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->bExpansion, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    const int nCount = *pNameLast - *pNameFirst + 1;
    D2_ASSERT(nCount != -1, 96);
    return nCount;
}

// 0x005762B0
void __fastcall sub_005762B0_RepairItemCallback(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2GAME_NPC_RepairItem_6FCC6970(pGame, pItem, pPlayer);
}

// 0x00576D90
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost)
{
    const int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    if (nGold + STATLIST_UnitGetStatValue(pPlayer, 15, 0) < nCost)
    {
        return 0;
    }

    if (nCost <= nGold)
    {
        PLRTRADE_AddGold(pPlayer, 14, -nCost);
        return 1;
    }

    PLRTRADE_AddGold(pPlayer, 14, -nGold);

    const int nValue = nGold - nCost;
    if (pPlayer)
    {
        const int nNewValue = nValue + STATLIST_UnitGetStatValue(pPlayer, 15, 0);
        if (nNewValue < 0)
        {
            STATLIST_SetUnitStat(pPlayer, 15, 0, 0);
            return 1;
        }

        if (pPlayer->dwUnitType == 0 && nNewValue > UNITS_GetStashGoldLimit(pPlayer))
        {
            STATLIST_SetUnitStat(pPlayer, 15, 0, 0);
            return 1;
        }

        STATLIST_AddUnitStat(pPlayer, 15, nValue, 0);
    }

    return 1;
}

// 0x00576F50
void __fastcall sub_6FCC7E20(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a5)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (pNpcRecord->bGambleInit && a5 == 2)
    {
        D2NpcGambleStrc* pNpcGamble = pNpcRecord->pGamble;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        while (pNpcGamble)
        {
            if (pNpcGamble->dwGUID == nUnitGUID)
            {
                break;
            }

            pNpcGamble = pNpcGamble->pNext;
        }

        if (pNpcGamble && pNpcGamble->pInventory)
        {
            D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pNpcGamble->pInventory);
            while (pCurrent)
            {
                D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pCurrent);
                D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
                if (pCheck == pItem)
                {
                    sub_00576650_AddGambleItem(pUnit, pNpc, pItem, pGame, 1);
                    return;
                }

                pCurrent = pNext;
            }
        }
    }

    if (!sub_00576ED0(pGame, pNpc, pItem))
    {
        sub_6FCC6F10(pNpc, pItem, pGame, 1);
    }
}

// 0x00577470
int __fastcall sub_00577470_RelinkItemStatLists(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory); pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        int bStatNotDynamic = 0;
        if (pItem && pItem->dwUnitType == 4 && STATLIST_GetOwner(pItem, &bStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            STATLIST_MergeStatLists(pUnit, pItem, bStatNotDynamic);
        }
    }

    return 1;
}

// 0x00578C20
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit)
{
    int bStateRemoved = 0;
    for (int nState = 0; nState < sgptDataTables->nStatesTxtRecordCount; ++nState)
    {
        if (STATES_CheckState(pUnit, nState) && STATES_CheckStateMaskCurableByStateId(nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
                bStateRemoved = 1;
            }
        }
    }

    return bStateRemoved;
}

static __forceinline D2BitBufferStrc* sub_00578460_GetQuestRecord(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005762C0
void __fastcall sub_005762C0_SetItemTradeFlags(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pUnused, int bAdd, int nUnused)
{
    ITEMS_SetItemFlag(pItem, IFLAG_IDENTIFIED, 1);
    if (bAdd)
    {
        if (pItem)
        {
            pItem->dwFlagEx |= 4;
        }

        if (sub_0055F590_CheckItem(pItem, gszNpcSourceFile, 233))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);
        }

        UNITS_RefreshInventory(pPlayer, 1);
        INVENTORY_AddItemToTradeInventory(pPlayer->pInventory, pItem);
    }
}

// 0x00577F30
int __fastcall D2GAME_NPC_BuyItemHandler_6FCC92A0(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nItemId, int nItemMode, int nTransactionType, int nCost, int bMultibuy)
{
    D2_ASSERT(ptGame, 2372);

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(ptGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(ptGame, UNIT_MONSTER, nNpcUnitId);
    if (pNpc && pInteractUnit == pNpc)
    {
        return sub_00577830_BuyItem(ptGame, pPlayer, pNpc, nItemId, nItemMode, nTransactionType, nCost, bMultibuy);
    }

    sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2380), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
    return 1;
}

// 0x00577FE0
void __fastcall D2GAME_NPC_HireMerc_6FCC9540(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int a4)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (pNpc && pInteractUnit == pNpc)
    {
        SUNITNPC_HireMercenaryFromRoster(pGame, pPlayer, pNpc, a4);
    }
    else
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2477), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
    }
}

// 0x00578460
void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcGUID);
    if (!pNpc || pInteractUnit != pNpc)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2669), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    switch ((unsigned int)pNpc->dwClassId)
    {
    case 244:
    case 245:
    case 246:
    case 265:
    case 520:
    {
        const int nUnidentifiedItems = ITEMS_GetNoOfUnidItems(pPlayer);
        if (!nUnidentifiedItems)
        {
            sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2689), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
            return;
        }

        if (QUESTRECORD_GetQuestState(sub_00578460_GetQuestRecord(pGame, pPlayer), 4, 0) != 1
            && QUESTRECORD_GetQuestState(sub_00578460_GetQuestRecord(pGame, pPlayer), 4, 1) != 1)
        {
            if (!sub_00576D90_SpendGold(pGame, pPlayer, 100 * nUnidentifiedItems))
            {
                sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2704), 0x2A, 12, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
                return;
            }
        }

        D2UnitStrc* pNext;
        for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pPlayer->pInventory); pNode; pNode = pNext)
        {
            pNext = INVENTORY_GetNextItem(pNode);
            const int nPage = INVENTORY_GetItemNodePage(pNode);
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
            if ((nPage == 1 && (ITEMS_GetInvPage(pItem) == 0 || ITEMS_GetInvPage(pItem) == 3)) || nPage == 3)
            {
                if (!ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 2721, gszNpcSourceFile))
                {
                    D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
                }
            }
        }

        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2730), 0x2A, 3, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        break;
    }
    default:
        break;
    }
}

// 0x00578D30
void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc)
{
    if (SUNIT_GetInteractUnit(pGame, pUnit) != pNpc)
    {
        return;
    }

    int bPlaySound = 0;

    const unsigned int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_HITPOINTS, nMaxHp, pUnit);
        bPlaySound = 1;
    }

    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_MANA, nMaxMana, pUnit);
        bPlaySound = 1;
    }

    const unsigned int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_STAMINA, nMaxStamina, pUnit);
        bPlaySound = 1;
    }

    D2StatListStrc* pStatListPoison = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_POISON);
    if (pStatListPoison)
    {
        D2Common_10474(pUnit, pStatListPoison);
        STATLIST_FreeStatList(pStatListPoison);
        bPlaySound = 1;
    }

    D2StatListStrc* pStatListFreeze = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_FREEZE);
    if (pStatListFreeze)
    {
        D2Common_10474(pUnit, pStatListFreeze);
        STATLIST_FreeStatList(pStatListFreeze);
        bPlaySound = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pUnit))
    {
        bPlaySound = 1;
    }

    PLAYERPETS_IteratePets(pGame, pUnit, SUNITNPC_PetIterate_Heal, &bPlaySound);

    if (bPlaySound == 1)
    {
        SUNIT_AttachSound(pNpc, 10, 0);
    }
}

// 0x00579C00
void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (!pNpc || pInteractUnit != pNpc)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2397), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    switch ((unsigned int)pNpc->dwClassId)
    {
    case 150:
    case 198:
    case 252:
    case 367:
    case 515:
        break;
    default:
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2412), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    D2UnitStrc* pHireling = sub_6FC7E8B0(pGame, pPlayer, 7, 1);
    if (!pHireling)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2419), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    if (!sub_00576D90_SpendGold(pGame, pPlayer, MONSTERS_GetHirelingResurrectionCost(pHireling)))
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2452), 0x2A, 12, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    pHireling->dwFlags &= 0xFFFEFFFF;
    UNITS_ChangeAnimMode(pHireling, 1);
    STATLIST_SetUnitStat(pHireling, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pHireling), 0);
    sub_00579AA0_ReplacePet(pGame, pPlayer, pHireling);
    D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszNpcSourceFile, 2461), 0xFFFF, 0);
    const int nHirelingGUID = pHireling->dwUnitId;
    sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2462), 0x2A, 5, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), nHirelingGUID, 0);
}

static __forceinline int UNITS_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }

    return -1;
}

// 0x00576650
void __fastcall sub_00576650_AddGambleItem(D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit)
{
    if (!pItem || !pNpc)
    {
        return;
    }

    D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNpc);
    if (!pGambleInventory)
    {
        return;
    }

    int nUnused;
    sub_6FC446B0(pGame, pNpc, UNITS_GetUnitGUIDInline(pItem), &nUnused, 0, 0, pGambleInventory, 0);
    if (bInit)
    {
        pItem->dwFlagEx |= 0x10;
        UNITS_RefreshInventory(pNpc, 1);
        INVENTORY_AddItemToTradeInventory(pGambleInventory, pItem);
        ITEMS_SetItemCMDFlag(pItem, 1, 1);
    }
    else
    {
        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
}

// 0x00579430
void __fastcall D2GAME_STORES_CreateVendorCache_6FCC74F0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC, int bRefreshInventory, int bGamble)
{
    if (!pNPC)
    {
        return;
    }

    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNPC, &nUnused);
    if (!pNpcRecord)
    {
        return;
    }

    pNpcRecord->bTrading = 1;
    pNpcRecord->dwNPCGUID = UNITS_GetUnitGUIDInline(pNPC);
    D2GAME_STORES_CreateVendorCache_6FCCAE20(pGame, pPlayer, pNPC, bGamble);

    const int nClassId = pNPC->dwClassId;
    if (nClassId == NPC_CLASS_150 || nClassId == NPC_CLASS_515 || nClassId == NPC_CLASS_198)
    {
        return;
    }

    if (bRefreshInventory && !bGamble)
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->tTrade;
        if (pTrade->bRefreshInventory)
        {
            pTrade->bRefreshInventory = 0;
            SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, pNPC);
            D2GAME_NPC_FillStoreInventory_6FCC7100(pGame, pPlayer, pNPC, pTrade);
            pTrade->bVendorInit = 1;
        }
    }

    UNITS_RefreshInventory(pNPC, 1);
    if (!bGamble)
    {
        sub_00576C30_AddItemsToTrade(pNPC, pNPC->pInventory);
    }
    else
    {
        D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNPC);
        if (pGambleInventory)
        {
            sub_00576C30_AddItemsToTrade(pNPC, pGambleInventory);
        }
    }
}

// 0x005766D0
void __fastcall sub_005766D0(Unit* hNPC,Unit* hItem,Game* ptGame,int init)
{
    CHECK(ptGame,423);
    CHECK(hNPC,424);
    CHECK(hItem,425);
    int unused;
    unsigned id = hItem ? hItem->id : -1;
    sub_00560420(ptGame,hNPC,id,&unused,0,0,0,0);
    if(init) {
        hItem->flags |= 0x10;
        sub_00621000(hNPC,1);
        sub_0063CC70(hNPC->inventory,hItem);
        sub_00628170(hItem,1,1);
    } else {
        sub_00557FD0(ptGame,hItem);
    }
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00576900
int __fastcall sub_00576900_RollStoreItemQuality(D2SeedStrc* pSeed, unsigned int dwCode, int nItemLevel)
{
    int nQuality = ITEMQUAL_NORMAL;
    const unsigned int nRoll = (unsigned int)SEED_RollRandomNumber(pSeed) % 100;

    if (nItemLevel < 5)
    {
        if (nRoll > 90)
        {
            nQuality = ITEMQUAL_INFERIOR;
        }
    }
    else if (nItemLevel < 10)
    {
        if (nRoll > 85)
        {
            nQuality = ITEMQUAL_SUPERIOR;
        }
    }
    else if (nRoll >= 75)
    {
        nQuality = ITEMQUAL_SUPERIOR;
    }

    return nQuality;
}

// 0x00576E40
void __fastcall sub_00576E40_DecreaseSkillQuantity(D2UnitStrc* unit, int skillId, int decrement)
{
    if (skillId < 0) return;
    D2SkillStrc* skill = SKILLS_GetHighestLevelSkillFromUnitAndId(unit, skillId);
    if (!skill) return;
    int quantity = SKILLS_GetQuantity(skill) - decrement;
    if (quantity <= 0) {
        if (UNITS_GetRightSkill(unit) == skill) D2GAME_AssignSkill_6FD13800(unit, 0, 0, -1);
        quantity = 0;
    }
    SKILLS_SetQuantity(skill, quantity);
    int id, type;
    if (!unit) { id = -1; type = 6; }
    else { id = unit->dwUnitId; type = unit->dwUnitType; }
    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(unit, gszUnitNpcSource_006E15F0, 0x40b), (unsigned char)type, id, skillId, quantity);
}

// 0x00576F40
void __fastcall sub_00576F40_Gold(D2GameStrc* game,D2UnitStrc* unit,unsigned int value) {
 ITEMS_HandleGoldTransaction(game,unit,value);
}

// 0x00578610
static __declspec(noinline) int __stdcall sub_00578610_IsCursorItem(unsigned int nItemGUID, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
        if (pItem)
        {
            const unsigned int nId = (pItem ? pItem->dwUnitId : -1);
            if (nId == nItemGUID)
            {
                return 1;
            }
        }
    }

    return 0;
}

int __stdcall sub_M452_Emit_00578610(D2UnitStrc* pUnit, unsigned int nGUID)
{
    return sub_00578610_IsCursorItem(nGUID, pUnit) + 7;
}

// 0x00578AE0
void __fastcall sub_00578AE0_FillGambleIfMissing(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2NpcRecordStrc* pNpcRecord)
{
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    int bHasGamble = 0;
    for (D2NpcGambleStrc* pNpcGamble = pNpcRecord->pGamble; pNpcGamble; pNpcGamble = pNpcGamble->pNext)
    {
        if (pNpcGamble->dwGUID == nPlayerGUID)
        {
            bHasGamble = 1;
        }
    }

    if (!bHasGamble)
    {
        D2GAME_STORES_FillGamble_6FCCA9F0(pGame, pNpc, pPlayer, pNpcRecord);
    }
}

int gnNpcGUID_0088CAC4; // 0x0088CAC4

// 0x00578E70
void __fastcall D2GAME_NPC_Heal_6FCCB220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc)
{
    const int nGUID = !pNpc ? -1 : pNpc->dwUnitId;

    gnNpcGUID_0088CAC4 = nGUID;
    if (pNpc)
    {
        const int nClass = pNpc->dwClassId;
        if (nClass == 148 || nClass == 513 || nClass == 176 || nClass == 178 || nClass == 405 || nClass == 255)
        {
            D2GAME_NPC_HealPlayer_6FCCB080(pGame, pUnit, pNpc);
        }
    }
}

// 0x00579180
void __fastcall sub_00579180_ResurrectMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nVendorId)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, nVendorId, &nIndex);
    if (!pNpcRecord)
    {
        return;
    }

    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    if (!pMercData)
    {
        return;
    }

    if (pGame->bExpansion)
    {
        if (sub_6FC7E8B0(pGame, pPlayer, 7, 1))
        {
            sub_00577010_VendorRefresh(pGame, nVendorId, pNpcRecord);
            return;
        }
    }

    if (!pGame->bExpansion)
    {
        if (sub_6FC7E8B0(pGame, pPlayer, 7, 0))
        {
            return;
        }
    }

    D2HirelingTxt* pHirelingTxt = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->bExpansion, nVendorId, pGame->nDifficulty, 0);
    if (!pHirelingTxt)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFA2);
        exit(-1);
    }

    const int nNameLast = pHirelingTxt->wNameLast;
    const int nNameFirst = pHirelingTxt->wNameFirst;
    const int nClass = pHirelingTxt->dwClass;
    const int nCount = nNameLast - nNameFirst + 1;
    int nName = nNameFirst;
    while (nName <= nNameLast)
    {
        const int nIdx = nName - nNameFirst;
        if (nIdx >= nCount)
        {
            break;
        }

        if (pMercData[nIdx].bHired == 1)
        {
            ++nName;
            continue;
        }

        if (pMercData[nIdx].bDead == 1)
        {
            D2GSPacketSrv50 packet50;
            packet50.nHeader = 0x50;
            packet50.nType = 2;
            packet50.nMercName = pMercData[nIdx].nMercName;
            pMercData[nIdx].bHired = 1;
            D2GAME_SendPacket0x50_6FC3F440(UnitGetClient(pPlayer, gszNpcSourceFile, 0xFC7), &packet50);

            D2UnitStrc* pUnit = sub_6FC68D70(pGame, pPlayer, nClass, 1, 4, 0);
            if (!pUnit)
            {
                pUnit = sub_6FC68D70(pGame, pPlayer, nClass, 1, 6, 0);
                if (!pUnit)
                {
                    pUnit = sub_6FC68D70(pGame, pPlayer, nClass, 1, 0x0C, 0);
                    if (!pUnit)
                    {
                        return;
                    }
                }
            }

            MONSTERAI_AssignHireling(pGame, pPlayer, pUnit, -1, &pMercData[nIdx], 0);
            break;
        }

        ++nName;
    }

    sub_00577010_VendorRefresh(pGame, nVendorId, pNpcRecord);
}

// 0x00579360
int __fastcall D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, int a4)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nIndex);
    if (pNpcRecord)
    {
        D2NpcVendorChainStrc* pNpcVendorChain = SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer);
        const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
        if (pNpcVendorChain && pNpcVendorChain->field_4)
        {
            if (!a4)
            {
                for (D2NpcGambleStrc* pGamble = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &a4)->pGamble; pGamble; pGamble = pGamble->pNext)
                {
                    if (pGamble->dwGUID == nPlayerGUID)
                    {
                        for (D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pGamble->pInventory); pInventoryItem; pInventoryItem = INVENTORY_GetNextItem(pInventoryItem))
                        {
                            if (INVENTORY_UnitIsItem(pInventoryItem) == pItem)
                            {
                                return 1;
                            }
                        }
                        break;
                    }
                }
                return 0;
            }
        }
        else if (!ITEMS_CheckItemFlag(pItem, 0x10, 4109, gszNpcSourceFile))
        {
            return 0;
        }
    }
    return 1;
}
