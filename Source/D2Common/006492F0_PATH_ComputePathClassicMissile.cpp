typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_NONE 6

#define PATHTYPE_MISSILE 4
#define PATHTYPE_CHARGEDBOLT 10
#define PATHTYPE_BLESSEDHAMMER 14

#define PATH_UNKNOWN_FLAG_0x00010 0x00010
#define PATH_UNKNOWN_FLAG_0x00020 0x00020
#define PATH_UNKNOWN_FLAG_0x00800 0x00800
#define PATH_UNKNOWN_FLAG_0x01000 0x01000
#define PATH_MISSILE_MASK 0x40000

#define PATH_MAX_DISTANCE 100
#define PATH_SNAP_RANGE 5
#define PATH_DIR_NULL 0xFF
#define PATH_TRUE 1
#define PATH_ONE 1

#define LINE_PREPARE_MISSILE 0xC7
#define LINE_NOT_MISSILE_PATH 0x207
#define LINE_DOOR 0x215
#define LINE_PATH_UNIT 0x2E8
#define LINE_PATH_FUNCTION 0x37E
#define LINE_START_COORD 0x389

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

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
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

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    char unk0x04[0x08];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc tSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned short field_16;
    int nDistMax;
    unsigned char nMinimumFScoreToEvaluate;
    unsigned char field_1D;
    unsigned short field_1E;
    int nPathType;
    int nUnitSize;
    int nCollisionPattern;
    int nCollisionMask;
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

typedef int (__fastcall* PATH_FUNCTION)(D2PathInfoStrc* pPathInfo);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn);                                    // 0x006CC34C

extern const D2CoordStrc gatDirectionToOffset_006EB398[8];                                                  // 0x006EB398
extern const int gnTable_006EB490[][9];                                                                     // 0x006EB490
extern PATH_FUNCTION const scpfnPathFunction_006EB6D8[];                                                    // 0x006EB6D8

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY);// 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __stdcall UNITS_IsDoor(D2UnitStrc* pUnit);                                                              // 0x00621A70
int __fastcall UNITS_CheckIfObjectOrientationIs1(D2UnitStrc* pUnit);                                        // 0x00621AC0
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster);                                                  // 0x0063E860
void __fastcall sub_6FDA8220(D2DynamicPathStrc* pPath);                                                     // 0x00647FB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit);                                        // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask);   // 0x0064D910
void __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
void __fastcall sub_6FDAB7D0(int* pTestDir, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2);              // 0x00678DF0
void __fastcall PATHUtil_AdvanceTowardsTarget_6FDAB890(D2DynamicPathStrc* pPath);                           // 0x00679190
int __fastcall PATH_ComputePathBlessedHammer_6FDAB3C0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed);         // 0x0067A140
int __fastcall PATH_ComputePathChargedBolt_6FDAB4A0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed);           // 0x0067A240

#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

inline unsigned int PATH_InlineGetUnitX(D2UnitStrc* pUnit)
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

inline unsigned int PATH_InlineGetUnitY(D2UnitStrc* pUnit)
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

static __declspec(noinline) void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo); // 0x00648050

// build: context PATH_FindValidTargetCoordsByMovingOrthogonally
static __declspec(noinline) void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo)
{
    int nY;
    int nX = pPathInfo->tTargetCoord.X;
    const int nDeltaX = nX - pPathInfo->tStartCoord.X;
    const int nDeltaY = pPathInfo->tTargetCoord.Y - pPathInfo->tStartCoord.Y;
    const int nAbsDeltaX = D2_ABS(nDeltaX);
    const int nAbsDeltaY = D2_ABS(nDeltaY);
    if (nAbsDeltaX < PATH_SNAP_RANGE && nAbsDeltaY < PATH_SNAP_RANGE && (nAbsDeltaX != 0 || nAbsDeltaY != 0))
    {
        const int nCollisionPattern = pPathInfo->nCollisionPattern;
        const int nCollisionMask = pPathInfo->nCollisionMask;
        const int nOffsetX = gnTable_006EB490[nDeltaY][nDeltaX];
        const int nOffsetY = gnTable_006EB490[nDeltaX][nDeltaY];
        int nChebyshevDistance = D2_MAX(nAbsDeltaX, nAbsDeltaY);
        nY = pPathInfo->tTargetCoord.Y;
        while (nChebyshevDistance < PATH_SNAP_RANGE)
        {
            nX += nOffsetX;
            nY += nOffsetY;
            if (COLLISION_CheckAnyCollisionWithPattern(pPathInfo->pStartRoom, nX, nY, nCollisionPattern, nCollisionMask))
            {
                break;
            }

            ++nChebyshevDistance;
            pPathInfo->tTargetCoord.X = nX;
            pPathInfo->tTargetCoord.Y = nY;
        }
    }
}

