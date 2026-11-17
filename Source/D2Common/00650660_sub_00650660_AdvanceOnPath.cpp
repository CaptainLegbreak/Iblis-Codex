typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct D2UnitStrc;
struct D2DynamicPathStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

union D2FP32_16
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

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    D2DrlgCoordsStrc tCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
};

#pragma pack(push, 1)
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
    D2CoordStrc tDirectionVector;
    D2CoordStrc tVelocityVector;
    char padding0x7A[2];
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
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const D2CoordStrc gtPathZeroVelocity_006EB7D4;                                                              // 0x006EB7D4

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                         // 0x00641530
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY);                                                // 0x00643290
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
unsigned short __fastcall COLLISION_TryMoveUnitCollisionMask(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nUnitSize, int nCollisionMask, int nMoveConditionMask); // 0x0064ED20
unsigned short __fastcall COLLISION_TryTeleportUnitCollisionMask(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nCollisionPattern, int nFootprintCollisionMask, int nMoveConditionMask); // 0x0064EDA0
unsigned short __fastcall COLLISION_ForceTeleportUnitCollisionMaskAndGetCollision(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nUnitSize, int nFootprintCollisionMask, int nMoveConditionMask); // 0x0064EE70
unsigned short __fastcall COLLISION_TeleportUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nUnitSize, int nMask); // 0x0064EED0
int __fastcall COLLISION_TrySetUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nCollisionPattern, int nFootprintCollisionMask, int nMoveConditionMask); // 0x0064EF10
void __fastcall COLLISION_SetUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nCollisionPattern, int nCollisionMask); // 0x0064EFA0
void __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2);                                                     // 0x00650350
void __fastcall sub_6FDAB810(int* a1, int* a2);                                                              // 0x00678F00
void __fastcall sub_6FDAB940(D2PathPointStrc* pOutPathPoint, D2DynamicPathStrc* pPath);                     // 0x00679250

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

inline unsigned int PATH_ToFP16Center(unsigned int nValue)
{
    return (nValue << 16) + 0x8000;
}

inline unsigned int PATH_FP16FitToCenter(unsigned int nValue)
{
    return (nValue & 0xFFFF0000) + 0x8000;
}

inline D2FP32_16 PATH_MakeCoord(unsigned int nPrecisionX, unsigned int nPrecisionY)
{
    D2FP32_16 tCoord;
    tCoord.dwPrecisionX = nPrecisionX;
    tCoord.dwPrecisionY = nPrecisionY;
    return tCoord;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

inline BOOL PATH_IsZeroPoint(D2PathPointStrc tPoint)
{
    return tPoint.X == 0 && tPoint.Y == 0;
}

inline BOOL DUNGEON_TestRoomGame(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return nX >= pRoom->tCoords.nSubtileX && nX < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
        && nY >= pRoom->tCoords.nSubtileY && nY < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight;
}

inline void PATHMISC_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pNewRoom)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    pPath->pPreviousRoom = pPath->pRoom;
    if (pPath->pRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    pPath->dwFlags |= 2;
    pPath->pRoom = pNewRoom;
    if (pNewRoom)
    {
        UNITROOM_AddUnitToRoom(pUnit, pNewRoom);
        UNITROOM_RefreshUnit(pUnit);
    }
}

static __declspec(noinline) void __stdcall PATH_RecacheRoom(D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath)
{
    unsigned short nX = pPath->tGameCoords.wPosX;
    unsigned short nY = pPath->tGameCoords.wPosY;
    if (pPath->pRoom && DUNGEON_TestRoomGame(pPath->pRoom, nX, nY))
    {
        return;
    }

    D2ActiveRoomStrc* pRoomAtLocation = COLLISION_GetRoomBySubTileCoordinates(pPath->pRoom, nX, nY);
    if (!pRoomAtLocation && pHintRoom)
    {
        pRoomAtLocation = COLLISION_GetRoomBySubTileCoordinates(pHintRoom, nX, nY);
    }

    if (pRoomAtLocation || !(pPath->dwFlags & 0x40000))
    {
        PATHMISC_SetRoom(pPath, pRoomAtLocation);
    }
    else
    {
        pPath->dwPathPoints = 0;
    }
}

__declspec(noinline) static void __stdcall PATH_RecacheRoomAtCoordIfNeeded(D2FP32_16 tCoord, D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath); // 0x0064FB90

