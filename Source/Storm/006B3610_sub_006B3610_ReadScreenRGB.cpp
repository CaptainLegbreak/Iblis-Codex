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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult);                              // 0x006B20E0

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern D2DDrawSurfaceStrc* gpSurface_00970E6C;                                                              // 0x00970E6C

// 0x006B3610
int __fastcall sub_006B3610_ReadScreenRGB(unsigned char* pDst)
{
    D2DDSurfaceDescStrc tDesc = { sizeof(D2DDSurfaceDescStrc) };
    if (!gpSurface_00970E6C)
    {
        return 0;
    }

    long hResult = gpSurface_00970E6C->lpVtbl->Lock(gpSurface_00970E6C, 0, &tDesc, 0x11, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("Lock failed!", hResult);
        return 0;
    }

    int nPitch = tDesc.lPitch / 4;
    unsigned char* pOutRow = pDst;
    unsigned int* pSrcRow = (unsigned int*)tDesc.lpSurface;
    for (int y = 0; y < gnScreenHeight_007C913C; ++y)
    {
        unsigned char* pOut = pOutRow;
        unsigned int* pSrc = pSrcRow;
        for (int x = 0; x < gnScreenWidth_007C9138; ++x)
        {
            unsigned int dwPixel = *pSrc++;
            *pOut++ = (unsigned char)(dwPixel >> 16);
            *pOut++ = (unsigned char)(dwPixel >> 8);
            *pOut++ = (unsigned char)dwPixel;
        }
        pOutRow += gnScreenWidth_007C9138 * 3;
        pSrcRow += nPitch;
    }

    hResult = gpSurface_00970E6C->lpVtbl->Unlock(gpSurface_00970E6C, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("Unlock failed!", hResult);
        return 0;
    }
    return 1;
}
