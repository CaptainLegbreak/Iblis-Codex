#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2TxtTables.h"
#include "D2Primitives.h"
#include "D2TxtItems.h"

#define D2_NORETURN __declspec(noreturn)

#define Min(a,b) ((a) < (b) ? (a) : (b))

#define Max(a,b) ((a) > (b) ? (a) : (b))

#define STAT_DEXTERITY 2

#define STAT_LEVEL 12

#define STAT_QUANTITY 70

#define IFLAG_IDENTIFIED 0x10

#define IFLAG_ETHEREAL 0x400000

struct D2InventoryStrc;

struct D2ItemDataStrc;

struct D2MagicAffixTxt;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

struct D2ItemsTxt;

struct D2StatStrc;

struct D2SkillsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc*, int); // 0x00627EC0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc*, int); // 0x00627F80

unsigned short __stdcall sub_00627F20_GetAutoAffix(D2UnitStrc*); // 0x00627F20

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int); // 0x00633EE0

int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830

int __stdcall ITEMS_GetFileIndex(D2UnitStrc*); // 0x00629DA0

D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int); // 0x00483470

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc*, unsigned int); // 0x00463720

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670

D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int); // 0x00483440

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc*); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc*); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc*); // 0x0063DFA0

int __stdcall STATLIST_CopyStats(D2UnitStrc*, int, D2StatStrc*, int); // 0x006261D0

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc*); // 0x00451F60

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480

static __declspec(noinline) int __fastcall sub_00628830_ApplyClassMinimum(D2MagicAffixTxt*, D2UnitStrc*, int);

typedef int BOOL;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

BOOL __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pPotion); // 0x0063C560

extern "C" D2_NORETURN void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszEmptyAssertText; // 0x006CC837

static __declspec(noinline) void __stdcall sub_006292F0_AddSocketablesCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost);

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

extern "C" const char gszItemsSourceFile_006E1150[]; // 0x006E1150

static __declspec(noinline) int sub_0062A900_CountSocketedItems(D2UnitStrc* pItem);

unsigned char __stdcall sub_0062BC20(D2UnitStrc*); // 0x0062BC20

void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

int __fastcall sub_0062B5B0(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062B5B0

struct D2UnitStrc;

#define ITEMS_ADD_BONUS_COSTS(nMult, nAdd, nValue, nBuyDiv)                                        \
    if (*pSellCost * (nValue) > 0xFFFF && (nMult))                                          \
    {                                                                                       \
        nSell += *pSellCost * (nValue) / 1024 * (nMult) + (nAdd);                           \
        nBuy += *pBuyCost * (nValue) / (nBuyDiv) * (nMult) + (nAdd);                          \
        tLoop.nRep += *pRepCost * (nValue) / 1024 * (nMult) + (nAdd);                             \
    }                                                                                       \
    else                                                                                    \
    {                                                                                       \
        nSell += (nMult) * *pSellCost * (nValue) / 1024 + (nAdd);                           \
        nBuy += *pBuyCost * (nMult) * (nValue) / (nBuyDiv) + (nAdd);                          \
        tLoop.nRep += *pRepCost * (nMult) * (nValue) / 1024 + (nAdd);                             \
    }

#define IFLAG_NEWITEM 0x00080000

#define IFLAG_ISEAR 0x00010000

#define IFLAG_COMPACTSAVE 0x00200000

#define IFLAG_UNK_GAMBLE 0x02000000

struct D2ItemStatCostTxt;

struct D2TimeModStrc;

union D2SeedStrc;

struct D2RunesTxt;

struct D2RuneDataTbl;

struct D2StatesTxt;

struct D2GemsTxt;

struct D2TimeModStrc
{
    int nPeriodOfDay;
    int nMin;
    int nMax;
};

int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pStatBuffer, int nBufferSize); // 0x00625C30

int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560

int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30

void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX); // 0x00620470

void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY); // 0x006204C0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0

void __stdcall sub_00629EA0(D2UnitStrc* pItem, int nFirst, int nSecond); // 0x00629EA0

void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat); // 0x0062A6C0

int __stdcall ITEMS_DecodeItemBitstreamComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion); // 0x0062CBE0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

static __declspec(noinline) int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion);

typedef char check_D2RunesTxt_size[sizeof(D2RunesTxt) == 0x120 ? 1 : -1];

int __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

D2RuneDataTbl* __fastcall DATATBLS_GetRuneDataTables(); // 0x00639CB0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerId); // 0x00629EA0

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

static int sub_0062E5D0_IsQuantityRepairable(D2UnitStrc* pItem); // 0x0062E5D0

// build: context sub_00623C60
static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwClassId;
    }
    return -1;
}

