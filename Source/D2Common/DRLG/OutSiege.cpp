#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"

struct D2CoordStrc;

struct D2DrlgVertexStrc;

struct D2DrlgOutdoorInfoStrc;

struct D2LvlPrestRecordStrc;

struct D2DrlgOutPlaceCtxStrc;

struct D2Act5CornerPresetStrc;

struct D2Act5TypeRangeStrc;

struct D2Act5LevelPresetStrc;

struct D2LvlPrestRecordStrc
{
    char unk0x00[0x28];
    int nSizeX;
    int nSizeY;
};

struct D2DrlgOutPlaceCtxStrc
{
    D2DrlgLevelStrc* pLevel;
    int* pUnk54;
    D2DrlgGridStrc* pGrid04;
    D2DrlgGridStrc* pGrid2C;
    int unk0x10;
    int n14;
    int n18;
    int unk0x1C;
    int unk0x20;
    int (__fastcall* pfnTest)(D2DrlgLevelStrc*, int, int, int, int, unsigned int);
    int (__fastcall* pfnGetPreset)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn2C)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn30)(D2DrlgLevelStrc*, int, int);
    void (__fastcall* pfnPlace)(D2DrlgLevelStrc*, int, int, int, int, int);
};

struct D2Act5CornerPresetStrc
{
    int nLevelId;
    int nArg;
    int f_8;
    int nPresetTall;
    int nPresetWide;
};

struct D2Act5TypeRangeStrc
{
    int nType;
    int nMin;
    int nMax;
    int nPresetA;
    int nPresetB;
};

struct D2Act5LevelPresetStrc
{
    int nLevelId;
    int nPresetTall;
    int nPresetWide;
    int nArg;
    int nUnk10;
    int nCount;
    int bRequired;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0

void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280

D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0

int __fastcall sub_00674730(D2DrlgLevelStrc* pLevel, int nPresetId, int nArg, int a4, int a5);

void __fastcall sub_00675770(D2DrlgLevelStrc* pLevel);

void __fastcall sub_00670750(D2DrlgOutPlaceCtxStrc* pCtx); // 0x00670750

unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741E0

int __fastcall DRLGOUTDOOR_00674120(D2DrlgLevelStrc* pLevel, int nX, int nY);

int __fastcall sub_00674160(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674160

int __fastcall sub_006741A0(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741A0

int __fastcall DRLGOUTDOOR_006755C0(int nDirX, int nDirY, int nSize);

int __fastcall DRLGOUTDOOR_00675600(int nDirX, int nDirY, int nNextDirX, int nNextDirY, int nSize);

void __stdcall sub_0067DCF0(D2DrlgLevelStrc* pLevel); // 0x0067DCF0

void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel); // 0x0067DEF0

int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674120

struct D2LvlPrestTxt;

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nId); // 0x0061F0B0

void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6);

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

int __fastcall sub_006741E0(D2DrlgLevelStrc* pLevel, int nX, int nY);

void DRLGACT5_PlaceCornerPresets(D2DrlgLevelStrc* pLevel);

int __stdcall sub_0067DB00(D2DrlgOutdoorInfoStrc* pInfo, int nX, int nY, D2DrlgLevelStrc* pLevel, int nPresetId);

void __stdcall sub_0067DB50(D2DrlgLevelStrc* pLevel);

void sub_0067DCA0(D2DrlgLevelStrc* pLevel);

int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel);

int __fastcall sub_0067E000(D2DrlgLevelStrc* pLevel, int nType, int nIndex);

int __fastcall sub_0067E080(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nUnused, unsigned int dwCellFlags);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

static int sub_0067E210_PlaceShiftedPreset(D2DrlgLevelStrc* pLevel, int nX, int nY);

struct D2DrlgOutSiegeInitStrc
{
    int nLevelId;
    int field_4;
    int field_8;
    int nLevelPrestId1;
    int nLevelPrestId2;
};

extern const D2DrlgOutSiegeInitStrc gaOutSiegeCaves[3]; // 0x006F1F9C

void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770

void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel); // 0x0067E160

static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel); // 0x0067DA70

int DRLGACT5_ReplaceTransitionPreset(D2DrlgLevelStrc* pLevel, int nX, int nY);

void __stdcall sub_0067E560(D2DrlgLevelStrc* pLevel);

void __fastcall sub_0067E600(D2DrlgLevelStrc* pLevel);

static void sub_0067E0E0(D2DrlgLevelStrc* pLevel);

static void sub_0067E240(D2DrlgLevelStrc* pLevel);

static void sub_0067E4B0(D2DrlgLevelStrc* pLevel);

