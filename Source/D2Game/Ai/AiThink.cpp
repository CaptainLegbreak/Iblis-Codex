#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2PlayerModes.h"

#define ASSERT(expr,line) if (!(expr)) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),line); exit(-1); }

#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define STATE_INVIS 0x92

#define SKILL_MINIONSPAWNER 0x12E

struct D2AiTickStrc;

struct D2AiTableStrc;

struct D2StaticPathStrc;

struct D2MonStatsTxt;

struct D2AiCmdStrc;

struct D2SkillsTxt;

union D2SeedStrc;

struct D2UnitStrc;

struct D2AiControlStrc;

struct D2DataTablesStrc;

struct D2GameStrc;

struct D2AiTickParamStrc;

struct D2CoordStrc;

struct D2SuperUniquesTxt;

struct D2BaalThroneAiCallbackArgStrc;

extern "C" void* __cdecl memset(void*,int,unsigned int);

typedef void (__fastcall* AiFn)(D2GameStrc*,D2UnitStrc*,D2AiTickStrc*);

struct D2AiTickStrc { D2AiControlStrc* control; int unk04[6]; void* monstats; void* monstats2; };

struct D2AiTableStrc { int unk00; AiFn init; AiFn function; AiFn alternate; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const char gszEmpty_006CC837[]; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

__declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);

int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0

D2AiTableStrc* __fastcall sub_005B15D0_GetAiTable(D2UnitStrc*,int); // 0x005B15D0

void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc*,D2UnitStrc*); // 0x0058EDE0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc*,D2UnitStrc*,D2AiTickStrc*); // 0x005B0CD0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc*); // 0x005353F0

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc*, int, int); // 0x0058EEF0

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* hUnit, int nX, int nY); // 0x005DC5C0

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080

void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200

int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0

int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DED90

int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DEE50

int __fastcall sub_005DF7D0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005DF7D0

int __fastcall sub_005E8810_SelectAction(D2AiControlStrc*, D2UnitStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*); // 0x005E8810

int __fastcall AITHINK_CullPotentialTargetsForDiablo(D2UnitStrc*, D2UnitStrc*); // 0x005E8EB0

D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc*, D2UnitStrc*, int*, int*, D2AiCmdStrc*, int (__fastcall*)(D2UnitStrc*,D2UnitStrc*)); // 0x005E8F20

void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

extern const int gnSkillTable_006E3514[5]; // 0x006E3514

int __fastcall sub_005EDF70_TryRoomSteps(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005EDF70

int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0

struct D2BaalThroneAiCallbackArgStrc { D2UnitStrc* pTarget1; int nDistance1; D2UnitStrc* pTarget2; int nDistance2; int unk_10[6]; };

extern const int gnBaalThroneSuperUniqueIds[]; // 0x006E3528

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecord(int nSkill); // 0x0045C4B0

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

void __fastcall sub_00553380_SetUnitFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00553380

void __fastcall SUNITMSG_QueueMonsterPrecache(D2UnitStrc* pUnit, int nClass); // 0x00571C00

int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClass, int nMode); // 0x00574370

int __fastcall sub_00586B30_GetSuperUniqueId(unsigned int nIndex); // 0x00586B30

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nState); // 0x005B0E00

D2UnitStrc* __fastcall sub_005DD0B0_FindTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, void* pCallback, int nCallbackId); // 0x005DD0B0

void __fastcall sub_005EF210_BaalThroneSpawnMinion(D2UnitStrc* pUnit, int nSuperUnique, D2AiTickParamStrc* pTick); // 0x005EF210

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pList, int nState); // 0x006252D0

void __stdcall sub_00626E10(D2UnitStrc* pUnit, D2StatListStrc* pList, int bReset); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pList, int nStat, int nValue, int nLayer); // 0x00627150

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUnique); // 0x006556E0

extern "C" const char gszEmptyAssertText; // 0x006CC837

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

int __fastcall ACT5Q5_GetPortalCount(D2GameStrc* pGame); // 0x0058CFB0

int __fastcall ACT5Q5_IsActivatable(D2GameStrc* pGame); // 0x0058CFE0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

struct D2AiBaalTargetArgsStrc;

#define UNIT_PLAYER 0

#define PATHTYPE_TOWARD 2

int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY);               // 0x005DC530

int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs); // 0x005E8530

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40

extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget);        // 0x00648B90

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType);                                    // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3);                   // 0x00649970

