struct Game;
struct Damage;
struct Unit
{
    int type;
};
struct Difficulty;
struct Context
{
    Game* game;
    Difficulty* difficulty;
    Unit* attacker;
    Unit* defender;
    int attackerFlag;
    int defenderFlag;
    Damage* damage;
    int zeroReduction;
    int flatReduction1;
    int flatReduction2;
};
struct Record
{
    int damageOffset;
    int resistanceStat;
    int maximumStat;
    int pierceStat;
    int absorbPercentStat;
    int absorbFlatStat;
    int reductionIndex;
    int requiresAttackerFlag;
    int scales;
    const char* name;
    unsigned char flags;
    unsigned char tail[3];
};
extern Record gVar_00732980_Records[12]; // 0x00732980
extern int __fastcall sub_00451F30_HasFlags(Unit*,unsigned int); // 0x00451F30
extern int __fastcall sub_00483360_Ratio(int,int,int); // 0x00483360
extern void __fastcall sub_005347D0_Report(Game*,Unit*,Unit*,int,int,int,int,const char*,unsigned char); // 0x005347D0
extern void __fastcall sub_005347E0_ReportAbsorb(Game*,Unit*,Unit*,int,const char*); // 0x005347E0
extern int __fastcall sub_005C0C30_Event(Game*,int,Unit*,Unit*,Damage*); // 0x005C0C30
extern Difficulty* __stdcall sub_00611D30_Difficulty(int); // 0x00611D30
extern int __stdcall sub_00625480_Stat(Unit*,int,int); // 0x00625480
extern int __stdcall sub_00625500_BaseStat(Unit*,int,int); // 0x00625500
extern int __stdcall sub_00639DF0_State(Unit*,int); // 0x00639DF0
extern int __stdcall sub_0063E940_ClassA(Unit*); // 0x0063E940
extern int __stdcall sub_0063E990_ClassB(Unit*); // 0x0063E990
extern int __stdcall sub_0063E9F0_ClassC(Game*,Unit*); // 0x0063E9F0
extern int __stdcall sub_0063EDC0_ClassD(Unit*); // 0x0063EDC0
extern int __stdcall sub_0063EE90_ClassE(Unit*); // 0x0063EE90

#define FIELD(p,offset) (*(int*)((char*)(p)+(offset)))
#define BYTEFIELD(p,offset) (*(unsigned char*)((char*)(p)+(offset)))

// 0x0057BE00
static __declspec(noinline) int __cdecl sub_0057BE00_Resistance(Context* c,Record* r)
{
    int resistance=0;
    if(r->resistanceStat!=-1)
        resistance=sub_00625480_Stat(c->defender,r->resistanceStat,0);
    if(r->pierceStat!=-1 && (resistance<100 || !c->defenderFlag))
    {
        int pierce=sub_00625480_Stat(c->attacker,r->pierceStat,0);
        if(pierce) resistance-=pierce;
    }
    if(!c->defenderFlag && r->resistanceStat!=36 && r->resistanceStat!=37)
    {
        if(FIELD(c->game,112)) resistance+=FIELD(c->difficulty,0);
        else
        {
            switch(BYTEFIELD(c->game,109))
            {
            case 1: resistance-=20; break;
            case 2: resistance-=50; break;
            }
        }
    }
    if(resistance<=0)
    {
        if(resistance<=-100)
        {
            resistance=-100;
        }
        return resistance;
    }
    else
    {
        if(!c->defenderFlag)
        {
            int maximum=75;
            const int nMaximumStat=r->maximumStat;
            if(nMaximumStat!=-1)
                maximum=sub_00625480_Stat(c->defender,nMaximumStat,0)+75;
            else if(r->resistanceStat==36) maximum=50;
            if(maximum>=95) maximum=95;
            resistance=(resistance>-100 ? resistance : -100)<maximum ? (resistance>-100 ? resistance : -100) : maximum;
        }
        if(r->resistanceStat==36 && sub_00639DF0_State(c->attacker,47) && sub_0063E990_ClassB(c->defender))
        {
            resistance=0;
        }
        return resistance;
    }
}

static __declspec(noinline) int __cdecl sub_0057BF10_Absorb(Record* r,Context* c,int amount)
{
    if(r->absorbPercentStat!=-1)
    {
        int percent=sub_00625480_Stat(c->defender,r->absorbPercentStat,0);
        if(percent>=40) percent=40;
        if(percent>0)
        {
            int absorbed=sub_00483360_Ratio(amount,percent,100);
            FIELD(c->damage,72)+=absorbed;
            amount-=absorbed;
        }
        int absorbed=sub_00625480_Stat(c->defender,r->absorbFlatStat,0)<<8;
        if(absorbed>0)
        {
            if(absorbed>=amount) absorbed=amount;
            FIELD(c->damage,72)+=absorbed;
            amount-=absorbed;
        }
    }
    return amount;
}

