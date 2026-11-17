int __stdcall SFileReadFile(void* hFile, void* pBuffer, unsigned int nToRead, unsigned int* pnRead, void* pOverlapped); // 0x0041B050
unsigned int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);                         // 0x00416370
unsigned long __stdcall sub_004165A0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004165A0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);                   // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                           // 0x00412650

struct PcxHeaderStrc
{
    unsigned char nManufacturer;
    unsigned char nVersion;
    unsigned char nEncoding;
    unsigned char nBitsPerPixel;
    unsigned short nXMin;
    unsigned short nYMin;
    unsigned short nXMax;
    unsigned short nYMax;
    unsigned short nHDpi;
    unsigned short nVDpi;
    unsigned char pColorMap[48];
    unsigned char nReserved;
    unsigned char nPlanes;
    unsigned short nBytesPerLine;
    unsigned short nPaletteInfo;
    unsigned short nHScreenSize;
    unsigned short nVScreenSize;
    unsigned char pFiller[54];
};

struct PcxRgbStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

__declspec(noinline) static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nSrcSize, int nWidth, int nBytesPerLine, int nPlanes);
static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nSrcSize, int nWidth, int nBytesPerLine, int nPlanes)
{
    unsigned int* pOut = (unsigned int*)pDst;
    pOut[0] = nLimit;
    pOut[1] = nLimit ^ nSrcSize;
    pOut[2] = nSrcSize + 1;
    pOut[3] = nWidth + nBytesPerLine + nPlanes + pSrc - (const unsigned char*)0;
}

__declspec(noinline) static int __stdcall sub_006C6790_LoadPcx(void* hFile, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth);
static int __stdcall sub_006C6790_LoadPcx(void* hFile, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth); // 0x006C6790

// 0x006C6790
static int __stdcall sub_006C6790_LoadPcx(void* hFile, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    PcxHeaderStrc header;
    if (!SFileReadFile(hFile, &header, sizeof(header), 0, 0))
    {
        return 0;
    }

    const int nWidth = header.nXMax - header.nXMin + 1;
    const int nHeight = header.nYMax - header.nYMin + 1;
    const int nBits = header.nBitsPerPixel * header.nPlanes;

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

    const int bPalette = pPalette && nBits == 8;

    if (pPixels)
    {
        const int nDataSize = sub_00416370_StormGetFileSize(hFile, 0) - (nBits == 8 ? 0x300 : 0) - sub_004165A0_SetFilePointer(hFile, 0, 0, 1);
        unsigned char* pData = (unsigned char*)SMemAlloc(nDataSize, ".\\SOURCE\\SBMP.CPP", 1131, 0);
        SFileReadFile(hFile, pData, nDataSize, 0, 0);
        sub_006C5CF0_DecodeRle(pPixels, nPixelsSize, pData, nDataSize - (nBits == 8 ? 1 : 0), nWidth, header.nBytesPerLine, header.nPlanes);
        SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 1140, 0);
    }
    else if (bPalette)
    {
        sub_004165A0_SetFilePointer(hFile, -0x300, 0, 2);
    }

    if (bPalette)
    {
        PcxRgbStrc pColors[256];
        SFileReadFile(hFile, pColors, sizeof(pColors), 0, 0);
        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = pColors[i].nRed;
            pPalette[4 * i + 1] = pColors[i].nGreen;
            pPalette[4 * i + 2] = pColors[i].nBlue;
            pPalette[4 * i + 3] = 0;
        }
    }

    return 1;
}

int __stdcall sub_Emit_006C6790(void* hFile, unsigned char* pPalette, unsigned char* pPixels, unsigned int nSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    return sub_006C6790_LoadPcx(hFile, pPalette, pPixels, nSize, pWidth, pHeight, pBitDepth) + 2;
}
