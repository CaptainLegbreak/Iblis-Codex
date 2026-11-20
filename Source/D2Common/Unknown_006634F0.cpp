#include "D2Common.h"
#include "D2Structs.h"

struct D2InventoryStrc;
union D2SeedStrc;
struct D2Rolled6634F0Strc;
struct D2Roll8Strc;
struct D2Roll16Strc;
struct D2Roll24Strc;
struct D2Roll20Strc;
struct D2Roll28Strc;
struct D2HirelingTxt;


void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct D2Rolled6634F0Strc
{
    int nType;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    unsigned short wFlags;
};

struct D2Roll8Strc { int a; int b; };

struct D2Roll16Strc { int a; int b; int c; int d; };

struct D2Roll24Strc { int a; int b; int c; int d; int e; int f; };

struct D2Roll20Strc { int a; int b; int c; int d; int e; };

struct D2Roll28Strc { int a; int b; int c; int d; int e; int f; int g; };

extern const int gnRollBase1_007484CC[]; // 0x007484CC
extern const int gnRollCount1_007484DC[]; // 0x007484DC
extern const int gnRollBase2_007484F0[]; // 0x007484F0
extern const int gnRollCount2_00748500[]; // 0x00748500
extern const int gnRollBase3_00748514[]; // 0x00748514
extern const int gnRollCount3_00748524[]; // 0x00748524
extern const int gnRollBase4_00748538[]; // 0x00748538
extern const int gnRollCount4_00748548[]; // 0x00748548
extern const D2Roll8Strc gtRollStart_00748558[]; // 0x00748558
extern const D2Roll16Strc gtRoll1_00748578[]; // 0x00748578
extern const D2Roll16Strc gtRoll2_007485D8[]; // 0x007485D8
extern const D2Roll24Strc gtRoll3_00748638[]; // 0x00748638
extern const D2Roll20Strc gtRoll4_007486C8[]; // 0x007486C8
extern const D2Roll28Strc gtRollLevel_007487B8[]; // 0x007487B8

typedef unsigned short Unicode;

struct D2HirelingTxt
{
    char unk0x00[0xC];
    int dwAct;
};

extern "C" const unsigned short gnHirelingDescStringIds[9]; // 0x006EE410
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromClassId(int bExpansion, int nClassId, D2HirelingTxt* pOldRecord); // 0x00656440
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromNameId(int bExpansion, int nNameId, D2HirelingTxt* pOldRecord); // 0x00656390


int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
extern const int gnSetMaskToBonusMappingTable[0x40]; // 0x006EE440
void __fastcall sub_M102_UseBonusCount_00663A10(int nCount);
D2UnitStrc* __stdcall INVENTORY_IsItemInInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063E070
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
int __fastcall sub_00663A20_SetItemBonusStates(D2UnitStrc* pItem, unsigned int nSetItemMask); // 0x00663A20
int __fastcall sub_00663B40_SetBonusStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3); // 0x00663B40

