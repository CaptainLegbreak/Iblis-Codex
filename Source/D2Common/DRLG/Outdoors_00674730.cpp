#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#define LEVEL_COLDPLAINS 3
#define FLAG_OPERATION_OR 0

struct D2DrlgStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2SeedStrc;
struct D2CoordStrc;

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int field_10;
};

struct D2DrlgOutdoorInfoStrc
{
    int field_00;
    D2DrlgGridStrc pGrid[4];
    char unk0x54[0x08];
    int nGridWidth;
    int nGridHeight;
};


struct D2DrlgLevelStrc
{
    char pad_00[20];
    D2DrlgOutdoorInfoStrc* pOutdoor;
    char unk0x018[0x19C];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc tSeed;
    char unk0x1CC[0x04];
    int nLevelId;
};


int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, char nFlags); // 0x00674230
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int bBorder); // 0x006743C0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570

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

// 0x00674730
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags)
{
    D2CoordStrc pCoord[256];

    const int nWidth = pLevel->pOutdoor->nGridWidth - 2;
    const int nArea = nWidth * (pLevel->pOutdoor->nGridHeight - 2);

    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pLevel->tSeed, nArea);
            const unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pLevel->tSeed, nArea);

            const D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nX = pCoord[i].nX + 1;
            const int nY = pCoord[i].nY + 1;

            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nLevelPrestId, nOffset, nFlags))
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, nRand, 0);
                return 1;
            }
        }
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

// 0x00674B70
void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel)
{
    D2CoordStrc pCoord[256];
    const int nLevelId = pLevel->nLevelId;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoor;
    if (nLevelId == LEVEL_COLDPLAINS)
    {
        int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, nLevelId);
        int k;
        for (k = 0; k < 8; ++k)
        {
            if (pVisArray[k] == LEVEL_BLOODMOOR)
                break;
        }
        int nFlags = 1 << (k + 4);
        int nW = pOutdoors->nGridWidth;
        int nH = pOutdoors->nGridHeight;
        for (int i = 0; i < nH; ++i)
        {
            for (int j = 0; j < nW; ++j)
            {
                int a = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[1], j, i);
                int b = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], j, i);
                if ((a & nFlags) && (b & 0x400))
                {
                    if (!j) j = 1;
                    if (!i) i = 1;
                    if (j == nW - 1) --j;
                    if (i == nH - 1) --i;
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], j, i, 0x20000, FLAG_OPERATION_OR);
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], j, i, 0x800, FLAG_OPERATION_OR);
                    return;
                }
            }
        }
    }
    int nWidth = pOutdoors->nGridWidth - 2;
    int nArea = nWidth * (pOutdoors->nGridHeight - 2);
    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }
        for (int i = 0; i < nArea; ++i)
        {
            int nRand1 = SEED_RollLimitedRandomNumber_Inline(&pLevel->tSeed, nArea);
            int nRand2 = SEED_RollLimitedRandomNumber_Inline(&pLevel->tSeed, nArea);
            D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }
        for (int i = 0; i < nArea; ++i)
        {
            int nX = pCoord[i].nX + 1;
            int nY = pCoord[i].nY + 1;
            if (!(DRLGGRID_GetGridEntry(&pLevel->pOutdoor->pGrid[2], nX, nY) & 0x1B81))
            {
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], nX, nY, 0x10000, FLAG_OPERATION_OR);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x800, FLAG_OPERATION_OR);
                break;
            }
        }
    }
}
