extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
#pragma intrinsic(memcpy)
struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc { char unk00[12];int nX,nY; };
struct D2SeedStrc { unsigned int nLowSeed,nHighSeed; };
struct D2UnitStrc { int dwUnitType;char unk04[0x1C];D2SeedStrc pSeed;int unk28;union {D2DynamicPathStrc* pDynamicPath;D2StaticPathStrc* pStaticPath;}; };
struct D2AiControlStrc { char unk00[0x14];int nAction; };
struct D2BaalTargetInfoStrc {char unk00[12];int nX,nY;};
struct D2PlayerCountBonusStrc {int nHp,nExperience,nSkillBonus,nDifficulty,nPlayerCount;};
extern const char gszAiThink4Source[]; // 0x006E3500
int __fastcall sub_005353F0_GetPortalGuid(D2UnitStrc*); // 0x005353F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc*); // 0x00554010
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc*,D2PlayerCountBonusStrc*,D2ActiveRoomStrc*,D2UnitStrc*); // 0x00573930
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*,D2UnitStrc*); // 0x005DC380
int __fastcall sub_005DD290_CheckAttack(D2UnitStrc*,D2UnitStrc*); // 0x005DD290
int __fastcall sub_005FD470_CheckMissilePath(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005FD470
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc*); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*,D2UnitStrc*,int); // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0
unsigned int __stdcall sub_006417F0_GetDistance(D2UnitStrc*,int,int); // 0x006417F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*,const char*,int); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*,D2SkillStrc*,int); // 0x006442A0
int __stdcall PATH_GetX(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetY(D2DynamicPathStrc*); // 0x00648900
int __stdcall sub_0064D910_CheckCollision(D2ActiveRoomStrc*,int,int,int,int); // 0x0064D910
static __forceinline int sub_0045ADF0(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {case 2:case 4:case 5:return pUnit->pStaticPath->nX;}
    return pUnit->pDynamicPath ? PATH_GetX(pUnit->pDynamicPath):0;
}
static __forceinline int sub_0045AE20(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {case 2:case 4:case 5:return pUnit->pStaticPath->nY;}
    return pUnit->pDynamicPath ? PATH_GetY(pUnit->pDynamicPath):0;
}
static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed=pSeed->nHighSeed+0x6AC690C5i64*pSeed->nLowSeed;
    pSeed->nHighSeed=(unsigned int)(nSeed>>32);pSeed->nLowSeed=(unsigned int)nSeed;return nSeed;
}
static __forceinline unsigned int SEED_RollBounded(D2SeedStrc* pSeed,int nMax)
{
    unsigned int nResult=0;
    if(nMax>0)
    {
        if((nMax-1)&nMax) nResult=(unsigned int)SEED_RollRandomNumber(pSeed)%nMax;
        else nResult=SEED_RollRandomNumber(pSeed)&(nMax-1);
    }
    return nResult;
}
// 0x005E9750
int __fastcall sub_005E9750_DiabloChooseAction(D2AiControlStrc* pAi,D2UnitStrc* pUnit,D2UnitStrc* pTarget,unsigned int nDistance,int nTargets,D2BaalTargetInfoStrc* pInfo)
{
    if(pAi->nAction) return pAi->nAction;
    if(!pTarget)
    {
        if(sub_0064D910_CheckCollision(UNITS_GetRoom(pUnit),sub_0045ADF0(pUnit),sub_0045AE20(pUnit),2,64)) return 16;
        return (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed)%1000)<1 ? 4:11;
    }
    D2GameStrc* pGame=SUNIT_GetGameFromUnit(pTarget);
    if(!pGame)pGame=SUNIT_GetGameFromUnit(pUnit);
    D2UnitStrc* pPortal=0;
    int bPortal=0;
    if((!pTarget ? 6:pTarget->dwUnitType)==0)
    {
        pPortal=SUNIT_GetServerUnit(pGame,2,sub_005353F0_GetPortalGuid(pTarget));
        if(pPortal && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal))==108)
            if(sub_006417F0_GetDistance(pPortal,pInfo->nX,pInfo->nY)<85)bPortal=1;
    }
    int bDangerousSkill=0;
    D2SkillStrc* pSkill=UNITS_GetLeftSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,1356);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    pSkill=UNITS_GetRightSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,1363);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    int bFar=0;
    int bVeryFar=0;
    if(pInfo)
    {
        int nDist=AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget,pUnit);
        if(nDist>85)bFar=1;
        if(nDist>105)bVeryFar=1;
    }
    int bMelee=UNITS_IsInMeleeRange(pUnit,pTarget,0);
    int bAttack=sub_005DD290_CheckAttack(pUnit,pTarget);
    int nFireRes=STATLIST_UnitGetStatValue(pTarget,39,0);
    int nColdRes=STATLIST_UnitGetStatValue(pTarget,41,0);
    int nWeights[17];
    int bInitialized=0;
    if(bMelee)
    {
        int nInitial[17]={0,0,40,70,0,75,24,40,15,0,0,0,0,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(UNITS_GetCurrentLifePercentage(pTarget)<20)nWeights[2]=50;
        if(STATES_CheckState(pTarget,11)){nWeights[7]=0;nWeights[8]=0;}
        if(nFireRes>nColdRes)nWeights[6]-=10;
        if(nFireRes<nColdRes)nWeights[6]+=10;
        if(!bAttack){nWeights[5]=0;nWeights[6]=0;}
        if(bPortal)nWeights[15]=10;
        bInitialized=1;
    }
    if(!bAttack)
    {
        if(!bInitialized)
        {
            int nInitial[17]={0,0,0,0,5,0,25,0,25,40,0,0,25,0,0,0,0};
            memcpy(nWeights,nInitial,sizeof(nWeights));
            if(nTargets<2){nWeights[6]=0;nWeights[1]=25;nWeights[8]-=5;nWeights[9]=0;}
            if(bDangerousSkill && !bFar)nWeights[13]=15;
            else if(bFar)
            {
                nWeights[1]=60;nWeights[12]=15;nWeights[13]=25;
                if(!nWeights[9])nWeights[9]=20;
                if(nTargets<2)nWeights[9]-=5;
            }
            if(bVeryFar)nWeights[1]=60;
            if(bPortal)nWeights[15]=20;
        }
    }
    else if(!bInitialized)
    {
        int nInitial[17]={0,0,0,0,0,5,25,0,15,20,10,0,20,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit,pTarget)>25){nWeights[10]=20;nWeights[5]=0;nWeights[8]-=5;}
        if(nFireRes>nColdRes){nWeights[6]-=10;nWeights[8]-=10;}
        if(nFireRes<nColdRes){nWeights[6]+=10;nWeights[8]+=10;}
        if(nTargets<2)nWeights[6]-=10;
        if(nTargets>3)nWeights[6]+=5;
        if(nDistance>60)nWeights[9]+=10;
        D2PlayerCountBonusStrc tBonus;
        MONSTER_GetPlayerCountBonus(pGame,&tBonus,UNITS_GetRoom(pUnit),pUnit);
        if(nTargets<2 && tBonus.nDifficulty<2)nWeights[9]=0;
        if(bDangerousSkill && !bFar){nWeights[6]+=10;nWeights[10]=30;nWeights[13]=15;}
        else if(bFar)
        {
            nWeights[1]=50;nWeights[10]=0;nWeights[13]=15;
            if(!nWeights[9])nWeights[9]=10;
        }
        if(bVeryFar){nWeights[9]=20;nWeights[1]=60;}
        if(bPortal)nWeights[15]=15;
    }
    if(sub_005FD470_CheckMissilePath(pGame,pUnit,199,pTarget,0,0))nWeights[9]=0;
    if(nWeights[15] && pPortal && !sub_005FD470_CheckMissilePath(pGame,pUnit,199,pPortal,0,0))nWeights[15]=0;
    int* pWeight=nWeights;
    int nTotal=0;
    for(int n=17;n;--n)nTotal+=*pWeight++;
    int nRoll=SEED_RollBounded(&pUnit->pSeed,nTotal);
    int nSum=0;
    pWeight=nWeights;
    for(int i=0;i<17;++i,++pWeight)
    {
        nSum+=*pWeight;
        if(nRoll<nSum)return i;
    }
    return 11;
}
