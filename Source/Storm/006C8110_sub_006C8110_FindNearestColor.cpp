struct D2RgbQuad006C8110Strc
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

D2RgbQuad006C8110Strc gaColors_00989C40[256];        // 0x00989C40

// 0x006C8110
unsigned char __fastcall sub_006C8110_FindNearestColor(int nRed, int nBlue, int nGreen)
{
    unsigned char nIndex = 0;
    int nBest = 10000;
    for (int i = 1; i < 256; ++i)
    {
        int nDiff = gaColors_00989C40[i].rgbRed - nRed;
        if (nDiff < 0)
            nDiff = -nDiff;
        const int nRedDiff = nDiff;
        nDiff = gaColors_00989C40[i].rgbGreen - nGreen;
        if (nDiff < 0)
            nDiff = -nDiff;
        const int nGreenDiff = nDiff;
        nDiff = gaColors_00989C40[i].rgbBlue - nBlue;
        if (nDiff < 0)
            nDiff = -nDiff;
        nDiff += nGreenDiff;
        if (nDiff + nRedDiff < nBest)
        {
            nBest = nDiff + nRedDiff;
            nIndex = (unsigned char)i;
        }
    }
    return nIndex;
}
