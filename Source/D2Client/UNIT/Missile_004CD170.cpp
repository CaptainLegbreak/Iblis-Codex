#include "D2MissileIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2ClientGfx.h"

#define UNIT_INVALID 6

struct D2StaticPathStrc;

struct D2GfxEntryStrc;

union D2SeedStrc;

struct D2MissileStrc;

struct D2CltMissileSpawnArgStrc;

struct D2AreaScanStrc;

struct D2MissilesTxt;

struct D2SkillsTxt;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[20];
};

extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634

extern unsigned int gdwFadeTick_007C89CC; // 0x007C89CC

void __stdcall MISSTREAM_FreeMissileStream(D2UnitStrc* pMissile); // 0x00663D90

void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile); // 0x0064A150

void __stdcall sub_004DA080_FreeGfxMotion(D2UnitStrc* pUnit); // 0x004DA080

void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10

void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __fastcall sub_004CED60(D2UnitStrc* pMissile, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CED60

void __fastcall sub_004D85C0_SkillSeqDo0(D2UnitStrc* pUnit, int nArg); // 0x004D85C0

D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

struct D2CltMissileSpawnArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkill;
    int nSkillLevel;
    int nMaxCount;
    int nMissile;
};

struct D2AreaScanStrc
{
    int unk0x00;
    int nCount;
    D2CltMissileSpawnArgStrc* pArg;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CEF50

void __fastcall sub_004CEFE0_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nArg1, int nArg2, int nArg3); // 0x004CEFE0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit); // 0x00464810

void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

int __fastcall sub_004D01D0_CreateMissileFan(D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissile, int nSkill, int nSkillLevel, int nStep); // 0x004D01D0

extern const int gaRingOffsetY_006DB140[64]; // 0x006DB140

extern const int gaRingOffsetX_006DB240[64]; // 0x006DB240

extern const int gaRingOffsetY_006DB340[64]; // 0x006DB340

extern const int gaRingOffsetX_006DB440[64]; // 0x006DB440

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile); // 0x0064A730

extern "C" void __stdcall sub_006488A0(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3); // 0x00649970

enum
{
    CLTDO_TIMING_FRAME = 150,
    CLTDO_TIMING_ARG = 25,
    CLTDO_TIMING_LENGTH = 4000,
    CLTDO_SOUND_FRAME = 50,
    CLTDO_SOUND_ID = 0x121E,
    CLTDO_SLOW_FRAME = 8,
    CLTDO_SLOW_FLAG = 0x100,
    CLTDO_FAST_FRAME = 35,
};

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

#define TEST_OFFSET 0

#define LIGHT_LIMIT 60

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

struct D2GfxLightStrc;

struct D2UnitSfxNodeStrc;

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);

void __fastcall sub_004742D0_ResetLightSize(D2GfxLightStrc* pLight, int nSize);

int __fastcall sub_00474350_GetLightSize(D2GfxLightStrc* pLight);

void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce);

struct D2OwnerStrc_004CA990;

extern "C" void* __fastcall sub_004CA990_GetLinkFirst(D2OwnerStrc_004CA990* pOwner);

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                        // 0x0045C4B0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);         // 0x0064CB30

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

#define SPAWN_FLAGS 0x2001

#define COLLISION_MASK 0x45

typedef void (__fastcall* D2CltDoFunc)(D2UnitStrc* pMissile);

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

extern D2CltDoFunc gpfnCltDoFuncs_0072A398[];                                                               // 0x0072A398

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetXPosition(pUnit->pDynamicPath);
        return 0;
    }
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetYPosition(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x004CD170
void __fastcall sub_004CD170_FreeMissileUnit(D2UnitStrc* pMissile)
{
    MISSTREAM_FreeMissileStream(pMissile);
    MISSILE_FreeMissileData(pMissile);
    sub_004DA080_FreeGfxMotion(pMissile);
    sub_0046EC10_FreeGfxData(pMissile);
    if (gpAct_007A0634)
    {
        D2Common_10228(pMissile);
        UNITROOM_RemoveUnitFromRoom(pMissile);
    }
    PATH_FreeDynamicPath(0, pMissile->pDynamicPath);
    pMissile->pDynamicPath = 0;
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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
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
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004CE4B0
void __fastcall sub_004CE4B0_InitMotion(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->dwCltParam[1] > 0)
    {
        sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[0]);
        sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -pMissilesTxtRecord->dwCltParam[1], 1);
        const int nFrames = pMissilesTxtRecord->dwCltParam[0] / pMissilesTxtRecord->dwCltParam[1];
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
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

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x004CE650
void __fastcall sub_004CE650_SpawnScatterMissiles(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nCount)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(nMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nRange = 7 * nCount;
    const int nMissiles = nRange > 8 ? 8 : nRange;
    for (int i = 0; i < nMissiles; ++i)
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.pOwner = pOwner;
        tParams.pOrigin = pUnit;
        tParams.nSkill = MISSILE_GetSkill(pUnit);
        tParams.nSkillLevel = MISSILE_GetLevel(pUnit);
        tParams.nMissile = nMissile;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tParams);
        if (pMissile)
        {
            const int nX = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, nRange) - nRange / 2;
            const int nY = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, nRange) - nRange / 2;
            const int nZ = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, pMissilesTxtRecord->dwCltParam[1]);
            sub_004DA000_ResetGfxMotion(pMissile);
            sub_004DA1D0_SetMotionVectorA(pMissile, nX, nY, pMissilesTxtRecord->dwCltParam[0]);
            sub_004DA200_SetMotionVectorB(pMissile, 0, 0, nZ, 1);
            sub_004DA250(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[2], 1);
        }
    }
}

