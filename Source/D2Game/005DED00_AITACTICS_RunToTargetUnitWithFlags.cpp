extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

enum
{
    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_WALK = 2,
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL3 = 10,
    MONMODE_DEAD = 12,
    MONMODE_RUN = 15,
};

enum
{
    SKILL_BAALMONSTERSPAWN = 286,
    OBJECT_BAALS_PORTAL_WORLDSTONECHAMBER = 563,
};

struct D2SkillsTxt
{
    char unk0x000[0x148];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2MonStatsTxt
{
    char unk0x000[0x170];
    short nSkill[8];
    char unk0x180[0x28];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2AiParamStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    D2AiParamStrc* pAiParam;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
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
    void* pCurrentCmd;
    void* pLastCmd;
    D2GameStrc* pGame;
    int dwOwnerGUIDEx;
    unsigned int dwOwnerTypeEx;
    void* pMinionList;
    D2MapAIStrc* pMapAi;
    int nMinionSpawnClassId;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
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

struct D2BaalToStairsAiCallbackArgStrc
{
    int unk0x00;
    int nMaxDistance;
};

struct D2SandRaiderAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
};

int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags); // 0x005DEB60
void __fastcall D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(D2AiParamStrc* pAiParam, int a2, int nVel, unsigned char a4); // 0x005A6260
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
void __fastcall sub_005F6630_InitAiParamsFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005F6630
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet);       // 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E6800
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                         // 0x005DC5C0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit);                                                           // 0x0063EA40
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0

static D2SkillsTxt* AITHINK_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static D2MonStatsTxt* AITHINK_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005DED00
int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags)
{
    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_RUN, 0, 0, 1, nFlags);
}

// 0x005DED20
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_RUN, 0, 0, 1, 0);
}

// 0x005DED40
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags)
{
    D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0((pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pAiParam : 0, 13, 0, 0);
    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_WALK, 0, 0, 1, nFlags);
}

// 0x005DEF80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep)
{
    if (!bStep)
    {
        bStep = 1;
    }

    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_WALK, 0, 0, bStep, 0);
}

// 0x005DEFB0
int __fastcall AITACTICS_RunToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep)
{
    if (!bStep)
    {
        bStep = 1;
    }

    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_RUN, 0, 0, bStep, 0);
}

// 0x005E0390
void __fastcall sub_005E0390(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill[0] > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = AITHINK_GetSkillsTxtRecordInline(pMonStatsTxtRecord->nSkill[0]);
        pAiControl->dwAiParam[0] = (!pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[1]) + pGame->dwGameFrame;
    }
}

// 0x005E0400
void __fastcall AITHINK_Fn084_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pAiTickParam->pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005E2FD0
void __fastcall sub_005E2FD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[0] = -1;
}

// 0x005E3840
void __fastcall AITHINK_Fn097_Spirit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
        return;
    }

    if (bCombat)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E3890
void __fastcall AITHINK_Fn098_Smith(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    nLifePercentage = nLifePercentage < 0 ? 0 : (nLifePercentage > 100 ? 100 : nLifePercentage);
    AITACTICS_SetVelocity(pUnit, 0, (100 - nLifePercentage) >> 1, 0);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}

// 0x005E5B70
int __fastcall sub_6FCE5520(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MapAIStrc* pMapAi = pAiControl->pMapAi;
    if (pMapAi && pAiControl->dwAiParam[0] < pMapAi->nPathNodes)
    {
        if (pUnit)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = AITHINK_GetMonStatsTxtRecordInline(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                const int nSkillId = pMonStatsTxtRecord->nSkill[0];
                if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, nSkillId, 0, pMapAi->pPosition[pAiControl->dwAiParam[0]].nX, pMapAi->pPosition[pAiControl->dwAiParam[0]].nY);
                    ++pAiControl->dwAiParam[0];
                    pAiControl->dwAiParam[1] = pGame->dwGameFrame;
                    return 1;
                }
            }
        }
    }
    else
    {
        int nFrameDiff = pGame->dwGameFrame - pAiControl->dwAiParam[1];
        if (nFrameDiff < 0)
        {
            nFrameDiff = -nFrameDiff;
        }

        if (nFrameDiff > 700)
        {
            pAiControl->dwAiParam[0] = 0;
        }
    }

    return 0;
}

// 0x005E6190
void __fastcall sub_005E6190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    sub_005F6630_InitAiParamsFrame(pGame, pUnit, pAiTickParam);
    pAiTickParam->pAiControl->nMinionSpawnClassId = -1;
}

