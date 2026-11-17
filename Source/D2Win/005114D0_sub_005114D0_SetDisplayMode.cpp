extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RectStrc
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2DDSurfaceDescStrc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int unk0x08[24];
    unsigned int dwCaps;
};

struct D2IDirectDrawSurface
{
    virtual long __stdcall QueryInterface(void* riid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall AddAttachedSurface(void* pSurface) = 0;
    virtual long __stdcall AddOverlayDirtyRect(void* pRect) = 0;
    virtual long __stdcall Blt(void* pDestRect, void* pSrcSurface, void* pSrcRect, unsigned long dwFlags, void* pFx) = 0;
    virtual long __stdcall BltBatch(void* pBatch, unsigned long dwCount, unsigned long dwFlags) = 0;
    virtual long __stdcall BltFast(unsigned long dwX, unsigned long dwY, D2IDirectDrawSurface* pSrcSurface, D2RectStrc* pSrcRect, unsigned long dwTrans) = 0;
    virtual long __stdcall DeleteAttachedSurface(unsigned long dwFlags, void* pSurface) = 0;
    virtual long __stdcall EnumAttachedSurfaces(void* pContext, void* pfCallback) = 0;
    virtual long __stdcall EnumOverlayZOrders(unsigned long dwFlags, void* pContext, void* pfCallback) = 0;
    virtual long __stdcall Flip(D2IDirectDrawSurface* pTargetOverride, unsigned long dwFlags) = 0;
};

struct D2IDirectDrawPalette
{
    virtual long __stdcall QueryInterface(void* riid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(unsigned long* pCaps) = 0;
    virtual long __stdcall GetEntries(unsigned long dwFlags, unsigned long dwBase, unsigned long dwCount, void* pEntries) = 0;
    virtual long __stdcall Initialize(void* pDirectDraw, unsigned long dwFlags, void* pEntries) = 0;
    virtual long __stdcall SetEntries(unsigned long dwFlags, unsigned long dwStartingEntry, unsigned long dwCount, void* pEntries) = 0;
};

struct D2IDirectDraw
{
    virtual long __stdcall QueryInterface(void* riid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall Compact() = 0;
    virtual long __stdcall CreateClipper(unsigned long dwFlags, void** ppClipper, void* pOuter) = 0;
    virtual long __stdcall CreatePalette(unsigned long dwFlags, void* pEntries, void** ppPalette, void* pOuter) = 0;
    virtual long __stdcall CreateSurface(D2DDSurfaceDescStrc* pSurfaceDesc, D2IDirectDrawSurface** ppSurface, void* pOuter) = 0;
    virtual long __stdcall DuplicateSurface(void* pSurface, void** ppDuplicate) = 0;
    virtual long __stdcall EnumDisplayModes(unsigned long dwFlags, void* pDesc, void* pContext, void* pfCallback) = 0;
    virtual long __stdcall EnumSurfaces(unsigned long dwFlags, void* pDesc, void* pContext, void* pfCallback) = 0;
    virtual long __stdcall FlipToGDISurface() = 0;
    virtual long __stdcall GetCaps(void* pDriverCaps, void* pHelCaps) = 0;
    virtual long __stdcall GetDisplayMode(void* pSurfaceDesc) = 0;
    virtual long __stdcall GetFourCCCodes(unsigned long* pNumCodes, unsigned long* pCodes) = 0;
    virtual long __stdcall GetGDISurface(void** ppSurface) = 0;
    virtual long __stdcall GetMonitorFrequency(unsigned long* pFrequency) = 0;
    virtual long __stdcall GetScanLine(unsigned long* pScanLine) = 0;
    virtual long __stdcall GetVerticalBlankStatus(int* pIsInVB) = 0;
    virtual long __stdcall Initialize(void* pGuid) = 0;
    virtual long __stdcall RestoreDisplayMode() = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwFlags) = 0;
    virtual long __stdcall SetDisplayMode(unsigned long dwWidth, unsigned long dwHeight, unsigned long dwBpp) = 0;
};

void __fastcall sub_005103B0(const char* szText, long nResult);                                 // 0x005103B0
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
unsigned char gPaletteEntries_007C8CCC[1];                                                                  // 0x007C8CCC
extern unsigned int gdwVideoFlags_00881140;                                                                 // 0x00881140
int gnScreenHeight2_00881254;                                                                               // 0x00881254
int gnScreenWidth2_00881258;                                                                                // 0x00881258
int gbDDrawReady_00881264;                                                                                  // 0x00881264
int gbDDrawReady2_00881268;                                                                                 // 0x00881268
extern D2IDirectDraw* gpDirectDraw_00881270;                                                                // 0x00881270
extern D2IDirectDrawSurface* gpDDrawSurface_00881278;                                                       // 0x00881278
extern D2IDirectDrawSurface* gpDDrawBackSurface_0088127C;                                                   // 0x0088127C
extern D2IDirectDrawSurface* gpDDrawSurface_00881280;                                                       // 0x00881280
extern D2IDirectDrawPalette* gpDDrawPalette_00881290;                                                       // 0x00881290
extern int gbDDrawWindowed_00881294;                                                                        // 0x00881294
static int gbPaletteDirty_00881298;                                                                         // 0x00881298

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

// 0x00511870
int __fastcall sub_00511870_EndScene()
{
    if (gbDDrawWindowed_00881294)
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
