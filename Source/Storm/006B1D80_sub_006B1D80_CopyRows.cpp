extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

// 0x006B1D80
void __fastcall sub_006B1D80_CopyRows(char* pSrc, char* pDst, int nBytes, int nRows, int nDstPitch, int nUnused)
{
    for (int i = 0; i < nRows; ++i)
    {
        memcpy(pDst, pSrc, nBytes);
        pSrc += nBytes;
        pDst += nDstPitch;
    }
}
