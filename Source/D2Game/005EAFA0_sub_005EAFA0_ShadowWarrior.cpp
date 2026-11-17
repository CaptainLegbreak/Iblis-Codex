struct Seed { unsigned int low, high; };
struct Unit { char unknown00[32]; Seed seed; };
struct Game { char unknown00[0x6D]; unsigned char difficulty; char unknown6E[0x3A]; int frame; };
struct MonStats { char unknown00[0x56]; short param[8][3]; };
struct AiControl { char unknown00[0x14]; int param[3]; };
struct Tick { AiControl* control; int unknown04; Unit* target; int unknown0C[2]; int distance; int combat; MonStats* stats; };
struct Skill;
struct T005EAFA0 { char unknown00[0x190]; unsigned int delay; };
unsigned int __fastcall SEED_RollLimitedRandomNumber(Seed*, int); // 0x0045C390
T005EAFA0* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(Game*, Unit*, int, int); // 0x00540E60
Unit* __fastcall AIGENERAL_GetMinionOwner(Unit*); // 0x0058F0D0
void __fastcall AITACTICS_IdleInNeutralMode(Game*, Unit*, int); // 0x005DE080
int __fastcall AITACTICS_UseSkill(Game*, Unit*, unsigned char, int, Unit*, int, int); // 0x005DEAD0
int __fastcall sub_005DED20_WalkToTarget(Game*, Unit*, Unit*); // 0x005DED20
int __fastcall sub_005E45D0(Game*, Unit*, Unit*, Unit*, int, Tick*, int, int); // 0x005E45D0
int __fastcall sub_005EAD50_CheckSkill(Game*, Unit*, Unit*, Skill*, int, int, Tick*); // 0x005EAD50
int __fastcall sub_005EAF00_ShadowWarriorSkillLevel(Unit*, Unit*, Skill*, Tick*); // 0x005EAF00
Skill* __stdcall UNITS_GetLeftSkill(Unit*); // 0x00620190
Skill* __stdcall UNITS_GetRightSkill(Unit*); // 0x006201D0
int __stdcall sub_006416D0_UnitEdgeDistance(Unit*, Unit*); // 0x006416D0
Skill* __fastcall SKILLS_GetSkillById(Unit*, int, int); // 0x006439B0
int __stdcall SKILLS_GetSkillIdFromSkill(Skill*, const char*, int); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(Unit*, Skill*, int); // 0x006442A0
int __stdcall SKILLS_GetSkillMode(Skill*); // 0x00644360
int __stdcall D2Common_11016(Unit*, Skill*); // 0x00645460
int __stdcall SKILLS_EvaluateSkillFormula(Unit*, unsigned int, int, int); // 0x00646CA0
void __stdcall SKILLS_AssignSkill(Unit*, int, int, int, const char*, int); // 0x00647280
#define MAXIMUM(a,b) ((a) > (b) ? (a) : (b))
#define MINIMUM(a,b) ((a) < (b) ? (a) : (b))
#define PARAM(n) stats->param[n][game->difficulty]
// 0x005EAFA0
void __fastcall sub_005EAFA0_ShadowWarrior(Game* game, Unit* unit, Tick* tick)
{
    MonStats* stats = tick->stats;
    Unit* target = tick->target;
    int combat = tick->combat;
    int distance = tick->distance;
    D2GAME_EVENTS_Delete_6FC34840(game, unit, 2, 0);
    Unit* owner = AIGENERAL_GetMinionOwner(unit);
    if (!owner) { AITACTICS_IdleInNeutralMode(game, unit, 100); return; }
    int limit = MINIMUM(MAXIMUM(tick->stats->param[7][2], 1), 256);
    tick->control->param[1] -= PARAM(3) + 1;
    if (tick->control->param[1] < 0 || tick->control->param[1] > 64 * limit) tick->control->param[1] = 0;
    int ownerDistance = sub_006416D0_UnitEdgeDistance(unit, owner);
    if (distance > PARAM(0) || ownerDistance > PARAM(1)) target = 0;
    if (sub_005E45D0(game, unit, target, owner, combat, tick, 0, 6)) return;
    if (!target) goto idle;
    {
    Skill* ownerRight = UNITS_GetRightSkill(owner);
    Skill* ownerLeft = UNITS_GetLeftSkill(owner);
    if (!ownerRight || !ownerLeft) goto idle;
    int rightId = SKILLS_GetSkillIdFromSkill(ownerRight, ".\\Ai\\AiThink4.cpp", 0xB53);
    int leftId = SKILLS_GetSkillIdFromSkill(ownerLeft, ".\\Ai\\AiThink4.cpp", 0xB54);
    int rightLevel = sub_005EAF00_ShadowWarriorSkillLevel(unit, owner, ownerRight, tick);
    int leftLevel = sub_005EAF00_ShadowWarriorSkillLevel(unit, owner, ownerLeft, tick);
    SKILLS_AssignSkill(unit, rightId, rightLevel, 0, ".\\Ai\\AiThink4.cpp", 0xB59);
    SKILLS_AssignSkill(unit, leftId, leftLevel, 0, ".\\Ai\\AiThink4.cpp", 0xB5A);
    Skill* right = SKILLS_GetSkillById(unit, rightId, -1);
    Skill* left = SKILLS_GetSkillById(unit, leftId, -1);
    if (!right || !left) goto idle;
    Skill* selected = right;
    if (SEED_RollLimitedRandomNumber(&unit->seed, 2)) selected = left;
    int skillId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB66);
    int count = MAXIMUM(tick->control->param[2], 1);
    int chance = PARAM(2) - 2 * count;
    chance = MINIMUM(MAXIMUM(chance, 5), 100);
    if (combat && (int)SEED_RollLimitedRandomNumber(&unit->seed, 100) < chance) {
        selected = SKILLS_GetSkillById(unit, 0, -1);
        skillId = 0;
    }
    if (!sub_005EAD50_CheckSkill(game, unit, owner, selected, skillId, combat, tick)) {
        selected = selected == left ? right : left;
        int alternativeId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB79);
        if (!sub_005EAD50_CheckSkill(game, unit, owner, selected, alternativeId, combat, tick)) {
            selected = SKILLS_GetSkillById(unit, 0, -1);
            if (!selected) {
                SKILLS_AssignSkill(unit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 0xB81);
                selected = SKILLS_GetSkillById(unit, 0, -1);
            }
        }
    }
    if (!selected) goto idle;
    skillId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB8F);
    if (D2Common_11016(unit, selected) == 1) {
        if (combat) {
            AITACTICS_UseSkill(game, unit, SKILLS_GetSkillMode(selected), SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB96), target, 0, 0);
            T005EAFA0* record = sub_0045C4B0_GetSkillsTxtRecord(skillId);
            int level = SKILLS_GetSkillLevel(unit, selected, 1);
            if (level <= 1) level = 1;
            tick->control->param[0] = SKILLS_EvaluateSkillFormula(unit, record->delay, skillId, level) / 3 + game->frame + 18;
            return;
        }
        sub_005DED20_WalkToTarget(game, unit, target);
        return;
    }
    AITACTICS_UseSkill(game, unit, SKILLS_GetSkillMode(selected), SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xBA8), target, 0, 0);
    T005EAFA0* record = sub_0045C4B0_GetSkillsTxtRecord(skillId);
    int level = SKILLS_GetSkillLevel(unit, selected, 1);
    if (level <= 1) level = 1;
    tick->control->param[0] = SKILLS_EvaluateSkillFormula(unit, record->delay, skillId, level) / 3 + game->frame + 18;
    return;
    }
idle:
    AITACTICS_IdleInNeutralMode(game, unit, 25);
}
