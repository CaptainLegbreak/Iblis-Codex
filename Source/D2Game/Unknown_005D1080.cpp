#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

struct D2MissilesTxt;
struct D2SkillsTxt;
struct Monster;

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

enum D2C_Y09ImpInfernoConstants
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_ENDANIM = 1,
    EVENTTYPE_AITHINK = 2,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x005CC440
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pPath, int nMask); // 0x00648C30
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

struct Game
{
    unsigned char pad[28];
    void* pool;
};

struct Seed
{
    U32 low;
    U32 high;
};

struct Unit
{
    int type;
    int classId;
    U32 unknown08;
    int id;
    int mode;
    Monster* monster;
    U32 unknown18;
    void* pool;
    Seed seed;
};

struct AuraRequest
{
    Unit* owner;
    Unit* target;
    int skill;
    int level;
    int duration;
    int stat;
    int amount;
    int state;
    void* callback;
};

struct ModeRequest
{
    int mode;
    Unit* target;
    U32 field08;
    U32 field0C;
    U32 field10;
    U32 f_14;
    U32 f_18;
    U32 field1C;
};
extern "C" int __stdcall sub_00646CA0_Evaluate(Unit*, U32, int, int); // 0x00646CA0

// 0x005D1080
static __forceinline int SKILLS_GetThornsPercent(D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, 0x83, 0);
    if (nThornsPercent <= 0)
    {
        return 0;
    }
    if (!(pAttacker && pAttacker->dwUnitType == UNIT_PLAYER) && !MONSTERS_GetHirelingTypeId(pAttacker))
    {
        return nThornsPercent;
    }
    return (nThornsPercent + 4) / 8;
}

int __stdcall sub_M121_Emit_005D1080(D2UnitStrc* pDefender, D2UnitStrc* pAttacker) { return SKILLS_GetThornsPercent(pDefender, pAttacker); }

// 0x005D1320
static __forceinline void SKILLS_ResetEventsAndScheduleAiThink(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
    EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 13, 0, 0);
}

void __stdcall sub_M121_Emit_005D1320(D2GameStrc* pGame, D2UnitStrc* pUnit) { SKILLS_ResetEventsAndScheduleAiThink(pGame, pUnit); }

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D1350
int __fastcall SKILLS_SrvDo126_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
            UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;
    missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pMissile)
    {
        const int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->dwParam[1];
        PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
        MISSILE_SetTotalFrames(pMissile, nFrame);
        MISSILE_SetCurrentFrame(pMissile, nFrame);
    }

    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + 3, 0, 0);
    }
    else
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 13, 0, 0);
    }

    return 1;
}

// 0x005D1BF0
int __fastcall SKILLS_SrvSt61_SelfResurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkill, int nLevel)
{
    const unsigned int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
        return 0;
    SKILLS_ResurrectUnit(pGame, pUnit);
    pUnit->dwFlags &= ~14;
    PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 256);
    return 1;
}

// 0x005D1C30
static int __stdcall SKILLS_CreateMissileVolley(D2GameStrc* pGame, int nCount, D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nX, &missileParams.nY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
// build: symbol ?gnVolleyOffsetX@* 0x006E3254
        missileParams.nTargetX = gnVolleyOffsetX[i & 3];
// build: symbol ?gnVolleyOffsetY@* 0x006E3264
        missileParams.nTargetY = gnVolleyOffsetY[i & 3];
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

int __fastcall SKILLS_SrvDo130_VineAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D1CD0

#include "gen/data/Source/D2Game/Unknown_005D1080.inc"

static __forceinline SkillRecord* GetSkillRecord(int skill)
{
    if (skill < 0 || skill >= gVar_00744304->skillCount)
        return 0;
    return &gVar_00744304->skills[skill];
}

static __forceinline int GetUnitType(Unit* unit)
{
    return unit ? unit->type : 6;
}

static __forceinline AiState* GetAiState(Unit* unit)
{
    if (GetUnitType(unit) == 1 && unit->monster)
        return unit->monster->ai;
    return 0;
}

static __forceinline int SkillChanceSucceeds(Unit* owner, SkillRecord* record, int skill, int level)
{
    int chance = sub_00646CA0_Evaluate(owner, record->chance, skill, level);
    return sub_0045C390_Roll(&owner->seed, 100) < chance;
}

// 0x005D1D70
static __declspec(noinline) void __stdcall SKILLS_ApplyAuraStateToTarget(Unit* owner, Unit* target, int level, int skill)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return;
    AuraRequest request;
    memset(&request, 0, sizeof(request));
    request.owner = owner;
    request.target = target;
    request.skill = skill;
    request.level = level;
    request.duration = sub_00646CA0_Evaluate(owner, record->calc, skill, level);
    request.stat = -1;
    request.state = record->state;
    T005C40D0* list = sub_0056E970_Apply(&request);
    if (list)
        sub_005C6CC0_Configure(owner, list, record, skill, level);
}

static __declspec(noinline) void __stdcall sub_005D1E10_Transform(Unit* owner, int level, Game* game, Unit* target, int skill)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return;
    int selected = sub_0056E620_Select(owner, 0, skill, level, &level, 0, 0);
    if (selected < 0)
        return;
    const int type = GetUnitType(target);
    if (type != 1)
        return;
    int variant;
    sub_006510C0_ClassInfo(target->classId, 0, &variant);
    int resolved = sub_0054DA60_Resolve(selected, variant);
    sub_00574370_Change(game, target, resolved, level);
    AiState* ai = GetAiState(target);
    sub_005B0E00_Ai(game, target, ai, 15);
    ModeRequest mode;
    sub_005A7E60_FillMode(target, level, &mode);
    sub_005A7C20_SetMode(game, &mode, 1);
    sub_00639DB0_SetState(target, 142, 1);
    int ownerType, ownerId;
    if (!owner)
    {
        ownerId = -1;
        ownerType = 6;
    }
    else
    {
        ownerId = owner->id;
        ownerType = owner->type;
    }
    T005C40D0* list = sub_006251F0_Allocate(game->pool, 0, 0, ownerType, ownerId);
    if (list)
    {
        sub_00626E10_Attach(target, list, 1);
        sub_006252D0_State(list, 142);
        sub_00627150_Stat(list, 355, resolved, 0);
    }
    if (record->effect > 0 && record->effect < 43)
        sub_005A4850_Effect(game, target, record->effect, 0);
}

// build: symbol @SKILLS_SrvDo131_OverseerWhip@* 0x005D1F70
extern "C" int __fastcall SKILLS_SrvDo131_OverseerWhip(Game* game, Unit* owner, int skill, int level)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return 0;
    if (record->state < 0)
        return 0;
    if (record->state >= gVar_00744304->stateCount)
        return 0;
    Unit* target = sub_00553540_Target(game, owner);
    if (target && !sub_005541B0_Inactive(target))
    {
        const int type = GetUnitType(target);
        if (type != 1 || sub_00463900_ValidateClass(sub_00463860_BaseClass(target)) != 453
            || SkillChanceSucceeds(owner, record, skill, level)
            || sub_00639DF0_HasState(target, record->state))
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
            return 1;
        }
        sub_005D1E10_Transform(owner, level, game, target, skill);
        return 1;
    }
    return 0;
}