// 0x005B0E00
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* hUnit, D2AiControlStrc* pAiControl, int nAiSpecialState)
{
    ASSERT(!STATES_CheckState(hUnit, 54), 422);

    if (!pGame || !hUnit || !pAiControl || nAiSpecialState >= 18 || (!hUnit ? 6 : hUnit->dwUnitType) != 1)
    {
        return;
    }

    const int nClassId = hUnit->dwClassId;
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nAiSpecialState = 1;
    }

    if (pAiControl->pAiParamFn)
    {
        D2AiTableStrc* pAiTableRecord = sub_005B15D0_GetAiTable(hUnit, pAiControl->nAiSpecialState);
        if ((AiFn)pAiControl->pAiParamFn == pAiTableRecord->function && pAiTableRecord->alternate)
        {
            pAiControl->nAiSpecialState = nAiSpecialState;
            pAiControl->pAiParamFn = (void*)pAiTableRecord->alternate;
            return;
        }
    }

    memset(pAiControl->dwAiParam, 0, 3 * sizeof(int));

    AIGENERAL_FreeAllAiCommands(pGame, hUnit);

    D2AiTableStrc* __restrict pAiTableRecord = sub_005B15D0_GetAiTable(hUnit, nAiSpecialState);
    if (!pAiTableRecord)
    {
        return;
    }

    if (pAiTableRecord->init)
    {
        D2AiTickStrc aiTickParam = {};
        aiTickParam.control = pAiControl;
        aiTickParam.monstats = DATATBLS_GetMonStatsTxtRecord(nClassId);
        aiTickParam.monstats2 = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (!aiTickParam.monstats || !aiTickParam.monstats2)
        {
            return;
        }

        pAiTableRecord->init(pGame, hUnit, &aiTickParam);
    }

    AiFn pAiParamFn = pAiTableRecord->function;
    if (!pAiParamFn)
    {
        pAiParamFn = AITHINK_Fn001_100_Idle_Buffy;
    }

    pAiControl->nAiSpecialState = nAiSpecialState;
    pAiControl->pAiParamFn = (void*)pAiParamFn;

    ASSERT(!IsBadCodePtr((void*)pAiParamFn), 498);
}

struct D2MonStats2Txt;

struct D2StatListStrc;

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E5730
void __fastcall sub_005E5730_InitOwnerOffset(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    D2_ASSERT(pOwner, 3607);

    const int nOwnerX = CLIENTS_GetUnitXInline(pOwner);
    const int nOwnerY = CLIENTS_GetUnitYInline(pOwner);
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = nX - nOwnerX;
    pAiControl->dwAiParam[1] = nY - nOwnerY;
    if (pOwner == pUnit)
    {
        pAiControl->dwAiParam[2] = SEED_RollRandomNumber(&pUnit->pSeed) % 100;
    }
}

// 0x005E8F20
D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*))
{
    D2_ASSERT(pfCull, 890);

    UNITS_GetRoom(pUnit);

    D2UnitStrc* pTarget = 0;
    int nCount = 0;
    int nMax = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* ptTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (ptTargetNode)
        {
            D2_ASSERT(ptTargetNode->hUnit && ptTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 917);
            D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
                else
                {
                    nCurrent = 0;
                }

                while (1)
                {
                    if (nMax < nCurrent)
                    {
                        nMax = nCurrent;
                        pTarget = pTargetUnit;
                    }

                    ptTargetNode = ptTargetNode->pNext;
                    ++nCount;

                    if (!ptTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = ptTargetNode->hUnit;
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
            }
        }

        ptTargetNode = *++ppTargetNode;
    }

    while (ptTargetNode)
    {
        D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        ptTargetNode = ptTargetNode->pNext;
    }

    ptTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (ptTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            ptTargetNode = ptTargetNode->pNext;
        }
        while (ptTargetNode);

        if (pTemp && AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTemp, nX, nY) < 5 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            sub_00648B90_SetPathTarget(pPath, pTarget);
            PATH_SetType(pPath, PATHTYPE_TOWARD);
            D2Common_10142(pPath, pUnit, 0);

            if (!sub_00648780_pointCount(pPath))
            {
                pTarget = pTemp;
                nMax = nTemp;
            }
        }
    }

    *pCount = nCount;
    *pMax = nMax;

    return pTarget;
}

