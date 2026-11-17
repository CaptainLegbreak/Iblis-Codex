void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
void __stdcall SMemCopy(void* pDst, const void* pSrc, unsigned int nSize);                                  // 0x0041D2A0

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2TargaHeaderStrc { unsigned char bytes[18]; };

struct T004F51E0 { unsigned char red, green, blue, alpha; };
void __stdcall SMemZero(void* destination, unsigned int size);                                              // 0x0041D300

#pragma pack(push, 1)
struct D2TgaFieldsStrc
{
    unsigned char nIdLength;
    unsigned char nColorMapType;
    unsigned char nImageType;
    unsigned short nColorMapFirst;
    unsigned short nColorMapLength;
    unsigned char nColorMapDepth;
    unsigned short nXOrigin;
    unsigned short nYOrigin;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned char nPixelDepth;
    unsigned char nDescriptor;
};
#pragma pack(pop)

static __declspec(noinline) int sub_006C50D0_IsSupportedTgaHeader(const D2TgaFieldsStrc* pHeader);

static int sub_006C50D0_IsSupportedTgaHeader(const D2TgaFieldsStrc* pHeader)
{
    const unsigned char nType = pHeader->nImageType;
    if (nType == 1 || nType == 2 || nType == 9 || nType == 10)
    {
        if ((pHeader->nColorMapType == 0
                && ((pHeader->nPixelDepth == 24 && !(pHeader->nDescriptor & 0x0F))
                    || (pHeader->nPixelDepth == 32 && (pHeader->nDescriptor & 0x0F) == 8)))
            || (pHeader->nColorMapType == 1 && pHeader->nPixelDepth == 8
                && pHeader->nColorMapLength + pHeader->nColorMapFirst <= 0x100
                && (pHeader->nColorMapDepth == 24 || pHeader->nColorMapDepth == 32)))
        {
            if (!(pHeader->nDescriptor & 0xC0))
            {
                return 1;
            }
        }
    }

    return 0;
}

static __declspec(noinline) int __stdcall sub_006C5150_ReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, T004F51E0* palette)
{
    int bytesPerColor = (header->bytes[7] + 7) / 8;
    int index = *(const unsigned short*)&header->bytes[3];
    int end = index + *(const unsigned short*)&header->bytes[5];
    if ((end - index) * bytesPerColor != size)
        return 0;
    SMemZero(palette, index * sizeof(T004F51E0));
    for (; index < end; ++index)
    {
        palette[index].red = source[2];
        palette[index].green = source[1];
        palette[index].blue = source[0];
        palette[index].alpha = bytesPerColor > 3 ? source[3] : 0;
        source += bytesPerColor;
    }
    SMemZero(palette + index, (256 - index) * sizeof(T004F51E0));
    return 1;
}

static __declspec(noinline) int __fastcall sub_006C5210_DecodeTgaPixels(const D2TargaHeaderStrc* pHeader, const unsigned char* pSrc, int nSrcSize, unsigned char* pDst, int nDstSize)
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

static __declspec(noinline) int __stdcall sub_006C5730_DecodeTga(const D2TgaFieldsStrc* pHeader, unsigned int nSize, T004F51E0* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth);

// 0x006C5730
static int __stdcall sub_006C5730_DecodeTga(const D2TgaFieldsStrc* pHeader, unsigned int nSize, T004F51E0* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth)
{
    if (nSize < 18)
    {
        return 0;
    }

    if (!sub_006C50D0_IsSupportedTgaHeader(pHeader))
    {
        return 0;
    }

    const int nDepth = pHeader->nPixelDepth;
    const int nWidth = pHeader->nWidth;
    const int nHeight = pHeader->nHeight;

    int nColorMapSize;
    if (pHeader->nColorMapType)
    {
        nColorMapSize = (pHeader->nColorMapDepth + 7) / 8 * pHeader->nColorMapLength;
    }
    else
    {
        nColorMapSize = 0;
    }

    int nImageSize;
    if (pHeader->nImageType >= 9)
    {
        nImageSize = 1;
    }
    else
    {
        nImageSize = (nDepth + 7) / 8 * nHeight * nWidth;
    }

    if (pHeader->nIdLength + nImageSize + nColorMapSize + 18 > nSize)
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
    if (pDepth)
    {
        *pDepth = nDepth;
    }

    if (pPalette && pHeader->nColorMapType)
    {
        const unsigned char* pColorMap = (const unsigned char*)pHeader + pHeader->nIdLength + 18;
        if (!sub_006C5150_ReadTgaPalette((const D2TargaHeaderStrc*)pHeader, pColorMap, nColorMapSize, pPalette))
        {
            return 0;
        }
    }

    if (pDst)
    {
        const unsigned char* pSrc = (const unsigned char*)pHeader + pHeader->nIdLength + nColorMapSize + 18;
        if (!sub_006C5210_DecodeTgaPixels((const D2TargaHeaderStrc*)pHeader, pSrc, (const unsigned char*)pHeader - pSrc + nSize, pDst, nDstSize))
        {
            return 0;
        }
    }

    return 1;
}

