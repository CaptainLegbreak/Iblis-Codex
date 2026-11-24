#include "D2Gdi.h"

#include "D2SysTypes.h"

#include "D2Win32Base.h"

#include "D2GfxTypes.h"
#include "D2CelContext.h"

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

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

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

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2RgbQuadStrc gPaletteEntries_00989C40[256]; // 0x00989C40

extern int gnValue_007C913C; // 0x007C913C

extern int gnValue_007C9138; // 0x007C9138

struct D2CelStrc;

int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

int __stdcall CelGetOffsetX(D2CelStrc* pCel);                                                               // 0x00601920

int __stdcall CelGetOffsetY(D2CelStrc* pCel);                                                               // 0x00601950

int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250

extern D2PaletteTableStrc* gpGfxPaletteView;                                                               // 0x007C9150

void __stdcall CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, int nOriginX, int nModeWidth, unsigned char* pBuffer, int nHeight, int nWidth, int nArg9, unsigned char* pCaps, int nSkipTop, int nDrawHeight, int nArg13); // 0x00601650

void __stdcall CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, unsigned char* pShadowTable, int nArg10); // 0x00601730

int __cdecl sub_006C8A50_GetBlendedShadows(); // 0x006C8A50

struct D2ClipRect006C8750Strc
{
    int nX1;
    int nX2;
    int nY1;
    int nY2;
};

struct D2CelFileStrc;

struct D2CelContext006C8750Strc
{
    unsigned char unk_00[0x3C];
    D2CelFileStrc* pCelFile;
};

int __stdcall sub_006001F0_Prepare(D2CelContext006C8750Strc* pContext, int a2, int a3); // 0x006001F0

int __fastcall sub_006C8250_GetSetting(int nArg, D2ClipRect006C8750Strc** ppClip, int nY1, int nY2, int nFlags); // 0x006C8250

void __stdcall D2CMP_CelDrawEx(D2CelContext006C8750Strc* pContext, int nX, int nY, int nX1, int nX2, int a6, int a7, int a8, int a9, int a10); // 0x00601650

int __stdcall CelGetWidth(D2CelFileStrc* pCelFile); // 0x006018C0

int __stdcall CelGetHeight(D2CelFileStrc* pCelFile); // 0x006018F0

int __stdcall CelGetOffsetX(D2CelFileStrc* pCelFile); // 0x00601920

int __stdcall CelGetOffsetY(D2CelFileStrc* pCelFile); // 0x00601950

extern const char gszAssertExpr_006CC837[]; // 0x006CC837

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

static int __stdcall sub_006C8380_Clip(D2CelFileStrc* pCelFile, int nY, D2ClipRect006C8750Strc* pClip, int nX, D2ClipRect006C8750Strc* pOut);

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

// 0x006C7AF0
void __cdecl sub_006C7AF0_Nop()
{
}

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

static inline int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

// 0x006C84B0
int __fastcall sub_006C84B0_Draw(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    const int nGamma = (unsigned char)dwGamma;
    unsigned char* pGammaTable = 0;
    const int nCaps = sub_006C8250_GetSetting(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpGfxPaletteView->pShadowLightGammaPalettes[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpGfxPaletteView->pRemap;

    CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}

int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue)
{
// build: symbol ?gaSelectorValues@* 0x0074C5A0
    *pValue = gaSelectorValues[nSelector];
    switch (nSelector)
    {
    case 0:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[2];
    case 1:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[1];
    case 2:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[0];
    case 3:
        return (int)gpGfxPaletteView_007C9150->pScreenPalette;
    case 4:
        return (int)gpGfxPaletteView_007C9150->pLuminancePalette;
    case 6:
        return (int)gpGfxPaletteView_007C9150->pDarkBlendPalette;
    }
    return 0;
}

// 0x006C86A0
void __fastcall sub_006C86A0_DrawImageRows(D2CelContextStrc* pContext, int nX, int nY, int nSkipTop, int nDrawHeight, int nDrawMode)
{
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return;

    CelDrawEx(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C, gpScreenBuffer_007C9154,
        gnRenderHeight, gnRenderWidth, 0, (unsigned char*)sub_006C8250_GetSetting(nDrawMode, &nDrawHeight),
        nSkipTop, nDrawHeight, 0);
}

// 0x006C87E0
void __fastcall sub_006C87E0_DrawShadow(void* pData, int nX, int nY)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    unsigned char* pShadowTable = 0;
    if (sub_006C8A50_GetBlendedShadows())
        pShadowTable = gpGfxPaletteView_007C9150->pTransPalettes[0];

    CelDrawShadow(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, pShadowTable, 0);
}

static int __stdcall sub_006C8380_Clip(D2CelFileStrc* pCelFile, int nY, D2ClipRect006C8750Strc* pClip, int nX, D2ClipRect006C8750Strc* pOut)
{
    const int nWidth = CelGetWidth(pCelFile);
    const int nHeight = CelGetHeight(pCelFile);

    const int nX1 = D2_MAX(pClip->nX1, 0);
    const int nX2 = D2_MIN(pClip->nX2, gnValue_007C9138);
    if (nX1 > nX2)
    {
        return 1;
    }

    nX += CelGetOffsetX(pCelFile);
    if (nX >= nX2 || nWidth + nX < nX1)
    {
        return 1;
    }

    int nY1 = D2_MAX(pClip->nY1, 0);
    int nY2 = pClip->nY2;
    nY2 = D2_MIN(nY2, gnValue_007C913C);
    if (nY1 > nY2)
    {
        return 1;
    }

    nY += CelGetOffsetY(pCelFile);
    if (nY < nY1 || nY - nHeight > nY2)
    {
        return 1;
    }

    pOut->nX1 = nX1;
    pOut->nX2 = nX2;
    if (nY <= nY2)
    {
        pOut->nY1 = 0;
    }
    else
    {
        pOut->nY1 = nY - nY2 - 1;
    }

    if (nY - nHeight >= nY1)
    {
        pOut->nY2 = nHeight - pOut->nY1;
    }
    else
    {
        pOut->nY2 = nY - pOut->nY1 - nY1 + 1;
    }

    if (pOut->nY2 <= 0)
    {
        FOG_DisplayHalt(gszAssertExpr_006CC837, sub_00408090(), 209);
        exit(-1);
    }
    return 0;
}

// 0x006C8750
void __fastcall sub_006C8750_DrawCel(D2CelContext006C8750Strc* pContext, int nX, int nY, D2ClipRect006C8750Strc* pClip, int nC)
{
    D2ClipRect006C8750Strc tRect = {};
    if (!sub_006001F0_Prepare(pContext, 0, 1))
    {
        return;
    }

    if (sub_006C8380_Clip(pContext->pCelFile, nY, pClip, nX, &tRect))
    {
        return;
    }

    D2CMP_CelDrawEx(pContext, nX, nY, tRect.nX1, tRect.nX2, gnValue_007C9154, gnValue_007C913C, gnValue_007C9138, 0,
        sub_006C8250_GetSetting(nC, &pClip, tRect.nY1, tRect.nY2, 0));
}
