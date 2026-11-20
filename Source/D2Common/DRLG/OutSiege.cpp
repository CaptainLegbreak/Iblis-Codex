#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"

struct D2CoordStrc;
struct D2DrlgVertexStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2LvlPrestRecordStrc;
struct D2DrlgOutPlaceCtxStrc;
struct D2Act5CornerPresetStrc;
struct D2Act5TypeRangeStrc;
struct D2Act5LevelPresetStrc;

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};


struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgOutdoorInfoStrc
{
    int unk0x00;
    D2DrlgGridStrc tGrid04;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    D2DrlgGridStrc tGrid2C;
    int unk0x40;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    int unk0x54;
    int unk0x58;
    int nWidth;
    int nHeight;
    D2DrlgVertexStrc* pVertex;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int nSizeX;
    int nSizeY;
    char unk0x2C[0x1A4];
    int nLevelId;
};

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
int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280
D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0
void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0
int __fastcall sub_00674730(D2DrlgLevelStrc* pLevel, int nPresetId, int nArg, int a4, int a5);
void __fastcall sub_00675770(D2DrlgLevelStrc* pLevel);
void __fastcall sub_00670750(D2DrlgOutPlaceCtxStrc* pCtx); // 0x00670750
int __fastcall sub_006741E0(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741E0
int __fastcall DRLGOUTDOOR_00674120(D2DrlgLevelStrc* pLevel, int nX, int nY);
int __fastcall sub_00674160(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674160
int __fastcall sub_006741A0(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741A0
int __fastcall DRLGOUTDOOR_006755C0(int nDirX, int nDirY, int nSize);
int __fastcall DRLGOUTDOOR_00675600(int nDirX, int nDirY, int nNextDirX, int nNextDirY, int nSize);
void sub_0067E240(D2DrlgLevelStrc* pLevel);
void __stdcall sub_0067DCF0(D2DrlgLevelStrc* pLevel); // 0x0067DCF0
void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel); // 0x0067DEF0
int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674120

static const D2Act5CornerPresetStrc gAct5CornerPresets[3] =
{
    { 112, 0, 0, 913, 914 },
    { 117, 0, 1, 983, 984 },
    { 117, 0, 0, 985, 986 },
};

// build: context DRLGACT5_PlaceCornerPresets
static void DRLGACT5_PlaceCornerPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    for (int i = 0; i < 3; ++i)
    {
        const D2Act5CornerPresetStrc* pEntry = &gAct5CornerPresets[i];
        if (pLevel->nLevelId == pEntry->nLevelId)
        {
            int nPresetId;
            int nX;
            int nY;
            if (pLevel->nSizeX > pLevel->nSizeY)
            {
                nPresetId = pEntry->nPresetWide;
                sub_0061F0B0(nPresetId);
                nX = pEntry->f_8 ? pInfo->nWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nPresetId = pEntry->nPresetTall;
                sub_0061F0B0(nPresetId);
                nX = 2;
                nY = pEntry->f_8 ? pInfo->nHeight - 2 : 0;
            }
            sub_006743C0(pLevel, nX, nY, nPresetId, pEntry->nArg, 0);
        }
    }
}

// build: symbol ?sub_0067E600@@YIXPAUD2DrlgLevelStrc@@@Z 0x0067E600
// build: symbol ?sub_0067E160@@YGXPAUD2DrlgLevelStrc@@@Z 0x0067E160
// 0x0067DB00
static int __stdcall sub_0067DB00(D2DrlgOutdoorInfoStrc* pInfo, int nX, int nY, D2DrlgLevelStrc* pLevel, int nPresetId)
{
    if (sub_0067C570(&pInfo->tGrid2C, nX, nY) & 0x400)
    {
        sub_006743C0(pLevel, nX, nY, nPresetId, (pLevel->nLevelId == 110) ? 1 : -1, 0);
        return 1;
    }
    return 0;
}

// 0x0067DB50
void __stdcall sub_0067DB50(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;

    for (int nX = 0; nX < pInfo->nWidth; ++nX)
    {
        if (sub_0067DB00(pInfo, nX, 0, pLevel, 0x38D))
        {
            break;
        }
    }

    int nBottom = pInfo->nHeight - 2;
    for (int nX = 0; nX < pInfo->nWidth; ++nX)
    {
        if (sub_0067DB00(pInfo, nX, nBottom, pLevel, 0x38C))
        {
            break;
        }
    }

    for (int nY = 0; nY < pInfo->nHeight; ++nY)
    {
        if (sub_0067DB00(pInfo, 0, nY, pLevel, 0x38E))
        {
            break;
        }
    }

    int nRight = pInfo->nWidth - 2;
    for (int nY = 0; nY < pInfo->nHeight; ++nY)
    {
        if (sub_0067DB00(pInfo, nRight, nY, pLevel, 0x38B))
        {
            break;
        }
    }
}

// build: context sub_0067DCA0
static void sub_0067DCA0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, pInfo->nWidth - 2, pInfo->nHeight - 4, 0x400, 0);
    DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, pInfo->nWidth - 2, pInfo->nHeight - 3, 0x400, 0);
}

