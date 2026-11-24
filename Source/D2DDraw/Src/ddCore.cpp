#include "D2DDraw.h"
#include "D2GameTypes.h"
#include "D2GfxTypes.h"
#include "D2Win32Base.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"
#include "D2Win32Types.h"
#include "D2FogSystemInfo.h"

struct D2CriticalSectionStrc;

struct D2TileLibraryEntryStrc;

struct D2GfxLightExStrc;

class D2DDrawSurfaceClass;

class D2DDrawPaletteClass;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

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

unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex); // 0x005093F0

void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0

void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500

void __cdecl sub_0050BE20_GlideDebugRefresh(); // 0x0050BE20

void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x0050DBC0

void __cdecl DDRAW_ReleaseSurfaces(); // 0x00511A80

int __fastcall DDRAW_CreateSurface(void* hWnd, int nResolutionMode); // 0x005115E0

void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710

int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0

extern "C" const char gszCourier[]; // 0x006DD52C

extern unsigned long gdwDDrawDebugFontTextColor; // 0x0072F7F0

extern int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC

extern int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8

extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

extern void (__stdcall* gpfnGrTexDownloadTable)(int nType, void* pData); // 0x0087EB40

extern void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88

extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C

extern unsigned int gaGlidePalette[256]; // 0x0087EBA0

extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0

extern int gbGlidePaletteTable_0087EFC8; // 0x0087EFC8

extern int gnGlideColorCombineState; // 0x0087EFD8

extern int gnGlideAlphaCombineMode; // 0x0087EFDC

extern int gnGlideTexFilterMode; // 0x0087EFE0

extern int gbGlideDrawing; // 0x0087EFE4

extern unsigned int gnGlideBinkX; // 0x00880C08

extern D2BinkStrc* gpGlideBink; // 0x00880C0C

extern int gbGlideBinkDone; // 0x00880C18

D2DDrawSurfaceClass* gpDDrawPrimarySurface;                                                               // 0x00881278

D2DDrawPaletteClass* gpDDrawPalette;                                                                // 0x00881290

extern int gaDDrawDebugFontCharWidths[96]; // 0x00881428

extern unsigned char* gpDDrawDebugFontGlyphs; // 0x008815AC

extern unsigned int gnDDrawBinkX; // 0x008816BC

extern D2BinkStrc* gpDDrawBink; // 0x008816C0

extern int gbDDrawBinkDone; // 0x008816CC

int __fastcall DDRAW_Close(); // 0x00511B80

D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134

unsigned int gaGlideDebugLight[0x400]; // 0x0087F0D0

int gnGlideDebugX; // 0x008800D0

int gnGlideDebugY; // 0x008800D4

void** gppGlideDebugBuffer; // 0x00880454

unsigned int gnGlideBinkY; // 0x00880C04

unsigned int gnGlideBinkFlags; // 0x00880C14

int gaDDrawDebugFontGlyphOffsets[96]; // 0x008812A8

unsigned long gdwDDrawDebugFontBkColor; // 0x008815A8

unsigned int gnDDrawBinkY; // 0x008816B8

unsigned int gnDDrawBinkFlags; // 0x008816C8

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

int gbDDrawReady;                                                                                  // 0x00881264

int gbDDrawReady2;                                                                                 // 0x00881268

extern int gaDDrawModeWidth[4];                                                                    // 0x0072F7A8

extern int gaDDrawModeHeight[4];                                                                   // 0x0072F7B8

int gnDDrawBackBuffers;                                                                            // 0x00881294

D2DirectDrawClass* gpDirectDraw;                                                                   // 0x00881270

extern D2DDrawSurfaceClass* gpDDrawBackSurface;                                                    // 0x0088127C

D2DDrawSurfaceClass* gpDDrawOffscreenSurface;                                                              // 0x00881280

extern tagPALETTEENTRY gatGamePalette[256];                                                     // 0x007C8CC8

static int gnScreenWidth2;                                                                         // 0x00881258

static int gnScreenHeight2;                                                                        // 0x00881254

unsigned char gabPaletteEntries[1];                                                                  // 0x007C8CCC

static int gbPaletteDirty;                                                                         // 0x00881298

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

int __cdecl DDRAW_SetDisplayMode();                                                                  // 0x005114D0

