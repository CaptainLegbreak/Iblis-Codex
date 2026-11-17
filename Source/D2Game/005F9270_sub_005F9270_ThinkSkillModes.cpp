struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { int dwUnitType; char dwClassId[0x1C]; D2SeedStrc pSeed; };
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; char unk_6E[0x3A]; int dwGameFrame; };
struct D2AiControlStrc { int nAiSpecialState; char unk_04[0x10]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk_000[0x56]; short wAiParam[8][3]; char unk_086[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk_04; D2UnitStrc* pTarget; int unk_0C[2]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2UnitStrc* __fastcall sub_005DDC30_FindTarget(D2GameStrc*, D2UnitStrc*, int*, int); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc*, D2UnitStrc*, int); // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0
#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}
// 0x005F9270
void __fastcall sub_005F9270_ThinkSkillModes(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[2])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 2);
        pAiControl->dwAiParam[2] = 1;
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && pAiControl->dwAiParam[2] == 2 && pGame->dwGameFrame > pAiControl->dwAiParam[1])
    {
        if (nDistance > AI_GetParam(pGame, pMonStatsTxt, 5) || !bCombat && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 20);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[2] = 1;
            return;
        }
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && pAiControl->dwAiParam[2] == 1 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (bCombat || nDistance < AI_GetParam(pGame, pMonStatsTxt, 5)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 3);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 4));
        return;
    }

    D2UnitStrc* pNewTarget = sub_005DDC30_FindTarget(pGame, pUnit, &nDistance, 0);
    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pNewTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 4));
}