// 0x00628830
static int __fastcall sub_00628830_ApplyClassMinimum(D2MagicAffixTxt* record, D2UnitStrc* player, int required)
{
    if (!record)
        return required;
    if (record->characterClass != 255 && player && record->characterClass == sub_00623C60(player))
    {
        if (required <= record->classLevelReq)
            required = record->classLevelReq;
    }
    else
    {
        if (required <= record->levelReq)
            required = record->levelReq;
    }
    return required;
}

// build: context sub_00628830_Shim
// calling-convention shim (not game code)
int __fastcall sub_00628830_Shim(D2UnitStrc* item, D2UnitStrc* player)
{
    D2MagicAffixTxt* prefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(item, 0));
    D2MagicAffixTxt* suffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(item, 0));
    D2MagicAffixTxt* automatic = DATATBLS_GetMagicAffixTxtRecord(sub_00627F20_GetAutoAffix(item));
    int required = sub_00628830_ApplyClassMinimum(prefix, player, 0);
    required = sub_00628830_ApplyClassMinimum(suffix, player, required);
    required = sub_00628830_ApplyClassMinimum(automatic, player, required);
    return required;
}

// 0x00628BA0
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0x9A6);
    D2_ASSERT(hItem->dwUnitType == 4, 0x9A7);
    int nClassId = hItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    D2_ASSERT(pItemsTxtRecord, 0x9A9);
    if (pItemsTxtRecord->nAutoBelt || INVENTORY_HasSimilarPotionInBelt(pInventory, hItem) != -1) { return 1; }
    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00628D30
int __fastcall sub_00628D30_GetChargedSkillsCost(D2UnitStrc* pItem, int nBaseCost)
{
    D2StatStrc pStat[64];

    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    int nCost = 0;
    int i = 0;
    if (nStats > 0)
    {
        do
        {
            const int nLayer = pStat[i].nLayer;
            const int nSkillId = nLayer >> sgptDataTables->nStuff;
            const int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
            const int nMaxCharges = pStat[i].nValue >> 8;
            const int nCharges = pStat[i].nValue & 0xFF;
            if (nCharges < nMaxCharges)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inl(nSkillId);
                if (pSkillsTxtRecord)
                {
                    int nChargeCost;
                    if ((nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost > 0xFFFF && pSkillsTxtRecord->nCostMult)
                    {
                        nChargeCost = (nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost / 1024 * pSkillsTxtRecord->nCostMult;
                        nChargeCost += pSkillsTxtRecord->nCostAdd;
                    }
                    else
                    {
                        nChargeCost = pSkillsTxtRecord->nCostMult * (nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost / 1024;
                        nChargeCost += pSkillsTxtRecord->nCostAdd;
                    }
                    nCost += (nMaxCharges - nCharges) * nChargeCost / nMaxCharges;
                }
            }
            ++i;
        }
        while (i < nStats);
    }

    return nCost;
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x00628E70
void __fastcall ITEMS_CalculateAdditionalCostsForBonusStats(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor)
{
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    D2StatStrc pStat[511];
    D2TimeModStrc tTimeMod;
    int nStatId = 0;
    int nValue = 0;
    int nStats = 0;
    int nBuy = 0;
    int nSell = 0;
    struct
    {
        int i;
        int nRep;
    } tLoop;
    tLoop.nRep = 0;

    nStats = STATLIST_GetFullStatsDataFromUnit(pItem, pStat, 511);
    for (tLoop.i = 0; tLoop.i < nStats; ++tLoop.i)
    {
        nStatId = pStat[tLoop.i].nStat;
        nValue = STATLIST_GetUnitStatBonus(pItem, nStatId, pStat[tLoop.i].nLayer);
        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
            if (pItemStatCostTxtRecord)
            {
                if (pItemStatCostTxtRecord->nValShift)
                    nValue >>= pItemStatCostTxtRecord->nValShift;

                switch (pItemStatCostTxtRecord->nEncode)
                {
                case 1:
                {
                    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInl(pStat[tLoop.i].nLayer);
                    if (pSkillsTxtRecord)
                    {
                        ITEMS_ADD_BONUS_COSTS(pSkillsTxtRecord->nCostMult, pSkillsTxtRecord->nCostAdd, nValue, 4096);
                    }
                    break;
                }
                case 2:
                case 3:
                {
                    const int nLayer = pStat[tLoop.i].nLayer;
                    const int nSkillId = nLayer >> sgptDataTables->nStuff;
                    const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
                    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInl(nSkillId);
                    ITEMS_ADD_BONUS_COSTS(pSkillsTxtRecord->nCostMult, pSkillsTxtRecord->nCostAdd, nLevel, 4096);
                    break;
                }
                case 4:
                {
                    ITEMMODS_GetByTimeAdjustment(nValue, 0, 0, &tTimeMod.nPeriodOfDay, &tTimeMod.nMin, &tTimeMod.nMax);
                    const int nAverage = (tTimeMod.nMax + tTimeMod.nMin) / 2;
                    ITEMS_ADD_BONUS_COSTS(pItemStatCostTxtRecord->dwMultiply, pItemStatCostTxtRecord->dwAdd, nAverage, 1024);
                    break;
                }
                default:
                    ITEMS_ADD_BONUS_COSTS(pItemStatCostTxtRecord->dwMultiply, pItemStatCostTxtRecord->dwAdd, nValue, 1024);
                    break;
                }
            }
        }
    }

    *pSellCost += nSell / nDivisor;
    *pBuyCost += nBuy / nDivisor;
    *pRepCost += tLoop.nRep / nDivisor;
}

// 0x006292F0
static void __stdcall sub_006292F0_AddSocketablesCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost)
{
    int nSellCost = 0;
    int nBuyCost = 0;
    int nRepCost = 0;
    if (pItem->pInventory)
    {
        D2UnitStrc* pSocketable = INVENTORY_GetFirstItem(pItem->pInventory);
        while (pSocketable)
        {
            D2UnitStrc* pSocketItem = INVENTORY_UnitIsItem(pSocketable);
            pSocketable = INVENTORY_GetNextItem(pSocketable);
            if (pSocketItem)
            {
                const int nClassId = pSocketItem->dwClassId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                const int nSocketableCost = pItemsTxtRecord->dwCost / 2;
                nSellCost += nSocketableCost;
                nBuyCost += nSocketableCost;
                nRepCost += nSocketableCost;
            }
        }
        *pSellCost += nSellCost;
        *pBuyCost += nBuyCost;
        *pRepCost += nRepCost;
    }
}

// build: context sub_006292F0_Shim
// calling-convention shim (not game code)
int __fastcall sub_006292F0_Shim(D2UnitStrc* pItem, int nDivisor)
{
    int nSellCost = nDivisor;
    int nBuyCost = nDivisor * 2;
    int nRepCost = nDivisor * 3;
    sub_006292F0_AddSocketablesCost(pItem, &nSellCost, &nBuyCost, &nRepCost);
    return nSellCost + nBuyCost + nRepCost;
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

__declspec(noinline) int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem) // 0x00627E70
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

__declspec(noinline) unsigned int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile) // 0x006280A0
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

