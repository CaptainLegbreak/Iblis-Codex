unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

#define PAL_MAX(a, b) ((a) > (b) ? (a) : (b))

// 0x00605B70
void __stdcall sub_00605B70_BuildBlendTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        unsigned char nC0 = pData[i * 4 + 0];
        unsigned char nC1 = pData[i * 4 + 1];
        unsigned char nC2 = pData[i * 4 + 2];

        if (nC0 > 0)
        {
            nC0 += nC0 / -3;
        }

        if (nC2 > 0)
        {
            nC2 += nC2 / -3;
        }

        if (nC1 > 0)
        {
            nC1 += nC1 / -3;
        }

        pData[0x6B500 + i] = sub_00605210_FindNearestColor(pData, 256, nC0, nC1, nC2);
    }

    for (unsigned int j = 0; j < 256; ++j)
    {
        const unsigned int nMax = PAL_MAX(PAL_MAX(pData[j * 4 + 0], pData[j * 4 + 1]), pData[j * 4 + 2]);
        const unsigned int nInv = 255 - nMax;
        for (unsigned int k = 0; k < 256; ++k)
        {
            pData[0x5B500 + k * 256 + j] = sub_00605210_FindNearestColor(pData, 256,
                (unsigned char)((pData[j * 4 + 0] * nMax + pData[k * 4 + 0] * nInv) / 255),
                (unsigned char)((pData[j * 4 + 1] * nMax + pData[k * 4 + 1] * nInv) / 255),
                (unsigned char)((pData[j * 4 + 2] * nMax + pData[k * 4 + 2] * nInv) / 255));
        }
    }
}
