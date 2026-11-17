static __declspec(noinline) int sub_006C5F40_GetImageType(unsigned short signature);

// 0x006C5F40
static int sub_006C5F40_GetImageType(unsigned short signature)
{
    switch (signature)
    {
    case 0x050A:
        return 2;
    case 0x4D42:
        return 1;
    default:
        return 3;
    }
}

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
unsigned long __stdcall SFileSetFilePointer(void* hFile, long lDistanceToMove, long* plDistanceToMoveHigh, unsigned int dwMoveMethod); // 0x004165A0

void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

// build: context sub_006C59C0_FlipRows

__declspec(noinline) static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, unsigned int nDstSize, int nRowBytes, int nStride);
static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, unsigned int nDstSize, int nRowBytes, int nStride)
{
    FOG_AllocPool(pDst, 0, 0, nRows + *pDst, nRows);
    FOG_AllocPool(0, nDstSize, (const char*)pSrc, nRowBytes, nStride);
}

__declspec(noinline) static int __stdcall sub_006C5F70_LoadBmpFile(unsigned char* pPalette, void* hFile, int* pWidth, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth);
static int __stdcall sub_006C5F70_LoadBmpFile(unsigned char* pPalette, void* hFile, int* pWidth, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth); // 0x006C5F70

// 0x006C5F70
static int __stdcall sub_006C5F70_LoadBmpFile(unsigned char* pPalette, void* hFile, int* pWidth, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth)
{
    struct Bgr0Color { unsigned char blue, green, red, reserved; };
    Bgr0Color aColors[256];
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
            pPalette[4 * i + 0] = aColors[i].red;
            pPalette[4 * i + 1] = aColors[i].green;
            pPalette[4 * i + 2] = aColors[i].blue;
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
unsigned int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);                         // 0x00416370
unsigned long __stdcall sub_004165A0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004165A0

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

// build: context sub_006C5CF0_DecodeRle

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

struct D2TargaHeaderStrc { unsigned char bytes[18]; };
struct D2PaletteColorStrc { unsigned char red, green, blue, alpha; };

extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
void __stdcall SMemZero(void* destination, unsigned int size); // 0x0041D300
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

static __declspec(noinline)

// build: context sub_006C50D0_CheckTgaHeader
int sub_006C50D0_CheckTgaHeader(const D2TargaHeaderStrc* pHeader)
{
    const unsigned char nType = pHeader->bytes[2];
    if (nType != 1 && nType != 2 && nType != 9 && nType != 10)
    {
        return 0;
    }

    const unsigned char nColorMapType = pHeader->bytes[1];
    if (!nColorMapType)
    {
        const unsigned char nBits = pHeader->bytes[16];
        if (nBits == 24 && !(pHeader->bytes[17] & 0xF))
        {
            goto check_origin;
        }
        if (nBits == 32 && (pHeader->bytes[17] & 0xF) == 8)
        {
            goto check_origin;
        }
    }

    if (nColorMapType != 1 || pHeader->bytes[16] != 8)
    {
        return 0;
    }
    if (*(const unsigned short*)&pHeader->bytes[5] + *(const unsigned short*)&pHeader->bytes[3] > 256)
    {
        return 0;
    }
    if (pHeader->bytes[7] != 24 && pHeader->bytes[7] != 32)
    {
        return 0;
    }

check_origin:
    if (pHeader->bytes[17] & 0xC0)
    {
        return 0;
    }
    return 1;
}

static __declspec(noinline)
// 0x006C5150
int __stdcall sub_006C5150_ReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, D2PaletteColorStrc* palette)
{
    int bytesPerColor = (header->bytes[7] + 7) / 8;
    int index = *(const unsigned short*)&header->bytes[3];
    int end = index + *(const unsigned short*)&header->bytes[5];
    if ((end - index) * bytesPerColor != size)
        return 0;
    SMemZero(palette, index * sizeof(D2PaletteColorStrc));
    for (; index < end; ++index)
    {
        palette[index].red = source[2];
        palette[index].green = source[1];
        palette[index].blue = source[0];
        palette[index].alpha = bytesPerColor > 3 ? source[3] : 0;
        source += bytesPerColor;
    }
    SMemZero(palette + index, (256 - index) * sizeof(D2PaletteColorStrc));
    return 1;
}

static __declspec(noinline)

