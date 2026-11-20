#include "D2Structs.h"
#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIGHT_ABS(x) ((x) >= 0 ? (x) : -(x))

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};


struct D2GridCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2PathPointStrc
{
    char unk0x00[0x10];
    int nX;
    int nY;
};

struct D2R01LightStrc
{
    int nUnitType;
    unsigned int nUnitId;
    unsigned char f_8;
    char unk0x09[3];
    int nMode;
    int nX;
    int nY;
    int nRadius;
    int nTargetRadius;
    int bFixed;
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    D2R01LightStrc* pNext;
    int bMaskReady;
    unsigned int* pMask;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl abs(int nValue);
#pragma intrinsic(abs)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);                 // 0x004639B0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                              // 0x00463990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
int __fastcall sub_00474080_GetDistance(int nDX, int nDY);                                                  // 0x00474080
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
void __stdcall sub_00474610_UpdateLightGrid(int nArg);                                                                      // 0x00474610
void __cdecl sub_004756D0_ScanGridCollision();                                                              // 0x004756D0
int __cdecl sub_00475780_GetIndicatorLevel();                                                               // 0x00475780
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern int gnGlobal_007B0A54;                                                                               // 0x007B0A54
extern int gnGlobal_007B0A58;                                                                               // 0x007B0A58
extern int gnGlobal_007B0A5C;                                                                               // 0x007B0A5C
extern int gnGlobal_007B0A60;                                                                               // 0x007B0A60
extern unsigned int gdwReciprocals_007B0A68[0x100];                                                         // 0x007B0A68
extern D2GridCellStrc gtGridCells_007B0E68[];                                                               // 0x007B0E68
extern int gnGlobal_00712B8C;                                                                               // 0x00712B8C
extern int gnPathStepMode_007B0A64;                                                                         // 0x007B0A64
extern int gnPathStepSignX_007B0A50;                                                                        // 0x007B0A50
extern int gnPathStepSignY_007A8A48;                                                                        // 0x007A8A48
extern int gnPathStepRatio_007A8A4C;                                                                        // 0x007A8A4C
extern unsigned int gdwLightMapRows_007A8A50[][64];                                                         // 0x007A8A50
extern unsigned int gdwLightOverrideRows_007ACA50[][64];                                                    // 0x007ACA50
extern D2R01LightStrc* gpLights_007B5668;                                                                   // 0x007B5668
extern int gnLightCount_007B5674;                                                                           // 0x007B5674

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

static __declspec(noinline) void __stdcall sub_004747C0_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX)
{
    const int nGridX = (nX >> 3) - gnGlobal_007B0A54;
    if ((unsigned int)nGridX > 0x2F)
    {
        return;
    }

    const int nGridY = (nY >> 3) - gnGlobal_007B0A58;
    if ((unsigned int)nGridY > 0x2F)
    {
        return;
    }

    D2GridCellStrc* pCell = &gtGridCells_007B0E68[nGridY * 48 + nGridX];
    const int nOld = pCell->nValue0;
    const unsigned int nNew = LIGHT_MIN((unsigned int)(nOld + nIntensity), 0xFFu);

    if (gnGlobal_00712B8C)
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

static __declspec(noinline) void __stdcall sub_004748D0_AddAreaLight(D2R01LightStrc* pLight, int bNoClamp);

// 0x004748D0
static void __stdcall sub_004748D0_AddAreaLight(D2R01LightStrc* pLight, int bNoClamp)
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
            D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
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
    if ((nStartX >> 3) > gnGlobal_007B0A5C || (nStartX >> 3) + nSpan + 1 < gnGlobal_007B0A54
        || (nStartY >> 3) > gnGlobal_007B0A60 || (nStartY >> 3) + nSpan + 1 < gnGlobal_007B0A58)
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

#define LIGHT_CELL(v, r, c) { v = gdwLightOverrideRows_007ACA50[r][c]; if (!v) { v = gdwLightMapRows_007A8A50[r][c]; } }

static __declspec(noinline) void sub_00474C00_BlendLightCell(int nCol, int nRow);

// 0x00474C00
static void sub_00474C00_BlendLightCell(int nCol, int nRow)
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

static __forceinline unsigned char sub_K01_GetGridCellByte(int nX, int nY)
{
    const int nGridX = (nX >> 3) - gnGlobal_007B0A54;
    if (nGridX < 0)
    {
        return 1;
    }
    if (nGridX >= 0x30)
    {
        return 1;
    }

    const int nGridY = (nY >> 3) - gnGlobal_007B0A58;
    if (nGridY < 0)
    {
        return 1;
    }
    if (nGridY >= 0x30)
    {
        return 1;
    }

    return gtGridCells_007B0E68[nGridY * 48 + nGridX].unk0x00[0];
}

static __declspec(noinline) void sub_00474A70_BuildOverrideWindow(D2R01LightStrc* pLight)
{
    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    const int nSpan = (pLight->nRadius * 2) >> 3;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            gdwLightOverrideRows_007ACA50[nOffset + j][nOffset + i] = sub_K01_GetGridCellByte(nX, nY) << 4;
            nX += 8;
        }
    }
}

