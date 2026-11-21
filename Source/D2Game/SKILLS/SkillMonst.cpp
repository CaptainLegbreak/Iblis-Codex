#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

#define STAT_HITPOINTS 6

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MissilesTxt;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2MissileStrc;

struct D2DamageStrc;

enum D2C_M54SkillMonstConstants
{
    PATHTYPE_ASTAR = 1,
    PATHTYPE_TOWARD = 2,
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x005CC440

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170

unsigned short __fastcall sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

int __stdcall SKILLS_GetElementalLength(D2UnitStrc*, int, int, int); // 0x00644F20

void __stdcall UNITS_SetOverlay(D2UnitStrc*, int, int); // 0x00621E40

static int __stdcall sub_005CC2E0_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel);

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId);

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId);

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_TYPES 6

#define MONMODE_SEQUENCE 14

#define COLLIDE_MASK_PLAYER_PATH 0x1C09

union D2SeedStrc;

struct D2ModeChangeStrc;

enum D2C_J10SkillMonstConstants
{
    UNITFLAG_SKSRVDOFUNC = 0x00000040,
};

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960

int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2); // 0x005FD7B0

int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

__forceinline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
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

__forceinline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
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

// 0x005CB270
int __fastcall SKILLS_SrvSt45_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetUnitXPositionInline(pUnit), UNITS_GetUnitYPositionInline(pUnit), 5, 0x1000);
    return 1;
}

// 0x005CB4D0
int __fastcall SKILLS_SrvSt46_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, UNITS_GetUnitXPositionInline(pTarget));
    SKILLS_SetParam2(pSkill, UNITS_GetUnitYPositionInline(pTarget));
    return 1;
}

// 0x005CBBF0
int __fastcall SKILLS_SrvSt48_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    PATH_SetNewDistance(pDynamicPath, 5);

    PATH_SetType(pDynamicPath, PATHTYPE_TOWARD);
    D2Common_10142(pDynamicPath, pUnit, 0);
    if (!PATH_GetNumberOfPathPoints(pDynamicPath))
    {
        PATH_SetType(pDynamicPath, PATHTYPE_ASTAR);
        D2Common_10142(pDynamicPath, pUnit, 0);
        if (!PATH_GetNumberOfPathPoints(pDynamicPath))
        {
            return 0;
        }
    }

    SKILLS_SetFlags(pSkill, 1);
    return 1;
}

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

// build: context SKILLS_Abs
static int SKILLS_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x005CC050
int __fastcall sub_005CC050_PlaceSkillMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nUnitX = CLIENTS_GetUnitX(pUnit);
    const int nUnitY = CLIENTS_GetUnitY(pUnit);

    int nY = nTargetY;
    int nX = nTargetX;
    int i = 4;
    if (SKILLS_Abs(nTargetX - nUnitX) < SKILLS_Abs(nTargetY - nUnitY))
    {
        nX = nUnitX;
        do
        {
            if (nX > nTargetX)
            {
                --nX;
            }
            else if (nX < nTargetX)
            {
                ++nX;
            }
        }
        while (--i > 0);
    }
    else
    {
        nY = nUnitY;
        do
        {
            if (nY > nTargetY)
            {
                --nY;
            }
            else if (nY < nTargetY)
            {
                ++nY;
            }
        }
        while (--i > 0);
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    const int nDX = nX - nUnitX;
    const int nDY = nY - nUnitY;
    missileParams.nX = nUnitX + nDX / 6 - 1;
    missileParams.nY = nUnitY + nDY / 6 - 1;
    missileParams.nSkill = nSkillId;
    missileParams.dwFlags = 3;
    missileParams.nTargetX = nDX;
    missileParams.nTargetY = nDY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005CC1D0
int __fastcall SKILLS_SrvSt51_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    return 1;
}

// 0x005CC220
int __fastcall sub_005CC220_SetUnitFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x0E;
    }
    return 1;
}

// 0x005CC2E0
static int __stdcall sub_005CC2E0_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(!pMissile ? -1 : pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nFrame <= 0)
    {
        nFrame = pMissilesTxtRecord->dwParam[1] + nSkillLevel - 1;
    }

    nFrame = D2_MIN(D2_MAX(nFrame, 1), 0xFF);
    PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
    sub_00621780_SetMissileArg(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nFrame);
    MISSILE_SetTotalFrames(pMissile, nFrame);
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
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

__forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x005CC3B0
static int sub_005CC3B0_EndInfernoAnim(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nAnimLength = 11;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            nAnimLength = pMonStats2TxtRecord->nInfernoLen;
        }
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
    EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + nAnimLength, 0, 0);
    return 1;
}

// 0x005CC4E0
int __fastcall SKILLS_SrvDo095_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(nMissile);
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        sub_005CC3B0_EndInfernoAnim(pGame, pUnit);
        return 0;
    }

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        sub_005CC3B0_EndInfernoAnim(pGame, pUnit);
        return 0;
    }

    sub_005CC2E0_UpdateInfernoAnimationParameters(pUnit, pMissile, nSkillId, nSkillLevel);
    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, 12))
    {
        int nAnimLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (nAnimLength < 1)
        {
            nAnimLength = 1;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + nAnimLength, 0, 0);
    }
    else
    {
        sub_005CC3B0_EndInfernoAnim(pGame, pUnit);
    }

    return 1;
}

