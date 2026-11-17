enum D2C_PathConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2ActiveRoomStrc;

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

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2DynamicPathStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
    char unk0x08[0x14];
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x4];
    int dwCurrentPointIdx;
    int dwPathPoints;
    char unk0x2C[0x4];
    D2UnitStrc* pUnit;
    char unk0x34[0x8];
    unsigned int dwPathType;
    char unk0x40[0x8];
    unsigned int dwCollisionPattern;
    char unk0x4C[0x4];
    unsigned int nMoveTestCollisionMask;
    char unk0x54[0x4];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x20];
    int dwVelocity;
    char unk0x80[0x10];
    unsigned char nDist;
    char unk0x91[0x7];
    int nDirOffset;
    D2PathPointStrc PathPoints[78];
};

struct D2CollisionTestStrc
{
    D2ActiveRoomStrc* pRoom;
    unsigned int nCollisionPattern;
    unsigned int nCollisionMask;
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
    char unk0x1C[0xC];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70
int __stdcall sub_00679380_PathTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2);            // 0x00679380
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
extern const D2CoordStrc gatDirectionToOffset[8];                                                           // 0x006F1798

inline const int& PATH_MaxRef(const int& a, const int& b)
{
    return a > b ? a : b;
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 0) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 1)) != 0, 52);

    const int nCollisionMask = pPathInfo->nCollisionMask;
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;

    D2PathPointStrc tTest0;
    tTest0.X = tPoint.X + gatDirectionToOffset[pTestDir[0]].nX;
    tTest0.Y = tPoint.Y + gatDirectionToOffset[pTestDir[0]].nY;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tTest0.X, tTest0.Y, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[0];
        return 1;
    }

    D2PathPointStrc tTest1;
    tTest1.X = tPoint.X + gatDirectionToOffset[pTestDir[1]].nX;
    tTest1.Y = tPoint.Y + gatDirectionToOffset[pTestDir[1]].nY;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tTest1.X, tTest1.Y, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[1];
        return 1;
    }

    D2_ASSERT(pTestDir[2] != 0xFF, 76);

    D2PathPointStrc tTest2;
    tTest2.X = tPoint.X + gatDirectionToOffset[pTestDir[2]].nX;
    tTest2.Y = tPoint.Y + gatDirectionToOffset[pTestDir[2]].nY;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tTest2.X, tTest2.Y, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[2];
        return 1;
    }

    return 0;
}

static __forceinline int PATH_TestCollision(const D2CollisionTestStrc* pTest, int nX, int nY)
{
    return COLLISION_CheckAnyCollisionWithPattern(pTest->pRoom, nX, nY, pTest->nCollisionPattern, pTest->nCollisionMask);
}

static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath); // 0x00679720

// build: context PATH_RayTrace
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath)
{
    D2CollisionTestStrc tTest;
    tTest.pRoom = pDynamicPath->pRoom;
    tTest.nCollisionPattern = pDynamicPath->dwCollisionPattern;
    tTest.nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    const D2PathPointStrc tTargetPoint = *pPathDestination;

    D2PathPointStrc tLastPointWithoutCollision = tStartCoord;
    D2PathPointStrc tCurPoint = tStartCoord;
    const int nDeltaX = tTargetPoint.X - tStartCoord.X;
    const int nDeltaY = tTargetPoint.Y - tStartCoord.Y;
    const int nPointsX = (nDeltaX < 0 ? -nDeltaX : nDeltaX) + 1;
    const int nPointsY = (nDeltaY < 0 ? -nDeltaY : nDeltaY) + 1;

    if (nPointsX > nPointsY)
    {
        if (nDeltaX == 0)
        {
            const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
            if (tStartCoord.Y != tTargetPoint.Y)
            {
                do
                {
                    tCurPoint.Y += nYIncrement;
                    if (PATH_TestCollision(&tTest, tStartCoord.X, tCurPoint.Y))
                    {
                        *pPathDestination = tLastPointWithoutCollision;
                        return 0;
                    }
                    tLastPointWithoutCollision = tCurPoint;
                }
                while (tCurPoint.Y != tTargetPoint.Y);
            }
        }
        else
        {
            const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
            const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
            if (tStartCoord.X != tTargetPoint.X)
            {
                int nYOffset = nPointsY;
                while (1)
                {
                    tCurPoint.X += nXIncrement;
                    if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                    {
                        *pPathDestination = tLastPointWithoutCollision;
                        return 0;
                    }
                    nYOffset += nPointsY;
                    if (nYOffset >= nPointsX)
                    {
                        nYOffset -= nPointsX;
                        tCurPoint.Y += nYIncrement;
                        if (nYOffset > 0)
                        {
                            if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                            {
                                *pPathDestination = tLastPointWithoutCollision;
                                return 0;
                            }
                        }
                    }
                    tLastPointWithoutCollision = tCurPoint;
                    if (tCurPoint.X == tTargetPoint.X)
                    {
                        return 1;
                    }
                }
            }
        }
        return 1;
    }

    if (nPointsX >= nPointsY)
    {
        const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
        const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
        if (tStartCoord.X == tTargetPoint.X)
        {
            return 1;
        }

        do
        {
            tCurPoint.Y += nYIncrement;
            tCurPoint.X += nXIncrement;
            if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
            {
                *pPathDestination = tLastPointWithoutCollision;
                return 0;
            }
            tLastPointWithoutCollision = tCurPoint;
        }
        while (tCurPoint.X != tTargetPoint.X);
        return 1;
    }

    if (nDeltaY == 0)
    {
        const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
        if (tStartCoord.X == tTargetPoint.X)
        {
            return 1;
        }

        do
        {
            tCurPoint.X += nXIncrement;
            if (PATH_TestCollision(&tTest, tCurPoint.X, tStartCoord.Y))
            {
                *pPathDestination = tLastPointWithoutCollision;
                return 0;
            }
            tLastPointWithoutCollision = tCurPoint;
        }
        while (tCurPoint.X != tTargetPoint.X);
        return 1;
    }

    const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
    const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
    if (tStartCoord.Y == tTargetPoint.Y)
    {
        return 1;
    }

    int nEndOffsetX = nPointsX;
    do
    {
        tCurPoint.Y += nYIncrement;
        if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
        {
            *pPathDestination = tLastPointWithoutCollision;
            return 0;
        }

        nEndOffsetX += nPointsX;
        if (nEndOffsetX >= nPointsY)
        {
            nEndOffsetX -= nPointsY;
            tCurPoint.X += nXIncrement;
            if (nEndOffsetX > 0)
            {
                if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
            }
        }
        tLastPointWithoutCollision = tCurPoint;
    }
    while (tCurPoint.Y != tTargetPoint.Y);
    return 1;
}

