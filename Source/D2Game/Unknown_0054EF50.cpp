#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};
struct D2ActiveRoomStrc
{
    char pad00[0x6C];
    D2SeedStrc pSeed;
    unsigned int field74;
    int field78;
};
struct D2MonsterRegionStrc
{
    char pad00[0x2C4];
    int nWanderingCount;
};
struct D2GameStrc
{
    char pad00[0xF0];
    D2MonsterRegionStrc* pMonsterRegion[1];
};
struct D2LevelsTxt
{
    char pad00[3];
    unsigned char nAct;
    char pad04[0x18];
    unsigned char field1C[0x12];
    unsigned char nWandering;
};
struct D2WanderingRange
{
    unsigned char nBase;
    unsigned char nCount;
};
extern D2WanderingRange gWanderingRanges_00731B30[]; // 0x00731B30
extern int gWanderingIds_00731B2C[]; // 0x00731B2C
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc*, D2ActiveRoomStrc*, D2UnitStrc*, int, int*, int*, int); // 0x0054DC40
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc*, D2ActiveRoomStrc*, int, int, int, int, int, int); // 0x005B2F20
void __fastcall sub_6FC40280(D2GameStrc*, D2UnitStrc*, int, int); // 0x005B1990
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc**, int); // 0x00547BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int); // 0x0061DB70

inline unsigned __int64 RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

// 0x0054EF50
static __declspec(noinline) void __stdcall sub_0054EF50_SpawnWandering(
    D2MonsterRegionStrc* pRegion, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2LevelsTxt* pLevels)
{
    unsigned char nAct = pLevels->nAct;
    if (nAct >= 5)
        return;
    int nCount = gWanderingRanges_00731B30[nAct].nCount;
    int nBase = gWanderingRanges_00731B30[nAct].nBase;
    if (!nCount)
        return;
    int nMonster = gWanderingIds_00731B2C[SEED_RollLimitedRandomNumber(pRoom ? &pRoom->pSeed : 0, nCount) + nBase];
    int nX;
    int nY;
    if (!sub_0054DC40_FindSpawnPosition(pGame, pRoom, 0, nMonster, &nX, &nY, 0))
        return;
    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonster, 1, -1, 0);
    if (pMonster)
    {
        sub_6FC40280(pGame, pMonster, 0, 8);
        ++pRegion->nWanderingCount;
    }
}

// 0x0054EFF0
static __declspec(noinline) void __stdcall sub_0054EFF0_CheckWandering(
    D2GameStrc* pGame, int nLevel, D2LevelsTxt* pLevels, D2ActiveRoomStrc* pRoom)
{
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    if ((int)((unsigned int)RollSeedInline(pSeed) % 100) < 3)
    {
        D2MonsterRegionStrc* pRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonsterRegion, nLevel);
        if (pRegion->nWanderingCount < 3)
            sub_0054EF50_SpawnWandering(pRegion, pGame, pRoom, pLevels);
    }
}

// 0x0054F060
void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    if (((unsigned int)RollSeedInline(pRoom ? &pRoom->pSeed : 0) & 0x7FFF) == 0 && !pRoom->field78)
    {
        int nLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
        D2LevelsTxt* pLevels = DATATBLS_GetLevelsTxtRecord(nLevel);
        if (pLevels->nWandering && pLevels->field1C)
            sub_0054EFF0_CheckWandering(pGame, nLevel, pLevels, pRoom);
    }
}

#include "gen/data/Source/D2Game/Unknown_0054EF50.inc"
