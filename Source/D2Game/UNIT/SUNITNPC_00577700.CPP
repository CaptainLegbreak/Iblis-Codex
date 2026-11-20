#include "D2Game.h"
#include "D2Structs.h"
#define MONSTER_KASHYA 150
#define MONSTER_GREIZ 198
#define MONSTER_ASHEARA 252
struct D2NpcGambleStrc;
struct D2NpcTradeStrc;
struct D2NpcRecordStrc;
struct D2NpcVendorChainStrc;


struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char bHireInit;
    unsigned char nAct;
    unsigned char bTrader;
};

struct D2NpcRecordStrc
{
    int nNPC;
    D2InventoryStrc* pInventory;
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
    int unk0x10;
    void* pEvent;
    int unk0x18;
    int bTrading;
    D2NpcTradeStrc npcTrade;
};

struct D2NpcVendorChainStrc
{
    int dwGUID;
    unsigned char field_4;
};

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer); // 0x00536CB0
void __fastcall sub_00576070_InitGamble(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00576070
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade); // 0x00576980
void __fastcall sub_00578AE0_FillGambleIfMissing(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2NpcRecordStrc* pNpcRecord); // 0x00578AE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
extern "C" const char gszNpcSourceFile[]; // 0x006E15F0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit); // 0x00578C20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit); // 0x00622DE0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_0053D740_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType); // 0x0053D740
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost); // 0x00576D90
void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00578D30

// 0x00577700
D2UnitStrc* __fastcall sub_6FCC87C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* a4)
{
    *a4 = 1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_GetAutoStack(pItem))
    {
        return 0;
    }

    D2UnitStrc* pStackItem = 0;
    int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
    while (1)
    {
        pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    int nQuantity = 0;
    while (1)
    {
        pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    *a4 = nMaxStack;
    return 0;
}

// 0x00578B30
void __fastcall D2GAME_STORES_CreateVendorCache_6FCCAE20(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bGamble)
{
    if (!pNpc)
    {
        return;
    }

    const int nNpcClassId = pNpc->dwClassId;
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        return;
    }

    if (bGamble)
    {
        if (pNpcRecord->bGambleInit)
        {
            SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer)->field_4 = 1;
            sub_00578AE0_FillGambleIfMissing(pGame, pNpc, pPlayer, pNpcRecord);
        }
    }
    else
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->npcTrade;
        if (pTrade && pTrade->bTrader)
        {
            SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer)->field_4 = 0;
            if (!pTrade->bVendorInit)
            {
                D2GAME_NPC_FillStoreInventory_6FCC7100(pGame, pPlayer, pNpc, pTrade);
                pTrade->bVendorInit = 1;
            }

            if (!pTrade->bHireInit)
            {
                if (nNpcClassId == MONSTER_KASHYA || nNpcClassId == MONSTER_QUAL_KEHK || nNpcClassId == MONSTER_GREIZ || nNpcClassId == MONSTER_ASHEARA)
                {
                    sub_00576070_InitGamble(pGame, nNpcClassId, pNpcRecord);
                }
                pTrade->bHireInit = 1;
            }
        }
    }
}

// 0x00578CA0
void __fastcall SUNITNPC_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, void* a4)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nHitpoints < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, 6, nMaxHp, 0);
        *(unsigned char*)a4 = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pUnit))
    {
        *(unsigned char*)a4 = 1;
    }

    D2StatListStrc* pStatListPoison = STATLIST_GetStatListFromUnitAndState(pUnit, 2);
    if (pStatListPoison)
    {
        D2Common_10474(pUnit, pStatListPoison);
        STATLIST_FreeStatList(pStatListPoison);
        *(unsigned char*)a4 = 1;
    }

    D2StatListStrc* pStatListFreeze = STATLIST_GetStatListFromUnitAndState(pUnit, 1);
    if (pStatListFreeze)
    {
        D2Common_10474(pUnit, pStatListFreeze);
        STATLIST_FreeStatList(pStatListFreeze);
        *(unsigned char*)a4 = 1;
    }
}

// 0x00578ED0
void __fastcall D2GAME_NPC_PurchaseHeal_6FCCB280(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID)
{
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
    if (!pNpc || pInteractUnit != pNpc)
    {
        return;
    }

    int nStatRestored = 0;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 6, 0) != nMaxHp)
    {
        nStatRestored = 1;
    }

    unsigned int nHealingCost = UNITS_GetHealingCost(pUnit);
    if (!nHealingCost)
    {
        nHealingCost = 1;
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 8, 0) != nMaxMana)
    {
        nStatRestored = 1;
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 10, 0) == nMaxStamina && !nStatRestored)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3848), 0x2A, 14, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
        return;
    }

    if (STATLIST_UnitGetStatValue(pUnit, 14, 0) + STATLIST_UnitGetStatValue(pUnit, 15, 0) >= nHealingCost)
    {
        if (!sub_00576D90_SpendGold(pGame, pUnit, nHealingCost))
        {
            sub_0053D740_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3861), 0x2A, 9, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
            return;
        }

        D2GAME_NPC_HealPlayer_6FCCB080(pGame, pUnit, pNpc);
        sub_0053D740_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3874), 0x2A, 6, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
    }
    else
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3868), 0x2A, 12, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
    }
}
