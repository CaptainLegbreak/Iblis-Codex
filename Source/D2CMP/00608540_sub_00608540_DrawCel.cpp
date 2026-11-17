struct D2CelStrc { unsigned int flags,width,height; unsigned char unknown0C[0x14]; unsigned char pixels[1]; };
extern const char gszEmptyAssertText; // 0x006CC837
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern int gnGenericRle_008F03C8; // 0x008F03C8
const unsigned char* __fastcall sub_00606D10_SkipCelLines(const unsigned char*,int); // 0x00606D10
void __fastcall sub_00606D40_RleCopyRows(const unsigned char*,unsigned char*,int,int); // 0x00606D40
void __fastcall sub_00606DA0_RleCopyRowsClipped(const unsigned char*,unsigned char*,int,int,int,int,int); // 0x00606DA0
void __fastcall sub_00606E40_BlitBlendMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00606E40
void __fastcall sub_00607060_BlitClippedBlendMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607060
void __fastcall sub_006072F0_BlitDoubleMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x006072F0
void __fastcall sub_00607480_BlitClippedDoubleMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607480
void __fastcall sub_00607680_BlitMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607680
void __fastcall sub_006077C0_BlitClippedMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*); // 0x006077C0
void __fastcall sub_00607970_BlitBlendMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00607970
void __fastcall sub_00607B90_BlitClippedBlendMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607B90
void __fastcall sub_00607E20_BlitMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607E20
void __fastcall sub_00607F60_BlitClippedMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*); // 0x00607F60
void __fastcall sub_00608110_BlitBlend(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00608110
void __fastcall sub_006082E0_BlitClippedBlend(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*); // 0x006082E0
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
// 0x00608540
void __fastcall sub_00608540_DrawCel(D2CelStrc* pCel, unsigned char* pDest, int nX, int nLeft, int nRight, int nPitch, int nSkipRows, int nRows, const unsigned char* pMapA, const unsigned char* pBlend, const unsigned char* pMapB)
{
    const int nStartX = nX;
    const int nWidth = pCel->width;
    if ((unsigned int)nPitch < (unsigned int)nWidth)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1514);
        exit(-1);
    }
    if ((unsigned int)(nSkipRows + nRows) > pCel->height)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1515);
        exit(-1);
    }

    const unsigned char* pSrc = sub_00606D10_SkipCelLines(pCel->pixels, nSkipRows);
    const int nStride = (pCel->flags & 1) ? nPitch : -nPitch;

    if (gnGenericRle_008F03C8)
    {
        unsigned char* pNextRow = pDest + nStride;
        for (;;)
        {
            char nCode = *pSrc++;
            if (nCode < 0)
            {
                nCode &= 0x7F;
                if (!nCode)
                {
                    nX = nStartX;
                    pDest = pNextRow;
                    pNextRow += nStride;
                    if (!--nRows)
                        return;
                }
                else
                {
                    nX += nCode;
                    pDest += nCode;
                }
                continue;
            }

            const int nRun = nCode;
            const unsigned char* pSrcEnd = pSrc + nRun;
            unsigned char* pDestEnd = pDest + nRun;
            int nCount = nRun;
            if (nLeft || nRight)
            {
                const int nSkip = D2_MAX(nLeft - nX, 0);
                int nEnd = D2_MAX(nRight - nX, 0);
                nEnd = D2_MIN(nEnd, nRun);
                nCount = nEnd - nSkip;
                if (nCount <= 0)
                {
                    nCount = 0;
                }
                else
                {
                    pDest += nSkip;
                    pSrc += nSkip;
                }
            }

            const unsigned char* pSrcStop = pSrc + nCount;
            if (pMapA)
            {
                if (pBlend)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pBlend[pMapA[*pSrc] + (*pDest << 8)];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else if (pMapB)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapA[pMapB[*pSrc]];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapA[*pSrc];
                        ++pSrc;
                        ++pDest;
                    }
                }
            }
            else if (pMapB)
            {
                if (pBlend)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pBlend[pMapB[*pSrc] + (*pDest << 8)];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapB[*pSrc];
                        ++pSrc;
                        ++pDest;
                    }
                }
            }
            else if (pBlend)
            {
                while (pSrc < pSrcStop)
                {
                    *pDest = pBlend[*pSrc + (*pDest << 8)];
                    ++pSrc;
                    ++pDest;
                }
            }
            else
            {
                while (pSrc < pSrcStop)
                {
                    *pDest = *pSrc;
                    ++pSrc;
                    ++pDest;
                }
            }

            nX += nRun;
            pSrc = pSrcEnd;
            pDest = pDestEnd;
        }
    }

    const int bUnclipped = (!nLeft && !nRight) || (nX >= nLeft && nX + nWidth < nRight);
    if (pMapA)
    {
        if (pBlend)
        {
            if (bUnclipped)
                sub_00606E40_BlitBlendMapped(pSrc, pDest, nRows, nStride, pMapA, pBlend);
            else
                sub_00607060_BlitClippedBlendMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pBlend);
        }
        else if (pMapB)
        {
            if (bUnclipped)
                sub_006072F0_BlitDoubleMapped(pSrc, pDest, nRows, nStride, pMapA, pMapB);
            else
                sub_00607480_BlitClippedDoubleMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pMapB);
        }
        else
        {
            if (bUnclipped)
                sub_00607680_BlitMapped(pSrc, pDest, nRows, nStride, pMapA);
            else
                sub_006077C0_BlitClippedMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA);
        }
    }
    else if (pMapB)
    {
        if (pBlend)
        {
            if (bUnclipped)
                sub_00607970_BlitBlendMapped(pSrc, pDest, nRows, nStride, pMapB, pBlend);
            else
                sub_00607B90_BlitClippedBlendMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB, pBlend);
        }
        else
        {
            if (bUnclipped)
                sub_00607E20_BlitMapped(pSrc, pDest, nRows, nStride, pMapB);
            else
                sub_00607F60_BlitClippedMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB);
        }
    }
    else if (pBlend)
    {
        if (bUnclipped)
            sub_00608110_BlitBlend(pSrc, pDest, nRows, nStride, pBlend);
        else
            sub_006082E0_BlitClippedBlend(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pBlend);
    }
    else
    {
        if (bUnclipped)
            sub_00606D40_RleCopyRows(pSrc, pDest, nRows, nStride);
        else
            sub_00606DA0_RleCopyRowsClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight);
    }
}
