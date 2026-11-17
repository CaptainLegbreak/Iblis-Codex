struct D2PaletteStrc { unsigned char colors[256]; };
unsigned char gLightCube_007CA320[32][32][32];        // 0x007CA320
D2PaletteStrc gLightPalettes_007D2348[49];      // 0x007D2348
extern int gnScreenPitch_007D544C; // 0x007D544C
// 0x004F71A0
void __fastcall sub_004F71A0_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
    while (nRows) {
        int nSkip = *pSrc++;
        int nLength = *pSrc++;
        if (!nSkip && !nLength) {
            nLightX += nLightXStep;
            nLightY += nLightYStep;
            pDst += gnScreenPitch_007D544C;
            --nRows;
            pRow = pDst;
            pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
        } else {
            pRow += nSkip;
            pLight += nSkip;
            switch (nLength) {
            case 32: pRow[31] = gLightPalettes_007D2348[pLight[31]].colors[pSrc[31]];
            case 31: pRow[30] = gLightPalettes_007D2348[pLight[30]].colors[pSrc[30]];
            case 30: pRow[29] = gLightPalettes_007D2348[pLight[29]].colors[pSrc[29]];
            case 29: pRow[28] = gLightPalettes_007D2348[pLight[28]].colors[pSrc[28]];
            case 28: pRow[27] = gLightPalettes_007D2348[pLight[27]].colors[pSrc[27]];
            case 27: pRow[26] = gLightPalettes_007D2348[pLight[26]].colors[pSrc[26]];
            case 26: pRow[25] = gLightPalettes_007D2348[pLight[25]].colors[pSrc[25]];
            case 25: pRow[24] = gLightPalettes_007D2348[pLight[24]].colors[pSrc[24]];
            case 24: pRow[23] = gLightPalettes_007D2348[pLight[23]].colors[pSrc[23]];
            case 23: pRow[22] = gLightPalettes_007D2348[pLight[22]].colors[pSrc[22]];
            case 22: pRow[21] = gLightPalettes_007D2348[pLight[21]].colors[pSrc[21]];
            case 21: pRow[20] = gLightPalettes_007D2348[pLight[20]].colors[pSrc[20]];
            case 20: pRow[19] = gLightPalettes_007D2348[pLight[19]].colors[pSrc[19]];
            case 19: pRow[18] = gLightPalettes_007D2348[pLight[18]].colors[pSrc[18]];
            case 18: pRow[17] = gLightPalettes_007D2348[pLight[17]].colors[pSrc[17]];
            case 17: pRow[16] = gLightPalettes_007D2348[pLight[16]].colors[pSrc[16]];
            case 16: pRow[15] = gLightPalettes_007D2348[pLight[15]].colors[pSrc[15]];
            case 15: pRow[14] = gLightPalettes_007D2348[pLight[14]].colors[pSrc[14]];
            case 14: pRow[13] = gLightPalettes_007D2348[pLight[13]].colors[pSrc[13]];
            case 13: pRow[12] = gLightPalettes_007D2348[pLight[12]].colors[pSrc[12]];
            case 12: pRow[11] = gLightPalettes_007D2348[pLight[11]].colors[pSrc[11]];
            case 11: pRow[10] = gLightPalettes_007D2348[pLight[10]].colors[pSrc[10]];
            case 10: pRow[9] = gLightPalettes_007D2348[pLight[9]].colors[pSrc[9]];
            case 9: pRow[8] = gLightPalettes_007D2348[pLight[8]].colors[pSrc[8]];
            case 8: pRow[7] = gLightPalettes_007D2348[pLight[7]].colors[pSrc[7]];
            case 7: pRow[6] = gLightPalettes_007D2348[pLight[6]].colors[pSrc[6]];
            case 6: pRow[5] = gLightPalettes_007D2348[pLight[5]].colors[pSrc[5]];
            case 5: pRow[4] = gLightPalettes_007D2348[pLight[4]].colors[pSrc[4]];
            case 4: pRow[3] = gLightPalettes_007D2348[pLight[3]].colors[pSrc[3]];
            case 3: pRow[2] = gLightPalettes_007D2348[pLight[2]].colors[pSrc[2]];
            case 2: pRow[1] = gLightPalettes_007D2348[pLight[1]].colors[pSrc[1]];
            case 1: pRow[0] = gLightPalettes_007D2348[pLight[0]].colors[pSrc[0]];
            }
            pRow += nLength;
            pSrc += nLength;
            pLight += nLength;
        }
    }
}