#define PATH_SET_TARGET_AND_LEAVE(tPoint)                                       \
    pPathInfo->tTargetCoord.X = tPoint.X;                                       \
    pPathInfo->tTargetCoord.Y = tPoint.Y;                                       \
    if (tPoint.X == nStartX && tPoint.Y == nStartY)                             \
    {                                                                           \
        return FALSE;                                                           \
    }                                                                           \
    break;

static __declspec(noinline) BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2_ASSERT(!(pPath->dwFlags & PATH_MISSILE_MASK), LINE_PREPARE_MISSILE);

    const unsigned short nStartX = pPathInfo->tStartCoord.X;
    const unsigned short nStartY = pPathInfo->tStartCoord.Y;
    const int nUnitType = pPath->pUnit ? pPath->pUnit->dwUnitType : UNIT_NONE;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;

    D2PathPointStrc aTestDirPathPoints[3];
    aTestDirPathPoints[0].X = pPathInfo->tTargetCoord.X;
    aTestDirPathPoints[0].Y = pPathInfo->tTargetCoord.Y;
    aTestDirPathPoints[1].X = pPathInfo->tTargetCoord.X;
    aTestDirPathPoints[1].Y = pPathInfo->tTargetCoord.Y;
    aTestDirPathPoints[2].X = pPathInfo->tTargetCoord.X;
    aTestDirPathPoints[2].Y = pPathInfo->tTargetCoord.Y;

    int aTestDir[3];
    sub_6FDAB7D0(aTestDir, pPathInfo->tTargetCoord, pPathInfo->tStartCoord);
    while (1)
    {
        if (nStartX == aTestDirPathPoints[0].X && nStartY == aTestDirPathPoints[0].Y)
        {
            return FALSE;
        }

        aTestDirPathPoints[0].X += gatDirectionToOffset_006EB398[aTestDir[0]].nX;
        aTestDirPathPoints[0].Y += gatDirectionToOffset_006EB398[aTestDir[0]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[0].X, aTestDirPathPoints[0].Y, nCollisionPattern, nCollisionMask))
        {
            PATH_SET_TARGET_AND_LEAVE(aTestDirPathPoints[0])
        }

        aTestDirPathPoints[1].X += gatDirectionToOffset_006EB398[aTestDir[1]].nX;
        aTestDirPathPoints[1].Y += gatDirectionToOffset_006EB398[aTestDir[1]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[1].X, aTestDirPathPoints[1].Y, nCollisionPattern, nCollisionMask))
        {
            PATH_SET_TARGET_AND_LEAVE(aTestDirPathPoints[1])
        }

        if (aTestDir[2] != PATH_DIR_NULL)
        {
            aTestDirPathPoints[2].X += gatDirectionToOffset_006EB398[aTestDir[2]].nX;
            aTestDirPathPoints[2].Y += gatDirectionToOffset_006EB398[aTestDir[2]].nY;
            if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[2].X, aTestDirPathPoints[2].Y, nCollisionPattern, nCollisionMask))
            {
                PATH_SET_TARGET_AND_LEAVE(aTestDirPathPoints[2])
            }
        }

        int aNextTestDir[3];
        sub_6FDAB7D0(aNextTestDir, aTestDirPathPoints[0], pPathInfo->tStartCoord);
        aTestDir[0] = aNextTestDir[0];
    }

    if (nUnitType == UNIT_PLAYER)
    {
        PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
    }
    return PATH_TRUE;
}

static __declspec(noinline) BOOL PATH_IsTargetDestinationAllowed(D2PathInfoStrc* pPathInfo, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return TRUE;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return TRUE;
    }

    if (MONSTERS_CanBeInTown(pUnit))
    {
        return TRUE;
    }

    D2ActiveRoomStrc* pTargetRoom = pPathInfo->pTargetRoom;
    if (!pTargetRoom)
    {
        const unsigned short nStartX = pPathInfo->tStartCoord.X;
        const unsigned short nStartY = pPathInfo->tStartCoord.Y;
        const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
        const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
        D2ActiveRoomStrc* pRoomHalfway = COLLISION_GetRoomBySubTileCoordinates(
            pPathInfo->pStartRoom,
            nStartX + (nTargetX - nStartX) / 2,
            nStartY + (nTargetY - nStartY) / 2);
        pTargetRoom = COLLISION_GetRoomBySubTileCoordinates(pRoomHalfway, nTargetX, nTargetY);
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}

