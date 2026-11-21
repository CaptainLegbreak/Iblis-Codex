#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0

void __stdcall sub_00648AD0(D2DynamicPathStrc* pPath, int nX, int nY);                                    // 0x00648AD0

void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970

int __stdcall sub_0064A3B0(D2UnitStrc* pMissile);                                                         // 0x0064A3B0

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nValue);                                        // 0x0064A710

int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);                                    // 0x0064A730

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nValue);                                        // 0x0064A760

int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);                                               // 0x0064A780

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed);                                          // 0x00650E40

int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                          // 0x00650E50

struct D2StaticPathStrc { int unk0x00[3]; int nXPos; int nYPos; };

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArgs);

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930

D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode);  // 0x00466730

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

void __fastcall sub_004ADE80(D2UnitStrc* pUnit, void* pArg);                                                // 0x004ADE80

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840

void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY);                      // 0x004C51E0

int __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                                 // 0x004CA900

void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000

void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350

void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0

void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690

D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int nX, int nY);                             // 0x00619DA0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit); // 0x00624390

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame);       // 0x00626D40

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);                     // 0x006488A0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pDynamicPath, int nX, int nY);            // 0x00648AD0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pTargetUnit);                // 0x00648B90

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner);                                  // 0x0064A400


struct D2CltSpreadStrc
{
    int nOffsetX;
    int nOffsetY;
    unsigned char nDirection;
    char pad0x09[3];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern const D2CltSpreadStrc gaCltSpread_006DB7F0[7];                                                       // 0x006DB7F0

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0

void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0

void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

int __stdcall sub_0064A210_GetSkillLevel(D2UnitStrc* pUnit);                                                // 0x0064A210

int __stdcall sub_0064A280_GetSkill(D2UnitStrc* pUnit);                                                     // 0x0064A280

static __declspec(noinline) void __stdcall sub_004CD420_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile);

