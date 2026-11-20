#include "D2Structs.h"
#include "D2Path.h"
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
    char unk0x000[0x464];
    void* hArchive;
    char unk0x468[0x10];
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

D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId);                                                 // 0x0061FA90
void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pLvlSubTxtRecord);                    // 0x006704E0
int __stdcall sub_0066FF50(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord);          // 0x0066FF50
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

static __declspec(noinline) void __stdcall DRLGTILESUB_DoSubstitutions(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pRecord);

// 0x00670170
static void __stdcall DRLGTILESUB_DoSubstitutions(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pRecord)
{
    D2DrlgRoomStrc* pRoom = pOutdoor->pDrlgRoom;
    void* pMemPool = pRoom->ptDrlgLevel->pDrlg->pMemPool;
    D2DrlgFileStrc* pFile = pRecord->pDrlgFile;
    const int nMax = pRecord->nMax[pOutdoor->nSubTheme];
    if (!pFile->nSubstGroups) return;
    for (int nCount = 0; nCount < nMax; ++nCount)
    {
        D2DrlgSubstGroupStrc* pGroup = &pFile->pSubstGroups[SEED_RollLimitedRandomNumber(&pRoom->pSeed, pFile->nSubstGroups)];
        int nHeight = pRoom->nTileHeight - pGroup->tBox.nHeight + 1;
        int nWidth = pRoom->nTileWidth - pGroup->tBox.nWidth + 1;
        if (nWidth > 1 && nHeight > 1)
        {
            const int nTrials = pRecord->nTrials[pOutdoor->nSubTheme];
            if (nTrials == -1)
            {
                const int nAvailableWidth = nWidth - 1;
                const int nArea = nAvailableWidth * (nHeight - 1);
                if (!nArea) continue;
                D2CoordStrc tCoords[256];
                for (int i = 0; i < nArea; ++i)
                {
                    tCoords[i].nX = i % nAvailableWidth;
                    tCoords[i].nY = i / nAvailableWidth;
                }
                for (int i = 0; i < nArea; ++i)
                {
                    unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pRoom->pSeed, nArea);
                    unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pRoom->pSeed, nArea);
                    D2CoordStrc tTemp = tCoords[nRand1];
                    tCoords[nRand1] = tCoords[nRand2];
                    tCoords[nRand2] = tTemp;
                }
                for (int i = 0; i < nArea; ++i)
                {
                    int nX = tCoords[i].nX + 1;
                    int nY = tCoords[i].nY + 1;
                    if (sub_0066FCF0(nX,nY,pOutdoor,pGroup,pRecord))
                    {
                        sub_0066FAD0(pMemPool,nX,nY,pOutdoor,pGroup,pRecord,0);
                        break;
                    }
                }
            }
            else
            {
                for (int i=0; i<nTrials; ++i)
                {
                    int nX = SEED_RollLimitedRandomNumber(&pRoom->pSeed,nWidth-1)+1;
                    int nY = SEED_RollLimitedRandomNumber(&pRoom->pSeed,nHeight-1)+1;
                    if (sub_0066FCF0(nX,nY,pOutdoor,pGroup,pRecord))
                    {
                        sub_0066FAD0(pMemPool,nX,nY,pOutdoor,pGroup,pRecord,0);
                        break;
                    }
                }
            }
        }
    }
}

// build: context sub_006707A0
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
