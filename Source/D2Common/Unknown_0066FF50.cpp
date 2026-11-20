#include "D2Structs.h"

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
    int nSubstMethod;
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
    char unk0x000[0x478];
    void* pMemPool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgDrlgStrc* pDrlg;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x14];
    D2SeedStrc pSeed;
    char unk0x1C[0x18];
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x44[0x14];
    D2DrlgLevelStrc* ptDrlgLevel;
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
    int field_28;
    int nLayers;
    int nSubWaypoint_Shrine;
    int nSubTheme;
    int nSubThemePicked;
};

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570
int __stdcall sub_0066FCF0(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord); // 0x0066FCF0
void __stdcall sub_0066FAD0(void* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nPick); // 0x0066FAD0

static __forceinline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, unsigned int nMax)
{
    if ((int)nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumberHighFirst(pSeed) % nMax;
    return SEED_RollRandomNumberHighFirst(pSeed) & (nMax - 1);
}
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

static __declspec(noinline) int __stdcall sub_0066FE00_TestSubstGroupTiles(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup);

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

// 0x0066FF50
void __stdcall sub_0066FF50(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord)
{
    D2DrlgRoomStrc* pDrlgRoom = pOutdoor->pDrlgRoom;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMemPool;
    D2DrlgFileStrc* pDrlgFile = pLvlSubTxtRecord->pDrlgFile;

    for (int nGroup = 0; nGroup < pDrlgFile->nSubstGroups; ++nGroup)
    {
        D2DrlgSubstGroupStrc* pSubstGroup = &pDrlgFile->pSubstGroups[nGroup];
        const int nWidth = pDrlgRoom->nTileWidth - pSubstGroup->tBox.nWidth + 1;
        const int nHeight = pDrlgRoom->nTileHeight - pSubstGroup->tBox.nHeight + 1;
        if (nWidth > 0 && nHeight > 0)
        {
            switch (pDrlgFile->nSubstMethod)
            {
            case 1:
                for (int nY = 1; nY < nHeight; ++nY)
                {
                    for (int nX = 1; nX < nWidth; ++nX)
                    {
                        if (sub_0066FCF0(nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord))
                        {
                            sub_0066FAD0(pMemPool, nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, 0);
                        }
                    }
                }
                break;

            case 2:
                for (int nY = 0; nY < nHeight; ++nY)
                {
                    for (int nX = 0; nX < nWidth; ++nX)
                    {
                        if (sub_0066FE00_TestSubstGroupTiles(nX, nY, pOutdoor, pLvlSubTxtRecord, pSubstGroup))
                        {
                            const int nRoll = SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, 100);
                            if (pLvlSubTxtRecord->nProb[pOutdoor->nSubTheme] < nRoll)
                            {
                                const int nPick = SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, pSubstGroup->field_14);
                                sub_0066FAD0(pMemPool, nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, (pSubstGroup->tBox.nWidth + 1) * (nPick + 1));
                            }
                        }
                    }
                }
                break;
            }
        }
    }
}
