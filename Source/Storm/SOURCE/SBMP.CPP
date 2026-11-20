#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

struct D2TargaHeaderStrc;
struct D2TgaFieldsStrc;
struct D2BitOutputStrc;
struct D2BitmapFileHeader;
struct D2BitmapInfoHeader;
struct D2PaletteEntry;
struct D2BitmapColor;
struct D2CopyStackArg;

struct D2TargaHeaderStrc { unsigned char bytes[18]; };

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

struct tagPALETTEENTRY { unsigned char red, green, blue, alpha; };

void __stdcall SMemZero(void* destination, unsigned int size); // 0x0041D300

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
static __declspec(noinline) int __stdcall DecodeTgaMem(const D2TgaFieldsStrc* pHeader, unsigned int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
static __declspec(noinline) void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride);
static __declspec(noinline) int __stdcall sub_006C60F0_DecodeBmp(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize);

struct D2BitOutputStrc
{
    int f_0;
    int nCodeMask;
    int nInitialCodeWidth;
    int nBits;
    int nBitCount;
    int unknown14[2];
    int nClearCode;
    int unknown20;
    int nNextCode;
    void* f_28;
    int unknown2C;
    int nBlockLength;
    unsigned char pBlock[256];
};
static __declspec(noinline) void sub_006C5A60_FlushBlock(D2BitOutputStrc*, unsigned char**);
static __declspec(noinline) void __fastcall sub_006C5A90_EmitCode(D2BitOutputStrc*, unsigned char**, int);
static __declspec(noinline) void __stdcall ClearBlock(unsigned char**, D2BitOutputStrc*);
const char* __stdcall SStrChr(const char* szString, char c); // 0x00413490
static __declspec(noinline) const char* sub_006C5EE0_FindExtension(const char* szPath);
static __declspec(noinline) int sub_006C5F40_GetImageType(unsigned short signature);
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

typedef unsigned char BYTE;

typedef unsigned short WORD;

typedef unsigned int DWORD;

#pragma pack(push, 2)
struct D2BitmapFileHeader { WORD type; DWORD size; WORD reserved1; WORD reserved2; DWORD offset; };

#pragma pack(pop)
struct D2BitmapInfoHeader {
    DWORD size; int width; int height; WORD planes; WORD bits;
    DWORD compression; DWORD imageSize; int xppm; int yppm; DWORD colorsUsed; DWORD colorsImportant;
};

struct D2PaletteEntry { BYTE red, green, blue, flags; };

struct D2BitmapColor { BYTE blue, green, red, reserved; };
void* __stdcall sub_00413020_Alloc(unsigned int, const char*, int, unsigned int); // 0x00413020
void __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
extern "C" __declspec(dllimport) int __stdcall WriteFile(void*, const void*, unsigned int, unsigned int*, void*); // 0x006CC1A8

struct D2CopyStackArg { unsigned int value; };

static __declspec(noinline) unsigned int __stdcall sub_006C59C0_CopyPixels(BYTE* out, D2CopyStackArg src, D2CopyStackArg size, D2CopyStackArg pitch, D2CopyStackArg width, unsigned int rows); // 0x006C59C0
static __declspec(noinline) int __stdcall EncodeBmp256File(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height);

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

