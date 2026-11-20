#include "D2Game.h"
#include "D2Txt.h"

union D2SeedStrc;
struct D2PlayerDataStrc;
struct D2MercDataStrc;
struct D2NpcRecordStrc;
struct D2HirelingInitStrc;
struct D2ItemsTxt;
struct D2MonsterDataStrc;
struct D2NpcTradeStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x04];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short unk0x02;
    int dwSeed;
    int bHired;
    int unk0x0C;
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char bHireInit;
    unsigned char nAct;
    unsigned char bTrader;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2MercDataStrc* pMercData;
    unsigned char unk_14[0xC];
    D2NpcTradeStrc npcTrade;
};

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

extern "C" const char gszNpcSourceFile[]; // 0x006E15F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel); // 0x00576890
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_0053D740_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType); // 0x0053D740
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass); // 0x00575FF0
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, unsigned short nNameId); // 0x00663750
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost); // 0x00576D90
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nId, D2MercDataStrc* pMercData, int bDead); // 0x00573270
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bSingle); // 0x00576770
void __fastcall sub_00577010_VendorRefresh(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00577010


D2SeedStrc* __fastcall SUNITPROXY_GetSeedFromNpcControl(D2GameStrc* pGame); // 0x00536B40
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

enum { UNIT_MONSTER = 1 };

extern int gnNpcGUID_0088CAC4; // 0x0088CAC4
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0
void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory); // 0x0063CB70
void __stdcall sub_0063BD00_Return(D2InventoryStrc* pInventory); // 0x0063BD00
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade); // 0x00576980

// 0x005770E0
void __fastcall SUNITNPC_HireMercenaryFromRoster(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, unsigned short wName)
{
    int nLevel = STATLIST_UnitGetStatValue(pPlayer, 0x0C, 0);
    nLevel = sub_00576890(pGame, pNpc, nLevel);
    UNITS_GetPlayerData(pPlayer);

    if (pNpc)
    {
        if (pNpc->dwClassId == 0x203)
        {
            D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestRecord, 0x24, 0))
            {
                sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x654), 0x2A, 0x0B, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
                return;
            }
        }

        if (pNpc->dwClassId == 0x96 && nLevel < 8)
        {
            D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestRecord, 2, 0))
            {
                sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x65F), 0x2A, 0x0B, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
                return;
            }
        }
    }

    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x66C), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    int nVendorId;
    if (!pNpc)
    {
        nVendorId = -1;
    }
    else
    {
        nVendorId = pNpc->dwClassId;
    }

    int nNameFirst;
    int nNameLast;
    int nClass;
    sub_00575FF0(pGame, nVendorId, &nNameFirst, &nNameLast, &nClass);

    if (wName < nNameFirst || wName > nNameLast)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x685), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    D2MercDataStrc* pMercData = &pNpcRecord->pMercData[wName - nNameFirst];
    if (pMercData->nMercName != wName)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x693), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    if (pMercData->bHired)
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x69A), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    D2HirelingInitStrc hirelingInit;
    const int nAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, pMercData->nMercName);
    const int nDifficulty = pGame->nDifficulty;
    if (!MONSTERS_HirelingInit(pGame->bExpansion, pPlayer, pMercData->dwSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    if (!sub_00576D90_SpendGold(pGame, pPlayer, hirelingInit.nGold))
    {
        sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x6AE), 0x2A, 0x0C, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    D2UnitStrc* pMerc = MONSTERSPAWN_SpawnAtUnit(pGame, pNpc, nClass, 1, 4, 0);
    if (!pMerc)
    {
        pMerc = MONSTERSPAWN_SpawnAtUnit(pGame, pPlayer, nClass, 1, 4, 0);
        if (!pMerc)
        {
            sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x6BA), 0x2A, 0x0F, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
            return;
        }
    }

    pMercData->bHired = 1;
    MONSTERAI_AssignHireling(pGame, pPlayer, pMerc, -1, pMercData, 0);
    D2GAME_NPC_BuildHirelingList_6FCC6FF0(pGame, UnitGetClient(pPlayer, gszNpcSourceFile, 0x6C5), pNpc, MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)) <= 1);
    sub_0053D740_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x6C6), 0x2A, 5, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), !pMerc ? -1 : pMerc->dwUnitId, 0);
    sub_00577010_VendorRefresh(pGame, nVendorId, pNpcRecord);
}

// 0x005786A0
static int __stdcall sub_005786A0_RollGambleUpgrade(int nItemId, int nUberChance, int nUltraChance, D2GameStrc* pGame, int nItemLevel)
{
    if (!pGame->bExpansion)
    {
        return nItemId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return nItemId;
    }

    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUltraItemId;
    if (pItemsTxtRecord->dwUberCode != 0x20202020 && pItemsTxtRecord->dwUberCode)
    {
        int nUberItemId;
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemsTxtRecord->dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            const int nUberItemChance = (nItemLevel - pUberItemsTxtRecord->nLevel) * nUberChance + 1;
            if (nUberItemChance > 0)
            {
                if (ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUberItemChance)
                {
                    return nUberItemId;
                }

                if (pItemsTxtRecord->dwUltraCode != 0x20202020 && pItemsTxtRecord->dwUltraCode)
                {
                    D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
                    if (pUltraItemsTxtRecord)
                    {
                        const int nUltraItemChance = (nItemLevel - pUltraItemsTxtRecord->nLevel) * nUltraChance + 1;
                        if (nUltraItemChance > 0 && ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUltraItemChance)
                        {
                            return nUltraItemId;
                        }
                    }
                }
            }
        }
    }

    return nItemId;
}

int __stdcall sub_J17_Emit_005786A0(D2GameStrc* pGame, int nItemLevel, int nItemId, int nUberChance, int nUltraChance)
{
    return sub_005786A0_RollGambleUpgrade(nItemId, nUberChance, nUltraChance, pGame, nItemLevel);
}

static __forceinline D2NpcTradeStrc* SUNITNPC_GetNpcTrade(D2NpcRecordStrc* pNpcRecord)
{
    if (pNpcRecord)
    {
        return &pNpcRecord->npcTrade;
    }

    return 0;
}

// 0x00579090
void __fastcall sub_00579090_RefillNpcStore(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (!gnNpcGUID_0088CAC4)
    {
        return;
    }

    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, gnNpcGUID_0088CAC4);
    if (!pNpc)
    {
        return;
    }

    int bHasInteractUnit;
    if (pNpc->dwUnitType == UNIT_MONSTER && pNpc->pMonsterData)
    {
        bHasInteractUnit = MONSTERAI_HasInteractUnit(pNpc->pMonsterData->pMonInteract);
    }
    else
    {
        bHasInteractUnit = MONSTERAI_HasInteractUnit(0);
    }

    if (bHasInteractUnit == 1)
    {
        return;
    }

    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nIndex);
    D2InventoryStrc* pInventory = pNpc->pInventory;
    if (pInventory)
    {
        INVENTORY_RemoveInventoryItems(pInventory);
        sub_0063BD00_Return(pInventory);
    }

    D2NpcTradeStrc* pTrade = SUNITNPC_GetNpcTrade(pNpcRecord);
    if (pTrade && pTrade->bTrader)
    {
        pTrade->bVendorInit = 0;
        D2UnitStrc* const pStorePlayer = *(D2UnitStrc* volatile*)&pPlayer;
        D2GameStrc* const pStoreGame = *(D2GameStrc* volatile*)&pGame;
        D2GAME_NPC_FillStoreInventory_6FCC7100(pStoreGame, pStorePlayer, pNpc, pTrade);
        pTrade->bVendorInit = 1;
    }
}
