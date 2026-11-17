#include "D2Client.h"

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
struct D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileStrc;
struct D2StaticPathStrc;
struct D2SpawnArgsStrc;
struct D2MissileScanArgStrc;
struct D2MissileScanStateStrc;
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
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
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
    unsigned short wHitSound;
    unsigned short wExplosionMissile;
    short wSubMissile[3];
    short wSound;
    unsigned char unk_20[0x4];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    short wProgOverlay;
    unsigned char unk_36[0x2];
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x1E];
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

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    union
    {
        struct
        {
            D2CoordStrc tGameCoords;
        };
        struct
        {
            int nXPos;
            int nYPos;
        };
        struct
        {
            int nX;
            int nY;
        };
    };
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2UnitStrc* __fastcall sub_004CD540(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

struct D2SpawnArgsStrc
{
    D2UnitStrc* pOwner;
    int nMissile;
};

static __declspec(noinline) D2UnitStrc* __stdcall sub_004CE530_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile);
void __fastcall sub_004B9A00_PlayOverlay(int nOverlay, D2UnitStrc* pOwner, int a3, int a4, int a5); // 0x004B9A00
void __fastcall sub_004CD540_CreateClientMissile(D2MissileStrc* pMissile); // 0x004CD540
void __fastcall sub_004CE650_PlaySound(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSound, int nLevel); // 0x004CE650

struct D2MissileScanArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pMissile;
    int nSkillId;
    int nSkillLevel;
    int nMaxHits;
    int nSubMissile;
};

struct D2MissileScanStateStrc
{
    int unk0x00;
    int nHits;
    D2MissileScanArgStrc* pScanArg;
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    char unk0x054[0x10];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0xD0];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40
int __fastcall sub_004CFD70_HitScanCallback(void* pArg, D2UnitStrc* pUnit); // 0x004CFD70
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
int __stdcall sub_0064A730_GetTargetX(D2UnitStrc* pUnit); // 0x0064A730
int __stdcall sub_0064A780_GetTargetY(D2UnitStrc* pUnit); // 0x0064A780

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

static __forceinline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static __forceinline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004CE140
void __fastcall sub_004CE140_SpawnRingAround(D2UnitStrc* pMissile, int nChance, int nCount, int nRange, int nMissile)
{
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    if (sub_0064A380_GetRemainingFrames(pMissile) && ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nChance) > 0)
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x20;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.pOrigin = pMissile;
    tParams.nSkill = sub_0064A280(pMissile);
    tParams.nSkillLevel = sub_0064A210(pMissile);
    tParams.nMissile = nMissile;

    int nOffsetX = 0;
    int nOffsetY = 0;
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);

    for (int i = 0; i < nCount; ++i)
    {
        nOffsetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
        nOffsetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
        nOffsetX += nOffsetX < 0 ? -nRange : nRange;
        nOffsetY += nOffsetY < 0 ? -nRange : nRange;
        tParams.nTargetX = nOffsetX + nX;
        tParams.nTargetY = nOffsetY + nY;
        sub_004CD540_CreateMissile(&tParams);
    }
}

// 0x004CE320
D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nRange, int nFrequency, int nMissileId)
{
    if (nFrequency <= 0)
    {
        return 0;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrequency)
    {
        return 0;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
    {
        return 0;
    }

    SEED_InitLowSeed(&pMissile->pSeed, CLIENTS_GetUnitX(pMissile) + sub_0064A3B0_GetElapsedFrames(pMissile));

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2003;
    tMissileParams.pOwner = pOwner;
    tMissileParams.nSkill = sub_0064A280(pMissile);
    tMissileParams.nSkillLevel = sub_0064A210(pMissile);
    tMissileParams.nMissile = nMissileId;

    --nRange;
    const int nOffsetX = nRange - ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange);
    const int nOffsetY = nRange - ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange);
    const int nX = CLIENTS_GetUnitX(pMissile) + nOffsetX;
    tMissileParams.nX = nX;
    const int nY = CLIENTS_GetUnitY(pMissile) + nOffsetY;
    tMissileParams.nY = nY;

    if (COLLISION_CheckMask(pRoom, nX, nY, 4))
    {
        return 0;
    }

    return sub_004CD540(&tMissileParams);
}

