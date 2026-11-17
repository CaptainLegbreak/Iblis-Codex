struct D2BnHashCtxStrc
{
    unsigned int aState[5];
    int nBitCountLo;
    int nBitCountHi;
    unsigned int f_1C[16];
};

extern D2BnHashCtxStrc gaBnHashCtx_00882760[];                                                              // 0x00882760

// 0x00524280
void __fastcall sub_00524280_InitHashContext(int nIndex)
{
    D2BnHashCtxStrc* pCtx = &gaBnHashCtx_00882760[nIndex];
    pCtx->aState[0] = 0x67452301;
    pCtx->aState[1] = 0xEFCDAB89;
    pCtx->aState[2] = 0x98BADCFE;
    pCtx->aState[3] = 0x10325476;
    pCtx->aState[4] = 0xC3D2E1F0;
    pCtx->nBitCountLo = 0;
    pCtx->nBitCountHi = 0;
}
