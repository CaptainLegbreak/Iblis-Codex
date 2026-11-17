static __declspec(noinline) void __cdecl sub_006C5B10_EncodeRow(unsigned char** ppSource, unsigned char** ppDest, int nCount);

// 0x006C5B10
static void __cdecl sub_006C5B10_EncodeRow(unsigned char** ppSource, unsigned char** ppDest, int nCount)
{
    do
    {
        const unsigned char nByte = **ppSource;
        ++*ppSource;
        int nRun = 1;
        --nCount;
        while (nCount && nByte == **ppSource && nRun < 63)
        {
            --nCount;
            ++*ppSource;
            ++nRun;
        }

        if (nRun > 1 || nByte >= 0xC0)
        {
            **ppDest = (unsigned char)(nRun | 0xC0);
            ++*ppDest;
        }
        **ppDest = nByte;
        ++*ppDest;
    }
    while (nCount);
}

// build: context sub_006C5B10_Shim
// calling-convention shim (not game code)
void __cdecl sub_006C5B10_Shim(unsigned char** ppSource, unsigned char** ppDest, int nCount)
{
    sub_006C5B10_EncodeRow(ppSource, ppDest, nCount);
}
