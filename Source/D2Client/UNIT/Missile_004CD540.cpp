#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2Path.h"

extern D2DataTablesStrc* sgptDataTables_00744304; // 0x00744304

extern const unsigned char gbFlagMask_006CE270; // 0x006CE270

int __stdcall sub_0064A3E0(D2UnitStrc* pUnit); // 0x0064A3E0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

static int MISSILE_UseCharge(D2UnitStrc* pUnit); // 0x004CD310

struct D2GfxLightStrc;

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArgs);

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode);  // 0x00466730

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nMode, int nRadius, unsigned char nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x00474160

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, void* pArg);                                                // 0x004ADE80

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840

void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY);                      // 0x004C51E0

int __fastcall MISSILE_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                                 // 0x004CA900

void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000

void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350

void __fastcall SKILLS_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0

void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(void* pAct, int nX, int nY);                             // 0x00619DA0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame);       // 0x00626D40

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);                     // 0x006488A0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pDynamicPath, int nX, int nY);            // 0x00648AD0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pTargetUnit);                // 0x00648B90

void __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3);                  // 0x00649970

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner);                                  // 0x0064A400

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

static void __stdcall MISSILE_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile); // 0x004CD420

union D2SeedStrc;

struct D2MissilesTxt;

struct D2MissileStrc;

struct D2StaticPathStrc;

struct D2SpawnArgsStrc;

struct D2MissileScanArgStrc;

struct D2MissileScanStateStrc;

struct D2SkillsTxt;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

struct D2SpawnArgsStrc
{
    D2UnitStrc* pOwner;
    int nMissile;
};

static D2UnitStrc* __stdcall sub_004CE530_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile);

void __fastcall sub_004B9A00_PlayOverlay(int nOverlay, D2UnitStrc* pOwner, int a3, int a4, int a5); // 0x004B9A00

void __fastcall MISSILE_SpawnScatterMissiles(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSound, int nLevel); // 0x004CE650

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

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

void __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __fastcall MISSILE_CreateCallbackMissile(void* pArgument, D2UnitStrc* pUnit); // 0x004CFD70

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

int __stdcall sub_0064A730_GetTargetX(D2UnitStrc* pUnit); // 0x0064A730

int __stdcall sub_0064A780_GetTargetY(D2UnitStrc* pUnit); // 0x0064A780

extern int gnMissileTargetX_006DB100[]; // 0x006DB100

extern int gnMissileTargetY_006DB120[]; // 0x006DB120

int __stdcall MISSILE_GetSkill(D2UnitStrc*); // 0x0064A280

int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath); // 0x006487F0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

struct D2OwnerStrc_004CA990;

void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall PATH_SetMaxVelocity(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity); // 0x006486D0

void __stdcall PATH_SetAcceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration); // 0x00648700

void __stdcall sub_006488A0(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

void __stdcall PATH_SetTargetPos(D2DynamicPathStrc* pDynamicPath, int nX, int nY); // 0x00648AD0

void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pTargetUnit); // 0x00648B90

void __stdcall sub_0064A1E0_SetMissileLevel(D2UnitStrc* pMissile, int nSkillLevel); // 0x0064A1E0

int __stdcall sub_0064A300(D2UnitStrc* pMissile); // 0x0064A300

void __fastcall DLIGHTMAP_ResetLightSize(D2GfxLightStrc* pLight, int nSize); // 0x004742D0

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce); // 0x004BA790

extern "C" void* __fastcall ROSTER_GetLinkFirst(D2OwnerStrc_004CA990* pOwner); // 0x004CA990

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pMissile, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pMissile, int nX, int nY, int nZ, int nArg); // 0x004DA200

#define SUBMISSILE_ID 375

struct D2UnitStrc;

int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

int __stdcall sub_0064A3B0(D2UnitStrc* pMissile);                                                         // 0x0064A3B0

int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);                                    // 0x0064A730

