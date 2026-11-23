#include "D2StatIds.h"
#include "D2Game.h"
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
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" DataTables* sgptDataTables; // 0x00744304
extern "C" int __stdcall SKILLS_EvaluateSkillFormula(Unit*, U32, int, int); // 0x00646CA0
extern "C" void __fastcall SKILLS_ApplyAuraStatsToStatList(Unit*, T005C40D0*, SkillRecord*, int, int); // 0x005C6CC0
extern "C" int __fastcall D2GAME_GetSummonIdFromSkill(Unit*, int, int, int, int*, int, int); // 0x0056E620
extern "C" int __stdcall DATATBLS_GetMonsterChainInfo(int, int*, int*); // 0x006510C0
extern "C" int __fastcall SKILLS_GetMonsterClassFromChain(int, int); // 0x0054DA60
extern "C" int __fastcall MONSTER_Reinitialize(Game*, Unit*, int, int); // 0x00574370
extern "C" void __fastcall AITHINK_ExecuteAiFn(Game*, Unit*, AiState*, int); // 0x005B0E00
extern "C" void __stdcall MONSTERMODE_GetModeChangeInfo(Unit*, int, ModeRequest*); // 0x005A7E60
extern "C" int __stdcall D2GAME_ModeChange_6FC65220(Game*, ModeRequest*, int); // 0x005A7C20
extern "C" void __stdcall STATES_ToggleState(Unit*, int, int); // 0x00639DB0
extern "C" T005C40D0* __stdcall STATLIST_AllocStatList(void*, int, int, int, int); // 0x006251F0
extern "C" void __stdcall D2COMMON_10475_PostStatToStatList(Unit*, T005C40D0*, int); // 0x00626E10
extern "C" void __stdcall STATLIST_SetState(T005C40D0*, int); // 0x006252D0
extern "C" void __stdcall STATLIST_SetStatIfListIsValid(T005C40D0*, int, int, int); // 0x00627150
extern "C" void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(Game*, Unit*, int, int); // 0x005A4850
extern "C" Unit* __stdcall SUNIT_GetTargetUnit(Game*, Unit*); // 0x00553540
extern "C" int __fastcall SUNIT_IsDead(Unit*); // 0x005541B0
extern "C" int __fastcall CUNIT_GetMonsterBaseId(Unit*); // 0x00463860
extern "C" int __fastcall CUNIT_ValidateMonsterId(int); // 0x00463900
extern "C" int __fastcall SEED_RollLimitedRandomNumber(Seed*, int); // 0x0045C390
extern "C" int __stdcall STATES_CheckState(Unit*, int); // 0x00639DF0

static inline SkillRecord* GetSkillRecord(int skill)
{
    if (skill < 0 || skill >= sgptDataTables->skillCount)
        return 0;
    return &sgptDataTables->skills[skill];
}

static inline int GetUnitType(Unit* unit)
{
    return unit ? unit->type : 6;
}

static inline int SkillChanceSucceeds(Unit* owner, SkillRecord* record, int skill, int level)
{
    int chance = SKILLS_EvaluateSkillFormula(owner, record->chance, skill, level);
    return SEED_RollLimitedRandomNumber(&owner->seed, 100) < chance;
}

void __stdcall SKILLS_ApplyAuraStateToTarget(Unit* owner, Unit* target, int level, int skill); // 0x005D1D70
// 0x005D1E10
static void __stdcall sub_005D1E10_Transform(Unit* owner, int level, int skill, Game* game, Unit* target)
{
    SkillRecord* record = 0;
    if (skill >= 0 && skill < sgptDataTables->skillCount)
        record = &sgptDataTables->skills[skill];
    if (!record)
        return;

    int selected = D2GAME_GetSummonIdFromSkill(owner, 0, skill, level, &level, 0, 0);
    if (selected < 0)
        return;
    if (GetUnitType(target) != 1)
        return;

    int variant;
    DATATBLS_GetMonsterChainInfo(!target ? -1 : target->classId, 0, &variant);
    int resolved = SKILLS_GetMonsterClassFromChain(selected, variant);
    MONSTER_Reinitialize(game, target, resolved, level);

    AiState* ai;
    if (target->type == 1 && target->monster)
        ai = target->monster->ai;
    else
        ai = 0;
    AITHINK_ExecuteAiFn(game, target, ai, 15);

    ModeRequest mode;
    MONSTERMODE_GetModeChangeInfo(target, level, &mode);
    D2GAME_ModeChange_6FC65220(game, &mode, 1);
    STATES_ToggleState(target, 142, 1);

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
    T005C40D0* list = STATLIST_AllocStatList(game->pool, 0, 0, ownerType, ownerId);
    if (list)
    {
        D2COMMON_10475_PostStatToStatList(target, list, 1);
        STATLIST_SetState(list, 142);
        STATLIST_SetStatIfListIsValid(list, STAT_SHORTPARAM1, resolved, 0);
    }

    if (record->effect > 0 && record->effect < 43)
        D2GAME_BOSSES_AssignUMod_6FC6FF10(game, target, record->effect, 0);
}

// 0x005D1F70
extern "C" int __fastcall SKILLS_SrvDo131_OverseerWhip(Game* game, Unit* owner, int skill, int level)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return 0;
    if (record->state < 0)
        return 0;
    if (record->state >= sgptDataTables->stateCount)
        return 0;
    Unit* target = SUNIT_GetTargetUnit(game, owner);
    if (target && !SUNIT_IsDead(target))
    {
        const int type = GetUnitType(target);
        int bSkip = 1;
        if (type == 1 && CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(target)) == 453)
        {
            bSkip = SkillChanceSucceeds(owner, record, skill, level);
        }
        if (bSkip)
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
            return 1;
        }
        if (STATES_CheckState(target, record->state))
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
            return 1;
        }
        sub_005D1E10_Transform(owner, level, skill, game, target);
        return 1;
    }
    return 0;
}
