#include "D2DDraw.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"

struct D2CriticalSectionStrc;

struct D2TileLibraryEntryStrc;

struct D2GfxLightExStrc;

class D2DDrawSurfaceClass;

class D2DDrawPaletteClass;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C

extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4

extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC

extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0

extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4

extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y); // 0x006CC0B8

extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho); // 0x006CC0D4

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534

extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink); // 0x006CC5BC

extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0

extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink); // 0x006CC5C4

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex); // 0x005093F0

void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0

void __fastcall sub_00509500_GlideSetCombine(int nMode); // 0x00509500

void __cdecl sub_0050BE20_GlideDebugRefresh(); // 0x0050BE20

void __fastcall sub_0050DBC0_GlideSetAmbientColor(int nRed, int nGreen, int nBlue); // 0x0050DBC0

void __cdecl sub_00511A80_DDrawReleaseSurfaces(); // 0x00511A80

int __fastcall sub_005115E0_DDrawRestoreSurface(void* hWnd, int nResolutionMode); // 0x005115E0

void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710

int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0

extern "C" const char gszCourier_006DD52C[]; // 0x006DD52C

extern unsigned long gdwDDrawDebugFontTextColor_0072F7F0; // 0x0072F7F0

extern int (__stdcall* gpfGlideLfbLock_0087EADC)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC

extern int (__stdcall* gpfGlideLfbUnlock_0087EAD8)(int nType, int nBuffer); // 0x0087EAD8

extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

extern void (__stdcall* gpfGlideTexDownloadTable_0087EB40)(int nType, void* pData); // 0x0087EB40

extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88

extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable); // 0x0087EB8C

extern unsigned int gaGlidePalette_0087EBA0[256]; // 0x0087EBA0

extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor); // 0x0087EFA0

extern int gbGlidePaletteTable_0087EFC8; // 0x0087EFC8

extern int gnGlideState_0087EFD8; // 0x0087EFD8

extern int gnGlideState_0087EFDC; // 0x0087EFDC

extern int gnGlideState_0087EFE0; // 0x0087EFE0

extern int gbGlideDrawing_0087EFE4; // 0x0087EFE4

extern unsigned int gnGlideBinkX_00880C08; // 0x00880C08

extern D2BinkStrc* gpGlideBink_00880C0C; // 0x00880C0C

extern int gbGlideBinkDone_00880C18; // 0x00880C18

D2DDrawSurfaceClass* gpDDrawSurface_00881278;                                                               // 0x00881278

D2DDrawPaletteClass* gpDDrawPalette_00881290;                                                                // 0x00881290

extern int gaDDrawDebugFontCharWidths_00881428[96]; // 0x00881428

extern unsigned char* gpDDrawDebugFontGlyphs_008815AC; // 0x008815AC

extern unsigned int gnDDrawBinkX_008816BC; // 0x008816BC

extern D2BinkStrc* gpDDrawBink_008816C0; // 0x008816C0

extern int gbDDrawBinkDone_008816CC; // 0x008816CC

int __fastcall sub_00511B80_DDrawClose(); // 0x00511B80

D2CriticalSectionStrc* gpRenderCriticalSection_007C9134; // 0x007C9134

unsigned int gaGlideDebugLight_0087F0D0[0x400]; // 0x0087F0D0

int gnGlideDebugX_008800D0; // 0x008800D0

int gnGlideDebugY_008800D4; // 0x008800D4

void** gppGlideDebugBuffer_00880454; // 0x00880454

unsigned int gnGlideBinkY_00880C04; // 0x00880C04

unsigned int gnGlideBinkFlags_00880C14; // 0x00880C14

int gaDDrawDebugFontGlyphOffsets_008812A8[96]; // 0x008812A8

unsigned long gdwDDrawDebugFontBkColor_008815A8; // 0x008815A8

unsigned int gnDDrawBinkY_008816B8; // 0x008816B8

unsigned int gnDDrawBinkFlags_008816C8; // 0x008816C8

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
    virtual long __stdcall Unlock(void* pRect);
};

class D2DirectDrawClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper(unsigned long dwFlags, void** ppClipper, void* pUnkOuter);
    virtual long __stdcall CreatePalette(unsigned int dwFlags, tagPALETTEENTRY* pEntries, D2DDrawPaletteClass** ppPalette, void* pUnkOuter);
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode);                                             // 0x00511DF0

