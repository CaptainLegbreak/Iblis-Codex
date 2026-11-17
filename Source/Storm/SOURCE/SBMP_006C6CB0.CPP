// build: base-profile

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

const char* __stdcall SStrChr(const char* szString, char c);                                                                  // 0x00413490
extern "C" int __cdecl _stricmp(const char*, const char*);                                                  // 0x006841E9
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void __stdcall SMemZero(void* pDst, unsigned int nSize); // 0x0041D300
int __fastcall sub_006C5B60_WritePcx(int nHeight, int nWidth, void* hFile, unsigned char* pPalette, unsigned char* pPixels); // 0x006C5B60
extern const char gszTga_006FCC7C[]; // 0x006FCC7C
extern const char gszPcx_006FCC74[]; // 0x006FCC74
extern const char gszGif_006FCC6C[]; // 0x006FCC6C

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
struct RGBQuad { unsigned char r, g, b, a; };
struct RGBTriple { unsigned char r, g, b; };
void* __stdcall sub_00413020_Alloc(unsigned int, const char*, int, unsigned int); // 0x00413020
void __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
extern "C" __declspec(dllimport) int __stdcall WriteFile(void*, const void*, unsigned int, unsigned int*, void*); // 0x006CC1A8
extern const char gszSBmpSource[]; // 0x006FCC58
int __fastcall sub_006C6470_CompressGif(int nCount, const unsigned char* pPixels, unsigned char* pOut); // 0x006C6470

static __declspec(noinline) const char* sub_006C5EE0_FindExtension(const char* szPath);
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

static __forceinline int SBmpWrite(void* hFile, const void* pData, unsigned int nBytes)
{
    unsigned int written;
    return WriteFile(hFile, pData, nBytes, &written, 0);
}

static __declspec(noinline) int __stdcall sub_006C6620_SaveGif(void* hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight);

// 0x006C6620
static int __stdcall sub_006C6620_SaveGif(void* hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight)
{
    unsigned char header[13];
    unsigned char marker;
    RGBTriple palette[256];
    unsigned int written;

    header[0] = 'G';
    header[1] = 'I';
    header[2] = 'F';
    header[3] = '8';
    header[4] = '7';
    header[5] = 'a';
    *(unsigned short*)(header + 6) = (unsigned short)nWidth;
    *(unsigned short*)(header + 8) = (unsigned short)nHeight;
    header[10] = 0xF7;
    header[11] = 0;
    header[12] = 0;
    SBmpWrite(hFile, header, 13);

    for (int i = 0; i < 256; ++i)
    {
        palette[i].r = pPalette[i].r;
        palette[i].g = pPalette[i].g;
        palette[i].b = pPalette[i].b;
    }
    SBmpWrite(hFile, palette, 768);

    marker = ',';
    SBmpWrite(hFile, &marker, 1);

    *(unsigned short*)(header + 0) = 0;
    *(unsigned short*)(header + 2) = 0;
    *(unsigned short*)(header + 4) = (unsigned short)nWidth;
    *(unsigned short*)(header + 6) = (unsigned short)nHeight;
    header[8] = 0;
    header[9] = 8;
    SBmpWrite(hFile, header, 10);

    unsigned char* pData = (unsigned char*)sub_00413020_Alloc(nWidth * nHeight * 2, gszSBmpSource, 1000, 0);
    int nLength = sub_006C6470_CompressGif(nWidth * nHeight, pPixels, pData);
    WriteFile(hFile, pData, nLength, &written, 0);
    SMemFree(pData, gszSBmpSource, 1006, 0);

    marker = 0;
    SBmpWrite(hFile, &marker, 1);
    marker = ';';
    SBmpWrite(hFile, &marker, 1);
    return 1;
}

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

static __declspec(noinline) void __stdcall sub_006C59C0_FlipRows(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride);

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
    if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

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

static __declspec(noinline) int __stdcall sub_006C61C0_WriteBmp(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height);
// 0x006C61C0
static int __stdcall sub_006C61C0_WriteBmp(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height)
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
    sub_006C59C0_FlipRows(buffer, height, pixels, bufferSize, nPitch, width);
    WriteFile(file, buffer, bufferSize, &pixelWritten, 0);
    SMemFree(buffer, ".\\SOURCE\\SBMP.CPP", 668, 0);
    return 1;
}

#pragma pack(push, 1)
struct D2TargaHeaderStrc
{
    unsigned char nIdLength;
    unsigned char nColorMapType;
    unsigned char nImageType;
    unsigned short nColorMapFirst;
    unsigned short nColorMapLength;
    unsigned char nColorMapDepth;
    unsigned short nOriginXY[2];
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned char nPixelDepth;
    unsigned char nAttributeBits : 4;
    unsigned char nOrigin : 2;
    unsigned char nInterleave : 2;
};
#pragma pack(pop)

struct D2TgaSourceColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nReserved;
};

