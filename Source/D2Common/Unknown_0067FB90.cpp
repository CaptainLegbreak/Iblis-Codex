#include "D2Common.h"

struct D2DrlgOutdoorInfoStrc;
struct D2PresetPairStrc;
struct D2DrlgOutRectStrc;
struct D2SeedStrc;
struct D2OutdoorColumnFilesStrc;

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgOutdoorInfoStrc
{
    int nFlags;
    union
    {
        struct
        {
            D2DrlgGridStrc pGrid[3];
        };
        struct
        {
            D2DrlgGridStrc tGrid04;
            unsigned char unk_18[0x14];
            D2DrlgGridStrc tGridFlags;
        };
    };
    char unk0x040[0x1C];
    int nGridWidth;
    int nHeight;
};

struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    union
    {
        D2DrlgOutdoorInfoStrc* pOutdoors;
        D2DrlgOutdoorInfoStrc* pOutdoor;
    };
    char pad_after_outdoor[428];
    D2SeedStrc tSeed;
};

int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

struct D2PresetPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2DrlgOutRectStrc
{
    int nX;
    int nY;
    int unk0x08;
    unsigned char nFlags;
    char pad0x0D[3];
    D2DrlgOutRectStrc* pBounds;
};

extern D2PresetPairStrc gaPresetPairs_006F2680[]; // 0x006F2680
void __stdcall sub_M127_EmitSink(int nValue);

struct D2OutdoorColumnFilesStrc
{
    int nLeft;
    int nRight;
};

extern D2OutdoorColumnFilesStrc gColumnFiles_006F2680[]; // 0x006F2680

// build: symbol ?DRLGOUTWILD_FindBridgeInColumn@@YGXPAUD2DrlgLevelStrc@@HPAH1@Z 0x0067FB90
static void __stdcall DRLGOUTWILD_FindBridgeInColumn(D2DrlgLevelStrc* pLevel, int nX, int* pX, int* pY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int nY = 1; nY < pOutdoors->nGridWidth - 1; ++nY)
    {
        const int nEntry = sub_0067C570(&pOutdoors->pGrid[0], nX, nY);
        const unsigned int nPacked = sub_0067C570(&pOutdoors->pGrid[2], nX, nY);
        const int nPickedFile = (nPacked >> 16) & 0xF;
        if (nEntry == 28 && nPickedFile == 1)
        {
            *pX = nX;
            *pY = nY;
            return;
        }
    }

    *pX = -1;
    *pY = -1;
}

// 0x0067FC20
void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    DRLGOUTWILD_FindBridgeInColumn(pLevel, pLevel->pOutdoors->nGridWidth / 2 - 1, pX, pY);
}

// 0x0067FC50
void __fastcall sub_0067FC50(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    DRLGOUTWILD_FindBridgeInColumn(pLevel, pLevel->pOutdoors->nGridWidth - 2, pX, pY);
}

// 0x0067FCD0
static __forceinline int __stdcall sub_0067FCD0_GetPresetPairValue(int bFirst, int nIndex, unsigned int nFlags)
{
    if (nIndex)
    {
        if (nIndex == 7 && (nFlags & 0xF0000) == 0x30000)
        {
            return nIndex - 4;
        }
        if (bFirst)
        {
            return gaPresetPairs_006F2680[nIndex].nFirst;
        }
        return gaPresetPairs_006F2680[nIndex].nSecond;
    }
    return (nFlags & 0x100) ? 0 : 3;
}