static __declspec(noinline) int __stdcall sub_006C5150_ReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, tagPALETTEENTRY* palette)
{
    int bytesPerColor = (header->bytes[7] + 7) / 8;
    int index = *(const unsigned short*)&header->bytes[3];
    int end = index + *(const unsigned short*)&header->bytes[5];
    if ((end - index) * bytesPerColor != size)
        return 0;
    SMemZero(palette, index * sizeof(tagPALETTEENTRY));
    for (; index < end; ++index)
    {
        palette[index].red = source[2];
        palette[index].green = source[1];
        palette[index].blue = source[0];
        palette[index].alpha = bytesPerColor > 3 ? source[3] : 0;
        source += bytesPerColor;
    }
    SMemZero(palette + index, (256 - index) * sizeof(tagPALETTEENTRY));
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

// 0x006C5730
static int __stdcall DecodeTgaMem(const D2TgaFieldsStrc* pHeader, unsigned int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth)
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

int __stdcall sub_006C5730_EmitCaller(int nUnused, const D2TgaFieldsStrc* pHeader, unsigned int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth)
{
    if (pWidth)
    {
        *pWidth = 0;
    }
    return DecodeTgaMem(pHeader, nSize, pPalette, pDst, nDstSize, pWidth, pHeight, pDepth);
}

// 0x006C59C0
static void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride)
{
    VALIDATEBEGIN;
    VALIDATE(pDst);
    __assume(pDst != 0);
    VALIDATE(pSrc);
    __assume(pSrc != 0);
    VALIDATE(nDstSize);
    __assume(nDstSize != 0);
    VALIDATE(nRowWidth);
    __assume(nRowWidth != 0);
    VALIDATE(nStride);
    __assume(nStride != 0);
    VALIDATE(nRows);
    __assume(nRows != 0);
    VALIDATEEND;

    {
    pSrc += (nRows - 1) * nStride;
    unsigned char* pEnd = pDst + nDstSize;
    while (nRows--)
    {
        const int nCopy = nRowWidth < pEnd - pDst ? nRowWidth : pEnd - pDst;
        if (!nCopy)
            break;
        SMemCopy(pDst, pSrc, nCopy);
        pDst += nCopy;
        pSrc -= nStride;
    }
    }
}

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

// 0x006C5A60
static void sub_006C5A60_FlushBlock(D2BitOutputStrc* pState, unsigned char** ppOutput)
{
    if (pState->nBlockLength)
    {
        pState->pBlock[0] = (unsigned char)pState->nBlockLength;
        ++pState->nBlockLength;
        SMemCopy(*ppOutput, pState->pBlock, pState->nBlockLength);
        *ppOutput += pState->nBlockLength;
        pState->nBlockLength = 0;
    }
}

void __fastcall EmitCodeContext(unsigned char** ppOutput, D2BitOutputStrc* pState, int nCode)
{
    pState->nBits |= nCode << pState->nBitCount;
    pState->nBitCount += pState->f_0;
    while (pState->nBitCount >= 8)
    {
        ++pState->nBlockLength;
        pState->pBlock[pState->nBlockLength] = (unsigned char)pState->nBits;
        if (pState->nBlockLength >= 255)
            sub_006C5A60_FlushBlock(pState, ppOutput);
        pState->nBits >>= 8;
        pState->nBitCount -= 8;
    }
    if (pState->nNextCode > pState->nCodeMask)
    {
        ++pState->f_0;
        pState->nCodeMask = pState->f_0 == 12 ? 4096 : (1 << pState->f_0) - 1;
    }
}

// 0x006C5A90
static void __fastcall sub_006C5A90_EmitCode(D2BitOutputStrc* pState, unsigned char** ppOutput, int nCode)
{
    pState->nBits |= nCode << pState->nBitCount;
    pState->nBitCount += pState->f_0;
    while (pState->nBitCount >= 8)
    {
        ++pState->nBlockLength;
        pState->pBlock[pState->nBlockLength] = (unsigned char)pState->nBits;
        if (pState->nBlockLength >= 255)
            sub_006C5A60_FlushBlock(pState, ppOutput);
        pState->nBits >>= 8;
        pState->nBitCount -= 8;
    }
    if (pState->nNextCode > pState->nCodeMask)
    {
        ++pState->f_0;
        if (pState->f_0 == 12)
            pState->nCodeMask = 4096;
        else
            pState->nCodeMask = (1 << pState->f_0) - 1;
    }
}

