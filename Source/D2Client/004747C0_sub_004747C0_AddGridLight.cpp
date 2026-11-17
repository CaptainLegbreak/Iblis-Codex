#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))

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

extern int gnGlobal_007B0A54;                                                                               // 0x007B0A54
extern int gnGlobal_007B0A58;                                                                               // 0x007B0A58
extern unsigned int gdwReciprocals_007B0A68[0x100];                                                         // 0x007B0A68
extern D2GridCellStrc gtGridCells_007B0E68[];                                                               // 0x007B0E68
extern int gnGlobal_00712B8C;                                                                               // 0x00712B8C

// 0x004747C0
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

void __stdcall sub_P08_Emit_004747C0(D2P08LightSourceStrc* pSource, int nX, int nY, int nIntensity)
{
    if (nIntensity > 0)
    {
        sub_004747C0_AddGridLight(nIntensity, pSource->nRed, pSource->nGreen, pSource->nBlue, nY, nX);
    }
}