static __forceinline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context sub_004CE530_Shim
// calling-convention shim (not game code)
D2UnitStrc* __fastcall sub_004CE530_Shim(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile)
{
    return sub_004CE530_SpawnSubMissile(pOwner, nMissile, 0x14, pMissile);
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
    tMissile.nSkill = sub_0064A280(pMissile);
    tMissile.nSkillLevel = sub_0064A210(pMissile);

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

static __forceinline int UNITS_GetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int UNITS_GetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int RollOffset(D2UnitStrc* pUnit, int nRange)
{
    return ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRange / 2;
}

// 0x004CE850
void __fastcall sub_004CE850_SpawnPeriodicMissile(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissileId, int nFrame, int nLevel)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTable->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTable->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (pMissilesTxtRecord->wSound > 0)
    {
        sub_004CE650_PlaySound(pOwner, pUnit, pMissilesTxtRecord->wSound, nLevel);
    }

    if (pMissilesTxtRecord->wProgOverlay > 0 && nFrame == 315)
    {
        sub_004B9A00_PlayOverlay(pMissilesTxtRecord->wProgOverlay, pOwner, 0, 0, 0);
    }

    if (nFrame % 2 != 0)
    {
        return;
    }

    if (nLevel < 3 && nFrame % 16 != 0)
    {
        return;
    }

    int nRange = 4;
    if (nLevel < 3)
    {
        nRange = 1;
    }
    else if (nLevel < 6)
    {
        nRange = 2;
    }
    else if (nLevel < 9)
    {
        nRange = 3;
    }

    int nOffsetX = 0;
    int nOffsetY = 0;
    if (nRange > 1)
    {
        nOffsetX = RollOffset(pUnit, nRange);
        nOffsetY = RollOffset(pUnit, nRange);
    }

    D2MissileStrc missile;
    memset(&missile, 0, sizeof(missile));
    missile.dwFlags = 1;
    missile.pOwner = pOwner;
    missile.nSkill = sub_0064A280(pUnit);
    missile.nSkillLevel = sub_0064A210(pUnit);
    missile.nMissile = nMissileId;
    missile.nX = UNITS_GetXPosition(pUnit) + nOffsetX;
    missile.nY = UNITS_GetYPosition(pUnit) + nOffsetY;
    sub_004CD540_CreateClientMissile(&missile);
}

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CFD70
int __fastcall sub_004CFD70_CreateCallbackMissile(void* pArgument, D2UnitStrc* pUnit)
{
    D2MissileScanStateStrc* pState = (D2MissileScanStateStrc*)pArgument;
    D2MissileScanArgStrc* pScanArg = pState->pScanArg;
    if (pState->nHits >= pScanArg->nMaxHits)
    {
        return 0;
    }

    D2MissileStrc tMissileParams = {};
    tMissileParams.pOwner = pScanArg->pOwner;
    tMissileParams.pOrigin = pScanArg->pMissile;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.nSkill = pScanArg->nSkillId;
    tMissileParams.nSkillLevel = pScanArg->nSkillLevel;
    tMissileParams.nMissile = pScanArg->nSubMissile;
    tMissileParams.nTargetX = UNITS_GetXPositionForceInl(pUnit);
    tMissileParams.nTargetY = UNITS_GetYPositionForceInl(pUnit);
    sub_004CD540_CreateMissile(&tMissileParams);
    return 1;
}

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004CFE30
int __fastcall sub_004CFE30_CltHitScanArea(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    int nFlags = pSkillsTxtRecord->dwAuraFilter;
    if (!nFlags)
    {
        nFlags = 0xA783;
    }

    D2MissileScanArgStrc tArg;
    tArg.pOwner = pOwner;
    tArg.pMissile = pMissile;
    tArg.nSkillId = nSkillId;
    tArg.nSkillLevel = nSkillLevel;
    tArg.nMaxHits = nParam;
    tArg.nSubMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    sub_004C5C40_ScanArea(pOwner, nX, nY, nRange, nFlags, sub_004CFD70_HitScanCallback, &tArg, 1);

    return 1;
}

