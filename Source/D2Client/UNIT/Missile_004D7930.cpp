#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"




struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if(nMax<=0)return 0;
    if((nMax-1)&nMax)return SEED_RollRandomNumber(pSeed)%nMax;
    return SEED_RollRandomNumber(pSeed)&(nMax-1);
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004D2520
static void __stdcall sub_004D2520_SpawnBaalBolt(int nX, int nY, D2UnitStrc* pMissile)
{
    if (COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), nX, nY, 3, 1))
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x2001;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.nMissile = SEED_RollRandomNumber(&pMissile->pSeed) % 3 + 0x27B;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = nX;
    tParams.nY = nY;

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tParams);
    if (pNewMissile)
    {
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, 0xFA);
        sub_004DA200_SetMotionVectorB(pNewMissile, 0, 0, -10, 1);
        MISSILE_SetTotalFrames(pNewMissile, 0x19);
        MISSILE_SetCurrentFrame(pNewMissile, 0x19);
        sub_0064A690_SetMissileAnimSpeed(pNewMissile, 0x80);
    }
}

struct D2StormPhaseStrc { int nFrameLimit,nPeriod,bSpawn; };
extern D2StormPhaseStrc gtStormPhase_006DB908[5]; // 0x006DB908
int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380
int __stdcall MISSILE_GetTargetY(D2UnitStrc*); // 0x0064A780
D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc*,int,int); // 0x0065A620
// 0x004D7930
void __fastcall sub_004D7930_CltDoBaalStormMissile(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner=sub_004639D0_GetOwnerUnit(pMissile);
    if(!pOwner)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    int nFrames=MISSILE_GetCurrentFrame(pMissile);
    int nPhase;
    for(nPhase=0;nPhase<4;++nPhase)
    {
        if(nFrames>gtStormPhase_006DB908[nPhase].nFrameLimit)break;
    }
    if(!(nFrames%gtStormPhase_006DB908[nPhase].nPeriod) && gtStormPhase_006DB908[nPhase].bSpawn)
    {
        SEED_RollRandomNumber(&pMissile->pSeed);
        D2MissileStrc tParams;
        memset(&tParams,0,sizeof(tParams));
        tParams.pOwner=pOwner;
        tParams.nTargetX=SEED_RollRandomNumber(&pMissile->pSeed)%40-20;
        int nTargetY=SEED_RollRandomNumber(&pMissile->pSeed)%40-20;
        tParams.dwFlags=2;
        tParams.pOrigin=pMissile;
        tParams.nTargetY=nTargetY;
        tParams.nMissile=626;
        tParams.nSkill=MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel=MISSILE_GetLevel(pMissile);
        D2UnitStrc* pNewMissile=sub_004CD540_CreateMissile(&tParams);
        if(pNewMissile)MISSILE_SetTargetX(pNewMissile,!pMissile ? -1 : pMissile->dwUnitId);
    }
    if(nFrames<210)MISSILE_SetTargetX(pMissile,2);
    else MISSILE_SetTargetX(pMissile,1);
    switch(nFrames)
    {
    case 450:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        sub_004CDB40_SubmitRequest(pOwner,631,nX+1,nY+1,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    case 425:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        sub_004CDB40_SubmitRequest(pOwner,632,nX,nY,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    case 375:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        sub_004CDB40_SubmitRequest(pOwner,633,nX,nY,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    case 325:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        sub_004CDB40_SubmitRequest(pOwner,634,nX,nY,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    }
    if(MISSILE_GetTargetY(pMissile))
    {
        D2UnitStrc* pTarget=sub_0065A620_FindUnitInAdjacentRooms(UNITS_GetRoom(pMissile),1,521);
        if(pTarget)
        {
            const unsigned __int64 lSeed1=(unsigned __int64)pMissile->pSeed.nHighSeed+(unsigned __int64)pMissile->pSeed.nLowSeed*0x6AC690C5;
            int nOffsetX=(unsigned int)lSeed1%10-5;
            const unsigned __int64 lSeed2=(lSeed1>>32)+(unsigned __int64)(unsigned int)lSeed1*0x6AC690C5;
            pMissile->pSeed.nHighSeed=(unsigned int)(lSeed2>>32);
            pMissile->pSeed.nLowSeed=(unsigned int)lSeed2;
            int nOffsetY=(unsigned int)lSeed2%10-5;
            int nX=UNITS_GetUnitXPosition(pTarget)+nOffsetX;
            int nY=UNITS_GetUnitYPosition(pTarget)+nOffsetY;
            sub_004D2520_SpawnBaalBolt(nX,nY,pMissile);
        }
    }
    sub_004D30C0_CltDoCommon(pMissile);
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D7930.inc"
