#include "D2Client.h"

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
struct D2StaticPathStrc;
struct D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileStrc;
struct D2SkillsTxt;
struct D2SpawnArgsStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

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
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x14];
    int nSeqCurrentFramePrecise;
    int nFrameRate;
    char unk0x4C[0x18];
    void* pLight;
    char unk0x68[0x5C];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2MissilesTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[4];
    char unk0x008[0x0A];
    short wTravelSound;
    char unk0x014[0x0A];
    short wCltSubMissile[3];
    unsigned char unk_24[0x8];
    short wCltHitSubMissile;
    unsigned char unk_2E[0xA];
    int dwCltHitPar38;
    unsigned char unk_3C[0x1C];
    int dwCltParam[5];
    int dwCltHitPar0;
    char unk0x070[0x26];
    short wRange;
    short wLevRange;
    unsigned char nVel;
    unsigned char nVelLev;
    unsigned char nMaxVel;
    char unk0x09D;
    short wAccel;
    char unk0x0A0[0x90];
    unsigned char nLight;
    unsigned char nFlicker;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nCanDestroy;
    unsigned char nActivate;
    char unk0x137[0x41];
    unsigned char nAnimLen;
    char unk0x179[0x07];
    unsigned char nSubLoop;
    unsigned char nSubStart;
    unsigned char nSubStop;
    char unk0x183[0x1E];
    unsigned char nAnimSpeed;
    char unk0x1A2[0x02];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
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
    unsigned char nLightRadius;
    char unk0x51[0x03];
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern void* gpGlobal_007A0634; // 0x007A0634
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit); // 0x00464930
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730
void* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
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
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit); // 0x00624390
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame); // 0x00626D40
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pDynamicPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3); // 0x00649970
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x0064A400
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
static __declspec(noinline) void __stdcall sub_004CD420_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern int gnMissileTargetX_006DB100[]; // 0x006DB100
extern int gnMissileTargetY_006DB120[]; // 0x006DB120
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

struct D2SkillsTxt
{
    char unk0x000[0x138];
    int dwCalc0;
    char unk0x13C[0x100];
};

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc*); // 0x004639D0
int __stdcall MISSILE_GetSkill(D2UnitStrc*); // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,int,int,int); // 0x00646CA0
int __stdcall PATH_GetDirection(D2DynamicPathStrc*); // 0x006487F0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

struct D2SpawnArgsStrc
{
    D2UnitStrc* pOwner;
    int nMissile;
};

