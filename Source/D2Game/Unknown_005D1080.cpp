#include "D2Game.h"

struct D2MissilesTxt;
struct D2SkillsTxt;
struct Monster;

struct D2UnitStrc
{
    int dwUnitType;
    char unk_04[0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk_30[0x94];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

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
    int unk0x38[7];
    void (__fastcall* pInitFunc)(D2UnitStrc* pMissile, int nInitArg);
    int nInitArg;
};

struct D2MissilesTxt
{
    char unk0x000[0x38];
    int dwParam[5];
    char unk0x04C[0x4E];
    unsigned char nVel;
    unsigned char nVelLev;
    char unk0x09C[0x108];
};

struct D2SkillsTxt
{
    char unk0x000[0x48];
    union
    {
        short wSrvMissileA;
        short wSrvMissile;
    };
    char unk0x04A[0xEE];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

enum D2C_Y09ImpInfernoConstants
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_ENDANIM = 1,
    EVENTTYPE_AITHINK = 2,
    STATE_INFERNO = 12,
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

typedef unsigned int U32;

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

struct Monster
{
    unsigned char pad[40];
    AiState* ai;
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

struct SkillRecord
{
    unsigned char pad0[96];
    U32 calc;
    unsigned char pad1[130 - 100];
    short state;
    unsigned char pad2[228 - 132];
    short effect;
    unsigned char pad3[312 - 230];
    U32 chance;
    unsigned char pad4[572 - 316];
};

struct DataTables
{
    unsigned char pad0[196];
    int stateCount;
    unsigned char pad1[2968 - 200];
    SkillRecord* skills;
    unsigned char pad2[2976 - 2972];
    int skillCount;
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

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" int __stdcall sub_00646CA0_Evaluate(Unit*, U32, int, int); // 0x00646CA0

// 0x005D1080
static __forceinline int sub_005D1080_GetThornsPercent(D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, 0x83, 0);
    if (nThornsPercent <= 0)
    {
        return 0;
    }
    if (!(pAttacker && pAttacker->dwUnitType == 0) && !MONSTERS_GetHirelingTypeId(pAttacker))
    {
        return nThornsPercent;
    }
    return (nThornsPercent + 4) / 8;
}

int __stdcall sub_M121_Emit_005D1080(D2UnitStrc* pDefender, D2UnitStrc* pAttacker) { return sub_005D1080_GetThornsPercent(pDefender, pAttacker); }

// 0x005D1320
static __forceinline void sub_005D1320_ResetUnitEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
    EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 13, 0, 0);
}

void __stdcall sub_M121_Emit_005D1320(D2GameStrc* pGame, D2UnitStrc* pUnit) { sub_005D1320_ResetUnitEvents(pGame, pUnit); }

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
int __fastcall sub_005D1BF0_ResurrectMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkill, int nLevel)
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
static int __stdcall sub_005D1C30_CreateMissileVolley(D2GameStrc* pGame, int nCount, D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel)
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
        missileParams.nTargetX = gnVolleyOffsetX_006E3254[i & 3];
        missileParams.nTargetY = gnVolleyOffsetY_006E3264[i & 3];
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// build: context sub_005D1CD0_SrvDoMissileVolley
int __fastcall sub_005D1CD0_SrvDoMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissile;
    if (nMissile <= 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    sub_005D1C30_CreateMissileVolley(pGame, nCount, pUnit, nMissile, nSkillId, nSkillLevel);
    return 1;
}

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
static __declspec(noinline) void __stdcall sub_005D1D70_ApplyAura(Unit* owner, Unit* target, int level, int skill)
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

extern "C" int __fastcall sub_005D1F70_Dispatch(Game* game, Unit* owner, int skill, int level)
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
            sub_005D1D70_ApplyAura(owner, target, level, skill);
            return 1;
        }
        sub_005D1E10_Transform(owner, level, game, target, skill);
        return 1;
    }
    return 0;
}
