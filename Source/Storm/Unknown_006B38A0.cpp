#include "D2DDrawTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0
extern "C" const char gszFailedToLockDest_006FB130[];                                                       // 0x006FB130
extern "C" const char gszFailedToLockSource_006FB14C[];                                                     // 0x006FB14C

// 0x006B38A0
void __fastcall sub_006B38A0_Copy(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, unsigned int nRows)
{
    unsigned char* pSrcBits;
    unsigned char* pDstBits;
    unsigned int nDstPitch;
    unsigned int nWidth;
    D2DDSurfaceDesc2Strc tSrcDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    long hResult = pSrc->lpVtbl->Lock(pSrc, 0, &tSrcDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszFailedToLockSource_006FB14C, hResult);
    }
    else
    {
        pSrcBits = (unsigned char*)tSrcDesc.lpSurface;
        D2DDSurfaceDesc2Strc tDstDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        hResult = pDst->lpVtbl->Lock(pDst, 0, &tDstDesc, 0x21, 0);
        if (hResult)
        {
            sub_006B20E0_DDrawLogError(gszFailedToLockDest_006FB130, hResult);
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

#include "gen/data/Source/Storm/Unknown_006B38A0.inc"
