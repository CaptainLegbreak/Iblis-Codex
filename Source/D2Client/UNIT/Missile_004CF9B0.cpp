#include "D2Client.h"
#include "D2DataTbls.h"

struct D2GfxLightStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2SeedStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

#pragma pack(push, 4)
struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};

#pragma pack(pop)
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    unsigned char unk_08[0x18];
    D2SeedStrc tSeed;
    int unk0x28[1];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x34];
    D2GfxLightStrc* pLight;
};

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
    int unk0x38[5];
    int nParam4C;
    int unk0x50[3];
};

struct D2MissilesTxt
{
    char unk0x000[0x2C];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
    int dwCltHitPar[3];
    char unk0x078[0x12C];
};

struct D2SkillsTxt
{
    char unk0x000[0x150];
    int nParam150;
    int nParam154;
    char unk0x158[0xE4];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gaRing5OffsetX_006DB0EC[]; // 0x006DB0EC
extern const int gaRing5OffsetY_006DB0D8[]; // 0x006DB0D8
extern const int gaRing18OffsetX_006DB090[]; // 0x006DB090
extern const int gaRing18OffsetY_006DB048[]; // 0x006DB048
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
void __fastcall sub_004742D0_ResetLightSize(D2GfxLightStrc* pLight, int nRadius); // 0x004742D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
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
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

// calling-convention shim (not game code)
__declspec(noinline) D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams)
{
    return sub_004639D0_GetOwnerUnit(pMissileParams->pOwner);
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

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int SKILLS_GetLevelBasedParam(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return (nLevel - 1) * pSkillsTxtRecord->nParam154 + pSkillsTxtRecord->nParam150;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004CF9B0
int __fastcall sub_004CF9B0_CltHitRingSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    if (!DATATBLS_GetSkillsTxtRecord(nSkill))
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pOwner;
    tMissile.dwFlags = 0x4001;
    tMissile.nSkill = nSkill;
    tMissile.nSkillLevel = nLevel;
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        const int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        for (int i = 0; i < nCount; ++i)
        {
            tMissile.nX = nX + gaRing5OffsetX_006DB0EC[i % 5];
            tMissile.nY = nY + gaRing5OffsetY_006DB0D8[i % 5];
            sub_004CD540_CreateMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        tMissile.dwFlags = 0x8001;
        tMissile.nParam4C = SKILLS_GetLevelBasedParam(nSkill, nLevel);
        tMissile.nX = nX;
        tMissile.nY = nY;
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
        if (pNew && pNew->pLight)
        {
            sub_004742D0_ResetLightSize(pNew->pLight, 0xC);
        }
    }

    tMissile.dwFlags = 0xC001;
    int nIndex = 0;
    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        nIndex = pMissilesTxtRecord->dwCltHitPar[1];
        for (int i = 0; i < nIndex; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX_006DB090[i % 18];
            tMissile.nY = nY + gaRing18OffsetY_006DB048[i % 18];
            sub_004CD540_CreateMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[3] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[3];
        const int nEnd = nIndex + pMissilesTxtRecord->dwCltHitPar[2];
        for (int i = nIndex; i < nEnd; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX_006DB090[i % 18];
            tMissile.nY = nY + gaRing18OffsetY_006DB048[i % 18];
            sub_004CD540_CreateMissile(&tMissile);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004CF9B0.inc"

// 0x0045C370
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned __int64 SEED_RollRandomNumber64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollNext64(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollNextHL(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (unsigned __int64)(unsigned int)(lPrev >> 32) + (unsigned __int64)(unsigned int)lPrev * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned __int64 SEED_RollHL64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned int sub_004D2610_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x004D2520
static void __stdcall sub_004D2520_SpawnBaalBolt(D2UnitStrc* pMissile, int nX, int nY)
{
    if (COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), nX, nY, 3, 1))
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x2001;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.nMissile = SEED_RollRandomNumber(&pMissile->tSeed) % 3 + 0x27B;
    tParams.nSkill = sub_0064A280(pMissile);
    tParams.nSkillLevel = sub_0064A210(pMissile);
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

// 0x004D2610
void __fastcall sub_004D2610_CltDoBaalStorm(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int bInRange = 0;
    int nLevelId = 0;
    if (pOwner)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOwner));
    }
    switch (nLevelId)
    {
    case 131:
    case 132:
        bInRange = 1;
        break;
    }
    if (!pOwner || !bInRange)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);

    if (!MISSILE_GetTargetX(pMissile) || !(SEED_RollRandomNumber(&pMissile->tSeed) & 0x3F))
    {
        sub_00476A80_StartTiming(6, 2000, 3000, 2000);
        MISSILE_SetTargetX(pMissile, 1);
    }

    unsigned __int64 lSeed = SEED_RollHL64(&pMissile->tSeed);
    if (!((unsigned int)lSeed % 10))
    {
        lSeed = SEED_RollNextHL(&pMissile->tSeed, lSeed);
        const unsigned int nRollX = (unsigned int)lSeed;
        lSeed = SEED_RollNextHL(&pMissile->tSeed, lSeed);
        const unsigned int nRollY = (unsigned int)lSeed;
        const int nX = CLIENTS_GetUnitX(pMissile) + nRollX % 60 - 30;
        const int nY = CLIENTS_GetUnitY(pMissile) + nRollY % 60 - 30;
        sub_004D2520_SpawnBaalBolt(pMissile, nX, nY);
    }
}
