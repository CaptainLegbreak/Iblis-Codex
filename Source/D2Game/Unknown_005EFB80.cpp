#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2StaticPathStrc;
struct D2UnitFindArgStrc;
struct Target005F6630;
struct Obj005F6630;
struct D2Record5F6E20Strc;
struct D2FetishShamanAiCallbackArgStrc;
struct D2AiCmdStrc;



struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
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

enum D2C_BruteAIParams
{
    BRUTE_AI_PARAM_CIRCLE_CHANCE_PCT = 1,
    BRUTE_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    BRUTE_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT = 3,
};

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

enum D2C_M80SkeletonAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    SKELETON_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    SKELETON_AI_PARAM_STALL_TIME = 1,
    SKELETON_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    SKELETON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
};

int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

enum D2C_MosquitoAIParams
{
    MOSQUITO_AI_PARAM_MIN_SUCK_LOOP = 0,
    MOSQUITO_AI_PARAM_SUCK_LOOP_RNG = 1,
    MOSQUITO_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    MOSQUITO_AI_PARAM_SUCK_OR_ATTACK_CHANCE_PCT = 3,
    MOSQUITO_AI_PARAM_MAX_AMBIENT_LOOP = 4,
};

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

typedef int(__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit);

struct D2UnitFindArgStrc
{
    int nFlags; int unk0x04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk0x28; int unk0x2C; int unk0x30; int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesNoStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE490
int __fastcall sub_005F3960_IsMonster76Alive(D2UnitStrc* pUnit); // 0x005F3960
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall sub_006260B0(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

struct Target005F6630 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; unsigned int dwValue18; };

struct Obj005F6630 { unsigned char bUnknown00[0xA8]; unsigned int dwValueA8; };

struct D2Record5F6E20Strc
{
    char unk0x00[0x32];
    short nMax;
    short nCurrent;
};

struct D2FetishShamanAiCallbackArgStrc
{
    D2UnitStrc* pClosestDeadTarget;
    int nSquaredDistanceToClosestDeadTarget;
    int nMaxSearchRangeSquared;
    D2UnitStrc* pClosestAliveTarget;
    int nSquaredDistanceToClosestAliveTarget;
    int nAliveTargets;
    int nHealCapability;
    int unk0x1C[3];
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M172FetishShamanAi
{
    STATE_INFERNO = 12,
    FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT = 0,
    FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY = 1,
    FETISHSHAMAN_AI_PARAM_HEAL_RANGE = 2,
    FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
    FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE = 4,
};

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nSkillFlags); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AIUTIL_TargetCallback pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY);
D2UnitStrc* __fastcall AITHINK_TargetCallback_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F99A0

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005EFB80
void __fastcall AITHINK_Fn007_Brute(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, BRUTE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, BRUTE_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            return;
        }

        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, BRUTE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    int nLife = UNITS_GetCurrentLifePercentage(pUnit);
    if (nLife < 40)
    {
        nLife = 40;
    }
    else if (nLife > 100)
    {
        nLife = 100;
    }

    AITACTICS_SetVelocity(pUnit, 0, 100 - nLife, 0);
    sub_6FCD0410(pGame, pUnit, pTarget, 7);
}

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005EFCF0
void __fastcall AITHINK_Fn002_Skeleton(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_STALL_TIME));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 4 | 2 | 1);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_STALL_TIME));
}

// 0x005F3730
void __fastcall AITHINK_Fn024_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_ATTACK_CHANCE_PCT) || !pAiControl->dwAiParam[1])
        {
            ++pAiControl->dwAiParam[1];

            if (pMonStatsTxt->nSkill[0] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_SUCK_OR_ATTACK_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        if (AI_RollPercentage(pUnit) > 20)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        pAiControl->dwAiParam[1] = 0;
    }

    if (pAiControl->dwAiParam[0] == 0)
    {
        AITACTICS_SetVelocity(pUnit, 13, 100, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
    }
    else if (pAiControl->dwAiParam[0] == 1)
    {
        AITACTICS_SetVelocity(pUnit, 0, 50, 0);
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_MAX_AMBIENT_LOOP))
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
        }
    }
    else if (pAiControl->dwAiParam[0] == 2)
    {
        AITACTICS_SetVelocity(pUnit, 2, 100, 0);
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 10, 1);
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;
    }
    else
    {
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

// 0x005F3960
int __fastcall sub_005F3960_IsMonster76Alive(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwUnitType : 6) != 1)
    {
        return 0;
    }

    if (MONSTERS_IsDead(pUnit))
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(sub_00463860(pUnit)) != 0x76)
    {
        return 0;
    }

    return 1;
}