void __cdecl DDRAW_CloseAtExit();                                                               // 0x00511CD0

void __cdecl DDRAW_CreateDebugFont();                                                           // 0x00512430

void __cdecl DDRAW_FreeDebugFont();                                                             // 0x005125B0

extern "C" const char gszDirectDrawCreateFailed[];                                                  // 0x006DE1B4

unsigned char gabDDrawDeviceGuid[16];                                                              // 0x00881144

int gbDDrawInitialized;                                                                            // 0x00881260

D2DDrawObjectClass* gpDDrawObject;                                                                 // 0x00881274

int __fastcall DDRAW_Blit();                                                                     // 0x00511870

void __fastcall sub_00512ED0_ClearScreen(int bPartial);                                                     // 0x00512ED0

extern int gaDDrawCapsTypes[8];                                                                    // 0x0072F7D0

D2PaletteTableStrc* gpGfxPaletteView;                                                                      // 0x007C9150

void* gpDDrawSmackBuffer;                                                                          // 0x008816B0

int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, void* pBuffer, unsigned int nBufferSize, unsigned int* pnBytesRead); // 0x00414DE0

int gbDDrawPlatformFlag; // 0x0088125C

char gszDDrawDeviceName[256]; // 0x00881154

D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo(); // 0x00407360

void __fastcall GLCORE_SetPalette(const tagPALETTEENTRY* pPalette); // 0x00509300

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2FogSystemInfoStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall sub_006BE190_BuildGammaTable(int nGamma, void* pTable, double dScale, int nArg, int nEntries, int nMask); // 0x006BE190

unsigned long gdwVideoFlags; // 0x00881140

tagPALETTEENTRY gaDDrawSavedPalette[256]; // 0x00880D40


void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x0050C0F0

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50

void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor);                     // 0x00512D90

void __fastcall DDRAW_CloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x00513330

// 0x0050BEF0
void __fastcall GLIDE_DebugDraw(const unsigned int* pLight, const unsigned int* pPlayerLight, int nPosX, int nPosY)
{
    gnGlideDebugX = nPosX;
    gnGlideDebugY = nPosY;
    memcpy(gaGlideDebugLight, pLight, 0x1000);
    memcpy(*gppGlideDebugBuffer, pPlayerLight, 0x4800);
    sub_0050BE20_GlideDebugRefresh();
}

