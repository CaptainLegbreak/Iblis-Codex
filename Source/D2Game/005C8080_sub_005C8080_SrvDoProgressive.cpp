struct D2GameStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { int dwUnitType; int unk04[7]; D2SeedStrc pSeed; char unk28[0xC4 - 0x28]; unsigned int dwFlags; };
typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);
struct D2MissileStrc
{
    unsigned int dwFlags; D2UnitStrc* pOwner; D2UnitStrc* pOrigin; D2UnitStrc* pTarget; int nMissile;
    int nX; int nY; int nTargetX; int nTargetY; int nGfxArg; int nVelocity; int nSkill; int nSkillLevel; int nLoops;
    int unk0x38[7]; MissileInitFunc pInitFunc; int pInitArgs;
};
struct D2SkillsTxt { char unk0x000[0x23C]; };
struct D2DataTablesStrc { char unk0x000[0xB98]; D2SkillsTxt* pSkillsTxt; char unkB9C[4]; int nSkillsTxtRecordCount; };
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                    // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                        // 0x00744304
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                              // 0x0045C390
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);      // 0x0059FA30
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                            // 0x005D3CF0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY);  // 0x0056D2C0
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId);                              // 0x0056E450
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                          // 0x0064A710
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005C8080
int __fastcall sub_005C8080_SrvDoProgressive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (!sub_6FD15340(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const unsigned char nRand = (unsigned char)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 256);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nRand);
    sub_6FCC6300(pUnit, 0, nSkillId, nSkillLevel, nX, nY, nRand);
    return 1;
}
