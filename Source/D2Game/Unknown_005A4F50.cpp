struct Seed { unsigned int low, high; };
struct MonStats { char unknown00[0x4C]; unsigned char alignment; char unknown4D[0xB1]; unsigned char elementMode[3]; unsigned char elementType[3]; unsigned char elementChance[3][3]; };
struct MonsterData { MonStats* stats; };
struct Unit { int type; int classId; char unknown08[0xC]; MonsterData* monster; char unknown18[8]; Seed seed; };
struct Game { char unknown00[0x6A]; unsigned char type; char unknown6B[2]; unsigned char difficulty; char unknown6E[2]; int expansion; int gameType; };
struct StatList;
struct SkillInfo { int minDamage, maxDamage, toHit; };
struct MonsterStatsInit { int minHP, maxHP, armor, toHit, experience, attack1Min, attack1Max, attack2Min, attack2Max, skill1Min, skill1Max, elementMin, elementMax, elementDuration; };
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
int __fastcall sub_00451F60_GetClassId(Unit*); // 0x00451F60
unsigned int __fastcall SEED_RollLimitedRandomNumber(Seed*, int); // 0x0045C390
Game* __fastcall SUNIT_GetGameFromUnit(Unit*); // 0x00554010
void __fastcall sub_6FD14D20(Unit*, int, SkillInfo*); // 0x0056E050
int __fastcall sub_005A4F20_GetDifficultyScaledBonus(Game*, int); // 0x005A4F20
int __stdcall STATLIST_UnitGetStatValue(Unit*, int, unsigned short); // 0x00625480
StatList* __stdcall STATLIST_GetStatListFromUnitAndFlag(Unit*, int); // 0x00625760
int __stdcall STATLIST_GetUnitAlignment(Unit*); // 0x006259B0
void __stdcall STATLIST_SetStatIfListIsValid(StatList*, int, int, unsigned short); // 0x00627150
void __stdcall sub_00627340_ClearStatList(StatList*); // 0x00627340
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int, int, int, int, int, MonsterStatsInit*); // 0x006538A0
// build: context GetType
static __forceinline int GetType(Unit* unit)
{
    return !unit ? 6 : unit->type;
}
// build: context GetMonStats
static __forceinline MonStats* GetMonStats(Unit* unit)
{
    if (unit && GetType(unit) == 1 && unit->monster) return unit->monster->stats;
    return 0;
}
// 0x005A4F50
void __fastcall MONSTERMODE_UpdateModeAttackStats(Unit* unit, int mode)
{
    MonStats* record = GetMonStats(unit);
    if (!record) return;
    SkillInfo skill = {};
    sub_6FD14D20(unit, mode, &skill);
    StatList* list = STATLIST_GetStatListFromUnitAndFlag(unit, 1);
    if (!list) return;
    sub_00627340_ClearStatList(list);
    Game* game = SUNIT_GetGameFromUnit(unit);
    int difficulty = game->difficulty;
    int gameType = game->type != 0 || game->gameType != 0;
    int bonus = 0;
    if (!STATLIST_GetUnitAlignment(unit)) {
        int players = STATLIST_UnitGetStatValue(unit, 100, 0);
        if (players < 1) players = 1;
        bonus = sub_005A4F20_GetDifficultyScaledBonus(game, players);
    }
    int minDamage, maxDamage, toHit;
    switch (mode) {
    default:
    {
        MonsterStatsInit init;
        memset(&init, 0, sizeof(init));
        const int classId = unit->classId;
        DATATBLS_CalculateMonsterStatsByLevel(classId, gameType, difficulty, STATLIST_UnitGetStatValue(unit, 12, 0), 8, &init);
        minDamage = init.attack1Min + skill.minDamage;
        maxDamage = init.attack1Max + skill.maxDamage;
        toHit = init.toHit + skill.toHit;
        break;
    }
    case 7:
    case 8:
    {
        MonsterStatsInit init;
        memset(&init, 0, sizeof(init));
        const int classId = unit->classId;
        DATATBLS_CalculateMonsterStatsByLevel(classId, gameType, difficulty, STATLIST_UnitGetStatValue(unit, 12, 0), 32, &init);
        minDamage = skill.minDamage + init.skill1Min;
        maxDamage = skill.maxDamage + init.skill1Max;
        toHit = skill.toHit + init.toHit;
        break;
    }
    case 5:
    {
        MonsterStatsInit init;
        memset(&init, 0, sizeof(init));
        const int classId = unit->classId;
        DATATBLS_CalculateMonsterStatsByLevel(classId, gameType, difficulty, STATLIST_UnitGetStatValue(unit, 12, 0), 16, &init);
        minDamage = init.attack2Min + skill.minDamage;
        maxDamage = init.attack2Max + skill.maxDamage;
        toHit = init.toHit + skill.toHit;
        break;
    }
    }
    if (!game->expansion && game->difficulty && record->alignment != 1) {
        minDamage = 10 * minDamage / 12;
        maxDamage = 10 * maxDamage / 12;
        toHit = 10 * toHit / 15;
    }
    if (game->expansion && bonus) {
        minDamage += minDamage * bonus / 128;
        maxDamage += maxDamage * bonus / 128;
        toHit += toHit * bonus / 128;
    }
    STATLIST_SetStatIfListIsValid(list, 21, minDamage, 0);
    STATLIST_SetStatIfListIsValid(list, 22, maxDamage, 0);
    STATLIST_SetStatIfListIsValid(list, 19, toHit, 0);
    for (int i = 0; i < 3; ++i) {
        if (record->elementMode[i] > 0 && mode == record->elementMode[i]) {
            if (record->elementChance[i][difficulty] > 0 && (record->elementChance[i][difficulty] >= 100 || (int)SEED_RollLimitedRandomNumber(&unit->seed, 100) < record->elementChance[i][difficulty])) {
            MonsterStatsInit init;
            memset(&init, 0, sizeof(init));
            DATATBLS_CalculateMonsterStatsByLevel(sub_00451F60_GetClassId(unit), gameType, difficulty, STATLIST_UnitGetStatValue(unit, 12, 0), 64 + i, &init);
            int minElement = init.elementMin;
            int maxElement = init.elementMax;
            int duration = init.elementDuration;
            if (game->expansion && bonus) {
                minElement += minElement * bonus / 128;
                maxElement += maxElement * bonus / 128;
                duration += duration * bonus / 128;
            }
            unsigned char element = record->elementType[i];
            if (element == 10) {
                element = SEED_RollLimitedRandomNumber(&unit->seed, 5) + 1;
                if (!duration) duration = 25;
            }
            switch (element) {
            case 1:
                STATLIST_SetStatIfListIsValid(list, 48, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 49, maxElement, 0);
                break;
            case 2:
                STATLIST_SetStatIfListIsValid(list, 50, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 51, maxElement, 0);
                break;
            case 3:
                STATLIST_SetStatIfListIsValid(list, 52, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 53, maxElement, 0);
                break;
            case 4:
                STATLIST_SetStatIfListIsValid(list, 54, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 55, maxElement, 0);
                STATLIST_SetStatIfListIsValid(list, 56, duration, 0);
                break;
            case 5:
                STATLIST_SetStatIfListIsValid(list, 57, 10 * minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 58, 10 * maxElement, 0);
                STATLIST_SetStatIfListIsValid(list, 59, 2 * duration, 0);
                break;
            case 6:
                STATLIST_SetStatIfListIsValid(list, 60, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 61, maxElement, 0);
                break;
            case 7:
                STATLIST_SetStatIfListIsValid(list, 62, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 63, maxElement, 0);
                break;
            case 8:
                STATLIST_SetStatIfListIsValid(list, 64, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 65, maxElement, 0);
                break;
            case 9:
                STATLIST_SetStatIfListIsValid(list, 66, duration, 0);
                break;
            case 11:
                STATLIST_SetStatIfListIsValid(list, 316, minElement, 0);
                STATLIST_SetStatIfListIsValid(list, 317, maxElement, 0);
                STATLIST_SetStatIfListIsValid(list, 315, duration, 0);
                break;
            }
        }
        }
    }
}
