#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

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

struct D2ItemDataStrc
{
    union
    {
        int dwQualityNo;
        unsigned int quality;
    };
    char unk0x04[0x14];
    unsigned int dwItemFlags;
    unsigned char unk_1C[0x1A];
    unsigned short autoAffix;
    unsigned short prefix[3];
    unsigned short suffix[3];
};


struct D2MagicAffixTxt
{
    unsigned char pad00[0x65];
    unsigned char levelReq;
    unsigned char pad66;
    unsigned char characterClass;
    unsigned char classLevelReq;
};

struct D2UniqueItemsTxt { unsigned char pad00[0x36]; short levelReq; };

struct D2SetItemsTxt
{
    char unk0x00[0x2C];
    short nSetId;
    unsigned char nSetItemMask;
    unsigned char unk_2F[0x3];
    short levelReq;
    unsigned char unk_34[0x184];
};





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
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __fastcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062B5B0

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

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
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
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
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
                    nMask |= 1 << pRecord->nSetItemMask;
                }
            }
        }
    }

    return nMask;
}

static __forceinline int ITEMS_CheckIfSocketableByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }

    return 0;
}

static __forceinline int ITEMS_CheckIfSocketable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckIfSocketableByItemId(pItem->dwClassId);
    }

    return 0;
}

// 0x0062A900
static int sub_0062A900_CountSocketedItems(D2UnitStrc* pItem)
{
    int nSocketedItems = 0;
    if (!ITEMS_CheckIfSocketable(pItem))
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
    return data ? data->quality : 2;
}

// 0x0062BCB0
void __stdcall ITEMS_AddSockets(D2UnitStrc* item, int sockets) {
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
    maximum = Min(maximum, ITEMS_GetMaxSockets(item));
    sockets = Min(Max(sockets, 1), maximum);
    if (sockets > 0) {
        if (D2ItemDataStrc* data = GetData(item)) data->dwItemFlags |= 0x800;
        STATLIST_SetUnitStat(item, 194, sockets, 0);
    }
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

// 0x0062B450
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

    const int nLevelReq = ITEMS_GetLevelRequirement(pItem, pUnit);
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