// 0x00679A60
static int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord)
{
    D2PathPointStrc tPoint;

    D2_ASSERT(((pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 0) || (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 1)) != 0, 324);
    D2_ASSERT(pDynamicPath->dwPathType != 4, 325);
    D2_ASSERT(pGameCoord->X != 0, 326);
    D2_ASSERT(pGameCoord->Y != 0, 327);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pDynamicPath, 1, 1);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    tPoint.X = pDynamicPath->wPosX;
    tPoint.Y = pDynamicPath->wPosY;
    return PATH_RayTrace(tPoint, pGameCoord, pDynamicPath);
}

int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    const int nDistMax = pPathInfo->nDistMax;
    int nbPathPoints = pDynamicPath->dwPathPoints;
    D2PathPointStrc tLastSegmentEndCoord = pPathInfo->tStartCoord;
    const int nDirectionOffset = pDynamicPath->nDirOffset;
    {
        const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
        int nPrevDirection = 0xFF;
        int bSegmentEndAlreadyAdded = 0;

        D2PathPointStrc tCurCoords = tLastSegmentEndCoord;
        int nCurDistance;
        for (nCurDistance = 0; nCurDistance < nDistMax; nCurDistance += 1)
        {
            if (tCurCoords.X == tTargetCoord.X && tCurCoords.Y == tTargetCoord.Y)
            {
                break;
            }

            bSegmentEndAlreadyAdded = 0;
            int nDirections[3];
            PATH_GetDirections_6FDAB790(nDirections, tLastSegmentEndCoord, tTargetCoord);
            nDirections[0] = (nDirections[0] + nDirectionOffset) & 7;
            nDirections[1] = (nDirections[1] + nDirectionOffset) & 7;
            nDirections[2] = (nDirections[2] + nDirectionOffset) & 7;
            int nDirection;
            if (!sub_6FDAA880(tLastSegmentEndCoord, nDirections, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDirection)
            {
                break;
            }

            tCurCoords.X += gatDirectionToOffset[nDirection].nX;
            tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
            if (nDirection != nPrevDirection)
            {
                pDynamicPath->PathPoints[nbPathPoints] = tLastSegmentEndCoord;
                nbPathPoints += 1;
                bSegmentEndAlreadyAdded = 1;
            }
            tLastSegmentEndCoord = tCurCoords;
            nPrevDirection = nDirection;
        }

        if (!bSegmentEndAlreadyAdded && nCurDistance != 0)
        {
            pDynamicPath->PathPoints[nbPathPoints] = tLastSegmentEndCoord;
            nbPathPoints += 1;
        }
    }

    pDynamicPath->dwPathPoints = nbPathPoints;
    return nbPathPoints;
}

