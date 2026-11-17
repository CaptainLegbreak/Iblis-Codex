struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2AiControlStrc
{
    char unk0x00[0x14];
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

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                // 0x0045C390
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                    // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);                 // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                       // 0x00620BB0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int AI_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005E7C10
void __fastcall sub_005E7C10_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AI_GetAnimMode(pUnit) != 1)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int nDistance;
        int bCombat;
        D2UnitStrc* pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
        if (pTarget)
        {
            const int nRand = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (bCombat)
            {
                if (nRand < 80)
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                return;
            }

            if (nRand < 30)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