static __forceinline int GetX(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetY(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline D2SkillsTxt* GetSkill(int nId) {
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

// 0x005E9170
void __fastcall sub_005E9170_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pStats = pTick->pMonstatsTxt;
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pCmd) {
        D2AiCmdStrc cmd;
        cmd.nCmdParam[0] = 10;
        cmd.nCmdParam[1] = GetX(pUnit);
        cmd.nCmdParam[2] = GetY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &cmd);
        pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }
    D2UnitStrc* pTarget;
    D2AiControlStrc* pAi;
    int nAction;
    {
        int nMax;
        int nCount;
        pTarget = AIBAAL_GetTarget(pGame, pUnit, &nMax, &nCount, pCmd, AITHINK_CullPotentialTargetsForDiablo);
        pAi = pTick->pAiControl;
        nAction = sub_005E8810_SelectAction(pAi, pUnit, pTarget, nMax, nCount, pCmd);
    }
    if (nAction != 5 && pStats->nSkill[7] >= 0) {
        D2SkillsTxt* pSkill = GetSkill(pStats->nSkill[7]);
        if (pSkill && pSkill->nAuraState >= 0 && !STATES_CheckState(pUnit, pSkill->nAuraState)) {
            if (AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[7], pStats->nSkill[7], pTarget, 0, 0)) {
                pAi->dwAiParam[0] = 0;
                return;
            }
        }
    }
    int bKeepAction = 0;
    switch (nAction) {
    case 1:
        sub_005DE190_SetAiParam(pUnit, 0, 20, 0);
        AITACTICS_WalkToTargetCoordinates(pGame, pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
        break;
    case 2: AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget); break;
    case 3: AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget); break;
    case 4: AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 11, pTarget); break;
    case 5:
        if (pStats->nSkill[0] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        if (STATES_CheckState(pUnit, 12)) {
            STATES_ToggleState(pUnit, 12, 0);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
            break;
        }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pTarget, 0, 0);
        bKeepAction = 1;
        break;
    case 6:
        if (pStats->nSkill[2] >= 0) AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[2], pStats->nSkill[2], pTarget, 0, 0);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
        break;
    case 7:
        if (pStats->nSkill[1] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[1], pStats->nSkill[1], pTarget, 0, 0);
        break;
    case 8:
        if (pStats->nSkill[3] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pTarget, 0, 0);
        break;
    case 13:
        if (pStats->nSkill[5] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[5], pStats->nSkill[5], pTarget, 0, 0);
        break;
    case 9:
        if (pStats->nSkill[6] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[6], pStats->nSkill[6], pTarget, 0, 0);
        break;
    case 10:
        if (pStats->nSkill[4] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[4], pStats->nSkill[4], pTarget, 0, 0);
        break;
    case 12: sub_005DF7D0(pGame, pUnit, pTarget, 4, 0); break;
    case 14:
        sub_005DE190_SetAiParam(pUnit, 0, 50, 100);
        if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            int nTargetX = pCmd->nCmdParam[1];
            int nTargetY = pCmd->nCmdParam[2];
            int nDistance = AIUTIL_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
            int nDirectionX = 0;
            int nDirectionY = 0;
            if (nX < nTargetX) nDirectionX = -1;
            if (nX > nTargetX) nDirectionX = 1;
            if (nY < nTargetY) nDirectionY = -1;
            if (nY > nTargetY) nDirectionY = 1;
            sub_005DE190_SetAiParam(pUnit, 0, 50, 100);
            if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX + (nDistance >> 1) * nDirectionX, nTargetY + (nDistance >> 1) * nDirectionY)) {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
            }
        }
        break;
    case 15:
        {
            if ((pTarget ? pTarget->dwUnitType : UNIT_INVALID) != 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 3); break; }
            int nObjectId = PLAYER_GetUniqueIdFromPlayerData(pTarget);
            if (!SUNIT_GetServerUnit(pGame, 2, nObjectId)) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
            if (pStats->nSkill[6] >= 0) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[6], pStats->nSkill[6], 0, nObjectId, 2);
                break;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
        }
        break;
    case 16:
        sub_005DE190_SetAiParam(pUnit, 0, 20, 0);
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        break;
    default:
        {
            int nDelay = 12;
            switch (pGame->nDifficulty) { case 1: nDelay = 8; break; case 2: nDelay = 4; break; }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, nDelay);
        }
        break;
    }
    if (!bKeepAction) pAi->dwAiParam[0] = 0;
    else pAi->dwAiParam[0] = nAction;
}

