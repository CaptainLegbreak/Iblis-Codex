#include "D2Gdi.h"
struct D2PaletteEntry006C7C10Strc;
struct D2LogPalette006C7C10Strc;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszEmptyAssertText; // 0x006CC837
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd); // 0x006CC44C
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC); // 0x006CC448
static void sub_006C7B00_CreateBackBuffer(int nResolution);

extern "C" __declspec(dllimport) void* __stdcall CreatePalette(const D2LogPalette006C7C10Strc* pLogPalette);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho);
extern D2PaletteEntry006C7C10Strc gaPalette_007C8CC8[256]; // 0x007C8CC8

void* gpBufferBits_007C9154; // 0x007C9154

void* ghBufferBitmap_0098A164; // 0x0098A164

// 0x006C7B00
static void sub_006C7B00_CreateBackBuffer(int nResolution)
{
    D2_ASSERT(!gpBufferBits_007C9154, 111);

    int nWidth;
    int nHeight;
    switch (nResolution)
    {
    case 0:
        nWidth = 640;
        nHeight = 480;
        break;

    case 3:
        nWidth = 1344;
        nHeight = 700;
        break;

    default:
        nWidth = 800;
        nHeight = 600;
        break;
    }

    gnBufferWidth_007C9138 = nWidth;
    gnBufferHeight_007C913C = nHeight;

    D2BitmapInfoStrc tBitmapInfo;
    memset(&tBitmapInfo, 0, sizeof(tBitmapInfo));
    tBitmapInfo.biSize = 40;
    tBitmapInfo.biWidth = nWidth;
    tBitmapInfo.biHeight = -nHeight;
    tBitmapInfo.biPlanes = 1;
    tBitmapInfo.biBitCount = 8;
    tBitmapInfo.biCompression = 0;

    void* hDC = GetDC(0);
    ghBufferBitmap_0098A164 = CreateDIBSection(hDC, &tBitmapInfo, 0, &gpBufferBits_007C9154, 0, 0);
    ReleaseDC(0, hDC);

    gpBufferFuncs_007C914C->pfnSetBuffer(gpBufferBits_007C9154, gnBufferWidth_007C9138, gnBufferHeight_007C913C, 0);
}

void __cdecl sub_Emit_006C7B00(int nResolution)
{
    sub_006C7B00_CreateBackBuffer(nResolution);
}

void* ghPalette_0098A160; // 0x0098A160

// 0x006C7C10
int __fastcall sub_006C7C10_InitPalette(int nValue, int nArg)
{
    gnValue_007C9140 = nValue;
    sub_006C7B00_CreateBackBuffer(nArg);
    memset(gaPalette_007C8CC8, 0, sizeof(gaPalette_007C8CC8));
    D2LogPalette006C7C10Strc tLogPalette;
    tLogPalette.palVersion = 0x300;
    tLogPalette.palNumEntries = 0x100;
    memset(tLogPalette.palPalEntry, 0, sizeof(tLogPalette.palPalEntry));
    ghPalette_0098A160 = CreatePalette(&tLogPalette);
    sub_006C8930_Init();
    sub_006C82D0_Apply(nArg);
    return 1;
}

// 0x006C80B0
int __fastcall sub_006C80B0_ResetSurface(int nUnused, int nMode)
{
    DeleteObject(ghBufferBitmap_0098A164);
    gpBufferBits_007C9154 = 0;
    gpBufferFuncs_007C914C->pfnSetBuffer(0, 0, 0, 0);
    sub_006C7B00_CreateBackBuffer(nMode);
    sub_006C82D0_Apply(nMode);
    return 1;
}
