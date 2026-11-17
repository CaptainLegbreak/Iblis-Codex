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
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult);                              // 0x006B20E0
extern "C" const char gszFailedToLockDest_006FB130[];                                                       // 0x006FB130
extern "C" const char gszFailedToLockSource_006FB14C[];                                                     // 0x006FB14C

// 0x006B38A0
void __fastcall sub_006B38A0_Copy(D2DDrawSurfaceStrc* pDst, D2DDrawSurfaceStrc* pSrc, unsigned int nRows)
{
    unsigned char* pSrcBits;
    unsigned char* pDstBits;
    unsigned int nDstPitch;
    unsigned int nWidth;
    D2DDSurfaceDescStrc tSrcDesc = { sizeof(D2DDSurfaceDescStrc) };
    long hResult = pSrc->lpVtbl->Lock(pSrc, 0, &tSrcDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError(gszFailedToLockSource_006FB14C, hResult);
    }
    else
    {
        pSrcBits = (unsigned char*)tSrcDesc.lpSurface;
        D2DDSurfaceDescStrc tDstDesc = { sizeof(D2DDSurfaceDescStrc) };
        hResult = pDst->lpVtbl->Lock(pDst, 0, &tDstDesc, 0x21, 0);
        if (hResult)
        {
            sub_006B20E0_ReportError(gszFailedToLockDest_006FB130, hResult);
        }
        else
        {
            nDstPitch = tDstDesc.lPitch;
            nWidth = tSrcDesc.lPitch;
            pDstBits = (unsigned char*)tDstDesc.lpSurface;
            nWidth = nWidth < nDstPitch ? nWidth : nDstPitch;
            unsigned int nLeft = nRows;
            while (nLeft--)
            {
                memcpy(pDstBits, pSrcBits, nWidth);

                if (nLeft && (int)pDst < 0 && (int)pSrc < 0 && nWidth) pDstBits += nDstPitch; else pDstBits += nDstPitch;
                pSrcBits += tSrcDesc.lPitch;
            }
        }
    }
    pSrc->lpVtbl->Unlock(pSrc, 0);
    pDst->lpVtbl->Unlock(pDst, 0);
}

#include "gen/data/Source/Storm/006B38A0_sub_006B38A0_Copy.inc"
