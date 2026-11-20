#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

struct D2MonStatsTxt;
struct D2AiTargetSearchArgsStrc;
struct D2MonStats2Txt;
struct D2AiCmdStrc;
struct D2MapAIPathPositionStrc;
struct D2FallenShamanAiCallbackArgStrc;
union D2SeedStrc;
struct D2AiTargetArgsStrc;



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

struct D2AiTargetSearchArgsStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int bCheckTargetCollision;
    int nMaxDistance;
    int unk0x10;
    D2UnitStrc* pAlternativeTarget;
    int nAlternativeDistance;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0


int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit); // 0x005DC920
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0
int __stdcall sub_006259B0_GetStateStat(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40
extern "C" unsigned int __fastcall sub_00541860(D2UnitStrc* pUnit); // 0x00541860
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130

enum D2C_J07AiConstants
{
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

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinatesNoSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEF30
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
extern "C" int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall sub_00451F30_HasFlags(D2UnitStrc* pUnit, unsigned int nFlags); // 0x00451F30
int __fastcall sub_005A0180_HasMask(D2UnitStrc* pUnit, unsigned short wMask); // 0x005A0180
int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiMode, int a4); // 0x005B0DA0

struct D2AiTargetArgsStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    union
    {
        struct
        {
            int bCheckTargetCollision;
            int nMaxDistance;
            int unk0x10;
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tSearch;
        struct
        {
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tEligible;
        D2UnitStrc* pIgnoredTarget;
    };
    int unk0x1C[3];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3); // 0x00649970
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pPath); // 0x00648780
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit); // 0x005730E0
int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit); // 0x00573100
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit); // 0x00573120
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DD610

static __forceinline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

// 0x005DCA70
D2UnitStrc* __fastcall AIUTIL_TargetCallback_SelectHostileTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiTargetSearchArgsStrc* pArg = (D2AiTargetSearchArgsStrc*)pCallbackArg;

    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || !UNITS_CanBeAttackedInline(pTarget) || !sub_00554200(pGame, pUnit, pTarget))
    {
        if (pTarget->dwUnitType == 1 && (!pUnit || pUnit->dwUnitType != 0) && !sub_006259B0_GetStateStat(pUnit) && pArg->bCheckTargetCollision && !MONSTERS_IsDead(pTarget))
        {
            D2AiControlStrc* pAiControl = (D2AiControlStrc*)sub_00541860(pTarget);
            if ((pAiControl->nAiFlags & 8) && pArg->unk0x10 == D2Common_10095(UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
            {
                pAiControl->nAiFlags |= 8;
                pArg->bCheckTargetCollision = 0;
            }
        }

        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nThreat = sub_005DC920_GetThreat(pTarget);
    if (nThreat > 1)
    {
        if (nDistance >= pArg->nDistance)
        {
            return 0;
        }
    }
    else if (nDistance >= pArg->nAlternativeDistance)
    {
        return 0;
    }

    if (pArg->bCheckTargetCollision && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        return 0;
    }

    if (nThreat > 1)
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }
    else
    {
        pArg->pAlternativeTarget = pTarget;
        pArg->nAlternativeDistance = nDistance;
    }

    return 0;
}

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

// 0x005DD480
int __fastcall sub_005DD480_CanSwitchAiMode(D2UnitStrc* pUnit, int nAiMode)
{
    if (!pUnit)
    {
        return 0;
    }
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }
    if (nAiMode > 0x13)
    {
        return 0;
    }
    if (STATES_CheckState(pUnit, 0x36))
    {
        return 0;
    }
    if (!UNITS_CanSwitchAI(pUnit->dwClassId))
    {
        return 0;
    }
    if (!sub_00451F30_HasFlags(pUnit, 4) && !SUNIT_IsDead(pUnit))
    {
        return 0;
    }
    if (sub_005A0180_HasMask(pUnit, 10))
    {
        return 0;
    }
    if (nAiMode != 0x13)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!AITHINK_CanUnitSwitchAi(pUnit, pMonStatsTxtRecord, nAiMode, 1))
        {
            return 0;
        }
    }
    return 1;
}

