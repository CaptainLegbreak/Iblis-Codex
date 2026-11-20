#include "D2Game.h"

#define D2_ASSERT(expr,line) if(!(expr)) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1); }
struct D2MonsterDataStrc;
struct D2StaticPathStrc;
struct D2NearestRecord005DC870Strc;
struct UnkAiStrc5;
struct D2SeedStrc;
struct D2UnkAiCallbackArgStrc2;
struct D2AiCallback7ArgStrc;
struct D2AiCallback11ArgStrc;
struct D2UbersAiCallbackArgStrc;
struct Obj005DD220;
struct Obj005DD230;
struct D2MonStatsTxt;

struct D2MonsterDataStrc
{
    char unk0x00[0x50];
    int pVision;
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
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x8];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    unsigned char unk_30[0x94];
    unsigned int dwFlags;
    unsigned char unk_C8[0x20];
    D2UnitStrc* pRoomNext;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

enum D2C_Y10AiUtilConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
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
    };
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380

struct D2NearestRecord005DC870Strc
{
    D2UnitStrc* pNearest;
    int nBestDistance;
    int nCount;
    int nMaxDistance;
};

int __fastcall sub_00554200_CheckTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

enum D2C_P11AiUtilConstants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONMODE_DEATH = 0,
};

struct UnkAiStrc5
{
    unsigned int nMaxDistance;
};

struct D2UnkAiCallbackArgStrc2
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* pAlternativeTarget;
    int nAlternativeDistance;
};

struct D2AiCallback7ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* unk0x08;
};

struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit);
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0

struct D2AiCallback11ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* unk0x08;
};

int __fastcall sub_6FCF14D0(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005DC640

struct D2UbersAiCallbackArgStrc
{
    int nUberMephisto;
    int nUberDiablo;
    int nUberBaal;
    int nDistance;
    int nOtherMonsters;
    int nDiabloSpawner;
    int nBaalMinions;
    int nDiabloMinions;
};

struct Obj005DD220 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned short wFlags08; };

struct Obj005DD230 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned short wFlags08;
};

struct D2MonStatsTxt { short nId,nBaseId; char unk04[0x1A4]; };

struct D2DataTablesStrc { char unk00[0xA78]; D2MonStatsTxt* pMonStatsTxt; int unkA7C; int nMonStatsTxtRecordCount; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc*,int,int); // 0x00463740

// 0x005DC360
int __fastcall sub_005DC360_GetMonsterVision(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pVision;
    }
    return 0;
}

// 0x005DC840
int __fastcall sub_005DC840_IsActiveUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    switch (pUnit->dwUnitType)
    {
    case 0:
    case 1:
        return !SUNIT_IsDead(pUnit);
    case 3:
        return 1;
    }
    return 0;
}

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DC640
int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || !pTarget)
    {
        return 0;
    }

    unsigned char aSteps[25] = { 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    int nStep;
    if (nDistance >= 25)
    {
        nStep = 3;
    }
    else
    {
        nStep = aSteps[nDistance];
    }

    const unsigned int nTargetX = CLIENTS_GetUnitX(pTarget);
    const unsigned int nTargetY = CLIENTS_GetUnitY(pTarget);
    int nX = CLIENTS_GetUnitX(pUnit) - nTargetX;
    int nY = CLIENTS_GetUnitY(pUnit) - nTargetY;

    if (nX < 0)
    {
        nX = -nStep;
    }
    else if (nX > 0)
    {
        nX = nStep;
    }

    if (nY < 0)
    {
        nY = -nStep;
    }
    else if (nY > 0)
    {
        nY = nStep;
    }

    if (!UNITS_TestCollisionByCoordinates(pUnit, nTargetX, nTargetY, 0x805))
    {
        return 1;
    }

    if (!UNITS_TestCollisionByCoordinates(pUnit, nTargetX - nY, nTargetY + nX, 0x805))
    {
        return 1;
    }

    return !UNITS_TestCollisionByCoordinates(pUnit, nTargetX + nY, nTargetY - nX, 0x805);
}

// 0x005DC870
int __fastcall sub_005DC870_FindNearestMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2NearestRecord005DC870Strc* pRecord)
{
    if (pUnit == pTarget)
    {
        return 0;
    }
    if (!pTarget)
    {
        return 0;
    }
    const int nUnitType = pTarget ? pTarget->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }
    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance >= pRecord->nMaxDistance)
    {
        return 0;
    }
    if (sub_00554200_CheckTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }
    ++pRecord->nCount;
    if (nDistance < pRecord->nBestDistance)
    {
        pRecord->nBestDistance = nDistance;
        pRecord->pNearest = pTarget;
    }
    return 0;
}

// 0x005DC8E0
D2UnitStrc* __fastcall sub_6FCF1740(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    UnkAiStrc5* pArg = (UnkAiStrc5*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != MONMODE_DEATH)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit) < pArg->nMaxDistance ? pTarget : 0;
}

