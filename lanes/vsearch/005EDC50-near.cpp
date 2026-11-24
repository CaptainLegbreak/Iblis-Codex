// 0x005EDC50 (D2Game AI think, between 0x5EDC40 and 0x5EDF70 in Ai/AiThink4.cpp), near version: 789/791 B.
// Frame (sub esp, 28), slots, the seed rolls (no seed write-back between the two rolls of a pair) and the
// control flow are the original's. Left: the two tick-field loads swap ecx/edx in the prologue, the first X
// (-40) gets folded into the quotient (`add edx, 2`), and the order of the +-30 direction term in the second
// and third Y. Insert before `// 0x005EDF70`.
static inline unsigned int SEED_RollNext_005EDC50(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed;
}

static inline unsigned int SEED_RollAgain_005EDC50(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed;
}

// 0x005EDC50
void __fastcall AITHINK_Fn5EDC50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pUnit->dwNodeIndex == 11)
    {
        TARGETS_InsertUnitNode(pGame, pUnit, 0, 8);
    }

    if (pTarget)
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            AITACTICS_Idle(pGame, pUnit, AI_GetParamValue(pGame, pMonStatsTxt, 0));
            return;
        }

        if (nDistance < AI_GetParamValue(pGame, pMonStatsTxt, 2) && (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_GetParamValue(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_SetVelocity(pUnit, 0, 100, 0);
            AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
            return;
        }
    }

    const int nX = CLIENTS_GetUnitXInline_005E17E0(pUnit);
    const int nY = CLIENTS_GetUnitYInline_005E17E0(pUnit);

    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned int nLowSeed, nHighSeed;
    unsigned int nRandX = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed);
    unsigned int nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 40, nY + nRandY % 20 - 10))
    {
        return;
    }

    const int bDirection = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed) & 1;
    nRandX = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 10, nY + nRandY % 20 - 10 - 30 * (bDirection ? 1 : -1)))
    {
        return;
    }

    nRandX = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed);
    nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 10, nY + nRandY % 20 - 10 - 30 * (!bDirection ? 1 : -1)))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