// 0x0062A370
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem)
{
    if (!pPlayer || !pSetItem || *(volatile int*)&pSetItem->dwUnitType != UNIT_ITEM || !pSetItem->pItemData)
    {
        return 0;
    }
    switch (*(volatile int*)&pSetItem->pItemData->dwQualityNo)
    {
    case ITEMQUAL_SET:
        break;
    default:
        return 0;
    }
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pSetItem));
    if (!pSetItemsTxtRecord)
    {
        return 0;
    }
    if (!sub_00483410_GetSetsTxtRecord(pSetItemsTxtRecord->nSetId))
    {
        return 0;
    }

    unsigned int nMask = 0;
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        if (INVENTORY_GetItemNodePage(pNode) == 3)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
            if (pItem && pItem->dwUnitType == UNIT_ITEM && (bDontIgnoreInputItem || pItem != pSetItem)
                && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET
                && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x144E, gszItemsSourceFile_006E1150)
                && !ITEMS_CheckItemFlag(pItem, 0x100, 0x144F, gszItemsSourceFile_006E1150))
            {
                D2SetItemsTxt* pRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pRecord && pRecord->nSetId == pSetItemsTxtRecord->nSetId)
                {
                    nMask |= 1 << (unsigned char)pRecord->nSetItems;
                }
            }
        }
    }

    return nMask;
}

static __forceinline int ITEMS_CheckIfSocketableByItemIdForceInl(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }

    return 0;
}

static __forceinline int ITEMS_CheckIfSocketableForceInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckIfSocketableByItemIdForceInl(pItem->dwClassId);
    }

    return 0;
}

// 0x0062A900
static int sub_0062A900_CountSocketedItems(D2UnitStrc* pItem)
{
    int nSocketedItems = 0;
    if (!ITEMS_CheckIfSocketableForceInl(pItem))
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pInventoryItem)
    {
        return 0;
    }

    do
    {
        ++nSocketedItems;
        pInventoryItem = INVENTORY_GetNextItem(pInventoryItem);
    }
    while (pInventoryItem);

    return nSocketedItems;
}

