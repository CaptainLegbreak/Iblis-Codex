#include "D2Game.h"
#include "D2Txt.h"
#include "D2Path.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2LowQualityItemsTxt;
union D2SeedStrc;
struct D2MagicAffixTxt;
struct D2RareAffixIndexAndPtrStrc;
struct D2ItemsTxt;
struct D2LowQualityItemDataTbl;


struct D2ItemDropStrc
{
    char unk0x00[0x68];
    int nPrefix[3];
    int nSuffix[3];
};

struct D2MagicAffixTxt
{
    char unk0x00[0x5C];
    unsigned int dwGroup;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280


short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0
void __stdcall ITEMMODS_AssignProperty(int nMode, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nSet, int nUnused); // 0x0065FEC0
extern const int gnRareAffixCounts_006E3014[]; // 0x006E3014
static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1E80


struct D2LowQualityItemDataTbl
{
    int nLowQualityItemsTxtRecordCount;
    D2LowQualityItemsTxt* pLowQualityItemsTxt;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2LowQualityItemDataTbl* __fastcall DATATBLS_GetLowQualityItemDataTables(); // 0x006375B0

static __forceinline unsigned int sub_RareSeedRoll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int sub_RareSeedRollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        if ((nMax - 1) & nMax)
        {
            return sub_RareSeedRoll(pSeed) % nMax;
        }
        else
        {
            return sub_RareSeedRoll(pSeed) & (nMax - 1);
        }
    }

    return 0;
}

static unsigned short __stdcall sub_005C19A0_RollRareAffixOld(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].nIndex = nAffixIndex + i;
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

static unsigned short __stdcall sub_005C1AB0_RollRareAffixNew(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].nIndex = nAffixIndex + i;
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

static __forceinline unsigned short D2GAME_RollRareAffixInline(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C1AB0_RollRareAffixNew(pItem, bPrefix);
    }

    return sub_005C19A0_RollRareAffixOld(pItem, bPrefix);
}

static __forceinline bool ITEMS_HasAffixOrGroupInline(D2UnitStrc* pItem, unsigned short nAffix, int bPrefix)
{
    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        const unsigned short nSlotAffix = bPrefix ? ITEMS_GetPrefixId(pItem, nAffixSlot) : ITEMS_GetSuffixId(pItem, nAffixSlot);
        if (D2MagicAffixTxt* pSlotRecord = DATATBLS_GetMagicAffixTxtRecord(nSlotAffix))
        {
            D2MagicAffixTxt* pAffixRecord = DATATBLS_GetMagicAffixTxtRecord(nAffix);
            if (nAffix == nSlotAffix || pAffixRecord->dwGroup == pSlotRecord->dwGroup)
            {
                return true;
            }
        }
    }

    return false;
}

static __forceinline short ITEMS_RollMagicAffixesInline(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

static __forceinline void ITEMS_ApplyRareAffixesInline(D2UnitStrc* pItem)
{
    ITEMS_SetItemFlag(pItem, 0x10, 0);

    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        if (D2MagicAffixTxt* pPrefixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pPrefixRecord, 0, 0);
        }

        if (D2MagicAffixTxt* pSuffixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pSuffixRecord, 0, 0);
        }
    }
}

