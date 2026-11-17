void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

static __declspec(noinline) void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride);

// calling-convention shim (not game code)
static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride)
{
    FOG_AllocPool(pDst, 0, 0, nRows + *pDst, nRows);
    FOG_AllocPool(0, nDstSize, (const char*)pSrc, nRowWidth, nStride);
}

static __declspec(noinline) int __stdcall sub_006C60F0_DecodeBmp(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize);

// 0x006C60F0
static int __stdcall sub_006C60F0_DecodeBmp(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize)
{
    unsigned char* pOut = pPalette;
    if (pWidth)
    {
        *pWidth = *(const int*)(pData + 0x12);
    }

    if (pHeight)
    {
        *pHeight = *(const int*)(pData + 0x16);
    }

    if (pBitCount)
    {
        *pBitCount = *(const unsigned short*)(pData + 0x1C);
    }

    {
        if (*(const unsigned short*)(pData + 0x1C) > 8)
        {
            pOut = 0;
        }
        else if (pOut)
        {

            const unsigned char* pColors = pData + 0x36;
            for (pPalette = 0; (int)pPalette < 256; ++pPalette)
            {
                pOut[4 * (int)pPalette + 0] = pColors[4 * (int)pPalette + 2];
                pOut[4 * (int)pPalette + 1] = pColors[4 * (int)pPalette + 1];
                pOut[4 * (int)pPalette + 2] = pColors[4 * (int)pPalette + 0];
                pOut[4 * (int)pPalette + 3] = 0;
            }
        }

        if (pPixels)
        {
            const int nBitCount = *(const unsigned short*)(pData + 0x1C);
            const int nOffset = *(const int*)(pData + 0x0A) - (pOut ? 0x400 : 0) - 0x36;
            const int nRowWidth = (nBitCount * *(const int*)(pData + 0x12)) >> 3;
            int nStride = nRowWidth;
            if (nRowWidth & 3)
            {
                nStride = nRowWidth - (nRowWidth & 3) + 4;
            }

            sub_006C59C0_FlipRows(pPixels, *(const int*)(pData + 0x16), pData + nOffset, nPixelsSize, nRowWidth, nStride);
        }
    }

    return 1;
}

// build: context sub_006C60F0_Shim
// calling-convention shim (not game code)
int __stdcall sub_006C60F0_Shim(const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nSize, int* pWidth, int* pHeight, unsigned int* pBitCount)
{
    return sub_006C60F0_DecodeBmp(pWidth, pHeight, pBitCount, pData, pPalette, pPixels, nSize) + 2;
}
