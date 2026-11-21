#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

struct D2DrlgOutdoorInfoStrc;
union D2SeedStrc;
struct D2LvlPrestRecordStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgVertexStrc;
struct D2DrlgGridStrc;
struct D2DrlgLevelStrc;
struct D2CoordStrc;





struct D2LvlPrestRecordStrc
{
    int f_0;
    char pad_04[60];
    int nFiles;
};

extern D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0
extern void* __fastcall sub_0040B430(void* pPool, int nSize, const char* szFile, int nLine, int nZero); // 0x0040B430
extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0
extern int __fastcall DRLGPRESET_GetSizeX(int nPresetId); // 0x00666FD0
extern int __fastcall DRLGPRESET_GetSizeY(int nPresetId); // 0x00666FE0
extern void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0



int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, int nFlags); // 0x00674230
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int bBorder); // 0x006743C0


int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel); // 0x0067DCE0


extern "C" const int gdwAct12ShrineFlags_006F061C[4]; // 0x006F061C
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570

// 0x00674320
static __declspec(noinline) int __cdecl sub_00674320_PickFile(D2DrlgLevelStrc* pLevel, int nPresetId)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgBuildStrc* pFile = pLevel->pBuild;
    while (pFile)
    {
        if (pFile->nPreset == nPresetId)
            break;
        pFile = pFile->pNext;
    }
    if (!pFile)
    {
        D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(nPresetId);
        pFile = (D2DrlgBuildStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgBuildStrc), ".\\DRLG\\Outdoors.cpp", 249, 0);
        memset(pFile, 0, sizeof(D2DrlgBuildStrc));
        pFile->nPreset = pRecord->f_0;
        pFile->nDivisor = pRecord->nFiles;
        pFile->nRand = sub_0045C3E0_RollLimited(&pLevel->pSeed, pRecord->nFiles);
        pFile->pNext = pLevel->pBuild;
        pLevel->pBuild = pFile;
    }
    pFile->nRand = (pFile->nRand + 1) % pFile->nDivisor;
    return pFile->nRand;
}

// 0x006743C0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const int nWidth = DRLGPRESET_GetSizeX(nPresetId) / 8;
    const int nHeight = DRLGPRESET_GetSizeY(nPresetId) / 8;
    if (nPickedFile == -1)
        nPickedFile = sub_00674320_PickFile(pLevel, nPresetId);
    for (int y = nY; y < nY + nHeight; ++y)
    {
        for (int x = nX; x < nX + nWidth; ++x)
        {
            DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], x, y, 983040, 5);
            DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], x, y, (nPickedFile << 16) | 512, 0);
            if (bFlag && ((nPresetId >= 4 && nPresetId <= 15) || (unsigned int)(nPresetId - 364) <= 11))
                DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], x, y, 1, 0);
            DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[0], x, y, 0, 3);
        }
    }
    DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[0], nX, nY, nPresetId, 3);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x006744F0
int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const int nPosX = pLevel->nPosX;
    const int nPosY = pLevel->nPosY;
    const int nWidth = pOutdoor->nGridWidth - 2;
    const int nHeight = pOutdoor->nGridHeight - 2;
    const int nOffsetX = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nWidth);
    const int nOffsetY = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nHeight);
    int nBestDistance = 0;
    const int nCenterX = pCoords->nWidth / 2 + pCoords->nPosX;
    const int nCenterY = pCoords->nHeight / 2 + pCoords->nPosY;
    int nBestX = -1;
    int nBestY = -1;

    for (int j = 0; j <= nHeight; ++j)
    {
        for (int i = 0; i <= nWidth; ++i)
        {
            const int nY = (j + nOffsetY) % nHeight + 1;
            const int nX = (i + nOffsetX) % nWidth + 1;
            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nLevelPrestId, a5, a6))
            {
                const int nDeltaX = 8 * nX - nCenterX + nPosX + 4;
                const int nDiffX = D2_ABS(nDeltaX);
                const int nDeltaY = 8 * nY - nCenterY + nPosY + 4;
                const int nDiffY = D2_ABS(nDeltaY);
                const int nDistance = (nDiffX > nDiffY ? nDiffY + 2 * nDiffX : nDiffX + 2 * nDiffY) / 2;
                if (nBestDistance < nDistance)
                {
                    nBestDistance = nDistance;
                    nBestX = nX;
                    nBestY = nY;
                }
            }
        }
    }

    if (nBestX != -1 && nBestY != -1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nBestX, nBestY, nLevelPrestId, nPickedFile, 0);
        return 1;
    }

    return 0;
}

int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    return !(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x1B81);
}

static __forceinline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00674E40
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines)
{
    D2CoordStrc pCoord[256];

    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nIndex = SEED_RollRandomNumber(&pLevel->pSeed) & 3;
    const int nWidth = pOutdoors->nGridWidth - 2;
    const int nArea = nWidth * (pOutdoors->nGridHeight - 2);

    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);
            const unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);

            const D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }

        for (int i = 0; i < nArea; ++i)
        {
            if (nShrines <= 0)
            {
                break;
            }

            const int nX = pCoord[i].nX + 1;
            const int nY = pCoord[i].nY + 1;

            if (DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, nX, nY))
            {
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], nX, nY, gdwAct12ShrineFlags_006F061C[nIndex], 0);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x1000, 0);
                nIndex = (nIndex + 1) % 4;
                --nShrines;
            }
        }
    }
}

// 0x00675080
static void sub_00675080_ScaleAndMergeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    D2DrlgVertexStrc* pVertex = *ppVertex;
    do
    {
        pVertex->nPosX /= 8;
        pVertex->nPosY /= 8;
        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);

    do
    {
        D2DrlgVertexStrc* pNextVertex = pVertex->pNext;

        if (pVertex->nPosX == pNextVertex->nPosX && pVertex->nPosY == pNextVertex->nPosY)
        {
            if (pNextVertex == *ppVertex)
            {
                *ppVertex = pVertex;
            }

            pVertex->pNext = pNextVertex->pNext;
            pVertex->dwFlags |= pNextVertex->dwFlags;
            pVertex->nDirection = pNextVertex->nDirection;
            FOG_FreeServerMemory(pMemPool, pNextVertex, ".\\DRLG\\Outdoors.cpp", 715, 0);
        }

        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);
}

void __fastcall sub_M16_EmitScaleAndMergeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    sub_00675080_ScaleAndMergeVertices(pMemPool, ppVertex);
}

// 0x00675290
int __fastcall sub_00675290_GetOutdoorValue(D2DrlgLevelStrc* pLevel, int nIndex)
{
    return (int)pLevel->pOutdoors->pRoads[nIndex];
}

// 0x006757E0
int __fastcall sub_006757E0_GetLevelStyle(D2DrlgLevelStrc* pLevel, bool bFlag)
{
    switch (pLevel->nLevelType)
    {
    case 2:
        return !bFlag;
    case 16:
        return 2;
    case 27:
        return 3;
    case 31:
        return sub_0067DCE0(pLevel);
    }
    return -1;
}

#include "gen/data/Source/D2Common/DRLG/Outdoors.inc"
