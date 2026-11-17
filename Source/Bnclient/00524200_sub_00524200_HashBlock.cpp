struct D2BnHashCtxStrc
{
    unsigned int aState[5];
    int nBitCountLo;
    int nBitCountHi;
    unsigned int f_1C[16];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern D2BnHashCtxStrc gaBnHashCtx_00882760[];                                                              // 0x00882760
void __stdcall sub_00523AF0_HashTransform(D2BnHashCtxStrc* pCtx);                                           // 0x00523AF0

// 0x00524200
void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest)
{
    D2BnHashCtxStrc* pCtx = &gaBnHashCtx_00882760[nIndex];
    const int nOld = pCtx->nBitCountLo;
    const int nNew = nOld + 0x200;
    if (nNew < nOld)
        ++pCtx->nBitCountHi;
    pCtx->nBitCountLo = nNew;
    memcpy(pCtx->f_1C, pBlock, sizeof(pCtx->f_1C));
    sub_00523AF0_HashTransform(pCtx);
    if (pDigest)
    {
        for (int i = 0; i < 5; ++i)
            pDigest[i] = gaBnHashCtx_00882760[nIndex].aState[i];
    }
}
