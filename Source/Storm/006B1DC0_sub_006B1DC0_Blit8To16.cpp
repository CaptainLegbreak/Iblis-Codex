extern unsigned short gwPaletteTo16_0096FA80[256]; // 0x0096FA80

// 0x006B1DC0
void __fastcall sub_006B1DC0_Blit8To16(const unsigned char* pSrc, unsigned short* pDst, int nWidth, int nHeight, int nDstPitch, int nUnused)
{
    unsigned short* pRowDst = pDst;
    const unsigned char* pRowSrc = pSrc;
    for (int y = 0; y < nHeight; ++y)
    {
        unsigned short* d = pRowDst;
        const unsigned char* s = pRowSrc;
        for (int x = 0; x < nWidth; ++x)
        {
            *d++ = gwPaletteTo16_0096FA80[*s++];
        }
        pRowSrc += nWidth;
        pRowDst += nDstPitch;
    }
}
