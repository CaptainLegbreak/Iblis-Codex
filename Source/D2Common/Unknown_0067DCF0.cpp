struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
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
    int unk0x00;
    D2DrlgGridStrc tGrid04;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    D2DrlgGridStrc tGrid2C;
    int unk0x40;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    int unk0x54;
    int unk0x58;
    int nWidth;
    int nHeight;
    D2DrlgVertexStrc* pVertex;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    char unk0x18[0x1B8];
    int eLevelId;
};

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0
int __fastcall sub_006755C0_LookupTable(int nA, int nB, int nC);                                             // 0x006755C0
int __fastcall sub_00675600_LookupTable(int nA, int nB, int nC, int nD, int nE);                             // 0x00675600
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);    // 0x0067C4F0
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280

static void sub_0067DCA0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;

    const int nX = pInfo->nWidth - 2;
    const int nY = pInfo->nHeight - 3;
    D2DrlgGridStrc* const pGrid = &pInfo->tGrid2C;
    DRLGGRID_AlterGridFlag(pGrid, pInfo->nWidth - 2, pInfo->nHeight - 4, 0x400, 0);
    DRLGGRID_AlterGridFlag(pGrid, nX, nY, 0x400, 0);
}

static int sub_0067DCE0(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->eLevelId == 117) + 4;
}

// 0x0067DCF0
void __stdcall sub_0067DCF0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    D2DrlgVertexStrc* pVertex = pInfo->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;
    int nSize = sub_0067DCE0(pLevel);

    do
    {
        int nDirX;
        int nDirY;
        int nNextDirX;
        int nNextDirY;
        sub_0067D280(pVertex, &nDirX, &nDirY);
        sub_0067D280(pNext, &nNextDirX, &nNextDirY);

        int nAbsDirX = nDirX < 0 ? -nDirX : nDirX;
        int nAbsDirY = nDirY >= 0 ? nDirY : -nDirY;

        int nX = pVertex->nPosX & ~1;
        int nY = pVertex->nPosY & ~1;
        int nNextX = pNext->nPosX & ~1;
        int nNextY = pNext->nPosY & ~1;
        int nPresetId = sub_006755C0_LookupTable(nDirX, nDirY, nSize);

        if (!(pVertex->dwFlags & 2))
        {
            while (nX != nNextX || nY != nNextY)
            {
                nX += 2 * nDirX;
                nY += 2 * nDirY;
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId, -1, 0);
                DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nX, nY, 1, 0);
            }
        }

        if (pVertex->dwFlags & 1)
        {
            int nMaxX = pVertex->nPosX <= pNext->nPosX ? pNext->nPosX : pVertex->nPosX;
            int nMarkX = (nMaxX - 4 * nAbsDirX) & ~1;
            int nMaxY = pVertex->nPosY > pNext->nPosY ? pVertex->nPosY : pNext->nPosY;
            int nMarkY = (nMaxY - 4 * nAbsDirY) & ~1;
            DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nMarkX, nMarkY, 0x400, 0);
            DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nMarkX + 2 * nAbsDirX, nMarkY + 2 * nAbsDirY, 0x400, 0);
        }

        int nCornerPresetId = sub_00675600_LookupTable(2 * nDirX, 2 * nDirY, 2 * nNextDirX, 2 * nNextDirY, nSize);
        if (nCornerPresetId)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nNextX, nNextY, nCornerPresetId, -1, 0);
            DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nNextX, nNextY, 1, 0);
        }

        pVertex = pNext;
        pNext = pNext->pNext;
    }
    while (pVertex != pInfo->pVertex);

    if (pLevel->eLevelId == 111)
    {
        sub_0067DCA0(pLevel);
    }
}