// build: context PATH_RecacheRoomAtCoordIfNeeded
static void __stdcall PATH_RecacheRoomAtCoordIfNeeded(D2FP32_16 tCoord, D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath)
{
    if ((pPath->dwFlags & 0x40000) && !COLLISION_GetRoomBySubTileCoordinates(pPath->pRoom, tCoord.dwPrecisionX >> 16, tCoord.dwPrecisionY >> 16))
    {
        pPath->dwPathPoints = 0;
        return;
    }

    pPath->tGameCoords.dwPrecisionX = tCoord.dwPrecisionX;
    pPath->tGameCoords.dwPrecisionY = tCoord.dwPrecisionY;

    int nX = tCoord.dwPrecisionX >> 11;
    int nY = tCoord.dwPrecisionY >> 11;
    DUNGEON_GameToClientCoords(&nX, &nY);
    pPath->dwClientCoordX = nX;
    pPath->dwClientCoordY = nY;

    if (pPath->pUnit && (pPath->dwFlags & 1))
    {
        PATH_RecacheRoom(pHintRoom, pPath);
    }
}

__declspec(noinline) static BOOL __stdcall sub_0064FF90_TestStepCollision(D2PathPointStrc tNext, D2PathPointStrc tCurrent, D2DynamicPathStrc* pPath);
// 0x0064FF90
static BOOL __stdcall sub_0064FF90_TestStepCollision(D2PathPointStrc tNext, D2PathPointStrc tCurrent, D2DynamicPathStrc* pPath)
{
    if (pPath->dwFlags & 4)
    {
        D2_ASSERT(sub_0044BE50(pPath->pUnit) == 0 || sub_0044BE50(pPath->pUnit) == 1, 0x209);
        COLLISION_SetUnitCollisionMask(pPath->pRoom, tCurrent.X, tCurrent.Y, pPath->pRoom, tNext.X, tNext.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        return 1;
    }

    const unsigned int bMissile = pPath->dwFlags & 0x40000;
    int nMoveTestCollisionMask = pPath->nMoveTestCollisionMask;
    if (nMoveTestCollisionMask == 0x3401)
    {
        nMoveTestCollisionMask = 0x3C01;
    }

    if (bMissile)
    {
        pPath->nCollidedWithMask |= COLLISION_TryMoveUnitCollisionMask(pPath->pRoom, tCurrent.X, tCurrent.Y, tNext.X, tNext.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask, nMoveTestCollisionMask);
    }
    else
    {
        pPath->nCollidedWithMask |= COLLISION_TryTeleportUnitCollisionMask(pPath->pRoom, tCurrent.X, tCurrent.Y, tNext.X, tNext.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask, nMoveTestCollisionMask);
    }

    const unsigned short nCollidedWithMask = pPath->nCollidedWithMask;
    if (nCollidedWithMask && !bMissile)
    {
        return FALSE;
    }

    if (bMissile && (nCollidedWithMask & 5))
    {
        return FALSE;
    }

    return 1;
}

static __declspec(noinline) BOOL __stdcall sub_00650090_GetStepToNextPoint(D2CoordStrc* pVelocity, D2DynamicPathStrc* pPath)
{
    *pVelocity = pPath->tVelocityVector;
    if (pPath->dwPathType == 4)
    {
        return FALSE;
    }

    D2CoordStrc tTarget;
    tTarget.nX = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].X);
    tTarget.nY = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].Y);
    const int nDeltaX = tTarget.nX - pPath->tGameCoords.dwPrecisionX;
    const int nAbsDeltaX = D2_ABS(nDeltaX);
    const int nAbsDeltaY = D2_ABS(tTarget.nY - (int)pPath->tGameCoords.dwPrecisionY);
    const int nMaxStep = D2_MAX(D2_ABS(pVelocity->nX), D2_ABS(pVelocity->nY));
    if (nAbsDeltaX > nMaxStep || nAbsDeltaY > nMaxStep)
    {
        return FALSE;
    }

    pVelocity->nX = nDeltaX;
    pVelocity->nY = tTarget.nY - pPath->tGameCoords.dwPrecisionY;
    return 1;
}