static __declspec(noinline) void sub_00474D70_AddBlendedAreaLight(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nSpan = (pLight->nRadius * 2) >> 3;
    if ((nStartX >> 3) > gnGlobal_007B0A5C || (nStartX >> 3) + nSpan + 1 < gnGlobal_007B0A54
        || (nStartY >> 3) > gnGlobal_007B0A60 || (nStartY >> 3) + nSpan + 1 < gnGlobal_007B0A58)
    {
        return;
    }

    memset(gdwLightMapRows_007A8A50, 0, 0x1000);
    const int nRadCells = pLight->nRadius >> 3;
    const int nCellX = pLight->nX >> 3;
    const int nCellY = pLight->nY >> 3;
    sub_00474A70_BuildOverrideWindow(pLight);

    int nHi = 0x20 + 2;
    for (int k = 2; k <= nRadCells; ++k, ++nHi)
    {
        const int nLo = 0x20 - k;
        const int nTopX = (nCellX + k) * 8 + 4;
        const int nTopY = (nCellY + k) * 8 + 4;
        const int nBotX = (nCellX - k) * 8 + 4;
        const int nBotY = (nCellY - k) * 8 + 4;
        for (int m = 0; m <= k; ++m)
        {
            const int nUpX = (nCellX + m) * 8 + 4;
            const int nUpY = (nCellY + m) * 8 + 4;
            const int nDnX = (nCellX - m) * 8 + 4;
            const int nDnY = (nCellY - m) * 8 + 4;
            sub_00474B50_SetupStepDirection(nDnX, nBotY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 - m, nLo);
            sub_00474B50_SetupStepDirection(nUpX, nBotY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 + m, nLo);
            sub_00474B50_SetupStepDirection(nDnX, nTopY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 - m, nHi);
            sub_00474B50_SetupStepDirection(nUpX, nTopY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 + m, nHi);
            sub_00474B50_SetupStepDirection(nTopX, nDnY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nHi, 0x20 - m);
            sub_00474B50_SetupStepDirection(nTopX, nUpY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nHi, 0x20 + m);
            sub_00474B50_SetupStepDirection(nBotX, nDnY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nLo, 0x20 - m);
            sub_00474B50_SetupStepDirection(nBotX, nUpY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nLo, 0x20 + m);
        }
    }

    const int nScale = (pLight->nIntensity << 0x10) / pLight->nRadius;
    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        const int nDiffY = pLight->nY - nY;
        const int nDy = LIGHT_ABS(nDiffY);
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            const int nMask = gdwLightMapRows_007A8A50[nOffset + j][nOffset + i];
            if (nMask < 0x10)
            {
                const int nDiffX = pLight->nX - nX;
                const int nDx = LIGHT_ABS(nDiffX);
                int nValue = (int)(pLight->nRadius - sub_004740D0_ApproxDistance(nDy, nDx)) * nScale >> 0x10;
                nValue = nValue * (8 - (nMask >> 1)) >> 3;
                if (nValue > 0)
                {
                    sub_004747C0_AddGridLight(nValue, pLight->nRed, pLight->nGreen, pLight->nBlue, nY, nX);
                }
            }
            nX += 8;
        }
    }
}