static __declspec(noinline) D2UnitStrc* __stdcall sub_004CE530_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile);
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

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
    if (pOwner && pOwner->dwUnitType != 0 && pOwner->dwUnitType != 1)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(MISSILE_GetClassId(pMissile));
    if (!(pMissilesTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7]))
    {
        return;
    }

    int nChance = STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0);
    if (!nChance)
    {
        return;
    }

    int nSeed;
    if (pOwner && pOwner->dwUnitType == 0 && sub_00463DD0() != pOwner)
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
        D2UnitStrc* pPlayer = sub_00463DD0();
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
    if (pMissileParams->pOwner && (pMissilesTxtRecord->nFlags[3 >> 3] & gdwBitMasks[3 & 7])
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

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004D01D0
int __fastcall sub_004D01D0_CreateMissileFan(D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissile, int nSkill, int nSkillLevel, int nStep)
{
    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecord(nMissile);
    if (!pMissilesTxt)
    {
        return 0;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x1F;
    tMissile.pOwner = pOwner;
    tMissile.pOrigin = pOrigin;
    tMissile.nMissile = nMissile;
    tMissile.nX = UNITS_GetUnitXPosition(pOrigin);
    tMissile.nY = UNITS_GetUnitYPosition(pOrigin);
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nSkill = nSkill;
    tMissile.nLoops = nSkillLevel - 1;
    tMissile.nVelocity = pMissilesTxt->dwCltHitPar38 << 7;

    for (int i = 0; i < 8; i += nStep)
    {
        tMissile.nTargetX = gnMissileTargetX_006DB100[i];
        tMissile.nTargetY = gnMissileTargetY_006DB120[i];
        sub_004CD540_CreateMissile(&tMissile);
    }

    return 1;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D01D0.inc"

static __forceinline D2MissilesTxt* GetMissileRecord(int id) {
 if(id>=0 && id<sgptDataTables->nMissilesTxtRecordCount)
  return &sgptDataTables->pMissilesTxt[id];
 return 0;
}

static __forceinline D2SkillsTxt* GetSkillRecord(int id) {
 if(id>=0 && id<sgptDataTables->nSkillsTxtRecordCount)
  return &sgptDataTables->pSkillsTxt[id];
 return 0;
}

// 0x004D0380
int __fastcall sub_004D0380_CreateChildMissile(D2UnitStrc* unit)
{
 D2MissilesTxt* missile=GetMissileRecord(unit ? unit->dwClassId : -1);
 if(!missile || missile->wCltHitSubMissile<0)return 1;
 D2UnitStrc* owner=sub_004639D0_GetOwnerUnit(unit);
 if(!owner)return 1;
 int skillId=MISSILE_GetSkill(unit);
 int level=MISSILE_GetLevel(unit);
 D2SkillsTxt* skill=GetSkillRecord(skillId);
 if(!skill)return 1;
 int range=missile->dwCltHitPar0;
 if(!range) {
  range=SKILLS_EvaluateSkillFormula(owner,skill->dwCalc0,skillId,level);
  if(range<5)range=5;
 }
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.pOwner=owner;
 params.dwFlags=1;
 params.nMissile=missile->wCltHitSubMissile;
 params.nSkill=level;
 params.nSkillLevel=level;
 params.nX=CLIENTS_GetUnitX(unit);
 params.nY=CLIENTS_GetUnitY(unit);
 if(range>0) {params.dwFlags=0x8001;params.nRange=range;}
 D2UnitStrc* child=sub_004CD540_CreateMissile(&params);
 if(child) PATH_SetDirection(child->pDynamicPath,PATH_GetDirection(unit->pDynamicPath));
 return 1;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
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
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static __forceinline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
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

// 0x004CE530
static D2UnitStrc* __stdcall sub_004CE530_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 2;
    tMissile.nMissile = nMissile;
    tMissile.pOwner = pOwner;
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);

    tMissile.nTargetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
    const int nY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
    tMissile.nTargetY = nY;
    if (!tMissile.nTargetX && !nY)
    {
        tMissile.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nSpread - 1) + 1;
    }

    const int nX = tMissile.nTargetX;

    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
    if (pNew)
    {
        MISSILE_SetTargetX(pNew, nX);
        MISSILE_SetTargetY(pNew, nY);
    }

    return pNew;
}

// 0x004D4F20
void __fastcall sub_004D4F20_CltDoSubMissileTimers(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    const int nSpread = pMissilesTxtRecord->dwCltParam[2];
    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        int nTimer = MISSILE_GetTargetX(pMissile);
        if (nTimer <= 0)
        {
            sub_004CE530_SpawnSubMissile(pOwner, pMissilesTxtRecord->wCltSubMissile[0], nSpread, pMissile);
            nTimer = pMissilesTxtRecord->dwCltParam[0];
        }

        MISSILE_SetTargetX(pMissile, nTimer - 1);
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] > 0)
    {
        int nTimer = MISSILE_GetTargetY(pMissile);
        if (nTimer <= 0)
        {
            D2MissileStrc tMissile;
            memset(&tMissile, 0, sizeof(tMissile));
            tMissile.dwFlags = 0x102;
            tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            tMissile.pOwner = pOwner;
            tMissile.pOrigin = pMissile;
            tMissile.nSkill = MISSILE_GetSkill(pMissile);
            tMissile.nSkillLevel = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 5) + 1;
            tMissile.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
            tMissile.nTargetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
            if (!tMissile.nTargetX && !tMissile.nTargetY)
            {
                tMissile.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nSpread - 1) + 1;
            }

            D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
            if (pNew)
            {
                MISSILE_SetTargetX(pNew, SEED_RollLimitedRandomNumber(&pMissile->pSeed, 5));
            }

            nTimer = pMissilesTxtRecord->dwCltParam[1];
        }

        MISSILE_SetTargetY(pMissile, nTimer - 1);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
