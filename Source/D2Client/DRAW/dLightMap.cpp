#include "D2Client.h"
#include "D2Structs.h"

#pragma intrinsic(abs)

#define LIGHT_MAX_SIZE 18
#define LIGHT_SIZE_SHIFT 3
#define LIGHT_TYPE_2 2
#define INDICATOR_HOLD_MS 2000
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIGHT_ABS(x) ((x) >= 0 ? (x) : -(x))
#define LIGHT_CELL(v, r, c) { v = gdwLightOverrideRows_007ACA50[r][c]; if (!v) { v = gdwLightMapRows_007A8A50[r][c]; } }

struct D2UnitRefStrc;
struct D2LightCellStrc;
struct D2LightStrc;
struct D2P08LightSourceStrc;
struct D2R01LightStrc;
struct D2GridCellStrc;
struct D2PathPointStrc;
struct D2UnitStrc;
struct D2DrlgCoordsStrc;

struct D2UnitRefStrc
{
    int nType;
    unsigned int nUnitId;
    unsigned char f_8;
};

struct D2LightCellStrc
{
    union
    {
        int nFlags;
        unsigned char f_0;
    };
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};


D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
extern int gbFlag_00712B8C; // 0x00712B8C
extern int gnCellOriginX_007B0A54; // 0x007B0A54
extern int gnCellOriginY_007B0A58; // 0x007B0A58

struct D2LightStrc
{
    char unk0x00[0x0C];
    int nType;
    int nX;
    int nY;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
    D2LightStrc* pNext;
    int nUnk0x2C;
    void* pData;
};

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_004F5210(); // 0x004F5210
int __cdecl sub_004CCF30(); // 0x004CCF30
int __cdecl sub_0044DAE0(); // 0x0044DAE0
void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos); // 0x004F68B0
void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction); // 0x0061AF60
void __fastcall sub_00475930_ActCallback(D2ActiveRoomStrc* pRoom); // 0x00475930
void __fastcall sub_004FB1C0_CopyRowTable(unsigned char (*pRows)[0x100]); // 0x004FB1C0
unsigned char* __stdcall sub_00475B80_BuildLerpTable(unsigned int nCount, int nSteps); // 0x00475B80
unsigned char** __stdcall sub_00475C40_BuildLerpRowTable(unsigned int nCount, int nSteps); // 0x00475C40
unsigned char** __stdcall sub_00475D30_BuildRampTable(unsigned int nSize, int nSteps); // 0x00475D30
extern unsigned int gdwLightMap_007A8A50[]; // 0x007A8A50
extern unsigned int gdwLightGrid_007B0E68[]; // 0x007B0E68
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
extern unsigned char gRowTable_007B5C10[][0x100]; // 0x007B5C10
extern unsigned char** gppLerpRows_007B953C; // 0x007B953C
extern unsigned char* gpLerpTable_007B9540; // 0x007B9540
extern unsigned char* gpLerpTable_007B9544; // 0x007B9544
extern unsigned char** gppRampTable_007B954C; // 0x007B954C
extern unsigned char* gpLerpTable_007B9550; // 0x007B9550
extern int gdwGlobal_007BB384; // 0x007BB384
void __stdcall sub_004F5230(void* pArg); // 0x004F5230
extern int gdwGlobal_00712CCC; // 0x00712CCC
extern int gdwGlobal_007BB38C; // 0x007BB38C
extern int gdwGlobal_007BB3B4; // 0x007BB3B4
extern int gdwGlobal_00712F04; // 0x00712F04
extern int gdwGlobal_007BC9B0; // 0x007BC9B0
extern int gdwGlobal_007BC9B4; // 0x007BC9B4
extern int gdwGlobal_007BC99C; // 0x007BC99C
extern int gdwGlobal_007BC9BC; // 0x007BC9BC
extern int gdwGlobal_007BF024; // 0x007BF024
extern int gdwGlobal_007BF1F6; // 0x007BF1F6