extern const D2CoordStrc gAct5WallSteps_006F1FD8[12]; // 0x006F1FD8

static const D2Act5CornerPresetStrc gAct5CornerPresets[3] =
{
    { 112, 0, 0, 913, 914 },
    { 117, 0, 1, 983, 984 },
    { 117, 0, 0, 985, 986 },
};

// build: context DRLGACT5_PlaceCornerPresets
static void DRLGACT5_PlaceCornerPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    for (int i = 0; i < 3; ++i)
    {
        const D2Act5CornerPresetStrc* pEntry = &gAct5CornerPresets[i];
        if (pLevel->eLevelId == pEntry->nLevelId)
        {
            int nPresetId;
            int nX;
            int nY;
            if (pLevel->nWidth > pLevel->nHeight)
            {
                nPresetId = pEntry->nPresetWide;
                sub_0061F0B0(nPresetId);
                nX = pEntry->f_8 ? pInfo->nGridWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nPresetId = pEntry->nPresetTall;
                sub_0061F0B0(nPresetId);
                nX = 2;
                nY = pEntry->f_8 ? pInfo->nGridHeight - 2 : 0;
            }
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId, pEntry->nArg, 0);
        }
    }
}

// build: symbol ?sub_0067E600@@YIXPAUD2DrlgLevelStrc@@@Z 0x0067E600
// build: symbol ?sub_0067E160@@YGXPAUD2DrlgLevelStrc@@@Z 0x0067E160
// 0x0067DB00
static int __stdcall sub_0067DB00(D2DrlgOutdoorInfoStrc* pInfo, int nX, int nY, D2DrlgLevelStrc* pLevel, int nPresetId)
{
    if (DRLGGRID_GetGridEntry(&pInfo->pGrid[2], nX, nY) & 0x400)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId, (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS) ? 1 : -1, 0);
        return 1;
    }
    return 0;
}

// 0x0067DB50
void __stdcall sub_0067DB50(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;

    for (int nX = 0; nX < pInfo->nGridWidth; ++nX)
    {
        if (sub_0067DB00(pInfo, nX, 0, pLevel, 0x38D))
        {
            break;
        }
    }

    int nBottom = pInfo->nGridHeight - 2;
    for (int nX = 0; nX < pInfo->nGridWidth; ++nX)
    {
        if (sub_0067DB00(pInfo, nX, nBottom, pLevel, 0x38C))
        {
            break;
        }
    }

    for (int nY = 0; nY < pInfo->nGridHeight; ++nY)
    {
        if (sub_0067DB00(pInfo, 0, nY, pLevel, 0x38E))
        {
            break;
        }
    }

    int nRight = pInfo->nGridWidth - 2;
    for (int nY = 0; nY < pInfo->nGridHeight; ++nY)
    {
        if (sub_0067DB00(pInfo, nRight, nY, pLevel, 0x38B))
        {
            break;
        }
    }
}

// 0x0067DCA0
static void sub_0067DCA0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;

    const int nX = pInfo->nGridWidth - 2;
    const int nY = pInfo->nGridHeight - 3;
    D2DrlgGridStrc* const pGrid = &pInfo->pGrid[2];
    DRLGGRID_AlterGridFlag(pGrid, pInfo->nGridWidth - 2, pInfo->nGridHeight - 4, 0x400, 0);
    DRLGGRID_AlterGridFlag(pGrid, nX, nY, 0x400, 0);
}

// 0x0067DCE0
int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS) + 4;
}

// build: context EmitMarkLevel111Exit
// calling-convention shim (not game code)
void __stdcall EmitMarkLevel111Exit(D2DrlgLevelStrc* pLevel)
{
    sub_0067DCA0(pLevel);
}

// 0x0067DEF0
void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    int nRight = pInfo->nGridWidth - 2;
    int nX = nRight;
    int nY = 0;
    int nBottom = pInfo->nGridHeight - 2;
    int bTundra = pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS;
    int nKindBase = bTundra ? 0x3BD : 0x371;
    int nPresetBase = bTundra ? 0x3C9 : 0x37D;

    while (nX != 0 || nY != nBottom)
    {
        const int nEntry = DRLGGRID_GetGridEntry(&pInfo->pGrid[0], nX, nY);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nEntry - nKindBase + nPresetBase, -1, 0);
        nX += 2 * gAct5WallSteps_006F1FD8[nEntry - nKindBase].nX;
        nY += 2 * gAct5WallSteps_006F1FD8[nEntry - nKindBase].nY;
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, 0, bTundra ? 0x3D6 : 0x38A, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nBottom, bTundra ? 0x3D5 : 0x389, -1, 0);
}

