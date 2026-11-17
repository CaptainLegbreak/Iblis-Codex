enum D2C_J07AiConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_ATTACK1 = 4,
    MONMODE_DEAD = 12,
    UNITFLAG_NOTC = 0x20000,
    MONTYPEFLAG_UNIQUE_CHAMPION = 0xE,
    MONSTATSFLAGINDEX_BYTE1_BIT0 = 0,
    MONSTATSFLAGINDEX_BYTE1_BIT7 = 7,
    TRAPMISSILE_AI_PARAM_DISTANCE = 0,
    TRAPMISSILE_AI_PARAM_NUM_TO_SHOOT = 1,
    TRAPMISSILE_AI_PARAM_DELAY = 2,
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x08];
    short wMonStatsEx;
    char unk0x1A[0x3C];
    short wAiParam[8][3];
    char unk0x86[0x122];
};

struct D2MonStats2Txt
{
    char unk0x00[0x10B];
    unsigned char nResurrectMode;
    unsigned short nResurrectSkill;
    char unk0x10E[0x26];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
    char unk0xA9C[0x104];
    int nSkillsTxtRecordCount;
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

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                 // 0x005DC5C0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinatesNoSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEF30
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                     // 0x0063E9F0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster);                                                   // 0x0063EDC0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
}

static __forceinline void AITHINK_DieInline(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }
    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
}

// 0x005DCDA0
D2UnitStrc* __fastcall AIUTIL_TargetCallback_CountDeadMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FallenShamanAiCallbackArgStrc* pArg = (D2FallenShamanAiCallbackArgStrc*)pCallbackArg;
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance <= pArg->nMaxDistance)
    {
        const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            const int bTargetable = pTarget ? (pTarget->dwFlags >> 1) & 1 : 0;
            if (bTargetable && !STATES_CheckStateMaskUdeadOnUnit(pTarget) && AIGENERAL_GetMinionOwner(pTarget) == pUnit)
            {
                ++pArg->nCounter;
                pArg->pTarget = pTarget;
                pArg->nDistance = nDistance;
            }
        }
    }

    return 0;
}

// 0x005E6DE0
bool __fastcall sub_6FCE61E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY && AIUTIL_GetDistanceToCoordinates(pUnit, pPosition->nX, pPosition->nY) > 0)
    {
        AITACTICS_SetVelocity(pUnit, 7, 0, 0);
        AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pPosition->nX, pPosition->nY);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
        bResult = true;
    }

    return bResult;
}

// 0x005EB650
int __fastcall AITHINK_IsTargetKillableByShadowMaster(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[MONSTATSFLAGINDEX_BYTE1_BIT0])
    {
        return 0;
    }

    if (!(pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[MONSTATSFLAGINDEX_BYTE1_BIT7]))
    {
        return 0;
    }

    if (pTarget->dwUnitType == UNIT_PLAYER)
    {
        return 1;
    }

    if (MONSTERS_IsBoss(0, pTarget))
    {
        return 1;
    }

    if (MONSTERS_IsPrimeEvil(pTarget))
    {
        return 1;
    }

    return MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE_CHAMPION) != 0;
}

// 0x005FB5B0
void __fastcall AITHINK_Fn077_TrapMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!pTarget)
    {
        AITHINK_DieInline(pGame, pUnit);
        return;
    }

    if (nTargetDistance > pMonStatsTxt->wAiParam[TRAPMISSILE_AI_PARAM_DISTANCE][pGame->nDifficulty])
    {
        AITHINK_DieInline(pGame, pUnit);
        return;
    }

    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[TRAPMISSILE_AI_PARAM_NUM_TO_SHOOT][pGame->nDifficulty])
    {
        AITHINK_DieInline(pGame, pUnit);
        return;
    }

    if (!pAiControl->dwAiParam[1])
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        pAiControl->dwAiParam[0] += 1;
        pAiControl->dwAiParam[1] = 1;
        return;
    }

    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[TRAPMISSILE_AI_PARAM_DELAY][pGame->nDifficulty]);
}

// 0x005FD7B0
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int bUseResurrectConfig)
{
    if (bUseResurrectConfig)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecordFromUnit(pUnit);
        if (pMonStats2TxtRecord)
        {
            const unsigned short nSkillId = pMonStats2TxtRecord->nResurrectSkill;
            if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
            {
                UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId));
            }

            if (pMonStats2TxtRecord->nResurrectMode < 16)
            {
                return pMonStats2TxtRecord->nResurrectMode;
            }
        }
        return MONMODE_NEUTRAL;
    }

    return MONMODE_NEUTRAL;
}
