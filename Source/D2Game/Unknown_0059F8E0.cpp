#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
union D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileUnitFindTableStrc;

void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile); // 0x0064A150
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

typedef void(__fastcall* MISSILEINITFUNC)(D2UnitStrc* pMissile, int nInitArg);

extern "C" D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2MissileUnitFindTableStrc gtMissileCollisionModes[]; // 0x0073C720
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc* pUnit, int a2); // 0x00535D10
void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc* pUnit, int a2); // 0x00535E20
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall sub_005A43B0_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile); // 0x005A43B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame); // 0x00626D40
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648CE0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

// 0x0059F8E0
void __fastcall MISSILES_Free(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    MISSILE_FreeMissileData(pMissile);
    sub_6FC349F0(pGame, pMissile);
}

static __forceinline unsigned int MISSILES_RollPierceSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0059F900
static __declspec(noinline) void __stdcall sub_0059F900_ApplyMissileDamage(D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel, D2UnitStrc* pOwner)
{
    D2MissileDamageDataStrc tDamage;

    PLAYER_ApplyWeaponStatsForSkill(pOwner, 0);
    MISSILE_CalculateDamageData(&tDamage, pOwner, pOrigin, pMissile, nLevel);
    MISSILE_SetDamageStats(pOwner, pMissile, &tDamage, nLevel);
    PLAYER_RestoreWeaponStats(pOwner, 0);
}