static __forceinline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004D63E0
void __fastcall sub_004D63E0_CltDoZigZag(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nUpdateInterval = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0(pMissile) % nUpdateInterval)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    if (!pSeed)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    SEED_InitLowSeed(pSeed, sub_0064A730_GetMissileTargetStatus(pMissile));

    const unsigned int nPackedOffset = sub_0064A780_targetValue(pMissile);
    const int nPreviousOffsetX = (short)nPackedOffset;
    const int nPreviousOffsetY = (short)(nPackedOffset >> 16);

    int nSignedOffsetX;
    int nSignedOffsetY;
    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nSignedOffsetX = nPreviousOffsetX;
        nSignedOffsetY = -nPreviousOffsetY;
    }
    else
    {
        nSignedOffsetX = -nPreviousOffsetX;
        nSignedOffsetY = nPreviousOffsetY;
    }

    int nNextOffsetX = (nSignedOffsetY + 4 * nPreviousOffsetX) / 4;
    int nNextOffsetY = (nSignedOffsetX + 4 * nPreviousOffsetY) / 4;
    if (!nNextOffsetX)
    {
        nNextOffsetX = 1;
    }

    if (!nNextOffsetY)
    {
        nNextOffsetY = 1;
    }

    sub_00648AD0(pMissile->pDynamicPath, nNextOffsetX + CLIENTS_GetUnitX(pMissile), nNextOffsetY + CLIENTS_GetUnitY(pMissile));
    D2Common_10142(pMissile->pDynamicPath, pMissile, 0);

    MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
    const unsigned short nPackedOffsetX = (unsigned short)nNextOffsetX;
    const unsigned short nPackedOffsetY = (unsigned short)nNextOffsetY;
    MISSILE_SetTargetY(pMissile, nPackedOffsetX + (nPackedOffsetY << 16));

    sub_004D30C0_CltDoCommon(pMissile);
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline int MISSILE_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// build: context sub_004CD420_RollPierce
static void __stdcall sub_004CD420_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int nPierce = 0;
    if (pOwner && pOwner->dwUnitType != UNIT_PLAYER && pOwner->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(MISSILE_GetClassId(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[2 >> 3] & gdwBitMasks[2 & 7]))
    {
        return;
    }

    int nChance = STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0);
    if (!nChance)
    {
        return;
    }

    int nSeed;
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && sub_00463DD0_GetPlayerUnit() != pOwner)
    {
        nChance = 100;
        nSeed = 0;
    }
    else
    {
        nSeed = STATLIST_GetUnitBaseStat(pOwner, 0x148, 0);
    }

    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nSeed);
    while (nPierce < 4)
    {
        const unsigned __int64 lSeed = tSeed.nHighSeed + 0x6AC690C5i64 * tSeed.nLowSeed;
        tSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        tSeed.nLowSeed = (unsigned int)lSeed;
        if ((int)((unsigned int)lSeed % 100) >= nChance)
        {
            break;
        }
        ++nPierce;
    }

    STATLIST_SetUnitStat(pMissile, 0x148, nPierce, 0);
}

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissileParams->nMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nX = 0;
    int nY = 0;
    if (pMissileParams->dwFlags & 1)
    {
        nX = pMissileParams->nX;
        nY = pMissileParams->nY;
    }
    else
    {
        if (!pMissileParams->pOrigin)
        {
            return 0;
        }

        nX = CLIENTS_GetUnitX(pMissileParams->pOrigin);
        nY = CLIENTS_GetUnitY(pMissileParams->pOrigin);
    }

    if (pMissileParams->pOwner)
    {
        if (!COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pMissileParams->pOwner), nX, nY)
            && !sub_00619DA0_ActLookup(gpGlobal_007A0634, nX, nY))
        {
            return 0;
        }
    }
    else
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && !COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pPlayer), nX, nY)
            && !sub_00619DA0_ActLookup(gpGlobal_007A0634, nX, nY))
        {
            return 0;
        }
    }

    int nTargetX;
    int nTargetY;
    if (pMissileParams->dwFlags & 2)
    {
        nTargetX = pMissileParams->nTargetX + nX;
        nTargetY = pMissileParams->nTargetY + nY;
    }
    else if (pMissileParams->dwFlags & 0x20)
    {
        nTargetX = pMissileParams->nTargetX;
        nTargetY = pMissileParams->nTargetY;
    }
    else
    {
        nTargetX = nX;
        nTargetY = nY;
    }

    int nVelocity = (pMissileParams->dwFlags & 4)
        ? ((pMissileParams->dwFlags & 0x10) ? pMissileParams->nVelocity : pMissileParams->nVelocity << 8)
        : (pMissilesTxtRecord->nVel + (pMissilesTxtRecord->nVelLev * pMissileParams->nSkillLevel) / 8) << 8;

    int nVelocityPercent = 100;
    if (pMissileParams->pOwner && (pMissilesTxtRecord->nMissileFlags[3 >> 3] & gdwBitMasks[3 & 7])
        && STATES_CheckState(pMissileParams->pOwner, 0x57))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pMissileParams->pOwner, 0x57);
        if (pStatList)
        {
            nVelocityPercent = STATLIST_GetStatValue(pStatList, 0xA1, 0);
            nVelocity = DATATBLS_ApplyRatio(nVelocity, nVelocityPercent, 100);
        }
    }

    if (nVelocity)
    {
        nVelocity = MISSILE_ApplyRatio(nVelocity, 75, 100);
    }

    D2UnitStrc* pTarget = pMissileParams->pTarget;
    if (nVelocity)
    {
        if (pMissileParams->pOwner && !pTarget)
        {
            if (nTargetX == nX && nTargetY == nY)
            {
                sub_004C51E0_GetAdjacentPosition(pMissileParams->pOwner, &nTargetX, &nTargetY);
            }
        }
        else if (pTarget && pMissileParams->pOwner && pTarget != pMissileParams->pOwner
            && CLIENTS_GetUnitX(pTarget) == CLIENTS_GetUnitX(pMissileParams->pOwner)
            && CLIENTS_GetUnitY(pTarget) == CLIENTS_GetUnitY(pMissileParams->pOwner))
        {
            sub_004C51E0_GetAdjacentPosition(pMissileParams->pOwner, &nTargetX, &nTargetY);
            pTarget = 0;
        }

        int nDestX = nTargetX;
        int nDestY = nTargetY;
        if (pTarget)
        {
            nDestX = CLIENTS_GetUnitX(pTarget);
            nDestY = CLIENTS_GetUnitY(pTarget);
        }

        const int nXDiff = nDestX - nX;
        if (D2_ABS(nXDiff) >= 100)
        {
            return 0;
        }

        const int nYDiff = nDestY - nY;
        if (D2_ABS(nYDiff) >= 100)
        {
            return 0;
        }
    }

    D2UnitStrc* pMissile = sub_00466730_SpawnPresetUnit(pMissileParams->nMissile, nX, nY, 3, 0);
    if (!pMissile)
    {
        return 0;
    }

    sub_00624390_AnimInit(pMissile);
    STATLIST_AllocStatListEx(pMissile, 0, 0, 0);
    pMissile->dwFrameCountPrecise = pMissilesTxtRecord->nAnimLen << 8;
    MISSILE_SetAnimSpeed(pMissile, pMissilesTxtRecord->nAnimSpeed << 4);

    int nRange;
    if (pMissileParams->dwFlags & 0x8000)
    {
        nRange = pMissileParams->nRange;
    }
    else
    {
        nRange = pMissilesTxtRecord->wRange + pMissileParams->nSkillLevel * pMissilesTxtRecord->wLevRange;
        if (pMissileParams->dwFlags & 8 && pMissilesTxtRecord->nSubLoop)
        {
            nRange += pMissileParams->nLoops * (pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart);
        }

        if (nVelocityPercent && nVelocityPercent != 100)
        {
            nRange += DATATBLS_ApplyRatio(nRange, 100, nVelocityPercent);
        }
    }

    if (pMissileParams->dwFlags & 0x200)
    {
        nRange -= pMissileParams->nFrame;
        pMissile->nSeqCurrentFramePrecise = pMissileParams->nFrame << 8;
    }

    MISSILE_SetTotalFrames(pMissile, nRange);
    MISSILE_SetCurrentFrame(pMissile, nRange);

    if (pMissileParams->dwFlags & 0x800)
    {
        nRange -= pMissileParams->nActivateFrame;
    }
    else
    {
        nRange -= pMissilesTxtRecord->nActivate;
    }
    MISSILE_SetActivateFrame(pMissile, nRange);

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        sub_00465F00_RemoveClientUnit(pMissile->dwUnitId, pMissile->dwUnitType);
        return 0;
    }

    PATH_SetVelocity(pPath, 0, ".\\UNIT\\Missile.cpp", 7924);

    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pPath, nTargetX, nTargetY);
    }

    if (nVelocity)
    {
        PATH_SetVelocity(pPath, nVelocity, ".\\UNIT\\Missile.cpp", 7935);
        D2Common_10142(pPath, pMissile, 0);
    }

    if (pMissilesTxtRecord->nCanDestroy)
    {
        pMissile->dwFlagEx |= 0x40000;
    }

    MISSILE_SetOwner(pMissile, pMissileParams->pOwner);
    PATH_SetAcceleration(pPath, pMissilesTxtRecord->wAccel);
    PATH_SetMaxVelocity(pPath, pMissilesTxtRecord->nMaxVel << 8);

    if (pMissileParams->dwFlags & 0x2000)
    {
        PATH_SetDirection(pMissile->pDynamicPath, SEED_RollLimitedRandomNumber(&pMissile->pSeed, 0x40));
    }

    sub_004DA000_ResetGfxMotion(pMissile);
    sub_004DA690_ReplaceMotionFlag1With8(pMissile);

    if (pMissileParams->dwFlags & 0x400)
    {
        unsigned int nDistance = UNITS_GetDistanceToCoordinates(pMissile, nTargetX, nTargetY);
        if (!nDistance)
        {
            nDistance = 1;
        }

        unsigned int nStep = nVelocity << 4;
        if (nStep)
        {
            const int nFrames = (nDistance << 16) / nStep;
            MISSILE_SetCurrentFrame(pMissile, nFrames);
            MISSILE_SetTotalFrames(pMissile, nFrames);
        }
    }

    if (pMissileParams->dwFlags & 0x100)
    {
        sub_004DA5B0_SetBallistic(pMissile, pMissileParams->nGfxArg, MISSILE_GetTotalFrames(pMissile));
        sub_004DA350_UpdateMotion(pMissile);
        PATH_SetDirection(pPath, (unsigned char)(nTargetX + nTargetY) & ~0xC0);
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
    }

    MISSILE_SetSkill(pMissile, pMissileParams->nSkill);
    MISSILE_SetLevel(pMissile, pMissileParams->nSkillLevel);

    if (pMissileParams->pOwner)
    {
        UNITS_StoreOwner(pMissile, pMissileParams->pOwner);
        sub_004CD420_RollPierce(pMissileParams->pOwner, pMissile);
    }

    pMissile->dwFlags &= ~8;

    if (gnValue_0072A348 && !(pMissileParams->dwFlags & 0x4000))
    {
        if (pMissilesTxtRecord->nLight || (unsigned char)pMissileParams->nLightRadius)
        {
            sub_00464930_FreeLight(pMissile);
            pMissile->pLight = sub_00474160_MakeLightEntry(pMissile, 1, pMissilesTxtRecord->nLight, 0xFF,
                pMissilesTxtRecord->nRed, pMissilesTxtRecord->nGreen, pMissilesTxtRecord->nBlue);
        }
    }
    else
    {
        sub_00464930_FreeLight(pMissile);
    }

    if (pMissileParams->pInitFunc)
    {
        pMissileParams->pInitFunc(pMissile, pMissileParams->nInitArg);
    }

    if (pMissilesTxtRecord->wTravelSound)
    {
        const int nSound = pMissilesTxtRecord->wTravelSound;
        if (nSound)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
            if (pMissileParams->pOwner)
            {
                const int nHandle = sub_004CA900_FindUnitSfxInRange(pMissileParams->pOwner, 0x13A);
                if (nHandle)
                {
                    sub_004BA840(nHandle);
                }
            }
        }
    }

    if (pMissileParams->pOwner)
    {
        sub_004ADE80(pMissileParams->pOwner, pMissile);
    }

    return pMissile;
}

