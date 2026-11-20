#include "D2Structs.h"
#include "D2Drlg.h"
typedef unsigned __int64 uint64_t;

#pragma pack(push, 4)

struct D2MonsterRegionStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    char unk_010[0x2BC - 0x10];
    unsigned char nBossMin;
    unsigned char nBossMax;
    char unk_2BE[0x2C8 - 0x2BE];
    unsigned char dwUniqueCount;
};

#pragma pack(pop)

static __forceinline uint64_t SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    uint64_t lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    return (unsigned int)SEED_RollRandomNumber(pSeed);
}

static __forceinline D2SeedStrc* DUNGEON_GetRoomSeed(D2ActiveRoomStrc* pRoom)
{
    return pRoom ? &pRoom->pSeed : 0;
}

// 0x005BE020
int __fastcall MONSTERCHOOSE_GetBossSpawnType(D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom)
{
    const unsigned char nBossMax = pMonsterRegion->nBossMax;
    const unsigned char nUniqueCount = pMonsterRegion->dwUniqueCount;
    if (nUniqueCount < pMonsterRegion->nBossMin)
    {
        const int nDivisor = pMonsterRegion->unk0x0C;
        if (nDivisor)
        {
            const int nFactor = pMonsterRegion->unk0x04;
            if ((int)(ITEMS_RollRandomNumber(DUNGEON_GetRoomSeed(pRoom)) % 100) < 100 * nFactor / nDivisor)
            {
                return 0;
            }
        }
    }

    if (nUniqueCount < nBossMax && (int)(ITEMS_RollRandomNumber(DUNGEON_GetRoomSeed(pRoom)) % 100) <= 5)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(DUNGEON_GetRoomSeed(pRoom)) % 100) > 35)
    {
        return 2;
    }

    return 1;
}