int gbDDrawReady_00881264;                                                                                  // 0x00881264

int gbDDrawReady2_00881268;                                                                                 // 0x00881268

extern int gaDDrawModeWidth_0072F7A8[4];                                                                    // 0x0072F7A8

extern int gaDDrawModeHeight_0072F7B8[4];                                                                   // 0x0072F7B8

int gnDDrawBackBuffers_00881294;                                                                            // 0x00881294

D2DirectDrawClass* gpDirectDraw_00881270;                                                                   // 0x00881270

extern D2DDrawSurfaceClass* gpDDrawBackSurface_0088127C;                                                    // 0x0088127C

D2DDrawSurfaceClass* gpDDrawSurface_00881280;                                                              // 0x00881280

extern tagPALETTEENTRY gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8

static int gnScreenWidth2_00881258;                                                                         // 0x00881258

static int gnScreenHeight2_00881254;                                                                        // 0x00881254

struct D2RectStrc
{
    long left;
    long top;
    long right;
    long bottom;
};

unsigned char gPaletteEntries_007C8CCC[1];                                                                  // 0x007C8CCC

static int gbPaletteDirty_00881298;                                                                         // 0x00881298

class D2DDrawPaletteClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps(unsigned long* pCaps);
    virtual long __stdcall GetEntries(unsigned long dwFlags, unsigned long dwBase, unsigned long dwCount, void* pEntries);
    virtual long __stdcall Initialize(void* pDirectDraw, unsigned long dwFlags, void* pEntries);
    virtual long __stdcall SetEntries(unsigned long dwFlags, unsigned long dwStartingEntry, unsigned long dwCount, void* pEntries);
};

class D2DDrawObjectClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210

extern "C" long __stdcall DirectDrawCreate(void* pGuid, D2DirectDrawClass** ppDirectDraw, void* pUnkOuter); // 0x006B1350

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)());                                                   // 0x00683824

int __cdecl sub_005114D0_SetDisplayMode();                                                                  // 0x005114D0

void __cdecl sub_00511CD0_DDrawCloseAtExit();                                                               // 0x00511CD0

void __cdecl sub_00512430_DDrawCreateDebugFont();                                                           // 0x00512430

void __cdecl sub_005125B0_DDrawFreeDebugFont();                                                             // 0x005125B0

extern "C" const char szDirectDrawCreateFailed_006DE1B4[];                                                  // 0x006DE1B4

unsigned char gabDDrawDeviceGuid_00881144[16];                                                              // 0x00881144

int gbDDrawInitialized_00881260;                                                                            // 0x00881260

D2DDrawObjectClass* gpDDrawObject_00881274;                                                                 // 0x00881274

int __fastcall sub_00511870_EndScene();                                                                     // 0x00511870

void __fastcall sub_00512ED0_ClearScreen(int bPartial);                                                     // 0x00512ED0

extern int gaDDrawCapsTypes_0072F7D0[7];                                                                    // 0x0072F7D0

D2PaletteTableStrc* gpDDrawCaps_007C9150;                                                                      // 0x007C9150

void* gpDDrawSmackBuffer_008816B0;                                                                          // 0x008816B0

// 0x00508FE0
int __fastcall sub_00508FE0_GlideStartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (gbRenderPaused_007C9144)
        return 0;
    gbGlideDrawing_0087EFE4 = 1;
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x401);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (bClear)
        gpfGlideBufferClear_0087EB88((((nRed << 4) | nGreen) << 4 | nBlue) << 4, 0, 0);
    gnGlideState_0087EFD8 = 0;
    gnGlideState_0087EFDC = 0;
    gnGlideState_0087EFE0 = 0;
    gpfGlideMask_0087EB8C(1);
    sub_0050DBC0_GlideSetAmbientColor(0xFF, 0xFF, 0xFF);
    return 1;
}

void __fastcall sub_00509300_GlideSetPalette(const tagPALETTEENTRY* pPalette); // 0x00509300

// 0x0050BEF0
void __fastcall sub_0050BEF0_GlideDebugDraw(const unsigned int* pLight, const unsigned int* pPlayerLight, int nPosX, int nPosY)
{
    gnGlideDebugX_008800D0 = nPosX;
    gnGlideDebugY_008800D4 = nPosY;
    memcpy(gaGlideDebugLight_0087F0D0, pLight, 0x1000);
    memcpy(*gppGlideDebugBuffer_00880454, pPlayerLight, 0x4800);
    sub_0050BE20_GlideDebugRefresh();
}

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x0050C0F0