// 0x0067DCE0
int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->nLevelId == 117) + 4;
}

// build: context sub_0067DCF0
void __stdcall sub_0067DCF0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    D2DrlgVertexStrc* pVertex = pInfo->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;
    int nSize = sub_0067DCE0(pLevel);

    do
    {
        int nDirX;
        int nDirY;
        int nNextDirX;
        int nNextDirY;
        sub_0067D280(pVertex, &nDirX, &nDirY);
        sub_0067D280(pNext, &nNextDirX, &nNextDirY);

        int nAbsDirX = nDirX < 0 ? -nDirX : nDirX;
        int nAbsDirY = nDirY < 0 ? -nDirY : nDirY;

        int nX = pVertex->nPosX & ~1;
        int nY = pVertex->nPosY & ~1;
        int nNextX = pNext->nPosX & ~1;
        int nNextY = pNext->nPosY & ~1;
        int nPresetId = DRLGOUTDOOR_006755C0(nDirX, nDirY, nSize);

        if (!(pVertex->dwFlags & 2))
        {
            while (nX != nNextX || nY != nNextY)
            {
                nX += 2 * nDirX;
                nY += 2 * nDirY;
                sub_006743C0(pLevel, nX, nY, nPresetId, -1, 0);
                DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nX, nY, 1, 0);
            }
        }

        if (pVertex->dwFlags & 1)
        {
            int nMaxX = pVertex->nPosX > pNext->nPosX ? pVertex->nPosX : pNext->nPosX;
            int nMaxY = pVertex->nPosY > pNext->nPosY ? pVertex->nPosY : pNext->nPosY;
            int nMarkX = (nMaxX - 4 * nAbsDirX) & ~1;
            int nMarkY = (nMaxY - 4 * nAbsDirY) & ~1;
            DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nMarkX, nMarkY, 0x400, 0);
            DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nMarkX + 2 * nAbsDirX, nMarkY + 2 * nAbsDirY, 0x400, 0);
        }

        int nCornerPresetId = DRLGOUTDOOR_00675600(2 * nDirX, 2 * nDirY, 2 * nNextDirX, 2 * nNextDirY, nSize);
        if (nCornerPresetId)
        {
            sub_006743C0(pLevel, nNextX, nNextY, nCornerPresetId, -1, 0);
            DRLGGRID_AlterGridFlag(&pInfo->tGrid2C, nNextX, nNextY, 1, 0);
        }

        pVertex = pNext;
        pNext = pNext->pNext;
    }
    while (pVertex != pInfo->pVertex);

    if (pLevel->nLevelId == 111)
    {
        sub_0067DCA0(pLevel);
    }
}

static const D2CoordStrc gAct5WallSteps[12] =
{
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
    { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 },
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
};

// build: context sub_0067DEF0
void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    int nRight = pInfo->nWidth - 2;
    int nBottom = pInfo->nHeight - 2;
    int bTundra = pLevel->nLevelId == 117;
    int nKindBase = bTundra ? 0x3BD : 0x371;
    int nPresetBase = bTundra ? 0x3C9 : 0x37D;
    int nX = nRight;
    int nY = 0;

    while (nX != 0 || nY != nBottom)
    {
        int nKind = sub_0067C570(&pInfo->tGrid04, nX, nY) - nKindBase;
        sub_006743C0(pLevel, nX, nY, nKind + nPresetBase, -1, 0);
        nX += 2 * gAct5WallSteps[nKind].nX;
        nY += 2 * gAct5WallSteps[nKind].nY;
    }

    sub_006743C0(pLevel, nRight, 0, bTundra ? 0x3D6 : 0x38A, -1, 0);
    sub_006743C0(pLevel, 0, nBottom, bTundra ? 0x3D5 : 0x389, -1, 0);
}

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
int __fastcall sub_0067E000(D2DrlgLevelStrc* pLevel, int nStyle, int nIndex)
{
    if (nStyle != 48 && nStyle != 49)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 388);
        exit(-1);
    }

    int bTundra = pLevel->nLevelId == 117;
    for (int i = 0; i < 10; ++i)
    {
        const D2Act5TypeRangeStrc* pEntry = &gAct5TypeRanges[i];
        if (nStyle == pEntry->nType && nIndex >= pEntry->nMin && nIndex <= pEntry->nMax)
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

    return sub_006741E0(pLevel, nX, nY) != 0;
}

