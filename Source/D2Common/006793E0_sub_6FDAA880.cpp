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

// 0x006793E0
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 0) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 1)) != 0, 52);

    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;

    const int nX0 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[0]].nX);
    const int nY0 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[0]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX0, nY0, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[0];
        return 1;
    }

    const int nX1 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[1]].nX);
    const int nY1 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[1]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX1, nY1, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[1];
        return 1;
    }

    D2_ASSERT(pTestDir[2] != 0xFF, 76);

    const int nX2 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[2]].nX);
    const int nY2 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[2]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX2, nY2, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[2];
        return 1;
    }

    return 0;
}

// 0x00679B30
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    int nPrevDirection = 0xFF;
    int nbPathPoints = pDynamicPath->dwPathPoints;
    const int nDistMax = pPathInfo->nDistMax;
    D2PathPointStrc tLastSegmentEndCoord = pPathInfo->tStartCoord;
    const int nDirectionOffset = pDynamicPath->nDirOffset;
    {
        int bSegmentEndAlreadyAdded = 0;
        const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;

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