static const D2CoordStrc gAct5WallSteps[12] =
{
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
    { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 },
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
};

static const D2Act5TypeRangeStrc gAct5TypeRanges[10] = // 0x006F2038
{
    { 49, 1, 16, 915, 987 },
    { 49, 31, 46, 915, 987 },
    { 48, 1, 1, 883, 959 },
    { 48, 2, 3, 881, 957 },
    { 48, 4, 4, 884, 960 },
    { 48, 5, 5, 895, 971 },
    { 48, 6, 7, 893, 969 },
    { 48, 8, 8, 896, 972 },
    { 48, 30, 30, 0, 0 },
    { 48, 31, 31, -5, -5 },
};

// 0x0067E000
int __fastcall sub_0067E000(D2DrlgLevelStrc* pLevel, int nType, int nIndex)
{
    if (nType != 48 && nType != 49)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 388);
        exit(-1);
    }

    int bTundra = pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS;
    for (int i = 0; i < 10; ++i)
    {
        const D2Act5TypeRangeStrc* pEntry = &gAct5TypeRanges[i];
        if (nType == pEntry->nType && nIndex >= pEntry->nMin && nIndex <= pEntry->nMax)
        {
            if (bTundra)
            {
                return pEntry->nPresetB - pEntry->nMin + nIndex;
            }
            return pEntry->nPresetA - pEntry->nMin + nIndex;
        }
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 421);
    exit(-1);
}

// 0x0067E080
int __fastcall sub_0067E080(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nUnused, unsigned int dwCellFlags)
{
    int nResult = sub_0067E000(pLevel, (dwCellFlags >> 20) & 0x3F, (dwCellFlags >> 8) & 0xFF);
    if (nResult == -5)
    {
        return 1;
    }

    if (nResult != nPresetId)
    {
        return 0;
    }

    return DRLGOUTDOORS_TestGridCellNonLvlLink(pLevel, nX, nY) != 0;
}

// 0x0067E0E0
static void sub_0067E0E0(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    D2DrlgOutPlaceCtxStrc tCtx;
    memset(&tCtx, 0, sizeof(tCtx));
    tCtx.pLevel = pLevel;
    tCtx.pUnk54 = &pInfo->unk0x54;
    tCtx.pGrid04 = &pInfo->pGrid[0];
    tCtx.pGrid2C = &pInfo->pGrid[2];
    tCtx.pfnTest = sub_0067E080;
    tCtx.pfn2C = sub_00674160;
    tCtx.pfn30 = sub_006741A0;
    tCtx.pfnPlace = DRLGOUTDOORS_SpawnOutdoorLevelPresetEx;
    tCtx.pfnGetPreset = sub_0067E000;
    tCtx.n14 = -1;
    tCtx.n18 = 12;
    sub_00670750(&tCtx);
}

static const D2Act5LevelPresetStrc gAct5LevelPresets[15] = // 0x006F2100
{
    { 111, 955, 956, 0, 25, 1, 1 },
    { 112, 955, 956, 0, 25, 1, 1 },
    { 117, 955, 956, 1, 25, 1, 1 },
    { 112, 953, 953, -1, 25, 1, 1 },
    { 117, 954, 954, -1, 25, 1, 1 },
    { 111, 944, 947, -1, 10, 1, 0 },
    { 111, 942, 945, -1, 20, 4, 0 },
    { 111, 943, 946, -1, 20, 4, 0 },
    { 112, 941, 941, -1, 10, 1, 0 },
    { 112, 939, 939, -1, 8, 1, 0 },
    { 112, 940, 940, -1, 15, 5, 0 },
    { 117, 948, 948, -1, 9, 4, 0 },
    { 117, 949, 949, -1, 9, 4, 0 },
    { 117, 950, 950, -1, 9, 4, 0 },
    { 117, 951, 951, -1, 5, 3, 0 },
};

// 0x0067E160
void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel)
{
    int bTall = pLevel->nWidth < pLevel->nHeight;
    for (int i = 0; i < 15; ++i)
    {
        if (pLevel->eLevelId == gAct5LevelPresets[i].nLevelId)
        {
            int nPresetId;
            if (bTall)
            {
                nPresetId = gAct5LevelPresets[i].nPresetTall;
            }
            else
            {
                nPresetId = gAct5LevelPresets[i].nPresetWide;
            }

            int nArg = gAct5LevelPresets[i].nArg;
            int bPlaced = 0;
            for (int j = 0; j < gAct5LevelPresets[i].nCount; ++j)
            {
                bPlaced = DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nPresetId, nArg, 0, 15);
            }

            if (!(bPlaced || !gAct5LevelPresets[i].bRequired))
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 537);
                exit(-1);
            }
        }
    }
}