struct D2GridCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2P08LightSourceStrc
{
    unsigned char unk0x00[0x25];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern unsigned int gdwReciprocals_007B0A68[0x100]; // 0x007B0A68
extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

extern D2LightCellStrc gaCells_007B0E68[0x30][0x30]; // 0x007B0E68
extern unsigned int gdwLightOverrideRows_007ACA50[][64]; // 0x007ACA50
extern D2LightStrc* gpLights_007B5668; // 0x007B5668

struct D2PathPointStrc
{
    char unk0x00[0x10];
    int nX;
    int nY;
};

extern "C" int __cdecl abs(int nValue);
extern int gnPathStepSignX_007B0A50; // 0x007B0A50
extern int gnPathStepSignY_007A8A48; // 0x007A8A48
static __forceinline unsigned char sub_00474A30_IsCellBlocked(int nX, int nY);
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit(); // 0x00463DE0
extern int gnGlobal_007B0A5C; // 0x007B0A5C
extern int gnGlobal_007B0A60; // 0x007B0A60
extern int gnPathStepMode_007B0A64; // 0x007B0A64
extern int gnPathStepRatio_007A8A4C; // 0x007A8A4C
static __declspec(noinline) void __stdcall sub_00474B50_SetupStepDirection(int nX, int nY, D2PathPointStrc* pPoint);

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
};

extern D2LightCellStrc gLightGrid_007B0E68[][48]; // 0x007B0E68
D2UnitStrc* __stdcall sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __fastcall sub_00474550_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int a6); // 0x00474550

static __declspec(noinline) void sub_00474C00_BlendLightCell(int nCol, int nRow);

int gnPathStepMode_007B0A64; // 0x007B0A64

int gnPathStepRatio_007A8A4C; // 0x007A8A4C

// 0x004740D0
static __declspec(noinline) unsigned int __stdcall sub_004740D0_ApproxDistance(int nB, int nA)
{
    const int nAbsA = abs(nA);
    const int nAbsB = abs(nB);
    if (nAbsA >= nAbsB)
    {
        return (unsigned int)(nAbsA * 0x3D7 + nAbsB * 0x197) >> 10;
    }

    return (unsigned int)(nAbsB * 0x3D7 + nAbsA * 0x197) >> 10;
}

D2LightCellStrc gaCells_007B0E68[0x30][0x30]; // 0x007B0E68

// 0x00474120
static __forceinline D2UnitStrc* sub_00474120_FindUnitFromRef(D2UnitRefStrc* pRef)
{
    if (pRef->nType == 6)
    {
        return 0;
    }
    if (pRef->f_8)
    {
        return sub_004639B0_FindServerSideUnit(pRef->nUnitId, pRef->nType);
    }
    return sub_00463990(pRef->nUnitId, pRef->nType);
}

// 0x00474140
void __cdecl sub_00474140_ToggleFlag()
{
    gbFlag_00712B8C = !gbFlag_00712B8C;
}

int __fastcall sub_M119_Emit_00474120(D2UnitRefStrc* pRef, int nX, int nY)
{
    int n = (int)sub_00474120_FindUnitFromRef(pRef);
    n += sub_00474A30_IsCellBlocked(nX, nY);
    return n;
}

#include "gen/data/Source/D2Client/DRAW/dLightMap.inc"

D2LightStrc* gpLights_007B5668; // 0x007B5668

int gnLightsReleased_007B5670; // 0x007B5670

int gnIndicatorLevel_007B567C; // 0x007B567C

unsigned long gdwIndicatorTick_007B5678; // 0x007B5678

unsigned int gdwReciprocals_007B0A68[0x100]; // 0x007B0A68

// 0x00474290
void __fastcall sub_00474290_SetLightSize(D2LightStrc* pLight, int nSize)
{
    if (nSize > 0)
    {
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        D2_ASSERT(pLight, 0x131);
        pLight->nUnk0x1C = nSize * 8;
    }
}

