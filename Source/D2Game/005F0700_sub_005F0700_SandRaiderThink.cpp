struct D2SeedStrc { unsigned int nLowSeed, nHighSeed; };
struct D2UnitStrc { int dwUnitType; char unk04[0x1C]; D2SeedStrc pSeed; };
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; };
struct D2MonStatsTxt { char unk00[0x4F]; unsigned char nAIDel[3]; char unk52[4]; short wAiParam[8][3]; char unk86[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiControlStrc { char unk00[0x14]; int dwAiParam[3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance, bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2SandRaiderAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*,int); // 0x0045C390
D2UnitStrc* __fastcall sub_005DD0B0_IterateUnits(D2GameStrc*,D2UnitStrc*,void*,D2UnitStrc* (__fastcall *)(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*),int); // 0x005DD0B0
int __fastcall sub_005DD280_GetValue(D2UnitStrc*); // 0x005DD280
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc*,D2UnitStrc*,unsigned char,int,D2UnitStrc*,int,int); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DEC80
int __fastcall sub_005DF7D0_Maneuver(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SandRaider(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*); // 0x005F06B0
void __stdcall sub_00621E40_ApplyOverlay(D2UnitStrc*,int,int); // 0x00621E40
void __stdcall STATES_ToggleState(D2UnitStrc*,int,int); // 0x00639DB0
static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])
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
        default: sub_00621E40_ApplyOverlay(pUnit,46,0); break;
        case 1: sub_00621E40_ApplyOverlay(pUnit,150,0); break;
        }
        AITACTICS_IdleInNeutralMode(pGame,pUnit,pMonStatsTxt->nAIDel[pGame->nDifficulty]+1);
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
    if (pAiControl->dwAiParam[2] < 7 && sub_005DD280_GetValue(pUnit) < AI_PARAM(0))
    {
        D2SandRaiderAiCallbackArgStrc args;
        args.pTarget = 0;
        args.nDistance = 0x7FFFFFFF;
        sub_005DD0B0_IterateUnits(pGame,pUnit,&args,AITHINK_TargetCallback_SandRaider,1);
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