static __forceinline int UNITS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int UNITS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005F39B0
void __fastcall sub_005F39B0_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nApproachOffsets[7][4][2] =
    {
        { { -10, -3 }, { 1, -5 }, { 6, 0 }, { 4, 10 } },
        { { -9, -2 }, { -6, -11 }, { -2, -5 }, { 6, 1 } },
        { { 0, 13 }, { -12, 0 }, { 7, 5 }, { -3, -11 } },
        { { -15, -3 }, { -6, -3 }, { -4, -5 }, { -6, -13 } },
        { { -12, -2 }, { -6, 2 }, { -5, 5 }, { 1, 11 } },
        { { -13, -6 }, { -8, -11 }, { -7, 0 }, { 1, 8 } },
        { { -5, -8 }, { -8, 1 }, { 1, -6 }, { 6, 9 } },
    };
    int nCastOffsets[7][4][2] =
    {
        { { 1, -5 }, { 6, 0 }, { 4, 10 }, { -10, -3 } },
        { { 1, 8 }, { -9, -2 }, { -5, 4 }, { 1, 8 } },
        { { -12, 0 }, { 7, 5 }, { -3, -11 }, { 11, -2 } },
        { { 7, 9 }, { -15, -3 }, { -6, -13 }, { 9, 7 } },
        { { -5, -7 }, { -5, -7 }, { 9, 0 }, { -12, -2 } },
        { { -8, -11 }, { -2, -6 }, { -2, -6 }, { -13, -6 } },
        { { -8, 1 }, { 1, -6 }, { 6, 9 }, { 0, 0 } },
    };
    int nCircleApproachOffsets[5][2] = { { -5, -5 }, { 3, -5 }, { 6, 3 }, { 3, 6 }, { -5, 3 } };
    int nCircleCastOffsets[5][2] = { { 6, 3 }, { 3, 6 }, { -5, 3 }, { -5, -5 }, { 3, -5 } };

    if (pTarget && pGame->dwGameFrame > pAiControl->dwAiParam[2] && AITHINK_GetSquaredDistance(pUnit, pTarget) < 1024
        && pAiControl->dwAiParam[0] < 4 && SEED_RollLimitedRandomNumber(pSeed, 1000) <= pGame->nDifficulty + 2)
    {
        pAiControl->dwAiParam[0] = 4;
    }

    if (pAiControl->dwAiParam[0] == 4)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nX = UNITS_GetUnitXInline(pUnit);
        const int nY = UNITS_GetUnitYInline(pUnit);

        D2UnitFindArgStrc unitFindArg;
        memset(&unitFindArg, 0, sizeof(unitFindArg));
        unitFindArg.nX = nX;
        unitFindArg.nY = nY;
        unitFindArg.nFlags = 0x583;
        unitFindArg.nSize = 32;

        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, 32, sub_005F3960_IsMonster76Alive, &unitFindArg);
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        if (unitFindData.nIndex == 4)
        {
            for (int i = 0; i < 4; ++i)
            {
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 1, 6);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 2, 0);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 3, i + 1);
                AITACTICS_IdleInNeutralMode(pGame, unitFindData.pUnitsArray[i], 337 - pGame->dwGameFrame % 337);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return;
        }

        if (unitFindData.nIndex == 5)
        {
            for (int i = 0; i < 5; ++i)
            {
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 1, 5);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 2, 0);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 3, i + 1);
                AITACTICS_IdleInNeutralMode(pGame, unitFindData.pUnitsArray[i], 337 - pGame->dwGameFrame % 337);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
        UNITFINDS_FreeUnitFindData(&unitFindData);
        return;
    }

    if (pAiControl->dwAiParam[0] >= 6)
    {
        if (pAiControl->dwAiParam[2] > 4)
        {
            pAiControl->dwAiParam[0] = 2;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pTarget) + nApproachOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0];
        const int nY = CLIENTS_GetUnitY(pTarget) + nApproachOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1];
        if (AIUTIL_GetDistanceToCoordinates(pUnit, nX, nY) > 3)
        {
            if (SEED_RollLimitedRandomNumber(pSeed, 100) < 34)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
                return;
            }

            AITACTICS_ChangeModeAndTargetCoordinatesNoStep(pGame, pUnit, nX, nY, 2);
            return;
        }

        if (pGame->dwGameFrame % 67)
        {
            goto lIdleS6Test;
        }

        if (pAiControl->dwAiParam[1] < 3)
        {
            if (!nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0] && !nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1])
            {
                ++pAiControl->dwAiParam[1];
                goto lIdleS6Zero;
            }

            const int nCastX = CLIENTS_GetUnitX(pTarget) + nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0];
            const int nCastY = CLIENTS_GetUnitY(pTarget) + nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1];
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 7, nCastX, nCastY);
            ++pAiControl->dwAiParam[1];
            return;
        }

        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 0;
        if (pAiControl->dwAiParam[0] - 6 > 6)
        {
            pAiControl->dwAiParam[0] = 2;
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + 1800;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);

        if (pTarget && pTarget->dwUnitType == 0 && !SUNIT_IsDead(pTarget))
        {
            const int nExpireFrame = pGame->dwGameFrame + 1728000;
            D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
            if (pStatList)
            {
                STATLIST_SetStatIfListIsValid(pStatList, 80, 50 * (pGame->nDifficulty + 1), 0);
                sub_006260B0(pStatList, nExpireFrame);
                sub_005417D0_DirectDated(pGame, pTarget, 12, nExpireFrame, 0, 0);
                D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
            }
        }
        return;
    }

    if (pAiControl->dwAiParam[0] == 5)
    {
        if (pAiControl->dwAiParam[2] > 5)
        {
            pAiControl->dwAiParam[0] = 2;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }

        {
            const int nX = nCircleApproachOffsets[pAiControl->dwAiParam[2] - 1][0] + CLIENTS_GetUnitX(pTarget);
            const int nY = nCircleApproachOffsets[pAiControl->dwAiParam[2] - 1][1] + CLIENTS_GetUnitY(pTarget);
            if (AIUTIL_GetDistanceToCoordinates(pUnit, nX, nY) > 3)
            {
                if (SEED_RollLimitedRandomNumber(pSeed, 100) < 34)
                {
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
                    return;
                }

                AITACTICS_ChangeModeAndTargetCoordinatesNoStep(pGame, pUnit, nX, nY, 2);
                return;
            }
        }

        if (pGame->dwGameFrame % 67)
        {
            goto lIdleS5Test;
        }

        if (pAiControl->dwAiParam[1] < 3)
        {
            if (!nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][0] && !nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][1])
            {
                ++pAiControl->dwAiParam[1];
                goto lIdleS5Zero;
            }

            {
                const int nCastX = CLIENTS_GetUnitX(pTarget) + nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][0];
                const int nCastY = CLIENTS_GetUnitY(pTarget) + nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][1];
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 7, nCastX, nCastY);
            }
            ++pAiControl->dwAiParam[1];
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        pAiControl->dwAiParam[2] = pGame->dwGameFrame + 1800;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
        return;

