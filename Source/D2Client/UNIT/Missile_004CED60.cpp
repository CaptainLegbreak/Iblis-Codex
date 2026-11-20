#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
struct D2LightStrc;
struct D2OwnerStrc_004CA990;

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
struct D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x14];
    int nSeqCurrentFramePrecise;
    int nFrameRate;
    char unk0x4C[0x18];
    void* pLight;
    char unk0x68[0x5C];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};



typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArgs);

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
    union
    {
        int nFrames;
        unsigned char nLightRadius;
    };
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern void* gpGlobal_007A0634; // 0x007A0634
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit); // 0x00464930
void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730
D2LightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nMode, int nRadius, unsigned char nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x00474160
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall sub_004ADE80(D2UnitStrc* pUnit, void* pArg); // 0x004ADE80
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004BA840(int nHandle); // 0x004BA840
void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C51E0
int __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int nX, int nY); // 0x00619DA0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit); // 0x00624390
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame); // 0x00626D40
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall sub_00648690(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall sub_006486D0(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity); // 0x006486D0
void __stdcall sub_00648700_acceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration); // 0x00648700
void __stdcall sub_006488A0(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0
void __stdcall sub_00648AD0(D2DynamicPathStrc* pDynamicPath, int nX, int nY); // 0x00648AD0
void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3); // 0x00649970
void __stdcall sub_0064A1E0_SetMissileLevel(D2UnitStrc* pMissile, int nSkillLevel); // 0x0064A1E0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
int __stdcall sub_0064A300(D2UnitStrc* pMissile); // 0x0064A300
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
int __stdcall sub_0064A3E0(D2UnitStrc* pMissile); // 0x0064A3E0
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x0064A400
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
static __declspec(noinline) void __stdcall sub_004CD420_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280


void __fastcall sub_004742D0_ResetLightSize(D2LightStrc* pLight, int nSize); // 0x004742D0
int __fastcall sub_00474350_GetLightSize(D2LightStrc* pLight); // 0x00474350
void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce); // 0x004BA790
extern "C" void* __fastcall sub_004CA990_GetLinkFirst(D2OwnerStrc_004CA990* pOwner); // 0x004CA990
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pMissile, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pMissile, int nX, int nY, int nZ, int nArg); // 0x004DA200
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

// build: context DATATBLS_GetMissilesTxtRecord
inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// build: context MISSILE_ApplyRatio
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

// build: context sub_004CD420_RollSeed
static __forceinline unsigned int sub_004CD420_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004CD420
static void __stdcall sub_004CD420_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int nPierce = 0;
    if (pOwner && pOwner->dwUnitType != 0 && pOwner->dwUnitType != 1)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(sub_0064A3E0(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[2 >> 3] & gdwBitMasks[2 & 7]))
    {
        return;
    }

    int nChance = STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0);
    if (!nChance)
    {
        return;
    }

    D2SeedStrc tSeed;
    if (pOwner && pOwner->dwUnitType == 0 && sub_00463DD0_GetPlayerUnit() != pOwner)
    {
        nChance = 100;
        SEED_InitLowSeed(&tSeed, 0);
    }
    else
    {
        SEED_InitLowSeed(&tSeed, STATLIST_GetUnitBaseStat(pOwner, 0x148, 0));
    }

    for (;;)
    {
        const int nRoll = nPierce < 4 ? (int)(sub_004CD420_RollSeed(&tSeed) % 100) : nChance;
        if (nRoll >= nChance)
        {
            break;
        }

        ++nPierce;
    }

    STATLIST_SetUnitStat(pMissile, 0x148, nPierce, 0);
}

