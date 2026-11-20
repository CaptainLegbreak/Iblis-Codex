#include "D2Game.h"
#include "D2Records.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
struct D2UnitStrc;

union D2SeedStrc;
struct D2MagicAffixTxt;
struct D2MagicAffixIndexAndPtrStrc;
struct D2SkillPairStrc;
struct D2RareAffixIndexAndPtrStrc;
struct D2ItemsTxt;
struct D2SetItemsTxt;

struct D2MagicAffixIndexAndPtrStrc
{
    int nAffixId;
    D2MagicAffixTxt* pMagicAffixRecord;
};

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0

struct D2SkillPairStrc
{
    int nA;
    int nB;
};

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc*); // 0x004DC0B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670

short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0
extern "C" void __stdcall sub_00627EF0(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0
extern "C" void __stdcall sub_00627FB0(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010
extern "C" void __stdcall sub_00628070(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMMODS_AssignProperty(int nMode, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nSet, int nUnused); // 0x0065FEC0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall sub_005C2740_RollLegacySetItem(D2UnitStrc* pItem); // 0x005C2740
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0
int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2AF0
int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2D40

// 0x005C0D00
static int __stdcall sub_005C0D00_ITEMS_AddPotentialMagicAffix(int nAffixId, D2MagicAffixTxt* pRecord, D2MagicAffixIndexAndPtrStrc* pAffixes, int nCount)
{
    if (nCount < 0x1FF)
    {
        pAffixes[nCount].pMagicAffixRecord = pRecord;
        pAffixes[nCount].nAffixId = nAffixId;
        ++nCount;
    }

    return nCount;
}

// 0x005C1500
static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup)
{
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall sub_M11_Emit_005C0D00(D2UnitStrc* pItem, D2MagicAffixTxt* pFirst, int nRecords, int nBase)
{
    D2MagicAffixIndexAndPtrStrc tAffixes[0x200];
    int nCount = 0;
    for (int i = 0; i < nRecords; ++i)
    {
        D2MagicAffixTxt* pRecord = &pFirst[i];
        if (ITEMMODS_HasAffixWithGroup(pItem, pRecord->dwGroup))
        {
            continue;
        }

        nCount = sub_005C0D00_ITEMS_AddPotentialMagicAffix(i + nBase, pRecord, tAffixes, nCount);
    }

    return nCount ? tAffixes[nCount - 1].nAffixId : 0;
}

// 0x005C0D20
static D2SkillPairStrc* __stdcall sub_005C0D20_GetArrayEntry(int nCount, D2SkillPairStrc* pArray, int nIndex)
{
    if (nIndex >= nCount)
    {
        return 0;
    }
    return &pArray[nIndex];
}

D2SkillPairStrc* __stdcall sub_K13_Emit_005C0D20(D2SkillPairStrc* pArray, int nIndex, int nCount)
{
    return sub_005C0D20_GetArrayEntry(nCount, pArray, nIndex);
}

// 0x005C0D40
static int __stdcall sub_005C0D40_PercentWithMinimum(int nPercent, int nValue, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

int __stdcall sub_K13_Emit_005C0D40(int nValue, int nPercent)
{
    return sub_005C0D40_PercentWithMinimum(nPercent, nValue, 2);
}

static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

// 0x005C0D70
void __stdcall sub_005C0D70(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId)
{
    int nSkills[3] = { -1, -1, -1 };
    int nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
    int nSkillCount;
    if (nRoll > 90)
        nSkillCount = 3;
    else if (nRoll > 70)
        nSkillCount = 2;
    else if (nRoll > 30)
        nSkillCount = 1;
    else
        return;
    int nBaseTier = 1;
    if (nItemLevel > 24)
        nBaseTier = 4;
    else if (nItemLevel > 18)
        nBaseTier = 3;
    else if (nItemLevel > 11)
        nBaseTier = 2;
    for (int i = 0; i < nSkillCount; ++i)
    {
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        int nTier = nBaseTier;
        if (nRoll > 80)
            nTier = nBaseTier + 1;
        else if (nRoll <= 30)
        {
            if (nRoll > 10)
                nTier = nBaseTier - 1;
            else
                nTier = nBaseTier - 2;
        }
        nItemLevel = nTier;
        if (nItemLevel < 1)
            nItemLevel = 1;
        int nSkillId;
        do
        {
            const int nSkillRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 5;
            nSkillId = nClassFirstSkillId + 5 * (nItemLevel - 1) + nSkillRoll;
        }
        while (nSkillId == 73 || nSkillId == nSkills[0] || nSkillId == nSkills[1] || nSkillId == nSkills[2]);
        nSkills[i] = nSkillId;
        nItemLevel = 1;
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        if (nRoll >= 90)
            nItemLevel = 3;
        else if (nRoll >= 60)
            nItemLevel = 2;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetUnitMemoryPool(pItem), 0x40, 0, 4, sub_00451F50_GetUnitGUID(pItem));
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
        }
        if (pStatList)
            STATLIST_SetStatIfListIsValid(pStatList, 107, nItemLevel, nSkillId);
    }
}

// 0x005C19A0
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
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            tAffixes[nMax].nIndex = nAffixIndex + i;
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

// 0x005C1AB0
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
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            tAffixes[nMax].nIndex = nAffixIndex + i;
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

// 0x005C1BC0
unsigned short __fastcall sub_005C1BC0_RollTemperedAffix(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C1AB0_RollRareAffixNew(pItem, bPrefix);
    }

    return sub_005C19A0_RollRareAffixOld(pItem, bPrefix);
}

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

// 0x005C21D0
int __fastcall sub_005C21D0_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    sub_00628070(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    const int nItemLvl = pItemDrop->nItemLvl;
    int nMinAffixes = 1;
    if (nItemLvl > 30)
    {
        nMinAffixes = 2;
    }
    if (nItemLvl > 50)
    {
        nMinAffixes = 3;
    }
    if (nItemLvl > 70)
    {
        nMinAffixes = 4;
    }

    unsigned int nAffixCount = sub_RareSeedRollLimited(pSeed, 5);
    if ((unsigned int)nMinAffixes > nAffixCount)
    {
        nAffixCount = nMinAffixes;
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
                const unsigned short nPrefix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 1, pItemDrop->nPrefix[nPrefixes]);
                if (ITEMS_HasAffixOrGroupInline(pItem, nPrefix, 1))
                {
                    if (nAttempt++ > 250)
                    {
                        sub_00627EF0(pItem, 0, nPrefixes);
                        break;
                    }
                }
                else
                {
                    sub_00627EF0(pItem, nPrefix, nPrefixes);
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
                const unsigned short nSuffix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 0, pItemDrop->nSuffix[nSuffixes]);
                if (ITEMS_HasAffixOrGroupInline(pItem, nSuffix, 0))
                {
                    if (nAttempt++ > 250)
                    {
                        sub_00627FB0(pItem, 0, nSuffixes);
                        break;
                    }
                }
                else
                {
                    sub_00627FB0(pItem, nSuffix, nSuffixes);
                    ++nSuffixes;
                    break;
                }
            }
        }
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    sub_005C1260(pItem, pItemDrop);
    return 1;
}

