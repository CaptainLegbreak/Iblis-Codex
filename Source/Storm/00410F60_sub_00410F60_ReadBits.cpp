struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

extern const unsigned int gdwBitMasks_006CE368[9]; // 0x006CE368
extern const unsigned char gnOffsetMasks_006CE38C[9]; // 0x006CE38C

// 0x00410F60
unsigned int __stdcall sub_00410F60_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    int n = pBuffer->nPosBits + nBits + 8 * pBuffer->nPos - pBuffer->nBits;

    if (n < 0)
    {
        n = 0;
    }

    nBits -= n;
    if (n)
    {
        pBuffer->bFull = 1;
    }

    unsigned int dwValue = 0;
    unsigned int dw = 0;
    int dwBitsLeft = nBits;

    if (dwBitsLeft > 0)
    {
        do
        {
            int i = 8 - pBuffer->nPosBits;
            if (i > dwBitsLeft)
            {
                i = dwBitsLeft;
            }
            const int nPosBits = pBuffer->nPosBits;

            dwValue += (gdwBitMasks_006CE368[i] & ((unsigned char)(*pBuffer->pBuffer & gnOffsetMasks_006CE38C[nPosBits]) >> nPosBits)) << dw;
            dwBitsLeft -= i;
            dw += i;
            pBuffer->nPosBits += i;

            if (pBuffer->nPosBits == 8)
            {
                pBuffer->pBuffer = pBuffer->pBuffer + 1;
                ++pBuffer->nPos;
                pBuffer->nPosBits = 0;
            }
        }
        while (dwBitsLeft > 0);
    }

    return dwValue;
}

#include "gen/data/Source/Storm/00410F60_sub_00410F60_ReadBits.inc"
