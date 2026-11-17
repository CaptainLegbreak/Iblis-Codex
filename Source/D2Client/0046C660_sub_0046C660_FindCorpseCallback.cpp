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
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

// 0x0046C660
int __fastcall sub_0046C660_FindCorpseCallback(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc** ppTarget, int* pDistance)
{
    if (!pTarget)
        return 0;

    const int nType = pTarget->dwUnitType;
    if (nType != UNIT_PLAYER && nType != UNIT_MONSTER)
        return 0;

    const int nMode = pTarget->dwAnimMode;
    if (nType == UNIT_PLAYER)
    {
        if (nMode != PLRMODE_DEATH && nMode != PLRMODE_DEAD)
            return 0;
    }
    else
    {
        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD)
            return 0;
    }

    const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
    if (nDistance >= 3 && nDistance <= 25 && sub_006416D0_UnitEdgeDistance(pTarget, sub_00463DD0()) > 7 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
    {
        *pDistance = nDistance;
        *ppTarget = pTarget;
    }

    return 0;
}
