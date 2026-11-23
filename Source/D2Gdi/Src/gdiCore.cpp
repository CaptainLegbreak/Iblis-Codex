#include "D2Gdi.h"
#include "D2SysTypes.h"
#include "D2Win32Base.h"
#include "D2GfxTypes.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern void* gpArg1_007C9148; // 0x007C9148

extern void* gpArg2_007C914C; // 0x007C914C

extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2Callbacks006C7CF0Strc;

struct D2CriticalSectionStrc;

struct D2RgbQuadStrc;

struct D2RgbQuad006C7FA0Strc;

struct D2Callbacks006C7CF0Strc
{
    void (__fastcall* pfnCallback00)(int a, int b, int c, int d);
};

extern void* ghObject_0098A164; // 0x0098A164

extern D2Callbacks006C7CF0Strc* gpCallbacks_007C914C; // 0x007C914C

void __fastcall sub_006C9280_Apply(int enabled, unsigned char unusedRegister, int unusedA, int unusedB); // 0x006C9280

struct D2RgbQuadStrc { unsigned char nBlue, nGreen, nRed, nReserved; };

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);

extern "C" __declspec(dllimport) unsigned int __stdcall SetDIBColorTable(void* hDC, unsigned int nStart, unsigned int nCount, const D2RgbQuadStrc* pColors);

extern "C" __declspec(dllimport) void* __stdcall SelectPalette(void* hDC, void* hPalette, int bForceBackground);

extern "C" __declspec(dllimport) unsigned int __stdcall RealizePalette(void* hDC);

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* pRect);

extern "C" __declspec(dllimport) int __stdcall StretchBlt(void* hDest, int nX, int nY, int nWidth, int nHeight, void* hSrc, int nSrcX, int nSrcY, int nSrcWidth, int nSrcHeight, unsigned long nRop);

extern "C" __declspec(dllimport) int __stdcall GdiFlush();

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);

void* __stdcall WINDOW_GetWindow(); // 0x004F59A0

extern int gnRenderHeight; // 0x007C913C

extern D2RgbQuadStrc gaPalette_00989C40[256]; // 0x00989C40

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const char gszEmptyAssertText; // 0x006CC837

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd); // 0x006CC44C

extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC); // 0x006CC448

static void GDI_CreateBackBuffer(int nResolution); // 0x006C7B00

extern "C" __declspec(dllimport) void* __stdcall CreatePalette(const D2LogPalette006C7C10Strc* pLogPalette);

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho);

extern D2PaletteEntry006C7C10Strc gaPalette_007C8CC8[256]; // 0x007C8CC8

void* gpSurfaceBits; // 0x007C9154

void* ghBufferBitmap; // 0x0098A164

void* ghPalette; // 0x0098A160

void __cdecl sub_006C8960_DeleteGraphicObject();                                                                    // 0x006C8960

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern int gnValue_007C9144;                                                                                        // 0x007C9144

extern "C" __declspec(dllimport) unsigned int __stdcall SetPaletteEntries(void* hPalette, unsigned int nStart, unsigned int nEntries, const D2PaletteEntry006C7C10Strc* pEntries);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern D2RgbQuad006C7FA0Strc gatGdiColors[256];                                                                // 0x00989C40

extern void* ghRenderWindow; // 0x007C9140

extern D2PaletteTableStrc gtPaletteView; // 0x0098A040

void __fastcall sub_006C8000_SetPaletteView(const D2PaletteTableStrc* source); // 0x006C8000

void __cdecl sub_006C8030_Nop(); // 0x006C8030

void __cdecl sub_006C8040_Nop(); // 0x006C8040

void __cdecl sub_006C8070_Nop(); // 0x006C8070

void __stdcall sub_006C8080_Nop(int unused1, int unused2, int unused3); // 0x006C8080

void __stdcall sub_006C8090_Nop(int unused1, int unused2, int unused3, int unused4); // 0x006C8090

void __cdecl sub_006C80A0_Nop(); // 0x006C80A0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


extern D2RgbQuadStrc gPaletteEntries_00989C40[256]; // 0x00989C40

extern int gnValue_007C913C; // 0x007C913C

extern int gnValue_007C9138; // 0x007C9138

