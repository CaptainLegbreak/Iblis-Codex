struct D2PalRgba00605AA0Strc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

// 0x00605AA0
void __stdcall sub_00605AA0_BuildMultiplyTable(unsigned char* pTables)
{
    const D2PalRgba00605AA0Strc* pPalette = (const D2PalRgba00605AA0Strc*)pTables;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            pTables[0x43500 + j * 256 + i] = sub_00605210_FindNearestColor(pTables, 256,
                (unsigned char)((unsigned int)(pPalette[j].nRed * pPalette[i].nRed) / 255),
                (unsigned char)((unsigned int)(pPalette[j].nGreen * pPalette[i].nGreen) / 255),
                (unsigned char)((unsigned int)(pPalette[j].nBlue * pPalette[i].nBlue) / 255));
        }
    }
}