// 0x0050FD10
void __cdecl GLIDE_DrawVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpGlideBink);
    D2_ASSERT(gpRenderCriticalSection, 0x39);
    EnterCriticalSection(gpRenderCriticalSection);
    D2GrLfbInfoStrc info = { sizeof(D2GrLfbInfoStrc) };
    if (gpfnGrLfbLock(1, 0, 5, 0, 0, &info))
    {
        BinkCopyToBuffer(gpGlideBink, info.lfbPtr, info.strideInBytes, gpGlideBink->nHeight, gnGlideBinkX, gnGlideBinkY, gnGlideBinkFlags);
        gpfnGrLfbUnlock(1, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
    if (gpGlideBink->nFrameNum == gpGlideBink->nFrames)
    {
        gbGlideBinkDone = 1;
        return;
    }
    BinkNextFrame(gpGlideBink);
}

// 0x00510020
int __fastcall DDRAW_Detect(void* hInstance)
{
    D2FogSystemInfoStrc* pSystemInfo = FOG_GetSystemInfo();
    D2_ASSERT(pSystemInfo, 0x6F);

    if (pSystemInfo->nOsKind == 1)
    {
        gbDDrawPlatformFlag = 1;
    }

    char szKey[] = "Diablo II\\VideoConfig";
    if (SRegLoadString(szKey, "DeviceName", 0, gszDDrawDeviceName, sizeof(gszDDrawDeviceName))
// build: symbol ?gdwVideoFlags@* 0x00881140
        && SRegLoadValue(szKey, "dwFlags", 0, &gdwVideoFlags))
    {
        if (gdwVideoFlags & gdwBitMasks[0])
        {
            return 1;
        }

        unsigned int nSize = sizeof(gabDDrawDeviceGuid);
        if (SRegLoadData(szKey, "GUID", 0, gabDDrawDeviceGuid, sizeof(gabDDrawDeviceGuid), &nSize)
            && nSize == sizeof(gabDDrawDeviceGuid))
        {
            return 1;
        }
    }

    strcpy(gszDDrawDeviceName, "Fallback DirectDraw Device");
    gdwVideoFlags = gdwBitMasks[0];
    return 1;
}

// 0x00510160
void __fastcall sub_00510160_DDrawSetPalette(tagPALETTEENTRY* pPalette)
{
    memcpy(gaDDrawSavedPalette, pPalette, sizeof(gaDDrawSavedPalette));

    unsigned char abGamma[256];
// build: symbol ?gnDDrawGammaScale@* 0x0072F7C8
// build: symbol ?gnDDrawGamma@* 0x0072F7CC
    sub_006BE190_BuildGammaTable(gnDDrawGamma, abGamma, gnDDrawGammaScale, 1, 256, 0xFF);
    for (int i = 0; i < 256; ++i)
    {
        gatGamePalette[i].peRed = abGamma[gaDDrawSavedPalette[i].peRed];
        gatGamePalette[i].peGreen = abGamma[gaDDrawSavedPalette[i].peGreen];
        gatGamePalette[i].peBlue = abGamma[gaDDrawSavedPalette[i].peBlue];
    }

    gbPaletteDirty = 1;
}

// 0x00511210
static int DDRAW_OpenSurfaces(int nResolutionMode)
{
    D2_ASSERT(!gbDDrawReady, 0x142);
    if (!nResolutionMode)
    {
// build: symbol ?gnRenderWidth@* 0x007C9138
        gnRenderWidth = 640;
// build: symbol ?gnRenderHeight@* 0x007C913C
        gnRenderHeight = 480;
    }
    else
    {
        gnRenderWidth = 800;
        gnRenderHeight = 600;
    }
    sub_00511DF0_DDrawSetMode(nResolutionMode);
    gnScreenWidth2 = gaDDrawModeWidth[nResolutionMode];
    gnScreenHeight2 = gaDDrawModeHeight[nResolutionMode];

    long hResult = gpDirectDraw->SetCooperativeLevel(ghDDrawWindow_007C9140, 0x11);
    if (hResult && hResult != 0x88760245)
    {
        sub_005103B0("SetCooperativeLevel failed!", hResult);
        return 0;
    }

    D2_ASSERT(gpDirectDraw, 0x1DA);
    const char* szError;
    hResult = gpDirectDraw->SetDisplayMode(gnScreenWidth2, gnScreenHeight2, 8);
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
    gnDDrawBackBuffers = desc.dwBackBufferCount = 2;
    if (gpDirectDraw->CreateSurface(&desc, &gpDDrawPrimarySurface, 0))
    {
        memset(&desc, 0, sizeof(desc));
        desc.dwSize = sizeof(desc);
        desc.dwFlags = 0x21;
        desc.dwCaps = 0x4218;
        gnDDrawBackBuffers = desc.dwBackBufferCount = 1;
        if (gpDirectDraw->CreateSurface(&desc, &gpDDrawPrimarySurface, 0))
        {
            memset(&desc, 0, sizeof(desc));
            desc.dwSize = sizeof(desc);
            desc.dwFlags = 1;
            desc.dwCaps = 0x4200;
            gnDDrawBackBuffers = 0;
            hResult = gpDirectDraw->CreateSurface(&desc, &gpDDrawPrimarySurface, 0);
            if (hResult)
            {
                szError = "CreateSurface (primary single buffered) failed!";
                goto fail;
            }
        }
    }

    if (gnDDrawBackBuffers)
    {
        unsigned int dwCaps = 4;
        hResult = gpDDrawPrimarySurface->GetAttachedSurface(&dwCaps, &gpDDrawBackSurface);
        if (hResult)
        {
            szError = "GetAttachedSurface (backbuffer) failed!";
            goto fail;
        }
    }

    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    hResult = gpDDrawPrimarySurface->GetSurfaceDesc(&desc);
    if (hResult)
    {
        szError = "GetSurfaceDesc (primary) failed!";
        goto fail;
    }

    desc.dwFlags = 7;
    desc.dwCaps = 0x840;
    hResult = gpDirectDraw->CreateSurface(&desc, &gpDDrawOffscreenSurface, 0);
    if (hResult)
    {
        szError = "CreateSurface (render) failed!";
        goto fail;
    }

    hResult = gpDDrawPrimarySurface->SetPalette(gpDDrawPalette);
    if (hResult)
    {
        szError = "SetPalette failed!";
        goto fail;
    }

    gbDDrawReady = 1;
    gbDDrawReady2 = 0;
    return 1;

fail:
    sub_005103B0(szError, hResult);
    LOGMANAGER_WriteLogLine("Opening DirectDraw window failed!");
    return 0;
}

// 0x005114D0
int __cdecl DDRAW_SetDisplayMode()
{
    D2_ASSERT(!gbDDrawReady, 0x26A);

    gnRenderWidth = 640;
    gnScreenWidth2 = 640;
    gnRenderHeight = 480;
    gnScreenHeight2 = 480;

    int nBpp = 16;
    if (gdwVideoFlags & gdwBitMasks[1])
    {
        nBpp = 32;
    }
    else if (gdwVideoFlags & gdwBitMasks[2])
    {
        nBpp = 24;
    }

    const char* szError;
    long hResult = gpDirectDraw->SetDisplayMode(640, 480, nBpp);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    {
        D2DDSurfaceDescStrc tSurfaceDesc = { sizeof(D2DDSurfaceDescStrc) };
        tSurfaceDesc.dwFlags = 1;
        tSurfaceDesc.dwCaps = 0x4200;
        hResult = gpDirectDraw->CreateSurface(&tSurfaceDesc, &gpDDrawPrimarySurface, 0);
    }

    if (hResult)
    {
        szError = "Failed to create primary surface for cutscenes";
fail:
        sub_005103B0(szError, hResult);
        LOGMANAGER_WriteLogLine("Opening DirectDraw window for cutscenes failed!");
        return 0;
    }

    gbDDrawReady = 1;
    gbDDrawReady2 = 1;
    return 1;
}

// 0x005115E0
int __fastcall DDRAW_CreateSurface(void* hWnd, int nResolutionMode)
{
    ghDDrawWindow_007C9140 = hWnd;
    long hResult = gpDirectDraw->SetCooperativeLevel(hWnd, 0x11);
    if (hResult)
    {
        sub_005103B0("SetCooperativeLevel failed!", hResult);
        return 0;
    }
    memset(gatGamePalette, 0, sizeof(gatGamePalette));
    hResult = gpDirectDraw->CreatePalette(4, gatGamePalette, &gpDDrawPalette, 0);
    if (hResult)
    {
        sub_005103B0("CreatePalette failed!", hResult);
        return 0;
    }
    return DDRAW_OpenSurfaces(nResolutionMode);
}

// 0x00511720
int __fastcall DDRAW_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (gbRenderPaused)
        return 0;

    D2_ASSERT(gpRenderCriticalSection, 0x3BF);
    EnterCriticalSection(gpRenderCriticalSection);
    sub_00512ED0_ClearScreen(1);
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    long nResult = gpDDrawOffscreenSurface->Lock(0, &tDesc, 0x21, 0);
    if (nResult)
    {
        sub_005103B0("Lock failed!", nResult);
        LeaveCriticalSection(gpRenderCriticalSection);
        return 0;
    }
    gpScreenBuffer_007C9154 = (unsigned char*)tDesc.lpSurface;
    gnRenderWidth = tDesc.lPitch;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable((unsigned char*)tDesc.lpSurface, tDesc.lPitch, gnRenderHeight, 0);
    return 1;
}

