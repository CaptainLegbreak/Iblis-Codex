// 0x00679C80
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
    if (PATH_GetTableHeuristic(nNextPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14)
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    union { D2PathPointStrc tPoint; unsigned int dwPoint; } uP; uP.tPoint = pPathInfo->tStartCoord;
    D2PathPointStrc tCurCoords = pPathInfo->tStartCoord;
    if (tCurCoords.X != nNextPoint.X || tCurCoords.Y != nNextPoint.Y)
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        uP.tPoint = nNextPoint;
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
        D2PathPointStrc* pPathPointsEnd = &pPath->PathPoints[nNewPointsCount];
        do
        {
            if (tCurCoords.X == nNextPoint.X && tCurCoords.Y == nNextPoint.Y)
            {
                break;
            }
            bNotStraightLine = 0;
            int aTestDir[3];
            PATH_GetDirections_6FDAB790(aTestDir, uP.tPoint, nNextPoint);
            int nDirection;
            if (!sub_6FDAA880(uP.tPoint, aTestDir, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDir)
            {
                goto LABEL_20;
            }
            tCurCoords.X += gatDirectionToOffset[nDirection].nX;
            tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
            if (nDirection != nPrevDir)
            {
                if ((unsigned short)uP.dwPoint != pPathInfo->tStartCoord.X || (unsigned short)(uP.dwPoint >> 16) != pPathInfo->tStartCoord.Y)
                {
                    *pPathPointsEnd = uP.tPoint;
                    nNewPointsCount += 1;
                    ++pPathPointsEnd;
                }
                bNotStraightLine = 1;
            }
            uP.tPoint = tCurCoords;
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
            pPath->PathPoints[nNewPointsCount] = uP.tPoint;
            nNewPointsCount += 1;
        }
    }
LABEL_22:
    pPath->dwPathPoints = nNewPointsCount;
    return pPath->dwPathPoints;
}
