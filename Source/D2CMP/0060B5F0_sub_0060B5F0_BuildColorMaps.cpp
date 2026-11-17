struct D2CmpByteMapStrc
{
    unsigned char ab[0x100];
    int nCount;
};

struct D2CmpByteMapArgStrc
{
    D2CmpByteMapStrc* p;
};

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

static __declspec(noinline) void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapArgStrc tInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward);

// 0x0060B5F0
static void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapArgStrc tInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward)
{
    int i;
    int n;
    for (i = 0, n = 0; i < 0x100; ++i)
    {
        if (pFlags[i])
        {
            pForward->ab[i] = (unsigned char)n;
            tInverse.p->ab[n] = (unsigned char)i;
            ++n;
        }
    }
    pForward->nCount = 0x100;
    tInverse.p->nCount = n;
}

// calling-convention shim (not game code)
void __fastcall sub_0060B5F0_Shim(D2CmpByteMapStrc* pInverse, const unsigned int* pBits, D2CmpByteMapStrc* pForward)
{
    unsigned char abFlags[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        abFlags[i] = (pBits[i >> 5] & gdwBitMasks_006CE268[i & 0x1F]) != 0;
    }
    D2CmpByteMapArgStrc tInverse = { pInverse };
    sub_0060B5F0_BuildColorMaps(tInverse, abFlags, pForward);
}
