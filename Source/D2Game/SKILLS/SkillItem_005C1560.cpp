#include "D2Txt.h"
#include "D2Path.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2DataTbls.h"
struct D2UnitStrc;

struct D2MagicAffixIndexAndPtrStrc
{
    int nAffixId;
    D2MagicAffixTxt* pMagicAffixRecord;
};

struct D2RareAffixTxt
{
    char unk0x00[0x48];
};

struct D2RareAffixDataTbl
{
    int nRareAffixTxtRecordCount;
    D2RareAffixTxt* pRareAffixTxt;
    D2RareAffixTxt* pRareSuffix;
    D2RareAffixTxt* pRarePrefix;
};

struct D2RareAffixIndexAndPtrStrc
{
    int nIndex;
    D2RareAffixTxt* pRareAffixRecord;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0
void __fastcall sub_005C1260(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);               // 0x005C1260
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);               // 0x00627EF0
void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);               // 0x00627FB0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix);                           // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix);                           // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem);                                                           // 0x0062E990
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables();                                           // 0x00634250
int __stdcall ITEMMODS_CanItemHaveRareAffix(D2UnitStrc* pItem, const D2RareAffixTxt* pRareAffixTxtRecord); // 0x0065E710
extern const int gnRareAffixCounts_006E3014[];                                                              // 0x006E3014
extern "C" void __stdcall sub_00627EF0(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);        // 0x00627EF0
extern "C" void __stdcall sub_00627FB0(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);        // 0x00627FB0
extern "C" void __stdcall sub_00628070(D2UnitStrc* pItem, unsigned short nSuffix);                       // 0x00628070
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables(); // 0x00633ED0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
unsigned char __stdcall ITEMS_GetItemQlvl(const D2UnitStrc* hItem); // 0x00628740
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nClassId); // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc* pItem, const D2MagicAffixTxt* pMagicAffixTxtRecord); // 0x0065E620
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem); // 0x0062C0B0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __stdcall ITEMMODS_AssignProperty(int nMode, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nSet, int nUnused); // 0x0065FEC0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo); // 0x00627EC0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0

// 0x005C0D00
static __declspec(noinline) int __stdcall sub_005C0D00_ITEMS_AddPotentialMagicAffix(int nAffixId, D2MagicAffixTxt* pRecord, D2MagicAffixIndexAndPtrStrc* pAffixes, int nCount)
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
        if (!pAffix) break;
        if (pAffix->dwGroup == nGroup) return 1;
    }
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
        if (!pAffix) break;
        if (pAffix->dwGroup == nGroup) return 1;
    }
    return 0;
}

static __forceinline D2MagicAffixIndexAndPtrStrc* GetPotentialMagicAffix(D2MagicAffixIndexAndPtrStrc* pAffixes, int nIndex, int nCount)
{
    if (nIndex >= nCount) return 0;
    return pAffixes;
}
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
static __forceinline int GetClassId(D2UnitStrc* pItem)
{
    if (!pItem) return -1;
    return pItem->dwClassId;
}

static __declspec(noinline) short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup);