// 0x006492F0
static __declspec(noinline) int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tOldCoords;
    tOldCoords.X = pPath->tGameCoords.wPosX;
    tOldCoords.Y = pPath->tGameCoords.wPosY;

    pPath->dwCurrentPointIdx = 0;

    if (pPath->pTargetUnit)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPath->pTargetUnit);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPath->pTargetUnit);
    }

    int nXDistance = tOldCoords.X - pPath->tTargetCoord.X;
    if (nXDistance < 0)
    {
        nXDistance = -nXDistance;
    }
    if (nXDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    int nYDistance = tOldCoords.Y - pPath->tTargetCoord.Y;
    if (nYDistance < 0)
    {
        nYDistance = -nYDistance;
    }
    if (nYDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    if (!pPath->tTargetCoord.X || !pPath->tTargetCoord.Y)
    {
        return 0;
    }

    pPath->PathPoints[0] = pPath->tTargetCoord;
    pPath->dwPathPoints = PATH_ONE;
    pPath->unk0x38 = 0;
    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_ONE, PATH_ONE);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    if (!pRoom
        || !(pPath->tTargetCoord.X >= pRoom->tCoords.nSubtileX && pPath->tTargetCoord.X < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
            && pPath->tTargetCoord.Y >= pRoom->tCoords.nSubtileY && pPath->tTargetCoord.Y < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight))
    {
        pPath->dwFlags |= PATH_ONE;
    }
    return pPath->dwPathPoints;
}

static __declspec(noinline) int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit)
{
    switch (pPath->dwPathType)
    {
    case PATHTYPE_MISSILE:
        if (!PATH_ComputePathClassicMissile(pPath))
        {
            pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
            return 0;
        }
        break;

    case PATHTYPE_CHARGEDBOLT:
        PATH_ComputePathChargedBolt_6FDAB4A0(pPath, &pUnit->tSeed);
        break;

    case PATHTYPE_BLESSEDHAMMER:
        PATH_ComputePathBlessedHammer_6FDAB3C0(pPath, &pUnit->tSeed);
        break;

    default:
        D2_ASSERT(0, LINE_NOT_MISSILE_PATH);
        break;
    }

    pPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00020;
    return pPath->dwPathPoints;
}

// 0x006497D0
static __declspec(noinline) unsigned char PATH_AdvanceToDoor(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* pTargetUnit = pPath->pTargetUnit;

    D2_ASSERT(UNITS_IsDoor(pTargetUnit), LINE_DOOR);

    if (UNITS_CheckIfObjectOrientationIs1(pTargetUnit))
    {
        if (pPath->tGameCoords.wPosY < PATH_InlineGetUnitY(pTargetUnit))
        {
            pPath->tTargetCoord.Y -= 2;
        }
        else
        {
            pPath->tTargetCoord.Y += 2;
        }
    }
    else
    {
        if (pPath->tGameCoords.wPosX < PATH_InlineGetUnitX(pTargetUnit))
        {
            pPath->tTargetCoord.X -= 2;
        }
        else
        {
            pPath->tTargetCoord.X += 2;
        }
    }

    return 2;
}

