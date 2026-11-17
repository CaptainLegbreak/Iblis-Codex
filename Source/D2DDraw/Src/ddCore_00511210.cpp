#include "D2DDraw.h"

struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};
struct D2DDSurfaceDescStrc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    int lPitch;
    unsigned int dwBackBufferCount;
    unsigned int dwRefreshRate;
    unsigned int dwAlphaBitDepth;
    unsigned int dwReserved;
    void* lpSurface;
    unsigned int unk0x28[16];
    unsigned int dwCaps;
};
class D2DDrawPaletteClass;
class D2DDrawSurfaceClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface(D2DDrawSurfaceClass* pSurface);
    virtual long __stdcall AddOverlayDirtyRect(void* pRect);
    virtual long __stdcall Blt(void* pDestRect, D2DDrawSurfaceClass* pSrc, void* pSrcRect, unsigned long dwFlags, void* pFx);
    virtual long __stdcall BltBatch(void* pBatch, unsigned long dwCount, unsigned long dwFlags);
    virtual long __stdcall BltFast(unsigned long dwX, unsigned long dwY, D2DDrawSurfaceClass* pSrc, void* pSrcRect, unsigned long dwTrans);
    virtual long __stdcall DeleteAttachedSurface(unsigned long dwFlags, D2DDrawSurfaceClass* pSurface);
    virtual long __stdcall EnumAttachedSurfaces(void* pContext, void* pfCallback);
    virtual long __stdcall EnumOverlayZOrders(unsigned long dwFlags, void* pContext, void* pfCallback);
    virtual long __stdcall Flip(D2DDrawSurfaceClass* pTarget, unsigned long dwFlags);
    virtual long __stdcall GetAttachedSurface(unsigned int* pCaps, D2DDrawSurfaceClass** ppSurface);
    virtual long __stdcall GetBltStatus(unsigned long dwFlags);
    virtual long __stdcall GetCaps(unsigned int* pCaps);
    virtual long __stdcall GetClipper(void** ppClipper);
    virtual long __stdcall GetColorKey(unsigned long dwFlags, void* pColorKey);
    virtual long __stdcall GetDC(void** phDC);
    virtual long __stdcall GetFlipStatus(unsigned long dwFlags);
    virtual long __stdcall GetOverlayPosition(long* pX, long* pY);
    virtual long __stdcall GetPalette(D2DDrawPaletteClass** ppPalette);
    virtual long __stdcall GetPixelFormat(void* pPixelFormat);
    virtual long __stdcall GetSurfaceDesc(D2DDSurfaceDescStrc* pDesc);
    virtual long __stdcall Initialize(void* pDirectDraw, D2DDSurfaceDescStrc* pDesc);
    virtual long __stdcall IsLost();
    virtual long __stdcall Lock(void* pRect, D2DDSurfaceDescStrc* pDesc, unsigned long dwFlags, void* hEvent);
    virtual long __stdcall ReleaseDC(void* hDC);
    virtual long __stdcall Restore();
    virtual long __stdcall SetClipper(void* pClipper);
    virtual long __stdcall SetColorKey(unsigned long dwFlags, void* pColorKey);
    virtual long __stdcall SetOverlayPosition(long nX, long nY);
    virtual long __stdcall SetPalette(D2DDrawPaletteClass* pPalette);
};
class D2DirectDrawClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper(unsigned long dwFlags, void** ppClipper, void* pUnkOuter);
    virtual long __stdcall CreatePalette(unsigned int dwFlags, T004F51E0* pEntries, D2DDrawPaletteClass** ppPalette, void* pUnkOuter);
    virtual long __stdcall CreateSurface(D2DDSurfaceDescStrc* pDesc, D2DDrawSurfaceClass** ppSurface, void* pUnkOuter);
    virtual long __stdcall DuplicateSurface(D2DDrawSurfaceClass* pSurface, D2DDrawSurfaceClass** ppDuplicate);
    virtual long __stdcall EnumDisplayModes(unsigned long dwFlags, D2DDSurfaceDescStrc* pDesc, void* pContext, void* pfCallback);
    virtual long __stdcall EnumSurfaces(unsigned long dwFlags, D2DDSurfaceDescStrc* pDesc, void* pContext, void* pfCallback);
    virtual long __stdcall FlipToGDISurface();
    virtual long __stdcall GetCaps(void* pDriverCaps, void* pHelCaps);
    virtual long __stdcall GetDisplayMode(D2DDSurfaceDescStrc* pDesc);
    virtual long __stdcall GetFourCCCodes(unsigned long* pCount, unsigned long* pCodes);
    virtual long __stdcall GetGDISurface(D2DDrawSurfaceClass** ppSurface);
    virtual long __stdcall GetMonitorFrequency(unsigned long* pFrequency);
    virtual long __stdcall GetScanLine(unsigned long* pScanLine);
    virtual long __stdcall GetVerticalBlankStatus(int* pIsInVB);
    virtual long __stdcall Initialize(void* pGuid);
    virtual long __stdcall RestoreDisplayMode();
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned int dwFlags);
    virtual long __stdcall SetDisplayMode(unsigned int dwWidth, unsigned int dwHeight, unsigned int dwBpp);
};
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode);                                             // 0x00511DF0
void __cdecl sub_00511A80_DDrawReleaseSurfaces();                                                           // 0x00511A80
extern int gbDDrawReady_00881264;                                                                           // 0x00881264
extern int gbDDrawReady2_00881268;                                                                          // 0x00881268
extern int gaDDrawModeWidth_0072F7A8[4];                                                                    // 0x0072F7A8
extern int gaDDrawModeHeight_0072F7B8[4];                                                                   // 0x0072F7B8
int gnDDrawBackBuffers_00881294;                                                                            // 0x00881294
D2DirectDrawClass* gpDirectDraw_00881270;                                                                   // 0x00881270
D2DDrawSurfaceClass* gpDDrawSurface_00881278;                                                               // 0x00881278
extern D2DDrawSurfaceClass* gpDDrawBackSurface_0088127C;                                                    // 0x0088127C
extern D2DDrawSurfaceClass* gpDDrawSurface_00881280;                                                        // 0x00881280
extern D2DDrawPaletteClass* gpDDrawObject_00881290;                                                         // 0x00881290
extern T004F51E0 gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8
static int gnScreenWidth2_00881258;                                                                         // 0x00881258
static int gnScreenHeight2_00881254;                                                                        // 0x00881254

