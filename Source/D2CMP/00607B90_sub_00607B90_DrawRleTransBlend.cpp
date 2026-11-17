typedef unsigned char BYTE;

#define BLEND_PIXEL(i) pDst[i] = pBlend[(pDst[i] << 8) + pTrans[pSrc[i]]]

// 0x00607B90
void __fastcall sub_00607B90_DrawRleTransBlend(const BYTE* pSrc, BYTE* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const BYTE* pTrans, const BYTE* pBlend)
{
    int nStartX = nX;
    BYTE* pLine = pDst + nPitch;

    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (--nRows == 0)
                {
                    return;
                }
                nX = nStartX;
                pDst = pLine;
                pLine += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
        }
        else
        {
            int nStart = nClipLeft - nX;
            if (nStart < 0)
            {
                nStart = 0;
            }
            int nEnd = nClipRight - nX;
            if (nEnd > nCode)
            {
                nEnd = nCode;
            }
            int nCount = nEnd - nStart;

            if (nCount > 0)
            {
                int nBlocks = nCount >> 3;
                const BYTE* pRunSrc = pSrc;
                BYTE* pRunDst = pDst;
                pSrc += nStart;
                pDst += nStart;
                int nRem = nCount & 7;
                switch (nRem)
                {
                case 7: BLEND_PIXEL(6);
                case 6: BLEND_PIXEL(5);
                case 5: BLEND_PIXEL(4);
                case 4: BLEND_PIXEL(3);
                case 3: BLEND_PIXEL(2);
                case 2: BLEND_PIXEL(1);
                case 1: BLEND_PIXEL(0);
                case 0:
                    pDst += nRem;
                    pSrc += nRem;
                    while (nBlocks)
                    {
                        BLEND_PIXEL(7);
                        BLEND_PIXEL(6);
                        BLEND_PIXEL(5);
                        BLEND_PIXEL(4);
                        BLEND_PIXEL(3);
                        BLEND_PIXEL(2);
                        BLEND_PIXEL(1);
                        BLEND_PIXEL(0);
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    }
                }
                nX += nCode;
                pSrc = pRunSrc + nCode;
                pDst = pRunDst + nCode;
            }
            else
            {
                nX += nCode;
                pSrc += nCode;
                pDst += nCode;
            }

        }
    }
}
