struct Seed { unsigned int low,high; };
struct Unit { char unknown00[32]; Seed seed; };
struct Game { char unknown00[0x6D]; unsigned char difficulty; };
struct AiControl { char unknown00[0x14]; int param[3]; };
struct MonStats { char unknown00[0x56]; short param[8][3]; char unknown86[0xEA]; short skill[8]; unsigned char mode[8]; };
struct Tick { AiControl* control; int unknown04; Unit* target; int unknown0C[2]; int distance,combat; MonStats* stats; };
unsigned int __fastcall SEED_RollLimitedRandomNumber(Seed*,int); // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(Game*,Unit*,int,int); // 0x00540E60
int __fastcall AITACTICS_ChangeModeAndTargetUnit(Game*,Unit*,int,Unit*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(Game*,Unit*,int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(Unit*,int,int,unsigned char); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(Game*,Unit*,unsigned char); // 0x005DE200
int __fastcall D2GAME_AICORE_Escape_6FCD0560(Game*,Unit*,Unit*,int,int); // 0x005DE6D0
int __fastcall AITACTICS_UseSkill(Game*,Unit*,unsigned char,int,Unit*,int,int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(Game*,Unit*,Unit*,unsigned char); // 0x005DEC80
int __fastcall sub_005DEFE0_Escape(Game*,Unit*,Unit*,unsigned char,int); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(Game*,Unit*,Unit*,unsigned char); // 0x005DF530
int __fastcall sub_005DF7D0(Game*,Unit*,Unit*,int,int); // 0x005DF7D0
Unit* __fastcall sub_005F77C0_SelectSkillTarget(Game*,Unit*,MonStats*,Unit*); // 0x005F77C0
int __stdcall UNITS_GetCurrentLifePercentage(Unit*); // 0x00621F20
int __stdcall UNITS_TestCollisionWithUnit(Unit*,Unit*,int); // 0x00622AA0
// 0x0045C370
static __forceinline unsigned __int64 SEED_RollRandomNumber(Seed* seed) {
    const unsigned __int64 value=seed->high+0x6AC690C5i64*seed->low;
    seed->high=(unsigned int)(value>>32);seed->low=(unsigned int)value;return value;
}
#define ROLL() ((int)((unsigned int)SEED_RollRandomNumber(seed)%100))
#define PARAM(n) (stats->param[n][game->difficulty])
// 0x005F78B0
void __fastcall sub_005F78B0_SkillSelectionAi(Game* game,Unit* unit,Tick* tick)
{
    const int distance=tick->distance;
    const int combat=tick->combat;
    Unit* target=tick->target;
    Seed* seed=&unit->seed;
    AiControl* control=tick->control;
    MonStats* stats=tick->stats;
    int life=UNITS_GetCurrentLifePercentage(unit);
    int injury=(100-life)/5;
    if(injury<0) injury=0;
    int state=control->param[2];
    if(combat) {
        if(ROLL()>PARAM(0)) state=3;
        else {
            state=2;
            control->param[0]=(unsigned int)SEED_RollRandomNumber(seed)%3+3;
        }
    }
    else {
        if(distance>20) state=4;
        else {
        L0:
            if(state==0) {
                if(life<=20 && distance<5 && ROLL()<40) state=1;
                else if(ROLL()<50+injury) {
                    state=2;
                    control->param[0]=(unsigned int)SEED_RollRandomNumber(seed)%3+3;
                }
                else {
                    if(state) goto L0;
                    goto Fallback;
                }
            }
        }
    }
    switch(state) {
    case 0:
        state=4;
        AITACTICS_IdleInNeutralMode(game,unit,5);
        break;
    case 1:
        state=0;
        AITACTICS_SetVelocity(unit,0,50,0);
        if(sub_005DEFE0_Escape(game,unit,target,8,1)) break;
        if(combat) {
            AITACTICS_UseSkill(game,unit,stats->mode[2],stats->skill[2],target,0,0);
            break;
        }

    case 2:
        if(--control->param[0]==0) state=0;
        if(control->param[1]) {
            ++control->param[1];
            target=sub_005F77C0_SelectSkillTarget(game,unit,stats,target);
            int count=0;
            int i=0;
            short* skills=stats->skill;
            short* skill=skills;
            for(;i<8;++i) {
                if(*skill<0) break;
                ++count;
                ++skill;
            }
            if(count>0) {
                int percent=100/count;
                int roll=ROLL();
                int blocked=0;
                if(game->difficulty>0 && target && UNITS_TestCollisionWithUnit(unit,target,4)) blocked=1;
                if(game->difficulty>0 && (blocked || distance>30)) AITACTICS_UseSkill(game,unit,stats->mode[5],stats->skill[5],target,0,0);
                else if(distance<15 && roll<percent && game->difficulty>0) AITACTICS_UseSkill(game,unit,stats->mode[4],stats->skill[4],target,0,0);
                else if(roll<2*percent) AITACTICS_UseSkill(game,unit,stats->mode[3],stats->skill[3],target,0,0);
                else if(roll<3*percent) AITACTICS_UseSkill(game,unit,stats->mode[1],stats->skill[1],target,0,0);
                else AITACTICS_UseSkill(game,unit,stats->mode[0],skills[0],target,0,0);
            }
            else AITACTICS_WalkCloseToUnit(game,unit,6);
            if(ROLL()<50-injury) control->param[1]=0;
        }
        else {
            control->param[1]=2;
            if(!sub_005DF7D0(game,unit,target,3,1)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    case 3:
        state=0;
        if((int)SEED_RollLimitedRandomNumber(seed,100)<80+injury) {
            if((int)SEED_RollLimitedRandomNumber(seed,100)<80-injury) AITACTICS_ChangeModeAndTargetUnit(game,unit,4,target);
            else AITACTICS_UseSkill(game,unit,stats->mode[2],stats->skill[2],target,0,0);
        }
        else {
            AITACTICS_SetVelocity(unit,0,50,0);
            if(!sub_005DF7D0(game,unit,target,3,1)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    case 4:
        state=0;
        AITACTICS_SetVelocity(unit,0,50,0);
        if(!D2GAME_AICORE_WalkToOwner_6FCD0B60(game,unit,target,6)) {
            D2GAME_EVENTS_Delete_6FC34840(game,unit,2,0);
            if(!D2GAME_AICORE_Escape_6FCD0560(game,unit,target,12,6)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    default:
    Fallback:
        state=0;
        if(ROLL()<65) {
            if(ROLL()<65 || distance>5) sub_005DF7D0(game,unit,target,4,0);
            else {
                AITACTICS_SetVelocity(unit,0,0,4);
                AITACTICS_WalkToTargetUnitWithFlags(game,unit,target,7);
            }
        }
        else AITACTICS_IdleInNeutralMode(game,unit,10);
        break;
    }
    control->param[2]=state;
}