static int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int nLegibleSets = 0;
    int nAccumulatedRarity = 0;
    int nIndex = -1;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nItemFormat = ITEMS_GetItemFormat(pItem);
    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    const int nItemLevel = ITEMS_GetItemLevel(pItem);
    int rarityData[512];

    for (int i = 0; i < sgptDataTables->nSetItemsTxtRecordCount; ++i)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = &sgptDataTables->pSetItemsTxt[i];
        if ((pSetItemsTxtRecord->wVersion < 100 || nItemFormat >= 100) && pSetItemsTxtRecord->wLvl <= nItemLevel
            && dwCode == pSetItemsTxtRecord->dwItemCode
            && (pSetItemsTxtRecord->nSetId != 29 || pItemDrop->dwFlags2 & 1))
        {
            if (pItemDrop->nItemIndex && pItemDrop->nItemIndex - 1 == i)
            {
                nIndex = i;
            }

            rarityData[2 * nLegibleSets] = i;
            rarityData[2 * nLegibleSets + 1] = pSetItemsTxtRecord->dwRarity;
            if (!pSetItemsTxtRecord->dwRarity)
            {
                rarityData[2 * nLegibleSets + 1] = 1;
            }

            nAccumulatedRarity += rarityData[2 * nLegibleSets + 1];
            ++nLegibleSets;
        }
    }

    int nFileIndex = nIndex;
    if (nIndex < 0)
    {
        if (!nAccumulatedRarity)
        {
            return 0;
        }

        int nChance = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nAccumulatedRarity);
        int nCounter = 0;
        while (nCounter < nLegibleSets)
        {
            if (nChance < rarityData[2 * nCounter + 1])
            {
                break;
            }

            nChance -= rarityData[2 * nCounter + 1];
            ++nCounter;
        }

        if (nCounter < 0 || nCounter >= nLegibleSets)
        {
            return 0;
        }

        nFileIndex = rarityData[2 * nCounter];
    }

    ITEMS_SetFileIndex(pItem, nFileIndex);
    ITEMS_SetItemFlag(pItem, 0x10, 0);
    ITEMMODS_AssignProperty(4, 0, pItem, 0, 0, 0);
    return 1;
}

// 0x005C2940
int __fastcall sub_005C2940_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C25C0_RollSetItemRecord(pItemDrop, pItem);
    }

    return sub_005C2740_RollLegacySetItem(pItem);
}

// 0x005C2FB0
int __fastcall sub_6FC55270(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_ApplyLowQuality(pItem, pItemDrop);
    }

    return ITEMS_ApplyLegacyLowQuality(pItem, pItemDrop);
}