static __forceinline unsigned int SEED_RollUnitSeedInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollUnitSeedWideInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.lSeed = lSeed;

    return (unsigned int)lSeed;
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

// 0x004D6820
void __fastcall sub_004D6820_CltDoSpreadSpawn(D2UnitStrc* pMissile)
{
    D2MissileStrc missileParams;
    D2UnitStrc* pNew;
    int nY;
    int nX;

    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);

    if (nRemaining == 0x96)
    {
        sub_00476A80_StartTiming(0x19, 0, 0xFA0, 0);
    }

    for (int i = 0; i < 7; ++i)
    {
        const D2CltSpreadStrc* pSpread = &gaCltSpread_006DB7F0[i];
        const int nFrame = 0x145 - 0x19 * i;
        if (nRemaining > nFrame)
        {
            break;
        }

        if (nRemaining == nFrame)
        {
            nY = UNITS_GetUnitYPosition(pMissile);
            nX = UNITS_GetUnitXPosition(pMissile);
            int nSkillLevel = sub_0064A210_GetSkillLevel(pMissile);
            int nSkill = sub_0064A280_GetSkill(pMissile);
            if (pOwner)
            {
                memset(&missileParams, 0, sizeof(missileParams));
                missileParams.dwFlags = 1;
                missileParams.pOwner = pOwner;
                missileParams.nX = pSpread->nOffsetX + nX;
                missileParams.nY = pSpread->nOffsetY + nY;
                missileParams.nSkill = nSkill;
                missileParams.nSkillLevel = nSkillLevel;
                missileParams.nMissile = 0x154;
                pNew = sub_004CD540_CreateMissile(&missileParams);
                if (pNew)
                {
                    PATH_SetDirection(pNew->pDynamicPath, pSpread->nDirection);
                    MISSILE_SetTotalFrames(pNew, nRemaining);
                    MISSILE_SetCurrentFrame(pNew, nRemaining);
                }
            }
        }
    }

    if (nRemaining < 0xA5 && !(nRemaining % 2))
    {
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pOwner;
        missileParams.nX = UNITS_GetUnitXPosition(pMissile);
        missileParams.nY = UNITS_GetUnitYPosition(pMissile);
        missileParams.nTargetX = UNITS_GetUnitXPosition(pMissile) - 13;
        missileParams.nTargetY = UNITS_GetUnitYPosition(pMissile) + 3;
        missileParams.nSkill = sub_0064A280_GetSkill(pMissile);
        missileParams.nSkillLevel = sub_0064A210_GetSkillLevel(pMissile);
        missileParams.nMissile = 0x153;
        pNew = sub_004CD540_CreateMissile(&missileParams);
        if (pNew)
        {
            sub_004DA1D0_SetMotionVectorA(pNew, 0, 0, 0x46);
            sub_004DA200_SetMotionVectorB(pNew, 0, 0, -1, 1);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            PATH_SetDirection(pPath, 0x15);
            D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
        }
    }

    if (nRemaining < 0x96)
    {
        const int nX2 = UNITS_GetUnitXPosition(pMissile) - 13;
        const int nY2 = UNITS_GetUnitYPosition(pMissile) + 3;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pOwner;
        missileParams.nX = nX2;
        missileParams.nY = nY2;
        missileParams.nTargetX = nX2 + (int)(SEED_RollUnitSeedInline(pMissile) % 5) + 1;
        missileParams.nTargetY = nY2 + (int)(SEED_RollUnitSeedWideInline(pMissile) % 10) - 5;
        missileParams.nSkill = sub_0064A280_GetSkill(pMissile);
        missileParams.nSkillLevel = sub_0064A210_GetSkillLevel(pMissile);
        missileParams.nMissile = 0x96;
        pNew = sub_004CD540_CreateMissile(&missileParams);
        if (pNew)
        {
            UNITS_SetAnimationSpeed(pNew, 0x40);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D63E0.inc"
