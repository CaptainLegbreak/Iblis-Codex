#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2SkillsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x00553C70
static void sub_005C8C10_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C8C10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

union D2SeedStrc;

enum
{
    SKILLDO_FRAME_A = 6,
    SKILLDO_FRAME_A_SET = 7,
    SKILLDO_FRAME_A_COUNT = 0x3200,
    SKILLDO_FRAME_B = 22,
    SKILLDO_REPEATS = 4,
    SKILLDO_FRAME_B_SET = 40,
    SKILLDO_FRAME_B_COUNT = 0x1100,
    SKILLDO_FRAME_C = 30,
    SKILLDO_FRAME_C_STATE = 12,
    PATHINIT_MAX_FRAMES = 78,
    PATHINIT_CAP_FRAMES = 77,
    PATHTYPE_CHARGEDBOLT = 10,
};

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

int __fastcall SKILLDESC_CltDoFrameSteps(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    const int nRepeats = SKILLS_GetParam1(pSkill);

    switch (pUnit->nSeqCurrentFramePrecise >> 8)
    {
    case SKILLDO_FRAME_A:
        UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_A_SET);
        pUnit->dwFrameCountPrecise = SKILLDO_FRAME_A_COUNT;
        break;

    case SKILLDO_FRAME_B:
        if (nRepeats >= SKILLDO_REPEATS)
        {
            UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_B_SET);
            pUnit->dwFrameCountPrecise = SKILLDO_FRAME_B_COUNT;
        }
        else
        {
            SKILLS_SetParam1(pSkill, nRepeats + 1);
        }
        break;

    case SKILLDO_FRAME_C:
        UNITMODE_SetUnitMode(pUnit, SKILLDO_FRAME_C_STATE);
        CUNIT_MarkUnitDead(pUnit);
        break;
    }

    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
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

static void sub_005C8C10_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit);
// 0x005C8BF0
void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
}

// 0x005C8C10
static void sub_005C8C10_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nInfernoLength = 1;
    STATES_ToggleState(pUnit, 12, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    if (pMonStats2TxtRecord)
    {
        nInfernoLength = pMonStats2TxtRecord->nInfernoLen;
    }

    EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + nInfernoLength, 0, 0);
}

// 0x005C8CA0
int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    int nX;
    int nY;
    if (!pSkillsTxtRecord || nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetParam1(pSkill))
    {
        int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.nMissile = nMissileId;
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.dwFlags = 0x8020;
        missileParams.pOwner = pUnit;
        missileParams.pOrigin = pUnit;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nRange = nRange;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    SKILLS_SetParam1(pSkill, 1);

    const bool bIsMonster = pUnit && pUnit->dwUnitType == UNIT_MONSTER;
    if (!bIsMonster)
    {
        SUNIT_RewindAnimationByFrames(pGame, pUnit, 1);
        return 1;
    }

    pUnit->nSeqCurrentFramePrecise = 0xB00;
    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 2, 4, 0);
        return 1;
    }

    sub_005C8C10_StopInferno(pGame, pUnit);
    return 1;
}
// 0x005C9290
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= PATHINIT_MAX_FRAMES)
    {
        nFrames = PATHINIT_CAP_FRAMES;
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath) + nSeedOffset);
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nFrames);
    D2Common_10142(pPath, pMissile, 0);
}