int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    if (pPath->nDirOffset)
    {
        return sub_6FDAA720(pPathInfo);
    }

    D2PathPointStrc nNextPoint = pPathInfo->tTargetCoord;
    pPath->PathPoints[0] = nNextPoint;

    if (PATH_CheckCollisionsToNextPosition(pPath, &nNextPoint))
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    if (sub_00679380_PathTableHeuristic(nNextPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14)
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    {
        D2PathPointStrc tPoint = pPathInfo->tStartCoord;
        D2PathPointStrc tCurCoords = pPathInfo->tStartCoord;
        if (tPoint.X != nNextPoint.X || tPoint.Y != nNextPoint.Y)
        {
            pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
            pPath->dwPathPoints += 1;
            tPoint = nNextPoint;
            tCurCoords = nNextPoint;
        }

        const int nDistMax = pPathInfo->nDistMax;
        nNextPoint = pPathInfo->tTargetCoord;
        int nPrevDir = 0xFF;
        int nNewPointsCount = pPath->dwPathPoints;
        int bNotStraightLine = 0;
        int nCurDist = 0;
        if (nDistMax > 0)
        {
            D2PathPointStrc* pPathPointsEnd = &pPath->PathPoints[pPath->dwPathPoints];
            do
            {
                if (tCurCoords.X == nNextPoint.X && tCurCoords.Y == nNextPoint.Y)
                {
                    break;
                }

                bNotStraightLine = 0;
                int aTestDir[3];
                PATH_GetDirections_6FDAB790(aTestDir, tPoint, nNextPoint);
                int nDirection;
                if (!sub_6FDAA880(tPoint, aTestDir, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDir)
                {
                    goto LABEL_20;
                }

                tCurCoords.X += gatDirectionToOffset[nDirection].nX;
                tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
                if (nDirection != nPrevDir)
                {
                    if (tPoint.X != pPathInfo->tStartCoord.X || tPoint.Y != pPathInfo->tStartCoord.Y)
                    {
                        *pPathPointsEnd = tPoint;
                        nNewPointsCount += 1;
                        ++pPathPointsEnd;
                    }
                    bNotStraightLine = 1;
                }
                tPoint = tCurCoords;
                nPrevDir = nDirection;
                nCurDist += 1;
            }
            while (nCurDist < nDistMax);

            if (bNotStraightLine)
            {
                goto LABEL_22;
            }
        LABEL_20:
            if (nCurDist)
            {
                pPath->PathPoints[nNewPointsCount] = tPoint;
                nNewPointsCount += 1;
            }
        }
    LABEL_22:
        pPath->dwPathPoints = nNewPointsCount;
    }

    return pPath->dwPathPoints;
}

// 0x00679F70
int __fastcall PATH_Leap_6FDAB1E0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    D2PathPointStrc pGameCoord = pPathInfo->tTargetCoord;
    pDynamicPath->PathPoints[0] = pGameCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pGameCoord);
    if (pPathInfo->tStartCoord.X == pGameCoord.X && pPathInfo->tStartCoord.Y == pGameCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = pGameCoord;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}

// 0x00679FD0
int __fastcall PATH_Knockback_Client(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->PathPoints[0] = pPathInfo->tTargetCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pDynamicPath->PathPoints[0]);
    return 1;
}

int __fastcall PATH_Knockback_Server(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    const int nHalfDist = (pDynamicPath->nDist >> 1) + 1;
    D2PathPointStrc tFinalCoords;
    if (pDynamicPath->pTargetUnit)
    {
        tFinalCoords = pPathInfo->tStartCoord;

        const int nTargetUnitX = UNITS_GetXPositionInline(pDynamicPath->pTargetUnit);
        const int nTargetUnitY = UNITS_GetYPositionInline(pDynamicPath->pTargetUnit);
        int nDeltaX = pPathInfo->tStartCoord.X - nTargetUnitX;
        int nDeltaY = pPathInfo->tStartCoord.Y - nTargetUnitY;
        if (const int nMax = PATH_MaxRef(nDeltaX < 0 ? -nDeltaX : nDeltaX, nDeltaY < 0 ? -nDeltaY : nDeltaY))
        {
            nDeltaX = (nDeltaX * nHalfDist) / nMax;
            nDeltaY = (nDeltaY * nHalfDist) / nMax;
        }
        tFinalCoords.X += nDeltaX;
        tFinalCoords.Y += nDeltaY;
    }
    else
    {
        tFinalCoords = pPathInfo->tTargetCoord;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    PATH_RayTrace(pPathInfo->tStartCoord, &tFinalCoords, pDynamicPath);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, tFinalCoords.X, tFinalCoords.Y);
    if (tFinalCoords.X == pPathInfo->tStartCoord.X && tFinalCoords.Y == pPathInfo->tStartCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}
