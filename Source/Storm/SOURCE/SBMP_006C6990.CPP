__declspec(noinline) static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nWidth, int nSrcSize, int nBytesPerLine, int nPlanes);
static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nWidth, int nSrcSize, int nBytesPerLine, int nPlanes)
{
    unsigned int* pOut = (unsigned int*)pDst;
    pOut[0] = nLimit;
    pOut[1] = nLimit ^ nSrcSize;
    pOut[2] = nSrcSize + 1;
    pOut[3] = nWidth + nBytesPerLine + nPlanes + pSrc - (const unsigned char*)0;
}

__declspec(noinline) static int __stdcall DecodePcxMem(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth);
static int __stdcall DecodePcxMem(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth); // 0x006C6990

// 0x006C6990
static int __stdcall DecodePcxMem(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth)
{
    const int nWidth = *(const unsigned short*)(pData + 8) - *(const unsigned short*)(pData + 4) + 1;
    const int nHeight = *(const unsigned short*)(pData + 0x0A) - *(const unsigned short*)(pData + 6) + 1;
    const int nBits = pData[3] * pData[0x41];

    if (pWidth)
    {
        *pWidth = nWidth;
    }

    if (pHeight)
    {
        *pHeight = nHeight;
    }

    if (pBitDepth)
    {
        *pBitDepth = nBits;
    }

    if (pPixels)
    {
        unsigned int nLimit = (nBits + 7) / 8 * nHeight * nWidth;
        if (nPixelsSize < nLimit)
        {
            nLimit = nPixelsSize;
        }

        sub_006C5CF0_DecodeRle(pPixels, nLimit, pData + 0x80, nWidth, nDataSize - (nBits == 8 ? 0x301 : 0) - 0x80, *(const unsigned short*)(pData + 0x42), pData[0x41]);
    }

    if (pPalette && nBits == 8)
    {
        const unsigned char* pColors = pData + nDataSize - 0x300;
        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = pColors[3 * i + 0];
            pPalette[4 * i + 1] = pColors[3 * i + 1];
            pPalette[4 * i + 2] = pColors[3 * i + 2];
            pPalette[4 * i + 3] = 0;
        }
    }

    return 1;
}

int __stdcall sub_Emit_006C6990(const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    return DecodePcxMem(pWidth, pData, nDataSize, pPalette, pPixels, nSize, pHeight, pBitDepth) + 2;
}
