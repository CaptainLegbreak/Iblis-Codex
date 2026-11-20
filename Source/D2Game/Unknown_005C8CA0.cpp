#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2SkillsTxt;







struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[5];
    int nRange;
    int unk0x50;
    void (__fastcall* pInitFunc)(D2UnitStrc* pMissile, int nInitArg);
    int nInitArg;
};

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
void __fastcall sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x00553C70
static void sub_005C8C10_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C8C10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

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

    const bool bIsMonster = pUnit && pUnit->dwUnitType == 1;
    if (!bIsMonster)
    {
        sub_6FCBD120(pGame, pUnit, 1);
        return 1;
    }

    pUnit->nSeqCurrentFramePrecise = 0xB00;
    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, 12))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 2, 4, 0);
        return 1;
    }

    sub_005C8C10_StopInferno(pGame, pUnit);
    return 1;
}

// 0x005C9220
int __fastcall sub_005C9220_SrvStTargetNotInTown(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pTargetRoom)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}