// 0x0067E210
static inline int sub_0067E210_PlaceShiftedPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    const int nPreset = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPreset >= 0x393 && nPreset <= 0x39A)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPreset + 0x10, -1, 0);
        return 1;
    }
    return 0;
}

int __fastcall sub_M119_Emit_0067E210(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    return sub_0067E210_PlaceShiftedPreset(pLevel, nY, nX);
}

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

// 0x0067E240
static void sub_0067E240(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId != LEVEL_ID_ACT5_BARRICADE_1)
        return;

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!pInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 564);
        exit(-1);
    }

    int nPlaced;
    int i;
    for (i = 0, nPlaced = 0; i < 90 && nPlaced < 3; ++i)
    {
        const int nX = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nGridWidth / 2);
        const int nY = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nGridHeight / 2);
        if (sub_0067E210_PlaceShiftedPreset(pLevel, nX, nY))
            ++nPlaced;
    }

    const int nOffsetX = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nGridWidth / 2);
    const int nOffsetY = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nGridHeight / 2);
    for (int y = 0; y < pInfo->nGridHeight && nPlaced < 3; ++y)
    {
        for (int x = 0; x < pInfo->nGridWidth && nPlaced < 3; ++x)
        {
            const int nX = (x + 2 * nOffsetX) % pInfo->nGridWidth;
            const int nY = (y + 2 * nOffsetY) % pInfo->nGridHeight;
            if (sub_0067E210_PlaceShiftedPreset(pLevel, nX, nY))
                ++nPlaced;
        }
    }

    if (nPlaced < 3)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 601);
        exit(-1);
    }
}

void __fastcall sub_Emit_0067E240(D2DrlgLevelStrc* pLevel)
{
    sub_0067E240(pLevel);
    sub_0067E240(pLevel);
}

static int DRLGACT5_ReplaceTransitionPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    int nPresetId = DRLGOUTDOOR_00674120(pLevel, nX, nY);
    if (nPresetId < 0x393 || nPresetId > 0x39A)
    {
        return 0;
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId + 0x10, -1, 0);
    return 1;
}

// 0x0067E4B0
static void sub_0067E4B0(D2DrlgLevelStrc* ptLevelData)
{
    if (!ptLevelData)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 623);
        exit(-1);
    }

    if (ptLevelData->eLevelId != LEVEL_ID_ACT5_BARRICADE_1)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 624);
        exit(-1);
    }

    D2DrlgOutdoorInfoStrc* pInfo = ptLevelData->pOutdoors;
    if (!pInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 627);
        exit(-1);
    }

    D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(0x370);
    if (!pRecord)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 631);
        exit(-1);
    }

    int nX = pInfo->nGridWidth - pRecord->nSizeX / 8;
    int nY = pInfo->nGridHeight - pRecord->nSizeY / 8;
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptLevelData, nX, nY, 0x370, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptLevelData, nX, nY - 2, 0x380, -1, 0);
}

// 0x0067E560
void __stdcall sub_0067E560(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!pInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 650);
        exit(-1);
    }

    D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(0x361);
    if (!pRecord)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 653);
        exit(-1);
    }

    int nStep = pRecord->nSizeX / 8;
    int nX = pInfo->nGridWidth - nStep;
    for (int i = 0; i < 15; ++i)
    {
        if (nX < 0)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 660);
            exit(-1);
        }

        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, 0, 0x361 + i, 0, 0);
        nX -= nStep;
    }
}

static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int i = 0; i < 3; ++i)
    {
        if (pLevel->eLevelId == gaOutSiegeCaves[i].nLevelId)
        {
            int nLevelPrestId;
            int nX;
            int nY;
            if (pLevel->nWidth > pLevel->nHeight)
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId2;
                sub_0061F0B0(nLevelPrestId);
                nX = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId1;
                sub_0061F0B0(nLevelPrestId);
                nX = 2;
                nY = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridHeight - 2 : 0;
            }
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, gaOutSiegeCaves[i].field_4, 0);
        }
    }
}

// 0x0067E600
void __fastcall sub_0067E600(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS)
    {
        sub_0067E560(pLevel);
        return;
    }

    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    sub_0067DCF0(pLevel);
    sub_0067DEF0(pLevel);
    sub_0067DB50(pLevel);
    DRLGOUTSIEGE_PlaceCaves(pLevel);

    if (pLevel->eLevelId == LEVEL_ID_ACT5_BARRICADE_1)
    {
        sub_0067E4B0(pLevel);
    }

    sub_0067E0E0(pLevel);
    sub_0067E240(pLevel);
    sub_0067E160(pLevel);
}
