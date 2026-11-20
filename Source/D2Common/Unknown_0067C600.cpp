#include "D2Structs.h"
#include "D2Path.h"
struct D2DrlgCoordStrc;
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

enum D2DrlgGridFlagOperation
{
    DRLGGRID_FLAG_OR = 0,
    DRLGGRID_FLAG_AND = 1,
    DRLGGRID_FLAG_XOR = 2,
    DRLGGRID_FLAG_OVERWRITE = 3,
    DRLGGRID_FLAG_OVERWRITE_IF_ZERO = 4,
    DRLGGRID_FLAG_AND_NEGATED = 5
};

extern "C" const char gszDrlgGridSourceFile;

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY); // 0x0066B980
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __fastcall sub_0067C420(int* pFlag, int nFlag);

void __fastcall sub_0067C430(int* pFlag, int nFlag);

void __fastcall sub_0067C440(int* pFlag, int nFlag);

void __fastcall sub_0067C450(int* pFlag, int nFlag);

void __fastcall sub_0067C460(int* pFlag, int nFlag);

void __fastcall sub_0067C470(int* pFlag, int nFlag);

static void (__fastcall* gpfnDrlgGridFlagOperations[])(int*, int) = // 0x00749BAC
{
    sub_0067C430,
    sub_0067C440,
    sub_0067C450,
    sub_0067C420,
    sub_0067C460,
    sub_0067C470,
};

int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid);

int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pGrid, int nX, int nY);

int* __stdcall sub_0067C4D0(D2DrlgGridStrc* pGrid, int nX, int nY);

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);

void __fastcall sub_0067C520(D2DrlgGridStrc* pGrid, D2CoordStrc* pCoord, int nFlag, int eOperation);

int* __fastcall DRLGGRID_GetGridCellPtr(D2DrlgGridStrc* pGrid, int nX, int nY);

int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);

void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);

// 0x0067C600
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    int* pTopCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[0]];
    int* pBottomCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[pGrid->nHeight - 1]];

    for (int nX = 0; nX < pGrid->nWidth; ++nX)
    {
        gpfnDrlgGridFlagOperations[eOperation](pTopCell, nFlag);
        ++pTopCell;
        gpfnDrlgGridFlagOperations[eOperation](pBottomCell, nFlag);
        ++pBottomCell;
    }

    for (int nY = 1; nY < pGrid->nHeight; ++nY)
    {
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY]], nFlag);
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + pGrid->nWidth - 1], nFlag);
    }
}

void __fastcall sub_0067C6D0(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);

void __fastcall sub_0067C760(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag, int eOperation, int bAlterNextVertex);

void __fastcall sub_0067C890(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag);

void __fastcall sub_0067C8E0(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pCoords, int nFlag, int eOperation, int nSize);

void __fastcall sub_0067CB60(D2DrlgGridStrc* pDstGrid, D2DrlgGridStrc* pSrcGrid);

void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);

void __fastcall sub_0067CBF0(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellsFlags, int* pCellsRowOffsets);

void __fastcall sub_0067CC60(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, int nWidth, int nHeight);

void __fastcall sub_0067CCC0(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride);

void __fastcall DRLGGRID_AssignSubArea(D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride, int* pCellsRowOffsets);

void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);

void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);
