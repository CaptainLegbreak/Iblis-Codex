struct D2DrlgLevelStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

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

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
};

struct D2DrlgLevelStrc
{
    char pad_00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char pad_18[0x1C4 - 0x18];
    D2SeedStrc pSeed;
    char pad_1CC[4];
    int nLevelId;
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

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);
void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset); // 0x0066F520

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

static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor); // 0x0066F3B0

// build: context DRLGTILESUB_TestReplaceSubPreset
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

static __forceinline unsigned int DRLGTILESUB_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int DRLGTILESUB_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return DRLGTILESUB_RollRandomNumberInline(pSeed) % nMax;
    return DRLGTILESUB_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0066F690
int __stdcall sub_0066F690_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup)
{
    D2CoordStrc pCoord[256];
    int bWilderness;
    int bSmallWilderness;
    int* pBox = pOutdoor->field_4;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int bSubType1 = pOutdoor->nLvlSubId == 1;
    const int nFlags = pLevel->pOutdoors->dwFlags & 12;

    if (pLevel->nLevelId >= 2 && pLevel->nLevelId <= 7)
        bWilderness = 1;
    else
        bWilderness = 0;

    const int nOffset = bSubType1 && nFlags ? -1 : 1;
    const int nWidth = pBox[2] - pSubstGroup->tBox.nWidth * pLvlSubTxtRecord->dwGridSize + nOffset;
    const int nHeight = pBox[3] - pSubstGroup->tBox.nHeight * pLvlSubTxtRecord->dwGridSize + 1;
    const int nArea = nWidth * nHeight;
    if (nArea)
    {
        if (bSubType1 && bWilderness && nWidth < 6 && nHeight < 6)
            bSmallWilderness = 1;
        else
            bSmallWilderness = 0;

        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nRand1 = DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, nArea);
            const int nRand2 = DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, nArea);
            const D2CoordStrc tTemp = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tTemp;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nX = pCoord[i].nX;
            const int nY = pCoord[i].nY;
            if (!bSmallWilderness || nX != 2 || nY != 2)
            {
                if (DRLGTILESUB_TestReplaceSubPreset(nX, nY, pSubstGroup, pLvlSubTxtRecord, pOutdoor))
                {
                    DRLGTILESUB_ReplaceSubPreset(nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, (DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, pSubstGroup->field_14) + 1) * (pSubstGroup->tBox.nWidth + 1));
                    if (pLvlSubTxtRecord->dwBordType == 0)
                        return 1;
                    else if (pLvlSubTxtRecord->dwBordType == 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}
