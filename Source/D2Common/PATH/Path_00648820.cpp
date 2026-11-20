#include "D2Common.h"
#include "D2Structs.h"

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2FP32_16
{
    union
    {
        struct
        {
            unsigned short wOffsetX;
            unsigned short wPosX;
            unsigned short wOffsetY;
            unsigned short wPosY;
        };
        struct
        {
            unsigned int dwPrecisionX;
            unsigned int dwPrecisionY;
        };
    };
};

struct D2DynamicPathStrc
{
    D2FP32_16 tGameCoords;
    int dwClientCoordX;
    int dwClientCoordY;
    D2PathPointStrc tTargetCoord;
    D2PathPointStrc tPrevTargetCoord;
    D2PathPointStrc tFinalTargetCoord;
    D2ActiveRoomStrc* pRoom;
    D2ActiveRoomStrc* pPreviousRoom;
    int dwCurrentPointIdx;
    int dwPathPoints;
    void* unk0x2C;
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
    unsigned int unk0x38;
    unsigned int dwPathType;
    unsigned int dwPrevPathType;
    unsigned int dwUnitSize;
    unsigned int dwCollisionPattern;
    unsigned int nFootprintCollisionMask;
    unsigned int nMoveTestCollisionMask;
    unsigned short nCollidedWithMask;
    unsigned short padding0x56;
    D2UnitStrc* pTargetUnit;
    unsigned int dwTargetType;
    unsigned int dwTargetId;
    unsigned char nDirection;
    unsigned char nNewDirection;
    unsigned char nDiffDirection;
    unsigned char unk0x67;
    unsigned char dwSpeed;
    unsigned char unk0x69;
    char unk0x6A[0x12];
    int dwVelocity;
    unsigned int nPreviousVelocity;
    int dwMaxVelocity;
    int dwAcceleration;
    int dwAccelerationsCounter;
    unsigned char nDist;
    unsigned char nDistMax;
    unsigned char nIDAStarInitFScore;
    unsigned char nStepNum;
    unsigned char nDistance;
    char padding0x95[3];
    int nDirOffset;
    D2PathPointStrc PathPoints[78];
    int nSavedStepsCount;
    D2PathPointStrc SavedSteps[10];
};


#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TYPES_COUNT 6
#define PATH_NB_DIRECTIONS 64
#define PATHTYPE_IDASTAR 0
#define PATH_CURRENT_ROOM_INVALID 0x00002
#define PATH_UNUSED_FLAG_0x00004 0x00004
#define PATH_UNKNOWN_FLAG_0x00040 0x00040
#define PATH_SAVE_STEPS_MASK 0x20000

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize);                        // 0x00648580
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit);                                        // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EA00
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

// 0x00648820
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection)
{
    D2_ASSERT(nDirection < PATH_NB_DIRECTIONS, 1650);

    const unsigned char nNormalizedDirection = nDirection & (PATH_NB_DIRECTIONS - 1);
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = UNIT_TYPES_COUNT;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        pDynamicPath->nDirection = nNormalizedDirection;
        break;
    case UNIT_MISSILE:
        if (!(pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00040))
        {
            pDynamicPath->nDirection = nNormalizedDirection;
        }
        break;
    default:
        if (nNormalizedDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nNormalizedDirection;
            const unsigned char nDiff = nNormalizedDirection - pDynamicPath->nDirection;
            pDynamicPath->nDiffDirection = gnDirectionDiffTable_006EB548[nDiff & (PATH_NB_DIRECTIONS - 1)];
        }
        break;
    }
}

// 0x006488C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath, 1682);

    return pDynamicPath->tGameCoords.wPosX;
}

// 0x00648900
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath, 1693);

    return pDynamicPath->tGameCoords.wPosY;
}

// 0x00648940
int __stdcall PATH_GetPrecisionX(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath, 1704);

    return pDynamicPath->tGameCoords.dwPrecisionX;
}

// 0x00648970
int __stdcall PATH_GetPrecisionY(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath, 1715);

    return pDynamicPath->tGameCoords.dwPrecisionY;
}

// 0x006489B0
void __stdcall PATH_SetPrecisionY(D2DynamicPathStrc* pDynamicPath, int nPrecisionY)
{
    pDynamicPath->tGameCoords.dwPrecisionY = nPrecisionY;
}

// 0x00648A90
void __stdcall PATH_SetRoom(D2DynamicPathStrc* pDynamicPath, D2ActiveRoomStrc* pRoom)
{
    pDynamicPath->pRoom = pRoom;
}

// 0x00648B30
int __stdcall PATH_IsCurrentRoomInvalid(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwFlags & PATH_CURRENT_ROOM_INVALID;
}

// 0x00648B60
void __stdcall PATH_SetUnusedFlag_0x00004(D2DynamicPathStrc* pDynamicPath, int bSet)
{
    if (bSet)
    {
        pDynamicPath->dwFlags |= PATH_UNUSED_FLAG_0x00004;
    }
    else
    {
        pDynamicPath->dwFlags &= ~PATH_UNUSED_FLAG_0x00004;
    }
}

// 0x00648B80
int __stdcall PATH_GetUnusedFlag_0x00004(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwFlags & PATH_UNUSED_FLAG_0x00004;
}