static __declspec(noinline) void __stdcall sub_0059F940_RollMissilePierce(D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    if (!pOwner || !pMissile || pMissile->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    if (pOwner->dwUnitType != UNIT_PLAYER && pOwner->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pMissile->dwClassId);
    if (!MISSILE_FLAGBIT(pMissilesTxtRecord, 2))
    {
        return;
    }

    const int nPierceValue = STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0);
    if (!nPierceValue)
    {
        return;
    }

    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, STATLIST_GetUnitBaseStat(pOwner, 0x148, 0));

    int nPierceIndex = 0;
    while (nPierceIndex < 4 && (int)(MISSILES_RollPierceSeed_Inline(&tSeed) % 100) < nPierceValue)
    {
        ++nPierceIndex;
    }

    STATLIST_SetUnitStat(pMissile, 0x148, nPierceIndex, 0);
}

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams)
{
    int nX;
    int nY;

    if (!pMissileParams->pOwner)
    {
        return 0;
    }

    if (pMissileParams->nMissile < 0 || pMissileParams->nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pMissileParams->pOwner->dwUnitType != UNIT_PLAYER && pMissileParams->pOwner->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pMissileParams->nMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

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

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pMissileParams->pOwner), nX, nY);
    if (!pRoom)
    {
        return 0;
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

    int nVelocity;
    if (pMissileParams->dwFlags & 4)
    {
        if (pMissileParams->dwFlags & 0x10)
        {
            nVelocity = pMissileParams->nVelocity;
        }
        else
        {
            nVelocity = pMissileParams->nVelocity << 8;
        }
    }
    else
    {
        nVelocity = (pMissilesTxtRecord->nVel + pMissileParams->nSkillLevel * pMissilesTxtRecord->nVelLev / 8) << 8;
    }

    if (MISSILE_FLAGBIT(pMissilesTxtRecord, 3) && STATES_CheckState(pMissileParams->pOwner, 0x57))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pMissileParams->pOwner, 0x57);
        if (pStatList)
        {
            nVelocity = STATLIST_GetStatValue(pStatList, 0xA1, 0) * nVelocity / 100;
        }
    }

    if (nVelocity)
    {
        nVelocity = 75 * nVelocity / 100;
    }

    D2UnitStrc* pTarget = pMissileParams->pTarget;
    if (nVelocity)
    {
        if (!pTarget)
        {
            if (nTargetX == nX && nTargetY == nY)
            {
                ++nTargetX;
                ++nTargetY;
            }
        }
        else if (pTarget != pMissileParams->pOwner
            && CLIENTS_GetUnitX(pTarget) == CLIENTS_GetUnitX(pMissileParams->pOwner)
            && CLIENTS_GetUnitY(pTarget) == CLIENTS_GetUnitY(pMissileParams->pOwner))
        {
            pTarget = 0;
            ++nTargetX;
            ++nTargetY;
        }

        int nDestX = nTargetX;
        int nDestY = nTargetY;
        if (pTarget)
        {
            nDestX = CLIENTS_GetUnitX(pTarget);
            nDestY = CLIENTS_GetUnitY(pTarget);
        }

        int nXDiff = nDestX - nX;
        if (nXDiff < 0)
        {
            nXDiff = -nXDiff;
        }

        if (nXDiff >= 100)
        {
            return 0;
        }

        int nYDiff = nDestY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff >= 100)
        {
            return 0;
        }
    }

    D2UnitStrc* pMissile = SUNIT_AllocUnitData(3, pMissileParams->nMissile, nX, nY, pGame, pRoom, 1, pMissilesTxtRecord->nCollideType, 0);
    if (!pMissile)
    {
        return 0;
    }

    int nRange;
    if (pMissileParams->dwFlags & 0x8000)
    {
        nRange = pMissileParams->nRange;
    }
    else
    {
        nRange = pMissilesTxtRecord->wRange + pMissileParams->nSkillLevel * pMissilesTxtRecord->wLevRange;
        if ((pMissileParams->dwFlags & 8) && pMissilesTxtRecord->nSubLoop)
        {
            nRange += pMissileParams->nLoops * (pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart);
        }
    }

    if (pMissileParams->dwFlags & 0x200)
    {
        nRange -= pMissileParams->nFrame;
        pMissile->nSeqCurrentFramePrecise = pMissileParams->nFrame << 8;
    }

    MISSILE_SetTotalFrames(pMissile, nRange);
    MISSILE_SetCurrentFrame(pMissile, nRange);

    int nActivateFrame;
    if (pMissileParams->dwFlags & 0x800)
    {
        nActivateFrame = pMissileParams->nActivateFrame;
    }
    else
    {
        nActivateFrame = pMissilesTxtRecord->nActivate;
    }
    MISSILE_SetActivateFrame(pMissile, nRange - nActivateFrame);

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    PATH_SetVelocity(pPath, 0, gszMissilesCppFile_006E2150, 0x18E);

    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pPath, nTargetX, nTargetY);
    }

    if (pMissilesTxtRecord->nCollision)
    {
        PATH_SetFootprintCollisionMask(pPath, 0x40);
    }
    else
    {
        PATH_SetFootprintCollisionMask(pPath, 0);
    }
    PATH_SetMoveTestCollisionMask(pPath, gtMissileCollisionModes[pMissilesTxtRecord->nCollideType].nCollisionMask);

    if (MISSILE_FLAGBIT(pMissilesTxtRecord, 4))
    {
        pMissile->dwFlags |= 4;
    }

    if (nVelocity)
    {
        PATH_SetVelocity(pPath, nVelocity, gszMissilesCppFile_006E2150, 0x1AA);
        D2Common_10142(pPath, pMissile, 0);
    }

    MISSILE_SetOwner(pMissile, pMissileParams->pOwner);
    PATH_SetAcceleration(pPath, pMissilesTxtRecord->wAccel);
    PATH_SetMaxVelocity(pPath, pMissilesTxtRecord->nMaxVel << 8);

    if (pMissileParams->dwFlags & 0x400)
    {
        int nDistance = sub_006417F0_GetDistanceToXY(pMissile, nTargetX, nTargetY);
        if (!nDistance)
        {
            nDistance = 1;
        }

        const unsigned int nStep = 16 * nVelocity;
        unsigned int nCurrentFrame = 0;
        if (nStep)
        {
            nCurrentFrame = (unsigned int)(nDistance << 16) / nStep;
        }

        MISSILE_SetCurrentFrame(pMissile, nCurrentFrame);
    }

    STATLIST_AllocStatListEx(pMissile, 0, 0, 0);

    if (pMissileParams->pInitFunc)
    {
        pMissileParams->pInitFunc(pMissile, pMissileParams->nInitArg);
    }

    MISSILE_SetSkill(pMissile, pMissileParams->nSkill);
    MISSILE_SetLevel(pMissile, pMissileParams->nSkillLevel);

    sub_0059F900_ApplyMissileDamage(pMissileParams->pOrigin, pMissile, pMissileParams->nSkillLevel, pMissileParams->pOwner);

    UNITS_StoreOwner(pMissile, pMissileParams->pOwner);
    pMissile->dwFlags &= ~8;

    sub_0059F940_RollMissilePierce(pMissile, pMissileParams->pOwner);

    if (pMissileParams->dwFlags & 0x1000)
    {
        STATLIST_SetUnitStat(pMissile, 0x13, pMissileParams->nAttBonus, 0);
    }

    if (pMissileParams->dwFlags & 0x10000)
    {
        MISSILE_SetFlags(pMissile, MISSILE_GetFlags(pMissile) | 2);
    }

    sub_005A43B0_OwnerMissileHook(pGame, pMissileParams->pOwner, pMissile);
    STATLIST_SetUnitStat(pMissile, 0x147, pMissilesTxtRecord->nMissileStatValue, 0);
    return pMissile;
}

#include "gen/data/Source/D2Game/Unknown_0059F8E0.inc"
