struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[3];
    char unk0x040[0x1C];
    int nGridWidth;
    int nGridHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
};

int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);                      // 0x0067C570

// build: symbol ?DRLGOUTWILD_FindBridgeInColumn@@YGXPAUD2DrlgLevelStrc@@HPAH1@Z 0x0067FB90
static void __stdcall DRLGOUTWILD_FindBridgeInColumn(D2DrlgLevelStrc* pLevel, int nX, int* pX, int* pY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int nY = 1; nY < pOutdoors->nGridWidth - 1; ++nY)
    {
        const int nEntry = sub_0067C570(&pOutdoors->pGrid[0], nX, nY);
        const unsigned int nPacked = sub_0067C570(&pOutdoors->pGrid[2], nX, nY);
        const int nPickedFile = (nPacked >> 16) & 0xF;
        if (nEntry == 28 && nPickedFile == 1)
        {
            *pX = nX;
            *pY = nY;
            return;
        }
    }

    *pX = -1;
    *pY = -1;
}

// 0x0067FC20
void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    DRLGOUTWILD_FindBridgeInColumn(pLevel, pLevel->pOutdoors->nGridWidth / 2 - 1, pX, pY);
}

// 0x0067FC50
void __fastcall sub_0067FC50(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    DRLGOUTWILD_FindBridgeInColumn(pLevel, pLevel->pOutdoors->nGridWidth - 2, pX, pY);
}