// 0x005C1BF0
static int __stdcall sub_005C1BF0_RollRareItemNew(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int bSuffixesDone = 0;
    int bPrefixesDone = 0;

    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    int nAffixCount = 0;
    if (ITEMS_GetItemType(pItem) == 0x3A)
    {
        nAffixCount = sub_00472280(pSeed, 3, 2);
    }
    else
    {
        nAffixCount = gnRareAffixCounts_006E3014[sub_RareSeedRollLimited(pSeed, 8)];
    }

    for (int i = 0; i < nAffixCount; ++i)
    {
        if (bPrefixesDone && bSuffixesDone)
        {
            break;
        }

        int bSuffix;
        if (bPrefixesDone)
        {
            bSuffix = 1;
        }
        else if (bSuffixesDone)
        {
            bSuffix = 0;
        }
        else
        {
            bSuffix = sub_RareSeedRoll(pSeed) & 1;
        }

        if (!bSuffix)
        {
            D2_ASSERT(nPrefixes < 3, 0x31D);

            const unsigned short nPrefix = ITEMS_RollMagicAffixesNew(pItem, 1, 1, 0, 1, pItemDrop->nPrefix[nPrefixes], 0);
            if (nPrefix > 0)
            {
                ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                ++nPrefixes;
                if (nPrefixes >= 3)
                {
                    bPrefixesDone = 1;
                }
            }
            else
            {
                bPrefixesDone = 1;
                --i;
            }
        }
        else
        {
            D2_ASSERT(nSuffixes < 3, 0x32E);

            const unsigned short nSuffix = ITEMS_RollMagicAffixesNew(pItem, 1, 1, 0, 0, pItemDrop->nSuffix[nSuffixes], 0);
            if (nSuffix > 0)
            {
                ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                ++nSuffixes;
                if (nSuffixes >= 3)
                {
                    bSuffixesDone = 1;
                }
            }
            else
            {
                bSuffixesDone = 1;
                --i;
            }
        }
    }

    if (!nPrefixes && !nSuffixes)
    {
        return 0;
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

#include "gen/data/Source/D2Game/Unknown_005C1BF0.inc"

// 0x005C1E80
static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    unsigned int nAffixCount = 0;
    if (ITEMS_GetItemType(pItem) == 0x3A)
    {
        nAffixCount = sub_00472280(pSeed, 3, 2);
    }
    else
    {
        nAffixCount = sub_00472280(pSeed, 4, 3);
    }

    for (unsigned int i = 0; i < nAffixCount; ++i)
    {
        int bSuffix = sub_RareSeedRoll(pSeed) & 1;
        if (nPrefixes == 3)
        {
            bSuffix = 1;
        }
        else if (nSuffixes == 3)
        {
            bSuffix = 0;
        }

        if (!bSuffix)
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nPrefix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 1, 0);
                if (nPrefix <= 0)
                {
                    break;
                }

                if (ITEMS_HasAffixOrGroupInline(pItem, nPrefix, 1))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignPrefix(pItem, 0, nPrefixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                    ++nPrefixes;
                    break;
                }
            }
        }
        else
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nSuffix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 0, 0);
                if (nSuffix <= 0)
                {
                    break;
                }

                if (ITEMS_HasAffixOrGroupInline(pItem, nSuffix, 0))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignSuffix(pItem, 0, nSuffixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                    ++nSuffixes;
                    break;
                }
            }
        }
    }

    if (!nPrefixes && !nSuffixes)
    {
        return 0;
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

// 0x005C21A0
int __fastcall D2GAME_RollRareItem_6FC53360(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (!ITEMS_CanBeRare(pItem))
    {
        return 0;
    }

    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C1BF0_RollRareItemNew(pItemDrop, pItem);
    }

    return ITEMS_RollLegacyRareItem(pItemDrop, pItem);
}

static __declspec(noinline) int __stdcall sub_005C0D40_PercentWithMinimum(int nValue, int nPercent, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

// 0x005C2AF0
int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            unsigned int nMaxDurability = pTxt->nDurability / 3;
            if (!nMaxDurability)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, 0x48, nDurability, 0);
            STATLIST_SetUnitStat(pItem, 0x49, nMaxDurability, 0);
        }
    }

    if (ITEMSIsA(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x16, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x16, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x15, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x15, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x18, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x18, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x17, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x17, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x9F, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, 0x9F, nMinThrowDamage, 0);

            const int nMaxThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0xA0, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, 0xA0, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMSIsA(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, 0x1F, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x1F, nArmorClass, 0);
        nResult = 1;
    }

    return nResult;
}

// 0x005C2D40
int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            int nMaxDurability = 33 * pTxt->nDurability / 100;
            if (nMaxDurability < 1)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = (unsigned int)nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, 0x48, nDurability, 0);
            STATLIST_SetUnitStat(pItem, 0x49, nMaxDurability, 0);
        }
    }

    if (ITEMSIsA(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x16, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x16, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x15, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x15, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x18, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x18, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x17, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x17, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x9F, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, 0x9F, nMinThrowDamage, 0);

            const int nMaxThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0xA0, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, 0xA0, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMSIsA(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, 0x1F, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x1F, nArmorClass, 0);
        nResult = 1;
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return nResult;
}
