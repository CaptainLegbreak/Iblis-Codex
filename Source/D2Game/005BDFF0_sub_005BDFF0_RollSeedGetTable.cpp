struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2SeedOwnerStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

extern void* gpUnk_007415F0;                                                                                // 0x007415F0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BDFF0
void* __fastcall sub_005BDFF0_RollSeedGetTable(D2SeedOwnerStrc* pOwner)
{
    D2SeedStrc* pSeed = pOwner ? &pOwner->pSeed : 0;
    SEED_RollRandomNumber(pSeed);
    return gpUnk_007415F0;
}

#include "gen/data/Source/D2Game/005BDFF0_sub_005BDFF0_RollSeedGetTable.inc"