static __declspec(noinline) int sub_006C5F40_GetImageType(unsigned short signature);

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

__declspec(noinline) static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nWidth, int nSrcSize, int nBytesPerLine, int nPlanes);
static void __stdcall sub_006C5CF0_DecodeRle(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nWidth, int nSrcSize, int nBytesPerLine, int nPlanes)
{
    unsigned int* pOut = (unsigned int*)pDst;
    pOut[0] = nLimit;
    pOut[1] = nLimit ^ nSrcSize;
    pOut[2] = nSrcSize + 1;
    pOut[3] = nWidth + nBytesPerLine + nPlanes + pSrc - (const unsigned char*)0;
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

__declspec(noinline) static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride);
static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride)
{
    const unsigned char* pRow = pSrc + (nRows - 1) * nStride;
    unsigned char* pEnd = pDst + nDstSize;
    while (nRows)
    {
        int nSize = pEnd - pDst;
        if (nRowWidth < nSize)
        {
            nSize = nRowWidth;
        }
        if (!nSize)
        {
            break;
        }
        SMemCopy(pDst, pRow, nSize);
        pRow -= nStride;
        pDst += nSize;
        --nRows;
    }
}

__declspec(noinline) static int __stdcall sub_006C60F0_DecodeBmp(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize);
static int __stdcall sub_006C60F0_DecodeBmp(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize);

static int __stdcall sub_006C60F0_DecodeBmp(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize)
{
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

    if (*(const unsigned short*)(pData + 0x1C) > 8)
    {
        pPalette = 0;
    }
    else if (pPalette)
    {
        const unsigned char* pColors = pData + 0x36;
        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = pColors[4 * i + 2];
            pPalette[4 * i + 1] = pColors[4 * i + 1];
            pPalette[4 * i + 2] = pColors[4 * i + 0];
            pPalette[4 * i + 3] = 0;
        }
    }

    if (pPixels)
    {
        const int nRowWidth = (*(const unsigned short*)(pData + 0x1C) * *(const int*)(pData + 0x12)) >> 3;
        int nStride = nRowWidth;
        if (nRowWidth & 3)
        {
            nStride = nRowWidth - (nRowWidth & 3) + 4;
        }

        const int nPaletteSize = pPalette ? 0x400 : 0;
        sub_006C59C0_FlipRows(pPixels, *(const int*)(pData + 0x16), pData + (*(const int*)(pData + 0x0A) - nPaletteSize - 0x36), nPixelsSize, nRowWidth, nStride);
    }

    return 1;
}

// 0x006C6A80
int __stdcall sub_006C6A80_DecodeImage(int nType, const unsigned char* pData, unsigned int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    if (pWidth)
        *pWidth = 0;
    if (pHeight)
        *pHeight = 0;
    if (pBitDepth)
        *pBitDepth = 0;

    VALIDATEBEGIN;
    VALIDATE(pData);
    VALIDATE(nDataSize);
    VALIDATE(nPixelsSize || !pPixels);
    VALIDATEEND;

    if (!nType && nDataSize >= 2)
    {
        nType = sub_006C5F40_GetImageType(*(const unsigned short*)pData);
    }

    switch (nType)
    {
    case 1:
        return sub_006C60F0_DecodeBmp(pWidth, pHeight, (unsigned int*)pBitDepth, pData, pPalette, pPixels, nPixelsSize);
    case 2:
        return sub_006C6990_DecodePcx(pWidth, pData, nDataSize, pPalette, pPixels, nPixelsSize, pHeight, pBitDepth);
    case 3:
        return sub_006C5730_DecodeTga((const D2TgaFieldsStrc*)pData, nDataSize, (T004F51E0*)pPalette, pPixels, nPixelsSize, pWidth, pHeight, pBitDepth);
    }

    return 0;
}