// 0x0050FD10
void __cdecl sub_0050FD10_GlideDrawVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpGlideBink_00880C0C);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x39);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    D2GrLfbInfoStrc info = { sizeof(D2GrLfbInfoStrc) };
    if (gpfGlideLfbLock_0087EADC(1, 0, 5, 0, 0, &info))
    {
        BinkCopyToBuffer(gpGlideBink_00880C0C, info.lfbPtr, info.strideInBytes, gpGlideBink_00880C0C->nHeight, gnGlideBinkX_00880C08, gnGlideBinkY_00880C04, gnGlideBinkFlags_00880C14);
        gpfGlideLfbUnlock_0087EAD8(1, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    if (gpGlideBink_00880C0C->nFrameNum == gpGlideBink_00880C0C->nFrames)
    {
        gbGlideBinkDone_00880C18 = 1;
        return;
    }
    BinkNextFrame(gpGlideBink_00880C0C);
}

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

    hResult = gpDDrawSurface_00881278->SetPalette(gpDDrawPalette_00881290);
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

// 0x005114D0
int __cdecl sub_005114D0_SetDisplayMode()
{
    D2_ASSERT(!gbDDrawReady_00881264, 0x26A);

    gnScreenWidth_007C9138 = 640;
    gnScreenWidth2_00881258 = 640;
    gnScreenHeight_007C913C = 480;
    gnScreenHeight2_00881254 = 480;

    int nBpp = 16;
    if (gdwVideoFlags_00881140 & gdwBitMasks[1])
    {
        nBpp = 32;
    }
    else if (gdwVideoFlags_00881140 & gdwBitMasks[2])
    {
        nBpp = 24;
    }

    const char* szError;
    long hResult = gpDirectDraw_00881270->SetDisplayMode(640, 480, nBpp);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    {
        D2DDSurfaceDescStrc tSurfaceDesc = { sizeof(D2DDSurfaceDescStrc) };
        tSurfaceDesc.dwFlags = 1;
        tSurfaceDesc.dwCaps = 0x4200;
        hResult = gpDirectDraw_00881270->CreateSurface(&tSurfaceDesc, &gpDDrawSurface_00881278, 0);
    }

    if (hResult)
    {
        szError = "Failed to create primary surface for cutscenes";
fail:
        sub_005103B0(szError, hResult);
        sub_00410610_WriteLogLine("Opening DirectDraw window for cutscenes failed!");
        return 0;
    }

    gbDDrawReady_00881264 = 1;
    gbDDrawReady2_00881268 = 1;
    return 1;
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
    hResult = gpDirectDraw_00881270->CreatePalette(4, gaDDrawPalette_007C8CC8, &gpDDrawPalette_00881290, 0);
    if (hResult)
    {
        sub_005103B0("CreatePalette failed!", hResult);
        return 0;
    }
    return sub_00511210_DDrawOpenSurfaces(nResolutionMode);
}

// 0x005117F0
int __fastcall sub_005117F0_DDrawEndDraw()
{
    long hResult = gpDDrawSurface_00881280->Unlock(0);
    if (hResult)
    {
        sub_005103B0("Unlock failed!", hResult);
        return 0;
    }

    gpScreenBuffer_007C9154 = 0;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 1036);
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}

// 0x00511870
int __fastcall sub_00511870_EndScene()
{
    if (gnDDrawBackBuffers_00881294)
    {
        if (gpDDrawSurface_00881280 && gpDDrawBackSurface_0088127C && gpDDrawSurface_00881280 != gpDDrawBackSurface_0088127C)
        {
            D2RectStrc tRect;
            tRect.left = 0;
            tRect.top = 0;
            tRect.right = gnScreenWidth_007C9138;
            tRect.bottom = gnScreenHeight_007C913C;
            const long hResult = gpDDrawBackSurface_0088127C->BltFast(0, 0, gpDDrawSurface_00881280, &tRect, 0x10);
            if (hResult)
            {
                sub_005103B0("BltFast failed!", hResult);
                return 0;
            }
        }

        gpDDrawSurface_00881278->Flip(0, 1);
    }
    else if (gpDDrawSurface_00881280)
    {
        D2RectStrc tRect;
        tRect.left = 0;
        tRect.top = 0;
        tRect.right = gnScreenWidth_007C9138;
        tRect.bottom = gnScreenHeight_007C913C;
        const long hResult = gpDDrawSurface_00881278->BltFast(0, 0, gpDDrawSurface_00881280, &tRect, 0x10);
        if (hResult)
        {
            sub_005103B0("BltFast failed!", hResult);
            return 0;
        }
    }

    if (gbPaletteDirty_00881298 && gpDDrawPalette_00881290)
    {
        gbPaletteDirty_00881298 = 0;
        const long hResult = gpDDrawPalette_00881290->SetEntries(0, 1, 0xFF, gPaletteEntries_007C8CCC);
        if (hResult)
        {
            sub_005103B0("SetEntries failed!", hResult);
            return 0;
        }
    }

    return 1;
}