int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);                                               // 0x0064A780


int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                          // 0x00650E50



struct D2CltSpreadStrc
{
    int nOffsetX;
    int nOffsetY;
    unsigned char nDirection;
    char pad0x09[3];
};

extern const D2CltSpreadStrc gaCltSpread_006DB7F0[7];                                                       // 0x006DB7F0

int __stdcall sub_0064A210_GetSkillLevel(D2UnitStrc* pUnit);                                                // 0x0064A210

int __stdcall sub_0064A280_GetSkill(D2UnitStrc* pUnit);                                                     // 0x0064A280

// build: context DATATBLS_GetMissilesTxtRecord
static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
	if (nMissileId >= 0 && nMissileId < sgptDataTables_00744304->nMissilesTxtRecordCount)
	{
		return &sgptDataTables_00744304->pMissilesTxt[nMissileId];
	}
	return 0;
}

// 0x004CD310
static int MISSILE_UseCharge(D2UnitStrc* pUnit)
{
	int nResult = 3;
	D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(sub_0064A3E0(pUnit));

	if (!(pMissilesTxtRecord->nMissileFlags[0] & gbFlagMask_006CE270))
	    return nResult;
		const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_PIERCE_IDX, 0);
		if (nValue)
		{
			nResult = 2;
			STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, nValue - 1, 0);
		}

	return nResult;
}

// build: context sub_004CD310_Shim

// calling-convention shim (not game code)
int __stdcall sub_004CD310_Shim(D2UnitStrc* pUnit)
{
	return MISSILE_UseCharge(pUnit);
}

static inline int MISSILE_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
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

static inline unsigned int sub_004CD420_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004CD420
static void __stdcall MISSILE_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
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

    int nChance = STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_PIERCE, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_PIERCE, 0);
    if (!nChance)
    {
        return;
    }

    D2SeedStrc tSeed;
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && sub_00463DD0_GetPlayerUnit() != pOwner)
    {
        nChance = 100;
        SEED_InitLowSeed(&tSeed, 0);
    }
    else
    {
        SEED_InitLowSeed(&tSeed, STATLIST_GetUnitBaseStat(pOwner, STAT_PIERCE_IDX, 0));
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

    STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, nPierce, 0);
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
            && !DUNGEON_FindRoomBySubtileCoordinates(gpGlobal_007A0634, nX, nY))
        {
            return 0;
        }
    }
    else
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && !COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pPlayer), nX, nY)
            && !DUNGEON_FindRoomBySubtileCoordinates(gpGlobal_007A0634, nX, nY))
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
        && STATES_CheckState(pMissileParams->pOwner, STATE_SLOWMISSILES))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pMissileParams->pOwner, STATE_SLOWMISSILES);
        if (pStatList)
        {
            nVelocityPercent = STATLIST_GetStatValue(pStatList, STAT_SKILL_HANDOFATHENA, 0);
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
                ITEM_GetAdjacentPosition(pMissileParams->pOwner, &nTargetX, &nTargetY);
            }
        }
        else if (pTarget && pMissileParams->pOwner && pTarget != pMissileParams->pOwner
            && CLIENTS_GetUnitX(pTarget) == CLIENTS_GetUnitX(pMissileParams->pOwner)
            && CLIENTS_GetUnitY(pTarget) == CLIENTS_GetUnitY(pMissileParams->pOwner))
        {
            ITEM_GetAdjacentPosition(pMissileParams->pOwner, &nTargetX, &nTargetY);
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

    D2UnitStrc* pMissile = CUNIT_SpawnPresetUnit(pMissileParams->nMissile, nX, nY, 3, 0);
    if (!pMissile)
    {
        return 0;
    }

    UNITS_SetAnimStartFrame(pMissile);
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

    PARTICLE_ResetGfxMotion(pMissile);
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
        SKILLS_SetBallistic(pMissile, pMissileParams->nGfxArg, MISSILE_GetTotalFrames(pMissile));
        sub_004DA350_UpdateMotion(pMissile);
        PATH_SetDirection(pPath, (unsigned char)(nTargetX + nTargetY) & ~0xC0);
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
    }

    MISSILE_SetSkill(pMissile, pMissileParams->nSkill);
    MISSILE_SetLevel(pMissile, pMissileParams->nSkillLevel);

    if (pMissileParams->pOwner)
    {
        UNITS_StoreOwner(pMissile, pMissileParams->pOwner);
        MISSILE_RollPierce(pMissileParams->pOwner, pMissile);
    }

    pMissile->dwFlags &= ~8;

    if (gnValue_0072A348 && !(pMissileParams->dwFlags & 0x4000))
    {
        if (pMissilesTxtRecord->nLight || (unsigned char)pMissileParams->nLightRadius)
        {
            CUNIT_FreeLight(pMissile);
            pMissile->pLight = sub_00474160_MakeLightEntry(pMissile, 1, pMissilesTxtRecord->nLight, 0xFF,
                pMissilesTxtRecord->nRed, pMissilesTxtRecord->nGreen, pMissilesTxtRecord->nBlue);
        }
    }
    else
    {
        CUNIT_FreeLight(pMissile);
    }

    if (pMissileParams->pInitFunc)
    {
        pMissileParams->pInitFunc(pMissile, pMissileParams->nInitArg);
    }

    if (pMissilesTxtRecord->wTravelSound)
    {
        const int nSound = (short)pMissilesTxtRecord->wTravelSound;
        if (nSound)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
            if (pMissileParams->pOwner)
            {
                const int nHandle = MISSILE_FindUnitSfxInRange(pMissileParams->pOwner, 0x13A);
                if (nHandle)
                {
                    sub_004BA840(nHandle);
                }
            }
        }
    }

    if (pMissileParams->pOwner)
    {
        MONSTER_RunUModMissileCallbacks(pMissileParams->pOwner, pMissile);
    }

    return pMissile;
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

static inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004CE140
void __fastcall MISSILE_SpawnRingAround(D2UnitStrc* pMissile, int nChance, int nCount, int nRange, int nMissile)
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
D2UnitStrc* __fastcall MISSILE_SpawnAtRandomUnitInRange(D2UnitStrc* pMissile, int nRange, int nFrequency, int nMissileId)
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

    return sub_004CD540_CreateMissile(&tMissileParams);
}

static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
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

static inline int UNITS_GetXPosition(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPosition(D2UnitStrc* pUnit)
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

static inline int RollOffset(D2UnitStrc* pUnit, int nRange)
{
    return ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRange / 2;
}

// 0x004CE850
void __fastcall MISSILE_SpawnPeriodicMissile(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissileId, int nFrame, int nLevel)
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

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        MISSILE_SpawnScatterMissiles(pOwner, pUnit, pMissilesTxtRecord->wCltSubMissile[0], nLevel);
    }

    if (pMissilesTxtRecord->wProgSound > 0 && nFrame == 315)
    {
        sub_004B9A00_PlayOverlay(pMissilesTxtRecord->wProgSound, pOwner, 0, 0, 0);
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
    sub_004CD540_CreateMissile(&missile);
}

// build: context DATATBLS_GetMissilesTxtRecordInline
static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x004CED60
void __fastcall MISSILE_CreateBurstAt(D2UnitStrc* pUnit, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissile);

    D2UnitStrc* pOwner = pUnit;
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
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

static inline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
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
int __fastcall MISSILE_CreateCallbackMissile(void* pArgument, D2UnitStrc* pUnit)
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

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004CFE30
int __fastcall MISSILE_ScanAreaCreateMissiles(D2UnitStrc* pMissile)
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
    sub_004C5C40_ScanArea(pOwner, nX, nY, nRange, nFlags, MISSILE_CreateCallbackMissile, &tArg, 1);

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

