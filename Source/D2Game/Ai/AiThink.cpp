#include "D2Game.h"
#include "D2Structs.h"

#define ASSERT(expr,line) if (!(expr)) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),line); exit(-1); }
#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STATE_INVIS 0x92
#define MONMODE_ATTACK1 4
#define SKILL_MINIONSPAWNER 0x12E

struct D2AiTickStrc;
struct D2AiTableStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2AiCmdStrc;
struct D2SkillsTxt;
struct D2SeedStrc;
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

struct D2AiControlStrc
{
    int state;
    AiFn function;
    int unk08[3];
    union
    {
        int dwAiParam[3];
        int unk14;
    };
};

struct D2AiTickStrc { D2AiControlStrc* control; int unk04[6]; void* monstats; void* monstats2; };

struct D2AiTableStrc { int unk00; AiFn init; AiFn function; AiFn alternate; };

struct D2DataTablesStrc
{
    char unk_00[0xC4];
    int nStatesTxtRecordCount;
    unsigned char unk_C8[0x9B8];
    int monstatsCount;
    unsigned char unk_A84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const char gszEmpty_006CC837[]; // 0x006CC837
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);
int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0
D2AiTableStrc* __fastcall sub_005B15D0_GetAiTable(D2UnitStrc*,int); // 0x005B15D0

struct D2GameStrc
{
    char unk_00[0x1C];
    void* pMemoryPool;
    char unk_20[0x4D];
    unsigned char nDifficulty;
    char unk6E[0x3A];
    int dwGameFrame;
};

void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc*,D2UnitStrc*); // 0x0058EDE0
void* __fastcall DATATBLS_GetMonStatsTxtRecord(int); // 0x00451F80
void* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc*,D2UnitStrc*,D2AiTickStrc*); // 0x005B0CD0

struct D2StaticPathStrc
{
    int unk00[3];
    int nXPos;
    int nYPos;
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

struct D2AiCmdStrc { D2AiCmdStrc* pNextCmd; D2AiCmdStrc* pPrevCmd; int nCmdParam[5]; };

struct D2SkillsTxt
{
    char unk00[0x80];
    short nAuraState;
    short nAuraTargetState;
    unsigned char unk_84[0x1B8];
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc*); // 0x005353F0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc*, int, int); // 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc*, D2UnitStrc*, D2AiCmdStrc*); // 0x0058EF40
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*, int, int); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*, int, int, unsigned char); // 0x005DE190
void __fastcall AITACTICS_WalkInRadiusToTarget(D2GameStrc*, D2UnitStrc*, unsigned char); // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DED90
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DEE50
int __fastcall sub_005DF7D0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005DF7D0
int __fastcall sub_005E8810_SelectAction(D2AiControlStrc*, D2UnitStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*); // 0x005E8810
int __fastcall sub_005E8EB0_CullTarget(D2UnitStrc*, D2UnitStrc*); // 0x005E8EB0
D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc*, D2UnitStrc*, int*, int*, D2AiCmdStrc*, int (__fastcall*)(D2UnitStrc*,D2UnitStrc*)); // 0x005E8F20
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

struct D2CoordStrc { int nX; int nY; };

extern const int gnSkillTable_006E3514[5]; // 0x006E3514
int __fastcall sub_005EDF70_TryRoomSteps(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005EDF70
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0

struct D2SuperUniquesTxt { int unk_00; int nClass; };

struct D2BaalThroneAiCallbackArgStrc { D2UnitStrc* pTarget1; int nDistance1; D2UnitStrc* pTarget2; int nDistance2; int unk_10[6]; };

extern const int gnBaalThroneSuperUniqueIds[]; // 0x006E3528
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecord(int nSkill); // 0x0045C4B0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860
void __fastcall sub_00553380_SetUnitFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00553380
void __fastcall sub_00571C00_RemoveMonsterCorpses(D2UnitStrc* pUnit, int nClass); // 0x00571C00
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClass, int nMode); // 0x00574370
int __fastcall sub_00586B30_GetSuperUniqueId(int nIndex); // 0x00586B30
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nState); // 0x005B0E00
D2UnitStrc* __fastcall sub_005DD0B0_FindTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, void* pCallback, int nCallbackId); // 0x005DD0B0
void __fastcall sub_005EF210_BaalThroneSpawnMinion(D2UnitStrc* pUnit, int nSuperUnique, D2AiTickParamStrc* pTick); // 0x005EF210
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pPool, int nFlags, int nExpire, int nType, int nUnitId); // 0x006251F0
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

// 0x005B0E00
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState)
{
    ASSERT(!STATES_CheckState(pUnit, 54), 422);

    if (!pGame || !pUnit || !pAiControl || nAiSpecialState >= 18 || (!pUnit ? 6 : pUnit->dwUnitType) != 1)
    {
        return;
    }

    const int nClassId = pUnit->dwClassId;
    if (nClassId >= sgptDataTables->monstatsCount)
    {
        nAiSpecialState = 1;
    }

    if (pAiControl->function)
    {
        D2AiTableStrc* pAiTableRecord = sub_005B15D0_GetAiTable(pUnit, pAiControl->state);
        if (pAiControl->function == pAiTableRecord->function && pAiTableRecord->alternate)
        {
            pAiControl->state = nAiSpecialState;
            pAiControl->function = pAiTableRecord->alternate;
            return;
        }
    }

    memset(&pAiControl->unk14, 0, 3 * sizeof(int));

    AIGENERAL_FreeAllAiCommands(pGame, pUnit);

    D2AiTableStrc* __restrict pAiTableRecord = sub_005B15D0_GetAiTable(pUnit, nAiSpecialState);
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

        pAiTableRecord->init(pGame, pUnit, &aiTickParam);
    }

    AiFn pAiParamFn = pAiTableRecord->function;
    if (!pAiParamFn)
    {
        pAiParamFn = AITHINK_Fn001_100_Idle_Buffy;
    }

    pAiControl->state = nAiSpecialState;
    pAiControl->function = pAiParamFn;

    ASSERT(!IsBadCodePtr((void*)pAiParamFn), 498);
}

#include "gen/data/Source/D2Game/Ai/AiThink.inc"

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
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
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

static __forceinline int GetX(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetY(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nYPos; }
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
        pTarget = AIBAAL_GetTarget(pGame, pUnit, &nMax, &nCount, pCmd, sub_005E8EB0_CullTarget);
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
        AITACTICS_SetVelocity(pUnit, 0, 20, 0);
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
        AITACTICS_SetVelocity(pUnit, 0, 50, 100);
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
            AITACTICS_SetVelocity(pUnit, 0, 50, 100);
            if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX + (nDistance >> 1) * nDirectionX, nTargetY + (nDistance >> 1) * nDirectionY)) {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
            }
        }
        break;
    case 15:
        {
            if ((pTarget ? pTarget->dwUnitType : 6) != 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 3); break; }
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
        AITACTICS_SetVelocity(pUnit, 0, 20, 0);
        AITACTICS_WalkInRadiusToTarget(pGame, pUnit, 5);
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
    return pSuperUnique->nClass;
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
                sub_00571C00_RemoveMonsterCorpses(pUnit, nWave);
                switch (nWave)
                {
                case 62: sub_00571C00_RemoveMonsterCorpses(pUnit, 23); break;
                case 105: sub_00571C00_RemoveMonsterCorpses(pUnit, 381); break;
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
            if (pSkills->nAuraTargetState >= 0 && pSkills->nAuraTargetState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pTarget, pSkills->nAuraTargetState)) goto Idle;
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
