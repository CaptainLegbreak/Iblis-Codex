static int gnClipYMax_007C97A0;                                                                             // 0x007C97A0
static int gnClipXMin_007CA318;                                                                             // 0x007CA318
static int gnClipYMin_007D2334;                                                                             // 0x007D2334
static int gnClipXMax_007D233C;                                                                             // 0x007D233C
extern int gnScreenPitch_007D544C;                                                                          // 0x007D544C

extern int gnResolutionMode_007C8CC4; // 0x007C8CC4
static int gnScreen_7C9780; // 0x007C9780
static int gnScreen_7C9784; // 0x007C9784
static int gnScreen_7C9788; // 0x007C9788
static int gnScreen_7C978C; // 0x007C978C
static int gnScreen_7C9790; // 0x007C9790
static int gnScreen_7C9794; // 0x007C9794
static int gnScreen_7C9798; // 0x007C9798
static int gnScreen_7C979C; // 0x007C979C
static int gnScreen_7C97A4; // 0x007C97A4
static int gnScreen_7CA31C; // 0x007CA31C
static int gnScreen_7D2320; // 0x007D2320
static int gnScreen_7D2324; // 0x007D2324
static int gnScreen_7D2328; // 0x007D2328
static int gnScreen_7D232C; // 0x007D232C
static int gnScreen_7D2330; // 0x007D2330
static int gnScreen_7D2338; // 0x007D2338

// 0x004F7DA0
void __fastcall sub_004F7DA0_SetPanelCoords(int nWidth, int nHeight)
{
    int nLeft = 0;
    int nRight = nWidth;
    const int nBottom = nHeight - 0x2F;
    if (gnResolutionMode_007C8CC4 == 1)
    {
        nRight -= nWidth / 2;
    }
    else if (gnResolutionMode_007C8CC4 == 2)
    {
        nLeft = nWidth / 2;
    }
    gnScreen_7D2338 = nBottom;
    gnScreen_7C97A4 = nLeft;
    gnScreen_7D2328 = nLeft;
    gnClipXMin_007CA318 = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnScreen_7C979C = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnScreen_7C9780 = 0;
    gnScreen_7D2320 = nRight - 0x20;
    gnScreen_7D232C = -0x20;
    gnScreen_7D2324 = nRight;
    gnScreen_7C978C = nBottom;
    gnScreen_7CA31C = 0;
    gnScreen_7C9794 = nLeft - 0x20;
    gnScreen_7C9790 = nBottom - 0x20;
    gnScreen_7C9784 = nRight - 0x20;
    gnClipYMin_007D2334 = 0;
    gnClipXMax_007D233C = nRight;
    gnClipYMax_007C97A0 = nBottom;
}

// 0x004F7580
void __fastcall sub_004F7580_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows)
{
    unsigned char* p = pDst;
    int i = 0;
    if (nRows > 0)
    {
    int nLeft = nY;
    do
    {
        int nSkip = *pSrc++;
        int nCount = *pSrc++;
        if (!nSkip && !nCount)
        {
            ++i;
            ++nLeft;
            pDst += gnScreenPitch_007D544C;
            p = pDst;
        }
        else
        {
            if (nLeft >= gnClipYMax_007C97A0)
            {
                return;
            }

            p += nSkip;
            if (nLeft >= gnClipYMin_007D2334)
            {
                unsigned char* pNextSrc = pSrc + nCount;
                unsigned char* pNext = p + nCount;
                const int nPos = p - pDst + nX;
                int nStart = gnClipXMin_007CA318 + (-nPos);
                nStart = nStart > 0 ? nStart : 0;
                int nEnd = gnClipXMax_007D233C + (-nPos);
                nEnd = nEnd > 0 ? nEnd : 0;
                nEnd = nEnd < nCount ? nEnd : nCount;
                const int nLength = nEnd - nStart;
                if (nLength > 0)
                {
                    p += nStart;
                    pSrc += nStart;
                    switch (nLength)
                    {
                    case 32: p[31] = pPalette[pSrc[31]];
                    case 31: p[30] = pPalette[pSrc[30]];
                    case 30: p[29] = pPalette[pSrc[29]];
                    case 29: p[28] = pPalette[pSrc[28]];
                    case 28: p[27] = pPalette[pSrc[27]];
                    case 27: p[26] = pPalette[pSrc[26]];
                    case 26: p[25] = pPalette[pSrc[25]];
                    case 25: p[24] = pPalette[pSrc[24]];
                    case 24: p[23] = pPalette[pSrc[23]];
                    case 23: p[22] = pPalette[pSrc[22]];
                    case 22: p[21] = pPalette[pSrc[21]];
                    case 21: p[20] = pPalette[pSrc[20]];
                    case 20: p[19] = pPalette[pSrc[19]];
                    case 19: p[18] = pPalette[pSrc[18]];
                    case 18: p[17] = pPalette[pSrc[17]];
                    case 17: p[16] = pPalette[pSrc[16]];
                    case 16: p[15] = pPalette[pSrc[15]];
                    case 15: p[14] = pPalette[pSrc[14]];
                    case 14: p[13] = pPalette[pSrc[13]];
                    case 13: p[12] = pPalette[pSrc[12]];
                    case 12: p[11] = pPalette[pSrc[11]];
                    case 11: p[10] = pPalette[pSrc[10]];
                    case 10: p[9] = pPalette[pSrc[9]];
                    case 9: p[8] = pPalette[pSrc[8]];
                    case 8: p[7] = pPalette[pSrc[7]];
                    case 7: p[6] = pPalette[pSrc[6]];
                    case 6: p[5] = pPalette[pSrc[5]];
                    case 5: p[4] = pPalette[pSrc[4]];
                    case 4: p[3] = pPalette[pSrc[3]];
                    case 3: p[2] = pPalette[pSrc[2]];
                    case 2: p[1] = pPalette[pSrc[1]];
                    case 1: p[0] = pPalette[pSrc[0]];
                    }
                }

                pSrc = pNextSrc;
                p = pNext;
            }
            else
            {
                p += nCount;
                pSrc += nCount;
            }
        }
    } while (i < nRows);
    }
}