// 0x004742D0
void __fastcall sub_004742D0_ResetLightSize(D2LightStrc* pLight, int nSize)
{
    if (nSize > 0)
    {
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        D2_ASSERT(pLight, 0x141);
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        pLight->nUnk0x18 = nSize * 8;
        pLight->nUnk0x1C = nSize * 8;
        if (pLight->nType == LIGHT_TYPE_2)
        {
            pLight->nUnk0x2C = 0;
            if (pLight->pData)
            {
                FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 0x14A, 0);
            }
            pLight->pData = 0;
        }
    }
}

// 0x00474350
int __fastcall sub_00474350_GetLightSize(D2LightStrc* pLight)
{
    D2_ASSERT(pLight, 0x155);
    return pLight->nUnk0x18 >> LIGHT_SIZE_SHIFT;
}

int gdwGlobal_007BB388; // 0x007BB388

int gdwGlobal_007BCC48; // 0x007BCC48

// 0x00474380
int __cdecl sub_00474380()
{
    return 32;
}

// 0x004743D0
void __fastcall sub_004743D0_ReleaseOverlayResource(D2LightStrc* pLight)
{
    if (!pLight)
    {
        return;
    }
    D2LightStrc* pPrev = 0;
    D2LightStrc* pCurrent = gpLights_007B5668;
    while (pCurrent)
    {
        if (pCurrent == pLight)
        {
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    D2_ASSERT(pCurrent, 0x17A);
    if (pPrev)
    {
        pPrev->pNext = pCurrent->pNext;
    }
    else
    {
        gpLights_007B5668 = pCurrent->pNext;
    }
    if (pLight->pData)
    {
        FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 0x181, 0);
    }
    FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 0x183, 0);
    gnLightsReleased_007B5670 += 1;
}

// 0x00474470
void __fastcall sub_00474470_ResetLight(D2LightStrc* pLight)
{
    D2_ASSERT(pLight, 0x18D);
    pLight->nUnk0x20 = 1;
    pLight->nUnk0x1C = 0;
    D2_ASSERT(pLight->nType != LIGHT_TYPE_2, 0x190);
}

void __stdcall sub_R01_Emit_00474C00(int nRow, int nColA, int nColB)
{
    sub_00474C00_BlendLightCell(nColA, nRow);
    sub_00474C00_BlendLightCell(nColB, nRow);
}

// 0x004744B0
static __declspec(noinline) void __stdcall sub_004744B0_FillLightGrid(int nX0, int nY0, int nX1, unsigned int nColor, int nY1)
{
    for (int nY = nY0; nY <= nY1; ++nY)
    {
        D2LightCellStrc* pCell = &gLightGrid_007B0E68[nY][nX0];
        for (int nX = nX0; nX <= nX1; ++nX)
        {
            pCell->nFlags = 0;
            pCell->nIntensity = (unsigned char)nColor;
            pCell->nRed = (unsigned char)(nColor >> 8);
            pCell->nGreen = (unsigned char)(nColor >> 16);
            pCell->nBlue = (unsigned char)(nColor >> 24);
            ++pCell;
        }
    }
}

// 0x00474610
void __stdcall sub_00474610_UpdateLightGrid(int bClear)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom;
    if (!pPlayer || (pRoom = UNITS_GetRoom(pPlayer)) == 0 || bClear)
    {
        sub_004744B0_FillLightGrid(0, 0, 47, 0, 47);
        return;
    }

    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

        unsigned char nRed = 0;
        unsigned char nGreen = 0;
        unsigned char nBlue = 0;
        int nIntensity = 0;
        sub_00474550_GetRoomLight(pRoom, &nIntensity, &nRed, &nGreen, &nBlue, 1);
        sub_004744B0_FillLightGrid(0, 0, 47, nIntensity | (nRed << 8) | (nGreen << 16) | (nBlue << 24), 47);

        for (int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pRoom)
            {
                continue;
            }

            sub_00474550_GetRoomLight(ppRoomList[i], &nIntensity, &nRed, &nGreen, &nBlue, 1);
            const unsigned int nColor = nIntensity | (nRed << 8) | (nGreen << 16) | (nBlue << 24);

            D2DrlgCoordsStrc tCoords;
            DUNGEON_GetRoomCoordinates(ppRoomList[i], &tCoords);

            int nX0 = tCoords.nSubtileX - gnCellOriginX_007B0A54;
            int nX1 = nX0 + tCoords.nSubtileWidth;
            if (nX0 > 48 || nX1 < 0)
            {
                continue;
            }

            int nY0 = tCoords.nSubtileY - gnCellOriginY_007B0A58;
            int nY1 = nY0 + tCoords.nSubtileHeight;
            if (nY0 > 48 || nY1 < 0)
            {
                continue;
            }

            if (nX0 < 0)
            {
                nX0 = 0;
            }
            if (nX1 >= 48)
            {
                nX1 = 47;
            }
            if (nY0 < 0)
            {
                nY0 = 0;
            }
            if (nY1 >= 48)
            {
                nY1 = 47;
            }

            sub_004744B0_FillLightGrid(nX0, nY0, nX1, nColor, nY1);
        }
    }
}

