struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2BitCodeStrc
{
    int nValue;
    int nBits;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern unsigned int gdwLowMasks_006CE368[];                                                                 // 0x006CE368
unsigned int __stdcall BITMANIP_Read(D2BitBufferStrc* pBuffer, int nBits);                                 // 0x00410F60

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00410D90
void __stdcall sub_00410D90_XorBits(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] ^ *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] ^ pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] ^ pB[i + 1];
    case 1:
        pOut[i] = pA[i] ^ pB[i];
    }
}

// 0x00410E40
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize)
{
    D2_ASSERT(pBuffer, 316);
    pBuffer->pBuffer = pBitStream;
    pBuffer->nBits = 8 * nSize;
    pBuffer->nPos = 0;
    pBuffer->nPosBits = 0;
    pBuffer->bFull = 0;
}

// 0x00410EB0
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits)
{
    if (pBuffer->nPosBits + 8 * pBuffer->nPos + nBits > pBuffer->nBits)
    {
        pBuffer->bFull = 1;
        pBuffer->nPos = pBuffer->nBits / 8;
        pBuffer->nPosBits = 0;
        return;
    }
    if (!pBuffer->nPosBits)
    {
        *pBuffer->pBuffer = 0;
    }
    while (nBits > 0)
    {
        int n = 8 - pBuffer->nPosBits;
        if (n > nBits)
        {
            n = nBits;
        }
        *pBuffer->pBuffer |= (unsigned char)(gdwLowMasks_006CE368[n] & nValue) << pBuffer->nPosBits;
        pBuffer->nPosBits += n;
        if (pBuffer->nPosBits != 8)
        {
            break;
        }
        ++pBuffer->nPos;
        ++pBuffer->pBuffer;
        pBuffer->nPosBits = 0;
        if (8 * pBuffer->nPos < pBuffer->nBits)
        {
            *pBuffer->pBuffer = 0;
        }
        nValue >>= n;
        nBits -= n;
    }
}

// 0x00411020
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    return BITMANIP_Read(pBuffer, nBits);
}

// 0x00411030
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits)
{
    int nValue = BITMANIP_Read(pBuffer, nBits);
    if (nBits < 32 && ((1 << (nBits - 1)) & nValue))
    {
        nValue |= ~((1 << nBits) - 1);
    }
    return nValue;
}

// 0x00411070
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer)
{
    if (pBuffer->nPosBits)
    {
        ++pBuffer->nPos;
        ++pBuffer->pBuffer;
        pBuffer->nPosBits = 0;
        if (8 * pBuffer->nPos < pBuffer->nBits)
        {
            *pBuffer->pBuffer = 0;
        }
    }
}

// 0x004110B0
void __stdcall sub_004110B0_WriteCode(D2BitBufferStrc* pBuffer, D2BitCodeStrc* pCodes, int nIndex)
{
    BITMANIP_Write(pBuffer, pCodes[nIndex].nValue, pCodes[nIndex].nBits);
}

// 0x004110D0
int __stdcall sub_004110D0_ReadTreeCode(D2BitBufferStrc* pBuffer, int* pTree)
{
    int nNode = 0;
    for (;;)
    {
        int nBit = (gdwBitMasks_006CE268[pBuffer->nPosBits] & *pBuffer->pBuffer) >> pBuffer->nPosBits;
        ++pBuffer->nPosBits;
        if (pBuffer->nPosBits == 8)
        {
            ++pBuffer->pBuffer;
            ++pBuffer->nPos;
            pBuffer->nPosBits = 0;
        }
        if (pTree[nBit + nNode] >= 0)
        {
            return pTree[nBit + nNode];
        }
        nNode = 2 * (nBit + nNode) + 2;
    }
}

#include "gen/data/Source/Storm/00410D90_sub_00410D90_XorBits.inc"