inline void ITEMS_SetItemFlag_Inline(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            if (bSet)
                pItemData->dwItemFlags |= dwFlag;
            else
                pItemData->dwItemFlags &= ~dwFlag;
        }
    }
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

inline void ITEMS_SetItemFlags(D2UnitStrc* pItem, unsigned int dwFlags)
{
    if (pItem)
    {
        switch (pItem->dwUnitType)
        {
        case UNIT_ITEM:
            if (pItem->pItemData)
                pItem->pItemData->dwItemFlags = dwFlags;
            break;
        }
    }
}

inline unsigned int ITEMS_GetItemFlags_Inline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}

inline void ITEMS_SetItemLevel_Inline(D2UnitStrc* pItem, int nItemLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemLevel = nItemLevel;
}

inline void ITEMS_SetMagicPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wMagicPrefix[nIndex] = nPrefix;
}

inline void ITEMS_SetMagicSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wMagicSuffix[nIndex] = nSuffix;
}

inline void ITEMS_SetRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wRarePrefix = nPrefix;
}

inline void ITEMS_SetRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wRareSuffix = nSuffix;
}

inline void ITEMS_SetBodyLoc(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nBodyLoc = nBodyLoc;
}

inline void ITEMS_SetInvPage_Inline(D2UnitStrc* pItem, char nInvPage)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nInvPage = nInvPage;
}

inline void ITEMS_SetEarLevel_Inline(D2UnitStrc* pItem, unsigned char nLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nEarLvl = nLevel;
}

inline char* ITEMS_GetEarName_Inline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->szPlayerName;
    return 0;
}

static __forceinline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

static __forceinline unsigned int BITMANIP_ReadInl(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

static __forceinline int ITEMS_ReadQuestItemDifficultyForceInl(D2BitBufferStrc* pBuffer, D2ItemStatCostTxt* pRecord)
{
    return (BITMANIP_ReadInl(pBuffer, pRecord->nSaveBits) - pRecord->dwSaveAdd) << pRecord->nValShift;
}

// 0x0062A970
static int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion)
{
    ITEMS_SetItemFormat(pItem, (unsigned short)sub_00411020_ReadBits(pBuffer, 10));

    const int nAnimMode = sub_00411020_ReadBits(pBuffer, 3);
    if (nAnimMode == 3 || nAnimMode == 5)
    {
        UNITS_SetXForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 16));
        UNITS_SetYForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 16));
    }
    else
    {
        ITEMS_SetBodyLoc(pItem, (unsigned char)sub_00411020_ReadBits(pBuffer, 4));
        UNITS_SetXForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 4));
        UNITS_SetYForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 4));
        ITEMS_SetInvPage_Inline(pItem, (char)(sub_00411020_ReadBits(pBuffer, 3) - 1));
    }
    UNITS_ChangeAnimMode(pItem, nAnimMode);

    if (ITEMS_GetItemFlags_Inline(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarName_Inline(pItem);
        ITEMS_SetFileIndex(pItem, sub_00411020_ReadBits(pBuffer, 3));
        ITEMS_SetEarLevel_Inline(pItem, (unsigned char)sub_00411020_ReadBits(pBuffer, 7));
        do
        {
            *szName = (char)sub_00411020_ReadBits(pBuffer, 7);
        }
        while (*szName++);
    }
    else
    {
        const unsigned int dwCode = sub_00411020_ReadBits(pBuffer, 32);
        const int nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
        if (pItem)
            pItem->dwClassId = nClassId;

        if (ITEMSIsA(pItem, 4))
        {
            if (sub_00411020_ReadBits(pBuffer, 1))
                STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, 32), 0);
            else
                STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, 12), 0);
        }

        if (ITEMSIsA(pItem, 22))
        {
            if (dwCode == ' cst')
                ITEMS_SetMagicSuffix(pItem, 0, 0);
            else if (dwCode == ' csi')
                ITEMS_AssignSuffix(pItem, 1, 0);
        }
    }

    if (dwVersion > 0x5C)
    {
        int nItemId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
        if (!pItemsTxtRecord)
            return -1;

        if (pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
        {
            D2ItemStatCostTxt* pRecord = DATATBLS_GetItemStatCostTxtRecord(356);
            if (!pRecord)
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1607);
                exit(-1);
            }
            const int nValue = ITEMS_ReadQuestItemDifficultyForceInl(pBuffer, pRecord);
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, 0x40, 0, 4, !pItem ? -1 : pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            }
            STATLIST_SetStat(pStatList, 356, nValue, 0);
        }
    }

    if (bCheckForHeader && dwVersion > 0x56 && sub_00411020_ReadBits(pBuffer, 1))
    {
        const int nFirst = sub_00411020_ReadBits(pBuffer, 32);
        sub_00629EA0(pItem, nFirst, sub_00411020_ReadBits(pBuffer, 32));
        if (dwVersion > 0x5D)
            sub_00411020_ReadBits(pBuffer, 32);
    }

    pItem->dwInitSeed = 0;
    SEED_InitLowSeed(&pItem->pSeed, 0);
    ITEMS_SetItemLevel_Inline(pItem, 1);
    if (pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwQualityNo = 2;
    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_0062A900_Shim(D2UnitStrc* pItem)
{
    return sub_0062A900_CountSocketedItems(pItem) + 1;
}

static __forceinline void GetDimensions(D2UnitStrc* item, unsigned char* width, unsigned char* height, const char* file, int line) {
    *width = 0;
    *height = 0;
    if (item && item->dwUnitType == 4) {
        D2ItemsTxt* txt = DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
        if (txt) { *width = txt->nInvWidth; *height = txt->nInvHeight; }
    }
}

static __forceinline D2ItemDataStrc* GetData(D2UnitStrc* item) {
    return (item && item->dwUnitType == 4 && item->pItemData) ? item->pItemData : 0;
}

static __forceinline unsigned int GetQuality(D2UnitStrc* item) {
    const int type = item ? item->dwUnitType : 6;
    D2ItemDataStrc* data = (type == 4 && item->pItemData) ? item->pItemData : 0;
    return data ? data->dwQualityNo : 2;
}

// 0x0062BCB0
void __stdcall sub_0062BCB0_AddSockets(D2UnitStrc* item, int sockets) {
    const int type = item ? item->dwUnitType : 6;
    if (type != 4) return;
    int maximum = 6;
    unsigned char width = 0, height = 0;
    GetDimensions(item, &width, &height, 0, 0);
    int area = height * width;
    if (area <= 6) maximum = area;
    if (!area) return;
    switch (GetQuality(item)) {
    case 5: case 7: {
        int existing = STATLIST_UnitGetStatValue(item, 194, 0);
        if (existing > 0) sockets = existing;
        else maximum = Min(maximum, 1);
        break;
    }
    case 6: maximum = Min(maximum, 2); break;
    case 4: maximum = Min(maximum, 4); break;
    case 8: case 9: maximum = Min(maximum, 3); break;
    }
    maximum = Min(maximum, sub_0062BC20(item));
    sockets = Min(Max(sockets, 1), maximum);
    if (sockets > 0) {
        if (D2ItemDataStrc* data = GetData(item)) data->dwItemFlags |= 0x800;
        STATLIST_SetUnitStat(item, 194, sockets, 0);
    }
}

static int ITEMS_IsMagSetRarUniCrfOrTmp_Inline(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && pItem->pItemData)
    {
        switch (pItem->pItemData->dwQualityNo)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return 1;
        default:
            return 0;
        }
    }
    return 0;
}