// 0x004D01D0
int __fastcall MISSILE_CreateMissileFan(D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissile, int nSkill, int nSkillLevel, int nStep)
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
    tMissile.nVelocity = pMissilesTxt->dwParam[0] << 7;

    for (int i = 0; i < 8; i += nStep)
    {
        tMissile.nTargetX = gnMissileTargetX_006DB100[i];
        tMissile.nTargetY = gnMissileTargetY_006DB120[i];
        sub_004CD540_CreateMissile(&tMissile);
    }

    return 1;
}

struct D2DynamicPathStrc;

static inline D2MissilesTxt* GetMissileRecord(int id) {
 if(id>=0 && id<sgptDataTables->nMissilesTxtRecordCount)
  return &sgptDataTables->pMissilesTxt[id];
 return 0;
}

static inline D2SkillsTxt* GetSkillRecord(int id) {
 if(id>=0 && id<sgptDataTables->nSkillsTxtRecordCount)
  return &sgptDataTables->pSkillsTxt[id];
 return 0;
}

// 0x004D0380
int __fastcall MISSILE_CreateChildMissile(D2UnitStrc* unit)
{
 D2MissilesTxt* missile=GetMissileRecord(unit ? unit->dwClassId : -1);
 if(!missile || missile->wCltHitSubMissile[0]<0)return 1;
 D2UnitStrc* owner=sub_004639D0_GetOwnerUnit(unit);
 if(!owner)return 1;
 int skillId=MISSILE_GetSkill(unit);
 int level=MISSILE_GetLevel(unit);
 D2SkillsTxt* skill=GetSkillRecord(skillId);
 if(!skill)return 1;
 int range=missile->dwCltHitPar[0];
 if(!range) {
  range=SKILLS_EvaluateSkillFormula(owner,skill->dwCalc[0],skillId,level);
  if(range<5)range=5;
 }
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.pOwner=owner;
 params.dwFlags=1;
 params.nMissile=missile->wCltHitSubMissile[0];
 params.nSkill=level;
 params.nSkillLevel=level;
 params.nX=CLIENTS_GetUnitX(unit);
 params.nY=CLIENTS_GetUnitY(unit);
 if(range>0) {params.dwFlags=0x8001;params.nRange=range;}
 D2UnitStrc* child=sub_004CD540_CreateMissile(&params);
 if(child) PATH_SetDirection(child->pDynamicPath,PATH_GetDirection(unit->pDynamicPath));
 return 1;
}

// 0x004D1820
int __fastcall MISSILE_SpawnOwnerSubMissile(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        D2MissileStrc params;
        memset(&params, 0, sizeof(params));
        params.pOwner = pOwner;
        params.pOrigin = pMissile;
        params.nMissile = SUBMISSILE_ID;
        params.nSkill = MISSILE_GetSkill(pMissile);
        params.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&params);
        if (pNew)
            MISSILE_SetTargetX(pNew, MISSILE_GetTargetX(pMissile));
    }
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
inline int MISSILE_GetApproxOffsetLengthInline(int nX, int nY)
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
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_HFFRAGMENT1);
    int aOffsetX[14] = { -4, 2, 4, -3, -2, 3, 5, -3, -5, 5, -6, -1, 0, 6 };
    int aOffsetY[14] = { 6, 4, -4, -2, 1, 7, 0, 3, -4, -3, 4, -5, 5, -3 };
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x8102;
    tParams.nMissile = MISSILE_HFFRAGMENT1;
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

// 0x004D3070
void __fastcall MISSILE_CltDoOwnerStep(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    if ((unsigned int)pOwner->dwUnitType <= UNIT_MONSTER && CUNIT_IsDeadOrDying(pOwner))
    {
        sub_004D2D70_CltMissileHit(pMissile, 0, 0);
        return;
    }
    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);
}