lIdleS6Test:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS6Zero:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS5Test:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS5Zero:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
        return;
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        if (pAiControl->dwAiParam[1] <= 0)
        {
            if (bCombat)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, 0);
                pAiControl->dwAiParam[0] = 3;
                return;
            }

            if (SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, 0);
                pAiControl->dwAiParam[0] = 2;
                return;
            }
        }

        --pAiControl->dwAiParam[1];
        if (SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            pAiControl->dwAiParam[0] = 1;
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
        return;
    }

    if (!bCombat && (pAiControl->dwAiParam[0] == 2 || SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0)))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 7, pTarget);
        pAiControl->dwAiParam[0] = 0;
        return;
    }

    if (bCombat && (pAiControl->dwAiParam[0] == 3 || SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1)))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        pAiControl->dwAiParam[0] = 0;
        return;
    }

    if (SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        pAiControl->dwAiParam[1] = 3;
        return;
    }

    pAiControl->dwAiParam[0] = 1;
    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
    pAiControl->dwAiParam[1] = 3;
}

// 0x005F6630
extern "C" __declspec(dllexport) void __fastcall sub_005F6630(Obj005F6630* pObj, int nUnusedEdx, Target005F6630** ppTarget) {
    Target005F6630* pTarget = *ppTarget;
    pTarget->dwValue14 = pObj->dwValueA8;
    pTarget->dwValue18 = 0;
}

// 0x005F6E20
int __fastcall sub_005F6E20_GetPercentOver100(D2Record5F6E20Strc* pRecord)
{
    int nResult = 0;
    const short nMax = pRecord->nMax;
    if (nMax > 0)
    {
        nResult = pRecord->nCurrent * 100 / nMax - 100;
        nResult = nResult > 0 ? nResult : 0;
        if (nResult >= 120)
        {
            nResult = 120;
        }
    }

    return nResult;
}

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_TYPES_COUNT;
    }
    return pUnit->dwUnitType;
}

// 0x005F9A80
void __fastcall AITHINK_Fn065_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nSkillLevel;
    D2SkillStrc* pSkill;

    if (pMonStatsTxt->nSkill[0] < 0
        || !(pSkill = SKILLS_GetSkillById(pUnit, pMonStatsTxt->nSkill[0], -1))
        || (nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1)) <= 0)
    {
        nSkillLevel = 1;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < nSkillLevel && !STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        aiCmd.nCmdParam[1] = sub_00451F50(pTarget);
        aiCmd.nCmdParam[2] = sub_0044BE50(pTarget);
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    D2FetishShamanAiCallbackArgStrc arg;
    arg.pClosestDeadTarget = 0;
    arg.nSquaredDistanceToClosestDeadTarget = 0x7FFFFFFF;
    arg.nMaxSearchRangeSquared = AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE) * AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE);
    arg.pClosestAliveTarget = 0;
    arg.nSquaredDistanceToClosestAliveTarget = 0x7FFFFFFF;
    arg.nAliveTargets = 0;
    arg.nHealCapability = AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY);
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_FetishShaman, 1);

    D2UnitStrc* pDeadTarget = arg.pClosestDeadTarget;
    if (pDeadTarget && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], arg.pClosestDeadTarget, 0, 0))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 14;
        aiCmd.nCmdParam[1] = pDeadTarget->dwUnitId;
        aiCmd.nCmdParam[2] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

        if (arg.nSquaredDistanceToClosestDeadTarget > AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_RANGE))
        {
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pDeadTarget, 10);
        }
        else
        {
            AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[2], pDeadTarget, 0, 0);
        }
        return;
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}
