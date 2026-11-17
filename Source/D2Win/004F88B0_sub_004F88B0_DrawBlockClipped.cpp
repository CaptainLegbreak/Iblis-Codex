struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};

struct D2TileLibraryBlockStrc
{
    short nPosX;
    short nPosY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned char nFormat;
    char unk0x09[0x07];
    unsigned char* pData;
};

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

void __fastcall sub_004F7580_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580

extern int gnSubtileRowXOffset_0072DB48[];                                                                  // 0x0072DB48
extern int gnSubtileRowWidth_0072DB84[];                                                                    // 0x0072DB84
extern int gnSubtileRowSrcOffset_0072DBC0[];                                                                // 0x0072DBC0
extern int gnBlockClipBottom_007C97A0;                                                                      // 0x007C97A0
extern int gnBlockClipLeft_007CA318;                                                                        // 0x007CA318
extern int gnBlockClipTop_007D2334;                                                                         // 0x007D2334
extern int gnBlockClipRight_007D233C;                                                                       // 0x007D233C
extern D2PaletteStrc gLightPalettes_007D2348[];                                                             // 0x007D2348
extern int gnScreenPitch_007D544C;                                                                          // 0x007D544C

// 0x004F88B0
void __fastcall sub_004F88B0_DrawBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, unsigned char nLight)
{
    unsigned char* pPalette = gLightPalettes_007D2348[nLight >> 3].unk0x00;
    if (pBlock->nFormat & 4)
    {
        sub_004F7580_DrawRleRowsClipped(nX, nY, pBlock->pData, pDst, pPalette, 0xF);
        return;
    }

    const int nStartRow = D2_MAX(gnBlockClipTop_007D2334 - nY, 0);
    const int nEndRow = D2_MIN(gnBlockClipBottom_007C97A0 - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch_007D544C * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
        const int nNegX = -(nX + gnSubtileRowXOffset_0072DB48[i]);
        unsigned char* d = pRow + gnSubtileRowXOffset_0072DB48[i];
        unsigned char* s = pBlock->pData + gnSubtileRowSrcOffset_0072DBC0[i];
        const int nSkipValue = D2_MAX(gnBlockClipLeft_007CA318 + nNegX, 0);
        const int nClipRight = gnBlockClipRight_007D233C;
        const int nRight = nNegX + nClipRight;
        const int nWidth = gnSubtileRowWidth_0072DB84[i];
        int nSkip;
        nSkip = nSkipValue;
        int nCount = D2_MAX(nRight, 0);
        nCount = D2_MIN(nCount, nWidth) - nSkip;
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            for (unsigned char* pEnd = s + nCount; s < pEnd; ++s, ++d)
            {
                *d = pPalette[*s];
            }
        }

        pRow += gnScreenPitch_007D544C;
    }
}
