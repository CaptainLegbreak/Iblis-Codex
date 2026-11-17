struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

// 0x0067C1E0
int __fastcall PATH_SimplifyToLines(D2PathPointStrc* pOutPathPoints, D2PathPointStrc* pInputPoints, D2PathPointStrc tStartCoord, int nbTempPoints)
{
    if (nbTempPoints < 2)
    {
        if (nbTempPoints == 1)
        {
            *pOutPathPoints = *pInputPoints;
            return 1;
        }
        return 0;
    }

    int nCurrentPointIdx = 0;
    int prevDeltaX = pInputPoints->X - tStartCoord.X;
    int nbOutPoints = 0;
    int nbPointsInLine = 0;
    int prevDeltaY = pInputPoints->Y - tStartCoord.Y;
    for (; nCurrentPointIdx < nbTempPoints - 1; )
    {
        int deltaX = pInputPoints[nCurrentPointIdx + 1].X - pInputPoints[nCurrentPointIdx].X;
        int deltaY = pInputPoints[nCurrentPointIdx + 1].Y - pInputPoints[nCurrentPointIdx].Y;
        if (deltaX == prevDeltaX && deltaY == prevDeltaY)
        {
            ++nbPointsInLine;
            ++nCurrentPointIdx;
        }
        else if (nbPointsInLine > 0)
        {
            pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
            nbPointsInLine = 0;
            ++nCurrentPointIdx;
        }
        else if (prevDeltaX == deltaX || prevDeltaY == deltaY)
        {
            pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
            nbPointsInLine = 0;
            ++nCurrentPointIdx;
        }
        else
        {
            nbPointsInLine = 1;
            deltaX = -2;
            ++nCurrentPointIdx;
        }
        prevDeltaY = deltaY;
        prevDeltaX = deltaX;
    }
    if (nCurrentPointIdx < nbTempPoints)
    {
        pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
    }

    return nbOutPoints;
}