// 0x004CED20
void __fastcall sub_004CED20_SubmitWithDirection(D2UnitStrc* pMissile, int nMissile)
{
    D2UnitStrc* pNew = sub_004CDBA0_SubmitOwnerRequest(pMissile, nMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNew)
    {
        PATH_SetDirection(pNew->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
    }
}

// 0x004CEF50
void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult)
{
    sub_004CED60(pMissile, CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), nCount, nMissile, nSkill, nLevel, nPerStep, nMult);
}

// 0x004CF250
int __fastcall sub_004CF250_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    sub_004CEF50_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], MISSILE_FIREEXPLOSION2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwCltHitPar[1], 1);
    return 1;
}

// 0x004CF2B0
int __fastcall sub_004CF2B0_CltHitEffect(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const short nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
        if (nSubMissile >= 0)
        {
            sub_004CEFE0_AddMissileEffect(pMissile, nSubMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->dwCltHitPar[2]);
        }
    }
    return 1;
}

// 0x004CF300
int __fastcall sub_004CF300_CltHitTwoSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    sub_004CDBA0_SubmitOwnerRequest(pMissile, (short)pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if ((short)pMissilesTxtRecord->wCltHitSubMissile[1] < 0)
    {
        return 1;
    }

    int nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[1];
    if ((short)pMissilesTxtRecord->wCltHitSubMissile[2] > (short)pMissilesTxtRecord->wCltHitSubMissile[1])
    {
        nSubMissile = sub_004CC790_RollRange(&pMissile->pSeed, (short)pMissilesTxtRecord->wCltHitSubMissile[1], (short)pMissilesTxtRecord->wCltHitSubMissile[2]);
    }

    D2UnitStrc* pSubMissile = sub_004CDBA0_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pSubMissile)
    {
        sub_00464810_SetUnitFlag16(pSubMissile);
    }
    return 1;
}

// 0x004CFC80
int __fastcall sub_004CFC80_CltHitRandomSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && (short)pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        int nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
        if ((short)pMissilesTxtRecord->wCltHitSubMissile[1] > (short)pMissilesTxtRecord->wCltHitSubMissile[0])
        {
            const int nMax = (short)pMissilesTxtRecord->wCltHitSubMissile[1];
            if (nSubMissile < nMax)
            {
                nSubMissile += ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nSubMissile + 1);
            }
        }

        sub_004CDBA0_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }
    return 1;
}

// 0x004CFD00
int __fastcall sub_004CFD00_CltHitOwnerRequest(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    sub_004CDBA0_SubmitOwnerRequest(pMissile, (short)pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    return 0;
}

inline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D02E0
int __fastcall sub_004D02E0_HitForward(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        if (!pUnit)
        {
            pUnit = pMissile;
        }

        int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        if (nCount < 1)
        {
            nCount = 1;
        }

        sub_004D01D0_CreateMissileFan(pOwner, pUnit, pMissilesTxtRecord->wCltHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nCount);
        return 1;
    }

    return 1;
}

// 0x004D04D0
int __fastcall sub_004D04D0_HitRing64(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 2;
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];

            int nStep = pMissilesTxtRecord->dwCltHitPar[0];
            if (nStep < 1)
            {
                nStep = 1;
            }

            for (int i = 0; i < 64; i += nStep)
            {
                tMissileParams.nTargetX = gaRingOffsetX_006DB240[i];
                tMissileParams.nTargetY = gaRingOffsetY_006DB140[i];
                D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
                if (pSubMissile)
                {
                    MISSILE_SetTargetX(pSubMissile, gaRingOffsetX_006DB240[i]);
                    MISSILE_SetTargetY(pSubMissile, gaRingOffsetY_006DB140[i]);
                }
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D05E0
int __fastcall sub_004D05E0_HitRing64(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 2;
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];

            int nStep = pMissilesTxtRecord->dwCltHitPar[0];
            if (nStep < 1)
            {
                nStep = 1;
            }

            for (int i = 0; i < 64; i += nStep)
            {
                tMissileParams.nTargetX = gaRingOffsetX_006DB440[i];
                tMissileParams.nTargetY = gaRingOffsetY_006DB340[i];
                D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
                if (pSubMissile)
                {
                    MISSILE_SetTargetX(pSubMissile, gaRingOffsetX_006DB440[i]);
                    MISSILE_SetTargetY(pSubMissile, gaRingOffsetY_006DB340[i]);
                }
            }
        }

        return 1;
    }

    return 1;
}

