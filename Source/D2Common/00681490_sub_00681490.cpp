struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgCoordsStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgRoadEndStrc
{
    int nX;
    int nY;
    int nDirection;
    int unk0x0C;
    int unk0x10;
};

struct D2DrlgOutdoorInfoStrc
{
    int unk0x000;
    D2DrlgGridStrc tGrid04;
    D2DrlgGridStrc tGrid18;
    D2DrlgGridStrc tGrid2C;
    D2DrlgGridStrc tGrid40;
    D2DrlgCoordsStrc tCoords;
    D2DrlgVertexStrc* pVertex;
    D2DrlgVertexStrc* pRoads[6];
    D2DrlgRoadEndStrc tRoadStarts[6];
    D2DrlgRoadEndStrc tRoadFrom[6];
    D2DrlgRoadEndStrc tRoadTo[6];
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMemPool;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    int unk0x18;
    int nPosX;
    int nPosY;
    char unk0x024[0x190];
    D2DrlgStrc* pDrlg;
};

struct T00681490
{
    int nCost;
    int nEstimate;
    int nSpent;
    int nX;
    int nY;
    int nTried;
    const unsigned char* pTurn;
    unsigned char nDirection;
    T00681490* pParent;
    T00681490* pChild;
};

struct D2DrlgPathSearchStrc
{
    T00681490* pStart;
    T00681490 tNodes[900];
    int nNodes;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);                         // 0x0067C570
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection);          // 0x0067CDD0
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordsStrc* pCoords, int nX, int nY);          // 0x0066B980
int __fastcall sub_00678CF0(int nX1, int nY1, int nX2, int nY2);              // 0x00678CF0

extern const unsigned char gPathTurns[4][4]; // 0x006F2840

extern const char gPathStepY[4];

extern const char gPathStepX[4];

// 0x00681490
static T00681490* sub_00681490(D2DrlgPathSearchStrc* pSearch)
{
    if (pSearch->nNodes == 900)
    {
        return 0;
    }

    T00681490* pNode = &pSearch->tNodes[pSearch->nNodes++];
    memset(pNode, 0, sizeof(T00681490));
    return pNode;
}

