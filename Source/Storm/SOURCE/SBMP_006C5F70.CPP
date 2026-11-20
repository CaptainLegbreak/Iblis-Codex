#pragma pack(push, 2)
struct D2BmpFileHeaderStrc
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
};
#pragma pack(pop)

struct D2BmpInfoHeaderStrc
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                   // 0x00412650
int __stdcall SFileReadFile(void* hFile, void* pBuffer, unsigned int nToRead, unsigned int* pnRead, void* pOverlapped); // 0x0041B050
unsigned long __stdcall SFileSetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004165A0

void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

__declspec(noinline) static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, unsigned int nDstSize, int nRowBytes, int nStride);
static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, unsigned int nDstSize, int nRowBytes, int nStride)
{
    FOG_AllocPool(pDst, 0, 0, nRows + *pDst, nRows);
    FOG_AllocPool(0, nDstSize, (const char*)pSrc, nRowBytes, nStride);
}

__declspec(noinline) static int __stdcall DecodeBmpFile(unsigned char* pPalette, int* pWidth, void* hFile, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth);
static int __stdcall DecodeBmpFile(unsigned char* pPalette, int* pWidth, void* hFile, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth); // 0x006C5F70

// 0x006C5F70
static int __stdcall DecodeBmpFile(unsigned char* pPalette, int* pWidth, void* hFile, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth)
{
    unsigned char aColors[0x400];
    D2BmpFileHeaderStrc tFileHeader;
    D2BmpInfoHeaderStrc tInfoHeader;

    if (!SFileReadFile(hFile, &tFileHeader, sizeof(tFileHeader), 0, 0))
    {
        return 0;
    }

    if (!SFileReadFile(hFile, &tInfoHeader, sizeof(tInfoHeader), 0, 0))
    {
        return 0;
    }

    if (pWidth)
    {
        *pWidth = tInfoHeader.biWidth;
    }

    if (pHeight)
    {
        *pHeight = tInfoHeader.biHeight;
    }

    if (pBitDepth)
    {
        *pBitDepth = tInfoHeader.biBitCount;
    }

    if (tInfoHeader.biBitCount > 8)
    {
        pPalette = 0;
    }
    else if (pPalette)
    {
        if (!SFileReadFile(hFile, aColors, sizeof(aColors), 0, 0))
        {
            return 0;
        }

        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = aColors[4 * i + 2];
            pPalette[4 * i + 1] = aColors[4 * i + 1];
            pPalette[4 * i + 2] = aColors[4 * i + 0];
            pPalette[4 * i + 3] = 0;
        }
    }

    if (pBuffer)
    {
        SFileSetFilePointer(hFile, tFileHeader.bfOffBits - (pPalette ? 0x400 : 0) - 0x36, 0, 1);

        unsigned int& nRead = *(unsigned int*)&pHeight;
        nRead = 0;
        unsigned char* pData = (unsigned char*)SMemAlloc(tInfoHeader.biSizeImage, ".\\SOURCE\\SBMP.CPP", 0x1FF, 0);
        SFileReadFile(hFile, pData, tInfoHeader.biSizeImage, &nRead, 0);

        const int nRowBytes = (int)(tInfoHeader.biBitCount * tInfoHeader.biWidth) >> 3;
        int nStride = nRowBytes;
        if (nRowBytes & 3)
        {
            nStride = nRowBytes - (nRowBytes & 3) + 4;
        }

        sub_006C59C0_FlipRows(pBuffer, tInfoHeader.biHeight, pData, nBufferSize, nRowBytes, nStride);
        SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 0x20B, 0);
        if (nRead < tInfoHeader.biSizeImage)
        {
            return 0;
        }
    }

    return 1;
}

int __stdcall sub_Emit_006C5F70(void* hFile, unsigned char* pPalette, unsigned char* pBuffer, unsigned int nBufferSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    return DecodeBmpFile(pPalette, pWidth, hFile, pBuffer, nBufferSize, pHeight, pBitDepth) + 1;
}