struct D2UnitStrc;

// 0x004D07E0
int __fastcall sub_004D07E0_CltHitScatter(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0x102;
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = sub_0064A280(pMissile);

            const int nSpread = pMissilesTxtRecord->dwCltHitPar[0] < 3 ? 3 : pMissilesTxtRecord->dwCltHitPar[0];
            const int nCount = sub_0064A730_GetMissileTargetStatus(pMissile);
            for (int i = 0; i < nCount; ++i)
            {
                tMissileParams.nSkillLevel = SEED_RollRandomNumber(&pMissile->pSeed) % 5 + 1;
                const int nOffsetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
                tMissileParams.nTargetX = nOffsetX;
                const int nOffsetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
                tMissileParams.nTargetY = nOffsetY;
                if (!nOffsetX && !nOffsetY)
                {
                    tMissileParams.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nSpread) + 1;
                }
                sub_004CD540_CreateMissile(&tMissileParams);
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D09E0
int __fastcall sub_004D09E0_HitSubMissileOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pSubMissile = sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pSubMissile)
        {
            D2DynamicPathStrc* pPath = pSubMissile->pDynamicPath;
            sub_006488A0(pPath, PATH_GetDirection(pMissile->pDynamicPath));
            D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
            MISSILE_SetTargetX(pSubMissile, sub_0064A730_GetMissileTargetStatus(pMissile));
        }

        return 1;
    }

    return 1;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D2C10
int __fastcall sub_004D2C10_CltHitSubMissile(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            const short nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
            if (nSubMissile >= 0)
            {
                int nPar = pMissilesTxtRecord->dwCltHitPar[0];
                if (nPar < 1)
                {
                    nPar = 1;
                }

                sub_004CEFE0_AddMissileEffect(pMissile, nSubMissile, nPar, 2, 0);
            }
        }
    }

    return 1;
}



static void sub_004CD1C0_FlickerLight(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissile->nSeqCurrentFramePrecise & 0x300)
        return;
    D2GfxLightStrc* pLight = pMissile->pLight;
    if (!pLight)
        return;
    if (sub_00474350_GetLightSize(pLight) < pMissilesTxtRecord->nLight)
        return;
    sub_00474290(pLight, ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nFlicker) + pMissilesTxtRecord->nLight);
}

// 0x004D2C70
void __fastcall sub_004D2C70_CltDoMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    if (pMissilesTxtRecord->nFlicker)
        sub_004CD1C0_FlickerLight(pMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        pRoom = sub_00463740_FindRoomAtPoint(0, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[10 >> 3] & gdwBitMasks[10 & 7]) && DUNGEON_IsRoomInTown(pRoom))
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    const short nCltDoFunc = pMissilesTxtRecord->wCltDoFunc;
    if (nCltDoFunc > 0 && nCltDoFunc < gnCltDoFuncs_0072A34C)
        gpfnCltDoFuncs_0072A398[nCltDoFunc](pMissile);
}

// 0x004D55C0
void __fastcall sub_004D55C0_CltDoOwnerSkill(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (pOwner)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pOwner);
            if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, gszMissileSourceFile_006DAEF4, 2285) == MISSILE_GetSkill(pMissile))
            {
                if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
                {
                    sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
                }

                D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
                sub_004D30C0_CltDoCommon(pMissile);
                return;
            }
        }
    }

    sub_00465F00_RemoveClientUnit(UNITS_GetUnitIdInline(pMissile), UNITS_GetUnitTypeInline(pMissile));
}