// 0x00511A80
void __cdecl sub_00511A80_DDrawReleaseSurfaces()
{
    if (gbDDrawReady_00881264)
    {
        for (int i = 0; i < 3; ++i)
        {
            sub_00512ED0_ClearScreen(0);
            sub_00511870_EndScene();
        }
        if (gpDDrawSurface_00881280)
        {
            gpDDrawSurface_00881280->Release();
            gpDDrawSurface_00881280 = 0;
        }
        if (gpDDrawBackSurface_0088127C)
        {
            gpDDrawBackSurface_0088127C->Release();
            gpDDrawBackSurface_0088127C = 0;
        }
        if (gpDDrawSurface_00881278)
        {
            gpDDrawSurface_00881278->Release();
            gpDDrawSurface_00881278 = 0;
        }
        gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
        gbDDrawReady_00881264 = 0;
        gbDDrawReady2_00881268 = 0;
    }
}

// 0x00511B10
int __fastcall sub_00511B10_DDrawPlayCutscene()
{
    if (gbRenderPaused_007C9144)
    {
        return 0;
    }

    sub_00511A80_DDrawReleaseSurfaces();
    return sub_005114D0_SetDisplayMode();
}

// 0x00511B30
int __fastcall sub_00511B30_DDrawCloseSurface()
{
    sub_00511A80_DDrawReleaseSurfaces();
    if (gpDDrawPalette_00881290)
    {
        gpDDrawPalette_00881290->Release();
        gpDDrawPalette_00881290 = 0;
    }
    ghDDrawWindow_007C9140 = 0;
    return 1;
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

// 0x00511B80
int __fastcall sub_00511B80_DDrawClose()
{
    if (gbDDrawInitialized_00881260)
    {
        sub_00511A80_DDrawReleaseSurfaces();
        if (gpDDrawPalette_00881290)
        {
            gpDDrawPalette_00881290->Release();
            gpDDrawPalette_00881290 = 0;
        }
        ghDDrawWindow_007C9140 = 0;
        if (gpDDrawObject_00881274)
        {
            gpDDrawObject_00881274->Release();
            gpDDrawObject_00881274 = 0;
        }
        if (gpDirectDraw_00881270)
        {
            gpDirectDraw_00881270->Release();
            gpDirectDraw_00881270 = 0;
        }
        if (gpRenderCriticalSection_007C9134)
        {
            DeleteCriticalSection(gpRenderCriticalSection_007C9134);
            FOG_Free(gpRenderCriticalSection_007C9134, ".\\Src\\ddCore.cpp", 293, 0);
            gpRenderCriticalSection_007C9134 = 0;
        }
        sub_005125B0_DDrawFreeDebugFont();
        gbDDrawInitialized_00881260 = 0;
    }
    return 1;
}

// 0x00511C20
void __fastcall sub_00511C20_DDrawPauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x2F7);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (nWindowState)
    {
        gbRenderPaused_007C9144 = 1;
        sub_00511A80_DDrawReleaseSurfaces();
        if (gpDDrawPalette_00881290)
        {
            gpDDrawPalette_00881290->Release();
            gpDDrawPalette_00881290 = 0;
        }
        gbSurfaceActive_007C9140 = 0;
    }
    else
    {
        gbRenderPaused_007C9144 = 0;
        sub_005115E0_DDrawRestoreSurface(hWnd, nResolutionMode);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
}

// 0x00511CD0
void __cdecl sub_00511CD0_DDrawCloseAtExit()
{
    sub_00511B80_DDrawClose();
}

