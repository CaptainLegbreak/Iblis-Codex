struct D2SeedStrc { unsigned int nLowSeed,nHighSeed; };
struct Unit { char seedPad[0x20]; D2SeedStrc seed; };
struct Control { char controlPad[0x18]; int params[2]; };
struct MonStats { char statsPad[0x170]; short skills[8]; };
struct Tick { Control* control; char pad4[0x18]; MonStats* stats; };
struct Skill;
extern const int skill_choices[2][2];  // 0x006E34E0
Skill* __fastcall sub_006439B0(Unit*,int,int);  // 0x006439B0
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}
// 0x005E2CD0
void __fastcall sub_005E2CD0(void* game,Unit* unit,Tick* tick)
{
    int choice=SEED_RollRandomNumber(&unit->seed)&1;
    for (int i=0;i<2;++i) {
        choice=(choice+1)%2;
        if (sub_006439B0(unit,tick->stats->skills[skill_choices[choice][0]],-1)) {
            tick->control->params[0]=skill_choices[choice][0];
            tick->control->params[1]=skill_choices[choice][1];
            return;
        }
    }
    tick->control->params[0]=0;
    tick->control->params[1]=0;
}

#include "gen/data/Source/D2Game/005E2CD0_sub_005E2CD0.inc"