// 0x004750F0
static __declspec(noinline) void sub_004750F0_BuildLightMask(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nSpan = (pLight->nRadius * 2) >> 3;
    memset(gdwLightMapRows_007A8A50, 0, 0x1000);
    const int nRadCells = pLight->nRadius >> 3;
    const int nCellX = pLight->nX >> 3;
    const int nCellY = pLight->nY >> 3;
    if (pLight->nUnitType == 6)
    {
        return;
    }

    D2UnitStrc* pUnit = pLight->f_8 ? sub_004639B0_FindServerSideUnit(pLight->nUnitId, pLight->nUnitType)
                                            : sub_00463990(pLight->nUnitId, pLight->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 0x414);

    const int nBaseX = CLIENTS_GetUnitX(pUnit) - 0x20;
    const int nBaseY = CLIENTS_GetUnitY(pUnit) - 0x20;
    for (int j = 0; j < 0x40; ++j)
    {
        for (int i = 0; i < 0x40; ++i)
        {
            gdwLightOverrideRows_007ACA50[j][i] = COLLISION_CheckMask(pRoom, i + nBaseX, j + nBaseY, 0x22) ? 0x10 : 0;
        }
    }

    int nHi = 0x20 + 2;
    for (int k = 2; k <= nRadCells; ++k, ++nHi)
    {
        const int nLo = 0x20 - k;
        const int nTopX = (nCellX + k) * 8 + 4;
        const int nTopY = (nCellY + k) * 8 + 4;
        const int nBotX = (nCellX - k) * 8 + 4;
        const int nBotY = (nCellY - k) * 8 + 4;
        for (int m = 0; m <= k; ++m)
        {
            const int nUpX = (nCellX + m) * 8 + 4;
            const int nUpY = (nCellY + m) * 8 + 4;
            const int nDnX = (nCellX - m) * 8 + 4;
            const int nDnY = (nCellY - m) * 8 + 4;
            sub_00474B50_SetupStepDirection(nDnX, nBotY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 - m, nLo);
            sub_00474B50_SetupStepDirection(nUpX, nBotY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 + m, nLo);
            sub_00474B50_SetupStepDirection(nDnX, nTopY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 - m, nHi);
            sub_00474B50_SetupStepDirection(nUpX, nTopY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(0x20 + m, nHi);
            sub_00474B50_SetupStepDirection(nTopX, nDnY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nHi, 0x20 - m);
            sub_00474B50_SetupStepDirection(nTopX, nUpY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nHi, 0x20 + m);
            sub_00474B50_SetupStepDirection(nBotX, nDnY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nLo, 0x20 - m);
            sub_00474B50_SetupStepDirection(nBotX, nUpY, (D2PathPointStrc*)pLight);
            sub_00474C00_BlendLightCell(nLo, 0x20 + m);
        }
    }

    D2_ASSERT(!pLight->bMaskReady, 0x454);
    D2_ASSERT(pLight->pMask, 0x455);

    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    unsigned int* pDst = pLight->pMask;
    for (int y = 0; y <= nSpan; ++y)
    {
        for (int x = 0; x <= nSpan; ++x)
        {
            *pDst++ = gdwLightMapRows_007A8A50[nOffset + y][nOffset + x];
        }
    }

    pLight->bMaskReady = 1;
}

static __declspec(noinline) void sub_00475420_AddMaskedAreaLight(D2R01LightStrc* pLight);

// 0x00475420
static void sub_00475420_AddMaskedAreaLight(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nSpan = (pLight->nRadius * 2) >> 3;
    int nCell = nStartX >> 3;
    if (nCell > gnGlobal_007B0A5C || nCell + nSpan + 1 < gnGlobal_007B0A54)
    {
        return;
    }

    nCell = nStartY >> 3;
    if (nCell > gnGlobal_007B0A60 || nCell + nSpan + 1 < gnGlobal_007B0A58)
    {
        return;
    }

    D2_ASSERT(pLight->pMask, 0x47E);
    D2_ASSERT(pLight->bMaskReady, 0x47F);

    const int nScale = (pLight->nIntensity << 0x10) / pLight->nRadius;
    int* pMask = (int*)pLight->pMask;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + 8 * j;
        const int nDiffY = pLight->nY - nY;
        const int nDy = LIGHT_ABS(nDiffY);
        for (int i = 0; i <= nSpan; ++i)
        {
            const int nX = nStartX + 8 * i;
            const int nMaskValue = *pMask;
            if (nMaskValue < 0x10)
            {
                const int nDiffX = pLight->nX - nX;
                const int nDx = LIGHT_ABS(nDiffX);
                int nValue = (pLight->nRadius - sub_00474080_GetDistance(nDx, nDy)) * nScale >> 0x10;
                nValue = nValue * (8 - (nMaskValue >> 1)) >> 3;
                if (nValue > 0)
                {
                    sub_004747C0_AddGridLight(nValue, pLight->nRed, pLight->nGreen, pLight->nBlue, nY, nX);
                }
            }
            ++pMask;
        }
    }
}

