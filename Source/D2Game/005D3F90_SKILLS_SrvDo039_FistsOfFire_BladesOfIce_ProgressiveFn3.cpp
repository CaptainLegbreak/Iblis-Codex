struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { int dwUnitType; int unk04[7]; D2SeedStrc pSeed; };
typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);
struct D2MissileStrc
{
    unsigned int dwFlags; D2UnitStrc* pOwner; D2UnitStrc* pOrigin; D2UnitStrc* pTarget; int nMissile;
    int nX; int nY; int nTargetX; int nTargetY; int nGfxArg; int nVelocity; int nSkill; int nSkillLevel; int nLoops;
    int unk0x38[7]; MissileInitFunc pInitFunc; int pInitArgs;
};
struct D2SkillsTxt { char unk0x000[0x64]; unsigned int dwAuraRangeCalc; char unk0x068[0x23C - 0x68]; };
struct D2DataTablesStrc { char unk0x000[0xB98]; D2SkillsTxt* pSkillsTxt; char unkB9C[4]; int nSkillsTxtRecordCount; };
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables;                                                                        // 0x00744304
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                     // 0x00650E40
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                              // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                   // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY);    // 0x00463740
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);      // 0x0059FA30
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                            // 0x005D3CF0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY);  // 0x0056D2C0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);           // 0x005D3DA0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005D3F90
int __fastcall SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nRand = SEED_RollRandomNumber(&pUnit->pSeed);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2MissileStrc missileParams = {};

    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2SeedStrc seed;
    SEED_InitLowSeed(&seed, nRand);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nArea = nRange * nRange;
    for (int i = 0; i < nArea; ++i)
    {
        const int nX = nRange - SEED_RollLimitedRandomNumber(&seed, 2 * nRange);
        const int nY = nRange - SEED_RollLimitedRandomNumber(&seed, 2 * nRange);

        if (nX * nX + nY * nY <= nArea)
        {
            missileParams.nX = nTargetX + nX;
            missileParams.nY = nTargetY + nY;

            if (D2GAME_GetRoom_6FC52070(pRoom, missileParams.nX, missileParams.nY))
            {
                MISSILES_CreateMissileFromParams(pGame, &missileParams);
            }
        }
    }

    return 1;
}
