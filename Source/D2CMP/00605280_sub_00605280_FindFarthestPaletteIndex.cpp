extern int gnSquareTable_008E9034[511];                                                                     // 0x008E9034
#define gnSquareTableCenter_008E9430 (gnSquareTable_008E9034 + 255)

// 0x00605280
unsigned char __stdcall sub_00605280_FindFarthestPaletteIndex(unsigned char* pPalette, unsigned int nCount, int nRed, int nGreen, int nBlue)
{
    unsigned int nBest = 0;
    unsigned int nBestIndex = 0;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        const int d0 = pPalette[i * 4 + 0] - nRed;
        const int d1 = pPalette[i * 4 + 1] - nGreen;
        const int d2 = pPalette[i * 4 + 2] - nBlue;
        const unsigned int nDist = d0 * d0 + d1 * d1 + d2 * d2;
        if (nDist > nBest)
        {
            nBestIndex = i;
            nBest = nDist;
        }
    }
    return (unsigned char)nBestIndex;
}

// 0x006052F0
void __cdecl sub_006052F0_InitSquareTable()
{
    for (int i = -256; i < 256; ++i)
        gnSquareTableCenter_008E9430[i] = i * i;
}