static __declspec(noinline) BOOL __stdcall sub_00650150_TraceSteps(int nDeltaX, int nDeltaY, D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tNext;
    D2PathPointStrc tCurrent;
    D2PathPointStrc tEnd;
    unsigned int bSaveSteps;
    int nStepY;
    int nStepX;

    pPath->nSavedStepsCount = 0;
    nStepX = nDeltaX;
    nStepY = nDeltaY;
    sub_6FDAB810(&nStepX, &nStepY);

    unsigned int dwX = pPath->tGameCoords.dwPrecisionX;
    unsigned int dwY = pPath->tGameCoords.dwPrecisionY;
    tCurrent.X = dwX >> 16;
    tCurrent.Y = dwY >> 16;

    const unsigned int dwEndX = dwX + nDeltaX;
    const unsigned int dwEndY = dwY + nDeltaY;
    tEnd.X = dwEndX >> 16;
    tEnd.Y = dwEndY >> 16;

    bSaveSteps = pPath->dwFlags & 0x20000;
    while (tCurrent.X != tEnd.X || tCurrent.Y != tEnd.Y)
    {
        const unsigned int dwNextX = dwX + nStepX;
        const unsigned int dwNextY = dwY + nStepY;
        tNext.X = dwNextX >> 16;
        tNext.Y = dwNextY >> 16;

        if (tCurrent.X != tNext.X || tCurrent.Y != tNext.Y)
        {
            if (!sub_0064FF90_TestStepCollision(tNext, tCurrent, pPath))
            {
                pOutCoord->dwPrecisionX = (dwX & 0xFFFF0000) + 0x8000;
                pOutCoord->dwPrecisionY = (dwY & 0xFFFF0000) + 0x8000;
                *pSteps = pPath->nSavedStepsCount;
                return TRUE;
            }

            if (bSaveSteps)
            {
                pPath->SavedSteps[pPath->nSavedStepsCount] = tNext;
            }

            ++pPath->nSavedStepsCount;
            if (pPath->nSavedStepsCount >= 10)
            {
                break;
            }
        }

        dwX = dwNextX;
        dwY = dwNextY;
        tCurrent = tNext;
    }

    if (pPath->nSavedStepsCount)
    {
        pPath->dwFlags |= 8;
    }

    pOutCoord->dwPrecisionX = dwEndX;
    pOutCoord->dwPrecisionY = dwEndY;
    *pSteps = pPath->nSavedStepsCount;
    return FALSE;
}

__declspec(noinline) static void sub_6FD5CEB0(int nBaseVelocity, D2DynamicPathStrc* pPath);
// 0x006502D0
static void sub_6FD5CEB0(int nBaseVelocity, D2DynamicPathStrc* pPath)
{
    if (nBaseVelocity <= 0)
    {
        nBaseVelocity = 0x400;
    }

    if (int nAcceleration = pPath->dwAcceleration)
    {
        pPath->dwAccelerationsCounter++;
        if (pPath->dwAccelerationsCounter >= 5)
        {
            pPath->dwVelocity = nAcceleration + pPath->dwVelocity;
            const int nMaxVelocity = pPath->dwMaxVelocity;
            if (pPath->dwVelocity > nMaxVelocity)
            {
                pPath->dwVelocity = nMaxVelocity;
                pPath->dwAcceleration = 0;
            }
            else if (pPath->dwVelocity < 0)
            {
                pPath->dwVelocity = 0;
            }

            pPath->dwAccelerationsCounter = 0;
        }
    }

    const int nVelocityMagnitude = (nBaseVelocity * pPath->dwVelocity) >> 6;
    pPath->tVelocityVector.nX = (nVelocityMagnitude * pPath->tDirectionVector.nX) >> 12;
    pPath->tVelocityVector.nY = (nVelocityMagnitude * pPath->tDirectionVector.nY) >> 12;
}

