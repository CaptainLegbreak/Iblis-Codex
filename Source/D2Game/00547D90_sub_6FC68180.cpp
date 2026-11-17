struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2MonsterRegionStrc
{
    char unk0x00[716];
    unsigned int dwMonSpawnCount;
    unsigned int dwMonKillCount;
};
struct D2DataTablesStrc
{
    char unk0x00[3164];
    int nLevelsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int a5);         // 0x0040B480
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet);                         // 0x00573570
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __fastcall MONSTER_CheckSummonerFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00573540
int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit);                                                       // 0x00573520
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0

#define D2_FREE_POOL(pMemPool, ptr, line) FOG_FreePool(pMemPool, ptr, ".\\MONSTER\\MonsterRegion.cpp", line, 0)
#define SUMMONER_FLAG 2
#define UNIT_ALIGNMENT_EVIL 0

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