// 0x004CD540
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
    pMissile->nFrameRate = pMissilesTxtRecord->nAnimLen << 8;
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
        sub_00465F00_RemoveServerSideUnit(pMissile->dwUnitId, pMissile->dwUnitType);
        return 0;
    }

    sub_00648690(pPath, 0, ".\\UNIT\\Missile.cpp", 7924);

    if (pTarget)
    {
        sub_00648B90_SetPathTarget(pPath, pTarget);
    }
    else
    {
        sub_00648AD0(pPath, nTargetX, nTargetY);
    }

    if (nVelocity)
    {
        sub_00648690(pPath, nVelocity, ".\\UNIT\\Missile.cpp", 7935);
        D2Common_10142(pPath, pMissile, 0);
    }

    if (pMissilesTxtRecord->nCanDestroy)
    {
        pMissile->dwFlagEx |= 0x40000;
    }

    MISSILE_SetOwner(pMissile, pMissileParams->pOwner);
    sub_00648700_acceleration(pPath, pMissilesTxtRecord->wAccel);
    sub_006486D0(pPath, pMissilesTxtRecord->nMaxVel << 8);

    if (pMissileParams->dwFlags & 0x2000)
    {
        sub_006488A0(pMissile->pDynamicPath, SEED_RollLimitedRandomNumber(&pMissile->pSeed, 0x40));
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
        sub_004DA5B0_SetBallistic(pMissile, pMissileParams->nGfxArg, sub_0064A300(pMissile));
        sub_004DA350_UpdateMotion(pMissile);
        sub_006488A0(pPath, (unsigned char)(nTargetX + nTargetY) & ~0xC0);
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
    }

    MISSILE_SetSkill(pMissile, pMissileParams->nSkill);
    sub_0064A1E0_SetMissileLevel(pMissile, pMissileParams->nSkillLevel);

    if (pMissileParams->pOwner)
    {
        UNITS_StoreOwner(pMissile, pMissileParams->pOwner);
        sub_004CD420_RollPierce(pMissileParams->pOwner, pMissile);
    }

    pMissile->dwFlags &= ~8;

    if (gnValue_0072A348 && !(pMissileParams->dwFlags & 0x4000))
    {
        if (pMissilesTxtRecord->nLight || pMissileParams->nLightRadius)
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
        pMissileParams->pInitFunc(pMissile, pMissileParams->pInitArgs);
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

// build: context SEED_RollRandomNumber
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumberInline
static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
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

// build: context DATATBLS_GetMissilesTxtRecordInline
static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x004CED60
void __fastcall sub_004CED60(D2UnitStrc* pUnit, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissile);

    D2UnitStrc* pOwner = pUnit;
    if (!pUnit || (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1))
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return;
        }
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x01;
    tParams.dwFlags |= 0x200;
    if (pMissilesTxtRecord->nRandFrames)
    {
        tParams.dwFlags |= 0x200;
    }
    tParams.pOwner = pOwner;
    tParams.nSkill = nSkill;
    tParams.nMissile = nMissile;
    tParams.nSkillLevel = nLevel;

    const int nRadiusSq = nCount * nCount;
    const int nStart = -nCount;
    for (int nOffsetY = nStart; nOffsetY <= nCount; nOffsetY += nMult)
    {
        const int nOffsetYSq = nOffsetY * nOffsetY;
        for (int nOffsetX = -nCount; nOffsetX <= nCount; nOffsetX += nMult)
        {
            if (nOffsetX * nOffsetX + nOffsetYSq <= nRadiusSq && SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, nPerStep) <= 0)
            {
                tParams.nX = nOffsetX + nX;
                tParams.nY = nOffsetY + nY;
                if (pMissilesTxtRecord->nRandFrames)
                {
                    tParams.nFrame = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, pMissilesTxtRecord->nRandFrames);
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
                if (COLLISION_GetRoomBySubTileCoordinates(pRoom, tParams.nX, tParams.nY))
                {
                    sub_004CD540_CreateMissile(&tParams);
                }
            }
        }
    }
}

// build: context SKILLS_GetMissilesTxtRecord
inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004CC910
static __declspec(noinline) int sub_004CC910_GetSpawnDelay(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < 125)
        return 25;
    if (nFrames < 175)
        return 10;
    return nFrames < 300 ? 3 : 15;
}

// 0x004D48B0
void __fastcall sub_004D48B0_CltDoDelayedSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        int nTimer = MISSILE_GetTargetX(pMissile);
        if (!nTimer)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 2;
            missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            missileParams.nSkill = MISSILE_GetSkill(pMissile);
            missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            missileParams.pOwner = pOwner;
            missileParams.pOrigin = pOwner;
            int nX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - pMissilesTxtRecord->dwCltParam[0];
            missileParams.nTargetX = nX;
            const int* pRange = &pMissilesTxtRecord->dwCltParam[0];
            int nY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - *pRange;
            missileParams.nTargetY = nY;
            if (!nX && !nY)
            {
                nX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, *pRange) + 1;
                missileParams.nTargetX = nX;
            }
            D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pNewMissile)
            {
                MISSILE_SetTargetX(pNewMissile, nX);
                MISSILE_SetTargetY(pNewMissile, nY);
            }
            nTimer = sub_004CC910_GetSpawnDelay(pMissile);
        }
        MISSILE_SetTargetX(pMissile, nTimer - 1);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// build: context SKILLS_GetMissilesTxtRecordChecked
inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// build: context MISSILE_GetMissilesTxtRecordFromUnit
static inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return SKILLS_GetMissilesTxtRecordChecked(pUnit->dwClassId);
}

// 0x004D4DC0
void __fastcall sub_004D4DC0_CltDoRandomSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
    {
        const int nFrequency = pMissilesTxtRecord->dwCltParam[2] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[2];
        if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrequency)
        {
            sub_004D30C0_CltDoCommon(pMissile);
            return;
        }

        const int nOffsetX = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - pMissilesTxtRecord->dwCltParam[0];
        const int nOffsetY = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - pMissilesTxtRecord->dwCltParam[0];
        const int nX = CLIENTS_GetUnitX(pMissile) + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[1] + 1) - pMissilesTxtRecord->dwCltParam[1];
        const int nY = CLIENTS_GetUnitY(pMissile) + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[1] + 1) - pMissilesTxtRecord->dwCltParam[1];

        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nX = nX;
        tParams.nY = nY;
        tParams.nTargetX = nX + nOffsetX;
        tParams.nTargetY = nY + nOffsetY;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        sub_004CD540_CreateMissile(&tParams);

        sub_004D30C0_CltDoCommon(pMissile);
    }
    else
    {
        sub_004CD390_CltDoDefault(pMissile);
    }
}