static __declspec(noinline) BOOL sub_6FD5DB70(D2DynamicPathStrc* pPath)
{
    switch (pPath->dwPathType)
    {
    case 5:
    case 6:
        if (pPath->dwCurrentPointIdx >= pPath->dwPathPoints)
        {
            return TRUE;
        }
        break;
    }

    D2UnitStrc* pTargetUnit = pPath->pTargetUnit;
    D2UnitStrc* pUnit = pPath->pUnit;
    if (!pTargetUnit)
    {
        D2PathPointStrc tPos;
        tPos.X = pPath->tGameCoords.wPosX;
        tPos.Y = pPath->tGameCoords.wPosY;
        if (pPath->dwCurrentPointIdx >= pPath->dwPathPoints && (tPos.X != pPath->tFinalTargetCoord.X || tPos.Y != pPath->tFinalTargetCoord.Y))
        {
            return D2Common_10236(pUnit, FALSE);
        }

        return TRUE;
    }

    if (D2Common_10399(pTargetUnit, pUnit) <= pPath->nStepNum)
    {
        return FALSE;
    }

    const unsigned short nPosX = pPath->tGameCoords.wPosX;
    const unsigned short nPosY = pPath->tGameCoords.wPosY;
    D2PathPointStrc tTargetPos;
    sub_6FDAB940(&tTargetPos, pPath);

    pTargetUnit = pPath->pTargetUnit;
    if (pTargetUnit && pTargetUnit->dwUnitType >= 0 && pTargetUnit->dwUnitType <= 1)
    {
        const int nDiffX = pPath->tPrevTargetCoord.X - tTargetPos.X;
        const int nDiffY = pPath->tPrevTargetCoord.Y - tTargetPos.Y;
        if (D2_ABS(nDiffX) > 5 || D2_ABS(nDiffY) > 5)
        {
            return D2Common_10236(pUnit, TRUE);
        }
    }

    if (pPath->dwCurrentPointIdx < pPath->dwPathPoints || (pPath->tFinalTargetCoord.X == nPosX && pPath->tFinalTargetCoord.Y == nPosY))
    {
        return TRUE;
    }

    return D2Common_10236(pUnit, TRUE);
}

// 0x00650590
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath)
{
    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionX), PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionY)), 0, pPath);
}

// 0x006505E0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit)
{
    D2_ASSERT(pRiderUnit, 0x54E);
    D2_ASSERT(pMountUnit, 0x54F);

    D2DynamicPathStrc* pRiderPath = pRiderUnit->pDynamicPath;
    D2DynamicPathStrc* pMountPath = pMountUnit->pDynamicPath;
    if (pRiderPath->tGameCoords.wPosX == pMountPath->tGameCoords.wPosX && pRiderPath->tGameCoords.wPosY == pMountPath->tGameCoords.wPosY)
    {
        pRiderPath->dwFlags &= 0xFFFFFFF7;
    }
    else
    {
        pRiderPath->dwFlags |= 8;
    }

    if (pRiderPath->pRoom != pMountPath->pRoom)
    {
        pRiderPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(pMountPath->tGameCoords, pMountPath->pRoom, pRiderPath);
}

__declspec(noinline) static BOOL __stdcall sub_00650660_AdvanceOnPath(D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath);
// 0x00650660
static BOOL __stdcall sub_00650660_AdvanceOnPath(D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    pPath->nCollidedWithMask = 0;
    *pSteps = 0;

    const BOOL bRepath = pUnit && pUnit->dwUnitType == 1 && (pPath->dwFlags & 0x10);
    if (!pPath->tVelocityVector.nX && !pPath->tVelocityVector.nY)
    {
        pPath->dwPathPoints = 0;
        pPath->dwCurrentPointIdx = 0;
        pOutCoord->dwPrecisionX = PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionX);
        pOutCoord->dwPrecisionY = PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionY);
        return FALSE;
    }

    D2CoordStrc tVelocity;
    const BOOL bReachedPoint = sub_00650090_GetStepToNextPoint(&tVelocity, pPath);
    const unsigned int nPrecX = pPath->tGameCoords.dwPrecisionX;
    const unsigned int nPrecY = pPath->tGameCoords.dwPrecisionY;
    D2FP32_16 tNewCoord;
    tNewCoord.dwPrecisionX = tVelocity.nX + nPrecX;
    tNewCoord.dwPrecisionY = tVelocity.nY + nPrecY;
    D2PathPointStrc tOld;
    tOld.X = nPrecX >> 16;
    tOld.Y = nPrecY >> 16;
    D2PathPointStrc tNew;
    tNew.X = tNewCoord.dwPrecisionX >> 16;
    tNew.Y = tNewCoord.dwPrecisionY >> 16;
    if (tOld.X != tNew.X || tOld.Y != tNew.Y)
    {
        if (pPath->nDist && pPath->dwPathType != 8 && pPath->dwPathType != 11)
        {
            --pPath->nDist;
        }

        if (sub_00650150_TraceSteps(tVelocity.nX, tVelocity.nY, pOutCoord, pSteps, pPath))
        {
            if (bRepath)
            {
                return !D2Common_10236(pUnit, pPath->pTargetUnit != 0);
            }

            pPath->dwCurrentPointIdx = pPath->dwPathPoints;
            return FALSE;
        }
    }

    *pOutCoord = tNewCoord;
    if (bReachedPoint)
    {
        ++pPath->dwCurrentPointIdx;
        return TRUE;
    }

    return FALSE;
}