// 0x004747C0
static __declspec(noinline) void __stdcall sub_004747C0_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX)
{
    const int nGridX = (nX >> 3) - gnCellOriginX_007B0A54;
    if ((unsigned int)nGridX > 0x2F)
    {
        return;
    }

    const int nGridY = (nY >> 3) - gnCellOriginY_007B0A58;
    if ((unsigned int)nGridY > 0x2F)
    {
        return;
    }

    D2GridCellStrc* pCell = &gtGridCells_007B0E68[nGridY * 48 + nGridX];
    const int nOld = pCell->nValue0;
    const unsigned int nNew = LIGHT_MIN((unsigned int)(nOld + nIntensity), 0xFFu);

    if (gbFlag_00712B8C)
    {
        const unsigned int nRecip = gdwReciprocals_007B0A68[nNew];
        int nR = (pCell->nValue1 * nOld + nRed * nIntensity) * nRecip >> 0x10;
        if (nR > 0xFF)
        {
            nR = 0xFF;
        }
        int nG = (pCell->f_6 * nOld + nGreen * nIntensity) * nRecip >> 0x10;
        if (nG > 0xFF)
        {
            nG = 0xFF;
        }
        int nB = (pCell->nValue3 * nOld + nBlue * nIntensity) * nRecip >> 0x10;
        if (nB > 0xFF)
        {
            nB = 0xFF;
        }
        pCell->nValue0 = (unsigned char)nNew;
        pCell->nValue1 = (unsigned char)nR;
        pCell->f_6 = (unsigned char)nG;
        pCell->nValue3 = (unsigned char)nB;
    }
    else
    {
        pCell->nValue1 = 0;
        pCell->f_6 = 0;
        pCell->nValue3 = 0;
        pCell->nValue0 = (unsigned char)nNew;
    }
}

int __stdcall sub_W04_Emit_004740D0(int nX, int nY, int nDx, int nDy)
{
    int nA = nX - nDx;
    if (nA < 0) nA = -nA;
    int nB = nY - nDy;
    if (nB < 0) nB = -nB;
    return sub_004740D0_ApproxDistance(nB, nA) + nX;
}

void __stdcall sub_W04_Emit_00474B50(D2PathPointStrc* pPoint, int nX, int nY)
{
    sub_00474B50_SetupStepDirection(nX, nY, pPoint);
    sub_00474B50_SetupStepDirection(nY, nX, pPoint);
}

int gnPathStepSignX_007B0A50; // 0x007B0A50

int gnPathStepSignY_007A8A48; // 0x007A8A48

unsigned int gdwLightMapRows_007A8A50[64][64]; // 0x007A8A50

unsigned int gdwLightOverrideRows_007ACA50[64][64]; // 0x007ACA50