// 0x005CC690
int __fastcall SKILLS_SrvDo152_DiabLight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(nMissile);
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        sub_005CC3B0_EndInfernoAnim(pGame, pUnit);
        return 0;
    }

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        sub_005CC3B0_EndInfernoAnim(pGame, pUnit);
        return 0;
    }

    sub_005CC2E0_UpdateInfernoAnimationParameters(pUnit, pMissile, nSkillId, nSkillLevel);
    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, 12))
    {
        int nAnimLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (nAnimLength < 1)
        {
            nAnimLength = 1;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + nAnimLength, 0, 0);
    }
    else
    {
        sub_005CC3B0_EndInfernoAnim(pGame, pUnit);
    }

    return 1;
}

// 0x005CC840
int __fastcall SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nMaxRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nMax = D2_MIN(D2_MAX(nMaxRaw, 0), 100);

    const int nMinRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMin = D2_MIN(D2_MAX(nMinRaw, 0), nMax);

    const int nPercentage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin) + nMin;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget);
    int nNewHp = DATATBLS_ApplyRatio(nMaxHp, nPercentage, 100) + STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    nNewHp = D2_MIN(D2_MAX(nNewHp, 1), nMaxHp);
    STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nNewHp, 0);
    return 1;
}

// 0x005CCB10
int __fastcall SKILLS_SrvDo097_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!MONSTERS_IsDead(pTarget) || STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pTarget);
    const int nY = CLIENTS_GetUnitY(pTarget);
    const int nUnitType = pTarget->dwUnitType;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pTarget);
    if (COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, nCollisionPattern, nUnitType != UNIT_PLAYER ? COLLIDE_MASK_MONSTER_PATH : COLLIDE_MASK_PLAYER_PATH))
    {
        return 0;
    }

    sub_00648B90_SetPathTarget(pUnit->pDynamicPath, pTarget);
    SKILLS_ResurrectUnit(pGame, pTarget);

    const int nTargetType = pTarget ? pTarget->dwUnitType : UNIT_TYPES;
    if (nTargetType == UNIT_MONSTER)
    {
        const int nMode = MONSTERSPAWN_GetResurrectMode(pTarget, 1);
        D2ModeChangeStrc tModeChange;
        MONSTERMODE_GetModeChangeInfo(pTarget, nMode, &tModeChange);
        MONSTERSPAWN_GetResurrectMode(pTarget, 1);
        D2GAME_ModeChange_6FC65220(pGame, &tModeChange, nMode != MONMODE_SEQUENCE);
    }

    if (pSkillsTxtRecord->wSrvOverlay >= 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
    }

    return 1;
}

// 0x005CCE80
int __fastcall sub_005CCE80_ApplyFreezingSkillDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DamageStrc damage;
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        memset(&damage, 0, sizeof(damage));
        damage.wResultFlags |= 1;
        damage.wResultFlags |= *(unsigned short*)&pSkillsTxt->wResultFlags;
        damage.dwHitFlags |= pSkillsTxt->dwHitFlags;
        if (pSkillsTxt->dwHitClass)
            damage.dwHitClass = pSkillsTxt->dwHitClass;
        damage.dwFrzLen = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
        if (!STATLIST_UnitGetStatValue(pTarget, 6, 0))
            damage.wResultFlags |= 2;
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
        if (pSkillsTxt->wSrvOverlay > 0 && pSkillsTxt->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
            UNITS_SetOverlay(pTarget, pSkillsTxt->wSrvOverlay, 0);
    }
    return 1;
}

// 0x005CCFA0
int __fastcall SKILLS_SrvDo101_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissile;
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        missileParams.nTargetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        missileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - CLIENTS_GetUnitX(pUnit);
        missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return pMissilesTxtRecord ? 1 : 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

// 0x005CD2C0
int __fastcall SKILLS_SrvSt54_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0);
    SKILLS_SetParam1(pSkill, sub_00451F50(pTarget));
    const int nTargetType = sub_0044BE50(pTarget);
    SKILLS_SetParam2(pSkill, nTargetType);
    PATH_SetTargetUnit(pUnit->pDynamicPath, 0);
    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, CLIENTS_GetUnitXInline(pTarget), CLIENTS_GetUnitYInline(pTarget));
    return 1;
}

// 0x005CD380
int __fastcall SKILLS_SrvDo103_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[0] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[1]);
        return 1;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    if (nFrame == pSkillsTxtRecord->dwParam[2])
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath)
        {
            return 0;
        }

        int nBaseVelocity = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) << 8;
        if (nBaseVelocity <= 256)
        {
            nBaseVelocity = 256;
        }

        const int nVelocityPct = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        PATH_SetVelocity(pPath, DATATBLS_ApplyRatio(nBaseVelocity, nVelocityPct, 100), ".\\SKILLS\\SkillMonst.cpp", 1841);
        PATH_SetType(pPath, PATHTYPE_ASTAR);
        D2Common_10142(pPath, pUnit, 0);
        SKILLS_SetFlags(pSkill, 1);
        return 1;
    }

    if (nFrame == pSkillsTxtRecord->dwParam[3])
    {
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[4] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[5]);
        return 1;
    }

    if (pUnit->nActionFrame == 1)
    {
        D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), SKILLS_GetParam1(pSkill));
        if (pTarget)
        {
            if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                D2DamageStrc damage;
                pUnit->nActionFrame = 0;
                memset(&damage, 0, sizeof(damage));
                sub_6FD155E0(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);

                if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
                {
                    damage.dwHitFlags = pSkillsTxtRecord->dwHitFlags | 0x20;
                    if (pSkillsTxtRecord->dwHitClass)
                    {
                        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
                    }

                    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
                    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
                    SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);

                    if (!STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0))
                    {
                        damage.wResultFlags |= 2u;
                    }

                    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
                }
            }
        }
    }

    return 1;
}
