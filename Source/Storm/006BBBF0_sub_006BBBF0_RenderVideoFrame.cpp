struct D2CriticalSectionStrc;

struct D2BinkStrc
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Frames;
    unsigned int f_C;
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
    unsigned int unk0x28[21];
};

struct D2DDrawSurfaceStrc;

struct D2DDrawSurfaceVtblStrc
{
    void* unk0x00[25];
    long (__stdcall* Lock)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDSurfaceDescStrc* pSurfaceDesc, unsigned long dwFlags, void* hEvent);
    void* unk0x68[6];
    long (__stdcall* Unlock)(D2DDrawSurfaceStrc* pThis, void* pRect);
};

struct D2DDrawSurfaceStrc
{
    D2DDrawSurfaceVtblStrc* lpVtbl;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink);                            // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink);                               // 0x006CC5C4

extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
extern int gbSurfaceActive_007C9140;                                                                        // 0x007C9140
extern D2DDrawSurfaceStrc* gpSurface_00970E68;                                                              // 0x00970E68
unsigned int gnBinkY_00989C08;                                                                              // 0x00989C08
extern unsigned int gnBinkX_00989C0C;                                                                       // 0x00989C0C
extern D2BinkStrc* gpBink_00989C10;                                                                         // 0x00989C10
unsigned int gnBinkFlags_00989C18;                                                                          // 0x00989C18
extern int gbBinkDone_00989C1C;                                                                             // 0x00989C1C

// 0x006BBBF0
void __cdecl sub_006BBBF0_RenderVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    D2DDSurfaceDescStrc ddsd = { sizeof(D2DDSurfaceDescStrc) };
    BinkDoFrame(gpBink_00989C10);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x3D);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (gpSurface_00970E68->lpVtbl->Lock(gpSurface_00970E68, 0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpBink_00989C10, ddsd.lpSurface, ddsd.lPitch, gpBink_00989C10->Height, gnBinkX_00989C0C, gnBinkY_00989C08, gnBinkFlags_00989C18);
        gpSurface_00970E68->lpVtbl->Unlock(gpSurface_00970E68, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    if (gpBink_00989C10->f_C == gpBink_00989C10->Frames)
    {
        gbBinkDone_00989C1C = 1;
        return;
    }
    BinkNextFrame(gpBink_00989C10);
}