// 0x005E6300
void __fastcall sub_005E6300(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[2] = 0;
}

// 0x005E6860
bool __fastcall sub_005E6860_HomeCommandStep(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, unsigned int nMaxDistance)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        return sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam);
    }

    if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) > nMaxDistance)
    {
        D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pCurrentAiCmd)
        {
            pCurrentAiCmd->nCmdParam[1] = pAiCmd->nCmdParam[1];
            pCurrentAiCmd->nCmdParam[2] = pAiCmd->nCmdParam[2];
            pCurrentAiCmd->nCmdParam[3] = 12;
            pCurrentAiCmd->nCmdParam[4] = 10;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return true;
    }

    return false;
}

// build: context AITHINK_Fn062_TownRogue
void __fastcall AITHINK_Fn062_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    int nDistance = pAiTickParam->nTargetDistance;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// build: context sub_005E7DC0_SpecialState08TownRogue
void __fastcall sub_005E7DC0_SpecialState08TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    int nDistance = pAiTickParam->nTargetDistance;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005EA290
void __fastcall sub_005EA290(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = pGame->dwGameFrame;
    pAiControl->dwAiParam[1] = -1;
}

// 0x005EA510
void __fastcall sub_005EA510(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = -1;
    pAiControl->dwAiParam[1] = 1;
    pAiControl->dwAiParam[2] = 0;
}

// 0x005EC6A0
void __fastcall sub_005EC6A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[0] = 0;
}

// 0x005EDC00
void __fastcall sub_005EDC00_SetAiParams12(D2GameStrc* pGame, D2AiControlStrc* pAiControl, int nParam1, int nParam2)
{
    D2_ASSERT(pAiControl, 0x13B6);
    pAiControl->dwAiParam[1] = nParam1;
    pAiControl->dwAiParam[2] = nParam2;
}

// 0x005EF1F0
void __fastcall AITHINK_BaalThroneSetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag, int bSet)
{
    if (bSet)
    {
        pAiTickParam->pAiControl->dwAiParam[1] |= nFlag;
    }
    else
    {
        pAiTickParam->pAiControl->dwAiParam[1] &= ~nFlag;
    }
}

// 0x005EF210
void __fastcall sub_005EF210_BaalThroneSpawnMinion(D2UnitStrc* pUnit, int nSuperUnique, D2AiTickParamStrc* pAiTickParam)
{
    SKILLS_AssignSkill(pUnit, SKILL_BAALMONSTERSPAWN, 1, 0, ".\\Ai\\AiThink4.cpp", 0x1700);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_BAALMONSTERSPAWN);
    D2_ASSERT(pSkill, 0x1702);
    SKILLS_SetParam1(pSkill, nSuperUnique);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }

    AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL3, SKILL_BAALMONSTERSPAWN, 0, nX, nY + 13);
    ++pAiTickParam->pAiControl->dwAiParam[0];
    pAiTickParam->pAiControl->dwAiParam[2] = pGame->dwGameFrame + 100;
    AITHINK_BaalThroneSetAiParamFlag(pAiTickParam, 2, 1);
    AITHINK_BaalThroneSetAiParamFlag(pAiTickParam, 1, 0);
}

// 0x005EF5E0
D2UnitStrc* __fastcall AITHINK_TargetCallback_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2BaalToStairsAiCallbackArgStrc* pArg = (D2BaalToStairsAiCallbackArgStrc*)pCallbackArg;

    if (pTarget && pTarget->dwUnitType == UNIT_OBJECT && pTarget->dwClassId == OBJECT_BAALS_PORTAL_WORLDSTONECHAMBER)
    {
        return sub_006416D0_UnitEdgeDistance(pTarget, pUnit) <= pArg->nMaxDistance ? pTarget : 0;
    }

    return 0;
}

// 0x005F06B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SandRaider(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2SandRaiderAiCallbackArgStrc* pArg = (D2SandRaiderAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget || !pTarget || pTarget->dwUnitType != UNIT_MONSTER || STATLIST_GetUnitAlignment(pTarget) != 0 || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005FC830
void __fastcall AIBAAL_CountLivingMinions(D2UnitStrc* pUnit, void* ppUnitArg, void* pCounterArg)
{
    D2UnitStrc** ppUnit = (D2UnitStrc**)ppUnitArg;
    int* pCounter = (int*)pCounterArg;

    if (pUnit != *ppUnit && pUnit && pUnit->dwAnimMode != MONMODE_DEATH && pUnit->dwAnimMode != MONMODE_DEAD)
    {
        ++*pCounter;
    }
}