// 0x004748D0
static __declspec(noinline) void __stdcall sub_004748D0_AddAreaLight(D2R01LightStrc* pLight, int bNoClamp)
{
    int nRadius = pLight->nRadius;
    if ((unsigned int)(nRadius - 1) > 0xFE)
    {
        return;
    }

    if (!bNoClamp)
    {
        switch (pLight->nUnitType)
        {
        case 0:
        {
            D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
            if (pLight->nUnitId != (!pPlayer ? -1 : pPlayer->dwUnitId) && nRadius >= 0x10)
            {
                nRadius = 0x10;
            }
            break;
        }
        case 1:
            nRadius = 8;
            break;
        case 3:
            return;
        }
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - nRadius;
    const int nSpan = (nRadius * 2) >> 3;
    if ((nStartX >> 3) > gnGlobal_007B0A5C || (nStartX >> 3) + nSpan + 1 < gnCellOriginX_007B0A54
        || (nStartY >> 3) > gnGlobal_007B0A60 || (nStartY >> 3) + nSpan + 1 < gnCellOriginY_007B0A58)
    {
        return;
    }

    const int nScale = (pLight->nIntensity << 0x10) / nRadius;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        const int nDiffY = pLight->nY - nY;
        const int nDy = LIGHT_ABS(nDiffY);
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            const int nDiffX = pLight->nX - nX;
            const int nDx = LIGHT_ABS(nDiffX);
            const int nValue = (int)(nRadius - sub_004740D0_ApproxDistance(nDy, nDx)) * nScale >> 0x10;
            if (nValue > 0)
            {
                sub_004747C0_AddGridLight(nValue, pLight->nRed, pLight->nGreen, pLight->nBlue, nY, nX);
            }
            nX += 8;
        }
    }
}

// 0x00474A30
static __forceinline unsigned char sub_00474A30_IsCellBlocked(int nX, int nY)
{
    nX = (nX >> 3) - gnCellOriginX_007B0A54;
    if (nX < 0)
    {
        return 1;
    }
    if (nX >= 0x30)
    {
        return 1;
    }
    nY = (nY >> 3) - gnCellOriginY_007B0A58;
    if (nY < 0)
    {
        return 1;
    }
    if (nY >= 0x30)
    {
        return 1;
    }
    return gaCells_007B0E68[nY][nX].f_0;
}

void __stdcall sub_P08_Emit_004747C0(D2P08LightSourceStrc* pSource, int nX, int nY, int nIntensity)
{
    if (nIntensity > 0)
    {
        sub_004747C0_AddGridLight(nIntensity, pSource->nRed, pSource->nGreen, pSource->nBlue, nY, nX);
    }
}

// 0x00474A70
static __declspec(noinline) void sub_00474A70_BuildOverrideWindow(D2R01LightStrc* pLight)
{
    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    const int nSpan = (pLight->nRadius * 2) >> 3;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        unsigned int* pCell = &gdwLightOverrideRows_007ACA50[nOffset + j][nOffset];
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            *pCell++ = sub_00474A30_IsCellBlocked(nX, nY) << 4;
            nX += 8;
        }
    }
}

// 0x00474B50
static __declspec(noinline) void __stdcall sub_00474B50_SetupStepDirection(int nX, int nY, D2PathPointStrc* pPoint)
{
    int nDx = pPoint->nX - nX;
    int nDy = pPoint->nY - nY;
    if (!nDx && !nDy)
    {
        gnPathStepMode_007B0A64 = 0;
        return;
    }

    if (nDx < 0)
    {
        gnPathStepSignX_007B0A50 = -1;
        nDx = -nDx;
    }
    else
    {
        gnPathStepSignX_007B0A50 = 1;
    }

    if (nDy < 0)
    {
        gnPathStepSignY_007A8A48 = -1;
        nDy = -nDy;
    }
    else
    {
        gnPathStepSignY_007A8A48 = 1;
    }

    if (!nDx)
    {
        gnPathStepMode_007B0A64 = 4;
        return;
    }

    if (!nDy)
    {
        gnPathStepMode_007B0A64 = 1;
        return;
    }

    if (nDx >= nDy)
    {
        gnPathStepMode_007B0A64 = 2;
        gnPathStepRatio_007A8A4C = (nDy << 8) / nDx;
    }
    else
    {
        gnPathStepMode_007B0A64 = 3;
        gnPathStepRatio_007A8A4C = (nDx << 8) / nDy;
    }
}