static __declspec(noinline) int __stdcall sub_006C5830_WriteTga(void* hFile, const unsigned char* pPixels, const D2TgaSourceColorStrc* pPalette, int nWidth, int nHeight, int nPixelDepth, int nPitch);

// 0x006C5830
static int __stdcall sub_006C5830_WriteTga(void* hFile, const unsigned char* pPixels, const D2TgaSourceColorStrc* pPalette, int nWidth, int nHeight, int nPixelDepth, int nPitch)
{
    unsigned int nWritten;
    D2TargaHeaderStrc header;
    unsigned char colorMap[256][3];

    header.nIdLength = 0;
    if (nPixelDepth == 8)
    {
        header.nColorMapType = 1;
        header.nImageType = 1;
        header.nColorMapFirst = 0;
        header.nColorMapLength = 256;
        header.nColorMapDepth = 24;
    }
    else
    {
        header.nColorMapType = 0;
        header.nImageType = 2;
        header.nColorMapFirst = 0;
        header.nColorMapLength = 0;
        header.nColorMapDepth = 0;
    }
    header.nOriginXY[0] = 0;
    header.nOriginXY[1] = 0;
    header.nWidth = (unsigned short)nWidth;
    header.nHeight = (unsigned short)nHeight;
    header.nPixelDepth = (unsigned char)nPixelDepth;
    header.nAttributeBits = nPixelDepth == 32 ? 8 : 0;
    header.nOrigin = 2;
    header.nInterleave = 0;
    WriteFile(hFile, &header, sizeof(header), &nWritten, 0);

    if (nPixelDepth == 8)
    {
        for (int i = 0; i < 256; ++i)
        {
            colorMap[i][0] = pPalette[i].nBlue;
            colorMap[i][1] = pPalette[i].nGreen;
            colorMap[i][2] = pPalette[i].nRed;
        }
        WriteFile(hFile, colorMap, sizeof(colorMap), &nWritten, 0);
    }

    int nRowBytes = ((nPixelDepth + 7) / 8) * nWidth;
    if (nPitch == nRowBytes)
    {
        WriteFile(hFile, pPixels, nRowBytes * nHeight, &nWritten, 0);
    }
    else
    {
        const unsigned char* pSrc = pPixels;
        for (; nHeight; --nHeight)
        {
            WriteFile(hFile, pSrc, nRowBytes, &nWritten, 0);
            pSrc += nPitch;
        }
    }
    return 1;
}

// 0x006C6CB0
int __stdcall sub_006C6CB0_SaveImage(char* szFile, unsigned char* pPalette, unsigned char* pPixels, int nWidth, int nHeight, int nBits, int nPitch)
{
    VALIDATEBEGIN;
    VALIDATE(szFile);
    __assume(szFile != 0);
    VALIDATE(*szFile);
    __assume(*szFile != 0);
    VALIDATE(nBits != 8 || pPalette);
    __assume(nBits != 8 || pPalette != 0);
    VALIDATE(pPixels);
    __assume(pPixels != 0);
    VALIDATE(nWidth > 0);
    __assume(nWidth > 0);
    VALIDATE(nHeight > 0);
    __assume(nHeight > 0);
    VALIDATEEND;

    const char* pExtension = sub_006C5EE0_FindExtension(szFile);
    if (pExtension && !_stricmp(pExtension, gszTga_006FCC7C))
    {
        if (nBits != 8 && nBits != 24 && nBits != 32)
        {
            return 0;
        }
    }
    else if (nBits != 8)
    {
        return 0;
    }

    if (!nPitch)
    {
        nPitch = (nBits + 7) / 8 * nWidth;
    }

    void* hFile = CreateFileA(szFile, 0x40000000, 0, 0, 2, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return 0;
    }

    if (pExtension)
    {
        if (!_stricmp(pExtension, gszPcx_006FCC74))
        {
            const int nResult = sub_006C5B60_WritePcx(nHeight, nWidth, hFile, pPalette, pPixels);
            CloseHandle(hFile);
            return nResult;
        }

        if (!_stricmp(pExtension, gszGif_006FCC6C))
        {
            const int nResult = sub_006C6620_SaveGif(hFile, (const RGBQuad*)pPalette, pPixels, nWidth, nHeight);
            CloseHandle(hFile);
            return nResult;
        }

        if (!_stricmp(pExtension, gszTga_006FCC7C))
        {
            const int nResult = sub_006C5830_WriteTga(hFile, pPixels, (const D2TgaSourceColorStrc*)pPalette, nWidth, nHeight, nBits, nPitch);
            CloseHandle(hFile);
            return nResult;
        }
    }

    const int nResult = sub_006C61C0_WriteBmp(hFile, (const D2PaletteEntry*)pPalette, pPixels, nWidth, nHeight);
    CloseHandle(hFile);
    return nResult;
}

#include "gen/data/Source/Storm/SOURCE/SBMP_006C6CB0.inc"