static __forceinline int ITEMS_IsOfType(D2UnitStrc* pItem, int nItemType)
{
    return ITEMSIsA(pItem, nItemType);
}

// 0x0062BED0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem)
{
    int nRuneItemIds[6];

    if (!pItem)
    {
        return 0;
    }

    if (ITEMS_IsMagSetRarUniCrfOrTmp_Inline(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(sub_00623C60(pItem))->nQuest)
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pSocketFiller = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pSocketFiller)
    {
        return 0;
    }

    int nSocketedItems = 0;
    while (pSocketFiller)
    {
        D2UnitStrc* pRune = INVENTORY_UnitIsItem(pSocketFiller);
        if (!pRune)
        {
            return 0;
        }

        nRuneItemIds[nSocketedItems++] = pRune->dwClassId;
        pSocketFiller = INVENTORY_GetNextItem(pSocketFiller);
    }

    const int nSockets = (unsigned char)ITEMS_GetSockets(pItem);
    if (nSockets != nSocketedItems)
    {
        return 0;
    }

    D2RuneDataTbl* pRuneDataTbl = DATATBLS_GetRuneDataTables();
    if (!pRuneDataTbl)
    {
        return 0;
    }

    for (int i = 0; i < pRuneDataTbl->nRunesTxtRecordCount; ++i)
    {
        D2RunesTxt* pRunesTxtRecord = &pRuneDataTbl->pRunesTxt[i];
        if (pRunesTxtRecord->nComplete)
        {
            int nRuneCounter = 0;
            bool bMatch = true;

            while (nRuneCounter < 6 && pRunesTxtRecord->nRune[nRuneCounter] > 0)
            {
                if (nSocketedItems < nRuneCounter || nRuneItemIds[nRuneCounter] != pRunesTxtRecord->nRune[nRuneCounter])
                {
                    bMatch = false;
                    break;
                }

                ++nRuneCounter;
            }

            if (bMatch && nRuneCounter >= nSockets)
            {
                bool isItemTypeIgnored = false;
                for (int nETypeCounter = 0; nETypeCounter < 3 && pRunesTxtRecord->wEType[nETypeCounter]; ++nETypeCounter)
                {
                    if (ITEMSIsA(pItem, pRunesTxtRecord->wEType[nETypeCounter]))
                    {
                        isItemTypeIgnored = true;
                        break;
                    }
                }

                if (!isItemTypeIgnored)
                {
                    for (int nITypeCounter = 0; nITypeCounter < 6 && pRunesTxtRecord->wIType[nITypeCounter]; ++nITypeCounter)
                    {
                        if (ITEMSIsA(pItem, pRunesTxtRecord->wIType[nITypeCounter]))
                        {
                            return pRunesTxtRecord;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

inline int ITEMS_CheckIfSocketableAlt_Inl(D2UnitStrc* pItem)
{
    if (pItem && (!pItem ? 6 : pItem->dwUnitType) == 4)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            return pItemsTxtRecord->nHasInv;
        }
    }

    return 0;
}

inline unsigned int ITEMS_CheckItemFlag_Inl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData_Inl(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == 4 && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_GetItemQuality_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

inline unsigned short ITEMS_GetPrefixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicPrefix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetSuffixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicSuffix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetAutoAffix_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wAutoAffix;
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord_Inl(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

static unsigned char sub_0062A250(int nTransform, int nColor)
{
    if (nTransform <= 0 || nTransform >= 9 || nColor < 0 || nColor >= 0x15)
    {
        return 0;
    }

    unsigned char nPacked = nColor & 0x1F;
    nPacked += nTransform << 5;
    return nPacked;
}

// 0x0062C100
unsigned char* __stdcall ITEMS_GetColor(D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pColor, int nTransType)
{
    D2MagicAffixTxt* pMagicAffixTxtRecord;
    int i;

    if (pItem)
    {
        if (pPlayer)
        {
            for (int i = 0; i < sgptDataTables->nColourStates; ++i)
            {
                const short nState = sgptDataTables->pColourStates[i];
                if (STATES_CheckState(pPlayer, nState))
                {
                    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord_Inl(nState);
                    if (pStatesTxtRecord && pStatesTxtRecord->nItemTrans < 0x15 && ITEMSIsA(pItem, pStatesTxtRecord->wItemType))
                    {
                        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_00451F60_UnitClassId(pItem)))
                        {
                            return sub_00600C20(pItemsTxtRecord->nTransform, pStatesTxtRecord->nItemTrans);
                        }
                    }
                }
            }
        }

        switch (ITEMS_GetItemQuality_Inl(pItem))
        {
        case 4:
        case 6:
            i = 0;
            do
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                    *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

                    if (nTransType)
                    {
                        return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);

            i = 0;
            do
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                    *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

                    if (nTransType)
                    {
                        return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);
            break;

        case 7:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
            if (!pItemsTxtRecord)
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

            if (nTransType)
            {
                if (pUniqueItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                int const nUniqueColor = pUniqueItemsTxtRecord->nChrTransform;
                *pColor = sub_0062A250(pItemsTxtRecord->nTransform, nUniqueColor);
                int const nInventoryTransform = pItemsTxtRecord->nInvTrans;
                return sub_00600C20(nInventoryTransform, pUniqueItemsTxtRecord->nInvTransform);
            }

            if (pUniqueItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
            return sub_00600C20(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
        }
        case 5:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pSetItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pSetItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                int const nTransform = pItemsTxtRecord->nTransform;
                int const nSetColor = pSetItemsTxtRecord->nChrTransform;
                *pColor = sub_0062A250(nTransform, nSetColor);
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pSetItemsTxtRecord->nInvTransform);
            }

            if (pSetItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
            return sub_00600C20(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
        }
        default:
            if (ITEMS_CheckIfSocketableAlt_Inl(pItem) && sub_0062BC20(pItem) > 0 && ITEMS_CheckItemFlag_Inl(pItem, 0x800))
            {
                D2InventoryStrc* pInventory = pItem->pInventory;
                D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pInventory);
                if (pInventoryItem)
                {
                    pInventoryItem = INVENTORY_UnitIsItem(pInventoryItem);
                    if (pInventoryItem && ITEMSIsA(pInventoryItem, 0x14))
                    {
                        D2ItemsTxt* pGemItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pInventoryItem ? -1 : pInventoryItem->dwClassId);
                        D2_ASSERT(pGemItemsTxtRecord, 0x1271);

                        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pGemItemsTxtRecord->dwGemOffset);
                        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                        *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                        if (nTransType)
                        {
                            return sub_00600C20(pItemsTxtRecord->nInvTrans, pGemsTxtRecord->nTransform);
                        }

                        return sub_00600C20(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                    }
                }
            }
            break;
        }

        pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix_Inl(pItem));
        if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

            if (nTransType)
            {
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
            }

            return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
        }
    }

    return 0;
}

inline void ITEMS_ClearItemFlags(D2UnitStrc* pItem)
{
    const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
    if (nUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemFlags = 0;
}

// 0x0062E430
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail)
{
    D2BitBufferStrc tBuffer;
    int bGamble = 0;

    BITMANIP_Initialize(&tBuffer, pBitstream, nSize);
    if (bCheckForHeader && BITMANIP_ReadSigned(&tBuffer, 16) != 0x4D4A)
    {
        *pFail = 1;
        return 0;
    }

    *pFail = 0;

    unsigned int dwItemFlags = sub_00411020_ReadBits(&tBuffer, 32);
    if (dwItemFlags & IFLAG_UNK_GAMBLE)
    {
        bGamble = 1;
        dwItemFlags &= ~IFLAG_UNK_GAMBLE;
    }

    ITEMS_ClearItemFlags(pItem);
    ITEMS_SetItemFlag_Inline(pItem, dwItemFlags, 1);
    ITEMS_SetItemFlag_Inline(pItem, IFLAG_NEWITEM, 0);
    ITEMS_SetItemLevel_Inline(pItem, 1);
    ITEMS_SetMagicPrefix(pItem, 0, 0);
    ITEMS_SetMagicSuffix(pItem, 0, 0);
    ITEMS_SetMagicPrefix(pItem, 0, 1);
    ITEMS_SetMagicSuffix(pItem, 0, 1);
    ITEMS_SetMagicPrefix(pItem, 0, 2);
    ITEMS_SetMagicSuffix(pItem, 0, 2);
    ITEMS_SetRarePrefix(pItem, 0);
    ITEMS_SetRareSuffix(pItem, 0);

    if (dwItemFlags & IFLAG_COMPACTSAVE)
    {
        const int nResult = ITEMS_DecodeItemBitstreamCompact(pItem, &tBuffer, bCheckForHeader, dwVersion);
        if (pSocketedItemCount)
            *pSocketedItemCount = 0;
        if (nResult <= 0)
            *pFail = 1;
    }
    else
    {
        if (ITEMS_DecodeItemBitstreamComplete(pItem, &tBuffer, bCheckForHeader, bGamble, pSocketedItemCount, dwVersion) <= 0)
            *pFail = 1;
    }

    return BITMANIP_GetSize(&tBuffer);
}

inline D2ItemDataStrc* ITEMS_GetItemDataTypeInl(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return nType == UNIT_ITEM ? pItem->pItemData : 0;
}

inline int ITEMS_CheckItemFlagLineInl(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataTypeInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

// calling-convention shim (not game code)
static __declspec(noinline) int sub_0062E5D0_IsQuantityRepairable(D2UnitStrc* pItem)
{
    if (ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem))
    {
        return 1;
    }
    return 0;
}

// 0x0062E660
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem)
{
    if (!ITEMS_CheckItemFlagLineInl(pItem, IFLAG_IDENTIFIED, 0, 0) || ITEMS_CheckItemFlagLineInl(pItem, IFLAG_ETHEREAL, 0, 0))
    {
        return 0;
    }

    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
    {
        return 1;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_00555C90_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
    if (!pItemTypesTxtRecord || !pItemTypesTxtRecord->nRepair)
    {
        return 0;
    }

    if (sub_0062E5D0_IsQuantityRepairable(pItem))
    {
        return 1;
    }

    return ITEMS_HasDurability(pItem) != 0;
}

inline int ITEMS_CheckIfSocketableByItemIdInl(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }
    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

inline int ITEMS_CheckItemFlagInl(D2UnitStrc* pItem, unsigned int nFlag)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & nFlag;
    }
    return 0;
}

