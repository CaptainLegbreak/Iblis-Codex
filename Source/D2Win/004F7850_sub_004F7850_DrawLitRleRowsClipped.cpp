struct D2PaletteStrc { unsigned char remap[256]; };
extern unsigned char gLightCube_007CA320[32][32][32]; // 0x007CA320
extern D2PaletteStrc gLightPalettes_007D2348[]; // 0x007D2348

static int gnInnerRight_007C9784;                                                                           // 0x007C9784
static int gnClipBottom_007C978C;                                                                           // 0x007C978C
static int gnInnerBottom_007C9790;                                                                          // 0x007C9790
static int gnClipLeft_007C9794;                                                                             // 0x007C9794
static int gnRowClipBottom_007C97A0;                                                                        // 0x007C97A0
static int gnColClipLeft_007CA318;                                                                          // 0x007CA318
static int gnInnerTop_007CA31C;                                                                             // 0x007CA31C
static int gnClipRight_007D2324;                                                                            // 0x007D2324
static int gnInnerLeft_007D2328;                                                                            // 0x007D2328
static int gnClipTop_007D232C;                                                                              // 0x007D232C
static int gnRowClipTop_007D2334;                                                                           // 0x007D2334
static int gnColClipRight_007D233C;                                                                         // 0x007D233C
extern int gnScreenPitch_007D544C; // 0x007D544C

extern int gnResolutionMode_007C8CC4; // 0x007C8CC4
static int gnScreen_7C9780; // 0x007C9780
static int gnScreen_7C9788; // 0x007C9788
static int gnScreen_7C9798; // 0x007C9798
static int gnScreen_7C979C; // 0x007C979C
static int gnScreen_7C97A4; // 0x007C97A4
static int gnScreen_7D2320; // 0x007D2320
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
    gnInnerLeft_007D2328 = nLeft;
    gnColClipLeft_007CA318 = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnScreen_7C979C = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnScreen_7C9780 = 0;
    gnScreen_7D2320 = nRight - 0x20;
    gnClipTop_007D232C = -0x20;
    gnClipRight_007D2324 = nRight;
    gnClipBottom_007C978C = nBottom;
    gnInnerTop_007CA31C = 0;
    gnClipLeft_007C9794 = nLeft - 0x20;
    gnInnerBottom_007C9790 = nBottom - 0x20;
    gnInnerRight_007C9784 = nRight - 0x20;
    gnRowClipTop_007D2334 = 0;
    gnColClipRight_007D233C = nRight;
    gnRowClipBottom_007C97A0 = nBottom;
}