// 0x005DC970
static int __stdcall sub_6FCF1A50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1 || !pTarget || pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) || !sub_00451F30_TestUnitFlag(pTarget, 4))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, 0x92))
    {
        switch (pTarget->dwUnitType)
        {
        case 0:
            if ((int)SEED_RollLimitedRandomNumber(&pTarget->pSeed, 100) < 80 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                return 0;
            }
            break;
        case 1:
            if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                return 0;
            }
            break;
        }
    }

    return sub_00554200(pGame, pUnit, pTarget);
}

// 0x005DCBD0
D2UnitStrc* __fastcall sub_6FCF1980(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2UnkAiCallbackArgStrc2* pArg = (D2UnkAiCallbackArgStrc2*)pCallbackArg;

    if (!sub_6FCF1A50(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    const int nThreat = sub_005DC920_GetThreat(pTarget);
    if (nThreat > 1)
    {
        if (nDistance >= pArg->nDistance)
        {
            return 0;
        }
    }
    else if (nDistance >= pArg->nAlternativeDistance)
    {
        return 0;
    }

    if (!UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        if (nThreat > 1)
        {
            pArg->pTarget = pTarget;
            pArg->nDistance = nDistance;
        }
        else
        {
            pArg->pAlternativeTarget = pTarget;
            pArg->nAlternativeDistance = nDistance;
        }
    }

    return 0;
}

// 0x005DCC60
D2UnitStrc* __fastcall sub_6FCF1B30(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiCallback7ArgStrc* pArg = (D2AiCallback7ArgStrc*)pCallbackArg;

    if (pTarget == pArg->unk0x08)
    {
        return 0;
    }

    if (!sub_6FCF1A50(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    if (sub_005DC920_GetThreat(pTarget) > 1 && nDistance < pArg->nDistance && !UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }

    return 0;
}

static __forceinline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

// 0x005DCCC0
D2UnitStrc* __fastcall sub_6FCF1BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiCallback11ArgStrc* pArg = (D2AiCallback11ArgStrc*)pCallbackArg;

    if (pTarget == pArg->unk0x08 || !pTarget || pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || !UNITS_CanBeAttackedInline(pTarget) || !sub_00554200(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    if (sub_005DC920_GetThreat(pTarget) > 1 && nDistance < pArg->nDistance && sub_6FCF14D0(pUnit, pTarget))
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }

    return 0;
}

// 0x005DD140
D2UnitStrc* __fastcall AIUTIL_TargetCallback_Ubers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2UbersAiCallbackArgStrc* pArg = (D2UbersAiCallbackArgStrc*)pCallbackArg;

    if (pTarget
        && (!pTarget ? 6 : pTarget->dwUnitType) == 1
        && !SUNIT_IsDead(pTarget))
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
        if (nDistance > pArg->nDistance)
        {
            return 0;
        }

        const int nClassId = pTarget->dwClassId;
        if (nClassId == 704)
        {
            pArg->nUberMephisto++;
            return 0;
        }
        if (nClassId == 705)
        {
            pArg->nUberDiablo++;
            return 0;
        }
        if (nClassId == 709)
        {
            pArg->nUberBaal++;
            return 0;
        }
        if (nClassId == 711)
        {
            pArg->nDiabloSpawner++;
            return 0;
        }
        if (nClassId == 712)
        {
            pArg->nDiabloMinions++;
            return 0;
        }
        if (nClassId == 732 || nClassId == 731 || nClassId == 733)
        {
            pArg->nBaalMinions++;
            return 0;
        }
        pArg->nOtherMonsters++;
    }

    return 0;
}

// 0x005DD220
extern "C" __declspec(dllexport) int __fastcall sub_005DD220(Obj005DD220* pObj, unsigned short wMask) {
    return (pObj->wFlags08 & wMask) != 0;
}

// 0x005DD230
extern "C" __declspec(dllexport) void __fastcall sub_005DD230(Obj005DD230* pObj, unsigned short wMask, int bSet) {
    if (bSet) {
        pObj->wFlags08 |= wMask;
    } else {
        pObj->wFlags08 &= ~wMask;
    }
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }

    return pMonStatsTxtRecord->nBaseId;
}

static __forceinline int CLIENTS_GetUnitXForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitYForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DD370
D2UnitStrc* __fastcall sub_005DD370_FindMonsterAtCoords(D2GameStrc* game,D2ActiveRoomStrc* room,int x,int y,int baseId)
{
 D2_ASSERT(room,1954);
 room=D2GAME_GetRoom_6FC52070(room,x,y);
 D2_ASSERT(room,1956);
 for(D2UnitStrc* unit=room->pUnitFirst;unit;unit=unit->pRoomNext) {
  if((!unit ? 6 : unit->dwUnitType)!=1) continue;
  int nBase = MONSTERS_GetBaseIdFromMonsterId(unit->dwClassId);

  if (unit->dwClassId) { if (nBase != baseId) continue; } else { if (nBase != baseId) continue; }
  if (CLIENTS_GetUnitXForceInline(unit)==x && CLIENTS_GetUnitYForceInline(unit)==y) return unit;
 }
 return 0;
}
