#define STORM_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

__declspec(noinline) static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, unsigned int nWidth, int nSrcSize, unsigned int nBytesPerLine, int nPlanes);

// 0x006C5CF0
static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, unsigned int nWidth, int nSrcSize, unsigned int nBytesPerLine, int nPlanes)
{
    unsigned char* pDstEnd = pDst + nLimit;
    const unsigned char* pSrcEnd = pSrc + nSrcSize;
    const int nRowBytes = nWidth * nPlanes;
    unsigned int nColumn = 0;
    int nPlane = nPlanes - 1;

    while (pDst + nColumn < pDstEnd && pSrc < pSrcEnd)
    {
        unsigned char nToken = *pSrc++;
        if (nToken >= 0xC0)
        {
            unsigned int nCount = nToken & 0x3F;
            nCount = STORM_MIN(nCount, (unsigned int)(pDstEnd - pDst));

            nToken = *pSrc++;
            do
            {
                if (nColumn >= nWidth)
                {
                    unsigned int nSkip = STORM_MIN(nCount, nBytesPerLine - nColumn);
                    nColumn += nSkip;
                    if (nColumn >= nBytesPerLine)
                    {
                        nColumn -= nBytesPerLine;
                        if (--nPlane < 0)
                        {
                            pDst += nRowBytes;
                            nPlane = nPlanes - 1;
                        }
                    }

                    nCount -= nSkip;
                    if (!nCount)
                    {
                        break;
                    }
                }

                int nRun = STORM_MIN(nCount, nWidth - nColumn);

                switch (nPlanes)
                {
                case 1:
                    memset(pDst + nColumn, nToken, nRun);
                    break;

                case 3:
                {
                    int nOffset = nColumn * 3 + nPlane;
                    int nEnd = nOffset + STORM_MIN(pDstEnd - pDst, nRun * 3);
                    for (; nOffset < nEnd; nOffset += 3)
                    {
                        pDst[nOffset] = nToken;
                    }
                    break;
                }

                default:
                {
                    int nOffset = nColumn * nPlanes + nPlane;
                    int nEnd = nOffset + STORM_MIN(pDstEnd - pDst, nRun * nPlanes);
                    for (; nOffset < nEnd; nOffset += nPlanes)
                    {
                        pDst[nOffset] = nToken;
                    }
                    break;
                }
                }

                nColumn += nRun;
                if (nColumn >= nBytesPerLine)
                {
                    nColumn -= nBytesPerLine;
                    if (--nPlane < 0)
                    {
                        pDst += nRowBytes;
                        nPlane = nPlanes - 1;
                    }
                }

                nCount -= nRun;
            }
            while (nCount > 0);
        }
        else
        {
            if (nColumn < nWidth)
            {
                switch (nPlanes)
                {
                case 1:
                    pDst[nColumn] = nToken;
                    break;

                case 3:
                    if (pDst + (nColumn * 3 + nPlane) < pDstEnd)
                    {
                        pDst[nColumn * 3 + nPlane] = nToken;
                    }
                    break;

                default:
                    if (pDst + (nColumn * nPlanes + nPlane) < pDstEnd)
                    {
                        pDst[nColumn * nPlanes + nPlane] = nToken;
                    }
                    break;
                }
            }

            ++nColumn;
            if (nColumn >= nBytesPerLine)
            {
                nColumn -= nBytesPerLine;
                if (--nPlane < 0)
                {
                    pDst += nRowBytes;
                    nPlane = nPlanes - 1;
                }
            }
        }
    }
}

__declspec(noinline) static int __stdcall sub_006C6990_DecodePcx(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth);
static int __stdcall sub_006C6990_DecodePcx(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth); // 0x006C6990

// 0x006C6990
static int __stdcall sub_006C6990_DecodePcx(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth)
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

// build: context sub_Emit_006C6990

int __stdcall sub_Emit_006C6990(const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    return sub_006C6990_DecodePcx(pWidth, pData, nDataSize, pPalette, pPixels, nSize, pHeight, pBitDepth) + 2;
}
