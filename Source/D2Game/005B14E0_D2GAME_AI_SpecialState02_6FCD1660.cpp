struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    int unk0x04[4];
    int dwAiParam[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    int unk0x04;
    D2UnitStrc* pTarget;
    int unk0x0C[2];
    int nTargetDistance;
};

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);         // 0x005DE200
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B14E0
void __fastcall D2GAME_AI_SpecialState02_6FCD1660(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nDistance = pAiTickParam->nTargetDistance;
    if (sub_6FCF2E70(pUnit) || nDistance < 4)
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance > 10 && !pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 12);
        return;
    }
    if ((AI_RollUnitSeed(pUnit) & 0xFF) < 77)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        return;
    }
    if ((AI_RollUnitSeed(pUnit) & 0xFF) < 26)
    {
        pAiControl->dwAiParam[0] = 0;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