void __stdcall sub_R01_Emit_004748D0(D2R01LightStrc* pLight, int nMode)
{
    if (pLight->nUnitType != 6)
    {
        sub_004748D0_AddAreaLight(pLight, nMode);
    }
    pLight->nRadius = 0;
}

// 0x00474C00
static __declspec(noinline) void sub_00474C00_BlendLightCell(int nCol, int nRow)
{
    int nValue1;
    int nValue2;
    switch (gnPathStepMode_007B0A64)
    {
    case 0:
        return;

    case 2:
        LIGHT_CELL(nValue1, nRow, gnPathStepSignX_007B0A50 + nCol);
        LIGHT_CELL(nValue2, nRow + gnPathStepSignY_007A8A48, gnPathStepSignX_007B0A50 + nCol);
        gdwLightMapRows_007A8A50[nRow][nCol] = ((0x100 - gnPathStepRatio_007A8A4C) * nValue1 + gnPathStepRatio_007A8A4C * nValue2) >> 8;
        break;

    case 3:
        LIGHT_CELL(nValue1, nRow + gnPathStepSignY_007A8A48, nCol);
        LIGHT_CELL(nValue2, nRow + gnPathStepSignY_007A8A48, gnPathStepSignX_007B0A50 + nCol);
        gdwLightMapRows_007A8A50[nRow][nCol] = ((0x100 - gnPathStepRatio_007A8A4C) * nValue1 + gnPathStepRatio_007A8A4C * nValue2) >> 8;
        break;

    case 1:
        LIGHT_CELL(nValue1, nRow, gnPathStepSignX_007B0A50 + nCol);
        gdwLightMapRows_007A8A50[nRow][nCol] = nValue1;
        break;

    case 4:
        LIGHT_CELL(nValue1, nRow + gnPathStepSignY_007A8A48, nCol);
        gdwLightMapRows_007A8A50[nRow][nCol] = nValue1;
        break;
    }
}

// 0x00475780
int __cdecl sub_00475780_GetIndicatorLevel()
{
    int nValue;
    int nLevel = 2;
    if (sub_004F5210())
    {
        if (!sub_004CCF30())
        {
            goto low;
        }
        nLevel = 1;
    }
    nValue = sub_0044DAE0();
    if (nValue <= 9)
    {
low:
        nLevel = 0;
    }
    else if (nValue <= 12)
    {
        nLevel = 1;
    }
    else if (nValue <= 15)
    {
        if (gnIndicatorLevel_007B567C >= 1)
        {
            return gnIndicatorLevel_007B567C;
        }
        nLevel = 1;
    }
    if (nLevel != gnIndicatorLevel_007B567C)
    {
        const unsigned long dwTick = GetTickCount();
        if (dwTick - gdwIndicatorTick_007B5678 > INDICATOR_HOLD_MS)
        {
            gdwIndicatorTick_007B5678 = dwTick;
            gnIndicatorLevel_007B567C = nLevel;
        }
        else
        {
            return gnIndicatorLevel_007B567C;
        }
    }
    return nLevel;
}

void sub_M241_Emit_00474D70(D2R01LightStrc* pLight)
{
    sub_00474A70_BuildOverrideWindow(pLight);
}

// 0x004758D0
void __cdecl sub_004758D0_FreeAllLights()
{
    D2LightStrc* pLight = gpLights_007B5668;
    while (pLight)
    {
        D2LightStrc* pNext = pLight->pNext;
        if (pLight->pData)
        {
            FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 1405, 0);
        }
        FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 1407, 0);
        pLight = pNext;
    }

    gpLights_007B5668 = 0;
}

// 0x00475B20
void __cdecl sub_00475B20_DebugDrawLights()
{
    D2LightStrc* pLight = gpLights_007B5668;
    D2GFX_DebugDraw(gdwLightMap_007A8A50, gdwLightGrid_007B0E68, pLight->nX, pLight->nY);
}

