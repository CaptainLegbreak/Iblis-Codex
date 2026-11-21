#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"
#include "D2TxtTables.h"






struct D2DrlgDrlgStrc
{
    char unk0x000[0x478];
    void* pMemPool;
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

static inline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, unsigned int nMax)
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

static int __stdcall sub_0066FE00_TestSubstGroupTiles(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup);

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
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgFileStrc* pDrlgFile = pLvlSubTxtRecord->pDrlgFile;

    for (int nGroup = 0; nGroup < pDrlgFile->nSubstGroups; ++nGroup)
    {
        D2DrlgSubstGroupStrc* pSubstGroup = &pDrlgFile->pSubstGroups[nGroup];
        const int nWidth = pDrlgRoom->pDrlgCoord.nWidth - pSubstGroup->tBox.nWidth + 1;
        const int nHeight = pDrlgRoom->pDrlgCoord.nHeight - pSubstGroup->tBox.nHeight + 1;
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
                                const int nPick = SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, pSubstGroup->nSubstGroup);
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