// 0x0057BF80
static __declspec(noinline) int __stdcall sub_0057BF80_Apply(int ignore,Context* c,Record* r)
{
    int* field=&FIELD(c->damage,r->damageOffset);
    int amount=*field;
    int originalAmount=amount;
    if(amount<=0) { *field=0; return 0; }
    int resistance=sub_0057BE00_Resistance(c,r);
    if(ignore)
    {
        if(resistance>0) resistance=0;
    }
    else amount-=FIELD(c,28+4*r->reductionIndex);
    if(amount>0 && resistance)
    {
        if(resistance>=100) resistance=100;
        amount=sub_00483360_Ratio(amount,100-resistance,100);
    }
    sub_005347D0_Report(c->game,c->attacker,c->defender,originalAmount,resistance,FIELD(c,28+4*r->reductionIndex),amount,r->name,r->flags);
    originalAmount=amount;
    if(!ignore)
    {
        amount=sub_0057BF10_Absorb(r,c,amount);
        sub_005347E0_ReportAbsorb(c->game,c->attacker,c->defender,originalAmount-amount,r->name);
    }
    *field=amount;
    return amount;
}

// 0x0057C060
static __declspec(noinline) int __cdecl sub_0057C060_Scale(Context* c)
{
    if(c->attacker && c->defender && c->attacker!=c->defender)
    {
        if(c->defender->type==0)
        {
            if(c->attacker->type==0 || sub_0063EE90_ClassE(c->attacker)) return 17;
            Unit* attacker=c->attacker;
            if(sub_00451F30_HasFlags(attacker,0x80000000u) || sub_0063EE90_ClassE(attacker)) return 17;
        }
        else
        {
            if(sub_0063EE90_ClassE(c->defender) && sub_0063EE90_ClassE(c->attacker)) return 25;
            if(sub_0063EE90_ClassE(c->attacker) && sub_0063E9F0_ClassC(0,c->defender))
            {
                Difficulty* difficulty=c->difficulty;
                if(difficulty) return FIELD(difficulty,56);
                return 100;
            }
            if(sub_0063EDC0_ClassD(c->attacker))
            {
                Unit* defender=c->defender;
                if(sub_00451F30_HasFlags(defender,0x80000000u)) return sub_0063EE90_ClassE(defender) ? 200 : 400;
            }
        }
    }
    return 100;
}

// 0x0057C140
static __declspec(noinline) void __cdecl sub_0057C140_Durations(Context* c)
{
    if(FIELD(c->damage,48)>0 || FIELD(c->damage,52)>0)
    {
        if(sub_00625500_BaseStat(c->defender,153,0))
        {
            FIELD(c->damage,48)=0;
            FIELD(c->damage,52)=0;
        }
        else if(sub_00625500_BaseStat(c->defender,118,0))
        {
            FIELD(c->damage,48)/=2;
            FIELD(c->damage,52)/=2;
        }
    }
    if(FIELD(c->damage,44)>0 && sub_00639DF0_State(c->defender,133)) FIELD(c->damage,44)=0;
    if(FIELD(c->damage,24)>0 && sub_00639DF0_State(c->defender,131)) FIELD(c->damage,24)=0;
}

// 0x0057C1E0
void __fastcall sub_0057C1E0_Total(Game* game,Unit* attacker,Unit* defender,Damage* damage)
{
    Context c;
    c.game=game;
    c.difficulty=sub_00611D30_Difficulty(BYTEFIELD(game,109));
    c.attacker=attacker;
    c.defender=defender;
    c.damage=damage;
    c.attackerFlag=attacker && attacker->type==1 && !sub_0063EE90_ClassE(attacker);
    c.defenderFlag=defender && defender->type==1 && !sub_0063EE90_ClassE(defender);
    c.zeroReduction=0;
    int reduction=sub_00625480_Stat(defender,34,0)<<8;
    if(reduction>0 && FIELD(damage,84)>0) reduction=sub_00483360_Ratio(reduction,FIELD(damage,84),1024);
    c.flatReduction1=reduction;
    reduction=sub_00625480_Stat(defender,35,0)<<8;
    if(reduction>0 && FIELD(damage,84)>0) reduction=sub_00483360_Ratio(reduction,FIELD(damage,84),1024);
    c.flatReduction2=reduction;
    int scale=sub_0057C060_Scale(&c);
    if(scale!=100)
    {
        Record* r=gVar_00732980_Records;
        int remaining=12;
        do
        {
            if(r->scales)
            {
                int* field=&FIELD(damage,r->damageOffset);
                if(*field>0) *field=sub_00483360_Ratio(*field,scale,100);
            }
            ++r;
        } while(--remaining);
    }
    sub_005C0C30_Event(game,11,defender,attacker,damage);
    sub_0057C140_Durations(&c);
    int ignore=0;
    if(defender && defender->type==1)
    {
        int classB=sub_0063E990_ClassB(defender);
        int classA=sub_0063E940_ClassA(defender);
        if(classB && (FIELD(damage,0)&256)) ignore=1;
        if(classA && (FIELD(damage,0)&512)) ignore=1;
        if(!classB && !classA && (FIELD(damage,0)&1024)) ignore=1;
    }
    else if(FIELD(damage,0)&1024) ignore=1;
    Record* r=gVar_00732980_Records;
    for(int i=0;i<12;++i,++r)
    {
        if(r->requiresAttackerFlag && !c.attackerFlag) break;
        sub_0057BF80_Apply(ignore,&c,r);
    }
    FIELD(damage,76)=FIELD(damage,8)+(FIELD(damage,40)+FIELD(damage,36)+FIELD(damage,32)+FIELD(damage,28)+FIELD(damage,16));
    if(c.attackerFlag) FIELD(damage,76)+=FIELD(damage,56);
}