// 0x004CFFA0
int __fastcall sub_004CFFA0_HitScanCallback(void* pArgument, D2UnitStrc* pUnit)
{
    D2MissileScanStateStrc* pState = (D2MissileScanStateStrc*)pArgument;
    D2MissileScanArgStrc* pScanArg = pState->pScanArg;
    if (pState->nHits >= pScanArg->nMaxHits)
    {
        return 0;
    }

    D2MissileStrc tMissileParams = {};
    tMissileParams.pOwner = pScanArg->pOwner;
    tMissileParams.pOrigin = pScanArg->pMissile;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.nSkill = pScanArg->nSkillId;
    tMissileParams.nSkillLevel = pScanArg->nSkillLevel;
    tMissileParams.nMissile = pScanArg->nSubMissile;
    tMissileParams.nTargetX = UNITS_GetXPositionForceInl(pUnit);
    tMissileParams.nTargetY = UNITS_GetYPositionForceInl(pUnit);
    sub_004CD540_CreateMissile(&tMissileParams);
    return 1;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// build: context MISSILE_GetApproxOffsetLengthInline
__forceinline int MISSILE_GetApproxOffsetLengthInline(int nX, int nY)
{
    int nAbsX = nX < 0 ? -nX : nX;
    int nAbsY = nY < 0 ? -nY : nY;
    if (nX >= nY)
        return (nAbsX + 2 * nAbsY) >> 1;
    return (nAbsY + 2 * nAbsX) >> 1;
}

// 0x004D19D0
static void __stdcall sub_004D19D0_SpawnRing(int nTargetUnitId, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(0x176);
    int aOffsetX[14] = { -4, 2, 4, -3, -2, 3, 5, -3, -5, 5, -6, -1, 0, 6 };
    int aOffsetY[14] = { 6, 4, -4, -2, 1, 7, 0, 3, -4, -3, 4, -5, 5, -3 };
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x8102;
    tParams.nMissile = 0x176;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = sub_0064A280(pMissile);
    tParams.nSkillLevel = sub_0064A210(pMissile);
    for (int i = 0; i < 14; ++i)
    {
        const int nX = aOffsetX[i];
        const int nY = aOffsetY[i];
        tParams.nTargetX = nX;
        tParams.nTargetY = nY;
        tParams.nRange = pMissilesTxtRecord->wRange * MISSILE_GetApproxOffsetLengthInline(nX, nY) / 6;
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, nTargetUnitId);
            MISSILE_SetTargetY(pNew, SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10);
        }
    }
}

void __fastcall sub_004D6680_CltDoObjectRing(D2UnitStrc* pMissile)
{
    const int nTargetUnitId = MISSILE_GetTargetX(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!sub_00463990(nTargetUnitId, 2))
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    if (nFrames == 10)
    {
        sub_004D19D0_SpawnRing(nTargetUnitId, pMissile);
        sub_00476A80_StartTiming(nFrames - 6, nFrames + 0x46, 0x50, 0x190);
    }
    sub_004D30C0_CltDoCommon(pMissile);
}

static __forceinline int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetXPosition(pUnit->pDynamicPath);
        return 0;
    }
}

static __forceinline int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetYPosition(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x004D7880
void __fastcall sub_004D7880_CltDoRotateTarget(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDiffY = 0;
    const int nX = GetX(pUnit);
    const int nY = GetY(pUnit);
    const int nDiffX = nX - sub_0064A730_GetTargetX(pUnit);
    nDiffY = nY - sub_0064A780_GetTargetY(pUnit);
    D2COMMON_10170_PathSetTargetPos(pPath, nX + nDiffY, nY - nDiffX);
    D2Common_10142(pPath, pUnit, 0);
    sub_004D30C0_CltDoCommon(pUnit);
}
