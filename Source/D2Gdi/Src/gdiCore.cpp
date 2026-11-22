#include "D2Gdi.h"
#include "D2SysTypes.h"


extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern void* gpArg1_007C9148; // 0x007C9148
extern void* gpArg2_007C914C; // 0x007C914C
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);

// 0x006C7A70
int __fastcall sub_006C7A70_Init(void* pArg1, void* pArg2)
{
    gpArg1_007C9148 = pArg1;
    gpArg2_007C914C = pArg2;
    gpLock_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\gdiCore.cpp", 0x4B, 0);
    InitializeCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7AB0
int __cdecl sub_006C7AB0_Free()
{
    if (gpLock_007C9134)
    {
        DeleteCriticalSection(gpLock_007C9134);
        FOG_Free(gpLock_007C9134, ".\\Src\\gdiCore.cpp", 0x59, 0);
        gpLock_007C9134 = 0;
    }
    return 1;
}

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

struct D2RgbQuad006C7FA0Strc
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

void __cdecl sub_006C8960_DeleteGraphicObject();                                                                    // 0x006C8960
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern int gnValue_007C9144;                                                                                        // 0x007C9144
extern "C" __declspec(dllimport) unsigned int __stdcall SetPaletteEntries(void* hPalette, unsigned int nStart, unsigned int nEntries, const D2PaletteEntry006C7C10Strc* pEntries);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern D2RgbQuad006C7FA0Strc gaColors_00989C40[256];                                                                // 0x00989C40

// 0x006C7CF0
int __cdecl sub_006C7CF0_Close()
{
    sub_006C8960_DeleteGraphicObject();
    DeleteObject(ghBufferBitmap_0098A164);
    gpBufferBits_007C9154 = 0;
    gpBufferFuncs_007C914C->pfnSetBuffer(0, 0, 0, 0);
    return 1;
}

// 0x006C7D30
void __stdcall sub_006C7D30_SetValue(int nValue)
{
    D2_ASSERT(gpLock_007C9134, 0xF9);
    EnterCriticalSection(gpLock_007C9134);
    gnValue_007C9144 = nValue;
    LeaveCriticalSection(gpLock_007C9134);
}

// 0x006C7DF0
int __cdecl sub_006C7DF0_Unlock()
{
    D2_ASSERT(gpLock_007C9134, 0x11D);
    LeaveCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7FA0
void __fastcall sub_006C7FA0_SetPalette(D2PaletteEntry006C7C10Strc* pEntries)
{
    for (int i = 0; i < 256; ++i)
    {
        gaColors_00989C40[i].rgbRed = pEntries[i].peRed;
        gaColors_00989C40[i].rgbGreen = pEntries[i].peGreen;
        gaColors_00989C40[i].rgbBlue = pEntries[i].peBlue;
    }
    SetPaletteEntries(ghPalette_0098A160, 0, 256, pEntries);
    memcpy(gaPalette_007C8CC8, pEntries, sizeof(gaPalette_007C8CC8));
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