// build: context sub_006C5210_DecodeTgaPixels
int __fastcall sub_006C5210_DecodeTgaPixels(const D2TargaHeaderStrc* pHeader, const unsigned char* pSrc, int nSrcSize, unsigned char* pDst, int nDstSize)
{
    const int nBytes = (pHeader->bytes[16] + 7) / 8;
    const int nWidth = *(const unsigned short*)&pHeader->bytes[12];
    const int nImageSize = nBytes * *(const unsigned short*)&pHeader->bytes[14] * nWidth;
    int nSize = nDstSize;
    if (nSize >= nImageSize)
    {
        nSize = nImageSize;
    }

    const unsigned char nDescriptor = pHeader->bytes[17];
    int nStepX = nBytes;
    const unsigned char bRightToLeft = (nDescriptor >> 4) & 1;
    if (bRightToLeft)
    {
        nStepX = -nStepX;
    }

    const unsigned char bTopToBottom = (nDescriptor >> 5) & 1;
    int nRowStep;
    if (bTopToBottom)
    {
        nRowStep = (nBytes - nStepX) * nWidth;
    }
    else
    {
        nRowStep = -((nStepX + nBytes) * nWidth);
    }

    unsigned char* pOut = pDst;
    if (bRightToLeft)
    {
        pOut = pDst + (nWidth - 1) * nBytes;
    }

    if (!bTopToBottom)
    {
        pOut += (*(const unsigned short*)&pHeader->bytes[14] - 1) * nBytes * nWidth;
    }

    switch (pHeader->bytes[2])
    {
    case 1:
    case 2:
    {
        if (nSrcSize < nSize)
        {
            return 0;
        }

        if (!bRightToLeft && bTopToBottom)
        {
            SMemCopy(pOut, pSrc, nSize);
            return 1;
        }

        int nCount = nSize / nBytes;
        int nColumn = nWidth;
        while (nCount--)
        {
            switch (nBytes)
            {
            case 4:
                *(unsigned int*)pOut = *(const unsigned int*)pSrc;
                break;
            case 3:
                pOut[2] = pSrc[2];
            case 2:
                pOut[1] = pSrc[1];
            case 1:
                pOut[0] = pSrc[0];
            }

            pOut += nStepX;
            if (!--nColumn)
            {
                nColumn = nWidth;
                pOut += nRowStep;
            }

            pSrc += nBytes;
        }

        return 1;
    }

    case 9:
    case 10:
    {
        int nPixels = nSize / nBytes;
        int nColumn = nWidth;
        const unsigned char* pSrcEnd = pSrc + nSrcSize;
        while (nPixels)
        {
            if (pSrc >= pSrcEnd)
            {
                return 1;
            }

            int nRun = *pSrc++;
            if (nRun & 0x80)
            {
                nRun = (nRun & 0x7F) + 1;
                if (nRun >= nPixels)
                {
                    nRun = nPixels;
                }

                nPixels -= nRun;
                if (pSrc + nBytes > pSrcEnd)
                {
                    return 0;
                }

                while (nRun--)
                {
                    switch (nBytes)
                    {
                    case 4:
                        *(unsigned int*)pOut = *(const unsigned int*)pSrc;
                        break;
                    case 3:
                        pOut[2] = pSrc[2];
                    case 2:
                        pOut[1] = pSrc[1];
                    case 1:
                        pOut[0] = pSrc[0];
                    }

                    pOut += nStepX;
                    if (!--nColumn)
                    {
                        nColumn = nWidth;
                        pOut += nRowStep;
                    }
                }

                pSrc += nBytes;
            }
            else
            {
                nRun = nRun + 1;
                if (nRun >= nPixels)
                {
                    nRun = nPixels;
                }

                nPixels -= nRun;
                if (pSrc + nRun * nBytes > pSrcEnd)
                {
                    return 0;
                }

                while (nRun--)
                {
                    switch (nBytes)
                    {
                    case 4:
                        *(unsigned int*)pOut = *(const unsigned int*)pSrc;
                        break;
                    case 3:
                        pOut[2] = pSrc[2];
                    case 2:
                        pOut[1] = pSrc[1];
                    case 1:
                        pOut[0] = pSrc[0];
                    }

                    pOut += nStepX;
                    if (!--nColumn)
                    {
                        nColumn = nWidth;
                        pOut += nRowStep;
                    }

                    pSrc += nBytes;
                }
            }
        }

        return 1;
    }
    }

    return 0;
}