// 0x005117F0
int __fastcall DDRAW_EndDraw()
{
    long hResult = gpDDrawOffscreenSurface->Unlock(0);
    if (hResult)
    {
        sub_005103B0("Unlock failed!", hResult);
        return 0;
    }

    gpScreenBuffer_007C9154 = 0;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
    D2_ASSERT(gpRenderCriticalSection, 1036);
    LeaveCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x00511870
int __fastcall DDRAW_Blit()
{
    if (gnDDrawBackBuffers)
    {
        if (gpDDrawOffscreenSurface && gpDDrawBackSurface && gpDDrawOffscreenSurface != gpDDrawBackSurface)
        {
            tagRECT tRect;
            tRect.left = 0;
            tRect.top = 0;
            tRect.right = gnRenderWidth;
            tRect.bottom = gnRenderHeight;
            const long hResult = gpDDrawBackSurface->BltFast(0, 0, gpDDrawOffscreenSurface, &tRect, 0x10);
            if (hResult)
            {
                sub_005103B0("BltFast failed!", hResult);
                return 0;
            }
        }

        gpDDrawPrimarySurface->Flip(0, 1);
    }
    else if (gpDDrawOffscreenSurface)
    {
        tagRECT tRect;
        tRect.left = 0;
        tRect.top = 0;
        tRect.right = gnRenderWidth;
        tRect.bottom = gnRenderHeight;
        const long hResult = gpDDrawPrimarySurface->BltFast(0, 0, gpDDrawOffscreenSurface, &tRect, 0x10);
        if (hResult)
        {
            sub_005103B0("BltFast failed!", hResult);
            return 0;
        }
    }

    if (gbPaletteDirty && gpDDrawPalette)
    {
        gbPaletteDirty = 0;
        const long hResult = gpDDrawPalette->SetEntries(0, 1, 0xFF, gabPaletteEntries);
        if (hResult)
        {
            sub_005103B0("SetEntries failed!", hResult);
            return 0;
        }
    }

    return 1;
}

// 0x00511A80
void __cdecl DDRAW_ReleaseSurfaces()
{
    if (gbDDrawReady)
    {
        for (int i = 0; i < 3; ++i)
        {
            sub_00512ED0_ClearScreen(0);
            DDRAW_Blit();
        }
        if (gpDDrawOffscreenSurface)
        {
            gpDDrawOffscreenSurface->Release();
            gpDDrawOffscreenSurface = 0;
        }
        if (gpDDrawBackSurface)
        {
            gpDDrawBackSurface->Release();
            gpDDrawBackSurface = 0;
        }
        if (gpDDrawPrimarySurface)
        {
            gpDDrawPrimarySurface->Release();
            gpDDrawPrimarySurface = 0;
        }
        gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
        gbDDrawReady = 0;
        gbDDrawReady2 = 0;
    }
}

// 0x00511B10
int __fastcall DDRAW_PlayCutscene()
{
    if (gbRenderPaused)
    {
        return 0;
    }

    DDRAW_ReleaseSurfaces();
    return DDRAW_SetDisplayMode();
}

// 0x00511B30
int __fastcall DDRAW_CloseSurface()
{
    DDRAW_ReleaseSurfaces();
    if (gpDDrawPalette)
    {
        gpDDrawPalette->Release();
        gpDDrawPalette = 0;
    }
    ghDDrawWindow_007C9140 = 0;
    return 1;
}

// 0x00511B60
int __fastcall DDRAW_ChangeRes(void* hWnd, int nResolutionMode)
{
    if (!gbRenderPaused)
    {
        DDRAW_ReleaseSurfaces();
        return DDRAW_OpenSurfaces(nResolutionMode);
    }
    return 1;
}

// 0x00511B80
int __fastcall DDRAW_Close()
{
    if (gbDDrawInitialized)
    {
        DDRAW_ReleaseSurfaces();
        if (gpDDrawPalette)
        {
            gpDDrawPalette->Release();
            gpDDrawPalette = 0;
        }
        ghDDrawWindow_007C9140 = 0;
        if (gpDDrawObject)
        {
            gpDDrawObject->Release();
            gpDDrawObject = 0;
        }
        if (gpDirectDraw)
        {
            gpDirectDraw->Release();
            gpDirectDraw = 0;
        }
        if (gpRenderCriticalSection)
        {
            DeleteCriticalSection(gpRenderCriticalSection);
            FOG_Free(gpRenderCriticalSection, ".\\Src\\ddCore.cpp", 293, 0);
            gpRenderCriticalSection = 0;
        }
        DDRAW_FreeDebugFont();
        gbDDrawInitialized = 0;
    }
    return 1;
}

// 0x00511C20
void __fastcall DDRAW_PauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection, 0x2F7);
    EnterCriticalSection(gpRenderCriticalSection);
    if (nWindowState)
    {
        gbRenderPaused = 1;
        DDRAW_ReleaseSurfaces();
        if (gpDDrawPalette)
        {
            gpDDrawPalette->Release();
            gpDDrawPalette = 0;
        }
        gbSurfaceActive_007C9140 = 0;
    }
    else
    {
        gbRenderPaused = 0;
        DDRAW_CreateSurface(hWnd, nResolutionMode);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
}

