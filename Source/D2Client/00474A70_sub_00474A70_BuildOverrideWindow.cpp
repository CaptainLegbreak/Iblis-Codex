struct D2LightCellStrc
{
    unsigned char f_0;
    char unk0x01[7];
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

extern int gnCellOriginX_007B0A54;                                                                          // 0x007B0A54
extern int gnCellOriginY_007B0A58;                                                                          // 0x007B0A58
extern D2LightCellStrc gaCells_007B0E68[0x30][0x30];                                                        // 0x007B0E68
extern unsigned int gdwLightOverrideRows_007ACA50[][64];                                                    // 0x007ACA50

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

void sub_M241_Emit_00474D70(D2R01LightStrc* pLight)
{
    sub_00474A70_BuildOverrideWindow(pLight);
}
