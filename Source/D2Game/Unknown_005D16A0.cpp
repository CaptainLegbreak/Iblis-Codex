#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
struct D2SkillsTxt;
struct Monster;


struct D2DamageStrc { int unk00; unsigned short resultFlags; unsigned short unk06; int physical; };

struct D2SkillsTxt
{
    char unk0x000[0x48];
    short wSrvMissile;
    char unk0x04A[0xEE];
    union
    {
        unsigned int dwCalc[4];
        int calc;
    };
    char unk0x148[0xF4];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*,D2UnitStrc*); // 0x00553540
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc*,D2UnitStrc*); // 0x0057D690
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc*); // 0x0058F0D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,int,int,int); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int,int,int); // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0057D4F0

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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
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

static inline int sub_0044BE50(D2UnitStrc* unit)
{
 if(!unit)return 6;
 return unit->dwUnitType;
}

// 0x005D16A0
int __fastcall sub_005D16A0_TransferLifeFromDamage(D2GameStrc* game,D2UnitStrc* unit,int skillId,int level)
{
 D2SkillsTxt* skill=(skillId>=0 && skillId<sgptDataTables->nSkillsTxtRecordCount)?&sgptDataTables->pSkillsTxt[skillId]:0;
 if(!skill)return 0;
 D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
 if(!target)return 0;
 if(unit)unit->dwFlags|=0x40;
 D2DamageStrc* damage=SUNITDMG_GetDamageFromUnits(unit,target);
 if(!damage)return 0;
 if(damage->resultFlags&1) {
  D2UnitStrc* owner=0;
  if(sub_0044BE50(unit)==1) {
   owner=AIGENERAL_GetMinionOwner(unit);
   if(!owner)owner=unit;
  }
  int life=STATLIST_UnitGetStatValue(owner,6,0);
  int maxLife=STATLIST_GetMaxLifeFromUnit(owner);
  int amount=MIN(damage->physical,STATLIST_UnitGetStatValue(target,6,0));
  life+=DATATBLS_ApplyRatio(amount,SKILLS_EvaluateSkillFormula(unit,skill->calc,skillId,level),100);
  life=MIN(MAX(life,1),maxLife);
  STATLIST_SetUnitStat(owner,6,life,0);
 }
 SUNITDMG_DrainItemDurability(game,unit,target,0);
 return 1;
}

// build: context SKILLS_GetSkillsTxtRecord
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D1C30
static int __stdcall sub_005D1C30_CreateMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCount, int nMissile, int nSkillId, int nSkillLevel)
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

// 0x005D1CD0
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

    sub_005D1C30_CreateMissileVolley(pGame, pUnit, nCount, nMissile, nSkillId, nSkillLevel);
    return 1;
}

// build: context GetSkillRecord
static __forceinline SkillRecord* GetSkillRecord(int skill)
{
    if (skill < 0)
        return 0;
    if (skill >= gVar_00744304->skillCount)
        return 0;
    return &gVar_00744304->skills[skill];
}

// build: context GetUnitType
static __forceinline int GetUnitType(Unit* unit)
{
    return unit ? unit->type : 6;
}

// build: context GetAiState
static __forceinline AiState* GetAiState(Unit* unit)
{
    if (GetUnitType(unit) == 1 && unit->monster)
        return unit->monster->ai;
    return 0;
}

// build: context SkillChanceSucceeds
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

// 0x005D1E10
static __declspec(noinline) void __stdcall sub_005D1E10_Transform(Unit* owner, int level, int skill, Game* game, Unit* target)
{
    SkillRecord* record = 0;
    if (skill >= 0 && skill < gVar_00744304->skillCount)
        record = &gVar_00744304->skills[skill];
    if (!record)
        return;

    int selected = sub_0056E620_Select(owner, 0, skill, level, &level, 0, 0);
    if (selected < 0)
        return;
    if (GetUnitType(target) != 1)
        return;

    int variant;
    sub_006510C0_ClassInfo(!target ? -1 : target->classId, 0, &variant);
    int resolved = sub_0054DA60_Resolve(selected, variant);
    sub_00574370_Change(game, target, resolved, level);

    AiState* ai;
    if (target->type == 1 && target->monster)
        ai = target->monster->ai;
    else
        ai = 0;
    sub_005B0E00_Ai(game, target, ai, 15);

    ModeRequest mode;
    sub_005A7E60_FillMode(target, level, &mode);
    sub_005A7C20_SetMode(game, &mode, 1);
    sub_00639DB0_SetState(target, 142, 1);

    int ownerType;
    unsigned int ownerId;
    if (owner == 0)
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

// 0x005D1F70
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
        int bSkip = 1;
        if (type == 1 && sub_00463900_ValidateClass(sub_00463860_BaseClass(target)) == 453)
        {
            bSkip = SkillChanceSucceeds(owner, record, skill, level);
        }
        if (bSkip)
        {
            sub_005D1D70_ApplyAura(owner, target, level, skill);
        }
        else if (sub_00639DF0_HasState(target, record->state))
        {
            sub_005D1D70_ApplyAura(owner, target, level, skill);
        }
        else
        {
            sub_005D1E10_Transform(owner, level, skill, game, target);
        }
        return 1;
    }
    return 0;
}