// 0x00511CD0
void __cdecl DDRAW_CloseAtExit()
{
    DDRAW_Close();
}

// 0x00511CE0
int __fastcall DDRAW_Init(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pHelpers)
{
// build: symbol ?gpGfxSettings@* 0x007C9148
    gpGfxSettings = pSettings;
    gpTileDrawFunctions_007C914C = pHelpers;
    DDRAW_CreateDebugFont();
    long hResult;
    if (gdwVideoFlags & gdwBitMasks[0])
    {
        hResult = DirectDrawCreate(0, &gpDirectDraw, 0);
    }
    else
    {
        hResult = DirectDrawCreate(gabDDrawDeviceGuid, &gpDirectDraw, 0);
    }

    if (hResult)
    {
        sub_005103B0(gszDirectDrawCreateFailed, hResult);
        return 0;
    }

    atexit(DDRAW_CloseAtExit);
    gbDDrawInitialized = 1;
    gpRenderCriticalSection = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\ddCore.cpp", 246, 0);
    InitializeCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x00511D70
int __fastcall DDRAW_GetDrawModePalette(int nIndex, int* pType)
{
    *pType = gaDDrawCapsTypes[nIndex];
    switch (nIndex)
    {
    case 0:
        return (int)gpGfxPaletteView->pTransPalettes[2];
    case 1:
        return (int)gpGfxPaletteView->pTransPalettes[1];
    case 2:
        return (int)gpGfxPaletteView->pTransPalettes[0];
    case 3:
        return (int)gpGfxPaletteView->pScreenPalette;
    case 4:
        return (int)gpGfxPaletteView->pLuminancePalette;
    case 6:
        return (int)gpGfxPaletteView->pDarkBlendPalette;
    }
    return 0;
}

// 0x005126F0
void __stdcall DDRAW_DebugDraw(int nUnused1, int nUnused2)
{
}

// 0x00512700
int __cdecl DDRAW_GetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}

