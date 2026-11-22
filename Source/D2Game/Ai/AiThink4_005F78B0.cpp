#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*,int); // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*,D2UnitStrc*,int,int); // 0x00540E60
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*,int,int,unsigned char); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*,D2UnitStrc*,unsigned char); // 0x005DE200
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x005DE6D0
int __fastcall AITACTICS_UseSkill(D2GameStrc*,D2UnitStrc*,unsigned char,int,D2UnitStrc*,int,int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DEC80
int __fastcall sub_005DEFE0_Escape(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char,int); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DF530
int __fastcall sub_005DF7D0(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_FindTargetForMephisto(D2GameStrc*,D2UnitStrc*,D2MonStatsTxt*,D2UnitStrc*); // 0x005F77C0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc*,D2UnitStrc*,int); // 0x00622AA0
inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nValue = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    return nValue;
}
#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))
#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
// 0x005F78B0
void __fastcall sub_005F78B0_SkillSelectionAi(D2GameStrc* game,D2UnitStrc* unit,D2AiTickParamStrc* tick)
{
    const int distance=tick->nTargetDistance;
    const int combat=tick->bCombat;
    D2UnitStrc* target=tick->pTarget;
    D2SeedStrc* seed=&unit->pSeed;
    D2AiControlStrc* control=tick->pAiControl;
    D2MonStatsTxt* stats=tick->pMonstatsTxt;
    int life=UNITS_GetCurrentLifePercentage(unit);
    int injury=(100-life)/5;
    if(injury<0) injury=0;
    int state=control->dwAiParam[2];
    if(combat) {
        if(AI_ROLL_PERCENT(seed)>AI_PARAM(game, stats, 0)) state=3;
        else {
            state=2;
            control->dwAiParam[0]=(unsigned int)SEED_RollRandomNumber(seed)%3+3;
        }
    }
    else {
        if(distance>20) state=4;
        else {
        L0:
            if(state==0) {
                if(life<=20 && distance<5 && AI_ROLL_PERCENT(seed)<40) state=1;
                else if(AI_ROLL_PERCENT(seed)<50+injury) {
                    state=2;
                    control->dwAiParam[0]=(unsigned int)SEED_RollRandomNumber(seed)%3+3;
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
            AITACTICS_UseSkill(game,unit,stats->nSkillMode[2],stats->nSkill[2],target,0,0);
            break;
        }

    case 2:
        if(--control->dwAiParam[0]==0) state=0;
        if(control->dwAiParam[1]) {
            ++control->dwAiParam[1];
            target=AITHINK_FindTargetForMephisto(game,unit,stats,target);
            int count=0;
            int i=0;
            short* skills=stats->nSkill;
            short* skill=skills;
            for(;i<8;++i) {
                if(*skill<0) break;
                ++count;
                ++skill;
            }
            if(count>0) {
                int percent=100/count;
                int roll=AI_ROLL_PERCENT(seed);
                int blocked=0;
                if(game->nDifficulty>0 && target && UNITS_TestCollisionWithUnit(unit,target,4)) blocked=1;
                if(game->nDifficulty>0 && (blocked || distance>30)) AITACTICS_UseSkill(game,unit,stats->nSkillMode[5],stats->nSkill[5],target,0,0);
                else if(distance<15 && roll<percent && game->nDifficulty>0) AITACTICS_UseSkill(game,unit,stats->nSkillMode[4],stats->nSkill[4],target,0,0);
                else if(roll<2*percent) AITACTICS_UseSkill(game,unit,stats->nSkillMode[3],stats->nSkill[3],target,0,0);
                else if(roll<3*percent) AITACTICS_UseSkill(game,unit,stats->nSkillMode[1],stats->nSkill[1],target,0,0);
                else AITACTICS_UseSkill(game,unit,stats->nSkillMode[0],skills[0],target,0,0);
            }
            else AITACTICS_WalkCloseToUnit(game,unit,6);
            if(AI_ROLL_PERCENT(seed)<50-injury) control->dwAiParam[1]=0;
        }
        else {
            control->dwAiParam[1]=2;
            if(!sub_005DF7D0(game,unit,target,3,1)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    case 3:
        state=0;
        if((int)SEED_RollLimitedRandomNumber(seed,100)<80+injury) {
            if((int)SEED_RollLimitedRandomNumber(seed,100)<80-injury) AITACTICS_ChangeModeAndTargetUnit(game,unit,4,target);
            else AITACTICS_UseSkill(game,unit,stats->nSkillMode[2],stats->nSkill[2],target,0,0);
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
        if(AI_ROLL_PERCENT(seed)<65) {
            if(AI_ROLL_PERCENT(seed)<65 || distance>5) sub_005DF7D0(game,unit,target,4,0);
            else {
                AITACTICS_SetVelocity(unit,0,0,4);
                AITACTICS_WalkToTargetUnitWithFlags(game,unit,target,7);
            }
        }
        else AITACTICS_IdleInNeutralMode(game,unit,10);
        break;
    }
    control->dwAiParam[2]=state;
}
