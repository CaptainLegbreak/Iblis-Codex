#include "D2Drlg.h"
#include "D2DrlgMaps.h"


typedef void (__fastcall* DRLGGRID_FlagOperation)(int* pFlag, int nFlag);
extern DRLGGRID_FlagOperation gpfnDrlgGridFlagOperations[6]; // 0x00749BAC

static int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return nX >= 0 && nX < pDrlgGrid->nWidth && nY >= 0 && nY < pDrlgGrid->nHeight ? 1 : 0;
}

static int* __stdcall sub_0067C4D0(D2DrlgGridStrc* pGrid, int nX, int nY)
{
    return &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + nX];
}

static void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation)
{
    gpfnDrlgGridFlagOperations[eOperation](sub_0067C4D0(pGrid, nX, nY), nFlag);
}

// 0x0067C890
void __fastcall sub_0067C890(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag)
{
    D2DrlgVertexStrc* pCurrent = pVertex;
    if (pVertex)
    {
        do
        {
            const int nX = pCurrent->nPosX;
            const int nY = pCurrent->nPosY;
            pCurrent = pCurrent->pNext;
            if (DRLGGRID_IsPointInsideGridArea(pGrid, nX, nY))
            {
                DRLGGRID_AlterGridFlag(pGrid, nX, nY, nFlag, 0);
            }
        }
        while (pCurrent);
    }
}