// 0x00511CE0
int __fastcall sub_00511CE0_DDrawInit(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pHelpers)
{
    gpGfxSettings_007C9148 = pSettings;
    gpTileDrawFunctions_007C914C = pHelpers;
    sub_00512430_DDrawCreateDebugFont();
    long hResult;
    if (gdwVideoFlags_00881140 & gdwBitMasks[0])
    {
        hResult = DirectDrawCreate(0, &gpDirectDraw_00881270, 0);
    }
    else
    {
        hResult = DirectDrawCreate(gabDDrawDeviceGuid_00881144, &gpDirectDraw_00881270, 0);
    }

    if (hResult)
    {
        sub_005103B0(szDirectDrawCreateFailed_006DE1B4, hResult);
        return 0;
    }

    atexit(sub_00511CD0_DDrawCloseAtExit);
    gbDDrawInitialized_00881260 = 1;
    gpRenderCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\ddCore.cpp", 246, 0);
    InitializeCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}

// 0x00511D70
int __fastcall sub_00511D70_GetCapsValue(int nIndex, int* pType)
{
    *pType = gaDDrawCapsTypes_0072F7D0[nIndex];
    switch (nIndex)
    {
    case 0:
        return (int)gpDDrawCaps_007C9150->pTransPalettes[2];
    case 1:
        return (int)gpDDrawCaps_007C9150->pTransPalettes[1];
    case 2:
        return (int)gpDDrawCaps_007C9150->pTransPalettes[0];
    case 3:
        return (int)gpDDrawCaps_007C9150->pScreenPalette;
    case 4:
        return (int)gpDDrawCaps_007C9150->pLuminancePalette;
    case 6:
        return (int)gpDDrawCaps_007C9150->pDarkBlendPalette;
    }
    return 0;
}


// 0x00512700
int __cdecl sub_00512700_DDrawGetBlendedShadows()
{
    return gpGfxSettings_007C9148->bBlendedShadows;
}

// 0x005128B0
void __fastcall sub_005128B0_DDrawDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    int nDrawMode;
    if (nAlpha >= 0xC0)
        nDrawMode = 5;
    else if (nAlpha >= 0x80)
        nDrawMode = 2;
    else if (nAlpha >= 0x40)
        nDrawMode = 1;
    else if (nAlpha > 0)
        nDrawMode = 0;
    else
        return;
    sub_00512710_DDrawDrawBox(nXStart, nYStart, nXEnd, nYEnd, dwColor, nDrawMode);
}

// 0x00512900
void __fastcall sub_00512900_DDrawPutPixel(int nX, int nY, unsigned char nColor)
{
    if (nX >= 0 && nX < gnScreenWidth_007C9138 && nY >= 0 && nY < gnScreenHeight_007C913C)
        gpScreenBuffer_007C9154[gnScreenWidth_007C9138 * nY + nX] = nColor;
}

// 0x005132C0
int __fastcall sub_005132C0_DDrawFloorTileDraw(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData)
{
    int nResult = sub_005FDEA0(pTile, 1, 0);
    if (nResult)
    {
        nPosX -= 0x50;
        switch (nScreenPanels)
        {
        case 1:
            nPosX -= gnScreenWidth_007C9138 / 4;
            break;
        case 2:
            nPosX += gnScreenWidth_007C9138 / 4;
            break;
        }
        nResult = gpTileDrawFunctions_007C914C->pfDrawFloorTile(pTile, nPosX, nPosY, pLight);
    }
    return nResult;
}


// 0x005136F0
void __cdecl sub_005136F0_BlitBinkFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpDDrawBink_008816C0);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x42);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    D2DDSurfaceDescStrc ddsd = { sizeof(D2DDSurfaceDescStrc) };
    if (gpDDrawSurface_00881278->Lock(0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpDDrawBink_008816C0, ddsd.lpSurface, ddsd.lPitch, gpDDrawBink_008816C0->nHeight, gnDDrawBinkX_008816BC, gnDDrawBinkY_008816B8, gnDDrawBinkFlags_008816C8);
        gpDDrawSurface_00881278->Unlock(0);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    if (gpDDrawBink_008816C0->nFrameNum == gpDDrawBink_008816C0->nFrames)
    {
        gbDDrawBinkDone_008816CC = 1;
        return;
    }
    BinkNextFrame(gpDDrawBink_008816C0);
}

#include "gen/data/Source/D2DDraw/Src/ddCore.inc"
