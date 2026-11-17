#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIGHT_ABS(x) ((x) >= 0 ? (x) : -(x))

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
};

struct D2GridCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2R01LightStrc
{
    int nUnitType;
    unsigned int nUnitId;
    char unk0x08[8];
    int nX;
    int nY;
    int nRadius;
    char unk0x1C[8];
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern "C" int __cdecl abs(int nValue);
#pragma intrinsic(abs)

D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0

extern int gnGlobal_007B0A54;                                                                               // 0x007B0A54
extern int gnGlobal_007B0A58;                                                                               // 0x007B0A58
extern int gnGlobal_007B0A5C;                                                                               // 0x007B0A5C
extern int gnGlobal_007B0A60;                                                                               // 0x007B0A60
extern unsigned int gdwReciprocals_007B0A68[0x100];                                                         // 0x007B0A68
extern D2GridCellStrc gtGridCells_007B0E68[];                                                               // 0x007B0E68
extern int gnGlobal_00712B8C;                                                                               // 0x00712B8C
extern int gnPathStepMode_007B0A64;                                                                         // 0x007B0A64
int gnPathStepSignX_007B0A50;                                                                               // 0x007B0A50
int gnPathStepSignY_007A8A48;                                                                               // 0x007A8A48
extern int gnPathStepRatio_007A8A4C;                                                                        // 0x007A8A4C
unsigned int gdwLightMapRows_007A8A50[64][64];                                                              // 0x007A8A50
unsigned int gdwLightOverrideRows_007ACA50[64][64];                                                         // 0x007ACA50

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

void __stdcall sub_R01_Emit_004748D0(D2R01LightStrc* pLight, int nMode)
{
    if (pLight->nUnitType != 6)
    {
        sub_004748D0_AddAreaLight(pLight, nMode);
    }
    pLight->nRadius = 0;
}

#define LIGHT_CELL(v, r, c) { v = gdwLightOverrideRows_007ACA50[r][c]; if (!v) { v = gdwLightMapRows_007A8A50[r][c]; } }

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

void __stdcall sub_R01_Emit_00474C00(int nRow, int nColA, int nColB)
{
    sub_00474C00_BlendLightCell(nColA, nRow);
    sub_00474C00_BlendLightCell(nColB, nRow);
}
