struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

static __declspec(noinline) int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints);

// 0x0067B9F0
static int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints)
{
    nDistMax--;
    *nMajorDirection = 0;

    int nAbsDiffX = tTargetPoint.X - tStartPoint.X;
    int nAbsDiffY = tTargetPoint.Y - (int)tStartPoint.Y;
    int nStepY = 0;
    int nStepX = 0;
    int nbPoints = 0;
    if (nAbsDiffX < 0)
    {
        nAbsDiffX = -nAbsDiffX;
        nStepX = -1;
    }
    else
    {
        nStepX = 1;
    }
    if (nAbsDiffY < 0)
    {
        nAbsDiffY = -nAbsDiffY;
        nStepY = -1;
    }
    else
    {
        nStepY = 1;
    }

    if (nAbsDiffX == 0)
    {
        if (nAbsDiffY > 0)
        {
            unsigned short nY = tStartPoint.Y;
            *nMajorDirection = nStepY <= 0 ? 0 : 2;
            if (nAbsDiffY > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            do
            {
                pOutPoints[nbPoints].X = tStartPoint.X;
                nY += nStepY;
                pOutPoints[nbPoints].Y = (int)nY;
                ++nbPoints;
                --nAbsDiffY;
            }
            while (nAbsDiffY);
        }
    }
    else
    {
        unsigned short nX = tStartPoint.X;
        unsigned short nY = tStartPoint.Y;
        if (nAbsDiffY == 0)
        {
            *nMajorDirection = nStepX <= 0 ? 3 : 1;
            if (nAbsDiffX > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            do
            {
                nX += nStepX;
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = tStartPoint.Y;
                ++nbPoints;
                --nAbsDiffX;
            }
            while (nAbsDiffX);
        }
        else if (nAbsDiffX >= nAbsDiffY)
        {
            *nMajorDirection = nStepX <= 0 ? 3 : 1;
            if (nAbsDiffX > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            int nDeviation = 0;
            nDistMax = nAbsDiffX;
            do
            {
                nX += nStepX;
                nDeviation += nAbsDiffY;
                if (nDeviation >= nAbsDiffX)
                {
                    nDeviation -= nAbsDiffX;
                    nY += nStepY;
                }
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = nY;
                ++nbPoints;
                --nDistMax;
            }
            while (nDistMax);
        }
        else
        {
            *nMajorDirection = nStepY <= 0 ? 0 : 2;
            if (nAbsDiffY > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }
            int nRemainingStepsY = nAbsDiffY;
            int nDeviation = 0;
            do
            {
                nY += nStepY;
                nDeviation += nAbsDiffX;
                if (nDeviation >= nAbsDiffY)
                {
                    nDeviation -= nAbsDiffY;
                    nX += nStepX;
                }
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = nY;
                ++nbPoints;
                --nRemainingStepsY;
            }
            while (nRemainingStepsY);
        }
    }

    pOutPoints[nbPoints].X = 0;
    return nbPoints;
}

// build: context sub_0067B9F0_Shim
// calling-convention shim (not game code)
int __fastcall sub_0067B9F0_Shim(const D2PathPointStrc* pStart, const D2PathPointStrc* pTarget, int nDist)
{
    int nMajorDirection = 0;
    D2PathPointStrc aPathPoints[78];
    nDist = PATH_BresenhamLine(*pStart, *pTarget, nDist, &nMajorDirection, aPathPoints);
    return nDist + nMajorDirection + aPathPoints[1].Y;
}
