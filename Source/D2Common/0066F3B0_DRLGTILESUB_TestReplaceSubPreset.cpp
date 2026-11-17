struct D2DrlgLevelStrc;

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

struct D2UnkOutdoorStrc
{
    D2DrlgLevelStrc* pLevel;
    int* field_4;
    D2DrlgGridStrc* pGrid1;
    D2DrlgGridStrc* pGrid2;
    int nLevelPrestId;
    int field_14;
    int nLvlSubId;
    unsigned int(__fastcall* field_1C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    int(__fastcall* field_20)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags);
    int(__fastcall* field_24)(D2DrlgLevelStrc* pLevel, int nX, int nY, int a4, int a5, unsigned int a6);
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

// 0x0066F3B0
static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor)
{
    nX -= nX % pLvlSubTxtRecord->dwGridSize;
    nY -= nY % pLvlSubTxtRecord->dwGridSize;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nFloorFlags = sub_0066F350(i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY, pLvlSubTxtRecord);
            const int nWallFlags = sub_0066F380(i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY, pLvlSubTxtRecord);
            const int nPosX = nX + i * pLvlSubTxtRecord->dwGridSize;
            const int nPosY = nY + j * pLvlSubTxtRecord->dwGridSize;

            const int nEntry = DRLGGRID_GetGridEntry(pOutdoor->pGrid1, nPosX, nPosY);
            if (pOutdoor->field_24)
            {
                if (!pOutdoor->field_24(pOutdoor->pLevel, nPosX, nPosY, nEntry, nFloorFlags, nWallFlags))
                {
                    return 0;
                }
            }
            else if (nWallFlags & 1)
            {
                const int nStyle = ((nWallFlags >> 8) & 0xFF) - 1;
                if (nStyle != pOutdoor->field_14 && nStyle + pOutdoor->nLevelPrestId != nEntry)
                {
                    return 0;
                }

                if (!pOutdoor->field_1C(pOutdoor->pLevel, nPosX, nPosY))
                {
                    return 0;
                }
            }
            else if (nFloorFlags & 2)
            {
                if (!pOutdoor->field_20(pOutdoor->pLevel, nPosX, nPosY, 0, 0, 0))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int __stdcall sub_M16_EmitTestReplaceSubPreset(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup, int* pPos)
{
    return DRLGTILESUB_TestReplaceSubPreset(pPos[0], pPos[1], pSubstGroup, pLvlSubTxtRecord, pOutdoor);
}
