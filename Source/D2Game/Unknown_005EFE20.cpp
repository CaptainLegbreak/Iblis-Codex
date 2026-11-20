#include "D2Game.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2GameTypes.h"

#define MONMODE_ATTACK1 4
#define MONMODE_ATTACK2 5
#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2SandRaiderAiCallbackArgStrc;
struct D2DataTables;
struct D2GreaterMummyAiCallbackArgStrc;



struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};




int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x005DED20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

struct D2SandRaiderAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*,int); // 0x0045C390
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc*,D2UnitStrc*,void*,D2UnitStrc* (__fastcall *)(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*),int); // 0x005DD0B0
int __fastcall sub_005DD280(D2UnitStrc*); // 0x005DD280
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc*,D2UnitStrc*,unsigned char,int,D2UnitStrc*,int,int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DEC80
int __fastcall sub_005DF7D0_Maneuver(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SandRaider(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*); // 0x005F06B0
void __stdcall UNITS_SetOverlay(D2UnitStrc*,int,int); // 0x00621E40
void __stdcall STATES_ToggleState(D2UnitStrc*,int,int); // 0x00639DB0

struct D2DataTables { char unk00[0xA80]; int nMonStatsTxtRecordCount; };

struct D2GreaterMummyAiCallbackArgStrc { D2UnitStrc* pReviveTarget; D2UnitStrc* pHealTarget; int nHealReviveCounter,nCounter,nMaxDistance,bRadament,bNormal; int unk_1C[3]; };

extern D2DataTables* sgptDataTables; // 0x00744304
void __fastcall ACT2Q1_OnRadamentActivated(D2GameStrc*,D2UnitStrc*); // 0x00599420
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc*,D2UnitStrc*,int*,int*); // 0x005DDC30
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005DE000
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DEF80
D2UnitStrc* __fastcall AITHINK_TargetCallback_GreaterMummy(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*); // 0x005F2A00
int __fastcall sub_005FD470(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005FD470
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*,D2UnitStrc*); // 0x00620C10

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static int AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005EFE20
void __fastcall sub_005EFE20_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;

    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 3))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        }
        return;
    }

    int nParam1 = AI_GetParam(pGame, pMonStatsTxt, 1);
    int nParam0 = AI_GetParam(pGame, pMonStatsTxt, 0);
    if (sub_6FCF2E70(pUnit))
        goto lApproach;
    if (nDistance < nParam1 && AI_RollPercentage(pUnit) < nParam0)
        goto lApproach;

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_BURIALGROUNDS)
    {
lApproach:
        sub_005DE190_SetAiParam(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
}

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F0700
void __fastcall sub_005F0700_SandRaiderThink(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        STATES_ToggleState(pUnit,90,0);
        STATES_ToggleState(pUnit,91,0);
        pAiControl->dwAiParam[1] = 0;
    }
    ++pAiControl->dwAiParam[0];
    int nDelay = AI_PARAM(4);
    if (pAiControl->dwAiParam[0] == nDelay)
    {
        switch(AI_PARAM(5))
        {
        default: UNITS_SetOverlay(pUnit,46,0); break;
        case 1: UNITS_SetOverlay(pUnit,150,0); break;
        }
        AITACTICS_IdleInNeutralMode(pGame,pUnit,pMonStatsTxt->nAIdel[pGame->nDifficulty]+1);
        return;
    }
    if (pAiControl->dwAiParam[0] > nDelay)
    {
        switch(AI_PARAM(5))
        {
        default: STATES_ToggleState(pUnit,91,1); break;
        case 1: STATES_ToggleState(pUnit,90,1); break;
        }
        pAiControl->dwAiParam[1] = 1;
    }
    if (pAiControl->dwAiParam[2] < 7 && sub_005DD280(pUnit) < AI_PARAM(0))
    {
        D2SandRaiderAiCallbackArgStrc args;
        args.pTarget = 0;
        args.nDistance = 0x7FFFFFFF;
        AIUTIL_FindTargetWithCallback(pGame,pUnit,&args,AITHINK_TargetCallback_SandRaider,1);
        if(args.pTarget)
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,args.pTarget,0);
            return;
        }
        ++pAiControl->dwAiParam[2];
    }
    if (nDistance > 4 && !pAiControl->dwAiParam[1] && (int)(AI_RollSeed(pSeed)%100) < AI_PARAM(1))
    {
        sub_005DF7D0_Maneuver(pGame,pUnit,pTarget,0,0);
        return;
    }
    if(bCombat)
    {
        if(pAiControl->dwAiParam[1]==1 && pMonStatsTxt->nSkill[0]>=0)
        {
            AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[0],pMonStatsTxt->nSkill[0],pTarget,0,0);
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
            return;
        }
        if((int)(AI_RollSeed(pSeed)%100) < AI_PARAM(2))
        {
            if((int)SEED_RollLimitedRandomNumber(pSeed,100) < AI_PARAM(6))
                AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,5,pTarget);
            else
                AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,4,pTarget);
            return;
        }
    }
    else if(pAiControl->dwAiParam[1] || (int)(AI_RollSeed(pSeed)%100) < AI_PARAM(3))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,pTarget,0);
        return;
    }
    nDelay = AI_PARAM(4);
    nDistance = 24-nDelay;
    if(nDistance<6) nDistance=6;
    if(pAiControl->dwAiParam[0]>nDelay+nDistance)
    {
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
    }
    AITACTICS_IdleInNeutralMode(pGame,pUnit,15);
}