// 0x006498A0
static __declspec(noinline) unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* pPathTargetUnit = pPath->pTargetUnit;
    if (pPathTargetUnit)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPathTargetUnit);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPathTargetUnit);

        if (pPath->tTargetCoord.X == 0 && pPath->tTargetCoord.Y == 0)
        {
            return 0;
        }

        switch (pPathTargetUnit->dwUnitType)
        {
        case UNIT_ITEM:
            return 2;

        case UNIT_OBJECT:
            if (!UNITS_IsDoor(pPathTargetUnit))
            {
                return 2;
            }
            return PATH_AdvanceToDoor(pPathInfo);

        case UNIT_PLAYER:
        case UNIT_MONSTER:
            if (pPath->dwSpeed)
            {
                PATHUtil_AdvanceTowardsTarget_6FDAB890(pPath);
            }
            return 1;

        default:
            return 1;
        }
    }
    return 1;
}

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown)
{
    if (!pPath)
    {
        return 0;
    }

    D2_ASSERT(pPath->pUnit == pUnit, LINE_PATH_UNIT);

    if (pPath->dwFlags & PATH_MISSILE_MASK)
    {
        return PATH_MissileToTarget(pPath, pUnit);
    }

    pPath->nCollidedWithMask = 0;
    D2UnitStrc* pTargetUnit = pPath->pTargetUnit;
    if (pTargetUnit && (!CLIENTS_GetUnitX(pTargetUnit) || !CLIENTS_GetUnitY(pTargetUnit)))
    {
        return 0;
    }

    D2PathInfoStrc tPathInfo;
    D2PathPointStrc tStart;
    tStart.X = pPath->tGameCoords.wPosX;
    tStart.Y = pPath->tGameCoords.wPosY;
    tPathInfo.tStartCoord = tStart;
    if (tStart.X != 0 || tStart.Y != 0)
    {
        tPathInfo.nUnitSize = pPath->dwUnitSize;
        tPathInfo.nCollisionPattern = pPath->dwCollisionPattern;
        tPathInfo.pDynamicPath = pPath;
        tPathInfo.nCollisionMask = pPath->nMoveTestCollisionMask;
        tPathInfo.nDistMax = pPath->nDistMax;
        tPathInfo.nMinimumFScoreToEvaluate = pPath->nIDAStarInitFScore;
        tPathInfo.field_14 = PATH_UpdateTargetUnit(&tPathInfo);

        if (pPath->tTargetCoord.X != 0 || pPath->tTargetCoord.Y != 0)
        {
            tPathInfo.tTargetCoord = pPath->tTargetCoord;
            if (tPathInfo.tStartCoord.X != tPathInfo.tTargetCoord.X || tPathInfo.tStartCoord.Y != tPathInfo.tTargetCoord.Y)
            {
                const int nDeltaX = tPathInfo.tTargetCoord.X - tPathInfo.tStartCoord.X;
                const int nDeltaY = tPathInfo.tTargetCoord.Y - tPathInfo.tStartCoord.Y;
                if (nDeltaX <= PATH_MAX_DISTANCE && -nDeltaX <= PATH_MAX_DISTANCE && nDeltaY <= PATH_MAX_DISTANCE && -nDeltaY <= PATH_MAX_DISTANCE)
                {
                    tPathInfo.pStartRoom = pPath->pRoom;
                    tPathInfo.pTargetRoom = COLLISION_GetRoomBySubTileCoordinates(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y);
                    if (tPathInfo.pStartRoom && tPathInfo.pTargetRoom && (PATH_IsTargetDestinationAllowed(&tPathInfo, pUnit) || bAllowInTown))
                    {
                        tPathInfo.nPathType = pPath->dwPathType;

                        D2UnitStrc* pPathTargetUnit = pPath->pTargetUnit;
                        BOOL bRemovedTargetUnitFootprint = FALSE;
                        PATH_RemoveCollisionFootprintForUnit(pUnit, FALSE);
                        if (pPathTargetUnit && UNITS_GetUnitSizeX(pPathTargetUnit) && (pPath->dwFlags & PATH_UNKNOWN_FLAG_0x00800))
                        {
                            bRemovedTargetUnitFootprint = PATH_RemoveCollisionFootprintForUnit(pPathTargetUnit, FALSE);
                        }

                        BOOL bUpdatePath = PATH_TRUE;
                        if ((pPath->dwFlags & PATH_UNKNOWN_FLAG_0x01000)
                            && COLLISION_CheckAnyCollisionWithPattern(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y, pPath->dwCollisionPattern, pPath->nMoveTestCollisionMask))
                        {
                            bUpdatePath = PATH_PreparePathTargetForPathUpdate(&tPathInfo);
                        }

                        pPath->tFinalTargetCoord.X = tPathInfo.tTargetCoord.X;
                        pPath->dwCurrentPointIdx = 0;
                        pPath->tFinalTargetCoord.Y = tPathInfo.tTargetCoord.Y;
                        pPath->dwPathPoints = 0;
                        pPath->dwCurrentPointIdx = 0;

                        int nPathPoints = 0;
                        if (bUpdatePath)
                        {
                            D2_ASSERT(!IsBadCodePtr((void*)scpfnPathFunction_006EB6D8[tPathInfo.nPathType]), LINE_PATH_FUNCTION);
                            nPathPoints = scpfnPathFunction_006EB6D8[tPathInfo.nPathType](&tPathInfo);
                        }
                        pPath->dwPathPoints = nPathPoints;

                        D2_ASSERT(tPathInfo.tStartCoord.X == tStart.X && tPathInfo.tStartCoord.Y == tStart.Y, LINE_START_COORD);

                        if (bRemovedTargetUnitFootprint)
                        {
                            PATH_AddCollisionFootprintForUnit(pPath->pTargetUnit);
                        }
                        PATH_AddCollisionFootprintForUnit(pUnit);

                        if (!pPath->dwPathPoints)
                        {
                            pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
                            return 0;
                        }

                        PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_TRUE, PATH_TRUE);
                        if (pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                        {
                            sub_6FDA8220(pPath);
                            pPath->tPrevTargetCoord.X = pPath->tTargetCoord.X;
                            pPath->tPrevTargetCoord.Y = pPath->tTargetCoord.Y;
                            pPath->unk0x38 = 0;
                            if (!(pPath->dwFlags & PATH_UNKNOWN_FLAG_0x00010) && !pPath->pTargetUnit)
                            {
                                pPath->tTargetCoord.X = pPath->PathPoints[pPath->dwPathPoints - 1].X;
                                pPath->tTargetCoord.Y = pPath->PathPoints[pPath->dwPathPoints - 1].Y;
                            }

                            if (pPath->dwPathPoints)
                            {
                                pPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00020;
                            }
                            else
                            {
                                pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
                            }
                            return pPath->dwPathPoints;
                        }
                    }
                }
            }
        }
    }

    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
    return 0;
}
