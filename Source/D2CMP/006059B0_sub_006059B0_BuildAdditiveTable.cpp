struct D2PalRgba006059B0Strc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

#define PAL_SATURATE(x) ((unsigned int)(x) < 255 ? (x) : 255)

// 0x006059B0
void __stdcall sub_006059B0_BuildAdditiveTable(unsigned char* pTables)
{
    const D2PalRgba006059B0Strc* pPalette = (const D2PalRgba006059B0Strc*)pTables;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            const unsigned char nR = (unsigned char)PAL_SATURATE(pPalette[j].nRed + pPalette[i].nRed);
            const unsigned char nG = (unsigned char)PAL_SATURATE(pPalette[j].nGreen + pPalette[i].nGreen);
            const unsigned char nB = (unsigned char)PAL_SATURATE(pPalette[j].nBlue + pPalette[i].nBlue);
            pTables[0x33500 + j * 256 + i] = sub_00605210_FindNearestColor(pTables, 256, nR, nG, nB);
        }
    }
}
