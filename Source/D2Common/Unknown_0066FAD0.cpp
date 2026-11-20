#include "D2Common.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
#include "D2DrlgMaps.h"
#include "D2TxtTables.h"

struct D2PresetUnitStrc;



struct D2DrlgSubstGroupStrc
{
    D2DrlgCoordStrc tBox;
    int field_10;
    int field_14;
};




struct D2DrlgDrlgStrc
{
    char unk0x000[0x464];
    void* hArchive;
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

static int __stdcall sub_0066F380(D2LvlSubTxt* pLvlSubTxtRecord, int nLayer, int nX, int nY)
{
    return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pWallGrid[nLayer], nX, nY);
}

static int __stdcall DRLGTILESUB_GetTileTypeEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nLayer, int nX, int nY)
{
    return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pTileTypeGrid[nLayer], nX, nY);
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

// 0x0066FAD0
void __stdcall sub_0066FAD0(void* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nWallLayers = pLvlSubTxtRecord->pDrlgFile->nWallLayers;
    D2DrlgRoomStrc* pDrlgRoom = pOutdoor->pDrlgRoom;
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    const int nBaseY = pSubstGroup->tBox.nPosY;
    int nCounter = 0;
    int nFlags = 0;
    int i;
    int j;

    for (j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (i = 0; i < pSubstGroup->tBox.nWidth;)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j) & 0x8000000)
            {
                ++nCounter;
                ++i;
            }
            else
            {
                ++i;
            }
        }
    }

    DRLGROOMTILE_ReallocRoofTileGrid(pMemPool, pTileGrid, nCounter);

    for (j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            nFlags = sub_0066F350(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            if (nFlags & 2)
            {
                DRLGGRID_AlterGridFlag(pOutdoor->pFloorGrid, nX + i, nY + j, nFlags | 0x80, 3);
            }

            for (int nLayer = 0; nLayer < nWallLayers; ++nLayer)
            {
                nFlags = sub_0066F380(pLvlSubTxtRecord, nLayer, nBaseX + i, nBaseY + j);
                if (nFlags & 1 && pOutdoor->pWallsGrids[nLayer])
                {
                    DRLGGRID_AlterGridFlag(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j, nFlags, 3);
                }

                nFlags = DRLGTILESUB_GetTileTypeEntry(pLvlSubTxtRecord, nLayer, nBaseX + i, nBaseY + j);
                if (nFlags && pOutdoor->pOutdoorRooms[nLayer])
                {
                    DRLGGRID_AlterGridFlag(&pOutdoor->pOutdoorRooms[nLayer]->pTileTypeGrid, nX + i, nY + j, nFlags, 3);
                }
            }

            nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j);
            if (nFlags & 0x8000000)
            {
                DRLGROOMTILE_InitTileShadow(pDrlgRoom, pDrlgRoom->pDrlgCoord.nPosX + i + nX, pDrlgRoom->pDrlgCoord.nPosY + j + nY, nFlags);
            }
        }
    }

    sub_0066FA10(nX, nY, pSubstGroup, pOutdoor, pMemPool, pLvlSubTxtRecord);
}