// 0x006C7A70
int __fastcall GDI_Init(void* pArg1, void* pArg2)
{
    gpArg1_007C9148 = pArg1;
    gpArg2_007C914C = pArg2;
    gpLock_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\gdiCore.cpp", 0x4B, 0);
    InitializeCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7AB0
int __cdecl GDI_Close()
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

// 0x006C7B00
static void GDI_CreateBackBuffer(int nResolution)
{
    D2_ASSERT(!gpSurfaceBits, 111);

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
    ghBufferBitmap = CreateDIBSection(hDC, &tBitmapInfo, 0, &gpSurfaceBits, 0, 0);
    ReleaseDC(0, hDC);

    gpBufferFuncs_007C914C->pfnSetBuffer(gpSurfaceBits, gnBufferWidth_007C9138, gnBufferHeight_007C913C, 0);
}

// 0x006C7C10
int __fastcall GDI_CreateSurface(int nValue, int nArg)
{
    gnValue_007C9140 = nValue;
    GDI_CreateBackBuffer(nArg);
    memset(gaPalette_007C8CC8, 0, sizeof(gaPalette_007C8CC8));
    D2LogPalette006C7C10Strc tLogPalette;
    tLogPalette.palVersion = 0x300;
    tLogPalette.palNumEntries = 0x100;
    memset(tLogPalette.palPalEntry, 0, sizeof(tLogPalette.palPalEntry));
    ghPalette = CreatePalette(&tLogPalette);
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

// 0x006C7CF0
int __cdecl GDI_CloseSurface()
{
    sub_006C8960_DeleteGraphicObject();
    DeleteObject(ghBufferBitmap);
    gpSurfaceBits = 0;
    gpBufferFuncs_007C914C->pfnSetBuffer(0, 0, 0, 0);
    return 1;
}

// 0x006C7D30
void __stdcall GDI_PauseSurface(int nValue)
{
    D2_ASSERT(gpLock_007C9134, 0xF9);
    EnterCriticalSection(gpLock_007C9134);
    gnValue_007C9144 = nValue;
    LeaveCriticalSection(gpLock_007C9134);
}

// 0x006C7D80
int __fastcall sub_006C7D80_LockAndSend(void* pObject, char nKey, int a, int b)
{
    if (gnValue_007C9144)
    {
        return 0;
    }
    D2_ASSERT(gpLock_007C9134, 0x10D);
    EnterCriticalSection(gpLock_007C9134);
    if (pObject)
    {
        sub_006C9280_Apply(1, nKey, a, b);
    }
    return 1;
}

// 0x006C7DF0
int __cdecl GDI_EndDraw()
{
    D2_ASSERT(gpLock_007C9134, 0x11D);
    LeaveCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7E30
int __cdecl sub_006C7E30_BlitWindow()
{
    void* hDC = GetDC(ghRenderWindow);
    void* hMemoryDC = CreateCompatibleDC(hDC);
    SelectObject(hMemoryDC, ghObject_0098A164);
    SetDIBColorTable(hMemoryDC, 0, 256, gaPalette_00989C40);
    SelectPalette(hDC, ghPalette, 0);
    RealizePalette(hDC);
    tagRECT tRect;
    GetClientRect(WINDOW_GetWindow(), &tRect);
    StretchBlt(hDC, 0, 0, tRect.right - tRect.left, tRect.bottom - tRect.top,
// build: symbol ?gnRenderWidth@* 0x007C9138
        hMemoryDC, 0, 0, gnRenderWidth, gnRenderHeight, 0xCC0020);
    GdiFlush();
    DeleteDC(hMemoryDC);
    ReleaseDC(ghRenderWindow, hDC);
    return 1;
}

// 0x006C7F90
void __fastcall sub_006C7F90_GetScreenSize(int* width, int* height)
{
    *width = gnRenderWidth;
    *height = gnRenderHeight;
}

// 0x006C7FA0
void __fastcall GDI_SetPalette(D2PaletteEntry006C7C10Strc* pEntries)
{
    for (int i = 0; i < 256; ++i)
    {
        gatGdiColors[i].rgbRed = pEntries[i].peRed;
        gatGdiColors[i].rgbGreen = pEntries[i].peGreen;
        gatGdiColors[i].rgbBlue = pEntries[i].peBlue;
    }
    SetPaletteEntries(ghPalette, 0, 256, pEntries);
    memcpy(gaPalette_007C8CC8, pEntries, sizeof(gaPalette_007C8CC8));
}

// 0x006C80B0
int __fastcall GDI_ChangeRes(int nUnused, int nMode)
{
    DeleteObject(ghBufferBitmap);
    gpSurfaceBits = 0;
    gpBufferFuncs_007C914C->pfnSetBuffer(0, 0, 0, 0);
    GDI_CreateBackBuffer(nMode);
    sub_006C82D0_Apply(nMode);
    return 1;
}

// 0x006C81A0
void __fastcall sub_006C81A0_RENDERER_WINDOWED_GetPalette(void** phPalette, D2RgbQuadStrc** ppEntries)
{
    D2_ASSERT(phPalette, 546);
    D2_ASSERT(ppEntries, 547);
    *phPalette = ghPalette;
    *ppEntries = gPaletteEntries_00989C40;
}

// 0x006C81E0
void __fastcall sub_006C81E0_GetValues(int* pA, int* pB, int* pC)
{
    D2_ASSERT(pA, 0x230);
    D2_ASSERT(pB, 0x231);
    D2_ASSERT(pC, 0x232);
    *pA = gnValue_007C9154;
    *pB = gnValue_007C913C;
    *pC = gnValue_007C9138;
}
