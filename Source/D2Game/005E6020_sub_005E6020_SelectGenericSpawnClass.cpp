struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc tSeed;
};

struct D2MonRegDataStrc
{
    short nMonHcIdx;
    char unk0x02[0x32];
};

struct D2MonsterRegionStrc
{
    char unk0x00[0x10];
    unsigned char nMonCount;
    char pad0x11[3];
    D2MonRegDataStrc pMonData[13];
};

struct D2GameStrc
{
    char unk0x00[0xF0];
    D2MonsterRegionStrc* pMonReg[1024];
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned int dwMonStatsFlags;
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                    // 0x006CE268
int __fastcall sub_00573520_GetLevelIdFromUnit(D2UnitStrc* pUnit);                                          // 0x00573520
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** pMonReg, int nLevelId); // 0x00547BB0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (nMax & (nMax - 1))
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (!(nMonsterId >= 0))
        return 0;
    if (!(nMonsterId < sgptDataTables->nMonStatsTxtRecordCount))
        return 0;
    return &sgptDataTables->pMonStatsTxt[nMonsterId];
}

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

static __forceinline unsigned int TestMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return ((unsigned char*)&pMonStatsTxtRecord->dwMonStatsFlags)[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x005E6020
bool __fastcall sub_005E6020_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId)
{
    *pClassId = 453 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : 453;

    int const nLevelId = sub_00573520_GetLevelIdFromUnit(pUnit);
    D2MonsterRegionStrc* pMonRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, nLevelId);
    const int nMonsterId = pMonRegion->pMonData[SEED_RollLimitedRandomNumberInline(&pUnit->tSeed, pMonRegion->nMonCount)].nMonHcIdx;
    if (TestMonStatsFlag(nMonsterId, 21))
    {
        *pClassId = nMonsterId;
        return true;
    }

    for (int i = 0; i < pMonRegion->nMonCount; ++i)
    {
        const int nId = pMonRegion->pMonData[i].nMonHcIdx;
        if (TestMonStatsFlag(nId, 21))
        {
            *pClassId = nId;
            return true;
        }
    }

    *pClassId = 496 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : 496;
    return true;
}
