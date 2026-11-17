struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[4];
    D2SeedStrc tSeed;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode);  // 0x00466730

char gbGlobal_007C025F;                                                                                     // 0x007C025F
extern char gbGlobal_007C0260;                                                                              // 0x007C0260
extern unsigned int gnQuestUnitId_007C0261;                                                                 // 0x007C0261

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
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

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

// 0x004A3150
void __fastcall sub_004A3150_SpawnQuestUnits(int nX, int nY)
{
    if (gbGlobal_007C025F)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        int nCount = SEED_RollLimitedRandomNumber(&pPlayer->tSeed, 3) + 2;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pUnit = sub_00466730_SpawnPresetUnit(0x95, nX + i % 2, nY + i % 2, 1, 1);
            gnQuestUnitId_007C0261 = UNITS_GetUnitId(pUnit);
            gbGlobal_007C0260 = 1;
        }
    }
}
