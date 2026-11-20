#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define MONSTATSFLAGINDEX_PLACESPAWN 23

struct D2SeedStrc;
struct D2MonRegDataStrc;
struct D2MonsterRegionStrc;
struct D2LevelsTxt;
struct D2MonStatsTxt;
struct D2SeedOwnerStrc;


struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};


struct D2MonRegDataStrc
{
    unsigned short nMonHcIdx;
    unsigned char nRarity;
    char unk0x03[0x34 - 0x03];
};

struct D2MonsterRegionStrc
{
    char unk0x000[0x10];
    unsigned char nMonCount;
    unsigned char nTotalRarity;
    char unk0x012[0x02];
    D2MonRegDataStrc pMonData[13];
    char unk0x2B8[0x08];
    int dwlevel;
};

struct D2LevelsTxt
{
    char unk0x00[0x35];
    unsigned char nNumUniqueMonsters;
    char unk0x36[0x9A - 0x36];
    short wUniqueMonsters[25];
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct D2SeedOwnerStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

extern void* gpUnk_007415F0; // 0x007415F0

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005BDE80
int __fastcall MONSTERCHOOSE_GetPresetMonsterId(D2GameStrc* pGame, D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom, D2MonStatsTxt** ppMonStatsTxtRecord, unsigned char nChance, int bSpawnUMon)
{
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    if (bSpawnUMon && pGame->nDifficulty == 0)
    {
        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(pMonsterRegion->dwlevel);
        if (pLevelsTxtRecord->nNumUniqueMonsters)
        {
            const int nMonsterId = pLevelsTxtRecord->wUniqueMonsters[ITEMS_RollLimitedRandomNumber(pSeed, pLevelsTxtRecord->nNumUniqueMonsters)];
            *ppMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
            return nMonsterId;
        }

        *ppMonStatsTxtRecord = 0;
        return 0;
    }

    if (!pMonsterRegion->nMonCount)
    {
        *ppMonStatsTxtRecord = 0;
        return 0;
    }

    int nRarityRoll = ITEMS_RollLimitedRandomNumber(pSeed, pMonsterRegion->nTotalRarity) + 1;
    D2MonRegDataStrc* pMonRegData = pMonsterRegion->pMonData;
    for (int i = 0; i < pMonsterRegion->nMonCount; ++i)
    {
        nRarityRoll -= pMonRegData->nRarity;
        if (nRarityRoll <= 0)
        {
            break;
        }

        ++pMonRegData;
    }

    short nMonsterId = pMonRegData->nMonHcIdx;
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wSpawn >= 0 && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_PLACESPAWN >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_PLACESPAWN & 7])
    {
        const unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        if ((int)((unsigned int)lSeed % 100) > nChance)
        {
            nMonsterId = pMonStatsTxtRecord->wSpawn;
        }
    }

    *ppMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    return nMonsterId;
}

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

#include "gen/data/Source/D2Game/Unknown_005BDE80.inc"
