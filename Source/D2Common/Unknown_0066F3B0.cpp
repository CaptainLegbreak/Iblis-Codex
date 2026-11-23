#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2TxtTables.h"
#include "D2DrlgRooms.h"

struct D2DrlgCoordStrc;
struct D2DrlgSubstGroupStrc;
struct D2LvlSubTxt;
struct D2UnkOutdoorStrc;
union D2SeedStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2CoordStrc;
struct D2DrlgOutdoorRoomStrc;
struct D2UnkOutdoorStrc2;

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

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset); // 0x0066F520
static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor); // 0x0066F3B0


extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0
extern D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId); // 0x0061FA90
extern int __stdcall sub_0066F690_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord, D2DrlgSubstGroupStrc* pGroup); // 0x0066F690
extern void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pRecord); // 0x006704E0

struct D2UnkOutdoorStrc2
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgOutdoorRoomStrc* pOutdoorRooms[4];
    D2DrlgGridStrc* pWallsGrids[4];
    D2DrlgGridStrc* pFloorGrid;
};

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

static inline unsigned int DRLGTILESUB_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int DRLGTILESUB_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
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

    if (pLevel->eLevelId >= 2 && pLevel->eLevelId <= 7)
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
                    DRLGTILESUB_ReplaceSubPreset(nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, (DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, pSubstGroup->nSubstGroup) + 1) * (pSubstGroup->tBox.nWidth + 1));
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

// 0x0066F990
static void __stdcall sub_0066F990_ApplySecondaryGroups(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord)
{
    D2DrlgFileStrc* pFile = pRecord->pDrlgFile;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nGroups = pFile->nSubstGroups;
    int nStart = 0;
    if (nGroups)
    {
        if (pOutdoor->field_14 == -1)
            pOutdoor->field_14 = 62;
        if (!pRecord->dwBordType)
            nStart = sub_0045C3E0_RollLimited(&pLevel->pSeed, nGroups);
        for (int i = 0; i < nGroups; ++i)
        {
            if (sub_0066F690_ApplySubstGroup(pOutdoor, pRecord, &pFile->pSubstGroups[(nStart + i) % nGroups])
                && !pRecord->dwBordType)
                break;
        }
    }
}

// 0x00670750
void __fastcall sub_00670750_ApplySubstitutionBorder(D2UnkOutdoorStrc* pOutdoor)
{
    D2LvlSubTxt* pRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nLvlSubId);
    void* hArchive = pOutdoor->pLevel->pDrlg->hArchive;
    while (pRecord->dwType == pOutdoor->nLvlSubId)
    {
        DRLGTILESUB_InitializeDrlgFile(hArchive, pRecord);
        sub_0066F990_ApplySecondaryGroups(pOutdoor, pRecord);
        ++pRecord;
    }
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