static __forceinline int AI_RollPercentage(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005EE040
void __fastcall sub_005EE040_ChooseAreaSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if ((!pAiControl->dwAiParam[2] || AI_RollPercentage(pSeed) < 3) && sub_005EDF70_TryRoomSteps(pGame, pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 0, pTarget);
        return;
    }
    if (!pAiControl->dwAiParam[2]) pAiControl->dwAiParam[2] = 1;
    if (AI_PARAM(1) - pGame->dwGameFrame + pAiControl->dwAiParam[2] <= 0)
    {
        if (pTarget && AI_RollPercentage(pSeed) < AI_PARAM(0))
        {
            int nSkill;
            if (pAiControl->dwAiParam[1] <= 0)
            {
                nSkill = SEED_RollLimitedRandomNumber(pSeed, 5);
                pAiControl->dwAiParam[0] = nSkill;
                pAiControl->dwAiParam[1] = AI_PARAM(4);
            }
            else
            {
                nSkill = pAiControl->dwAiParam[0];
                --pAiControl->dwAiParam[1];
            }
            D2CoordStrc coords;
            coords.nX = CLIENTS_GetUnitX(pTarget) + SEED_RollLimitedRandomNumber(pSeed, 2 * AI_PARAM(3)) - AI_PARAM(3);
            coords.nY = CLIENTS_GetUnitY(pTarget) + SEED_RollLimitedRandomNumber(pSeed, 2 * AI_PARAM(3)) - AI_PARAM(3);
            if (COLLISION_GetFreeCoordinatesEx(UNITS_GetRoom(pUnit), &coords, 2, 0x805, 3))
            {
                AITACTICS_UseSkill(pGame, pUnit, 4, gnSkillTable_006E3514[nSkill], 0, coords.nX, coords.nY);
                pAiControl->dwAiParam[2] = pGame->dwGameFrame;
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(1));
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(1));
}

// 0x005EEAA0
void __fastcall AITHINK_Fn132_AncientStatue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!ACT5Q5_IsActivatable(pGame) || ACT5Q5_GetPortalCount(pGame) || STATES_CheckState(pUnit, STATE_INVIS))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit), 0);
    AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, SKILL_MINIONSPAWNER, 0, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
}

// 0x005EEB10
int __fastcall AITHINK_AreUnitsInSameLevel(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2_ASSERT(pUnit, 0x15CA);
    D2_ASSERT(pTarget, 0x15CB);

    return DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget));
}

// build: context BAALTHRONE_GetSuperUniqueClass
static __forceinline int BAALTHRONE_GetSuperUniqueClass(int nSuperUnique)
{
    D2SuperUniquesTxt* pSuperUnique = DATATBLS_GetSuperUniquesTxtRecord(nSuperUnique);
    if (!pSuperUnique)
    {
        return -1;
    }
    return pSuperUnique->dwClass;
}

// 0x005EF320
void __fastcall sub_005EF320_ThinkBaalThrone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    if (!pMonStats)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pGame->dwGameFrame - pAiControl->dwAiParam[2]);
        return;
    }
    D2BaalThroneAiCallbackArgStrc arg;
    int nWave = pAiControl->dwAiParam[0];
    arg.pTarget1 = 0;
    arg.nDistance2 = 64;
    arg.pTarget2 = 0;
    arg.nDistance1 = 64;
    sub_005DD0B0_FindTarget(pGame, pUnit, &arg, 0, 3);
    if (!arg.pTarget2)
    {
        if (!(pTick->pAiControl->dwAiParam[1] & 1))
        {
            if ((unsigned int)nWave <= 4)
            {
                nWave = BAALTHRONE_GetSuperUniqueClass(sub_00586B30_GetSuperUniqueId(gnBaalThroneSuperUniqueIds[nWave]));
                if (nWave < 0) return;
                SUNITMSG_QueueMonsterPrecache(pUnit, nWave);
                switch (nWave)
                {
                case 62: SUNITMSG_QueueMonsterPrecache(pUnit, 23); break;
                case 105: SUNITMSG_QueueMonsterPrecache(pUnit, 381); break;
                }
            }
            AITACTICS_UseSkill(pGame, pUnit, 10, 285, pUnit, 0, 0);
            pTick->pAiControl->dwAiParam[1] |= 1;
            pTick->pAiControl->dwAiParam[2] = pGame->dwGameFrame + 250;
            sub_00553380_SetUnitFlag(pUnit, 16, 0);
            return;
        }
        if (nWave >= 5)
        {
            MONSTER_Reinitialize(pGame, pUnit, 559, 1);
            AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
            STATES_ToggleState(pUnit, 142, 1);
            D2StatListStrc* pList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0,
                !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (pList)
            {
                sub_00626E10(pUnit, pList, 1);
                STATLIST_SetState(pList, 142);
                STATLIST_SetStat(pList, 355, 559, 0);
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }
        int nSuperUnique = DATATBLS_MapSuperUniqueId(2, sub_00586B30_GetSuperUniqueId(gnBaalThroneSuperUniqueIds[nWave]));
        sub_005EF210_BaalThroneSpawnMinion(pUnit, nSuperUnique, pTick);
        return;
    }
    D2UnitStrc* pTarget = pTick->pTarget;
    if (pMonStats->nSkill[0] > 0 && pTarget)
    {
        D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(pMonStats->nSkill[0]);
        if (pSkills)
        {
            if (pSkills->nAuraState >= 0 && pSkills->nAuraState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pUnit, pSkills->nAuraState)) goto Idle;
            if (pSkills->wAuraTargetState >= 0 && pSkills->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pTarget, pSkills->wAuraTargetState)) goto Idle;
            if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], pTarget, 0, 0);
                return;
            }
        }
    }
Idle:
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

#include "gen/data/Source/D2Game/Ai/AiThink.inc"
