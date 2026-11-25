// 0x005EDC50 (D2Game AI think, between 0x5EDC40 and 0x5EDF70 in Ai/AiThink4.cpp), near version: 786/791 B,
// 13 differing lines (was 789/791 with 112). Insert before `// 0x005EDF70`.
// What changed: AITACTICS_WalkToTargetCoordinatesDeleteAiEvent (0x5DEE50) takes its coordinates as unsigned int.
// That alone removes the folded -40 (`add edx, 2`) that no expression form could avoid. Changing the prototype in
// all three files that declare it leaves AiTatics.cpp and AiThink4.cpp building equal (its body only copies
// nX and nY into the mode-change struct). Then the +-30 term written `+ 30 * (bDirection ? -1 : 1)` and reading
// bCombat before nTargetDistance bring it to 13 lines.
// Left: the second and third rolls' `sete` / `setne` and the `neg` on the direction value sit one call apart
// from the original's (the original forms -30 * sign with `neg` and adds it), and one store moves in the prologue.
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
    int bCombat = pAiTickParam->bCombat;
    int nDistance = pAiTickParam->nTargetDistance;
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
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 10, nY + nRandY % 20 - 10 + 30 * (bDirection ? -1 : 1)))
    {
        return;
    }

    nRandX = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed);
    nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 10, nY + nRandY % 20 - 10 + 30 * (bDirection ? 1 : -1)))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