// 0x006814E0
static int __stdcall sub_006814E0(int nX1, int nY1, int nX2, int nY2)
{
    int nDiffX = nX1 - nX2;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = nY1 - nY2;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x00681510
static int __stdcall sub_00681510(T00681490* pNode, int nX, int nY)
{
    return (pNode->nX == nX || pNode->nY == nY) ? 2 : 3;
}

// 0x00681540
static const unsigned char* __stdcall sub_00681540(unsigned char nDirection, unsigned char nBase)
{
    return gPathTurns[(unsigned char)(nDirection - nBase) & 3];
}

static T00681490* __stdcall sub_00681560(D2DrlgPathSearchStrc* pSearch, T00681490* pNode)
{
    if (pNode->nTried < 4)
    {
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
    }

    ++pNode->nTried;
    if (pNode->nTried == 3)
    {
        do
        {
            if (pNode == pSearch->pStart)
            {
                return 0;
            }

            pNode = pNode->pParent;
            ++pNode->pTurn;
            pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
            ++pNode->nTried;
        }
        while (pNode->nTried == 3);
    }

    return pNode;
}

static int __stdcall sub_006815C0(D2DrlgVertexStrc* pGoal, int nX, int nY, D2DrlgLevelStrc* pLevel, T00681490* pNode)
{
    if (nX == pGoal->nPosX && nY == pGoal->nPosY)
    {
        return 1;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    if (!DRLGROOM_AreXYInsideCoordinates(&pInfo->tCoords, nX, nY) || (sub_0067C570(&pInfo->tGrid2C, nX, nY) & 0x200))
    {
        return 0;
    }

    for (; pNode; pNode = pNode->pParent)
    {
        if (pNode->nX == nX && pNode->nY == nY)
        {
            return 0;
        }
    }

    return 1;
}

static T00681490* __stdcall sub_00681630(D2DrlgPathSearchStrc* pSearch, int nMaxCost, D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pGoal)
{
    T00681490* pNode = pSearch->pStart;
    int nGoalX = pGoal->nPosX;
    int nGoalY = pGoal->nPosY;

    while (1)
    {
        if (pNode->nX == nGoalX && pNode->nY == nGoalY)
        {
            return pNode;
        }

        int nX = gPathStepX[pNode->nDirection] + pNode->nX;
        int nY = gPathStepY[pNode->nDirection] + pNode->nY;
        if (sub_006815C0(pGoal, nX, nY, pLevel, pNode))
        {
            int nSpent = pNode->nSpent + sub_00681510(pNode, nX, nY);
            int nEstimate = sub_006814E0(nX, nY, nGoalX, nGoalY);
            int nCost = nEstimate + nSpent;
            if (nCost <= nMaxCost)
            {
                if (!pNode->pChild)
                {
                    pNode->pChild = sub_00681490(pSearch);
                    if (!pNode->pChild)
                    {
                        return 0;
                    }
                    pNode->pChild->pParent = pNode;
                }

                pNode = pNode->pChild;
                pNode->nEstimate = nEstimate;
                pNode->nCost = nCost;
                pNode->nSpent = nSpent;
                pNode->nTried = 0;
                int nBase = sub_00678CF0(nX, nY, nGoalX, nGoalY) / 2;
                pNode->pTurn = sub_00681540(pNode->pParent->nDirection, nBase);
                pNode->nDirection = (*pNode->pTurn + nBase) & 3;
                pNode->nX = nX;
                pNode->nY = nY;
                continue;
            }
        }

        pNode = sub_00681560(pSearch, pNode);
        if (!pNode)
        {
            return 0;
        }
    }
}

// build: context sub_006817D0
int __fastcall sub_006817D0(D2DrlgLevelStrc* pLevel, int nRoad)
{
    void* pMemPool = pLevel->pDrlg->pMemPool;
    D2DrlgVertexStrc tGoal;
    memset(&tGoal, 0, sizeof(tGoal));

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    int nStartX = (pInfo->tRoadFrom[nRoad].nX - pLevel->nPosX) / 8;
    int nStartY = (pInfo->tRoadFrom[nRoad].nY - pLevel->nPosY) / 8;
    tGoal.nPosX = (pInfo->tRoadTo[nRoad].nX - pLevel->nPosX) / 8;
    tGoal.nPosY = (pInfo->tRoadTo[nRoad].nY - pLevel->nPosY) / 8;

    int nDiffX = nStartX - tGoal.nPosX;
    int nDiffY = nStartY - tGoal.nPosY;
    if ((nDiffX < 0 ? -nDiffX : nDiffX) + (nDiffY < 0 ? -nDiffY : nDiffY) < 2)
    {
        pInfo->pRoads[nRoad] = DRLGVER_AllocVertex(pMemPool, 0);
        pInfo->pRoads[nRoad]->nPosX = nStartX;
        pInfo->pRoads[nRoad]->nPosY = nStartY;
        pInfo->pRoads[nRoad]->pNext = DRLGVER_AllocVertex(pMemPool, 0);
        pInfo->pRoads[nRoad]->pNext->nPosX = tGoal.nPosX;
        pInfo->pRoads[nRoad]->pNext->nPosY = tGoal.nPosY;
        return 1;
    }

    D2DrlgPathSearchStrc tSearch;
    T00681490 tStart;
    int nDirection = sub_00678CF0(nStartX, nStartY, tGoal.nPosX, tGoal.nPosY) / 2;
    tStart.nSpent = 0;
    int nEstimate = sub_006814E0(nStartX, nStartY, tGoal.nPosX, tGoal.nPosY);
    tStart.nDirection = nDirection & 3;
    memset(tSearch.tNodes, 0, sizeof(T00681490));
    tSearch.pStart = tSearch.tNodes;
    tStart.nX = nStartX;
    tStart.nY = nStartY;
    int nMaxCost = nEstimate + nEstimate / 2;
    tStart.nEstimate = nEstimate;
    tStart.nCost = nEstimate;
    int nLimit = nMaxCost + 35;
    tStart.nTried = -1;
    tStart.pTurn = gPathTurns[0];
    tStart.pChild = 0;
    tStart.pParent = 0;
    tSearch.nNodes = 1;

    do
    {
        *tSearch.pStart = tStart;
        T00681490* pNode = sub_00681630(&tSearch, nMaxCost, pLevel, &tGoal);
        nMaxCost += 5;
        if (tSearch.nNodes >= 900)
        {
            return 0;
        }

        tSearch.nNodes = 1;
        if (pNode)
        {
            D2DrlgVertexStrc* pVertex = 0;
            do
            {
                D2DrlgVertexStrc* pNew;
                if (pInfo->pRoads[nRoad])
                {
                    pNew = DRLGVER_AllocVertex(pMemPool, 0);
                    pVertex->pNext = pNew;
                }
                else
                {
                    pNew = DRLGVER_AllocVertex(pMemPool, 0);
                    pInfo->pRoads[nRoad] = pNew;
                }

                pVertex = pNew;
                pVertex->nPosX = pNode->nX;
                pVertex->nPosY = pNode->nY;
                pNode = pNode->pParent;
            }
            while (pNode);

            return 1;
        }
    }
    while (nMaxCost < nLimit);

    return 0;
}

#include "gen/data/Source/D2Common/00681490_sub_00681490.inc"
