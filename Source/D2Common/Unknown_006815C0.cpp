#include "D2Common.h"

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

struct D2DrlgOutdoorInfoStrc
{
    int unk0x000;
    D2DrlgGridStrc tGrid04;
    D2DrlgGridStrc tGrid18;
    D2DrlgGridStrc tGrid2C;
    D2DrlgGridStrc tGrid40;
    D2DrlgCoordsStrc tCoords;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
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
T00681490* __stdcall sub_00681560(D2DrlgPathSearchStrc* pSearch, T00681490* pNode);
extern const unsigned char gPathTurns[4][4];
extern const char gPathStepY[4];
extern const char gPathStepX[4];

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

static int __stdcall sub_00681510(T00681490* pNode, int nX, int nY)
{
    return (pNode->nX == nX || pNode->nY == nY) ? 2 : 3;
}

static const unsigned char* __stdcall sub_00681540(unsigned char nDirection, unsigned char nBase)
{
    return gPathTurns[(unsigned char)(nDirection - nBase) & 3];
}

int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordsStrc* pCoords, int nX, int nY); // 0x0066B980

static __declspec(noinline) int __stdcall sub_006815C0(D2DrlgVertexStrc* pGoal, int nX, int nY, D2DrlgLevelStrc* pLevel, T00681490* pNode);

// 0x006815C0
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

    for (T00681490* pParent = pNode; pParent; pParent = pParent->pParent)
    {
        if (pParent->nX == nX && pParent->nY == nY)
        {
            return 0;
        }
    }

    return 1;
}

T00681490* __stdcall sub_Emit_00681630_Search(D2DrlgPathSearchStrc* pSearch, int nMaxCost, D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pGoal)
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
