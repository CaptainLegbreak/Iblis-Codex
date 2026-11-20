#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"

struct D2CoordStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgVertexStrc;
struct D2DrlgCoordStrc;




struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

enum D2DrlgGridFlagOperation
{
    DRLGGRID_FLAG_OR = 0,
    DRLGGRID_FLAG_AND = 1,
    DRLGGRID_FLAG_XOR = 2,
    DRLGGRID_FLAG_OVERWRITE = 3,
    DRLGGRID_FLAG_OVERWRITE_IF_ZERO = 4,
    DRLGGRID_FLAG_AND_NEGATED = 5
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordsStrc* pCoords, int nX, int nY); // 0x0066B980
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pGrid, int nX, int nY);
int* __fastcall DRLGGRID_GetGridCellPtr(D2DrlgGridStrc* pGrid, int nX, int nY);
int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);
void __fastcall DRLGGRID_AssignSubArea(D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride, int* pCellsRowOffsets);
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);


// 0x0067C420
static void __fastcall sub_0067C420(int* pFlag, int nFlag)
{
    *pFlag = nFlag;
}

// 0x0067C430
static void __fastcall sub_0067C430(int* pFlag, int nFlag)
{
    *pFlag |= nFlag;
}

// 0x0067C440
static void __fastcall sub_0067C440(int* pFlag, int nFlag)
{
    *pFlag &= nFlag;
}

// 0x0067C450
static void __fastcall sub_0067C450(int* pFlag, int nFlag)
{
    *pFlag ^= nFlag;
}

// 0x0067C460
static void __fastcall sub_0067C460(int* pFlag, int nFlag)
{
    *pFlag = *pFlag ? *pFlag : nFlag;
}

// 0x0067C470
static void __fastcall sub_0067C470(int* pFlag, int nFlag)
{
    *pFlag &= ~nFlag;
}

static void (__fastcall* gpfnDrlgGridFlagOperations[])(int*, int) = // 0x00749BAC
{
    sub_0067C430,
    sub_0067C440,
    sub_0067C450,
    sub_0067C420,
    sub_0067C460,
    sub_0067C470,
};

// 0x0067C480
int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid)
{
    if (pGrid && pGrid->pCellsFlags)
    {
        return 1;
    }

    return 0;
}

static int* __stdcall sub_0067C4D0(D2DrlgGridStrc* pGrid, int nX, int nY)
{
    return &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + nX];
}

// 0x0067C4F0
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation)
{
    gpfnDrlgGridFlagOperations[eOperation](sub_0067C4D0(pGrid, nX, nY), nFlag);
}

// 0x0067C520
void __fastcall sub_0067C520(D2DrlgGridStrc* pGrid, D2CoordStrc* pCoord, int nFlag, int eOperation)
{
    gpfnDrlgGridFlagOperations[eOperation](sub_0067C4D0(pGrid, pCoord->nX, pCoord->nY), nFlag);
}

// 0x0067C590
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    for (int nY = 0; nY < pGrid->nHeight; ++nY)
    {
        int* pCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY]];
        for (int nX = 0; nX < pGrid->nWidth; ++nX)
        {
            gpfnDrlgGridFlagOperations[eOperation](pCell, nFlag);
            ++pCell;
        }
    }
}

// build: context DRLGGRID_AlterEdgeGridFlags
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    int* pTopCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[0]];
    int* pBottomCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[pGrid->nHeight - 1]];

    for (int nX = 0; nX < pGrid->nWidth; ++nX)
    {
        gpfnDrlgGridFlagOperations[eOperation](pTopCell, nFlag);
        gpfnDrlgGridFlagOperations[eOperation](pBottomCell, nFlag);
        ++pTopCell;
        ++pBottomCell;
    }

    for (int nY = 1; nY < pGrid->nHeight; ++nY)
    {
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY]], nFlag);
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + pGrid->nWidth - 1], nFlag);
    }
}

// 0x0067C6D0
void __fastcall sub_0067C6D0(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    int* pCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[pGrid->nHeight - 1]];

    for (int nX = 0; nX < pGrid->nWidth - 1; ++nX)
    {
        gpfnDrlgGridFlagOperations[eOperation](pCell, nFlag);
        ++pCell;
    }

    for (int nY = 0; nY < pGrid->nHeight; ++nY)
    {
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + pGrid->nWidth - 1], nFlag);
    }
}

