struct Seed { unsigned int low, high; };
struct Unit { char unknown00[32]; Seed seed; };
struct Game { char unknown00[0x6D]; unsigned char difficulty; char unknown6E[0x3A]; int frame; };
struct MonStats { char unknown00[0x3E]; short missile; char unknown40[0x16]; short param[8][3]; char unknown86[0xEA]; short skill[8]; unsigned char mode[8]; };
struct AiControl { char unknown00[0x14]; int param[3]; };
struct Tick { AiControl* control; int unknown04; Unit* target; int unknown0C[2]; int distance; int combat; MonStats* stats; };
struct MissileRecord { char unknown00[0x96]; short range; };

struct TargetSearch { Unit* target; int life; int distance; int unknown0C[7]; };
struct Offset { int x, y; };
typedef Unit* (__fastcall* TargetCallback)(Game*, Unit*, Unit*, void*);
extern Offset offsets_006E337C[]; // 0x006E337C
int __fastcall CLIENTS_GetUnitX(Unit*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(Unit*); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(Seed*, int); // 0x0045C390
MissileRecord* __fastcall DATATBLS_GetMissilesTxtRecord(int); // 0x0046ACE0
int __fastcall sub_00472210_SeedRollMasked(Seed*, int); // 0x00472210
Unit* __fastcall sub_6FCF1E80(Game*, Unit*, void*, TargetCallback, int); // 0x005DD0B0
Unit* __fastcall AITHINK_TargetCallback_HighPriest(Game*, Unit*, Unit*, void*); // 0x005E0430
int __fastcall AITACTICS_ChangeModeAndTargetUnit(Game*, Unit*, int, Unit*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(Game*, Unit*, int); // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(Game*, Unit*, unsigned char); // 0x005DE200
int __fastcall AITACTICS_UseSkill(Game*, Unit*, unsigned char, int, Unit*, int, int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(Game*, Unit*, Unit*, unsigned char); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(Game*, Unit*, Unit*, unsigned char); // 0x005DEF80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(Game*, Unit*, Unit*, unsigned char, int); // 0x005DEFE0
int __fastcall sub_005DF7D0(Game*, Unit*, Unit*, int, int); // 0x005DF7D0
inline unsigned __int64 SEED_RollRandomNumber(Seed* seed)
{
    const unsigned __int64 value = seed->high + 0x6AC690C5i64 * seed->low;
    seed->high = (unsigned int)(value >> 32);
    seed->low = (unsigned int)value;
    return value;
}
#define PARAM(n) (stats->param[n][game->difficulty])
#define ROLL() ((int)((unsigned int)SEED_RollRandomNumber(seed) % 100))
// 0x005E0490
void __fastcall sub_005E0490_HighPriest(Game* game, Unit* unit, Tick* tick)
{
    int distance = tick->distance;
    int combat = tick->combat;
    Unit* target = tick->target;
    MonStats* stats = tick->stats;
    Seed* seed = &unit->seed;
    AiControl* control = tick->control;
    if (!control->param[0]) {
        if (combat) {
            if (ROLL() < PARAM(0)) {
                control->param[0] = 1;
                AITACTICS_ChangeModeAndTargetUnit(game, unit, 4, target);
                return;
            }
            D2GAME_AICORE_Escape_6FCD0560(game, unit, target, 6, 1);
            return;
        }
        if (stats->skill[1] >= 0 && game->frame > control->param[1]
            && (int)SEED_RollLimitedRandomNumber(seed, 100) < PARAM(1)) {
            TargetSearch search;
            search.target = 0;
            search.life = 75;
            search.distance = 2500;
            sub_6FCF1E80(game, unit, &search, AITHINK_TargetCallback_HighPriest, 1);
            if (search.target) {
                control->param[1] = PARAM(2) + game->frame;
                AITACTICS_UseSkill(game, unit, stats->mode[1], stats->skill[1], search.target, 0, 0);
                return;
            }
        }
        if (stats->skill[0] >= 0 && game->frame > control->param[1] && distance < PARAM(7)
            && (int)SEED_RollLimitedRandomNumber(seed, 100) < PARAM(3)) {
            int index = sub_00472210_SeedRollMasked(seed, 4);
            int x = CLIENTS_GetUnitX(target) + offsets_006E337C[index].x;
            int y = CLIENTS_GetUnitY(target) + offsets_006E337C[index].y;
            AITACTICS_UseSkill(game, unit, stats->mode[0], stats->skill[0], target, x, y);
            control->param[1] = game->frame + 100;
            return;
        }
        if (PARAM(4) > 0 && stats->missile > 0) {
            MissileRecord* missile = DATATBLS_GetMissilesTxtRecord(stats->missile);
            if (missile && distance < missile->range - 2 && (int)SEED_RollLimitedRandomNumber(seed, 100) < PARAM(4)) {
                AITACTICS_ChangeModeAndTargetUnit(game, unit, 8, target);
                return;
            }
        }
        if (ROLL() < 80) {
            if (distance > PARAM(7)) {
                AITACTICS_WalkToTargetUnitWithSteps(game, unit, target, 6);
                return;
            }
            sub_005DF7D0(game, unit, target, 3, 0);
            return;
        }
    }
    control->param[0] = 1;
    if (combat) {
        if (ROLL() < PARAM(6)) {
            AITACTICS_ChangeModeAndTargetUnit(game, unit, 8, target);
            return;
        }
        if (ROLL() < PARAM(5)) {
            D2GAME_AICORE_Escape_6FCD0560(game, unit, target, 6, 1);
            control->param[0] = 0;
            return;
        }
        if ((int)SEED_RollLimitedRandomNumber(seed, 100) < 90) {
            AITACTICS_ChangeModeAndTargetUnit(game, unit, 4, target);
            return;
        }
        AITACTICS_IdleInNeutralMode(game, unit, 10);
        return;
    }
    if (distance < 6 && ROLL() < PARAM(6)) {
        AITACTICS_ChangeModeAndTargetUnit(game, unit, 8, target);
        return;
    }
    if (ROLL() < PARAM(5)) {
        control->param[0] = 0;
        AITACTICS_IdleInNeutralMode(game, unit, 10);
        return;
    }
    if (ROLL() < 70) {
        AITACTICS_WalkToTargetUnitWithFlags(game, unit, target, 7);
        return;
    }
    AITACTICS_WalkCloseToUnit(game, unit, 12);
}

#include "gen/data/Source/D2Game/Unknown_005E0490.inc"