// 0x005C1560
static short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup)
{
    D2MagicAffixDataTbl* pTables = DATATBLS_GetMagicAffixDataTables();
    if (!pTables)
        return 0;

    D2MagicAffixTxt* pBegin;
    D2MagicAffixTxt* pEnd;
    int nCount;
    if (nAutoMagicGroup)
    {
        pBegin = pTables->pAutoMagic;
        pEnd = &pTables->pMagicAffixTxt[pTables->nMagicAffixTxtRecordCount];
        nCount = pEnd - pBegin;
    }
    else if (bPrefixes)
    {
        pBegin = pTables->pMagicPrefix;
        pEnd = pTables->pAutoMagic;
        nCount = pEnd - pBegin;
    }
    else
    {
        pBegin = pTables->pMagicSuffix;
        pEnd = pTables->pMagicPrefix;
        nCount = pEnd - pBegin;
    }

    if (!pBegin)
        return 0;
    const int nOffset = pBegin - pTables->pMagicAffixTxt;
    int nRolledAffixId = -1;
    int nPotentialCount = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
    unsigned __int64 nSeed = 0x6AC690C5ui64 * pSeed->nLowSeed + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    int nTotalFrequency = 0;
    const int nQualityLevel = ITEMS_GetItemQlvl(pItem);
    if (((unsigned int)nSeed & 1) || bForceAffixRoll)
    {
        D2MagicAffixTxt* pRolledRecord;

        int nLevel = ITEMS_GetItemLevel(pItem);
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(GetClassId(pItem));
        if (!pItemsTxt)
            return 0;
        nLevel = D2_MAX(nLevel, nQualityLevel);
        const int nMagicLevel = pItemsTxt->nMagicLevel;
        if (nMagicLevel)
            nLevel += nMagicLevel;
        else
        {
            const int nDistance = 99 - (nQualityLevel / 2);
            if (nLevel < nDistance)
                nLevel -= (nQualityLevel / 2);
            else
                nLevel = 2 * nLevel - (nQualityLevel / 2) - nDistance;
        }
        nLevel = D2_MIN(D2_MAX(nLevel, 1), 99);

        D2MagicAffixIndexAndPtrStrc tAffixes[512];
        for (int i = 0; i < nCount; ++i)
        {
            D2MagicAffixTxt* pAffix = &pBegin[i];
            if (bRequireSpawnableAffix && !pAffix->bSpawnable)
                continue;
            if (pAffix->wVersion >= 100 && nFormat < 100)
                continue;
            int bPreferred;
            if (nPreferredAffixIndex > 0 && nPreferredAffixIndex - 1 == i)
                bPreferred = 1;
            else
            {
                bPreferred = 0;
                if (pAffix->nLevel > nLevel)
                    continue;
                if (pAffix->nMaxLevel && pAffix->nMaxLevel < nLevel)
                    continue;
            }
            if (!pAffix->bRare)
            {
                switch (ITEMS_GetItemQuality(pItem))
                {
                case ITEMQUAL_RARE:
                case ITEMQUAL_CRAFT:
                case ITEMQUAL_TEMPERED:
                    continue;
                }
            }
            if (!ITEMMODS_CanItemHaveMagicAffix(pItem, pAffix))
                continue;
            if (nAutoMagicGroup && nAutoMagicGroup != pAffix->dwGroup)
                continue;
            if (!pAffix->nFrequency)
                continue;
            if (pAffix->nClass != 255 && ITEMS_GetClassOfClassSpecificItem(pItem) != 7 && pAffix->nClass != ITEMS_GetClassOfClassSpecificItem(pItem))
                continue;
            if (ITEMMODS_HasAffixWithGroup(pItem, pAffix->dwGroup))
                continue;
            if (bPreferred)
            {
                nRolledAffixId = i + nOffset;
                pRolledRecord = pAffix;
                break;
            }
            nPotentialCount = sub_005C0D00_ITEMS_AddPotentialMagicAffix(i + nOffset, pAffix, tAffixes, nPotentialCount);
            if (nMagicLevel)
                nTotalFrequency += pAffix->nFrequency * pAffix->nLevel;
            else
                nTotalFrequency += pAffix->nFrequency;
        }

        if (nRolledAffixId < 0)
        {
            if (nPotentialCount <= 0)
                return 0;
            int nRoll = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nTotalFrequency + 1);
            D2MagicAffixIndexAndPtrStrc* pRolled = 0;
            for (int i = 0; i < nPotentialCount; ++i)
            {
                pRolled = GetPotentialMagicAffix(&tAffixes[i], i, nPotentialCount);
                if (!pRolled)
                    return 0;
                const D2MagicAffixTxt* pRecord = pRolled->pMagicAffixRecord;
                if (nMagicLevel)
                    nRoll -= pRecord->nFrequency * pRecord->nLevel;
                else
                    nRoll -= pRecord->nFrequency;
                if (nRoll < 0)
                    break;
            }
            if (!pRolled)
                return 0;
            nRolledAffixId = pRolled->nAffixId;
            pRolledRecord = pRolled->pMagicAffixRecord;
        }
        if (bAssignProperties)
            ITEMMODS_AssignProperty(0, 0, pItem, pRolledRecord, 0, 0);
    }
    return nRolledAffixId + 1;
}

// build: context ?ITEMS_RollMagicAffixes@@YIFPAUD2UnitStrc@@HHHHH@Z
short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

// build: context ?ITEMS_RollMagicAffixes@@YIFPAUD2UnitStrc@@HHHHHH@Z
short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex, nAutoMagicGroup);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex);
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

// build: context sub_005C19A0_RollRareAffixOld
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

// build: context sub_005C1AB0_RollRareAffixNew
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

// build: context sub_005C1BF0_RollRareItemNew
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
    sub_005C1260(pItem, pItemDrop);
    return 1;
}

// build: context ITEMS_RollLegacyRareItem
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
    sub_005C1260(pItem, pItemDrop);
    return 1;
}

// build: context D2GAME_RollRareItem_6FC53360
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

// build: context sub_005C21D0_RollCraftedItem
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
