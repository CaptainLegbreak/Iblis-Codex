void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

struct D2StormBigBufferStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    void sub_00421FE0_GrowToFit(int nIndex);                                                                // 0x00421FE0
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    // build: context D2StormBigBufferStrc::InlineSetCount
    void InlineSetCount(unsigned int nCount)
    {
        if (nCount > f_4 && nCount > f_0)
        {
            unsigned int nChunk = f_C;
            if (!nChunk)
                nChunk = sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            sub_004216E0_ReallocData(nAlloc);
        }
        f_4 = nCount;
    }
    void InlineGrowToFit(int nIndex)
    {
        unsigned int nPosition = m_offset + nIndex;
        if (nPosition >= f_4)
        {
            unsigned int nNewCount = nPosition + 1;
            if (nNewCount > f_0)
            {
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nNewCount);
                sub_004216E0_ReallocData(RoundUp(nNewCount, nChunk));
            }
            SMemZero(&f_8[f_4], (nPosition - f_4 + 1) * sizeof(unsigned int));
            f_4 = nNewCount;
        }
    }
    unsigned int& Get(unsigned int nIndex)
    {
        sub_00421FE0_GrowToFit(nIndex);
        return f_8[m_offset + nIndex];
    }
    unsigned int& At(unsigned int nIndex)
    {
        InlineGrowToFit(nIndex);
        return f_8[m_offset + nIndex];
    }
};

// 0x00420F80
static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength)
{
    *pnLength = 0;
    *pnOffset = 0;
    while (*pnOffset < nSize)
    {
        unsigned int nByte = pData[(*pnOffset)++];
        if (nByte == 0xFF)
            break;
        *pnLength = *pnLength * 0xFF + nByte;
    }
    *pnLength = *pnLength < nSize - *pnOffset ? *pnLength : nSize - *pnOffset;
}
#define DECODE_LENGTH sub_00420F80_DecodeLength

static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, D2StormBigBufferStrc* pBuf)
{
    pBuf->InlineSetCount(pBuf->m_offset);
    for (unsigned int i = 0; i < nCount; i++)
    {
        unsigned int nByte = pData[i];
        unsigned int nWord = i >> 2;
        unsigned int nShift = i & 3;
        pBuf->At(nWord) = (nByte << (nShift * 8)) + (nShift ? pBuf->Get(nWord) : 0);
    }
}
#define FROM_BINARY sub_00423380_FromBinary

// 0x004234F0
static void __stdcall sub_004234F0_FromLengthPrefixed(D2StormBigBufferStrc* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData)
{
    unsigned int nOffset;
    unsigned int nLength;
    DECODE_LENGTH(pData, nSize, &nOffset, &nLength);
    FROM_BINARY(pData + nOffset, nLength, pBuf);
    if (pnUsed)
        *pnUsed = nOffset + nLength;
}
#define FROM_LENGTH_PREFIXED sub_004234F0_FromLengthPrefixed

// 0x00423850
void __stdcall sub_00423850(void* hBig, const void* pData, unsigned int nSize)
{
    FROM_BINARY((const unsigned char*)pData, nSize, (D2StormBigBufferStrc*)hBig);
}

// build: context sub_00423890_FromLengthPrefixed
void __stdcall sub_00423890_FromLengthPrefixed(void* hBig, const void* pData, unsigned int nSize, unsigned int* pnUsed)
{
    FROM_LENGTH_PREFIXED((D2StormBigBufferStrc*)hBig, pnUsed, nSize, (const unsigned char*)pData);
}
