#include "D2Common.h"

struct D2PresetUnitStrc;

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

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    int unk0x10;
    int nUnitType;
    int nYpos;
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
    void* pTileTypeLayer[4];
    void* pWallLayer[4];
    void* pFloorLayer[2];
    void* pShadowLayer;
    int unk0x48;
    int nSubstGroups;
    D2DrlgSubstGroupStrc* pSubstGroups;
    D2PresetUnitStrc* pPresetUnit;
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
    D2DrlgGridStrc pShadowGrid;
    int nProb[5];
    int nTrials[5];
    int nMax[5];
    int unk0x158;
};

struct D2DrlgDrlgStrc
{
    char unk0x000[0x464];
    void* hArchive;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgDrlgStrc* pDrlg;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    int nTileXPos;
    int nTileYPos;
    char unk0x3C[0x18];
    D2DrlgTileGridStrc* ptDrlgTiles;
    D2DrlgLevelStrc* ptDrlgLevel;
};

struct D2DrlgOutdoorRoomStrc
{
    D2DrlgGridStrc pTileTypeGrid;
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
    int(__fastcall* field_28)(D2DrlgLevelStrc* pLevel, int nStyle, int a3);
    void(__fastcall* field_2C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_30)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_34)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nRand, int a6);
};

struct D2UnkOutdoorStrc2
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgOutdoorRoomStrc* pOutdoorRooms[4];
    D2DrlgGridStrc* pWallsGrids[4];
    D2DrlgGridStrc* pFloorGrid;
    int field_28;
    int nLayers;
    int nSubWaypoint_Shrine;
    int nSubTheme;
    int nSubThemePicked;
};

D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId);                                                 // 0x0061FA90
D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30
void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pLvlSubTxtRecord);                    // 0x006704E0
void __stdcall sub_0066FF50(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord); // 0x0066FF50
int __stdcall DRLGTILESUB_DoSubstitutions(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord);         // 0x00670170
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570

static int __stdcall sub_0066F350(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    if (pLvlSubTxtRecord->pDrlgFile->nFloorLayers)
    {
        return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, nX, nY);
    }

    return 0;
}

static int __stdcall sub_0066F380(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    if (pLvlSubTxtRecord->pDrlgFile->nWallLayers)
    {
        return DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, nX, nY);
    }

    return 0;
}

void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nBaseY = pSubstGroup->tBox.nPosY;

    nX -= nX % pLvlSubTxtRecord->dwGridSize;
    nY -= nY % pLvlSubTxtRecord->dwGridSize;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nWallFlags = sub_0066F380(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            const int nFloorFlags = sub_0066F350(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            const int nPosX = nX + i * pLvlSubTxtRecord->dwGridSize;
            const int nPosY = nY + j * pLvlSubTxtRecord->dwGridSize;
            if (nWallFlags & 1)
            {
                const int nStyle = (nWallFlags >> 8) & 0xFF;
                const int nSubStyle = nStyle - 1;
                int nPresetId = 0;
                if (pOutdoor->field_28)
                {
                    nPresetId = pOutdoor->field_28(pLevel, ((unsigned int)nWallFlags >> 20) & 0x3F, nStyle);
                }
                else
                {
                    nPresetId = nSubStyle + pOutdoor->nLevelPrestId;
                }

                if (nPresetId != -5 && nSubStyle != pOutdoor->field_14)
                {
                    pOutdoor->field_34(pLevel, nPosX, nPosY, nPresetId, 0, 1);
                }
            }
            else if (nFloorFlags & 2)
            {
                pOutdoor->field_2C(pLevel, nPosX, nPosY);
            }
            else
            {
                pOutdoor->field_30(pLevel, nPosX, nPosY);
            }
        }
    }
}

