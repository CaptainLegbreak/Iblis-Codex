#include "D2MissileIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
struct Obj00648690;
struct Unit0064A210;
struct Unit0064A280;
struct Unit0064A300;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDB40
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0
extern "C" int __stdcall sub_0064A210(Unit0064A210* pUnit); // 0x0064A210
extern "C" int __stdcall sub_0064A280(Unit0064A280* pUnit); // 0x0064A280
extern "C" int __stdcall sub_0064A300(Unit0064A300* pUnit); // 0x0064A300
extern "C" void __stdcall sub_00648690(Obj00648690* pObj, int nValue, int nUnused3, int nUnused4); // 0x00648690
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0

void __fastcall sub_004742D0_ResetLightSize(void* pLight, int nSize); // 0x004742D0
int __fastcall sub_00474350_GetLightSize(void* pLight); // 0x00474350
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004BA790_UpdateUnitHint(void* pHint, D2UnitStrc* pUnit, int nArg); // 0x004BA790
void* __fastcall sub_004CA990_GetLinkFirst(D2UnitStrc* pUnit); // 0x004CA990
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004D0B90
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

int __fastcall sub_004D0DB0_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord)
        sub_004D0B90_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[0], pMissilesTxtRecord->wCltHitSubMissile[1], pMissile);
    return 1;
}

int __fastcall sub_004D0E00_CltHitBurstSub(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
        return 1;
    if (pHitUnit)
    {
        if (pHitUnit->dwUnitType != UNIT_MONSTER)
            return 0;
        if (!sub_004638A0_CheckMonStats2Flag(pHitUnit->dwClassId, 0xB))
            return 0;
    }
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
        sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltHitSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    sub_004D0B90_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[1], pMissilesTxtRecord->wCltHitSubMissile[2], pMissile);
    return 1;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D0B90.inc"
struct D2UnitStrc;

// 0x004D2190
static void __stdcall sub_004D2190_SpawnRandomBolt(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int aOffsetX[4] = { 1, 0, -1, 0 };
    int aOffsetY[4] = { 0, 1, 0, -1 };

    const unsigned int nZ = SEED_RollRandomNumber(&pMissile->pSeed) % 125;
    const int nDirection = SEED_RollRandomNumber(&pMissile->pSeed) & 3;
    const int nUnitX = UNITS_GetUnitXPosition(pMissile);
    const int nUnitY = UNITS_GetUnitYPosition(pMissile);
    const int nX = nUnitX + aOffsetX[nDirection];
    const int nY = nUnitY + aOffsetY[nDirection];
    const int nDiffY = nY - nUnitY;
    const int nDiffX = nX - nUnitX;

    int nMissile;
    switch (SEED_RollRandomNumber(&pMissile->pSeed) % 30)
    {
    case 0:
        nMissile = MISSILE_NEHLITHAKDEBRIS1;
        break;
    case 1:
        nMissile = MISSILE_NEHLITHAKDEBRIS2;
        break;
    case 2:
        nMissile = MISSILE_NEHLITHAKDEBRIS3;
        break;
    case 3:
        nMissile = MISSILE_NEHLITHAKDEBRIS4;
        break;
    default:
        nMissile = MISSILE_NEHLITHAKSWOOSH;
        break;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.pOwner = pOwner;
    tParams.nMissile = nMissile;
    tParams.nX = nX;
    tParams.nY = nY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nTargetX = nDiffY;
    tParams.nTargetY = -nDiffX;

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tParams);
    if (pNewMissile)
    {
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, nZ);
        MISSILE_SetTargetX(pNewMissile, UNITS_GetUnitXPosition(pMissile));
        MISSILE_SetTargetY(pNewMissile, UNITS_GetUnitYPosition(pMissile));
    }
}

// 0x004D2400
static void __stdcall sub_004D2400_SpawnRandomShard(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.pOwner = pOwner;

    int nTargetX = 20 - SEED_RollRandomNumber(&pMissile->pSeed) % 40;
    tParams.dwFlags = 2;
    tParams.pOrigin = pMissile;
    tParams.nTargetX = nTargetX;
    const int nTargetY = 20 - SEED_RollRandomNumber(&pMissile->pSeed) % 40;
    tParams.nTargetY = nTargetY;
    tParams.nMissile = MISSILE_BRDEATHLIGHTNINGBOLT;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (!nTargetX && !nTargetY)
    {
        nTargetX = SEED_RollRandomNumber(&pMissile->pSeed) % 19 + 1;
        tParams.nTargetX = nTargetX;
    }

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tParams);
    if (pNewMissile)
    {
        MISSILE_SetTargetX(pNewMissile, nTargetX);
        MISSILE_SetTargetY(pNewMissile, nTargetY);
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, -10);
    }
}

