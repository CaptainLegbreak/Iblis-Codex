// 0x006C7030
int __stdcall SUniConvertUTF16to8Len(const unsigned short* pSrc, unsigned int nSrcLength, unsigned int* pSrcRead)
{
    if (!nSrcLength || !pSrc)
    {
        if (pSrcRead)
        {
            *pSrcRead = 0;
        }
        return -1;
    }

    const unsigned short* pSrcStart = pSrc;
    const unsigned short* pSrcEnd = nSrcLength == 0x7FFFFFFF ? (const unsigned short*)-1 : pSrc + nSrcLength;
    int nResult = 0;

    for (;;)
    {
        if (pSrc >= pSrcEnd)
        {
            nResult = -1;
            break;
        }

        unsigned int ch = *pSrc++;
        if (ch - 0xD800 <= 0x3FF)
        {
            if (pSrc >= pSrcEnd)
            {
                nResult = -1;
                break;
            }

            const unsigned int ch2 = *pSrc;
            if (ch2 - 0xDC00 <= 0x3FF)
            {
                ch = ((ch - 0xD800) << 10) + (ch2 - 0xDC00) + 0x10000;
                ++pSrc;
            }
        }

        if (ch < 0x80)
        {
            ++nResult;
            if (!ch)
            {
                break;
            }
        }
        else if (ch < 0x800)
        {
            nResult += 2;
        }
        else if (ch < 0x10000)
        {
            nResult += 3;
        }
        else if (ch < 0x200000)
        {
            nResult += 4;
        }
        else if (ch < 0x4000000)
        {
            nResult += 5;
        }
        else if (ch <= 0x7FFFFFFF)
        {
            nResult += 6;
        }
        else
        {
            nResult += 2;
        }
    }

    if (pSrcRead)
    {
        *pSrcRead = pSrc - pSrcStart;
    }

    return nResult;
}