// 0x006C6330
static void __stdcall ClearBlock(unsigned char** ppOutput, D2BitOutputStrc* pState)
{
    SMemZero(pState->f_28, 0x4E2C);
    int nCode = pState->nClearCode;
    pState->nNextCode = nCode + 2;
    sub_006C5A90_EmitCode(pState, ppOutput, nCode);
    int nWidth = pState->nInitialCodeWidth;
    pState->f_0 = nWidth;
    pState->nCodeMask = (1 << nWidth) - 1;
}

void __fastcall ResetDictionaryContext(D2BitOutputStrc* pState, unsigned char** ppOutput)
{
    ClearBlock(ppOutput, pState);
}

// 0x006C5EE0
static const char* sub_006C5EE0_FindExtension(const char* szPath)
{
    const char* szName = szPath;
    while (SStrChr(szName, '\\'))
        szName = SStrChr(szName, '\\') + 1;
    while (SStrChr(szName + 1, '.'))
        szName = SStrChr(szName + 1, '.');
    return szName;
}

// calling-convention shim (not game code)
const char* __fastcall sub_006C5EE0_Shim(const char* szPath)
{
    return sub_006C5EE0_FindExtension(szPath);
}

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

int __cdecl EmitGetImageType(unsigned short signature)
{
    return sub_006C5F40_GetImageType(signature);
}

// build: context sub_006C59C0_CopyPixels
static unsigned int __stdcall sub_006C59C0_CopyPixels(BYTE* out, D2CopyStackArg src, D2CopyStackArg size, D2CopyStackArg pitch, D2CopyStackArg width, unsigned int rows)
{
    rows += src.value + size.value + pitch.value + width.value;
    out[0] = (BYTE)rows;
    out[1] = (BYTE)(rows >> 8);
    return rows;
}

// 0x006C61C0
static int __stdcall EncodeBmp256File(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height)
{
    D2BitmapFileHeader header;
    D2BitmapInfoHeader info;
    D2BitmapColor colors[256];
    unsigned int pixelWritten;
    {
        unsigned int written;
        SMemZero(&header, sizeof(header));
        int imageSize = width * height;
        header.size = imageSize + 1078;
        header.type = 0x4D42;
        header.offset = 1078;
        WriteFile(file, &header, sizeof(header), &written, 0);
        SMemZero(&info, sizeof(info));
        info.size = 40;
        info.width = width;
        info.height = height;
        info.planes = 1;
        info.bits = 8;
        info.compression = 0;
        info.imageSize = imageSize;
        info.colorsUsed = 256;
        info.colorsImportant = 256;
        WriteFile(file, &info, sizeof(info), &written, 0);
        for (int i = 0; i < 256; ++i)
        {
            colors[i].red = palette[i].red;
            colors[i].green = palette[i].green;
            colors[i].blue = palette[i].blue;
            colors[i].reserved = 0;
        }
        WriteFile(file, colors, sizeof(colors), &written, 0);
    }
    unsigned int nPitch = width;
    if ((width & 3))
        nPitch = width - (width & 3) + 4;
    int bufferSize = nPitch * height;
    BYTE* buffer = (BYTE*)sub_00413020_Alloc(bufferSize, ".\\SOURCE\\SBMP.CPP", 660, 0);
    D2CopyStackArg copySource = { (unsigned int)pixels };
    D2CopyStackArg copySize = { (unsigned int)bufferSize };
    D2CopyStackArg copyPitch = { nPitch };
    D2CopyStackArg copyWidth = { (unsigned int)width };
    sub_006C59C0_CopyPixels(buffer, copySource, copySize, copyPitch, copyWidth, height);
    WriteFile(file, buffer, bufferSize, &pixelWritten, 0);
    SMemFree(buffer, ".\\SOURCE\\SBMP.CPP", 668, 0);
    return 1;
}

// build: context sub_006C61C0_Shim
// calling-convention shim (not game code)
int __stdcall sub_006C61C0_Shim(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height)
{
    return EncodeBmp256File(file, palette, pixels, width, height);
}