// 0x004D7710
void __fastcall sub_004D7710_CltDoSpawner(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pOwner)
    {
        sub_004D2190_SpawnRandomBolt(pOwner, pMissile);
        sub_004D2190_SpawnRandomBolt(pOwner, pMissile);

        if (nFrames > 60 && !(nFrames % 20))
        {
            sub_004D2400_SpawnRandomShard(pOwner, pMissile);
        }

        if (nFrames == 25)
        {
            int nY = UNITS_GetUnitYPosition(pMissile);
            int nX = UNITS_GetUnitXPosition(pMissile);
            sub_004CDB40_SubmitRequest(pOwner, 0x26A, nX + 2, nY + 2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
            nY = UNITS_GetUnitYPosition(pMissile);
            nX = UNITS_GetUnitXPosition(pMissile);
            sub_004CDB40_SubmitRequest(pOwner, 0x269, nX + 2, nY + 2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
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

void __fastcall sub_004D2610_CltDoBaalStorm(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int bInRange = 0;
    if (pOwner)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOwner));
        if (nLevelId >= 0x83)
        {
            if (nLevelId <= 0x84)
            {
                bInRange = 1;
            }
        }
    }

    if (!bInRange)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);

    if (!MISSILE_GetTargetX(pMissile) || !(SEED_RollRandomNumber(&pMissile->pSeed) & 0x3F))
    {
        sub_00476A80_StartTiming(6, 2000, 3000, 2000);
        MISSILE_SetTargetX(pMissile, 1);
    }

    if (!(SEED_RollRandomNumber(&pMissile->pSeed) % 10))
    {
        const unsigned int nRollX = SEED_RollRandomNumber(&pMissile->pSeed);
        const unsigned int nRollY = SEED_RollRandomNumber(&pMissile->pSeed);
        const int nX = UNITS_GetUnitXPosition(pMissile) + nRollX % 60 - 30;
        const int nY = UNITS_GetUnitYPosition(pMissile) + nRollY % 60 - 30;
        sub_004D2520_SpawnBaalBolt(nX, nY, pMissile);
    }
}

// 0x004D2760
int __fastcall sub_004D2760_CltDoEightWaySpawn(D2UnitStrc* pMissile)
{
    const int nXOffsets[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    const int nYOffsets[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x58, 0, 0, sub_0064A280((Unit0064A280*)pMissile), sub_0064A210((Unit0064A210*)pMissile));

    for (int i = 0; i < 8; ++i)
    {
        const int nPosX = nXOffsets[i] + nX;
        const int nPosY = nYOffsets[i] + nY;
        D2UnitStrc* pChild = sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x59, 0, 0, sub_0064A280((Unit0064A280*)pMissile), sub_0064A210((Unit0064A210*)pMissile));
        if (pChild)
        {
            D2Common_10216(pChild->pDynamicPath, nPosX, nPosY, 0);
        }

        D2UnitStrc* pNew = sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x1A1, nPosX, nPosY, sub_0064A280((Unit0064A280*)pMissile), sub_0064A210((Unit0064A210*)pMissile));
        if (pNew)
        {
            int nFrames = sub_0064A300((Unit0064A300*)pNew);
            nFrames -= SEED_RollLimitedRandomNumber(&pMissile->pSeed, nFrames / 2);
            MISSILE_SetTotalFrames(pNew, nFrames);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            sub_00648690((Obj00648690*)pPath, SEED_RollLimitedRandomNumber(&pMissile->pSeed, PATH_GetVelocity(pPath)), (int)gszMissileSourceFile_006DAEF4, 0x1A6B);
            sub_004DA5B0_SetBallistic(pNew, 0x1E, nFrames);
        }
    }

    return 1;
}

