struct Seed { unsigned int low, high; };
struct AiControl { char unknown00[0x14]; int param[3]; };
struct MonsterData { char unknown00[0x28]; AiControl* control; };
struct Unit { int type; char unknown04[0x10]; MonsterData* monster; char unknown18[8]; Seed seed; };
struct Game { char unknown00[0x6D]; unsigned char difficulty; };
struct MonStats { char unknown00[0x56]; short param[8][3]; char unknown86[0xEA]; short skill[8]; char mode[8]; char unknown188[0x20]; };
struct Tick { AiControl* control; int unknown04; Unit* target; int unknown0C[2]; int distance; int combat; MonStats* stats; };
struct Tables { char unknown000[0xA78]; MonStats* stats; int unknownA7C; int count; };
extern Tables* sgptDataTables; // 0x00744304
unsigned int __fastcall SEED_RollLimitedRandomNumber(Seed*, int); // 0x0045C390
Unit* __fastcall SUNIT_GetServerUnit(Game*, int, int); // 0x00552F60
Unit* __fastcall SUNIT_GetOwner(Game*, Unit*); // 0x00552FD0
int __fastcall SUNIT_IsDead(Unit*); // 0x005541B0
int __fastcall sub_005B0BD0_DistanceSquared(Unit*, Unit*); // 0x005B0BD0
int __fastcall sub_005DD280_LifePercent(Unit*); // 0x005DD280
Unit* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(Game*, Unit*, int*, int*); // 0x005DDC30
void __fastcall AITACTICS_IdleInNeutralMode(Game*, Unit*, int); // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(Game*, Unit*, unsigned char); // 0x005DE200
int __fastcall AITACTICS_UseSkill(Game*, Unit*, unsigned char, int, Unit*, int, int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(Game*, Unit*, Unit*, unsigned char); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(Game*, Unit*, Unit*, unsigned char); // 0x005DEF80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(Game*, Unit*, Unit*, unsigned char, int); // 0x005DEFE0
void __fastcall AITACTICS_UseSkillInRange(Unit*, int, int, int); // 0x005DF850
int __stdcall STATLIST_GetUnitAlignment(Unit*); // 0x006259B0
inline unsigned __int64 SEED_RollRandomNumber(Seed* seed)
{
    const unsigned __int64 value = seed->high + 0x6AC690C5i64 * seed->low;
    seed->high = (unsigned int)(value >> 32);
    seed->low = (unsigned int)value;
    return value;
}
static inline MonStats* GetMonStats(int id)
{
    if (id >= 0 && id < sgptDataTables->count) return &sgptDataTables->stats[id];
    return 0;
}
static inline AiControl* GetAiControl(Unit* unit)
{
    if (unit && unit->type == 1 && unit->monster) return unit->monster->control;
    return 0;
}
#define PARAM(record,n) ((record)->param[n][game->difficulty])
#define ROLL() ((int)((unsigned int)SEED_RollRandomNumber(seed) % 100))
// 0x005E2FF0
void __fastcall sub_005E2FF0_MonsterThink(Game* game, Unit* unit, Tick* tick)
{
    int distance = tick->distance;
    int combat = tick->combat;
    Unit* target = tick->target;
    Seed* seed = &unit->seed;
    AiControl* control = tick->control;
    MonStats* stats = tick->stats;
    MonStats* records[4] = {GetMonStats(492), GetMonStats(493), GetMonStats(494), GetMonStats(495)};
    if (control->param[0] != -1 && !STATLIST_GetUnitAlignment(unit)) {
        int const tArg1 = control->param[0];
        Unit* other = SUNIT_GetServerUnit(game, 1, tArg1);
        if (!other || SUNIT_IsDead(other) || SUNIT_GetOwner(game, other) || STATLIST_GetUnitAlignment(other)) {
            GetAiControl(unit)->param[0] = -1;
        } else {
            if (sub_005B0BD0_DistanceSquared(unit, other) > PARAM(records[1], 0) * PARAM(records[1], 0)) {
                AITACTICS_WalkToTargetUnitWithFlags(game, unit, other, 0);
                return;
            }
            if (stats->skill[0] >= 0) {
                AITACTICS_UseSkill(game, unit, stats->mode[0], stats->skill[0], other, 0, 0);
                return;
            }
        }
    }
    if (combat) {
        if (stats->skill[0] >= 0 && sub_005DD280_LifePercent(unit) < PARAM(records[0], 0)) {
            AITACTICS_UseSkillInRange(unit, PARAM(records[0], 1), stats->skill[0], stats->mode[0]);
            return;
        }
        if (ROLL() < PARAM(records[2], 1) && D2GAME_AICORE_Escape_6FCD0560(game, unit, target, 5, 1)) return;
    }
    if (stats->skill[0] >= 0 && ROLL() < PARAM(records[0], 2)) {
        AITACTICS_UseSkillInRange(unit, PARAM(records[0], 1), stats->skill[0], stats->mode[0]);
        return;
    }
    if (distance < PARAM(records[2], 0) && ROLL() < PARAM(records[2], 1)) {
        D2GAME_AICORE_Escape_6FCD0560(game, unit, target, 5, 0);
        return;
    }
    if (stats->skill[3] >= 0) {
        Unit* selected = AIUTIL_SelectAiTargetWithCollisionCheck(game, unit, &distance, 0);
        if (selected) {
            if (distance < PARAM(records[2], 2)) {
                if ((int)SEED_RollLimitedRandomNumber(seed, 100) < PARAM(records[2], 3)) {
                    AITACTICS_UseSkill(game, unit, stats->mode[3], stats->skill[3], selected, 0, 0);
                    return;
                }
            } else if (distance < PARAM(records[3], 2)) {
                if ((int)SEED_RollLimitedRandomNumber(seed, 100) < PARAM(records[3], 3)) {
                    AITACTICS_UseSkill(game, unit, stats->mode[3], stats->skill[3], selected, 0, 0);
                    return;
                }
            }
        }
    }
    if (ROLL() < 33) {
        AITACTICS_WalkToTargetUnitWithSteps(game, unit, target, 4);
        return;
    }
    if (ROLL() < 20) {
        AITACTICS_WalkCloseToUnit(game, unit, 8);
        return;
    }
    AITACTICS_IdleInNeutralMode(game, unit, 10);
}