static __declspec(noinline) void PATH_ResetMovement(D2DynamicPathStrc* pPath)
{
    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionX), PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionY)), 0, pPath);
    pPath->dwFlags &= 0xFFFFFFDF;
    pPath->dwPathPoints = 0;
    pPath->dwCurrentPointIdx = 0;
    pPath->tVelocityVector = gtPathZeroVelocity_006EB7D4;
}

// build: context sub_00650800_CheckPathMoving
D2DynamicPathStrc* __fastcall sub_00650800_CheckPathMoving(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    pPath->dwFlags &= 0xFFFFFFF7;
    if (pPath->dwFlags & 0x40000)
    {
        pPath->nCollidedWithMask = 0;
    }

    if ((pPath->dwFlags & 0x20) && pPath->dwPathPoints > 0 && pPath->dwVelocity)
    {
        return pPath;
    }

    PATH_ResetMovement(pPath);
    return 0;
}

BOOL __stdcall D2Common_10226(D2UnitStrc* pUnit, int nBaseVelocity)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return FALSE;
    }

    pPath->dwFlags &= 0xFFFFFFF7;
    const unsigned int dwFlags = pPath->dwFlags;
    if (dwFlags & 0x40000)
    {
        pPath->nCollidedWithMask = 0;
    }

    if ((dwFlags & 0x20) && pPath->dwPathPoints > 0 && pPath->dwVelocity)
    {
        if (((dwFlags & 0x40000) || sub_6FD5DB70(pPath)) && pPath->dwCurrentPointIdx < pPath->dwPathPoints)
        {
            sub_6FD5CEB0(nBaseVelocity, pPath);
            if (pPath->tVelocityVector.nX || pPath->tVelocityVector.nY)
            {
                int nSteps;
                D2FP32_16 tCoord;
                sub_00650660_AdvanceOnPath(&tCoord, &nSteps, pPath);
                PATH_RecacheRoomAtCoordIfNeeded(tCoord, 0, pPath);
                if (pPath->dwPathType != 4 && pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                {
                    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, 1, 1);
                }

                if (pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                {
                    return 1;
                }
            }
        }
    }

    PATH_ResetMovement(pPath);
    return FALSE;
}

__declspec(noinline) static BOOL __stdcall sub_6FDAD5E0(D2ActiveRoomStrc* pDestRoom, D2PathPointStrc tDest, D2DynamicPathStrc* pPath); // 0x00650910

