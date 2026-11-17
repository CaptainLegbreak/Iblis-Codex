static __declspec(noinline) void __stdcall sub_006B9EB0_CopyBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch);
// 0x006B9EB0
static void __stdcall sub_006B9EB0_CopyBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch)
{
    for (unsigned int nRow = 64; nRow; --nRow)
    {
        const unsigned short* pIn = pSource;
        const int nDelta = (char*)pDest - (char*)pSource;
        for (unsigned int i = 256; i; --i)
        {
            *(unsigned short*)((char*)pIn + nDelta) = *pIn | 0x8000;
            ++pIn;
        }
        pDest = (unsigned short*)((char*)pDest + nDestPitch);
        pSource += 512;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_006B9EB0_Shim(unsigned short* pSource, unsigned short* pDest, int nDestPitch)
{
    sub_006B9EB0_CopyBlock(pSource, pDest, nDestPitch);
}
