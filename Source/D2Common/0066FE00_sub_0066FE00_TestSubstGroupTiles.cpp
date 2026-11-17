struct D2DrlgRoomStrc;

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int nFlags;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgSubstGroupStrc
{
    D2DrlgCoordStrc tBox;
    int field_10;
    int field_14;
};

struct D2DrlgFileStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nWidth;
    int nHeight;
    int nWallLayers;
    int nFloorLayers;
};

struct D2LvlSubTxt
{
    int dwType;
    char szFile[60];
    int dwCheckAll;
    int dwBordType;
    int dwDt1Mask;
    int dwGridSize;
    D2DrlgFileStrc* pDrlgFile;
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pFloorGrid;
};

struct D2DrlgOutdoorRoomStrc
{
    D2DrlgGridStrc pTileTypeGrid;
};

struct D2UnkOutdoorStrc2
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgOutdoorRoomStrc* pOutdoorRooms[4];
    D2DrlgGridStrc* pWallsGrids[4];
    D2DrlgGridStrc* pFloorGrid;
};

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570

static int __stdcall sub_0066F350(int nX, int nY, D2LvlSubTxt* pLvlSubTxtRecord)
{
    if (pLvlSubTxtRecord->pDrlgFile->nFloorLayers)
    {
        return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, nX, nY);
    }

    return 0;
}

static int __stdcall sub_0066F380(int nX, int nY, D2LvlSubTxt* pLvlSubTxtRecord)
{
    if (pLvlSubTxtRecord->pDrlgFile->nWallLayers)
    {
        return DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, nX, nY);
    }

    return 0;
}

// 0x0066FE00
static int __stdcall sub_0066FE00_TestSubstGroupTiles(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup)
{
    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nTileType = DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pTileTypeGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nTileType != DRLGGRID_GetGridEntry(&pOutdoor->pOutdoorRooms[0]->pTileTypeGrid, i + nX, j + nY))
            {
                return 0;
            }

            const int nFloorFlags1 = sub_0066F350(i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY, pLvlSubTxtRecord);
            if (nFloorFlags1 & 2)
            {
                const int nFloorFlags2 = DRLGGRID_GetGridEntry(pOutdoor->pFloorGrid, i + nX, j + nY);
                if (!(nFloorFlags2 & 2))
                {
                    return 0;
                }

                if ((nFloorFlags1 ^ nFloorFlags2) & 0x3F0FF00)
                {
                    return 0;
                }
            }

            const int nWallFlags1 = sub_0066F380(i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY, pLvlSubTxtRecord);
            if (nWallFlags1 & 1)
            {
                const int nWallFlags2 = DRLGGRID_GetGridEntry(pOutdoor->pWallsGrids[0], i + nX, j + nY);
                if (!(nWallFlags2 & 1))
                {
                    return 0;
                }

                if ((nWallFlags1 ^ nWallFlags2) & 0x3F0FF00)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int __stdcall sub_M16_EmitTestSubstGroupTiles(D2DrlgSubstGroupStrc* pSubstGroup, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    return sub_0066FE00_TestSubstGroupTiles(nX, nY, pOutdoor, pLvlSubTxtRecord, pSubstGroup);
}