// build: context sub_6FDAD5E0
static BOOL __stdcall sub_6FDAD5E0(D2ActiveRoomStrc* pDestRoom, D2PathPointStrc tDest, D2DynamicPathStrc* pPath)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    if (pUnit && pUnit->dwUnitType == 3)
    {
        if (PATH_IsZeroPoint(tDest))
        {
            COLLISION_ResetMaskWithSize(pPath->pRoom, pPath->tGameCoords.wPosX, pPath->tGameCoords.wPosY, pPath->dwUnitSize, pPath->nFootprintCollisionMask);
            pPath->nCollidedWithMask = 0;
        }
        else
        {
            D2PathPointStrc tPathPos;
            tPathPos.X = pPath->tGameCoords.wPosX;
            tPathPos.Y = pPath->tGameCoords.wPosY;
            if (tPathPos.X == tDest.X && tPathPos.Y == tDest.Y)
            {
                pPath->dwFlags &= 0xFFFFFFF7;
            }
            else
            {
                pPath->dwFlags |= 8;
            }

            pPath->nCollidedWithMask = COLLISION_ForceTeleportUnitCollisionMaskAndGetCollision(pPath->pRoom, tPathPos.X, tPathPos.Y, pDestRoom, tDest.X, tDest.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask, pPath->nMoveTestCollisionMask);
            pPath->nSavedStepsCount = 1;
            pPath->SavedSteps[0] = tDest;
        }
    }
    else
    {
        D2PathPointStrc tPathPos;
        tPathPos.X = pPath->tGameCoords.wPosX;
        tPathPos.Y = pPath->tGameCoords.wPosY;
        if (!tDest.X && !tDest.Y)
        {
            COLLISION_ResetMaskWithPattern(pPath->pRoom, tPathPos.X, tPathPos.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_SetUnitCollisionMask(pPath->pRoom, tPathPos.X, tPathPos.Y, pDestRoom, tDest.X, tDest.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
    }

    if (pPath->pRoom != pDestRoom)
    {
        pPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_ToFP16Center(tDest.X), PATH_ToFP16Center(tDest.Y)), pDestRoom, pPath);
    D2_ASSERT((!tDest.X && !tDest.Y) || COLLISION_GetRoomBySubTileCoordinates(pDestRoom, tDest.X, tDest.Y), 0x489);
    PATH_ResetMovement(pPath);
    return 1;
}

__declspec(noinline) static BOOL __stdcall D2Common_10231_Impl(D2ActiveRoomStrc* pRoomDest, D2PathPointStrc tDest, D2DynamicPathStrc* pPath); // 0x00650AA0

// build: context D2Common_10231_Impl
static BOOL __stdcall D2Common_10231_Impl(D2ActiveRoomStrc* pRoomDest, D2PathPointStrc tDest, D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tCurrentPos;
    tCurrentPos.X = pPath->tGameCoords.wPosX;
    tCurrentPos.Y = pPath->tGameCoords.wPosY;
    if (pPath->pUnit && pPath->pUnit->dwUnitType == 3)
    {
        if (PATH_IsZeroPoint(tDest))
        {
            COLLISION_ResetMaskWithSize(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_TeleportUnitCollisionMask(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pRoomDest, tDest.X, tDest.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask);
        }
    }
    else
    {
        if (!tDest.X && !tDest.Y)
        {
            COLLISION_ResetMaskWithPattern(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_SetUnitCollisionMask(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pRoomDest, tDest.X, tDest.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
    }

    if (pPath->pRoom != pRoomDest)
    {
        pPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_ToFP16Center(tDest.X), PATH_ToFP16Center(tDest.Y)), pRoomDest, pPath);
    D2_ASSERT((!tDest.X && !tDest.Y) || COLLISION_GetRoomBySubTileCoordinates(pRoomDest, tDest.X, tDest.Y), 0x4CC);
    PATH_ResetMovement(pPath);
    return 1;
}

// 0x00650BE0
BOOL __stdcall D2Common_10229(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pDestRoom, unsigned int nDestX, unsigned int nDestY)
{
    D2PathPointStrc tCoords;
    tCoords.X = (unsigned short)nDestX;
    tCoords.Y = (unsigned short)nDestY;
    const BOOL bResult = sub_6FDAD5E0(pDestRoom, tCoords, pDynamicPath);
    if (!bResult)
    {
        return bResult;
    }

    pDynamicPath->dwPathPoints = 0;
    return 1;
}

// 0x00650C20
int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY)
{
    D2PathPointStrc tDest;
    tDest.X = nX;
    tDest.Y = nY;
    D2Common_10231_Impl(pRooms, tDest, pDynamicPath);
    pDynamicPath->dwPathPoints = 0;
    return 1;
}

// 0x00650C60
BOOL __stdcall D2Common_10230(D2DynamicPathStrc* pDynamicPath, int a2, D2ActiveRoomStrc* pRoom, unsigned int a4, short a5)
{
    D2PathPointStrc tPos;
    tPos.X = (unsigned short)a4;
    tPos.Y = a5;
    const BOOL bResult = sub_6FDAD5E0(pRoom, tPos, pDynamicPath);
    if (!bResult)
    {
        return bResult;
    }

    pDynamicPath->unk0x38 = 15;
    return 1;
}

// build: context D2Common_10232
BOOL __stdcall D2Common_10232(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pDestRoom, int nTargetX, int nTargetY)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    D2_ASSERT(nUnitType == 0 || nUnitType == 1, 0x50D);

    if (COLLISION_TrySetUnitCollisionMask(pPath->pRoom, pPath->tGameCoords.wPosX, pPath->tGameCoords.wPosY, pDestRoom, nTargetX, nTargetY, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask, pPath->nMoveTestCollisionMask))
    {
        return FALSE;
    }

    if (pPath->pRoom != pDestRoom)
    {
        pPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_ToFP16Center(nTargetX), PATH_ToFP16Center(nTargetY)), pDestRoom, pPath);
    D2_ASSERT(COLLISION_GetRoomBySubTileCoordinates(pDestRoom, nTargetX, nTargetY), 0x524);
    PATH_ResetMovement(pPath);
    return 1;
}
