#include "D2Game.h"
#include "D2Structs.h"

#define D2_FREE_POOL(pMemPool, ptr, line) FOG_FreePool(pMemPool, ptr, ".\\MONSTER\\MonsterRegion.cpp", line, 0)
#define SUMMONER_FLAG 2
#define UNIT_ALIGNMENT_EVIL 0

struct D2MonsterRegionStrc;
struct D2SeedStrc;


struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char f_74[0x5C];
    D2SeedStrc pGameSeed;
    char unk0xD8[0x14];
    unsigned int dwMonSeed;
    D2MonsterRegionStrc* pMonReg[1024];
};

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

struct D2MonsterRegionStrc
{
    char unk0x00[716];
    unsigned int dwMonSpawnCount;
    unsigned int dwMonKillCount;
};

void __fastcall MONSTERREGION_InitializeAll(void* pMemoryPool, D2MonsterRegionStrc** ppMonsterRegion, D2SeedStrc* pSeed, int nSeed, unsigned char nDifficulty, int bExpansion); // 0x005479C0

struct D2DataTablesStrc
{
    char unk0x00[3164];
    int nLevelsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int a5); // 0x0040B480
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00573570
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

// 0x00547BB0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId)
{
    return ppMonsterRegion[nLevelId];
}

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00547D20
void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame)
{
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);

    const int nSeed = (unsigned int)ITEMS_RollRandomNumberInline(&pGame->pGameSeed);
    SEED_InitLowSeed(&tSeed, nSeed);
    pGame->dwMonSeed = nSeed;
    MONSTERREGION_InitializeAll(pGame->pMemoryPool, pGame->pMonReg, &tSeed, nSeed, pGame->nDifficulty, pGame->bExpansion);
}

// 0x00547D90
void __fastcall sub_6FC68180(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int bToggleFlag)
{
    if (bToggleFlag)
    {
        MONSTER_ToggleSummonerFlag(pUnit, SUMMONER_FLAG, 1);
    }
    else
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[DUNGEON_GetLevelIdFromRoom(pRoom)];
        ++pMonsterRegion->dwMonSpawnCount;
    }
}

// 0x00547E50
void __fastcall sub_6FC68240(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, SUMMONER_FLAG))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            ++pMonsterRegion->dwMonKillCount;
        }
    }
}

// 0x00547E90
void __fastcall sub_6FC68280(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, SUMMONER_FLAG))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (!STATLIST_GetUnitAlignment(pUnit))
        {
            --pMonsterRegion->dwMonKillCount;
        }
    }
}