// 0x00648BB0
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pDynamicPath, int* pTargetType, int* pTargetGUID)
{
    D2_ASSERT(pDynamicPath->pTargetUnit, 1984);

    *pTargetType = pDynamicPath->dwTargetType;
    *pTargetGUID = pDynamicPath->dwTargetId;
}

// 0x00648C30
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask)
{
    D2PathPointStrc tPosition;
    tPosition.X = pDynamicPath->tGameCoords.wPosX;
    tPosition.Y = pDynamicPath->tGameCoords.wPosY;

    if (pDynamicPath->pRoom)
    {
        if (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MISSILE)
        {
            COLLISION_ResetMaskWithSize(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwUnitSize, pDynamicPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_ResetMaskWithPattern(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwCollisionPattern, pDynamicPath->nFootprintCollisionMask);
        }
    }

    pDynamicPath->nFootprintCollisionMask = nCollisionMask;

    if (pDynamicPath->pRoom)
    {
        if (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MISSILE)
        {
            COLLISION_SetMaskWithSize(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwUnitSize, nCollisionMask);
        }
        else
        {
            COLLISION_SetMaskWithPattern(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwCollisionPattern, nCollisionMask);
        }
    }
}

// 0x00648CE0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask)
{
    pDynamicPath->nMoveTestCollisionMask = nCollisionMask;
}

// 0x00648E60
unsigned char __stdcall D2COMMON_10191_PATH_GetDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nDist;
}

// 0x00648EA0
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nDistMax;
}

// 0x00648EF0
unsigned short __stdcall D2Common_10202(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nCollidedWithMask;
}

// 0x00648F00
void __stdcall PATH_SetIDAStarInitFScore(D2DynamicPathStrc* pDynamicPath, int nIDAStarInitFScore)
{
    D2_ASSERT(pDynamicPath->dwPathType == PATHTYPE_IDASTAR, 2280);

    pDynamicPath->nIDAStarInitFScore = nIDAStarInitFScore;
}

// 0x00648F40
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints)
{
    D2_ASSERT(pDynamicPath->dwFlags & PATH_SAVE_STEPS_MASK, 2292);

    *ppPathPoints = pDynamicPath->SavedSteps;
    return pDynamicPath->nSavedStepsCount;
}

// 0x00648F90
int __stdcall D2COMMON_10199_PathGetSaveX(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath->dwFlags & PATH_SAVE_STEPS_MASK, 2306);

    if (pDynamicPath->nSavedStepsCount)
    {
        return pDynamicPath->SavedSteps[pDynamicPath->nSavedStepsCount - 1].X;
    }

    return 0;
}

// 0x00648FE0
int __stdcall D2COMMON_10200_PathGetSaveY(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath->dwFlags & PATH_SAVE_STEPS_MASK, 2321);

    if (pDynamicPath->nSavedStepsCount)
    {
        return pDynamicPath->SavedSteps[pDynamicPath->nSavedStepsCount - 1].Y;
    }

    return 0;
}

// 0x00649030
void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pDynamicPath, int bReset)
{
    if (pDynamicPath)
    {
        if (!bReset)
        {
            pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00040;
        }
        else
        {
            pDynamicPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00040;
        }
    }
}

// 0x006490C0
void __stdcall D2Common_10207(D2DynamicPathStrc* pDynamicPath, char a2, char a3)
{
    pDynamicPath->unk0x67 = a2;
    pDynamicPath->dwSpeed = a3;
}

// 0x006490E0
void __stdcall PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, int nDist)
{
    D2_ASSERT(nDist >= 0 && nDist <= 255, 2405);

    pDynamicPath->nDistance = nDist;
}

// 0x00649140
void __stdcall PATH_AddToDistance(D2DynamicPathStrc* pDynamicPath, int nAddition)
{
    const int nDistance = pDynamicPath->nDistance + nAddition;
    if (nDistance < 0)
    {
        pDynamicPath->nDistance = 0;
    }
    else if (nDistance > 255)
    {
        pDynamicPath->nDistance = 255;
    }
    else
    {
        pDynamicPath->nDistance = nDistance;
    }
}

// 0x00649180
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit)
{
    return pUnit->pDynamicPath->dwCollisionPattern;
}

// 0x006491B0
void __stdcall D2COMMON_10212_PATH_SetMoveFlags(D2UnitStrc* pUnit, int bSet)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;

    D2_ASSERT(pDynamicPath, 2466);

    if (bSet)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_UNK_PATH_RELATED;
    }
    else
    {
        pUnit->dwFlagEx &= ~UNITFLAGEX_UNK_PATH_RELATED;
    }
    pDynamicPath->unk0x38 = 0;
}

// 0x006492C0
int __stdcall D2Common_10237(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->dwCurrentPointIdx < pDynamicPath->dwPathPoints;
}

// 0x00649CA0
void __stdcall D2Common_10214(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (pDynamicPath)
    {
        if (UNITS_GetRoom(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            pUnit->pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);
            PATH_AddCollisionFootprintForUnit(pUnit);
        }
        else
        {
            pUnit->pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);
        }
    }
}

// 0x00649F50
void __stdcall D2Common_10228(D2UnitStrc* pUnit)
{
    if (pUnit->pDynamicPath)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
    }
}

// 0x0064A0E0
void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
}
