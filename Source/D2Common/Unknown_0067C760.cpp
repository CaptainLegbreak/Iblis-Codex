#include "D2Drlg.h"
#include "D2DrlgMaps.h"


extern void (__fastcall* gpfnDrlgGridFlagOperations[])(int*, int); // 0x00749BAC

// build: context sub_0067C4D0
static int* __stdcall sub_0067C4D0(D2DrlgGridStrc* pGrid, int nX, int nY)
{
    return &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + nX];
}

// build: context DRLGGRID_AlterGridFlag
static void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation)
{
    gpfnDrlgGridFlagOperations[eOperation](sub_0067C4D0(pGrid, nX, nY), nFlag);
}

// 0x0067C760
void __fastcall sub_0067C760(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag, int eOperation, int bAlterNextVertex)
{
    D2DrlgVertexStrc* pNext = pVertex->pNext;

    if (pVertex->nPosX == pNext->nPosX && pVertex->nPosY == pNext->nPosY)
    {
        DRLGGRID_AlterGridFlag(pGrid, pVertex->nPosX, pVertex->nPosY, nFlag, eOperation);
        return;
    }

    int nX;
    int nY;
    int nEndX;
    int nEndY;
    int bHorizontal;

    if (pVertex->nPosX == pNext->nPosX)
    {
        nX = pVertex->nPosX;
        nEndX = pVertex->nPosX;
        bHorizontal = 0;
        if (pVertex->nPosY < pNext->nPosY)
        {
            nY = pVertex->nPosY;
            nEndY = pNext->nPosY;
        }
        else
        {
            nY = pNext->nPosY;
            nEndY = pVertex->nPosY;
        }
    }
    else
    {
        bHorizontal = 1;
        nY = pVertex->nPosY;
        nEndY = pVertex->nPosY;
        if (pVertex->nPosX < pNext->nPosX)
        {
            nX = pVertex->nPosX;
            nEndX = pNext->nPosX;
        }
        else
        {
            nX = pNext->nPosX;
            nEndX = pVertex->nPosX;
        }
    }

    if (bHorizontal)
    {
        ++nX;
    }
    else
    {
        ++nY;
    }

    while (nX != nEndX || nY != nEndY)
    {
        DRLGGRID_AlterGridFlag(pGrid, nX, nY, nFlag, eOperation);
        if (bHorizontal)
        {
            ++nX;
        }
        else
        {
            ++nY;
        }
    }

    DRLGGRID_AlterGridFlag(pGrid, pVertex->nPosX, pVertex->nPosY, nFlag, eOperation);
    if (bAlterNextVertex)
    {
        DRLGGRID_AlterGridFlag(pGrid, pVertex->pNext->nPosX, pVertex->pNext->nPosY, nFlag, eOperation);
    }
}
