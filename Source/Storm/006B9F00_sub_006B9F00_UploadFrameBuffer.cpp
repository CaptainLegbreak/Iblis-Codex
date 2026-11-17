extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2DDSurfaceDesc2Strc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwHeight;
    unsigned long dwWidth;
    long lPitch;
    unsigned long dwBackBufferCount;
    unsigned long dwMipMapCount;
    unsigned long dwAlphaBitDepth;
    unsigned long dwReserved;
    void* lpSurface;
    unsigned char unk0x28[0x54];
};

struct D2DDSurfaceStrc;
struct D2DDSurfaceVtbl
{
    void* pfn00[25];
    long (__stdcall* Lock)(D2DDSurfaceStrc* pThis, void* pRect, D2DDSurfaceDesc2Strc* pDesc, unsigned long dwFlags, void* hEvent);
    void* pfn68[6];
    long (__stdcall* Unlock)(D2DDSurfaceStrc* pThis, void* pRect);
};
struct D2DDSurfaceStrc
{
    D2DDSurfaceVtbl* lpVtbl;
};

unsigned char* gpFrameBuffer_009897D0;                                                                      // 0x009897D0
D2DDSurfaceStrc* gpMemSurfaceA_009897D4;                                                                    // 0x009897D4
D2DDSurfaceStrc* gpMemSurfaceB_009897D8;                                                                    // 0x009897D8
extern "C" const char gszUnlockFailed_006FC284[];                                                           // 0x006FC284
extern "C" const char gszLockFailed_006FC2A4[];                                                             // 0x006FC2A4
void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult);                              // 0x006B20E0

static __declspec(noinline) void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch);

static void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch)
{
    for (int nRow = 64; nRow; --nRow)
    {
        unsigned short* pOut = (unsigned short*)pDst;
        for (int i = 0; i < 256; ++i)
        {
            pOut[i] = pSrc[i] | 0x8000;
        }
        pDst += nPitch;
        pSrc += 512;
    }
}

// 0x006B9F00
void __cdecl sub_006B9F00_UploadFrameBuffer()
{
    D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    if (!gpMemSurfaceA_009897D4)
    {
        return;
    }

    long hResult = gpMemSurfaceA_009897D4->lpVtbl->Lock(gpMemSurfaceA_009897D4, 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError(gszLockFailed_006FC2A4, hResult);
    }
    sub_006B9EB0_CopyWithAlpha((const unsigned short*)gpFrameBuffer_009897D0, (unsigned char*)tDesc.lpSurface, tDesc.lPitch);
    hResult = gpMemSurfaceA_009897D4->lpVtbl->Unlock(gpMemSurfaceA_009897D4, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError(gszUnlockFailed_006FC284, hResult);
    }

    if (!gpMemSurfaceB_009897D8)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1DB);
        exit(-1);
    }

    hResult = gpMemSurfaceB_009897D8->lpVtbl->Lock(gpMemSurfaceB_009897D8, 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError(gszLockFailed_006FC2A4, hResult);
    }
    sub_006B9EB0_CopyWithAlpha((const unsigned short*)(gpFrameBuffer_009897D0 + 0x200), (unsigned char*)tDesc.lpSurface, tDesc.lPitch);
    hResult = gpMemSurfaceB_009897D8->lpVtbl->Unlock(gpMemSurfaceB_009897D8, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError(gszUnlockFailed_006FC284, hResult);
    }
}
