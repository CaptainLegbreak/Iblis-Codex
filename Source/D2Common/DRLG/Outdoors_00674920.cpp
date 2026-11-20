#include "D2Structs.h"
#ifdef MOVED_TEST
#define PREFIX char movedPrefix[4];
#define BORDER 4
#define CELL_OFFSET 3
#define TEST_FLAGS 13
#else
#define PREFIX
#define BORDER 2
#define CELL_OFFSET 1
#define TEST_FLAGS 15
#endif
struct D2DrlgStrc;
struct D2DrlgGridStrc
{
    char unk0x00[0x14];
};
struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    char pad0x09[3];
    unsigned char nFlags;
    char pad0x0D[3];
    D2DrlgVertexStrc* pNext;
};
struct D2DrlgOutdoorInfoStrc
{
    PREFIX
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    char unk0x54[0x08];
    int nGridWidth;
    int nGridHeight;
    D2DrlgVertexStrc* pVertex;
};
struct D2DrlgCoordsStrc
{
    int nSubtileX;
};
struct D2DrlgLevelStrc
{
    PREFIX
    char unk0x000[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x04];
    D2DrlgCoordsStrc pLevelCoords;
    char unk0x020[0x194];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int eLevelId;
};
struct D2LvlPrestRecordStrc;
extern D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570
int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, int nFlags); // 0x00674230
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
static __forceinline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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
extern const signed char gOffsetX_006F0614[8];  // 0x006F0614
extern const signed char gOffsetY_006F060C[8];  // 0x006F060C
struct Point { int x, y; };
// 0x00674920
int __fastcall sub_00674920_PlaceRandomPreset(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand)
{
    sub_0061F0B0(nLvlPrestId);
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    const int width = pOutdoors->nGridWidth - BORDER;
    const int count = width * (pOutdoors->nGridHeight - BORDER);
    if (!count) return 0;
    Point cells[256];
    for (int i = 0; i < count; ++i)
    {
        cells[i].x = i % width;
        cells[i].y = i / width;
    }
    for (int i = 0; i < count; ++i)
    {
        const int first = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, count);
        const int second = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, count);
        Point temp = cells[first];
        cells[first] = cells[second];
        cells[second] = temp;
    }
    for (int i = 0; i < count; ++i)
    {
        const int x = cells[i].x + CELL_OFFSET;
        const int y = cells[i].y + CELL_OFFSET;
        if (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], x, y) & 0x80)
        {
            for (int j = 0; j < 8; ++j)
            {
                const int tx = x + gOffsetX_006F0614[j];
                const int ty = y + gOffsetY_006F060C[j];
                if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, tx, ty, nLvlPrestId, 0, TEST_FLAGS))
                {
                    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, tx, ty, nLvlPrestId, nRand, 0);
                    return 1;
                }
            }
        }
    }
    return DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nLvlPrestId, nRand, 0, TEST_FLAGS);
}

#include "gen/data/Source/D2Common/DRLG/Outdoors_00674920.inc"