// 0x00475B40
void __cdecl sub_00475B40_InitLightTables()
{
    DUNGEON_SetActCallbackFunc(gpGlobal_007A0634, sub_00475930_ActCallback);
    gdwReciprocals_007B0A68[0] = 0;
    for (int i = 1; i < 0x100; ++i)
    {
        gdwReciprocals_007B0A68[i] = 0x10000u / i;
    }
}

// 0x00475DF0
void __cdecl sub_00475DF0_BuildLerpTables()
{
    D2_ASSERT(!gppLerpRows_007B953C, 0xCA);
    D2_ASSERT(!gpLerpTable_007B9540, 0xCB);
    D2_ASSERT(!gpLerpTable_007B9544, 0xCC);
    D2_ASSERT(!gppRampTable_007B954C, 0xCD);
    D2_ASSERT(!gpLerpTable_007B9550, 0xCE);
    sub_004FB1C0_CopyRowTable(gRowTable_007B5C10);
    gppLerpRows_007B953C = sub_00475C40_BuildLerpRowTable(0x20, 8);
    gpLerpTable_007B9540 = sub_00475B80_BuildLerpTable(0x20, 0x10);
    gpLerpTable_007B9544 = sub_00475B80_BuildLerpTable(0x20, 0x20);
    gppRampTable_007B954C = sub_00475D30_BuildRampTable(0x20, 0x20);
    gpLerpTable_007B9550 = sub_00475B80_BuildLerpTable(0x20, 0x28);
}

// 0x00477680
int __cdecl sub_00477680()
{
    return gdwGlobal_007BB384;
}

// 0x004776C0
void __fastcall sub_004776C0(void* pArg)
{
    sub_004F5230(pArg);
}

// 0x00477730
int __cdecl sub_00477730()
{
    return gdwGlobal_00712CCC;
}

// 0x00477740
int __cdecl sub_00477740()
{
    return gdwGlobal_007BB38C;
}

// 0x00477C90
int __cdecl sub_00477C90()
{
    return gdwGlobal_007BB388;
}

// 0x00478150
int __cdecl sub_00478150()
{
    return gdwGlobal_007BB3B4;
}

// 0x0047A990
int __cdecl sub_0047A990()
{
    return gdwGlobal_00712EFC;
}

// 0x0047A9D0
int __cdecl sub_0047A9D0()
{
    return gdwGlobal_00712F04;
}

// 0x0047AA20
int __cdecl sub_0047AA20()
{
    return gdwGlobal_00712F00;
}

// 0x004817D0
int __cdecl sub_004817D0()
{
    return gdwGlobal_007BC9A4;
}

// 0x004817E0
int __cdecl sub_004817E0()
{
    return gdwGlobal_007BC9AC;
}

// 0x004817F0
int __cdecl sub_004817F0()
{
    return gdwGlobal_007BC9B0;
}

// 0x00481800
int __cdecl sub_00481800()
{
    return gdwGlobal_007BC9B4;
}

// 0x00481810
int __cdecl sub_00481810()
{
    return gdwGlobal_007BC99C;
}

// 0x00481820
int __cdecl sub_00481820()
{
    return gdwGlobal_007BC9BC;
}

// 0x00486E00
int __cdecl sub_00486E00()
{
    return 0;
}

// 0x00489870
int __cdecl sub_00489870()
{
    return gdwGlobal_007BCC48;
}

// 0x00489CD0
void __stdcall sub_00489CD0(int nUnused1)
{
}

// 0x0048BDF0
void __stdcall sub_0048BDF0(int nUnused1)
{
}

// 0x00494FB0
void __stdcall sub_00494FB0(int nUnused1)
{
}

// 0x0049C160
int __cdecl sub_0049C160()
{
    return gdwGlobal_007BF024;
}

// 0x0049E8A0
int __cdecl sub_0049E8A0()
{
    return gdwGlobal_007BF1F6;
}

// 0x0049F900
int __cdecl sub_0049F900()
{
    return gdwGlobal_007BF250;
}

// 0x004A8A20
int __cdecl sub_004A8A20()
{
    return 7;
}
