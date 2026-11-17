// 0x00605210
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2)
{
    unsigned int nBestDistance = 0xFFFFFFFF;
    unsigned int nBest = 0;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        const int nDelta0 = pPalette[i * 4 + 0] - nC0;
        const int nDelta1 = pPalette[i * 4 + 1] - nC1;
        const int nDelta2 = pPalette[i * 4 + 2] - nC2;
        const unsigned int nDistance = nDelta2 * nDelta2 + nDelta1 * nDelta1 + nDelta0 * nDelta0;
        if (nDistance < nBestDistance)
        {
            nBest = i;
            nBestDistance = nDistance;
        }
    }
    return (unsigned char)nBest;
}