// 0x0067E0E0
static void sub_0067E0E0(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == 110)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    D2DrlgOutPlaceCtxStrc tCtx;
    memset(&tCtx, 0, sizeof(tCtx));
    tCtx.pLevel = pLevel;
    tCtx.pUnk54 = &pInfo->unk0x54;
    tCtx.pGrid04 = &pInfo->tGrid04;
    tCtx.pGrid2C = &pInfo->tGrid2C;
    tCtx.pfnTest = sub_0067E080;
    tCtx.pfn2C = sub_00674160;
    tCtx.pfn30 = sub_006741A0;
    tCtx.pfnPlace = sub_006743C0;
    tCtx.pfnGetPreset = sub_0067E000;
    tCtx.n14 = -1;
    tCtx.n18 = 12;
    sub_00670750(&tCtx);
}

static const D2Act5LevelPresetStrc gAct5LevelPresets[15] =
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

void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel)
{
    int bTall = pLevel->nSizeX < pLevel->nSizeY;
    for (int i = 0; i < 15; ++i)
    {
        const D2Act5LevelPresetStrc* pEntry = &gAct5LevelPresets[i];
        if (pLevel->nLevelId != pEntry->nLevelId)
        {
            continue;
        }

        int nPresetId = bTall ? pEntry->nPresetTall : pEntry->nPresetWide;
        int bPlaced = 0;
        for (int j = 0; j < pEntry->nCount; ++j)
        {
            bPlaced = sub_00674730(pLevel, nPresetId, pEntry->nArg, 0, 15);
        }

        if (!bPlaced && pEntry->bRequired)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 537);
            exit(-1);
        }
    }
}

static int DRLGACT5_ReplaceTransitionPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    int nPresetId = DRLGOUTDOOR_00674120(pLevel, nX, nY);
    if (nPresetId < 0x393 || nPresetId > 0x39A)
    {
        return 0;
    }

    sub_006743C0(pLevel, nX, nY, nPresetId + 0x10, -1, 0);
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

    if (ptLevelData->nLevelId != 111)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 624);
        exit(-1);
    }

    D2DrlgOutdoorInfoStrc* pInfo = ptLevelData->pOutdoorInfo;
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

    int nX = pInfo->nWidth - pRecord->nSizeX / 8;
    int nY = pInfo->nHeight - pRecord->nSizeY / 8;
    sub_006743C0(ptLevelData, nX, nY, 0x370, -1, 0);
    sub_006743C0(ptLevelData, nX, nY - 2, 0x380, -1, 0);
}

// 0x0067E560
void __stdcall sub_0067E560(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
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
    int nX = pInfo->nWidth - nStep;
    for (int i = 0; i < 15; ++i)
    {
        if (nX < 0)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 660);
            exit(-1);
        }

        sub_006743C0(pLevel, nX, 0, 0x361 + i, 0, 0);
        nX -= nStep;
    }
}

void __fastcall sub_0067E600(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == 110)
    {
        sub_0067E560(pLevel);
        return;
    }

    sub_00675770(pLevel);
    sub_0067DCF0(pLevel);
    sub_0067DEF0(pLevel);
    sub_0067DB50(pLevel);
    DRLGACT5_PlaceCornerPresets(pLevel);

    if (pLevel->nLevelId == 111)
    {
        sub_0067E4B0(pLevel);
    }

    sub_0067E0E0(pLevel);
    sub_0067E240(pLevel);
    sub_0067E160(pLevel);
}

// 0x0067E210
static __forceinline int sub_0067E210_PlaceShiftedPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    const int nPreset = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPreset >= 0x393 && nPreset <= 0x39A)
    {
        sub_006743C0(pLevel, nX, nY, nPreset + 0x10, -1, 0);
        return 1;
    }
    return 0;
}

int __fastcall sub_M119_Emit_0067E210(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    return sub_0067E210_PlaceShiftedPreset(pLevel, nY, nX);
}
