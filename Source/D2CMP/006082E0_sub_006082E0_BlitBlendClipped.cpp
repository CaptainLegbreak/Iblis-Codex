// 0x006082E0
void __fastcall sub_006082E0_BlitBlendClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pBlend)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
            case 6: pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
            case 5: pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
            case 4: pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
            case 3: pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
            case 2: pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
            case 1: pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
            case 0:
                if (nBlocks)
                {
                    pDst += nCount;
                    pSrc += nCount;
                    do
                    {
                        pDst[7] = pBlend[(pDst[7] << 8) + pSrc[7]];
                        pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
                        pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
                        pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
                        pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
                        pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
                        pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
                        pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}