static __forceinline unsigned __int64 RollSeed(D2UnitStrc* pUnit)
{
 const unsigned __int64 lSeed=pUnit->pSeed.nHighSeed+0x6AC690C5i64*pUnit->pSeed.nLowSeed;
 pUnit->pSeed.lSeed=lSeed;return lSeed;
}

static __forceinline int MonsterId(int nId) { if (nId<0 || nId>=sgptDataTables->nMonStatsTxtRecordCount) return -1; return nId; }

static __forceinline int UnitClassId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwClassId; }

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
  ACT2Q1_OnRadamentActivated(pGame,pUnit);
  args.nMaxDistance=(AI_PARAM(4)+10)*(AI_PARAM(4)+10);args.bRadament=1;
  if(!pGame->nDifficulty) args.bNormal=1;
 }
 AIUTIL_FindTargetWithCallback(pGame,pUnit,&args,AITHINK_TargetCallback_GreaterMummy,1);
 D2UnitStrc* pActionTarget=args.pHealTarget;
 if(pMonStatsTxt->nSkill[1]>=0 && pActionTarget && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(2))
 {
  UNITS_SetTargetUnitForDynamicUnit(pUnit,args.pHealTarget);
  AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[1],pMonStatsTxt->nSkill[1],pActionTarget,0,0); return;
 }
 pActionTarget=args.pReviveTarget;
 if(pActionTarget && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(1) && sub_005FD470(pGame,pUnit,pMonStatsTxt->nSkill[0],args.pReviveTarget,0,0))
 {
  UNITS_SetTargetUnitForDynamicUnit(pUnit,pActionTarget);
  AITACTICS_UseSequenceSkill(pGame,pUnit,pMonStatsTxt->nSkill[0],pActionTarget,0,0); return;
 }
 if(pMonStatsTxt->nSkill[2]>=0 && (int)((unsigned int)RollSeed(pUnit)%100)<AI_PARAM(3))
 {
  pActionTarget=AIUTIL_SelectAiTargetWithCollisionCheck(pGame,pUnit,&nDistance,0);
  if(pActionTarget)
  {
   AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[2],pMonStatsTxt->nSkill[2],pActionTarget,0,0); return;
  }
 }
 if(args.nCounter<=0)
 {
  sub_005DE190_SetAiParam(pUnit,0,50,0);
  AITACTICS_WalkToTargetUnitWithSteps(pGame,pUnit,pTarget,3); return;
 }
 if((int)((unsigned int)RollSeed(pUnit)%100)<50)
  sub_005DF7D0_Maneuver(pGame,pUnit,pTarget,3,0);
 else
  AITACTICS_IdleInNeutralMode(pGame,pUnit,6);
}