inline D2ItemsTxt* ITEMS_GetItemsTxtRecordInl(D2UnitStrc* pItem)
{
    return DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
}

static void __stdcall sub_0062B450_GetSocketedStatBonus(int nStatId, int* pValue, D2UnitStrc* pItem)
{
    *pValue = 0;
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (ITEMS_CheckIfSocketableByItemIdInl(pItem->dwClassId))
        {
                D2InventoryStrc* pInventory = pItem->pInventory;
            for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
            {
                D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
                if (sub_00451F70_GetUnitMode(pItem) == IMODE_EQUIP)
                {
                    *pValue += STATLIST_UnitGetStatValue(pSocketed, nStatId, 0);
                }
            }
        }
    }
}

// 0x0062EAF0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* pStrength, int* pDexterity, int* pLevel)
{
    int nStrSocketBonus;
    int nBaseReqDex;
    int bIdentified;

    if (pStrength)
    {
        *pStrength = FALSE;
    }
    if (pDexterity)
    {
        *pDexterity = 0;
    }
    if (pLevel)
    {
        *pLevel = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    D2ItemsTxt* pItemsTxtRecord = nType == UNIT_ITEM ? ITEMS_GetItemsTxtRecordInl(pItem) : 0;
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int bStrReqMet = TRUE;
    int bDexReqMet = TRUE;
    int bLevelReqMet = TRUE;
    if (pItem->dwUnitType == UNIT_ITEM)
    {
        const D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            bIdentified = pItemData->dwItemFlags & IFLAG_IDENTIFIED;
        }
        else
        {
            bIdentified = FALSE;
        }
    }
    else
    {
        bIdentified = FALSE;
    }
    const int nBaseReqStr = pItemsTxtRecord->wReqStr;
    nBaseReqDex = pItemsTxtRecord->wReqDex;

    int nReqStrBonus = 0;
    int nReqDexBonus = 0;
    if (const int nReqPctBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_REQ_PERCENT, 0))
    {
        nReqStrBonus = DATATBLS_ApplyRatio(nBaseReqStr, nReqPctBonus, 100);
        nReqDexBonus = DATATBLS_ApplyRatio(nBaseReqDex, nReqPctBonus, 100);
    }

    if (ITEMS_CheckItemFlagInl(pItem, IFLAG_ETHEREAL))
    {
        nReqStrBonus -= 10;
        nReqDexBonus -= 10;
    }

    const int nStrength = STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    if (nStrength <= 0)
    {
        bStrReqMet = 0;
    }
    else
    {
        const int nReqStr = nBaseReqStr + nReqStrBonus;
        if (nStrength < nReqStr)
        {
            bStrReqMet = 0;
        }
        else if (bEquipping && STATLIST_GetOwner(pItem, 0))
        {
            nStrSocketBonus = 0;
            sub_0062B450_GetSocketedStatBonus(STAT_STRENGTH, &nStrSocketBonus, pItem);
            const int nAdjusted = nStrength - nStrSocketBonus;
            if (nAdjusted <= 0)
            {
                bStrReqMet = 0;
            }
            else if (nAdjusted < nReqStr)
            {
                bStrReqMet = 0;
            }
        }
    }

    const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
    if (nDexterity <= 0)
    {
        bDexReqMet = 0;
    }
    else
    {
        const int nReqDex = nBaseReqDex + nReqDexBonus;
        if (nDexterity < nReqDex)
        {
            bDexReqMet = 0;
        }
        else if (bEquipping)
        {
            int nSocketBonus = 0;
            sub_0062B450_GetSocketedStatBonus(STAT_DEXTERITY, &nSocketBonus, pItem);
            const int nAdjusted = nDexterity - nSocketBonus;
            if (nAdjusted <= 0)
            {
                bDexReqMet = 0;
            }
            if (nAdjusted < nReqDex)
            {
                bDexReqMet = 0;
            }
        }
    }

    const int nLevelReq = sub_0062B5B0(pItem, pUnit);
    if (nLevelReq != -1 && STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) < nLevelReq)
    {
        bLevelReqMet = 0;
    }

    if (pStrength)
    {
        *pStrength = bStrReqMet;
    }
    if (pDexterity)
    {
        *pDexterity = bDexReqMet;
    }
    if (pLevel)
    {
        *pLevel = bLevelReqMet;
    }

    if (bStrReqMet && bDexReqMet && bLevelReqMet && bIdentified)
    {
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) <= 0)
        {
            return 0;
        }

        const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
        if (nClass == PCLASS_INVALID)
        {
            return 1;
        }

        if (!pUnit)
        {
            return 0;
        }

        const int nUnitType = pUnit->dwUnitType;
        if (pUnit->dwUnitType == UNIT_MONSTER && nClass == PCLASS_BARBARIAN)
        {
            const int nMonsterId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
            if (nMonsterId >= MONSTER_ACT5HIRE1 && nMonsterId <= MONSTER_ACT5HIRE2)
            {
                return 1;
            }
        }

        if (nUnitType == UNIT_PLAYER && nClass == pUnit->dwClassId)
        {
            return 1;
        }
    }

    return 0;
}
