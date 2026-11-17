extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
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

struct D2DDrawSurfaceStrc;

struct D2DDrawSurfaceVtblStrc
{
    void* unk0x00[25];
    long (__stdcall* Lock)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDSurfaceDescStrc* pSurfaceDesc, unsigned long dwFlags, void* hEvent);
};

struct D2DDrawSurfaceStrc
{
    D2DDrawSurfaceVtblStrc* lpVtbl;
};

struct D2TileDrawFunctionsStrc
{
    void (__fastcall* pfFillYBufferTable)(unsigned char* pBits, int nWidth, int nHeight, int a4);
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void __fastcall sub_005103B0(const char* szText, long nResult);                                 // 0x005103B0
void __fastcall sub_00512ED0_ClearScreen(int bPartial);                                                     // 0x00512ED0

extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C;                                               // 0x007C914C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881280;                                                         // 0x00881280

// 0x00511720
int __fastcall sub_00511720_DDrawStartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (gbRenderPaused_007C9144)
        return 0;

    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x3BF);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    sub_00512ED0_ClearScreen(1);
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    long nResult = gpDDrawSurface_00881280->lpVtbl->Lock(gpDDrawSurface_00881280, 0, &tDesc, 0x21, 0);
    if (nResult)
    {
        sub_005103B0("Lock failed!", nResult);
        LeaveCriticalSection(gpRenderCriticalSection_007C9134);
        return 0;
    }
    gpScreenBuffer_007C9154 = (unsigned char*)tDesc.lpSurface;
    gnScreenWidth_007C9138 = tDesc.lPitch;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable((unsigned char*)tDesc.lpSurface, tDesc.lPitch, gnScreenHeight_007C913C, 0);
    return 1;
}
