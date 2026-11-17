typedef unsigned char (__stdcall* MapFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

unsigned char __stdcall sub_006056D0_FindNearestPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x006056D0
extern int gbPaletteLoaded_008E9934;                                                                        // 0x008E9934
int gbDarkTest_008E9D3C;                                                                                    // 0x008E9D3C

// 0x006057A0
int __stdcall sub_006057A0_MapColors(const unsigned char* pSource, unsigned char* pDest, unsigned int nCount, MapFn pfnMap)
{
    const unsigned char* pSrc = pSource;
    unsigned char* pDst = pDest;
    if (gbPaletteLoaded_008E9934)
    {
        MapFn pfn = !pfnMap ? sub_006056D0_FindNearestPaletteIndex : pfnMap;

        for (unsigned int i = 0; i < nCount; ++i)
        {
            unsigned char nRed = *pSrc++;
            unsigned char nGreen = *pSrc++;
            unsigned char nBlue = *pSrc++;
            if (gbDarkTest_008E9D3C && nRed <= 10 && nGreen <= 10 && nBlue <= 10)
            {
                nRed = 4;
                nBlue = 0;
                nGreen = 0;
            }

            *pDst++ = pfn(nRed, nGreen, nBlue);
        }
    }

    return 0;
}
