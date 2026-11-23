struct D2CodecBitReaderStrc
{
    unsigned int nReserved00;
    unsigned int* pCurWord;
    unsigned int nReserved08;
    int nBitOffset;
};

extern unsigned int gaCodecBitWidthTable_006E5F70[48]; // 0x006E5F70
extern unsigned int gaCodecSignExtendTable_006E60B8[32]; // 0x006E60B8

extern unsigned int gadwDccBitMasks[33]; // 0x006E6030

static unsigned int __stdcall sub_0060B200_ReadBits(int nNumBits, D2CodecBitReaderStrc* pBitState);

// 0x0060B200
static unsigned int __stdcall sub_0060B200_ReadBits(int nNumBits, D2CodecBitReaderStrc* pBitState)
{
    if (!nNumBits)
        return 0;

    const int nRemain = 32 - pBitState->nBitOffset;
    unsigned int nBits;
    if (nNumBits <= nRemain)
    {
        nBits = gadwDccBitMasks[nNumBits] & (*pBitState->pCurWord >> pBitState->nBitOffset);
        pBitState->nBitOffset += nNumBits;
        if (pBitState->nBitOffset == 32)
        {
            ++pBitState->pCurWord;
            pBitState->nBitOffset = 0;
        }
    }
    else
    {
        nBits = gadwDccBitMasks[nRemain] & (*pBitState->pCurWord++ >> pBitState->nBitOffset);
        pBitState->nBitOffset = nNumBits - nRemain;
        nBits |= (gadwDccBitMasks[pBitState->nBitOffset] & *pBitState->pCurWord) << nRemain;
    }
    return nBits;
}

static unsigned int __fastcall sub_0060B280_ReadBitsSigned(int nBitWidthCode, D2CodecBitReaderStrc* pBitState, int bSigned);

// build: context sub_0060B280_ReadBitsSigned
static unsigned int __fastcall sub_0060B280_ReadBitsSigned(int nBitWidthCode, D2CodecBitReaderStrc* pBitState, int bSigned)
{
    const int nNumBits = gaCodecBitWidthTable_006E5F70[nBitWidthCode];
    unsigned int nBitsRead = sub_0060B200_ReadBits(nNumBits, pBitState);
    if (nNumBits && bSigned && (gaCodecBitWidthTable_006E5F70[nNumBits + 15] & nBitsRead))
        nBitsRead |= gaCodecSignExtendTable_006E60B8[nNumBits];

    return nBitsRead;
}

// build: context sub_0060B280_Shim
// calling-convention shim (not game code)
unsigned int __fastcall sub_0060B280_Shim(int nBitWidthCode, D2CodecBitReaderStrc* pBitState, int bSigned)
{
    return sub_0060B280_ReadBitsSigned(nBitWidthCode, pBitState, bSigned);
}

#include "gen/data/Source/D2CMP/Unknown_0060B200.inc"
