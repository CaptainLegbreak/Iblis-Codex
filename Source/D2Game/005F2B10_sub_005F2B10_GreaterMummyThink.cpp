struct D2SeedStrc { union { struct { unsigned int nLowSeed,nHighSeed; }; unsigned __int64 lSeed; }; };
struct D2UnitStrc { int dwUnitType,dwClassId; char unk08[0x18]; D2SeedStrc pSeed; };
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; };
struct D2MonStatsTxt { char unk00[0x56]; short wAiParam[8][3]; char unk86[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiTickParamStrc { void* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance,bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2DataTables { char unk00[0xA80]; int nMonStatsTxtRecordCount; };
struct D2GreaterMummyAiCallbackArgStrc { D2UnitStrc* pReviveTarget; D2UnitStrc* pHealTarget; int nHealReviveCounter,nCounter,nMaxDistance,bRadament,bNormal; int unk_1C[3]; };
extern D2DataTables* sgptDataTables; // 0x00744304
void __fastcall sub_00599420_RadamentUpdate(D2GameStrc*,D2UnitStrc*); // 0x00599420
D2UnitStrc* __fastcall sub_005DD0B0_IterateUnits(D2GameStrc*,D2UnitStrc*,void*,D2UnitStrc* (__fastcall *)(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*),int); // 0x005DD0B0
D2UnitStrc* __fastcall sub_005DDC30_GetTarget(D2GameStrc*,D2UnitStrc*,int*,int*); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*); // 0x005DDF90
int __fastcall sub_005DE000_UseSkill(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005DE000
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*,int,int,unsigned char); // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc*,D2UnitStrc*,unsigned char,int,D2UnitStrc*,int,int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DEF80
int __fastcall sub_005DF7D0_Maneuver(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_GreaterMummy(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*); // 0x005F2A00
int __fastcall sub_005FD470_CanUseSkill(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005FD470
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*,D2UnitStrc*); // 0x00620C10
static __forceinline unsigned __int64 RollSeed(D2UnitStrc* pUnit)
{
 const unsigned __int64 lSeed=pUnit->pSeed.nHighSeed+0x6AC690C5i64*pUnit->pSeed.nLowSeed;
 pUnit->pSeed.lSeed=lSeed;return lSeed;
}
static __forceinline int MonsterId(int nId) { if (nId<0 || nId>=sgptDataTables->nMonStatsTxtRecordCount) return -1; return nId; }
static __forceinline int UnitClassId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwClassId; }
#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])
// 0x005F2B10
void __fastcall sub_005F2B10_GreaterMummyThink(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
 int nDistance=pAiTickParam->nTargetDistance;
 D2UnitStrc* pTarget=pAiTickParam->pTarget;
 D2MonStatsTxt* pMonStatsTxt=pAiTickParam->pMonstatsTxt;
 if(pAiTickParam->bCombat && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(0))
 {
  AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,4,pTarget); return;
 }
 if(nDistance<5 && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(0))
 {
  AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,5,pTarget); return;
 }
 D2GreaterMummyAiCallbackArgStrc args;
 args.pReviveTarget=0;args.pHealTarget=0;args.nHealReviveCounter=0;args.nCounter=0;
 int nRange=AI_PARAM(4);args.nMaxDistance=nRange*nRange;args.bRadament=0;args.bNormal=0;
 if(UnitClassId(pUnit)==MonsterId(229))
 {
  sub_00599420_RadamentUpdate(pGame,pUnit);
  args.nMaxDistance=(AI_PARAM(4)+10)*(AI_PARAM(4)+10);args.bRadament=1;
  if(!pGame->nDifficulty) args.bNormal=1;
 }
 sub_005DD0B0_IterateUnits(pGame,pUnit,&args,AITHINK_TargetCallback_GreaterMummy,1);
 D2UnitStrc* pActionTarget=args.pHealTarget;
 if(pMonStatsTxt->nSkill[1]>=0 && pActionTarget && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(2))
 {
  UNITS_SetTargetUnitForDynamicUnit(pUnit,args.pHealTarget);
  AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[1],pMonStatsTxt->nSkill[1],pActionTarget,0,0); return;
 }
 pActionTarget=args.pReviveTarget;
 if(pActionTarget && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(1) && sub_005FD470_CanUseSkill(pGame,pUnit,pMonStatsTxt->nSkill[0],args.pReviveTarget,0,0))
 {
  UNITS_SetTargetUnitForDynamicUnit(pUnit,pActionTarget);
  sub_005DE000_UseSkill(pGame,pUnit,pMonStatsTxt->nSkill[0],pActionTarget,0,0); return;
 }
 if(pMonStatsTxt->nSkill[2]>=0 && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(3))
 {
  pActionTarget=sub_005DDC30_GetTarget(pGame,pUnit,&nDistance,0);
  if(pActionTarget)
  {
   AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[2],pMonStatsTxt->nSkill[2],pActionTarget,0,0); return;
  }
 }
 if(args.nCounter<=0)
 {
  AITACTICS_SetVelocity(pUnit,0,50,0);
  AITACTICS_WalkToTargetUnitWithSteps(pGame,pUnit,pTarget,3); return;
 }
 if((int)((unsigned int)RollSeed(pUnit)%100)<50)
  sub_005DF7D0_Maneuver(pGame,pUnit,pTarget,3,0);
 else
  AITACTICS_IdleInNeutralMode(pGame,pUnit,6);
}
