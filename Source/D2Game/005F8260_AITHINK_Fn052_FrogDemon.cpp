struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0x170 - 0x86];
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

struct D2ActiveRoomStrc;

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit);                  // 0x005F2EB0
int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x005F2FC0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_RollChance(pGame, pSeed, pMonStatsTxt, nParamId) ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, nParamId))

static __forceinline int CLIENTS_GetUnitX_FrogDemon(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitY_FrogDemon(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005F8260
void __fastcall AITHINK_Fn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pAiControl->dwAiParam[2] == 0)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance > 12)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pAiTickParam->pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 8);
            pAiControl->dwAiParam[2] = 1;
            sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            goto LABEL_EMERGE0;
        }

        if (!COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX_FrogDemon(pUnit), CLIENTS_GetUnitY_FrogDemon(pUnit), 0xC01))
        {
            pAiControl->dwAiParam[2] = 2;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 7) && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
LABEL_EMERGE:
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < 20 && pAiControl->dwAiParam[1] > 64 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
        AITACTICS_Idle(pGame, pUnit, 24);
        ++pAiControl->dwAiParam[1];
        pAiControl->dwAiParam[2] = 1;
        return;

LABEL_EMERGE0:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    {
        if (!pTarget)
        {
            AITACTICS_Idle(pGame, pUnit, 32);
            return;
        }

        if (bCombat)
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 2))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 5))
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 4))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
            return;
        }

        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 4);
        return;
    }
}