// 0x00511210
static int sub_00511210_DDrawOpenSurfaces(int nResolutionMode)
{
    D2_ASSERT(!gbDDrawReady_00881264, 0x142);
    if (!nResolutionMode)
    {
        gnScreenWidth_007C9138 = 640;
        gnScreenHeight_007C913C = 480;
    }
    else
    {
        gnScreenWidth_007C9138 = 800;
        gnScreenHeight_007C913C = 600;
    }
    sub_00511DF0_DDrawSetMode(nResolutionMode);
    gnScreenWidth2_00881258 = gaDDrawModeWidth_0072F7A8[nResolutionMode];
    gnScreenHeight2_00881254 = gaDDrawModeHeight_0072F7B8[nResolutionMode];

    long hResult = gpDirectDraw_00881270->SetCooperativeLevel(ghDDrawWindow_007C9140, 0x11);
    if (hResult && hResult != 0x88760245)
    {
        sub_005103B0("SetCooperativeLevel failed!", hResult);
        return 0;
    }

    D2_ASSERT(gpDirectDraw_00881270, 0x1DA);
    const char* szError;
    hResult = gpDirectDraw_00881270->SetDisplayMode(gnScreenWidth2_00881258, gnScreenHeight2_00881254, 8);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    D2DDSurfaceDescStrc desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x21;
    desc.dwCaps = 0x4218;
    gnDDrawBackBuffers_00881294 = desc.dwBackBufferCount = 2;
    if (gpDirectDraw_00881270->CreateSurface(&desc, &gpDDrawSurface_00881278, 0))
    {
        memset(&desc, 0, sizeof(desc));
        desc.dwSize = sizeof(desc);
        desc.dwFlags = 0x21;
        desc.dwCaps = 0x4218;
        gnDDrawBackBuffers_00881294 = desc.dwBackBufferCount = 1;
        if (gpDirectDraw_00881270->CreateSurface(&desc, &gpDDrawSurface_00881278, 0))
        {
            memset(&desc, 0, sizeof(desc));
            desc.dwSize = sizeof(desc);
            desc.dwFlags = 1;
            desc.dwCaps = 0x4200;
            gnDDrawBackBuffers_00881294 = 0;
            hResult = gpDirectDraw_00881270->CreateSurface(&desc, &gpDDrawSurface_00881278, 0);
            if (hResult)
            {
                szError = "CreateSurface (primary single buffered) failed!";
                goto fail;
            }
        }
    }

    if (gnDDrawBackBuffers_00881294)
    {
        unsigned int dwCaps = 4;
        hResult = gpDDrawSurface_00881278->GetAttachedSurface(&dwCaps, &gpDDrawBackSurface_0088127C);
        if (hResult)
        {
            szError = "GetAttachedSurface (backbuffer) failed!";
            goto fail;
        }
    }

    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    hResult = gpDDrawSurface_00881278->GetSurfaceDesc(&desc);
    if (hResult)
    {
        szError = "GetSurfaceDesc (primary) failed!";
        goto fail;
    }

    desc.dwFlags = 7;
    desc.dwCaps = 0x840;
    hResult = gpDirectDraw_00881270->CreateSurface(&desc, &gpDDrawSurface_00881280, 0);
    if (hResult)
    {
        szError = "CreateSurface (render) failed!";
        goto fail;
    }

    hResult = gpDDrawSurface_00881278->SetPalette(gpDDrawObject_00881290);
    if (hResult)
    {
        szError = "SetPalette failed!";
        goto fail;
    }

    gbDDrawReady_00881264 = 1;
    gbDDrawReady2_00881268 = 0;
    return 1;

fail:
    sub_005103B0(szError, hResult);
    sub_00410610_WriteLogLine("Opening DirectDraw window failed!");
    return 0;
}

// 0x005115E0
int __fastcall sub_005115E0_DDrawRestoreSurface(void* hWnd, int nResolutionMode)
{
    ghDDrawWindow_007C9140 = hWnd;
    long hResult = gpDirectDraw_00881270->SetCooperativeLevel(hWnd, 0x11);
    if (hResult)
    {
        sub_005103B0("SetCooperativeLevel failed!", hResult);
        return 0;
    }
    memset(gaDDrawPalette_007C8CC8, 0, sizeof(gaDDrawPalette_007C8CC8));
    hResult = gpDirectDraw_00881270->CreatePalette(4, gaDDrawPalette_007C8CC8, &gpDDrawObject_00881290, 0);
    if (hResult)
    {
        sub_005103B0("CreatePalette failed!", hResult);
        return 0;
    }
    return sub_00511210_DDrawOpenSurfaces(nResolutionMode);
}

// 0x00511B60
int __fastcall sub_00511B60_DDrawChangeRes(void* hWnd, int nResolutionMode)
{
    if (!gbRenderPaused_007C9144)
    {
        sub_00511A80_DDrawReleaseSurfaces();
        return sub_00511210_DDrawOpenSurfaces(nResolutionMode);
    }
    return 1;
}

#include "gen/data/Source/D2DDraw/Src/ddCore_00511210.inc"
