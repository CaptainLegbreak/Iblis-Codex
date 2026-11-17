typedef unsigned int U32;
struct Game
{
    unsigned char pad[28];
    void* pool;
};
struct T005C40D0;
struct Unit;
struct AiState;
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
extern "C" DataTables* gVar_00744304; // 0x00744304
extern "C" int __stdcall sub_00646CA0_Evaluate(Unit*, U32, int, int); // 0x00646CA0
extern "C" T005C40D0* __fastcall sub_0056E970_Apply(AuraRequest*); // 0x0056E970
extern "C" void __fastcall sub_005C6CC0_Configure(Unit*, T005C40D0*, SkillRecord*, int, int); // 0x005C6CC0
extern "C" int __fastcall sub_0056E620_Select(Unit*, int, int, int, int*, int, int); // 0x0056E620
extern "C" int __stdcall sub_006510C0_ClassInfo(int, int*, int*); // 0x006510C0
extern "C" int __fastcall sub_0054DA60_Resolve(int, int); // 0x0054DA60
extern "C" int __fastcall sub_00574370_Change(Game*, Unit*, int, int); // 0x00574370
extern "C" void __fastcall sub_005B0E00_Ai(Game*, Unit*, AiState*, int); // 0x005B0E00
extern "C" void __stdcall sub_005A7E60_FillMode(Unit*, int, ModeRequest*); // 0x005A7E60
extern "C" int __stdcall sub_005A7C20_SetMode(Game*, ModeRequest*, int); // 0x005A7C20
extern "C" void __stdcall sub_00639DB0_SetState(Unit*, int, int); // 0x00639DB0
extern "C" T005C40D0* __stdcall sub_006251F0_Allocate(void*, int, int, int, int); // 0x006251F0
extern "C" void __stdcall sub_00626E10_Attach(Unit*, T005C40D0*, int); // 0x00626E10
extern "C" void __stdcall sub_006252D0_State(T005C40D0*, int); // 0x006252D0
extern "C" void __stdcall sub_00627150_Stat(T005C40D0*, int, int, int); // 0x00627150
extern "C" void __fastcall sub_005A4850_Effect(Game*, Unit*, int, int); // 0x005A4850
extern "C" Unit* __stdcall sub_00553540_Target(Game*, Unit*); // 0x00553540
extern "C" int __fastcall sub_005541B0_Inactive(Unit*); // 0x005541B0
extern "C" int __fastcall sub_00463860_BaseClass(Unit*); // 0x00463860
extern "C" int __fastcall sub_00463900_ValidateClass(int); // 0x00463900
extern "C" int __fastcall sub_0045C390_Roll(Seed*, int); // 0x0045C390
extern "C" int __stdcall sub_00639DF0_HasState(Unit*, int); // 0x00639DF0

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
