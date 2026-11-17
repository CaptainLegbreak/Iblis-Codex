unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

// 0x00605880
void __stdcall sub_00605880_BuildTablesA(unsigned char* pTables)
{
    unsigned int n = 0;
    if (3 > n)
    {
        do
        {
            int i = 0;
            int nAlpha;
            switch (n)
            {
            case 0:
                nAlpha = 0xBF;
                break;

            case 1:
                nAlpha = 0x7F;
                break;

            default:
                nAlpha = 0x3F;
                break;
            }

            const int nInverse = 0xFF - nAlpha;
            while (i < 256)
            {
                for (int j = 0; 256 > j; ++j)
                {
                    pTables[0x3500 + (n << 16) + j * 256 + i] = sub_00605210_FindNearestColor(pTables, 256,
                        (unsigned char)((unsigned int)(pTables[j * 4 + 0] * nInverse + pTables[i * 4 + 0] * nAlpha) / 255),
                        (unsigned char)((unsigned int)(pTables[j * 4 + 1] * nInverse + pTables[i * 4 + 1] * nAlpha) / 255),
                        (unsigned char)((unsigned int)(pTables[j * 4 + 2] * nInverse + pTables[i * 4 + 2] * nAlpha) / 255));
                }
                ++i;
            }
            ++n;
        } while (n < 3);
    }
}