// 0x0066FA10
static void __stdcall sub_0066FA10(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2UnkOutdoorStrc2* pOutdoor, void* pMemPool, D2LvlSubTxt* pLvlSubTxtRecord)
{
    int nSubX = nX;
    int nSubY = nY;
    int nMinX = pSubstGroup->tBox.nPosX;
    int nMinY = pSubstGroup->tBox.nPosY;
    int nSizeX = pSubstGroup->tBox.nWidth;
    int nSizeY = pSubstGroup->tBox.nHeight;

    DUNGEON_GameTileToSubtileCoords(&nSubX, &nSubY);
    DUNGEON_GameTileToSubtileCoords(&nMinX, &nMinY);
    DUNGEON_GameTileToSubtileCoords(&nSizeX, &nSizeY);

    for (D2PresetUnitStrc* pPresetUnit = pLvlSubTxtRecord->pDrlgFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->nXpos > nMinX && pPresetUnit->nYpos > nMinY && pPresetUnit->nXpos < nMinX + nSizeX && pPresetUnit->nYpos < nMinY + nSizeY)
        {
            DRLGROOM_AllocPresetUnit(pOutdoor->pDrlgRoom, pMemPool, pPresetUnit->nUnitType, pPresetUnit->nIndex, pPresetUnit->nMode, nSubX + pPresetUnit->nXpos - nMinX, nSubY + pPresetUnit->nYpos - nMinY);
        }
    }
}

void __stdcall sub_0066FAD0(void* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nWallLayers = pLvlSubTxtRecord->pDrlgFile->nWallLayers;
    D2DrlgRoomStrc* pDrlgRoom = pOutdoor->pDrlgRoom;
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    const int nBaseY = pSubstGroup->tBox.nPosY;
    int nCounter = 0;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j) & 0x8000000)
            {
                ++nCounter;
            }
        }
    }

    DRLGROOMTILE_ReallocRoofTileGrid(pMemPool, pTileGrid, nCounter);

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            int nFlags = sub_0066F350(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            if (nFlags & 2)
            {
                DRLGGRID_AlterGridFlag(pOutdoor->pFloorGrid, nX + i, nY + j, nFlags | 0x80, 3);
            }

            for (int nLayer = 0; nLayer < nWallLayers; ++nLayer)
            {
                nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pWallGrid[nLayer], nBaseX + i, nBaseY + j);
                if (nFlags & 1 && pOutdoor->pWallsGrids[nLayer])
                {
                    DRLGGRID_AlterGridFlag(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j, nFlags, 3);
                }

                nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pTileTypeGrid[nLayer], nBaseX + i, nBaseY + j);
                if (nFlags && pOutdoor->pOutdoorRooms[nLayer])
                {
                    DRLGGRID_AlterGridFlag(&pOutdoor->pOutdoorRooms[nLayer]->pTileTypeGrid, nX + i, nY + j, nFlags, 3);
                }
            }

            nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j);
            if (nFlags & 0x8000000)
            {
                DRLGROOMTILE_InitTileShadow(pDrlgRoom, pDrlgRoom->nTileXPos + i + nX, pDrlgRoom->nTileYPos + j + nY, nFlags);
            }
        }
    }

    sub_0066FA10(nX, nY, pSubstGroup, pOutdoor, pMemPool, pLvlSubTxtRecord);
}

int __stdcall sub_0066FCF0(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord)
{
    const int nLayers = pOutdoor->nLayers;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY) & 2
                || pLvlSubTxtRecord->pWallGrid[0].nWidth && DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY) & 1)
            {
                const int nFlags = DRLGGRID_GetGridEntry(pOutdoor->pFloorGrid, nX + i, nY + j);
                if (nFlags & 0x3F0FF00 || !(nFlags & 2))
                {
                    return 0;
                }

                for (int nLayer = 0; nLayer < nLayers; ++nLayer)
                {
                    if (pOutdoor->pWallsGrids[nLayer] && DRLGGRID_GetGridEntry(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j) & 1)
                    {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

void __fastcall sub_006707A0(D2UnkOutdoorStrc2* pOutdoor)
{
    if (pOutdoor->nSubWaypoint_Shrine != -1)
    {
        D2LvlSubTxt* pLvlSubTxtRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nSubWaypoint_Shrine);
        unsigned int nThemeFlag = pOutdoor->nSubThemePicked;
        void* hArchive = pOutdoor->pDrlgRoom->ptDrlgLevel->pDrlg->hArchive;
        while (nThemeFlag)
        {
            if (nThemeFlag & 1)
            {
                DRLGTILESUB_InitializeDrlgFile(hArchive, pLvlSubTxtRecord);

                if (pLvlSubTxtRecord->dwCheckAll)
                {
                    sub_0066FF50(pOutdoor, pLvlSubTxtRecord);
                }
                else
                {
                    DRLGTILESUB_DoSubstitutions(pOutdoor, pLvlSubTxtRecord);
                }
            }

            nThemeFlag >>= 1;
            ++pLvlSubTxtRecord;
        }
    }
}