// build: context sub_0067C760
void __fastcall sub_0067C760(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag, int eOperation, int bAlterNextVertex)
{
    if (pVertex->nPosX == pVertex->pNext->nPosX && pVertex->nPosY == pVertex->pNext->nPosY)
    {
        DRLGGRID_AlterGridFlag(pGrid, pVertex->nPosX, pVertex->nPosY, nFlag, eOperation);
        return;
    }

    int nX = 0;
    int nY = 0;
    int nEndX = 0;
    int nEndY = 0;
    int bHorizontal = 0;

    if (pVertex->nPosX == pVertex->pNext->nPosX)
    {
        bHorizontal = 0;
        nX = pVertex->nPosX;
        nEndX = pVertex->nPosX;
        if (pVertex->nPosY < pVertex->pNext->nPosY)
        {
            nY = pVertex->nPosY;
            nEndY = pVertex->pNext->nPosY;
        }
        else
        {
            nY = pVertex->pNext->nPosY;
            nEndY = pVertex->nPosY;
        }
        ++nY;
    }
    else
    {
        bHorizontal = 1;
        nY = pVertex->nPosY;
        nEndY = pVertex->nPosY;
        if (pVertex->nPosX < pVertex->pNext->nPosX)
        {
            nX = pVertex->nPosX;
            nEndX = pVertex->pNext->nPosX;
        }
        else
        {
            nX = pVertex->pNext->nPosX;
            nEndX = pVertex->nPosX;
        }
        ++nX;
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

// build: context sub_0067C890
void __fastcall sub_0067C890(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag)
{
    while (pVertex)
    {
        if (DRLGGRID_IsPointInsideGridArea(pGrid, pVertex->nPosX, pVertex->nPosY))
        {
            DRLGGRID_AlterGridFlag(pGrid, pVertex->nPosX, pVertex->nPosY, nFlag, DRLGGRID_FLAG_OR);
        }
        pVertex = pVertex->pNext;
    }
}

// build: context sub_0067C8E0
void __fastcall sub_0067C8E0(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pCoords, int nFlag, int eOperation, int nSize)
{
    int nX = pVertex->nPosX;
    int nY = pVertex->nPosY;
    int nDiffX = pVertex->pNext->nPosX - nX;
    int nDiffY = pVertex->pNext->nPosY - nY;
    int nStepX = 0;
    int nStepY = 0;

    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
        nStepX = -1;
    }
    else
    {
        nStepX = 1;
    }

    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
        nStepY = -1;
    }
    else
    {
        nStepY = 1;
    }

    int nOffsetX = nX - pCoords->nSubtileX;
    int nOffsetY = nY - pCoords->nSubtileY;
    int nError = 0;

    if (nDiffX < nDiffY)
    {
        for (int i = 0; i < nSize; ++i)
        {
            if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX + i, nY))
            {
                DRLGGRID_AlterGridFlag(pGrid, nOffsetX + i, nOffsetY, nFlag, eOperation);
            }
        }

        for (int j = 0; j < nDiffY; ++j)
        {
            nY += nStepY;
            nError += nDiffX;
            if (nError > nDiffY)
            {
                nX += nStepX;
                nError -= nDiffY;
            }

            nOffsetX = nX - pCoords->nSubtileX;
            nOffsetY = nY - pCoords->nSubtileY;
            for (int i = 0; i < nSize; ++i)
            {
                if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX + i, nY))
                {
                    DRLGGRID_AlterGridFlag(pGrid, nOffsetX + i, nOffsetY, nFlag, eOperation);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < nSize; ++i)
        {
            if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX, nY + i))
            {
                DRLGGRID_AlterGridFlag(pGrid, nOffsetX, nOffsetY + i, nFlag, eOperation);
            }
        }

        for (int j = 0; j < nDiffX; ++j)
        {
            nX += nStepX;
            nError += nDiffY;
            if (nError > nDiffX)
            {
                nY += nStepY;
                nError -= nDiffX;
            }

            nOffsetX = nX - pCoords->nSubtileX;
            nOffsetY = nY - pCoords->nSubtileY;
            for (int i = 0; i < nSize; ++i)
            {
                if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX, nY + i))
                {
                    DRLGGRID_AlterGridFlag(pGrid, nOffsetX, nOffsetY + i, nFlag, eOperation);
                }
            }
        }
    }
}

// 0x0067CB60
void __fastcall sub_0067CB60(D2DrlgGridStrc* pDstGrid, D2DrlgGridStrc* pSrcGrid)
{
    memcpy(pDstGrid->pCellsFlags, pSrcGrid->pCellsFlags, sizeof(int) * pSrcGrid->nHeight * pSrcGrid->nWidth);
}

