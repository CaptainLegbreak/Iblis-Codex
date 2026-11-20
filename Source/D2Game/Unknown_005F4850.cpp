#include "D2Structs.h"


struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
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

enum D2C_M75ThornHulkConstants
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    EVENTTYPE_ENDANIM = 1,
};

int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent);                       // 0x005415A0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static int AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

static __forceinline bool AI_RollChanceLimited(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
    return nRoll < AI_GetParam(pGame, pMonStatsTxt, nParamId);
}

// 0x005F4850
void __fastcall AITHINK_Fn027_ThornHulk(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiTickParam->bCombat || !pTarget)
    {
        pAiControl->dwAiParam[0] = 0;
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK2, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        const int nEventFrame = EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM);
        if (nEventFrame > pGame->dwGameFrame)
        {
            AITACTICS_Idle(pGame, pUnit, nEventFrame + AI_GetParam(pGame, pMonStatsTxt, 4) - pGame->dwGameFrame);
        }

        --pAiControl->dwAiParam[0];
        if (pAiControl->dwAiParam[0] <= 0)
        {
            pAiControl->dwAiParam[1] = 3;
        }
        return;
    }

    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        if (pAiControl->dwAiParam[1] > 0 || !AI_RollChanceLimited(pGame, pUnit, pMonStatsTxt, 3))
        {
            --pAiControl->dwAiParam[1];
            if (AI_RollChanceLimited(pGame, pUnit, pMonStatsTxt, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK2, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            const int nEventFrame = EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM);
            if (nEventFrame > pGame->dwGameFrame)
            {
                AITACTICS_Idle(pGame, pUnit, nEventFrame + AI_GetParam(pGame, pMonStatsTxt, 4) - pGame->dwGameFrame);
            }

            pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 5);
        }
        return;
    }

    if (AI_RollChanceLimited(pGame, pUnit, pMonStatsTxt, 2))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, MONMODE_ATTACK1, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