// 0x006634F0
int __fastcall sub_006634F0_RollSeededRecord(int nSeed, D2Rolled6634F0Strc* pOut, unsigned char nLevel)
{
    if (!nSeed)
        return 0;
    if (!pOut || nLevel > 2)
        return 0;

    const int nType = pOut->nType;
    if (nType < 0 || nType > 3)
        return 0;

    D2SeedStrc tSeed;
    pOut->wFlags = 0;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, nSeed);

    pOut->n34 = gtRollStart_00748558[nType].a;
    pOut->n20 = gtRollStart_00748558[nType].b;

    const int nRoll1 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount1_007484DC[nType]) + gnRollBase1_007484CC[nType];
    pOut->n04 = gtRoll1_00748578[nRoll1].a;
    pOut->n18 = gtRoll1_00748578[nRoll1].b;
    pOut->n20 += gtRoll1_00748578[nRoll1].d;
    pOut->n34 += gtRoll1_00748578[nRoll1].c;

    const int nRoll2 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount2_00748500[nType]) + gnRollBase2_007484F0[nType];
    pOut->n08 = gtRoll2_007485D8[nRoll2].a;
    pOut->n1C = gtRoll2_007485D8[nRoll2].b;
    pOut->n20 += gtRoll2_007485D8[nRoll2].d;
    pOut->n34 += gtRoll2_007485D8[nRoll2].c;

    const int nRoll3 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount3_00748524[nType]) + gnRollBase3_00748514[nType];
    if (nType < 3)
    {
        pOut->n0C = gtRoll3_00748638[nRoll3].a;
        pOut->n14 = 0;
    }
    else
    {
        pOut->n0C = 0;
        pOut->n14 = gtRoll3_00748638[nRoll3].a;
    }
    pOut->n24 = gtRoll3_00748638[nRoll3].c;
    pOut->n28 = gtRoll3_00748638[nRoll3].d;
    if (!gtRoll3_00748638[nRoll3].b)
        pOut->wFlags |= 1;
    pOut->n20 += gtRoll3_00748638[nRoll3].f;
    pOut->n34 += gtRoll3_00748638[nRoll3].e;

    const int nRoll4 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount4_00748548[nType]) + gnRollBase4_00748538[nType];
    pOut->n2C = gtRoll4_007486C8[nRoll4].a;
    pOut->n30 = gtRoll4_007486C8[nRoll4].d;
    if (pOut->n2C >= 9 && pOut->n2C <= 0xB)
        pOut->n10 = 1;
    else
        pOut->n10 = 0;
    pOut->n20 += gtRoll4_007486C8[nRoll4].c;
    pOut->n34 += gtRoll4_007486C8[nRoll4].b;

    if (nLevel)
    {
        pOut->n18 += gtRollLevel_007487B8[nLevel].a;
        pOut->n1C += gtRollLevel_007487B8[nLevel].b;
        pOut->n20 += gtRollLevel_007487B8[nLevel].c;
        pOut->n24 *= gtRollLevel_007487B8[nLevel].d;
        pOut->n28 *= gtRollLevel_007487B8[nLevel].e;
        pOut->n30 += gtRollLevel_007487B8[nLevel].f;
        pOut->n34 *= gtRollLevel_007487B8[nLevel].g;
    }
    return 1;
}

#include "gen/data/Source/D2Common/Unknown_006634F0.inc"

// 0x00663720
const Unicode* __fastcall MONSTERS_GetHirelingDescString(int nId)
{
    if (nId >= 0 && nId < sizeof(gnHirelingDescStringIds) / sizeof(gnHirelingDescStringIds[0]) && gnHirelingDescStringIds[nId])
    {
        return D2LANG_GetStringFromTblIndex(gnHirelingDescStringIds[nId]);
    }

    return 0;
}

// 0x00663750
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, int nNameId)
{
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromClassId(bExpansion, nClassId, 0);
    if (pHirelingTxtRecord)
    {
        return pHirelingTxtRecord->dwAct - 1;
    }

    pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromNameId(bExpansion, nNameId, 0);
    if (pHirelingTxtRecord)
    {
        return pHirelingTxtRecord->dwAct - 1;
    }

    return 0;
}

// 0x00663790
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel)
{
    return nExpPerLevel * nLevel * nLevel * (nLevel + 1);
}

// 0x006637B0
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling)
{
    const int nLevel = STATLIST_UnitGetStatValue(pHireling, 12, 0);
    unsigned int nCost = 15 * (nLevel * nLevel / 2);
    if (nCost > 50000)
    {
        nCost = 50000;
    }

    return nCost;
}

// 0x00663A10
static __declspec(noinline) int sub_00663A10_GetSetBonusCount(unsigned int nSetItemMask)
{
    if (nSetItemMask >= sizeof(gnSetMaskToBonusMappingTable) / sizeof(gnSetMaskToBonusMappingTable[0]))
        return 0;
    return gnSetMaskToBonusMappingTable[nSetItemMask];
}

void __stdcall sub_M102_Emit_00663A10(int nUnused, unsigned int nSetItemMask)
{
    sub_M102_UseBonusCount_00663A10(sub_00663A10_GetSetBonusCount(nSetItemMask));
}

__forceinline unsigned int ITEMS_GetStoreSetItemsMaskInline(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2UnitStrc* pInventoryItem = INVENTORY_IsItemInInventory(pUnit->pInventory, pItem);
    if (!pInventoryItem)
    {
        return 0;
    }

    if (INVENTORY_GetItemNodePage(pInventoryItem) != 3)
    {
        return 0;
    }

    return ITEMS_GetSetItemsMask(pUnit, pItem, 1);
}

// 0x00663CC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pItem || pItem->dwUnitType != 4 || !pUnit->pInventory)
    {
        return 0;
    }

    const unsigned int nSetItemMask = ITEMS_GetStoreSetItemsMaskInline(pUnit, pItem);

    if (a4 || !a3)
    {
        sub_00663A20_SetItemBonusStates(pItem, nSetItemMask);
    }

    sub_00663B40_SetBonusStatList(pUnit, pItem, a3);

    return 1;
}
