#include "D2MissileIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                                  // 0x0045C3E0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);                         // 0x00463740

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                                             // 0x004DA000

void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);                            // 0x004DA1D0

void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5);                 // 0x004DA200

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

struct D2MissilesTxt;

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

void __fastcall sub_004D2D70(D2UnitStrc* pMissile, int nArg1, int nArg2); // 0x004D2D70

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDB40

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

struct D2StormPhaseStrc { int nFrameLimit,nPeriod,bSpawn; };

extern D2StormPhaseStrc gtStormPhase_006DB908[5]; // 0x006DB908

int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380

int __stdcall MISSILE_GetTargetY(D2UnitStrc*); // 0x0064A780

D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc*,int,int); // 0x0065A620

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

// build: context SEED_RollRandomNumber
static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumber
static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// build: context MISSILE_RollInRange
static inline int MISSILE_RollInRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin < nMax)
    {
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }

    return nMin;
}

// build: context SKILLS_GetMissilesTxtRecord
static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// build: context UNITS_GetUnitXPosition
inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// build: context UNITS_GetUnitYPosition
inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004CEA00
void __fastcall sub_004CEA00_SpawnMissileInRadius(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nRadius)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (!UNITS_GetRoom(pUnit))
    {
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > nMissile)
    {
        nMissile = MISSILE_RollInRange(&pUnit->pSeed, nMissile, pMissilesTxtRecord->wCltSubMissile[0]);
        pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
        if (!pMissilesTxtRecord)
        {
            return;
        }
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pOwner;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pUnit);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pUnit);

    const int nRadiusSq = nRadius * nRadius;
    int nTries = 0;
    while (nTries < 4)
    {
        ++nTries;

        int nX = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRadius + 1) - nRadius;
        int nY = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRadius + 1) - nRadius;
        if (nX * nX + nY * nY > nRadiusSq)
        {
            continue;
        }

        nX += UNITS_GetUnitXPosition(pUnit);
        nY += UNITS_GetUnitYPosition(pUnit);

        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        if (!pRoom || COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, 0, 1))
        {
            continue;
        }

        tMissileParams.nX = nX;
        tMissileParams.nY = nY;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA000_ResetGfxMotion(pMissile);
            if (nRadius == 6)
            {
                sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 2 * pMissilesTxtRecord->dwCltParam[0]);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 2 * -pMissilesTxtRecord->dwCltParam[1], 1);
            }
            else
            {
                sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[0]);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -pMissilesTxtRecord->dwCltParam[1], 1);
            }
            return;
        }
    }
}




static void __stdcall sub_004D0B90_SpawnHitBurst(int nCount, int nVelocity, int nGate, int nRingMissile, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    D2MissileStrc tParams;
    if (nGate >= 0)
    {
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x524;
        tParams.pOwner = pOwner;
        tParams.pOrigin = pMissile;
        tParams.nMissile = MISSILE_MOLTENBOULDER_FLYINGROCKS;
        tParams.nVelocity = nVelocity;
        tParams.nSkill = nSkill;
        tParams.nSkillLevel = nLevel;
        const int nSpread = 2 * nCount;
        for (int i = 0; i < nCount; ++i)
        {
            const int nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread + nX;
            const int nTargetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread + nY;
            if (UNITS_GetDistanceToCoordinates(pMissile, nTargetX, nTargetY) > 3)
            {
                tParams.nTargetX = nTargetX;
                tParams.nTargetY = nTargetY;
                sub_004CD540_CreateMissile(&tParams);
            }
        }
    }
    if (nRingMissile >= 0)
    {
        for (int i = 0; i < 18; ++i)
        {
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 1;
            tParams.pOwner = pOwner;
            tParams.nX = gaHitRingX_006DB540[i] + nX;
            tParams.nY = gaHitRingY_006DB588[i] + nY;
            tParams.nSkill = nSkill;
            tParams.nSkillLevel = nLevel;
            tParams.nMissile = nRingMissile;
            sub_004CD540_CreateMissile(&tParams);
        }
    }
}

// 0x004D0DB0
int __fastcall sub_004D0DB0_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    sub_004D0B90_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[0], pMissilesTxtRecord->wCltHitSubMissile[1], pMissile);
    return 1;
}

static inline int sub_CanHitUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    return sub_004638A0_CheckMonStats2Flag(nClassId, 0xB);
}

// 0x004D0E00
int __fastcall sub_004D0E00_CltHitBurstSub(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (sub_CanHitUnit(pHitUnit))
    {
        if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
        {
            sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltHitSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
        }

        sub_004D0B90_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[1], pMissilesTxtRecord->wCltHitSubMissile[2], pMissile);
        return 1;
    }

    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return SKILLS_GetMissilesTxtRecordChecked(pUnit->dwClassId);
}

static inline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberInline(pSeed) % nMax;
    }

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x004D6130
void __fastcall sub_004D6130_CltDoRandomSubMissile3(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nCount = 0;
    do
    {
        if (pMissilesTxtRecord->wCltSubMissile[nCount] < 0 || pMissilesTxtRecord->dwCltParam[nCount + 1] <= 0)
        {
            break;
        }

        ++nCount;
    }
    while (nCount < 3);

    if (nCount <= 0)
    {
        sub_004D2D70(pMissile, 0, 0);
        return;
    }

    if (nFrames < pMissilesTxtRecord->dwCltParam[0])
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    SEED_InitLowSeed(&pMissile->pSeed, UNITS_GetXPositionForceInl(pMissile));

    const int nIndex = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, nCount);
    if (nFrames % pMissilesTxtRecord->dwCltParam[nIndex + 1])
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2MissileStrc tMissile = {};
    tMissile.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[nIndex];
    tMissile.nSkillLevel = nSkillLevel;

    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
    if (pNew)
    {
        sub_004D2D70(pNew, 0, 1);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

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
        tParams.nMissile=MISSILE_BAALFX_SPIRIT_1;
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

#include "gen/data/Source/D2Client/UNIT/Missile_004CEA00.inc"
