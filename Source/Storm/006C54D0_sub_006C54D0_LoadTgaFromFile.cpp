struct D2TargaHeaderStrc { unsigned char bytes[18]; };
struct D2PaletteColorStrc { unsigned char red, green, blue, alpha; };

extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
unsigned int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370
unsigned long __stdcall sub_004165A0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004165A0
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped); // 0x0041B050
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
    if (!SFileReadFile(hFile, &tHeader, sizeof(tHeader), &nRead, 0) || nRead != sizeof(tHeader))
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

int __stdcall sub_006C54D0_Emit(void* hFile, unsigned char* pBuffer, unsigned int* pWidth, D2PaletteColorStrc* pPalette, int nBufferSize, unsigned int* pHeight, unsigned int* pBitDepth)
{
    return sub_006C54D0_LoadTgaFromFile(hFile, pPalette, pBuffer, pWidth, nBufferSize, pHeight, pBitDepth) + 3;
}