// 0x0067FFB0
static __forceinline int sub_0067FFB0_IsRectAdjacent(D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther)
{
    D2DrlgOutRectStrc* pBounds = pRect->pBounds;
    if (pRect->nX < pBounds->nX && pOther->nY > pRect->nY && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    if (pRect->nY > pBounds->nY && pOther->nX > pRect->nX && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    return 0;
}

void __fastcall sub_M127_Emit_0067FCD0(int nValue, D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther, unsigned int nFlags)
{
    sub_M127_EmitSink(sub_0067FCD0_GetPresetPairValue(nValue & 1, nValue, nFlags));
    for (D2DrlgOutRectStrc* p = pOther; p; p = p->pBounds)
    {
        sub_M127_EmitSink(sub_0067FFB0_IsRectAdjacent(pRect, p));
    }
}

#include "gen/data/Source/D2Common/Unknown_0067FB90.inc"

static __forceinline unsigned __int64 RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->dwHigh + 0x6AC690C5i64 * pSeed->dwLow;
    pSeed->dwHigh = (unsigned int)(nSeed >> 32);
    pSeed->dwLow = (unsigned int)nSeed;
    return nSeed;
}

static __forceinline unsigned int RollLimitedInline(D2SeedStrc* pSeed, int nLimit)
{
    if (nLimit <= 0)
        return 0;
    if ((nLimit - 1) & nLimit)
        return (unsigned int)RollSeedInline(pSeed) % nLimit;
    return RollSeedInline(pSeed) & (nLimit - 1);
}

// @ref 0x0067FD20
static __declspec(noinline) void __stdcall sub_0067FD20_PlacePair(int nColumn, D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoor;
    const int nFlag = pOutdoor->nFlags & 4;
    const int nLimit = pOutdoor->nHeight - 2;
    const int nStart = RollLimitedInline(&pLevel->tSeed, nLimit);
    for (int i = 0; i < nLimit; ++i)
    {
        const int nRow = (i + nStart) % nLimit + 1;
        int nCheckColumn = nColumn - 1;
        if (!nFlag)
        {
            if (!sub_00674200_IsValid(pLevel, nCheckColumn, nRow))
                continue;
            nCheckColumn = nColumn + 2;
        }
        if (!sub_00674200_IsValid(pLevel, nCheckColumn, nRow))
            continue;
        if ((sub_0067C570_GetGrid(&pOutdoor->tGridFlags, nColumn, nRow) & 0xF0000) != 0x30000)
            continue;
        if ((sub_0067C570_GetGrid(&pOutdoor->tGridFlags, nColumn + 1, nRow) & 0xF0000) != 0x30000)
            continue;
        sub_006743C0_PlacePreset(pLevel, nColumn, nRow, 28, 1, 0);
        sub_006743C0_PlacePreset(pLevel, nColumn + 1, nRow, 28, 2 + (nFlag != 0), 0);
        return;
    }
}

// 0x0067FE90
void __stdcall sub_0067FE90_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoor;
    for (int nRow = 0; nRow < pOutdoor->nHeight; ++nRow)
    {
        int nFlags = sub_0067C570_GetGrid(&pOutdoor->tGridFlags, nColumn, nRow);
        int nType = sub_0067C570_GetGrid(&pOutdoor->tGrid04, nColumn, nRow);
        int nFile;
        if (nType)
        {
            if (nType == 7 && (nFlags & 0xF0000) == 0x30000)
                nFile = 3;
            else
                nFile = gColumnFiles_006F2680[nType].nLeft;
        }
        else
            nFile = (nFlags & 0x100) ? 0 : 3;
        sub_006743C0_PlacePreset(pLevel, nColumn, nRow, 26, nFile, 0);

        nFlags = sub_0067C570_GetGrid(&pOutdoor->tGridFlags, nColumn + 1, nRow);
        nType = sub_0067C570_GetGrid(&pOutdoor->tGrid04, nColumn + 1, nRow);
        if (nType)
        {
            if (nType == 7 && (nFlags & 0xF0000) == 0x30000)
                nFile = 3;
            else
                nFile = gColumnFiles_006F2680[nType].nRight;
        }
        else
            nFile = (nFlags & 0x100) ? 0 : 3;
        sub_006743C0_PlacePreset(pLevel, nColumn + 1, nRow, 27, nFile, 0);
    }
    if (pOutdoor->nFlags & 0x14)
        sub_0067FD20_PlacePair(nColumn, pLevel);
}
