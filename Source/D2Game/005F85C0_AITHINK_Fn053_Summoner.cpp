struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
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

enum D2C_SummonerAIParams
{
    SUMMONER_AI_PARAM_CAST_CHANCE_PCT = 0,
    SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT = 1,
    SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT = 2,
    SUMMONER_AI_PARAM_NOVA_TIMER = 3,
    SUMMONER_AI_PARAM_FIREWALL_TIMER = 4,
    SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT = 5,
    SUMMONER_AI_PARAM_NOVA_DISTANCE = 6,
    SUMMONER_AI_PARAM_MISSILE_DISTANCE = 7,
};

void __fastcall ACT2Q5_OnSummonerActivated(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x0059C330
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance);     // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005DEFE0_AiEscape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005F85C0
void __fastcall AITHINK_Fn053_Summoner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!pAiControl->dwAiParam[0])
    {
        ACT2Q5_OnSummonerActivated(pGame, pUnit);
        pAiControl->dwAiParam[0] = 1;
    }

    if (nTargetDistance < 5 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        sub_005DEFE0_AiEscape(pGame, pUnit, pTarget, 6, 0);
    }

    int bUseColdSkill = STATLIST_UnitGetStatValue(pTarget, 39, 0) >= STATLIST_UnitGetStatValue(pTarget, 43, 0);

    const int nX = CLIENTS_GetUnitXInline(pTarget);
    const int nY = CLIENTS_GetUnitYInline(pTarget);

    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_CAST_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[4] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }

        int nDistance;
        D2UnitStrc* pMissileTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

        if (AI_RollPercentage(pUnit) > AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT))
        {
            bUseColdSkill = (bUseColdSkill == 0);
        }

        if (bUseColdSkill)
        {
            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
            {
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMissileTarget, nX, nY);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2])
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_FIREWALL_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pMissileTarget, nX, nY);
            return;
        }

        if (!bUseColdSkill && pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
        {
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[4] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
}
