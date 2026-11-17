extern const unsigned int gdwUtf8FirstByteMark_006FCDA0[];                                                  // 0x006FCDA0

// 0x006C7130
int __stdcall SUniConvertUTF16to8(char* pDest, unsigned int nDestSize, const unsigned short* pSrc, unsigned int nSrcLength, unsigned int* pDestWritten, unsigned int* pSrcRead)
{
    const unsigned short* pSrcStart = pSrc;
    char* pDestStart = pDest;
    const unsigned short* pSrcEnd = nSrcLength == 0x7FFFFFFF ? (const unsigned short*)-1 : pSrc + nSrcLength;
    int nResult = 0;
    char* pDestEnd = pDest + nDestSize;

    for (;;)
    {
        if (pSrc >= pSrcEnd)
        {
            nResult = -1;
            break;
        }

        unsigned int ch = *pSrc;
        unsigned int nUnits = 1;
        if (ch - 0xD800 <= 0x3FF)
        {
            if (pSrc + 1 >= pSrcEnd)
            {
                nResult = -1;
                break;
            }

            const unsigned int ch2 = pSrc[1];
            if (ch2 - 0xDC00 <= 0x3FF)
            {
                ch = ((ch - 0xD800) << 10) + (ch2 - 0xDC00) + 0x10000;
                nUnits = 2;
            }
        }

        unsigned int nBytes;
        if (ch < 0x80)
        {
            nBytes = 1;
            if (!ch)
            {
                if (pDest >= pDestEnd)
                {
                    nResult = nBytes;
                    break;
                }

                *pDest = (char)ch;
                pDest += nBytes;
                break;
            }
        }
        else if (ch < 0x800)
        {
            nBytes = 2;
        }
        else if (ch < 0x10000)
        {
            nBytes = 3;
        }
        else if (ch < 0x200000)
        {
            nBytes = 4;
        }
        else if (ch < 0x4000000)
        {
            nBytes = 5;
        }
        else if (ch <= 0x7FFFFFFF)
        {
            nBytes = 6;
        }
        else
        {
            ch = 0xFFFD;
            nBytes = 2;
        }

        if (pDest + nBytes > pDestEnd)
        {
            nResult = nBytes;
            break;
        }

        pDest += nBytes;
        switch (nBytes)
        {
        case 6:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 5:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 4:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 3:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 2:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 1:
            *--pDest = (char)(gdwUtf8FirstByteMark_006FCDA0[nBytes] | ch);
        }

        pSrc += nUnits;
        pDest += nBytes;
    }

    if (pSrcRead)
    {
        *pSrcRead = pSrc - pSrcStart;
    }

    if (pDestWritten)
    {
        *pDestWritten = pDest - pDestStart;
    }

    return nResult;
}

#include "gen/data/Source/Storm/006C7130_SUniConvertUTF16to8.inc"
