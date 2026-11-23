#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2ClientGame.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNITFLAGEX_0x40000 0x40000
#define PATHTYPE_CHARGEDBOLT 10
struct D2TimedHintEntryStrc;
struct D2UnitSfxNodeStrc;
struct D2MonSoundsTxt;
struct D2UnitSndPlayerStrc;
struct D2UnitSndObjectStrc;
struct D2SuperUniquesTxt;
struct D2MonStatsTxt;
struct D2DirRateStrc;
struct D2SkillsTxt;
struct D2TimedHintNodeStrc;
struct D2StaticPathStrc;
struct D2DrlgCoordsStrc;
struct D2TileLibraryEntryStrc;
struct T00481920;
union D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct T00481920
{
    int unk0x00[7];
    int nMaterial1;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __cdecl UI_ClearGlobals(); // 0x00476AF0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004CC7C0
int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxt = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    if (nLevel <= 0)
        return 0;
    return pSkillsTxt->dwParam[2] + (nLevel - 1) * pSkillsTxt->dwParam[3];
}

#include "gen/data/Source/D2Client/Unknown_004CC790.inc"

// 0x004CC800
static int __stdcall sub_004CC800_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

// 0x004CCF20
void __fastcall sub_004CCF20_SetValue(int nValue)
{
// build: symbol ?gbMissileLights@* 0x0072A348
    gbMissileLights = nValue;
}

int __stdcall sub_M119_Emit_004CC800(D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY, int nMaxDistanceSq, int nX, int nY)
{
    return sub_004CC800_CheckDistanceAndLineOfSight(nMaxDistanceSq, nX, nY, pRoom, nOffsetX, nOffsetY);
}

// 0x004CC790
int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin >= nMax)
        return nMin;

    return ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1) + nMin;
}

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x004CC9A0
int __fastcall sub_004CC9A0_CltHitProgOverlay(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit && pMissile)
    {
        D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            const short nOverlay = pMissilesTxtRecord->wProgOverlay;
            if (nOverlay > 0)
                GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
        }
    }
    return 1;
}

// 0x004CCCA0
int __fastcall sub_004CCCA0_CltHitFlagOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
        pOwner->dwFlagEx |= UNITFLAGEX_0x40000;
    return 1;
}

// 0x004CCCC0
void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused)
{
    if (!pMissile)
        return;

    const int nRange = MISSILE_GetTotalFrames(pMissile) > 255 ? 255 : MISSILE_GetTotalFrames(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath));
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nRange);
    D2Common_10142(pPath, pMissile, 0);
}

// 0x004CCF00
int __fastcall sub_004CCF00_CltHitClearGlobals(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        UI_ClearGlobals();
        return 1;
    }
    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004CC910
static int sub_004CC910_GetSpawnDelay(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < 125)
        return 25;
    if (nFrames < 175)
        return 10;
    return nFrames < 300 ? 3 : 15;
}

// build: symbol ?MISSILE_CltDoDelayedSpawn@* 0x004D48B0
void __fastcall MISSILE_CltDoDelayedSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
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
            const int nRange = pMissilesTxtRecord->dwCltParam[0];
            int nX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1) - nRange;
            missileParams.nTargetX = nX;
            int nY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1) - pMissilesTxtRecord->dwCltParam[0];
            missileParams.nTargetY = nY;
            if (!nX && !nY)
            {
                nX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->dwCltParam[0]) + 1;
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

    MISSILE_CltDoCommon(pMissile);
}