// 0x004D2990
static void __stdcall sub_004D2990_SpawnAtFreeSpot(D2UnitStrc* pOwner, int nX, int nY, D2UnitStrc* pMissile)
{
    int bRetry = 1;
    int nTries = 0;
    if (!pMissile || !pOwner)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        return;
    while (bRetry && nTries < 4)
    {
        const int nOffsetX = 17 - SEED_RollRandomNumber(&pMissile->pSeed) % 34;
        const int nOffsetY = 17 - SEED_RollRandomNumber(&pMissile->pSeed) % 34;
        if (nOffsetX < -1 || nOffsetX > 1 || nOffsetY < -1)
        {
            if (!COLLISION_CheckMask(pRoom, nX + nOffsetX, nY + nOffsetY, 4))
            {
                nX += nOffsetX;
                nY += nOffsetY;
                bRetry = 0;
            }
        }
        ++nTries;
    }
    if (bRetry)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    tParams.pOwner = pOwner;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = nX;
    tParams.nMissile = MISSILE_ANYASTEAMVENT;
    tParams.nY = nY;
    sub_004CD540_CreateMissile(&tParams);
    tParams.nMissile = MISSILE_ANYASTEAM;
    sub_004CD540_CreateMissile(&tParams);
}

// 0x004D8000
void __fastcall sub_004D8000_CltDoEruption(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (nFrame < 110)
    {
        int nCount;
        if (!nFrame)
        {
            sub_004CDB40_SubmitRequest(pOwner, 0x214, nX, nY, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
            nCount = nFrame + 8;
        }
        else if (nFrame < 50)
        {
            nCount = 8;
        }
        else
        {
            nCount = nFrame < 80 ? 5 : 1;
        }
        for (int i = 0; i < nCount; ++i)
        {
            const int nLevel = MISSILE_GetLevel(pMissile);
            const int nSkill = MISSILE_GetSkill(pMissile);
            if (pOwner)
            {
                D2MissileStrc tParams;
                memset(&tParams, 0, sizeof(tParams));
                tParams.pOwner = pOwner;
                tParams.dwFlags = 1;
                tParams.nX = nX + 2;
                tParams.nY = nY + 2;
                tParams.nSkill = nSkill;
                tParams.nSkillLevel = nLevel;
                tParams.nMissile = MISSILE_ANYASTEAM1;
                D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
                if (pNew)
                {
                    const unsigned int nRoll1 = SEED_RollRandomNumber(&pMissile->pSeed);
                    const unsigned int nRoll2 = SEED_RollRandomNumber(&pMissile->pSeed);
                    const unsigned int nRoll3 = SEED_RollRandomNumber(&pMissile->pSeed);
                    sub_004DA1D0_SetMotionVectorA(pNew, 50 - nRoll1 % 100, 50 - nRoll2 % 100, 0);
                    sub_004DA200_SetMotionVectorB(pNew, 0, 0, (nRoll3 & 7) + 2, 1);
                }
            }
        }
    }
    if (nFrame == 5)
        sub_00476A80_StartTiming(nFrame - 2, 0x258, 0xFA0, 0xBB8);
    if (nFrame < 200 && !(nFrame % 7))
        sub_004D2990_SpawnAtFreeSpot(pOwner, nX, nY, pMissile);
    sub_004D30C0_CltDoCommon(pMissile);
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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pSkillsTxt[nSkillId];
}

// 0x004D39C0
void __fastcall sub_004D39C0_CltDoLightGrow(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nParam0 = pMissilesTxtRecord->dwCltParam[0] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[0];
    const int nParam1 = pMissilesTxtRecord->dwCltParam[1] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[1];
    const int nVelocityZ = nParam1 * nParam0;
    const int nParam2 = pMissilesTxtRecord->dwCltParam[2] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[2];
    const int nVelocityX = nParam2 * nParam0;

    int nSteps = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile), pSkillsTxtRecord->dwCalc[0], nSkillId, MISSILE_GetLevel(pMissile));
    nSteps = D2_MIN(D2_MAX(nSteps, 1), 0x3C);

    const int nInterval = 0x3C / nSteps;
    void* pLight = pMissile->pLight;
    const int nLightSize = pLight ? sub_00474350_GetLightSize(pLight) : 0;
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!((nFrames + 1) % nInterval) && nLightSize < nSteps && pLight)
        sub_004742D0_ResetLightSize(pLight, nLightSize + 1);

    if (!nFrames)
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 1;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nX = CLIENTS_GetUnitX(pMissile);
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tParams);
        if (pSubMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pSubMissile, -nVelocityX, 0, nVelocityZ);
            sub_004DA200_SetMotionVectorB(pSubMissile, nParam2, 0, -nParam1, 1);
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] > 0)
        {
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            pSubMissile = sub_004CD540_CreateMissile(&tParams);
            if (pSubMissile)
            {
                sub_004DA1D0_SetMotionVectorA(pSubMissile, -nVelocityX, 0, nVelocityZ);
                sub_004DA200_SetMotionVectorB(pSubMissile, nParam2, 0, -nParam1, 1);
            }
        }
    }

    if (nFrames == nParam0 - 2)
    {
        void* pHint = sub_004CA990_GetLinkFirst(pMissile);
        if (pHint)
            sub_004BA790_UpdateUnitHint(pHint, pMissile, 1);

        if (pMissilesTxtRecord->wProgSound > 0)
            sub_004B9A00(pMissilesTxtRecord->wProgSound, pMissile, 0, 0, 0);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D49F0
void __fastcall sub_004D49F0_CltDoWeave(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        if (pMissilesTxtRecord->wCltSubMissile[0] >= 0 && sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            tParams.pInitFunc = (MissileInitFunc)sub_004CC870_SubMissileCallback;
            tParams.nInitArg = (int)pMissile;
            D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
            if (pNew)
                sub_004DA1D0_SetMotionVectorA(pNew, 0, 0, sub_004DA150_GetMotionAZ(pMissile));
        }

        int nPeriod = pMissilesTxtRecord->dwCltParam[0];
        if (nPeriod < 1)
            nPeriod = 1;
        if (!(sub_0064A3B0_GetElapsedFrames(pMissile) % nPeriod))
        {
            const int nA = MISSILE_GetTargetX(pMissile);
            const int nB = MISSILE_GetTargetY(pMissile);
            int nOffsetX;
            int nOffsetY;
            if (SEED_RollRandomNumber(&pMissile->pSeed) & 1)
            {
                nOffsetX = nA - nB;
                nOffsetY = nB + nA;
            }
            else
            {
                nOffsetX = nB + nA;
                nOffsetY = nB - nA;
            }
            nOffsetX = 3 * nOffsetX / 4;
            nOffsetY = 3 * nOffsetY / 4;
            if (nOffsetX || nOffsetY)
            {
                D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
                D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
            }
            MISSILE_SetTargetX(pMissile, nOffsetX);
            MISSILE_SetTargetY(pMissile, nOffsetY);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D5090
void __fastcall sub_004D5090_CltDoTurn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        if (pMissilesTxtRecord->wCltSubMissile[0] > 0 && sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            sub_004CD540_CreateMissile(&tParams);
        }

        int nPeriod = pMissilesTxtRecord->dwCltParam[0];
        if (nPeriod < 1)
            nPeriod = 1;
        if (!(sub_0064A3B0_GetElapsedFrames(pMissile) % nPeriod))
        {
            const int nA = MISSILE_GetTargetX(pMissile);
            const int nB = MISSILE_GetTargetY(pMissile);
            int nOffsetX;
            int nOffsetY;
            switch (SEED_RollRandomNumber(&pMissile->pSeed) & 3)
            {
            case 0:
                nOffsetX = nA - nB;
                nOffsetY = nB + nA;
                nOffsetX = 3 * nOffsetX / 4;
                nOffsetY = 3 * nOffsetY / 4;
                break;
            case 2:
                nOffsetX = nB + nA;
                nOffsetY = nB - nA;
                nOffsetX = 3 * nOffsetX / 4;
                nOffsetY = 3 * nOffsetY / 4;
                break;
            default:
                nOffsetX = nA;
                nOffsetY = nB;
                break;
            }
            D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
            D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
            MISSILE_SetTargetX(pMissile, nOffsetX);
            MISSILE_SetTargetY(pMissile, nOffsetY);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D72C0
void __fastcall sub_004D72C0_CltDoPeriodicSpawn(D2UnitStrc* pMissile)
{
    if (!(sub_0064A380_GetRemainingFrames(pMissile) % 4))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x2521;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nMissile = MISSILE_QUEENDEATHGLOB;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        const int nX = UNITS_GetUnitXPosition(pMissile);
        tParams.nX = nX;
        const int nY = UNITS_GetUnitYPosition(pMissile);
        tParams.nY = nY;
        tParams.nTargetX = nX - SEED_RollRandomNumber(&pMissile->pSeed) % 12;
        tParams.nTargetY = SEED_RollRandomNumber(&pMissile->pSeed) % 13 + nY - 6;
        sub_004CD540_CreateMissile(&tParams);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