// 0x004D5710
void __fastcall sub_004D5710_CltDoPerpendicular(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0 && pMissile->pDynamicPath)
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) < 2)
        {
            int nDX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath) - nX;
            int nDY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath) - nY;
            MISSILE_SetTargetX(pMissile, -nDY);
            MISSILE_SetTargetY(pMissile, nDX);
        }

        if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0xB;
            tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
            tMissileParams.nX = nX;
            tMissileParams.nY = nY;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            tMissileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];
            tMissileParams.nTargetX = MISSILE_GetTargetX(pMissile);
            tMissileParams.nTargetY = MISSILE_GetTargetY(pMissile);
            sub_004CD540_CreateMissile(&tMissileParams);
            tMissileParams.nTargetX = -MISSILE_GetTargetX(pMissile);
            tMissileParams.nTargetY = -MISSILE_GetTargetY(pMissile);
            sub_004CD540_CreateMissile(&tMissileParams);
        }

        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    sub_00465F00_RemoveClientUnit(UNITS_GetUnitIdInline(pMissile), UNITS_GetUnitTypeInline(pMissile));
}

// 0x004D59E0
void __fastcall sub_004D59E0_CltDoSeededSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pRecord || pRecord->wCltSubMissile[0] < 0) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
    if (!pSkill) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile),pSkill->dwCalc[0],nSkill,nLevel);
    int nPeriod = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile),pSkill->dwCalc[1],nSkill,nLevel);
    if (nPeriod < 1) nPeriod = 1;
    int nElapsed = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nElapsed % nPeriod != 0) {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed,CLIENTS_GetUnitX(pMissile)+nElapsed);
        --nRange;
        int nDoubleRange = 2*nRange;
        int nX = ITEMS_RollLimitedRandomNumber(pSeed,nDoubleRange)-nRange;
        nX += CLIENTS_GetUnitX(pMissile);
        int nY = ITEMS_RollLimitedRandomNumber(pSeed,nDoubleRange)-nRange;
        nY += CLIENTS_GetUnitY(pMissile);
        if (!COLLISION_CheckMask(pRoom,nX,nY,COLLISION_MASK)) {
            D2MissileStrc params;
            memset(&params,0,sizeof(params));
            params.dwFlags = SPAWN_FLAGS;
            params.pOwner = pOwner;
            params.nSkill = MISSILE_GetSkill(pMissile);
            params.nSkillLevel = MISSILE_GetLevel(pMissile);
            params.nMissile = pRecord->wCltSubMissile[0];
            params.nX = nX;
            params.nY = nY;
            D2UnitStrc* pSub = sub_004CD540_CreateMissile(&params);
            if (pSub) sub_00464810_SetUnitFlag16(pSub);
            if (pRecord->wCltSubMissile[1] >= 0) {
                params.nMissile = pRecord->wCltSubMissile[1];
                sub_004CD540_CreateMissile(&params);
            }
        }
    }
    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D6540
void __fastcall sub_004D6540_CltDoTimedSound(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    if (nFrames == CLTDO_TIMING_FRAME)
    {
        sub_00476A80_StartTiming(CLTDO_TIMING_ARG, 0, CLTDO_TIMING_LENGTH, 0);
    }
    else if (nFrames == CLTDO_SOUND_FRAME)
    {
        sub_004B9A00(CLTDO_SOUND_ID, 0, 0, 0, 0);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D6590
void __fastcall sub_004D6590_CltDoAnimSpeedSteps(D2UnitStrc* pMissile)
{
    switch (sub_0064A3B0_GetElapsedFrames(pMissile))
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D6660
void __fastcall sub_004D6660_CltDoClearFrameWithOwner(D2UnitStrc* pMissile)
{
    if (sub_004639D0_GetOwnerUnit(pMissile))
    {
        pMissile->nSeqCurrentFramePrecise = 0;
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D7FC0
void __fastcall sub_004D7FC0_CltDoZRange(D2UnitStrc* pMissile)
{
    const int nMin = -MISSILE_GetTargetX(pMissile);
    const int nMax = MISSILE_GetTargetY(pMissile);
    const int nZ = sub_004DA150_GetMotionAZ(pMissile);
    if (nZ >= nMin && nZ <= nMax)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    sub_004CD390_CltDoDefault(pMissile);
}

// 0x004D8650
void __fastcall sub_004D8650(D2UnitStrc* pUnit, int nArg)
{
    sub_004D85C0_SkillSeqDo0(pUnit, nArg);
}

// 0x004DA340
void __fastcall sub_004DA340(D2UnitStrc* pMissile)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pMissile);
    if (pMotion)
        pMotion->dwFlags &= ~2;
}

// 0x004DA6E0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bSet)
            pMotion->dwFlags |= 0x20;
        else
            pMotion->dwFlags &= ~0x20;
    }
}

// 0x004DB1A0
unsigned char __fastcall sub_004DB1A0(D2UnitStrc* pUnit, int nIndex)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
        return 0;
    return pGfxData->tEntries[nIndex].nValue;
}

// 0x004DBFE0
void __cdecl sub_004DBFE0_StopSkill()
{
    gdwFadeTick_007C89CC = GetTickCount() + 500;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004CD170.inc"