// 0x0067CB80
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight)
{
    pGrid->nWidth = nWidth;
    pGrid->nHeight = nHeight;

    int nSize = sizeof(int) * (nWidth + 1) * nHeight;
    pGrid->pCellsRowOffsets = (int*)sub_0040B430(pMemPool, nSize, ".\\DRLG\\DrlgGrid.cpp", 407, 0);
    memset(pGrid->pCellsRowOffsets, 0, nSize);
    pGrid->pCellsFlags = &pGrid->pCellsRowOffsets[nHeight];

    int nOffset = 0;
    for (int i = 0; i < nHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pGrid->nFlags = 0;
}

// 0x0067CBF0
void __fastcall sub_0067CBF0(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellsFlags, int* pCellsRowOffsets)
{
    pGrid->nWidth = nWidth;
    pGrid->nHeight = nHeight;
    pGrid->pCellsFlags = pCellsFlags;
    memset(pCellsFlags, 0, sizeof(int) * nWidth * nHeight);
    pGrid->pCellsRowOffsets = pCellsRowOffsets;

    int nOffset = 0;
    for (int i = 0; i < nHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pGrid->nFlags = 0;
}

// 0x0067CC60
void __fastcall sub_0067CC60(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, int nWidth, int nHeight)
{
    pGrid->nWidth = nWidth;
    pGrid->nHeight = nHeight;
    pGrid->pCellsFlags = pCellsFlags;
    pGrid->pCellsRowOffsets = (int*)sub_0040B430(pMemPool, sizeof(int) * nHeight, ".\\DRLG\\DrlgGrid.cpp", 464, 0);

    int nOffset = 0;
    for (int i = 0; i < nHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pGrid->nFlags = 1;
}

// 0x0067CCC0
void __fastcall sub_0067CCC0(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride)
{
    pGrid->nWidth = pCoords->nSubtileWidth;
    pGrid->nHeight = pCoords->nSubtileHeight;
    pGrid->pCellsFlags = &pCellsFlags[pCoords->nSubtileY * nStride + pCoords->nSubtileX];
    pGrid->pCellsRowOffsets = (int*)sub_0040B430(pMemPool, sizeof(int) * pCoords->nSubtileHeight, ".\\DRLG\\DrlgGrid.cpp", 492, 0);

    int nOffset = 0;
    for (int i = 0; i < pCoords->nSubtileHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nStride;
    }

    pGrid->nFlags = 1;
}

// 0x0067CDC0
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid)
{
    pGrid->pCellsFlags = 0;
    pGrid->pCellsRowOffsets = 0;
}

// 0x0067C4A0
int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return nX >= 0 && nX < pDrlgGrid->nWidth && nY >= 0 && nY < pDrlgGrid->nHeight ? 1 : 0;
}

// 0x0067C550
int* __fastcall DRLGGRID_GetGridFlagsPointer(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return &pDrlgGrid->pCellsFlags[nX + pDrlgGrid->pCellsRowOffsets[nY]];
}

// 0x0067C570
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return pDrlgGrid->pCellsFlags[nX + pDrlgGrid->pCellsRowOffsets[nY]];
}

// 0x0067CD30
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pDrlgGrid, int* pCellPos, D2DrlgCoordStrc* pDrlgCoord, int nWidth, int* pCellFlags)
{
    pDrlgGrid->nWidth = pDrlgCoord->nWidth;
    pDrlgGrid->nHeight = pDrlgCoord->nHeight;
    pDrlgGrid->pCellsFlags = &pCellPos[pDrlgCoord->nPosY * nWidth + pDrlgCoord->nPosX];
    pDrlgGrid->pCellsRowOffsets = pCellFlags;

    int nOffset = 0;
    for (int i = 0; i < pDrlgCoord->nHeight; ++i)
    {
        pDrlgGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pDrlgGrid->nFlags = 1;
}

// 0x0067CD90
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pDrlgGrid)
{
    if (pDrlgGrid->pCellsRowOffsets)
    {
        sub_0040B480(pMemPool, pDrlgGrid->pCellsRowOffsets, ".\\DRLG\\DrlgGrid.cpp", 0x218, 0);
    }

    pDrlgGrid->pCellsFlags = 0;
    pDrlgGrid->pCellsRowOffsets = 0;
}
