#include "Storm.h"

typedef void* HANDLE;
struct RGBQuad { unsigned char r, g, b, a; };
extern "C" __declspec(dllimport) int __stdcall WriteFile(HANDLE, const void*, unsigned long, unsigned long*, void*); // 0x006CC1A8
void* __stdcall SMemAlloc(unsigned int, const char*, int, int); // 0x00413020
void __stdcall SMemFree(void*, const char*, int, int); // 0x00412650
int __fastcall CompressGifImage(int nCount, const unsigned char* pPixels, unsigned char* pOut); // 0x006C6470

struct RGBTriple { unsigned char r, g, b; };

static __forceinline int SBmpWrite(HANDLE hFile, const void* pData, unsigned long nBytes)
{
    unsigned long written;
    return WriteFile(hFile, pData, nBytes, &written, 0);
}

static __declspec(noinline) int __stdcall EncodeGif256File(HANDLE hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight);

// 0x006C6620
static int __stdcall EncodeGif256File(HANDLE hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight)
{
    unsigned char header[13];
    unsigned char marker;
    RGBTriple palette[256];
    unsigned long written;

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

    unsigned char* pData = (unsigned char*)SMemAlloc(nWidth * nHeight * 2, gszSBmpSource, 1000, 0);
    int nLength = CompressGifImage(nWidth * nHeight, pPixels, pData);
    WriteFile(hFile, pData, nLength, &written, 0);
    SMemFree(pData, gszSBmpSource, 1006, 0);

    marker = 0;
    SBmpWrite(hFile, &marker, 1);
    marker = ';';
    SBmpWrite(hFile, &marker, 1);
    return 1;
}

int __stdcall sub_Emit_006C6620(HANDLE hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight)
{
    return EncodeGif256File(hFile, pPalette, pPixels, nWidth, nHeight);
}
