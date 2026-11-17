#include "Storm.h"

#define D2_GUARD_BEGIN do { int d2Guard_ = -1
#define D2_CHECK(c) d2Guard_ &= (c) ? -1 : 0
#define D2_GUARD_END(fail, r) if (!d2Guard_) { fail; return r; } } while (0)
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2TargaHeaderStrc;
struct D2TgaSourceColorStrc;
struct D2PaletteColorStrc;

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nBytes, unsigned long* pWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
char* __stdcall SStrChr(const char*, int); // 0x00413490
extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9
int __fastcall sub_006C5B60_WritePcx(int nHeight, int nWidth, void* hFile, unsigned char* pPalette, unsigned char* pPixels); // 0x006C5B60
int __stdcall sub_006C6620_WriteGif(int nWidth, void* hFile, unsigned char* pPalette, unsigned char* pPixels, int nHeight); // 0x006C6620
int __stdcall sub_006C61C0_WriteBmp(unsigned char* pPalette, void* hFile, unsigned char* pPixels, int nHeight); // 0x006C61C0
extern const char gszTga_006FCC7C[]; // 0x006FCC7C
extern const char gszPcx_006FCC74[]; // 0x006FCC74
extern const char gszGif_006FCC6C[]; // 0x006FCC6C

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

static __declspec(noinline) char* sub_006C5EE0_FindExtension(char* path);
static __declspec(noinline) int __stdcall sub_006C5830_WriteTga(void* hFile, const unsigned char* pPixels, const D2TgaSourceColorStrc* pPalette, int nWidth, int nHeight, int nPixelDepth, int nPitch);
int __stdcall sub_006C6CB0_SaveImage(char* szFile, unsigned char* pPalette, unsigned char* pPixels, int nWidth, int nHeight, int nBits, int nPitch); // 0x006C6CB0

struct D2PaletteColorStrc { unsigned char red, green, blue, alpha; };

typedef void* (__stdcall* SBMPALLOCPROC)(unsigned int nSize);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
unsigned int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370
int __stdcall sub_004198D0(void* pArg); // 0x004198D0
int __stdcall sub_00419980(const char* szFileName, void** phFile); // 0x00419980
int __stdcall SFileReadFile(void* hFile, void* pBuffer, unsigned int nToRead, unsigned int* pnRead, void* pOverlapped); // 0x0041B050
int __stdcall sub_006C6A80_DecodeImage(int nType, const unsigned char* pData, unsigned int nDataSize, D2PaletteColorStrc* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth); // 0x006C6A80

// 0x006C5EE0
static char* sub_006C5EE0_FindExtension(char* path)
{
    char* cursor = path;
    while (SStrChr(cursor, '\\'))
        cursor = SStrChr(cursor, '\\') + 1;
    path = cursor + 1;
    while (SStrChr(path, '.'))
    {
        cursor = SStrChr(path, '.');
        path = cursor + 1;
    }
    return cursor;
}

// 0x006C5830
static int __stdcall sub_006C5830_WriteTga(void* hFile, const unsigned char* pPixels, const D2TgaSourceColorStrc* pPalette, int nWidth, int nHeight, int nPixelDepth, int nPitch)
{
    unsigned long nWritten;
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

// build: context sub_006C6CB0_SaveImage
int __stdcall sub_006C6CB0_SaveImage(char* szFile, unsigned char* pPalette, unsigned char* pPixels, int nWidth, int nHeight, int nBits, int nPitch)
{
    D2_GUARD_BEGIN;
    D2_CHECK(szFile);
    D2_CHECK(*szFile);
    D2_CHECK(nBits != 8 || pPalette);
    D2_CHECK(pPixels);
    D2_CHECK(nWidth > 0);
    D2_CHECK(nHeight > 0);
    D2_GUARD_END(SErrSetLastError(0x57), 0);

    char* pExtension = sub_006C5EE0_FindExtension(szFile);
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
            const int nResult = sub_006C6620_WriteGif(nWidth, hFile, pPalette, pPixels, nHeight);
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

    const int nResult = sub_006C61C0_WriteBmp(pPalette, hFile, pPixels, nHeight);
    CloseHandle(hFile);
    return nResult;
}

// 0x006C6E70
int __stdcall SBmpAllocLoadImage(const char* szFileName, D2PaletteColorStrc* pPalette, unsigned char** ppBuffer, int* pWidth, int* pHeight, int* pBitDepth, int nRequestedBitDepth, SBMPALLOCPROC pfAlloc)
{
    if (ppBuffer)
        *ppBuffer = 0;
    if (pWidth)
        *pWidth = 0;
    if (pHeight)
        *pHeight = 0;
    if (pBitDepth)
        *pBitDepth = 0;

    VALIDATEBEGIN;
    VALIDATE(szFileName);
    __assume((szFileName) != 0);
    VALIDATE(*szFileName);
    __assume((*szFileName) != 0);
    VALIDATE(ppBuffer);
    __assume((ppBuffer) != 0);
    VALIDATEEND;

    void* hFile;
    if (!nValid || !sub_00419980(szFileName, &hFile))
        return 0;

    unsigned int nFileSize = sub_00416370_StormGetFileSize(hFile, 0);
    unsigned char* pFileData = (unsigned char*)SMemAlloc(nFileSize, gszSBmpSource, 0x5B6, 0);
    SFileReadFile(hFile, pFileData, nFileSize, 0, 0);
    sub_004198D0(hFile);

    int bResult = 0;
    int nWidth;
    int nHeight;
    int nBitDepth;
    if (sub_006C6A80_DecodeImage(0, pFileData, nFileSize, 0, 0, 0, &nWidth, &nHeight, &nBitDepth))
    {
        if (!nRequestedBitDepth)
            nRequestedBitDepth = nBitDepth;
        else if (nRequestedBitDepth != nBitDepth)
            goto done;

        int nBufferSize = nWidth * nHeight * nRequestedBitDepth / 8;
        if (pfAlloc)
            *ppBuffer = (unsigned char*)pfAlloc(nBufferSize);
        else
            *ppBuffer = (unsigned char*)SMemAlloc(nBufferSize, szFileName, -4, 0);

        if (*ppBuffer)
        {
            sub_006C6A80_DecodeImage(0, pFileData, nFileSize, pPalette, *ppBuffer, nBufferSize, 0, 0, 0);
            if (pWidth)
                *pWidth = nWidth;
            if (pHeight)
                *pHeight = nHeight;
            if (pBitDepth)
                *pBitDepth = nRequestedBitDepth;
            bResult = 1;
        }
    }

done:
    SMemFree(pFileData, gszSBmpSource, 0x5F3, 0);
    return bResult;
}
