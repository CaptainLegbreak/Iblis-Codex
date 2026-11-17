struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

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

    pDrlgGrid->unk0x10 = 1;
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
