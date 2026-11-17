extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BnetHashContextStrc
{
    unsigned int aState[5];
    unsigned char f_14[64];
};

void __fastcall sub_005206B0_HashTransform(D2BnetHashContextStrc* pContext);                               // 0x005206B0

// 0x005209D0
void __fastcall sub_005209D0_HashBuffer(unsigned int* pOut, const void* pData, unsigned int nSize)
{
    D2BnetHashContextStrc tContext;
    tContext.aState[0] = 0x67452301;
    tContext.aState[1] = 0xEFCDAB89;
    tContext.aState[2] = 0x98BADCFE;
    tContext.aState[3] = 0x10325476;
    tContext.aState[4] = 0xC3D2E1F0;
    for (unsigned int i = 0; i < nSize; i += 64)
    {
        unsigned int nLength = nSize - i;
        if (nLength > 64)
            nLength = 64;
        memcpy(tContext.f_14, pData, nLength);
        if (nLength < 64)
            memset(&tContext.f_14[nLength], 0, 64 - nLength);
        sub_005206B0_HashTransform(&tContext);
    }
    pOut[0] = tContext.aState[0];
    pOut[1] = tContext.aState[1];
    pOut[2] = tContext.aState[2];
    pOut[3] = tContext.aState[3];
    pOut[4] = tContext.aState[4];
}
