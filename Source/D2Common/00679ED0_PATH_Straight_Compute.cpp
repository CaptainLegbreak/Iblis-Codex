struct D2ActiveRoomStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x24];
    int dwCurrentPointIdx;
    int dwPathPoints;
    char unk0x2C[0x70];
    D2PathPointStrc PathPoints[78];
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

int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo);                                             // 0x00679C80
int __fastcall PATH_AStar_ComputePath(D2PathInfoStrc* pPathInfo);                                           // 0x0067B850
int __stdcall sub_00679380_PathTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2);            // 0x00679380

// 0x00679ED0
int __fastcall PATH_Straight_Compute(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->dwPathPoints = 0;

    int nPathPoints = PATH_Toward_6FDAA9F0(pPathInfo);
    if (nPathPoints)
    {
        D2PathPointStrc tPathLastPoint = pDynamicPath->PathPoints[nPathPoints - 1];
        if (sub_00679380_PathTableHeuristic(tPathLastPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14
            && (tPathLastPoint.X != pPathInfo->tStartCoord.X || tPathLastPoint.Y != pPathInfo->tStartCoord.Y))
        {
            return nPathPoints;
        }
    }

    const int nMaxDist = 18;
    const int nMaxDistSquared = nMaxDist * nMaxDist;

    int nDX = pPathInfo->tStartCoord.X - pPathInfo->tTargetCoord.X;
    const int nDiffX = nDX < 0 ? -nDX : nDX;
    int nDY = pPathInfo->tStartCoord.Y - pPathInfo->tTargetCoord.Y;
    const int nDiffY = nDY < 0 ? -nDY : nDY;
    const int nSquaredDistance = nDiffX * nDiffX + nDiffY * nDiffY;

    if (nSquaredDistance <= nMaxDistSquared)
    {
        if (int nAStarPathPoints = PATH_AStar_ComputePath(pPathInfo))
        {
            return nAStarPathPoints;
        }
        else if (nPathPoints)
        {
            nPathPoints = PATH_Toward_6FDAA9F0(pPathInfo);
        }
    }
    return nPathPoints;
}
