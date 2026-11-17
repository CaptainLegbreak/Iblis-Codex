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
    char unk0x10[0x10];
    D2SeedStrc tSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
};

struct D2AiControlStrc;

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2SkillStrc;

int __fastcall sub_0045C390_SeedRollLimited(D2SeedStrc* pSeed, int nMax);                                    // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
void __fastcall sub_6FC61E30(D2UnitStrc* pUnit, int a2, int a3);                                            // 0x00573090
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam); // 0x005EA2B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill);                                                     // 0x00644360
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0

// 0x005E80E0
void __fastcall D2GAME_AI_SpecialState11_6FCE7E20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return;
    }

    switch (pTarget->dwUnitType)
    {
    case 0:
        sub_6FC61E30(pUnit, 1, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    case 1:
        sub_6FC61E30(pUnit, 2, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    case 3:
        sub_6FC61E30(pUnit, 4, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    }
}

// 0x005EA3D0
void __fastcall AITHINK_Fn101_AssassinSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nActiveDistance = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
    const int nSkillId = pMonStatsTxt->nSkill[0];
    if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 0))
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, 12))
    {
        STATES_ToggleState(pUnit, 12, 0);
    }

    int nDistance;
    int bInMeleeRange;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (!pTarget || nDistance >= nActiveDistance)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
        return;
    }

    const int nDifficulty = pGame->nDifficulty;
    if (sub_0045C390_SeedRollLimited(&pUnit->tSeed, 100) < pMonStatsTxt->wAiParam[0][nDifficulty])
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pSkill), nSkillId, pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][nDifficulty]);
}
