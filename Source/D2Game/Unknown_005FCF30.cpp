#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2MonStatsTxt;
struct D2AiCmdStrc;
struct D2SeedStrc;
struct D2StaticPathStrc;

enum D2C_F42AiBaalConstants
{
    STATE_INFERNO = 12,
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
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



void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0



D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20

struct D2MonStatsTxt { short nId; short nBaseId; unsigned char pad004[0x1A4]; };


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtCoords(D2ActiveRoomStrc*, int, int); // 0x00463740
unsigned short __stdcall sub_0064D9B0_CheckSize(D2ActiveRoomStrc*, int, int, int, unsigned short); // 0x0064D9B0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x0056E390
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010

enum D2C_Y11SkillItemConstants
{
    STATE_UNINTERRUPTABLE = 0x36,
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FCC60D0(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nUnitType, int nUnitGUID, int a6); // 0x005717C0
int __fastcall SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int a7); // 0x005FDA80

// 0x005FCF30
void __fastcall sub_005FCF30(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam1 = 0;
    int nParam2 = 0;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (pCurrentAiCmd)
    {
        nParam1 = pCurrentAiCmd->nCmdParam[1];
        nParam2 = pCurrentAiCmd->nCmdParam[2];
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);

    if (!AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0) && nParam1 && nParam2)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = nParam1;
        aiCmd.nCmdParam[2] = nParam2;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x005FD0F0
void __fastcall AIBAAL_SpawnUberBaalMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc coord;
    coord.nX = UNITS_GetUnitXPosition(pUnit);
    coord.nY = UNITS_GetUnitYPosition(pUnit);

    const int nMinionTypes[3] = { 0x2DC, 0x2DB, 0x2DD };
    const int nMinionModes[3] = { 1, 7, 8 };
    const int nChoice = (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 1;

    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &coord, 2, 0x100, 0);
    if (pRoom)
    {
        D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, coord.nX, coord.nY, nMinionTypes[nChoice], nMinionModes[nChoice], -1, 0);
        if (pMinion)
        {
            pMinion->dwFlags |= 0x4000000;
            STATES_ToggleState(pMinion, 0xB8, 1);
        }
    }
}

// 0x005FD200
void __fastcall AITHINK_Fn145_UberBaal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}

static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}

static __forceinline int GetMonsterBaseId(int nId)
{
    D2MonStatsTxt* pRecord = GetMonStatsTxtRecord(nId);
    if (!pRecord)
        return nId;
    return pRecord->nBaseId;
}

static __forceinline int ValidateMonsterId(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return nId;
    return -1;
}

// 0x005FD350
int __fastcall sub_005FD350_CheckMonsterCollision(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int nFlag)
{
    switch (ValidateMonsterId(GetMonsterBaseId(nMonsterId)))
    {
    case 206:
    {
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY + 3);
        if (!pTargetRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pTargetRoom, nX, nY + 3, 2, 0x3C01))
            return 0;
        break;
    }
    case 228:
        nY += 2;
        pRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY);
        if (!pRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    case 298:
        if (!nFlag)
        {
            pRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY);
            if (!pRoom)
                return 0;
            if (sub_0064D9B0_CheckSize(pRoom, nX, nY, 2, 0x3C01))
                return 0;
        }
        break;
    case 334:
    {
        int nAdjustedX = nX - 2;
        int nAdjustedY = nY - 2;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtCoords(pRoom, nAdjustedX, nAdjustedY);
        if (!pTargetRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pTargetRoom, nAdjustedX, nAdjustedY, 2, 0x1C0))
            return 0;
        break;
    }
    case 528:
    {
        nX += 2;
        nY += 4;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtCoords(pRoom, nX, nY);
        if (!pTargetRoom)
            return 0;
        if (sub_0064D9B0_CheckSize(pTargetRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    }
    }
    return 1;
}

// 0x005FD9C0
int __fastcall sub_005FD9C0_SelectSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pUnitType, int* pUnitGUID)
{
    D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    D2UnitStrc* pTarget = sub_6FD15210(pUnit, pCurrentTarget, nSkillId, nSkillLevel);
    if (!pTarget)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    if (pUnitType)
    {
        *pUnitType = pTarget->dwUnitType;
        *pUnitGUID = pTarget->dwUnitId;
    }
    return 1;
}

// 0x005FDA10
int __fastcall sub_005FDA10_TargetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2, int* pTargetType, int* pTargetGUID)
{
    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        D2UnitStrc* pTarget = SUNIT_GetLastAttacker(pGame, pUnit);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        if (pTargetType)
        {
            int nTargetType = 6;
            if (pTarget)
            {
                nTargetType = pTarget->dwUnitType;
            }
            *pTargetType = nTargetType;
            unsigned int nTargetGUID;
            if (!pTarget)
            {
                nTargetGUID = 0xFFFFFFFFu;
            }
            else
            {
                nTargetGUID = pTarget->dwUnitId;
            }
            *pTargetGUID = nTargetGUID;
        }
    }
    return 1;
}

// 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5)
{
    if (!pUnit || !pTargetUnit)
    {
        return 0;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    int nTargetUnitType = UNIT_INVALID;
    int nTargetUnitGUID = -1;
    int nTargetX;
    int nTargetY;
    if (!SKILLITEM_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, pTargetUnit, 0, 0, &nTargetUnitType, &nTargetUnitGUID, &nTargetX, &nTargetY, a5))
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (nTargetUnitType == UNIT_INVALID)
    {
        nUnitType = pTargetUnit->dwUnitType;
        nUnitGUID = pTargetUnit->dwUnitId;
    }
    else
    {
        nUnitType = nTargetUnitType;
        nUnitGUID = nTargetUnitGUID;
    }

    sub_6FCC60D0(pUnit, nSkillId, nSkillLevel, nUnitType, nUnitGUID, a5);
    return 1;
}
