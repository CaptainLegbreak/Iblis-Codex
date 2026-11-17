struct D2GameStrc;
struct D2UnitStrc;
struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};
typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);
struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId);
void __fastcall sub_005D40F0_RingMissileInit(D2UnitStrc* pMissile, int nInitSeed);

// 0x005D4150
static __declspec(noinline) void __stdcall SKILLS_CreateChargedBoltMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nLowSeed);

    D2MissileStrc missileParams = {};
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pInitFunc = sub_005D40F0_RingMissileInit;

    const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        const unsigned __int64 lSeed = tSeed.nHighSeed + 0x6AC690C5i64 * tSeed.nLowSeed;
        tSeed.lSeed = lSeed;
        missileParams.pInitArgs = (unsigned int)lSeed;

        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        MISSILE_SetTargetX(pMissile, sub_004EFC20_GetSkillParam2(0x118) + 1);
    }
}

int __fastcall sub_M269_Emit_005D4150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed)
{
    SKILLS_CreateChargedBoltMissileRing(pGame, pUnit, nMissileId, nX, nY, nSkillId, nSkillLevel, nStep, nLowSeed ^ 0x5A5);
    return 0x3C1;
}