// 0x004755A0
static __declspec(noinline) void __stdcall sub_004755A0_UpdateLight(int nLevel, D2R01LightStrc* pLight)
{
    if (!pLight->bFixed && pLight->nUnitType != 6)
    {
        D2UnitStrc* pUnit = pLight->f_8 ? sub_004639B0_FindServerSideUnit(pLight->nUnitId, pLight->nUnitType)
                                                : sub_00463990(pLight->nUnitId, pLight->nUnitType);
        if (pUnit)
        {
            const int nPrecX = UNITS_GetPrecisionX(pUnit);
            const int nPrecY = UNITS_GetPrecisionY(pUnit);
            pLight->nX = (nPrecX >> 0xD) + 4;
            pLight->nY = (nPrecY >> 0xD) + 4;
        }
    }

    if (pLight->nTargetRadius != pLight->nRadius)
    {
        if (pLight->nMode == 2)
        {
            pLight->bMaskReady = 0;
            if (pLight->pMask)
            {
                FOG_Free(pLight->pMask, ".\\DRAW\\dLightMap.cpp", 0x4CC, 0);
            }
            pLight->pMask = 0;
        }

        if (pLight->nTargetRadius > pLight->nRadius)
        {
            pLight->nRadius += 8;
        }
        else
        {
            pLight->nRadius -= 8;
        }
    }

    if (pLight->nRadius >= 0x100)
    {
        pLight->nRadius = 0xF8;
    }

    if (pLight->bFixed && pLight->nRadius <= 0)
    {
        sub_004743D0_ReleaseOverlayResource(pLight);
        return;
    }

    if (!pLight->nMode && nLevel > 1)
    {
        sub_00474D70_AddBlendedAreaLight(pLight);
        return;
    }

    if (pLight->nMode == 2)
    {
        if (!pLight->bMaskReady)
        {
            if (!pLight->pMask)
            {
                const int nSide = 2 * (pLight->nRadius >> 3) + 1;
                pLight->pMask = (unsigned int*)FOG_Alloc(nSide * nSide * sizeof(unsigned int), ".\\DRAW\\dLightMap.cpp", 0x4F1, 0);
            }
            sub_004750F0_BuildLightMask(pLight);
        }
        sub_00475420_AddMaskedAreaLight(pLight);
        return;
    }

    sub_004748D0_AddAreaLight(pLight, nLevel);
}

__forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00475800
void __cdecl sub_00475800_RunLightPass()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nX = CLIENTS_GetUnitXInline(pPlayer);
    const int nY = CLIENTS_GetUnitYInline(pPlayer);
    gnGlobal_007B0A54 = nX - 0x18;
    gnGlobal_007B0A58 = nY - 0x18;
    gnGlobal_007B0A5C = gnGlobal_007B0A54 + 0x30;
    gnGlobal_007B0A60 = gnGlobal_007B0A58 + 0x30;
    sub_00474610_UpdateLightGrid(0);
    sub_004756D0_ScanGridCollision();
    const int nLevel = sub_00475780_GetIndicatorLevel();
    gnLightCount_007B5674 = 0;
    D2R01LightStrc* pLight = gpLights_007B5668;
    while (pLight)
    {
        ++gnLightCount_007B5674;
        D2R01LightStrc* pNext = pLight->pNext;
        sub_004755A0_UpdateLight(nLevel, pLight);
        pLight = pNext;
    }
}