// 0x006C54D0
static int __stdcall sub_006C54D0_LoadTgaFromFile(void* hFile, D2PaletteColorStrc* pPalette, unsigned char* pBuffer, unsigned int* pWidth, int nBufferSize, unsigned int* pHeight, unsigned int* pBitDepth)
{
    D2TargaHeaderStrc tHeader;
    int nRead;
    if (!SFileReadFile(hFile, &tHeader, sizeof(tHeader), (unsigned int*)&nRead, 0) || nRead != sizeof(tHeader))
    {
        return 0;
    }
    if (!sub_006C50D0_CheckTgaHeader(&tHeader))
    {
        return 0;
    }

    const unsigned int nWidth = *(unsigned short*)&tHeader.bytes[12];
    const unsigned int nHeight = *(unsigned short*)&tHeader.bytes[14];
    const unsigned int nBitDepth = tHeader.bytes[16];

    int nPaletteSize;
    if (tHeader.bytes[1])
    {
        nPaletteSize = (tHeader.bytes[7] + 7) / 8 * *(unsigned short*)&tHeader.bytes[5];
    }
    else
    {
        nPaletteSize = 0;
    }

    int nImageSize;
    if (tHeader.bytes[2] >= 9)
    {
        nImageSize = 1;
    }
    else
    {
        nImageSize = ((int)nBitDepth + 7) / 8 * nHeight * nWidth;
    }

    const unsigned int nIdLength = tHeader.bytes[0];
    if (nIdLength + nImageSize + nPaletteSize + sizeof(tHeader) > sub_00416370_StormGetFileSize(hFile, 0))
    {
        return 0;
    }

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
        *pBitDepth = nBitDepth;
    }

    sub_004165A0_SetFilePointer(hFile, nIdLength, 0, 1);

    if (pPalette && tHeader.bytes[1])
    {
        unsigned char aPaletteData[0x400];
        SFileReadFile(hFile, aPaletteData, nPaletteSize, 0, 0);
        if (!sub_006C5150_ReadTgaPalette(&tHeader, aPaletteData, nPaletteSize, pPalette))
        {
            return 0;
        }
    }

    if (pBuffer)
    {
        const int nDataSize = sub_00416370_StormGetFileSize(hFile, 0) - sizeof(tHeader) - tHeader.bytes[0] - nPaletteSize;
        unsigned char* pData = (unsigned char*)SMemAlloc(nDataSize, ".\\SOURCE\\SBMP.CPP", 0x116, 0);
        SFileReadFile(hFile, pData, nDataSize, 0, 0);
        if (!sub_006C5210_DecodeTgaPixels(&tHeader, pData, nDataSize, pBuffer, nBufferSize))
        {
            SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 0x11D, 0);
            return 0;
        }
        SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 0x120, 0);
    }

    return 1;
}

int __stdcall sub_00419980(const char*,void**); // 0x00419980
int __stdcall sub_004198D0_CloseFile(void*); // 0x004198D0
void __stdcall sub_0041C340_SetLastError(unsigned int); // 0x0041C340

// 0x006C6B70
int __stdcall sub_006C6B70_LoadImage(const char* filename,unsigned char* palette,unsigned char* pixels,unsigned int bufferSize,int* width,int* height,int* bits)
{
 if(width)*width=0;
 if(height)*height=0;
 if(bits)*bits=0;
 int valid=((__int64)filename)?-1:0;
 valid &= (*filename)?-1:0;
 const unsigned int capacity=bufferSize;
 valid &= (capacity||!pixels)?-1:0;
 if(!valid){sub_0041C340_SetLastError(87);return 0;}
 void* hFile;
 if(!sub_00419980(filename,&hFile))return 0;
 int type=0;
 if(SFileReadFile(hFile,&bufferSize,2,0,0))
 {
  sub_004165A0_SetFilePointer(hFile,-2,0,1);
  type=sub_006C5F40_GetImageType((unsigned short)bufferSize);
 }
 int result=0;
 switch(type)
 {
 case 1:result=sub_006C5F70_LoadBmpFile(palette,hFile,width,pixels,capacity,height,bits);break;
 case 2:result=sub_006C6790_LoadPcx(hFile,palette,pixels,capacity,width,height,bits);break;
 case 3:result=sub_006C54D0_LoadTgaFromFile(hFile,(D2PaletteColorStrc*)palette,pixels,(unsigned int*)width,capacity,(unsigned int*)height,(unsigned int*)bits);break;
 }
 sub_004198D0_CloseFile(hFile);
 return result;
}
