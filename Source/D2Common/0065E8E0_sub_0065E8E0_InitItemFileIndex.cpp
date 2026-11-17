struct D2UnitStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

extern int gaItemFileIndices_0074638C[];                                                                    // 0x0074638C
extern int gnItemFileIndexCount_007463A4;                                                                   // 0x007463A4

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0065E8E0
void __stdcall sub_0065E8E0_InitItemFileIndex(D2UnitStrc* pItem)
{
    const int nCount = gnItemFileIndexCount_007463A4;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
    const int nIndex = SEED_RollLimitedRandomNumber(pSeed, nCount);
    ITEMS_SetFileIndex(pItem, gaItemFileIndices_0074638C[nIndex]);

    const int nFileIndex = gaItemFileIndices_0074638C[nIndex];
    int nValue;
    if (nFileIndex == 9)
    {
        nValue = ((SEED_RollRandomNumber(ITEMS_GetItemSeed(pItem)) & 3) + 1) << 8;
    }
    else if (nFileIndex == 7)
    {
        nValue = ((SEED_RollRandomNumber(ITEMS_GetItemSeed(pItem)) & 3) + 1) << 8;
    }
    else
    {
        nValue = 1;
    }
    STATLIST_SetUnitStat(pItem, 0x47, nValue, 0);
}

#include "gen/data/Source/D2Common/0065E8E0_sub_0065E8E0_InitItemFileIndex.inc"
