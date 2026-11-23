#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"







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
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                         // 0x0067C570
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection);          // 0x0067CDD0
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY);          // 0x0066B980

extern const unsigned char gPathTurns[4][4]; // 0x006F2840
extern const char gPathStepY[4]; // 0x006F2850
extern const char gPathStepX[4]; // 0x006F2854

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

static int __stdcall sub_006815C0(D2DrlgVertexStrc* pGoal, int nX, int nY, D2DrlgLevelStrc* pLevel, T00681490* pNode);

// 0x006815C0
static int __stdcall sub_006815C0(D2DrlgVertexStrc* pGoal, int nX, int nY, D2DrlgLevelStrc* pLevel, T00681490* pNode)
{
    if (nX == pGoal->nPosX && nY == pGoal->nPosY)
    {
        return 1;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!DRLGROOM_AreXYInsideCoordinates(&pInfo->tCoords, nX, nY) || (DRLGGRID_GetGridEntry(&pInfo->pGrid[2], nX, nY) & 0x200))
    {
        return 0;
    }

    for (T00681490* pParent = pNode; pParent; pParent = pParent->pParent)
    {
        if (pParent->nX == nX && pParent->nY == nY)
        {
            return 0;
        }
    }

    return 1;
}

static T00681490* __stdcall sub_00681560(T00681490* pNode, T00681490** ppRoot);

// 0x00681560
static T00681490* __stdcall sub_00681560(T00681490* pNode, T00681490** ppRoot)
{
    if (pNode->nTried < 4)
    {
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
    }
    ++pNode->nTried;

    while (pNode->nTried == 3)
    {
        if (pNode == *ppRoot)
        {
            return 0;
        }

        pNode = pNode->pParent;
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
        ++pNode->nTried;
    }

    return pNode;
}

static T00681490* __stdcall sub_00681630(D2DrlgPathSearchStrc* pSearch, int nMaxCost, D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pGoal);

// 0x00681630
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
        if (!sub_006815C0(pGoal, nX, nY, pLevel, pNode))
        {
            pNode = sub_00681560(pNode, &pSearch->pStart);
            if (!pNode)
            {
                return 0;
            }
            continue;
        }

        int nSpent = pNode->nSpent + sub_00681510(pNode, nX, nY);

        const int rawX = nX - nGoalX;
        int dx = rawX < 0 ? -rawX : rawX;
        const int rawY = nY - nGoalY;
        int dy = rawY < 0 ? -rawY : rawY;
        int nMin = dx;
        if (dx >= dy)
        {
            nMin = dy;
            if (dx > dy)
                dy = dx;
        }
        int nEstimate = nMin + 2 * dy;
        int nCost = nEstimate + nSpent;
        if (nCost > nMaxCost)
        {
            pNode = sub_00681560(pNode, &pSearch->pStart);
            if (!pNode)
            {
                return 0;
            }
            continue;
        }

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
    }
}

// 0x006817D0
int __fastcall sub_006817D0(D2DrlgLevelStrc* pLevel, int nRoad)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgVertexStrc tGoal = {};

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    D2DrlgVertexStrc tFrom;
    tFrom.nPosX = (pInfo->pVertices[nRoad + 6].nPosX - pLevel->nPosX) / 8;
    tFrom.nPosY = (pInfo->pVertices[nRoad + 6].nPosY - pLevel->nPosY) / 8;
    tGoal.nPosX = (pInfo->pVertices[nRoad + 12].nPosX - pLevel->nPosX) / 8;
    tGoal.nPosY = (pInfo->pVertices[nRoad + 12].nPosY - pLevel->nPosY) / 8;

    int nDiffX = tFrom.nPosX - tGoal.nPosX;
    if (nDiffX < 0)
        nDiffX = -nDiffX;
    int nDiffY = tFrom.nPosY - tGoal.nPosY;
    if (nDiffY < 0)
        nDiffY = -nDiffY;
    if (nDiffX + nDiffY < 2)
    {
        pInfo->pRoads[nRoad] = DRLGVER_AllocVertex(pMemPool, 0);
        pInfo->pRoads[nRoad]->nPosX = tFrom.nPosX;
        pInfo->pRoads[nRoad]->nPosY = tFrom.nPosY;
        D2DrlgVertexStrc* pGoalVertex = DRLGVER_AllocVertex(pMemPool, 0);
        pInfo->pRoads[nRoad]->pNext = pGoalVertex;
        pInfo->pRoads[nRoad]->pNext->nPosX = tGoal.nPosX;
        pInfo->pRoads[nRoad]->pNext->nPosY = tGoal.nPosY;
        return 1;
    }

    D2DrlgPathSearchStrc tSearch;
    T00681490 tStart;
    int nDirection = sub_00678CF0(tFrom.nPosX, tFrom.nPosY, tGoal.nPosX, tGoal.nPosY) / 2;
    tStart.nSpent = 0;
    int nDX = tFrom.nPosX - tGoal.nPosX;
    if (nDX < 0)
        nDX = -nDX;
    const int nRawY = tFrom.nPosY - tGoal.nPosY;
    const int nDY = nRawY < 0 ? -nRawY : nRawY;
    int nMin = nDX;
    int nMax = nDX;
    if (nDX >= nDY)
        nMin = nDY;
    if (nDX <= nDY)
        nMax = nDY;
    int nEstimate = nMin + 2 * nMax;
    tStart.nY = tFrom.nPosY;
    tStart.nDirection = nDirection & 3;
    memset(tSearch.tNodes, 0, sizeof(T00681490));
    tSearch.pStart = tSearch.tNodes;
    tStart.nX = tFrom.nPosX;
    int nMaxCost = nEstimate + nEstimate / 2;
    tStart.nEstimate = nEstimate;
    tStart.nCost = nEstimate;
    tStart.nTried = -1;
    tStart.pTurn = gPathTurns[0];
    tStart.pChild = 0;
    tStart.pParent = 0;
    tSearch.nNodes = 1;
    int nLimit = nMaxCost + 35;

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
                if (pInfo->pRoads[nRoad])
                {
                    pVertex = pVertex->pNext = DRLGVER_AllocVertex(pMemPool, 0);
                }
                else
                {
                    pVertex = pInfo->pRoads[nRoad] = DRLGVER_AllocVertex(pMemPool, 0);
                }

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