// 0x004F7850
void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
    int nRow = 0;
    if (nRows > 0)
    {
        int nCurrentY = nY;
        do
        {
            int nSkip = *pSrc++;
            int nLength = *pSrc++;
            if (!nSkip && !nLength)
            {
                ++nRow; ++nCurrentY;
                pDst += gnScreenPitch_007D544C;
                pRow = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
            }
            else
            {
                if (nCurrentY >= gnRowClipBottom_007C97A0) return;
                pRow += nSkip;
                pLight += nSkip;
                if (nCurrentY >= gnRowClipTop_007D2334)
                {
                    unsigned char* pSrcEnd = pSrc + nLength;
                    unsigned char* pDstEnd = pRow + nLength;
                    const int nPosX = pRow - pDst + nX;
                    int nStart = gnColClipLeft_007CA318 + (-nPosX);
                    nStart = nStart > 0 ? nStart : 0;
                    int nEnd = gnColClipRight_007D233C + (-nPosX);
                    nEnd = nEnd > 0 ? nEnd : 0;
                    if (nEnd >= nLength) nEnd = nLength;
                    int nVisible = nEnd - nStart;
                    if (nVisible > 0)
                    {
                        pRow += nStart;
                        pSrc += nStart;
                        switch(nVisible)
                        {
                        case 32: pRow[31] = gLightPalettes_007D2348[pLight[31]].remap[pSrc[31]];
                        case 31: pRow[30] = gLightPalettes_007D2348[pLight[30]].remap[pSrc[30]];
                        case 30: pRow[29] = gLightPalettes_007D2348[pLight[29]].remap[pSrc[29]];
                        case 29: pRow[28] = gLightPalettes_007D2348[pLight[28]].remap[pSrc[28]];
                        case 28: pRow[27] = gLightPalettes_007D2348[pLight[27]].remap[pSrc[27]];
                        case 27: pRow[26] = gLightPalettes_007D2348[pLight[26]].remap[pSrc[26]];
                        case 26: pRow[25] = gLightPalettes_007D2348[pLight[25]].remap[pSrc[25]];
                        case 25: pRow[24] = gLightPalettes_007D2348[pLight[24]].remap[pSrc[24]];
                        case 24: pRow[23] = gLightPalettes_007D2348[pLight[23]].remap[pSrc[23]];
                        case 23: pRow[22] = gLightPalettes_007D2348[pLight[22]].remap[pSrc[22]];
                        case 22: pRow[21] = gLightPalettes_007D2348[pLight[21]].remap[pSrc[21]];
                        case 21: pRow[20] = gLightPalettes_007D2348[pLight[20]].remap[pSrc[20]];
                        case 20: pRow[19] = gLightPalettes_007D2348[pLight[19]].remap[pSrc[19]];
                        case 19: pRow[18] = gLightPalettes_007D2348[pLight[18]].remap[pSrc[18]];
                        case 18: pRow[17] = gLightPalettes_007D2348[pLight[17]].remap[pSrc[17]];
                        case 17: pRow[16] = gLightPalettes_007D2348[pLight[16]].remap[pSrc[16]];
                        case 16: pRow[15] = gLightPalettes_007D2348[pLight[15]].remap[pSrc[15]];
                        case 15: pRow[14] = gLightPalettes_007D2348[pLight[14]].remap[pSrc[14]];
                        case 14: pRow[13] = gLightPalettes_007D2348[pLight[13]].remap[pSrc[13]];
                        case 13: pRow[12] = gLightPalettes_007D2348[pLight[12]].remap[pSrc[12]];
                        case 12: pRow[11] = gLightPalettes_007D2348[pLight[11]].remap[pSrc[11]];
                        case 11: pRow[10] = gLightPalettes_007D2348[pLight[10]].remap[pSrc[10]];
                        case 10: pRow[9] = gLightPalettes_007D2348[pLight[9]].remap[pSrc[9]];
                        case 9: pRow[8] = gLightPalettes_007D2348[pLight[8]].remap[pSrc[8]];
                        case 8: pRow[7] = gLightPalettes_007D2348[pLight[7]].remap[pSrc[7]];
                        case 7: pRow[6] = gLightPalettes_007D2348[pLight[6]].remap[pSrc[6]];
                        case 6: pRow[5] = gLightPalettes_007D2348[pLight[5]].remap[pSrc[5]];
                        case 5: pRow[4] = gLightPalettes_007D2348[pLight[4]].remap[pSrc[4]];
                        case 4: pRow[3] = gLightPalettes_007D2348[pLight[3]].remap[pSrc[3]];
                        case 3: pRow[2] = gLightPalettes_007D2348[pLight[2]].remap[pSrc[2]];
                        case 2: pRow[1] = gLightPalettes_007D2348[pLight[1]].remap[pSrc[1]];
                        case 1: pRow[0] = gLightPalettes_007D2348[pLight[0]].remap[pSrc[0]];
                        }
                    }
                    pSrc = pSrcEnd;
                    pRow = pDstEnd;
                    pLight += nLength;
                }
                else
                {
                    pRow += nLength;
                    pLight += nLength;
                    pSrc += nLength;
                }
            }
        } while (nRow < nRows);
    }
}