// 0x005128B0
void __fastcall DDRAW_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
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
void __fastcall DDRAW_SetPixel(int nX, int nY, unsigned char nColor)
{
    if (nX >= 0 && nX < gnRenderWidth && nY >= 0 && nY < gnRenderHeight)
        gpScreenBuffer_007C9154[gnRenderWidth * nY + nX] = nColor;
}

// 0x00512E80
void __fastcall DDRAW_UtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_00512D90_DDrawUtilFilledRect(&tRect, nPaletteIndex);
    }
}

// 0x005132C0
int __fastcall DDRAW_FloorTileDraw(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData)
{
    int nResult = D2CMPTileValidate(pTile, 1, 0);
    if (nResult)
    {
        nPosX -= 0x50;
        switch (nScreenPanels)
        {
        case 1:
            nPosX -= gnRenderWidth / 4;
            break;
        case 2:
            nPosX += gnRenderWidth / 4;
            break;
        }
        nResult = gpTileDrawFunctions_007C914C->pfDrawFloorTile(pTile, nPosX, nPosY, pLight);
    }
    return nResult;
}

// 0x005136F0
void __cdecl DDRAW_DrawVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpDDrawBink);
    D2_ASSERT(gpRenderCriticalSection, 0x42);
    EnterCriticalSection(gpRenderCriticalSection);
    D2DDSurfaceDescStrc ddsd = { sizeof(D2DDSurfaceDescStrc) };
    if (gpDDrawPrimarySurface->Lock(0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpDDrawBink, ddsd.lpSurface, ddsd.lPitch, gpDDrawBink->nHeight, gnDDrawBinkX, gnDDrawBinkY, gnDDrawBinkFlags);
        gpDDrawPrimarySurface->Unlock(0);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
    if (gpDDrawBink->nFrameNum == gpDDrawBink->nFrames)
    {
        gbDDrawBinkDone = 1;
        return;
    }
    BinkNextFrame(gpDDrawBink);
}

#include "gen/data/Source/D2DDraw/Src/ddCore.inc"