// 0x005DD510
static int __stdcall AIUTIL_ShouldUseAlternativeTarget(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        return 0;
    }

    if (!pAlternativeTarget)
    {
        return 0;
    }

    D2UnitStrc* pCurrentTarget = *ppTarget;
    if (!pCurrentTarget)
    {
        return 1;
    }

    if (nAlternativeDistance > 5)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nPathType = sub_00648E30_GetPathValue(pPath);
    D2UnitStrc* pPathTarget = PATH_GetTargetUnit(pPath);
    const int nX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    PATH_SetTargetUnit(pPath, pCurrentTarget);
    PATH_SetType(pPath, 2);
    D2Common_10142(pPath, pUnit, 0);
    PATH_SetTargetUnit(pPath, pPathTarget);
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, nPathType);

    if (PATH_GetNumberOfPathPoints(pPath))
    {
        return 0;
    }

    D2AiTargetArgsStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.pIgnoredTarget = pCurrentTarget;
    sub_6FCF1E80(SUNIT_GetGameFromUnit(pUnit), pUnit, &arg, 0, 7);

    if (!arg.pTarget || arg.nDistance >= 20)
    {
        return 1;
    }

    *ppTarget = arg.pTarget;
    *pTargetDistance = arg.nDistance;
    return 0;
}

static __forceinline int AIUTIL_IsOverrideTargetValid_Inline(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case 0:
    case 1:
        return !SUNIT_IsDead(pTarget);
    case 3:
        return 1;
    }
    return 0;
}

// build: context AIUTIL_ResolveTargetOverride
static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = 0;
    int nDistance = 0;

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    const int nOverride = MONSTERAI_GetTargetOverrideType(pUnit);
    if (!nOverride)
    {
        return 0;
    }

    switch (nOverride)
    {
    case 1:
        pTarget = SUNIT_GetServerUnit(pGame, 0, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        break;

    case 2:
        pTarget = SUNIT_GetServerUnit(pGame, 1, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        break;

    case 4:
        pTarget = SUNIT_GetServerUnit(pGame, 3, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        break;

    case 3:
    {
        const int nAlignment = sub_006259B0_GetStateStat(pUnit);
        const int nRoll = sub_00472210_SeedRollMasked(&pUnit->pSeed, 2);
        if (nAlignment == 1)
        {
            if (nRoll)
            {
                sub_6FCBDD30(pUnit, 2, 1);
            }
            else
            {
                sub_6FCBDD30(pUnit, 0, 1);
            }
        }
        else if (nRoll)
        {
            if (nAlignment == 0)
            {
                sub_6FCBDD30(pUnit, 2, 1);
            }
            else if (nAlignment == 2)
            {
                sub_6FCBDD30(pUnit, 0, 1);
            }
        }

        D2AiTargetArgsStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;
        if (!bUseEligibilityCheck)
        {
            const int nUnk = D2Common_10095(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.unk0x10 = nUnk;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 5);
        }
        else
        {
            arg.tEligible.pAlternativeTarget = 0;
            arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 6);
        }

        pTarget = arg.pTarget;
        nDistance = arg.nDistance;
        sub_6FCBDD30(pUnit, nAlignment, 1);
        break;
    }

    default:
        sub_00573120_ClearMonsterPair(pUnit);
        return 0;
    }

    if (AIUTIL_IsOverrideTargetValid_Inline(pTarget))
    {
        *ppUnit = pTarget;
        *pDistance = nDistance;
        return 1;
    }

    sub_00573120_ClearMonsterPair(pUnit);
    return 0;
}

// 0x005DDC30
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange)
{
    D2UnitStrc* pTarget;
    int nDistance;

    if (!AIUTIL_ResolveTargetOverride(0, 1, &pTarget, &nDistance, pGame, pUnit))
    {
        D2AiTargetArgsStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;
        arg.tEligible.pAlternativeTarget = 0;
        arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
        sub_6FCF1E80(pGame, pUnit, &arg, 0, 6);

        if (AIUTIL_ShouldUseAlternativeTarget(&arg.pTarget, &arg.nDistance, arg.tEligible.pAlternativeTarget, arg.tEligible.nAlternativeDistance, pUnit))
        {
            pTarget = arg.tEligible.pAlternativeTarget;
            nDistance = arg.tEligible.nAlternativeDistance;
        }
        else
        {
            pTarget = arg.pTarget;
            nDistance = arg.nDistance;
        }
    }

    if (!pTarget)
    {
        if (pInMeleeRange)
        {
            *pInMeleeRange = 0;
        }

        if (pDistance)
        {
            *pDistance = 0x7FFFFFFF;
        }

        return 0;
    }

    if (pInMeleeRange)
    {
        *pInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    }

    if (pDistance)
    {
        *pDistance = nDistance;
    }

    return pTarget;
}