static int sub_004CC910_GetSpawnDelay(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < 125)
        return 25;
    if (nFrames < 175)
        return 10;
    return nFrames < 300 ? 3 : 15;
}

// 0x004D48B0
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

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4DC0
void __fastcall MISSILE_CltDoPickSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
    {
        const int nFrequency = pMissilesTxtRecord->dwCltParam[2] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[2];
        if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrequency)
        {
            MISSILE_CltDoCommon(pMissile);
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

        MISSILE_CltDoCommon(pMissile);
    }
    else
    {
        MISSILE_CltDoDefault(pMissile);
    }
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x004D4F20
void __fastcall MISSILE_CltDoSubMissileTimers(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
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

    MISSILE_CltDoCommon(pMissile);
}

static inline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D63E0
void __fastcall MISSILE_CltDoZigZag(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nUpdateInterval = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0(pMissile) % nUpdateInterval)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    if (!pSeed)
    {
        MISSILE_CltDoDefault(pMissile);
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

    PATH_SetTargetPos(pMissile->pDynamicPath, nNextOffsetX + CLIENTS_GetUnitX(pMissile), nNextOffsetY + CLIENTS_GetUnitY(pMissile));
    D2Common_10142(pMissile->pDynamicPath, pMissile, 0);

    MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
    const unsigned short nPackedOffsetX = (unsigned short)nNextOffsetX;
    const unsigned short nPackedOffsetY = (unsigned short)nNextOffsetY;
    MISSILE_SetTargetY(pMissile, nPackedOffsetX + (nPackedOffsetY << 16));

    MISSILE_CltDoCommon(pMissile);
}

static inline unsigned int SEED_RollUnitSeedInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollUnitSeedWideInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.lSeed = lSeed;

    return (unsigned int)lSeed;
}

// 0x004D6820
void __fastcall MISSILE_CltDoSpreadSpawn(D2UnitStrc* pMissile)
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
                missileParams.nMissile = MISSILE_HORADRICLIGHT;
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
        missileParams.nMissile = MISSILE_HORADRICLIGHTNING;
        pNew = sub_004CD540_CreateMissile(&missileParams);
        if (pNew)
        {
            GFXUTIL_SetMotionVectorA(pNew, 0, 0, 0x46);
            GFXUTIL_SetMotionVectorB(pNew, 0, 0, -1, 1);
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
        missileParams.nMissile = MISSILE_DUST;
        pNew = sub_004CD540_CreateMissile(&missileParams);
        if (pNew)
        {
            UNITS_SetAnimationSpeed(pNew, 0x40);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// build: symbol ?MISSILE_CltDoObjectRing@* 0x004D6680
void __fastcall MISSILE_CltDoObjectRing(D2UnitStrc* pMissile)
{
    const int nTargetUnitId = MISSILE_GetTargetX(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!CUNIT_FindClientUnit(nTargetUnitId, 2))
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    if (nFrames == 10)
    {
        sub_004D19D0_SpawnRing(nTargetUnitId, pMissile);
        sub_00476A80_StartTiming(nFrames - 6, nFrames + 0x46, 0x50, 0x190);
    }
    MISSILE_CltDoCommon(pMissile);
}

static inline int GetX(D2UnitStrc* pUnit)
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

static inline int GetY(D2UnitStrc* pUnit)
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

// 0x004D7880
void __fastcall MISSILE_CltDoRotateTarget(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDiffY = 0;
    const int nX = GetX(pUnit);
    const int nY = GetY(pUnit);
    const int nDiffX = nX - sub_0064A730_GetTargetX(pUnit);
    nDiffY = nY - sub_0064A780_GetTargetY(pUnit);
    D2COMMON_10170_PathSetTargetPos(pPath, nX + nDiffY, nY - nDiffX);
    D2Common_10142(pPath, pUnit, 0);
    MISSILE_CltDoCommon(pUnit);
}

#include "gen/data/Source/D2Client/UNIT/Missile_004CD540.inc"
