extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BnHashCtxStrc
{
    unsigned int aState[5];
    int nBitCountLo;
    int nBitCountHi;
    unsigned int f_1C[16];
};

extern D2BnHashCtxStrc gaBnHashCtx_00882760[];                                                              // 0x00882760

// 0x005241A0
void __cdecl sub_005241A0_ClearHashContexts()
{
    memset(gaBnHashCtx_00882760, 0, sizeof(D2BnHashCtxStrc) * 3);
}
