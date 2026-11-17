unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

// 0x00605E60
void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 16; ++i)
    {
        for (unsigned int j = 0; j < 256; ++j)
        {
            pData[0x2400 + i * 256 + j] = sub_00605210_FindNearestColor(pData, 256,
                pData[j * 4 + 0] + ((0xFF - pData[j * 4 + 0]) * (i + 1) >> 4),
                pData[j * 4 + 1] + ((0xFF - pData[j * 4 + 1]) * (i + 1) >> 4),
                pData[j * 4 + 2] + ((0xFF - pData[j * 4 + 2]) * (i + 1) >> 4));
        }
    }
}
