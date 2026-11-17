#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

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
    void* f_14;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
};

struct D2MonStatsTxt
{
    char unk0x00[0x5C];
    short nAiDel[3];
    short nAiDist[3];
    short nAiP1[3];
    char unk0x6E[0x102];
    short nSkill[2];
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

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

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_004CC7C0_GetSkillRange(int nSkillId, int nSkillLevel);                                   // 0x004CC7C0
D2UnitStrc* __fastcall sub_0056E390_FindSkillTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x0056E390
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005EA2B0_Check(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int a4); // 0x005EA2B0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                        // 0x006416D0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);          // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

// 0x005EA980
void __fastcall sub_005EA980_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt;
    int nSkillId;
    D2SkillStrc* pSkill;
    int nSkillLevel;
    D2UnitStrc* pTarget;
    int nDistance;
    int bInMeleeRange;
    D2UnitStrc* pSkillTarget;
    int nLastTarget;
    int nRange;

    if (sub_005EA2B0_Check(pGame, pUnit, pAiTickParam, 0))
    {
        return;
    }

    pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    nSkillId = pMonStatsTxt->nSkill[0];
    pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return;
    }

    nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (nSkillLevel <= 0)
    {
        return;
    }

    pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAiDel[pGame->nDifficulty]);
        return;
    }

    pSkillTarget = sub_0056E390_FindSkillTarget(pUnit, pTarget, nSkillId, nSkillLevel);
    nLastTarget = pAiTickParam->pAiControl->dwAiParam[0];
    nRange = sub_004CC7C0_GetSkillRange(nSkillId, nSkillLevel) / 2;
    if (pSkillTarget && (!pSkillTarget ? -1 : pSkillTarget->dwUnitId) != nLastTarget && sub_006416D0_UnitEdgeDistance(pTarget, pSkillTarget) < nRange)
    {
        if (sub_005EA2B0_Check(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = !pSkillTarget ? -1 : pSkillTarget->dwUnitId;
        AITACTICS_UseSkill(pGame, pUnit, 9, nSkillId, pSkillTarget, 0, 0);
        return;
    }

    if (nDistance < pMonStatsTxt->nAiP1[pGame->nDifficulty] && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStatsTxt->nAiDist[pGame->nDifficulty])
    {
        if (sub_005EA2B0_Check(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        AITACTICS_UseSkill(pGame, pUnit, 14, pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAiDel[pGame->nDifficulty]);
}
