#include "D2Game.h"

#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2ItemsTxt;
struct D2SeedStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int type;
    int classId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
};

struct D2GameStrc { char pad00[0x1c];void* pool;char pad20[0x88];int frame; };

struct D2ItemsTxt { char pad00[0x98];short state;char pad9a[4];short stats[3];unsigned int calculations[3];unsigned int durationCalculation; };

struct D2ItemStatCostTxt { char pad00[0x18];unsigned char valueShift;char pad19[0x19];unsigned short maximumStat;char pad34[0x110]; };

struct D2DataTablesStrc { char pad00[0xc4];int stateCount;char padc8[0xb04];D2ItemStatCostTxt* statCosts;int unusedbd0,statCount; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc*,D2UnitStrc*,unsigned int); // 0x00627C20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*,int); // 0x006256B0
int __stdcall STATLIST_GetExpireFrame(D2StatListStrc*); // 0x00626090
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int,int,int); // 0x00483360
int __fastcall sub_0044BE50(D2UnitStrc*); // 0x0044BE50
int __fastcall sub_00451F50(D2UnitStrc*); // 0x00451F50
int __fastcall sub_005C6870(D2GameStrc*,D2UnitStrc*,int); // 0x005C6870
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*,int,int,int); // 0x006272B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*,unsigned int,unsigned int,int,int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*,int); // 0x006252D0
void __stdcall STATES_ToggleState(D2UnitStrc*,int,int); // 0x00639DB0
void __fastcall EVENT_SetEvent(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x005417D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*,RemoveCallback); // 0x00625CE0
void __fastcall sub_0056E900(D2UnitStrc*,int,D2StatListStrc*); // 0x0056E900
void __stdcall sub_00626E10(D2UnitStrc*,D2StatListStrc*,int); // 0x00626E10
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc*,int); // 0x006260B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc*,int,unsigned short); // 0x00625D00
void __stdcall STATLIST_SetStat(D2StatListStrc*,int,int,unsigned short); // 0x00627150
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005805D0
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc*,unsigned char); // 0x00571A10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall SKILLS_ApplyDimVisionToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0

// 0x005BE7B0
int __fastcall SKILLITEM_pSpell04_ApplyPotionStats(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,D2UnitStrc* target,int x,int y,int skillId)
{
 D2ItemsTxt* record=DATATBLS_GetItemsTxtRecord(!item ? -1:item->classId);
 if(!record)return 0;
 int duration=ITEMMODS_EvaluateItemFormula(unit,item,record->durationCalculation);
 int state=record->state;
 D2StatListStrc* list=0;
 int remaining=0;
 if(duration>0){
  if(state<=0 || state>=sgptDataTables->stateCount)return 0;
  list=STATLIST_GetStatListFromUnitAndState(unit,state);
  if(list)remaining=STATLIST_GetExpireFrame(list)-game->frame;
 }
 int changed=0,updateLife=0;
 for(int i=0;i<3;++i){
  int stat=record->stats[i];
  if(stat<0 || stat>=sgptDataTables->statCount)break;
  D2ItemStatCostTxt* cost=&sgptDataTables->statCosts[stat];
  if(!cost)continue;
  int value=ITEMMODS_EvaluateItemFormula(unit,item,record->calculations[i]);
  if(stat==26 || stat==74)value<<=8;
  value=value<<cost->valueShift;
  if(value<=0)continue;
  switch(stat){
   case 6:updateLife=1;
   case 74:if(!sub_0044BE50(unit))value=sub_005C6870(game,unit,value);break;
  }
  if(duration<=0){
   const int current=STATLIST_UnitGetStatValue(unit,stat,0);
   if(cost->maximumStat<sgptDataTables->statCount){
    int maximum=STATLIST_UnitGetStatValue(unit,cost->maximumStat,0);
    if(current+value>maximum)value=maximum-current;
   }
   STATLIST_AddUnitStat(unit,stat,value,0);
   changed=1;
  }else{
   int expiry=game->frame+remaining+duration;
   if(!list){
    int const nUnitGUID = sub_00451F50(unit);
    list=STATLIST_AllocStatList(game->pool,2,expiry,sub_0044BE50(unit),nUnitGUID);
    if(!list)continue;
    STATLIST_SetState(list,state);
    STATES_ToggleState(unit,state,1);
    if(sub_0044BE50(unit)){
     sub_00540E60(game,unit,3,0);
     EVENT_SetEvent(game,unit,3,game->frame+1,0,0);
    }
    STATLIST_SetStatRemoveCallback(list,sub_0056E900);
    sub_00626E10(unit,list,1);
   }
   STATLIST_SetExpireFrame(list,expiry);
   int total=STATLIST_GetStatValue(list,stat,0)*remaining+value;
   if(i==0)EVENT_SetEvent(game,unit,12,expiry,0,0);
   if(duration+remaining>0)STATLIST_SetStat(list,stat,total/(duration+remaining),0);
   changed=1;
  }
 }
 if(updateLife && unit && unit->type==0){
  unsigned char previous=(unsigned char)STATLIST_UnitGetStatValue(unit,352,0);
  unsigned char life=MONSTERMODE_GetHpPercent128(unit);
  int difference=(int)previous-(int)life;
  if(difference<0)difference=-difference;
  if(difference>4){
   SUNITMSG_QueueLifeUpdate(unit,life);
   STATLIST_SetUnitStat(unit,352,life,0);
  }
 }
 return changed;
}

// 0x005BFAA0
int __fastcall SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        goto ReturnZero;
    }

    if (!pUnit)
    {
        goto ReturnZero;
    }

    if ((!pUnit ? 6 : pUnit->type) != UNIT_MONSTER)
    {
ReturnZero:
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nChance = 5 * (nAttackerLevel + 4 * nValue - STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) + 6);
    if (nEvent == 6 && nChance > 0)
    {
        nChance /= 3;
    }

    nChance = D2_MIN(D2_MAX(nChance, 1), 99);

    const int nRoll = SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 100);
    if (nRoll >= nChance)
    {
        return 0;
    }

    int nLevel = (nChance - nRoll) / 5 + 1;
    nLevel = D2_MIN(D2_MAX(nLevel, 1), 20);

    SKILLS_ApplyDimVisionToTarget(pGame, pAttacker, pUnit, nLevel);
    return 1;
}
