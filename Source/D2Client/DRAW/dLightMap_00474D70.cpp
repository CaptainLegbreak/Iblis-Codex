#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIGHT_ABS(x) ((x) >= 0 ? (x) : -(x))

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

struct D2LightCellStrc
{
    unsigned char f_0;
    char unk0x01[7];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl abs(int nValue);
#pragma intrinsic(abs)

extern int gnGlobal_007B0A54;                                                                               // 0x007B0A54
extern int gnGlobal_007B0A58;                                                                               // 0x007B0A58
int gnGlobal_007B0A5C;                                                                                      // 0x007B0A5C
int gnGlobal_007B0A60;                                                                                      // 0x007B0A60
extern unsigned int gdwReciprocals_007B0A68[0x100];                                                         // 0x007B0A68
extern D2GridCellStrc gtGridCells_007B0E68[];                                                               // 0x007B0E68
extern int gnGlobal_00712B8C;                                                                               // 0x00712B8C
extern int gnPathStepMode_007B0A64;                                                                         // 0x007B0A64
extern int gnPathStepSignX_007B0A50;                                                                        // 0x007B0A50
extern int gnPathStepSignY_007A8A48;                                                                        // 0x007A8A48
extern int gnPathStepRatio_007A8A4C;                                                                        // 0x007A8A4C
extern unsigned int gdwLightMapRows_007A8A50[][64];                                                         // 0x007A8A50
extern unsigned int gdwLightOverrideRows_007ACA50[][64];                                                    // 0x007ACA50
extern int gnCellOriginX_007B0A54;                                                                          // 0x007B0A54
extern int gnCellOriginY_007B0A58;                                                                          // 0x007B0A58
extern D2LightCellStrc gaCells_007B0E68[0x30][0x30];                                                        // 0x007B0E68

static __declspec(noinline) void __stdcall sub_004747C0_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX);
static void __stdcall sub_004747C0_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX); // 0x004747C0
static __declspec(noinline) void sub_00474A70_BuildOverrideWindow(D2R01LightStrc* pLight);
static void sub_00474A70_BuildOverrideWindow(D2R01LightStrc* pLight); // 0x00474A70
static __declspec(noinline) void __stdcall sub_00474B50_SetupStepDirection(int nX, int nY, D2PathPointStrc* pPoint);
static void __stdcall sub_00474B50_SetupStepDirection(int nX, int nY, D2PathPointStrc* pPoint); // 0x00474B50
static __declspec(noinline) void sub_00474C00_BlendLightCell(int nCol, int nRow);
static void sub_00474C00_BlendLightCell(int nCol, int nRow); // 0x00474C00

static void __stdcall sub_004747C0_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX)
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

static void sub_00474A70_BuildOverrideWindow(D2R01LightStrc* pLight)
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

static void __stdcall sub_00474B50_SetupStepDirection(int nX, int nY, D2PathPointStrc* pPoint)
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

static unsigned int __stdcall sub_004740D0_ApproxDistanceInl(int nB, int nA)
{
    const int nAbsA = abs(nA);
    const int nAbsB = abs(nB);
    if (nAbsA >= nAbsB)
    {
        return (unsigned int)(nAbsA * 0x3D7 + nAbsB * 0x197) >> 10;
    }

    return (unsigned int)(nAbsB * 0x3D7 + nAbsA * 0x197) >> 10;
}

static __declspec(noinline) void sub_00474D70_AddBlendedAreaLight(D2R01LightStrc* pLight);

// 0x00474D70
static void sub_00474D70_AddBlendedAreaLight(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nSpan = (pLight->nRadius * 2) >> 3;
    const int nCellStartX = nStartX >> 3;
    if (nCellStartX > gnGlobal_007B0A5C || nCellStartX + nSpan + 1 < gnGlobal_007B0A54)
    {
        return;
    }

    const int nCellStartY = nStartY >> 3;
    if (nCellStartY > gnGlobal_007B0A60 || nCellStartY + nSpan + 1 < gnGlobal_007B0A58)
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
                int nValue = (int)(pLight->nRadius - sub_004740D0_ApproxDistanceInl(nDy, nDx)) * nScale >> 0x10;
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

void __stdcall sub_E4F1_Emit_00474D70(int nLevel, D2R01LightStrc* pLight)
{
    if (!pLight->nMode && nLevel > 1)
    {
        sub_00474D70_AddBlendedAreaLight(pLight);
        return;
    }

    pLight->nRadius = 0;
}
