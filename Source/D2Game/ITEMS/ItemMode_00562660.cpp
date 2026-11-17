#include "D2Game.h"

#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define IFLAG_BROKEN 0x00000100
#define EVENTTYPE_STATREGEN 3
#define STAT_ITEM_REPLENISH_DURABILITY 252
#define STAT_ITEM_REPLENISH_QUANTITY 253
#define STAT_DURABILITY 72
#define STAT_QUANTITY 70
struct D2RunesTxt;

struct D2GameStrc
{
    char unk_00[0x74];
    int dwGameType;
    unsigned char unk_78[0x30];
    int dwGameFrame;
};

struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode; char unk_14[0x4C]; D2InventoryStrc* pInventory; char unk_64[0x60]; unsigned int dwFlags; };

struct D2RunesTxt { char unk_00[0x81]; unsigned char nServer; };

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558530
void __fastcall sub_6FC51310(D2GameStrc*, D2UnitStrc*); // 0x00558580
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc*, const char*, int); // 0x0055BF50
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0055C2C0
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0055FE80
void __stdcall UNITS_RefreshInventory(D2UnitStrc*, int); // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
void __stdcall sub_006276C0_MergeSocketStats(D2UnitStrc*, D2UnitStrc*); // 0x006276C0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*, unsigned int, int, const char*); // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, unsigned int, int); // 0x006280D0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc*); // 0x00629900
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0
int __stdcall sub_0062BEB0_IsSocketFiller(D2UnitStrc*); // 0x0062BEB0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc*); // 0x0062BED0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void*, D2UnitStrc*); // 0x0063ABD0
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063B210
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc*, D2UnitStrc*); // 0x0063C180
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc*, D2UnitStrc*); // 0x0063CC70
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc*); // 0x0063CD60
void __stdcall sub_006600A0_ApplyRuneWord(D2UnitStrc*, D2UnitStrc*, int); // 0x006600A0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x00562660
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9)
{
    D2_ASSERT(pGame, 0x13A9);
    *bPlaced = 0;
    if (pUnit) sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x13B0);
    D2UnitStrc* pFiller = SUNIT_GetServerUnit(pGame, 4, nSocketFillerGUID);
    if (!pFiller)
    {
        *bPlaced = 1;
        return 0;
    }
    if (pFiller->dwUnitType != 4) return 0;
    if (pFiller->dwAnimMode != 4)
    {
        *bPlaced = 1;
        return 0;
    }
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *bPlaced = 1;
        return 0;
    }
    if (pItem->dwUnitType != 4) return 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x13DB, ".\\ITEMS\\ItemMode.cpp")) return 0;
    if (bCheckMode && pItem->dwAnimMode != 0 && pItem->dwAnimMode != 1) return 0;
    if (pFiller->dwUnitType != 4 || pItem->dwUnitType != 4 || !sub_0062BEB0_IsSocketFiller(pFiller)
        || !ITEMS_CheckItemFlag(pFiller, 0x10, 0x13EA, ".\\ITEMS\\ItemMode.cpp")
        || !ITEMS_CheckItemFlag(pItem, 0x800, 0x13EB, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CheckIfSocketable(pItem)) return 0;
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        pInventory = INVENTORY_AllocInventory(0, pItem);
        if (!pInventory) return 0;
    }
    const unsigned int nSockets = ITEMS_GetSockets(pItem);
    if (INVENTORY_GetItemCount(pInventory) >= nSockets) return 0;
    if (INVENTORY_PlaceItemInSocket(pInventory, pFiller, 1))
    {
    pFiller->dwFlags &= ~2u;
    if (bResetCursorItem && pUnit) INVENTORY_SetCursorItem(pUnit->pInventory, 0);
    D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pFiller, pItem, 0);
    sub_006276C0_MergeSocketStats(pFiller, pItem);
    UNITS_ChangeAnimMode(pFiller, 6);
    const D2RunesTxt* pRunesTxt = ITEMS_GetRunesTxtRecordFromItem(pItem);
    if (pRunesTxt && ((pRunesTxt->nServer && pGame->dwGameType) || !pRunesTxt->nServer))
    {
        sub_006600A0_ApplyRuneWord(pItem, pFiller, 0);
        ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
        sub_6FC51310(pGame, pItem);
        if (a9) D2GAME_RechargeItem_6FC4BD50(pGame, pUnit, pItem);
        bRefresh = 1;
    }
    if (bRefresh)
    {
        ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x143A, ".\\ITEMS\\ItemMode.cpp")) ITEMS_SetItemFlag(pItem, 0x4000, 0);
        if (pUnit)
        {
            UNITS_RefreshInventory(pUnit, 1);
            INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
        }
    }
    return 1;
    }
    else
    {
        D2_ASSERT(0, 0x1444);
    }
}

// 0x00562C40
static int __stdcall sub_6FC4A350(D2GameStrc* pGame, D2UnitStrc* pItem, int nLengthStatId, int nValueStatId, int nMaxValue)
{
    const int nLength = STATLIST_UnitGetStatValue(pItem, nLengthStatId, 0);
    if (!nLength)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetStatValue(pItem, nValueStatId, 0) + 1;
    if (nValue > nMaxValue)
    {
        return 1;
    }

    STATLIST_SetUnitStat(pItem, nValueStatId, nValue, 0);

    const int nOwnerGUID = ITEMS_GetOwnerId(pItem);
    if (nOwnerGUID != -1)
    {
        D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
        if (pOwner)
        {
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pOwner, ".\\ITEMS\\ItemMode.cpp", 5504);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, nValueStatId, nValue, 0);
                if (nValue >= 1)
                {
                    if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 5510, ".\\ITEMS\\ItemMode.cpp"))
                    {
                        D2GAME_RepairBrokenItem_6FC4B630(pGame, pOwner, pItem);
                    }
                }
            }
        }
    }

    int nDuration = 2500 / nLength + 1;
    if (nDuration < 125)
    {
        nDuration = 125;
    }

    EVENT_SetEvent(pGame, pItem, EVENTTYPE_STATREGEN, pGame->dwGameFrame + nDuration, 0, 0);

    return 1;
}

// 0x00562D30
void __fastcall sub_6FC4A2E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!ITEMS_CheckItemFlag(pUnit, IFLAG_BROKEN, 5542, ".\\ITEMS\\ItemMode.cpp") && ITEMS_HasDurability(pUnit) && sub_6FC4A350(pGame, pUnit, STAT_ITEM_REPLENISH_DURABILITY, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pUnit)))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pUnit))
    {
        sub_6FC4A350(pGame, pUnit, STAT_ITEM_REPLENISH_QUANTITY, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pUnit));
    }
}
