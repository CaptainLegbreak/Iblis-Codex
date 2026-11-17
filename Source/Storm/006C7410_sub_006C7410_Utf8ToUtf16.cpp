extern const unsigned char gaTrailingBytesForUtf8_006FCCA0[256];                                            // 0x006FCCA0
extern const unsigned int gaOffsetsFromUtf8_006FCC88[6];                                                    // 0x006FCC88

// 0x006C7410
int __stdcall sub_006C7410_Utf8ToUtf16(unsigned short* pDst, unsigned int nDstMax, const unsigned char* pSrc, unsigned int nSrcMax, unsigned int* pnDstWritten, unsigned int* pnSrcRead)
{
    const unsigned char* pSrcStart = pSrc;
    unsigned short* pDstStart = pDst;
    const unsigned char* pSrcEnd;
    if (nSrcMax == 0x7FFFFFFF)
    {
        pSrcEnd = (const unsigned char*)0xFFFFFFFF;
    }
    else
    {
        pSrcEnd = pSrc + nSrcMax;
    }
    unsigned short* pDstEnd = pDst + nDstMax;
    int nResult = 0;
    while (pSrc < pSrcEnd)
    {
        unsigned int nExtra = gaTrailingBytesForUtf8_006FCCA0[*pSrc];
        if (pSrc + nExtra >= pSrcEnd)
        {
            nResult = -1 - (int)nExtra;
            goto done;
        }
        int i = 0;
        unsigned int ch = 0;
        switch (nExtra)
        {
        case 5: ch += pSrc[i++]; ch <<= 6;
        case 4: ch += pSrc[i++]; ch <<= 6;
        case 3: ch += pSrc[i++]; ch <<= 6;
        case 2: ch += pSrc[i++]; ch <<= 6;
        case 1: ch += pSrc[i++]; ch <<= 6;
        case 0: ch += pSrc[i++];
        }
        ch -= gaOffsetsFromUtf8_006FCC88[nExtra];
        if (pDst >= pDstEnd)
        {
            nResult = 1;
            goto done;
        }
        if (ch <= 0xFFFF)
        {
            *pDst++ = (unsigned short)ch;
            if (!ch)
            {
                goto done;
            }
        }
        else if (ch > 0x10FFFF)
        {
            *pDst++ = 0xFFFD;
        }
        else
        {
            if (pDst + 1 >= pDstEnd)
            {
                nResult = 1;
                goto done;
            }
            ch -= 0x10000;
            *pDst++ = (unsigned short)((ch >> 10) + 0xD800);
            *pDst++ = (unsigned short)((ch & 0x3FF) + 0xDC00);
        }
        pSrc += i;
    }
    nResult = -1;
done:
    if (pnSrcRead)
    {
        *pnSrcRead = pSrc - pSrcStart;
    }
    if (pnDstWritten)
    {
        *pnDstWritten = pDst - pDstStart;
    }
    return nResult;
}
