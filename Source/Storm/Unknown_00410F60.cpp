struct D2BitBufferStrc;

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
extern "C" int __cdecl tolower(int nChar); // 0x0068523E
extern unsigned short gwStringCrcTable_00708140[256]; // 0x00708140

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

#include "gen/data/Source/Storm/Unknown_00410F60.inc"

// 0x004112C0
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString)
{
    unsigned short wCrc = 0xFFFF;
    char c;
    while ((c = (char)tolower((unsigned char)*szString++)) != 0)
    {
        wCrc = (wCrc >> 2) ^ gwStringCrcTable_00708140[(c ^ wCrc) & 0xFF];
    }
    return wCrc;
}
